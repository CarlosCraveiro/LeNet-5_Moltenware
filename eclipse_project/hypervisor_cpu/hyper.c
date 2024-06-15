//main CPU in design
#include "../cpus/cpus_config.h"
#include "../cpus/hyper_config.h"
#include "../memory/memory_layout.h"

//determina quais cpus estão ativas na camada atual
void get_actives_cpus(int *active_cpu_num)
{

    for (int i = 0; i < WORKER_CPU_NUM; i++) {
        *active_cpu_num += EXEC_LIST_CPU[i][CURRENT_LAYER];
    }

    return;
}

//limpar a região de memória com as CPUS que terminaram a execução
void clean_HYPERVISOR_check_addr(void)
{

    long long int *controller_addr = HYPERVISOR_CHECK_ADDR;
    for(int i = 0; i < WORKER_CPU_NUM; i++){
        *controller_addr = 0;
        controller_addr += WORD;
    }

    return;
}

//escreve quais CPUS serão usadas na próxima camada
void write_cpu_controllers(void)
{
    long long int *controller_addr = CPUS_CHECK_ADDR;
    for(int i = 0; i < WORKER_CPU_NUM; i++){
        *controller_addr = EXEC_LIST_CPU[i][CURRENT_LAYER];
        controller_addr += WORD;
    }

    return;
}

//HYPERVISOR
void HYPERVISOR_watchdog(void)
{

    int cpu_duty[WORKER_CPU_NUM];
    long long int *controller_addr = HYPERVISOR_CHECK_ADDR;
    int active_cpus = 0;
    int ready_cpus = 0;
    get_actives_cpus(&active_cpus);

    while (1) {
        for (int i = 0; i < active_cpus; i++) {
            // verificamos se o primeiro endereço na memória é 1 
            //(se cpu_0 terminou) e incrementamos o endereço de memória
            int cpu_ready = *controller_addr;
            if (cpu_ready == 1) {
                controller_addr += WORD;
                ready_cpus++;

                if (ready_cpus == active_cpus) {
                    CURRENT_LAYER++;
                    //nenhuma CPU terminou a próxima layer
                    clean_HYPERVISOR_check_addr();
                    //escrevemos quais CPUs estão ativas na próxima layer
                    write_cpu_controllers();
                    if(CURRENT_LAYER == 8) return;
                }
            }
        }
    }
}

int main(void)
{
    HYPERVISOR_watchdog();
    
    return 0;
}
