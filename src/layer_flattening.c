#include <layers.h>

void layer_flattening(feature_t* input, feature_t* output) {
    for(int i = 0; i < FLAT_INPUT_SIZE; i++) {
        for(int j = 0; j < FLAT_INPUT_SIZE; j++) {
            for(int k = 0; k < FLAT_INPUT_CHANNELS; k++) {
                output[ i*FLAT_INPUT_SIZE*FLAT_INPUT_CHANNELS + j*FLAT_INPUT_CHANNELS + k ] = input[k*FLAT_INPUT_SIZE*FLAT_INPUT_SIZE + i*FLAT_INPUT_SIZE + j];
            }
        }
    }
}
