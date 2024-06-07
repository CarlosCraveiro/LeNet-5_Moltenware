#include <layers.h>

void layer_p2(feature_t* input, feature_t* output) {
    feature_t batch[6][14*14][2*2];
    
    for(int h = 0; h < 6; h++) {
        for(int i = 0; i < 14; i++) {
            for(int j = 0; j < 14; j++) {
                for(int k = 0; k < 2; k++) {
                    for(int l = 0; l < 2; l++) {
                        batch[h][i*14 + j][k*2 + l] = input[h*28*28 + i*2*28 + k*28 + 2*j + l];
                    }
                }
            }
        }
    }
    
    for(int h = 0; h < 6; h++) {
        for(int i = 0; i < 14*14; i++) {
            int max_poll = 0; // Only positive values allowed (Re-LU)
            for(int j = 0; j < 4; j++) {
                max_poll = (batch[h][i][j] > max_poll)? batch[h][i][j] : max_poll;
            }
            output[h*14*14 + i] = max_poll;
        }
    }
}
