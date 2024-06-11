#include "../memory/memory_layout.h"
#include "../cpus/cpus_config.h"

void func(void)
{   
    //(podemos fazer um vetor de ponteiro de funções para as
    //funções das camadas paralelizadas), tipo:
    // *f = funcs[LAYER_NUM]; f(args[]);

    if(LAYER_NUM == 0){
        //func_1; 
    }
    //função de execução da CPU
    return;
}

void write_ready_status(long long int* controller_addr)
{
    *controller_addr = 1;
}

void proc(void){

    long long int* cpu_read_base; 
     long long int* cpu_write_base = HYPERVISOR_CHECK_ADDR;
    while(1){
        cpu_read_base = CPUS_CHECK_ADDR;
        while(*cpu_read_base){
            func();

            write_ready_status(cpu_write_base);
        }

    }
}

int main(void){

    proc();

    return 0;
}