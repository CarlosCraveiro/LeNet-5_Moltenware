#ifndef __memory_layout
#define __memory_layout

#define WORD 2
//definir ~16kb para cada (usada como memória de instrução)
#define CPU_0_RAM_START (long long int*) 0x0000
#define CPU_0_RAM_END (long long int*) 0x0FFF
#define CPU_1_RAM_START (long long int*) 0x1000 
#define CPU_1_RAM_END (long long int*) 0x1FFF
#define CPU_2_RAM_START (long long int*) 0x2000
#define CPU_2_RAM_END (long long int*) 0x2FFF
#define CPU_3_RAM_START (long long int*) 0x3000
#define CPU_3_RAM_END (long long int*) 0x3FFF
#define HYPERVISOR_ram_START (long long int*) 0x4000
#define HYPERVISOR_ram_END (long long int*) 0x4FFF

//definido atualmente 700 Mb
#define SHARED_MEM_START (long long int*) 0x5000
#define SHARED_MEM_END (long long int*) 0x8fff

//memória de controle
#define CONTROL_MEM_START (long long int*) 0x9000
#define CONTROL_MEM_END (long long int*) 0xABCD

//mem que o hypervisor lê para ver se a CPU terminou a execução (cpus escrevem)
#define HYPERVISOR_CHECK_ADDR CONTROL_MEM_START

//memória que as CPU's lerão para ver se estão ativas (hypervisor escreve) 
#define CPUS_CHECK_ADDR (long long int*) 0x9A000

//posição na qual as flags serão armazenadas na memória RAM compartilhada
#define CPU_0_FLAG_OFFSET SHARED_MEM_START
#define CPU_1_FLAG_OFFSET SHARED_MEM_START + 1*WORD
#define CPU_2_FLAG_OFFSET SHARED_MEM_START + 2*WORD
#define CPU_3_FLAG_OFFSET SHARED_MEM_START + 3*WORD
#define CPU_4_FLAG_OFFSET SHARED_MEM_START + 4*WORD

#endif // __memory_layout