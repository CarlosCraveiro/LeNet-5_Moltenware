#include "cnn_features.h"
#include <layers.h>
#include <convolution.h>
#include <activation.h>

void layer_c3(void* input, void* filters, void* biases, void* output, 
    int cpu_num, int cpu_id) 
{
    feature_t batchs[C1_NUMBER_OF_FILTERS][C3_OUTPUT_SIZE*C3_OUTPUT_SIZE][CONV_FILTER_SIZE*CONV_FILTER_SIZE];

    int start, end, size;
    size = C1_INPUT_SIZE/cpu_num;
    start = (cpu_id)*size;
    end = start+size;

    for(int i = start; i < end; i++) {
        for(int j = start; j < end; j++) {
            for(int k = 0; k < CONV_FILTER_SIZE; k++) {
                for(int l = 0; l < CONV_FILTER_SIZE; l++) {
                    for(int m = 0; m < C1_NUMBER_OF_FILTERS; m++) {
                        batchs[m][end*i + j][k*CONV_FILTER_SIZE + l] 
                            = ((feature_t*)input)[m*C3_INPUT_SIZE*C3_INPUT_SIZE + (i + k)*C3_INPUT_SIZE + j + l];
                    }
                }
            }
        }
    }
    
    for(int i = start; i < end*end; i++) {
        for(int j = 0; j < C3_NUMBER_OF_FILTERS; j++) {
            filter_t filter;
            filter.filters = filters;
            filter.size = CONV_FILTER_SIZE;
            filter.number = j;
            filter.channels = C3_INPUT_CHANNELS; 
            filter.numbers = C3_NUMBER_OF_FILTERS;

            feature_t sum;
            feature_t buffer;

            initialize_feature(&sum);

            for(int k = 0; k < C3_INPUT_CHANNELS; k++) {
                filter.channel_number = k;
                convolution(batchs[k][i], filter, &buffer);
                sum_feature(sum, buffer, &sum); 
            }
            sum_feature(sum, ((feature_t*)biases)[j], &sum);
        
            ReLU_feature(sum, &sum);
            ((feature_t*)output)[C3_OUTPUT_SIZE*C3_OUTPUT_SIZE*j + i] = sum; 
        }
    } 
}
