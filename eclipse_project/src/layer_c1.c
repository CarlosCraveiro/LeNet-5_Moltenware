#include "cnn_features.h"
#include "general_settings.h"
#include <layers.h>
#include <convolution.h>
#include <activation.h>

void layer_c1(void* input, feature_t* filters, feature_t* biases, 
 void* output, int cpu_num, int cpu_id) 
{

    feature_t batchs[C1_OUTPUT_SIZE*C1_OUTPUT_SIZE][CONV_FILTER_SIZE*CONV_FILTER_SIZE];

    int start, end, size;
    size = C1_INPUT_SIZE/cpu_num;
    start = (cpu_id)*size;
    end = start+size;

    for(int i = start; i < end; i++) {
        for(int j = start; j < end; j++) {
            for(int k = 0; k < CONV_FILTER_SIZE; k++) {
                for(int l = 0; l < CONV_FILTER_SIZE; l++) {
                    batchs[size*i + j][k*CONV_FILTER_SIZE + l] 
                        = ((feature_t*)input)[(i + k)*size + j + l];
                }
            }
        }
    }
    
    //o que de fato está sendo paralelizado
    for(int i = start; i < end*end; i++) {
        for(int j = 0; j < C1_NUMBER_OF_FILTERS; j++) {
            filter_t filter;
            filter.filters = filters;
            filter.size = CONV_FILTER_SIZE;
            filter.number = j;
            filter.channels = C1_INPUT_CHANNELS;
            filter.channel_number = 0;
            filter.numbers = C1_NUMBER_OF_FILTERS; 

            feature_t result;
            convolution(batchs[i], filter, &result);
            
            sum_feature(result, biases[j], &result);
            
            ReLU_feature(result, &result);
            ((feature_t*)output)[end*end*j + i] = result;
        }
    }
}
