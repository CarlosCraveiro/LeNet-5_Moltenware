#include <layers.h>
#include <convolution.h>

void layer_c1(feature_t* input, feature_t* filter, feature_t** output) {
    int size = 5;
    
    feature_t batchs[28*28][25];

    for(int i = 0; i < 28; i++) {
        for(int j = 0; j < 28; j++) {
            for(int k = 0; k < 5; k++) {
                for(int l = 0; l < 5; l++) {
                    batchs[28*i + j][k*5 + l] = input[(i + l)*32 + j + l];
                }
            }
        }
    }
}
