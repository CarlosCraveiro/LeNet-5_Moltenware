#include <layers.h>
#include <convolution.h>
    void layer_c1(feature_t* input, feature_t* filters, feature_t* output) {
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

            feature_map_t feat_map;
            feat_map.map = output;
            feat_map.size = C1_OUTPUT_SIZE;
            feat_map.number = i;
            
            feature_t result;
            convolution(batchs[i], filter, &result);
            ReLU_feature(result, &result);
            feat_map.map[C1_OUTPUT_SIZE*C1_OUTPUT_SIZE*j + i] = result;
        }
    } 
}
