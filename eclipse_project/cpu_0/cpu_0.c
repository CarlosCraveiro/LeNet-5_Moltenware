#include "../memory/memory_layout.h"
#include "hyper_config.h"
#include "layers.h"
#include <cnn_features.h>
#include <filters.h>
#include <convolution.h>
#include <layers.h>
#include <c1_params.h>
#include <c3_params.h>
#include <d5_params.h>
#include <d6_params.h>
#include <d7_params.h>
#include <test_image_1.h>
#include <test_image_0.h>

void func(void)
{   
    int num_cpus_c1 = 3;
    int num_cpus_p2 = 4;
    int num_cpus_c3 = 4;
    int num_cpus_p4 = 3;
    int cpu_id = 0;

    if(CURRENT_LAYER == 1){

        //manipulamos diretamente os endereços de memória. (houveram problemas)
        layer_c1((void*) IMAGE_START, (void*)C1_FILTERS_START, 
            (void *)C1_BIAS_START, (void*) LAYER_2_START, 
            num_cpus_c1, cpu_id);
    
    } else if(CURRENT_LAYER == 2){
        layer_p2((void*) LAYER_2_START, (void*) LAYER_3_START, 
            num_cpus_p2, cpu_id);
    
    } else if(CURRENT_LAYER == 3){
        layer_c3((void*)LAYER_3_START, (void*)C3_FILTER_START,
             (void*)C3_BIAS_START, (void*)LAYER_4_START, 
             num_cpus_c3, cpu_id);
        
    }else if(CURRENT_LAYER == 4){
        layer_p4((void*)LAYER_4_START, (void*)LAYER_5_START, 
            num_cpus_p4, cpu_id);
        
    }
    else if(CURRENT_LAYER == 5){
        layer_flattening((void*)LAYER_5_START, (void*)LAYER_6_START);
        
    }else if(CURRENT_LAYER == 6){
        layer_d5((void*)LAYER_6_START, (void*)D5_FILTER_START, 
            (void*)D5_BIASES_START, (void*)LAYER_7_START);
        
    }
    else if(CURRENT_LAYER == 7){
        layer_d7((void*)LAYER_7_START, (void*)D7_FILTER_START, 
            (void*)D7_BIASES_START, (void*)RESULT_VECTOR_START);        
    }
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