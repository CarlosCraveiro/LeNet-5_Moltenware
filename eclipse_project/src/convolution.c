#include <convolution.h>

void convolution(feature_t* batch, filter_t filter, feature_t* result) {
    feature_t sum;
    feature_t buffer;
    initialize_feature(&sum);

    int filter_number = filter.number;
    int filter_size = filter.size; 
    int filter_channel_number = filter.channel_number; 
    int filter_channels = filter.channels; 
    int filter_numbers = filter.numbers; 

    for(int i = 0; i < filter_size; i++) {
        for(int j = 0; j < filter_size; j++) {
            multiply_feature(
                    batch[i*filter_size +j]
                    , filter.filters[  
                        i * filter_size * filter_channels * filter_numbers
                        + j * filter_channels * filter_numbers
                        + filter_channel_number * filter_numbers
                        + filter_number
                    ]
                    , &buffer
            );
            
            sum_feature(sum, buffer, &sum); 
        }
    }
    *result = sum; 
}

void convolution_p(feature_t* batch, filter_t filter, feature_t* result, 
    int cpu_num, int cpu_id) 
{
    feature_t sum;
    feature_t buffer;
    initialize_feature(&sum);

    int filter_number = filter.number;
    int filter_size = filter.size; 
    int filter_channel_number = filter.channel_number; 
    int filter_channels = filter.channels; 
    int filter_numbers = filter.numbers;

    int start, end, size;
    size = filter_size/cpu_num;
    start = (cpu_id)*size;
    end = start+size; 

    for(int i = 0; i < filter_size; i++) {
        for(int j = 0; j < filter_size; j++) {
            multiply_feature(
                    batch[i*filter_size +j]
                    , filter.filters[  
                        i * filter_size * filter_channels * filter_numbers
                        + j * filter_channels * filter_numbers
                        + filter_channel_number * filter_numbers
                        + filter_number
                    ]
                    , &buffer
            );
            
            sum_feature(sum, buffer, &sum); 
        }
    }
    *result = sum; 
}