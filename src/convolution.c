#include <convolution.h>

void convolution(feature_t* batch, filter_t filter, feature_map_t result) {
    feature_t sum;
    feature_t buffer;
    initialize_feature(&sum);

    int filter_number = filter.number;
    int filter_size = filter.size;
    int result_index = result.number;
    int feature_size = result.size;

    for(int i = 0; i < filter_size; i++) {
        for(int j = 0; j < filter_size; j++) {
            multiply_feature(batch[i*filter_size +j], filter.filters[filter_number*filter_size*filter_size + i*filter_size + j], &buffer);
            sum_feature(sum, buffer, &sum); 
        }
    }

    result.map[feature_size*feature_size*filter_number + result_index] = sum;
}
