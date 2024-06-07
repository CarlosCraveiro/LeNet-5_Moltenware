#include <layers.h>
#include <convolution.h>
    void layer_c1(feature_t* input, feature_t* filters, feature_t* output) {
    feature_t batchs[28*28][25];

    for(int i = 0; i < 28; i++) {
        for(int j = 0; j < 28; j++) {
            for(int k = 0; k < 5; k++) {
                for(int l = 0; l < 5; l++) {
                    batchs[28*i + j][k*5 + l] = input[(i + k)*32 + j + l];
                }
            }
        }
    }
    
    for(int i = 0; i < 28*28; i++) {
        for(int j = 0; j < 6; j++) {
            filter_t filter;
            filter.filters = filters;
            filter.size = 5;
            filter.number = j;

            feature_map_t feat_map;
            feat_map.map = output;
            feat_map.size = 28;
            feat_map.number = i;
            
            feature_t result;
            convolution(batchs[i], filter, &result);
            ReLU_feature(result, &result);
            feat_map.map[28*28*j + i] = result;
        }
    } 
}
