#ifndef __hyper_config
#define __hyper_config

#include "cpus_config.h"

#define EXEC_LIST_CPU_0 {1, 1, 1, 1, 1, 1, 1, 1}
#define EXEC_LIST_CPU_1 {1, 1, 1, 1, 0, 1, 1, 0}
#define EXEC_LIST_CPU_2 {0, 0, 1, 1, 0, 1, 1, 0}
#define EXEC_LIST_CPU_3 {0, 0, 1, 0, 0, 1, 0, 0}

int EXEC_LIST_CPU[WORKER_CPU_NUM][LAYER_NUM] = {EXEC_LIST_CPU_0, EXEC_LIST_CPU_1,\
    EXEC_LIST_CPU_2, EXEC_LIST_CPU_3};

int CURRENT_LAYER = 0;

#endif // __hyper_config
