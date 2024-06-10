#include <layers.h>
#include <convolution.h>
#include <activation.h>
#include <stdio.h>

void layer_c1(feature_t* input, feature_t* filters, feature_t* biases, feature_t* output) {
    feature_t batchs[C1_OUTPUT_SIZE*C1_OUTPUT_SIZE][CONV_FILTER_SIZE*CONV_FILTER_SIZE];

    for(int i = 0; i < C1_OUTPUT_SIZE; i++) {
        for(int j = 0; j < C1_OUTPUT_SIZE; j++) {
            for(int k = 0; k < CONV_FILTER_SIZE; k++) {
                for(int l = 0; l < CONV_FILTER_SIZE; l++) {
                    batchs[C1_OUTPUT_SIZE*i + j][k*CONV_FILTER_SIZE + l] 
                        = input[(i + k)*C1_INPUT_SIZE + j + l];
                }
            }
        }
    }
    
    for(int i = 0; i < C1_OUTPUT_SIZE*C1_OUTPUT_SIZE; i++) {
        for(int j = 0; j < C1_NUMBER_OF_FILTERS; j++) {
            filter_t filter;
            filter.filters = filters;
            filter.size = CONV_FILTER_SIZE;
            filter.number = j;
            filter.channels = C1_INPUT_CHANNELS;
            filter.channel_number = 0;
            filter.numbers = C1_NUMBER_OF_FILTERS;
           
            printf("Batch %d\n", i);
            for(int k = 0; k < CONV_FILTER_SIZE; k++) {
                for(int l = 0; l < CONV_FILTER_SIZE; l++) {
                    printf("%f ", batchs[i][k*CONV_FILTER_SIZE + l]);
                }
                printf("\n");
            }
            printf("\n");

            feature_t result;
            convolution(batchs[i], filter, &result);
            
            sum_feature(result, biases[j], &result);
            
            ReLU_feature(result, &result);
            output[C1_OUTPUT_SIZE*C1_OUTPUT_SIZE*j + i] = result;
        }
    }
}
