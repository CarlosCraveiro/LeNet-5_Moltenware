#include <layers.h>
#include <convolution.h>
void layer_c3(feature_t* input, feature_t* filters, feature_t* output) {
    feature_t batchs[6][10*10][25];

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            for(int k = 0; k < 5; k++) {
                for(int l = 0; l < 5; l++) {
                    for(int m = 0; m < 6; m++) {
                        batchs[m][10*i + j][k*5 + l] = input[m*14*14 + (i + k)*14 + j + l];
                    }
                }
            }
        }
    }
    
    for(int i = 0; i < 10 * 10; i++) {
        for(int j = 0; j < 16; j++) {
            filter_t filter;
            filter.filters = filters;
            filter.size = 5;
            filter.number = j;

            feature_map_t feat_map;
            feat_map.map = output;
            feat_map.size = 10;
            feat_map.number = i;
            
            feature_t sum;
            feature_t buffer;

            initialize_feature(&sum);

            for(int k = 0; k < 6; k++) {
                convolution(batchs[k][i], filter, &buffer);
                sum_feature(sum, buffer, &sum);
            }

            feat_map.map[10*10*j + i] = sum;
            
        }
    } 
}
