#include <layers.h>

void layer_p2(feature_t* input, feature_t* output) {
    feature_t batch[C1_NUMBER_OF_FILTERS][P2_OUTPUT_SIZE*P2_OUTPUT_SIZE][POLL_FILTER_SIZE*POLL_FILTER_SIZE];
    
    for(int h = 0; h < C1_NUMBER_OF_FILTERS; h++) {
        for(int i = 0; i < P2_OUTPUT_SIZE; i++) {
            for(int j = 0; j < P2_OUTPUT_SIZE; j++) {
                for(int k = 0; k < POLL_FILTER_SIZE; k++) {
                    for(int l = 0; l < POLL_FILTER_SIZE; l++) {
                        batch[h][i*P2_OUTPUT_SIZE + j][k*POLL_FILTER_SIZE + l] 
                            = input[h*P2_INPUT_SIZE*P2_INPUT_SIZE + i*POLL_FILTER_SIZE*P2_INPUT_SIZE + k*P2_INPUT_SIZE + POLL_FILTER_SIZE*j + l];
                    }
                }
            }
        }
    }
    
    for(int h = 0; h < C1_NUMBER_OF_FILTERS; h++) {
        for(int i = 0; i < P2_OUTPUT_SIZE*P2_OUTPUT_SIZE; i++) {
            int max_poll = 0; // Only positive values allowed (Re-LU)
            for(int j = 0; j < POLL_FILTER_SIZE*POLL_FILTER_SIZE; j++) {
                max_poll = (batch[h][i][j] > max_poll)? batch[h][i][j] : max_poll;
            }
            output[h*P2_OUTPUT_SIZE*P2_OUTPUT_SIZE + i] = max_poll;
        }
    }
}
