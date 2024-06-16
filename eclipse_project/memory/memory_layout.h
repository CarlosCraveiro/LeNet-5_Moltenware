#ifndef __memory_layout
#define __memory_layout

#include <general_settings.h>

//estrutura da memória compartilhada (memória de dados):
//a memória compartilhada precisa ser gerada e colocada no momento
//da compilação no quartus.
/*     +++++++++++++++++++++++
       ++-------------------++
       +|   imagem_teste    |+
       +|         .         |+
       +|   output_layer_1  |+
       +|  (input_layer_2)  |+
       +|         .         |+
       +|         .         |+
       +|         .         |+
       +|       (...)       |+
       +|   output_layer_n  |+
       +| (input_layer_n+1) |+
       +|      (~17kb)      |+ 
       +|___________________|+
       +|    filtros e      |+
       +|      pesos        |+
       +|      (...)        |+
       +|    (~1400kb)      |+
       ++-------------------++
       +++++++++++++++++++++++

    //temos, segundo o manual, 6480 kb disponíveis.
    //https://www.secs.oakland.edu/~llamocca/Tutorials/Emb_Intel/Documentation/DE2i-150_FPGA_User_Manual.pdf
    (kb = kilobits (considerando um float como 32 bits = 4bytes))
*/

#define WORD 4 
//definir ~16kb para cada (usada como memória de instrução)
#define CPU_0_RAM_START (long long int*) 0x20000
#define CPU_0_RAM_END (long long int*) 0x24000
#define CPU_1_RAM_START (long long int*) 0x24000 
#define CPU_1_RAM_END (long long int*) 0x28000
#define CPU_2_RAM_START (long long int*) 0x2C000
#define CPU_2_RAM_END (long long int*) 0x2C000
#define CPU_3_RAM_START (long long int*) 0x30000
#define CPU_3_RAM_END (long long int*) 0x34000
#define HYPERVISOR_RAM_START (long long int*) 0x38000
#define HYPERVISOR_RAM_END (long long int*) 0x3C000

//definido como 1600 kb 
#define SHARED_MEM_START (long long int*) 0x3C000
#define SHARED_MEM_END (long long int*) 0x1CC000

//memória de controle (1kb) (precisaria ser de apenas 32 bits [8 floats])
#define CONTROL_MEM_START (long long int*) 0x1CC000
#define CONTROL_MEM_END (long long int*) 0x1CC400

//mem que o HYPERVISOR lê para ver se a CPU terminou a execução (cpus escrevem)
#define HYPERVISOR_CHECK_ADDR CONTROL_MEM_START

//memória que as CPU's lerão para ver se estão ativas (HYPERVISOR escreve) 
#define CPUS_CHECK_ADDR (long long int*) 0x1CC200

//posição na qual as flags serão armazenadas na memória RAM compartilhada
#define CPU_0_FLAG_OFFSET CONTROL_MEM_START
#define CPU_1_FLAG_OFFSET CONTROL_MEM_START + 1*WORD
#define CPU_2_FLAG_OFFSET CONTROL_MEM_START + 2*WORD
#define CPU_3_FLAG_OFFSET CONTROL_MEM_START + 3*WORD
#define CPU_4_FLAG_OFFSET CONTROL_MEM_START + 4*WORD

//definição das regiões da memória compartilhada:
//posição de leitura/escrita (separadas) (~17 kb)
#define IMAGE_START SHARED_MEM_START
#define LAYER_2_START IMAGE_START + IMAGE_SIZE*IMAGE_SIZE*WORD
#define LAYER_3_START LAYER_2_START + C1_OUTPUT_SIZE
#define LAYER_4_START LAYER_3_START + P2_OUTPUT_SIZE
#define LAYER_5_START LAYER_4_START + C3_OUTPUT_SIZE
#define LAYER_6_START LAYER_5_START + P4_OUTPUT_SIZE
#define LAYER_7_START LAYER_6_START + FLAT_OUTPUT_SIZE
#define LAYER_8_START LAYER_7_START + D5_OUTPUT_SIZE

//posição apenas de leitura (pesos e filtros) (~1400 kb)
#define WEIGHTS_START_POS LAYER_8_START + 10*WORD
#define C1_BIAS_START WEIGHTS_START_POS 
#define C1_FILTERS_START C1_BIAS_START + C1_NUMBER_OF_FILTERS*WORD
#define C3_BIAS_START C1_BIAS_START + C1_NUMBER_OF_FILTERS*C1_INPUT_CHANNELS*CONV_FILTER_SIZE*CONV_FILTER_SIZE*WORD
#define C3_FILTER_START C3_BIAS_START + C3_NUMBER_OF_FILTERS*WORD
#define D5_BIASES_START C3_FILTER_START + C3_NUMBER_OF_FILTERS*C3_INPUT_CHANNELS*CONV_FILTER_SIZE*CONV_FILTER_SIZE*WORD
#define D5_FILTER_START D5_BIASES_START + D5_OUTPUT_SIZE*WORD
#define D6_BIASES_START D5_FILTER_START + D5_INPUT_SIZE*D5_OUTPUT_SIZE*WORD
#define D6_FILTER_START D6_BIASES_START + D6_OUTPUT_SIZE*WORD
#define D7_BIASES_START D6_FILTER_START + D6_INPUT_SIZE*D6_OUTPUT_SIZE*WORD
#define D7_FILTER_START D7_BIASES_START + D7_OUTPUT_SIZE*WORD
#define RESULT_VECTOR_START D7_FILTER_START + D7_INPUT_SIZE*D7_OUTPUT_SIZE*WORD


#endif // __memory_layout