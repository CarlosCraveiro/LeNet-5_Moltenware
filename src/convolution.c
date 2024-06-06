#include <convolution.h>

void convolution(feature_t* batch, feature_t* filter, int size, feature_t* result) {
    feature_t sum;
    feature_t buffer;
    initialize_feature(&sum);
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            multiply_feature(batch[i*size +j], filter[i*size + j], &buffer);
            sum_feature(sum, buffer, &sum); 
        }
    }
    *result = sum;
}
