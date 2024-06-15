#include <layers.h>

void layer_p4(feature_t* input, feature_t* output, int cpu_num, int cpu_id) 
{
    feature_t batch[P4_OUTPUT_CHANNELS][P4_OUTPUT_SIZE*P4_OUTPUT_SIZE][POLL_FILTER_SIZE*POLL_FILTER_SIZE];

    int start, end, size;
    size = C1_INPUT_SIZE/cpu_num;
    start = (cpu_id)*size;
    end = start+size;

    for(int h = 0; h < P4_OUTPUT_CHANNELS; h++) {
        for(int i = start; i < end; i++) {
            for(int j = start; j < end; j++) {
                for(int k = 0; k < POLL_FILTER_SIZE; k++) {
                    for(int l = 0; l < POLL_FILTER_SIZE; l++) {
                        batch[h][i*end + j][k*POLL_FILTER_SIZE + l] 
                            = input[h*P4_INPUT_SIZE*P4_INPUT_SIZE + i*POLL_FILTER_SIZE*P4_INPUT_SIZE + k*P4_INPUT_SIZE + POLL_FILTER_SIZE*j + l];
                    }
                }
            }
        }
    }
    
    for(int h = 0; h < P4_OUTPUT_CHANNELS; h++) {
        for(int i = start; i < end*end; i++) {
            feature_t max_poll;
            initialize_feature(&max_poll); // Only positive values allowed (Re-LU) 
            for(int j = 0; j < POLL_FILTER_SIZE*POLL_FILTER_SIZE; j++) {
                max_poll = (batch[h][i][j] > max_poll)? batch[h][i][j] : max_poll;
            }
            output[h*end*end + i] = max_poll;
        }
    }
}
