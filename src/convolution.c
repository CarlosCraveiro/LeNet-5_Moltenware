#include <convolution.h>
#include <stdio.h>

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
            printf("%f * %f = %f\n"
                    , batch[i*filter_size +j]
                    , filter.filters[  
                        filter_channel_number * filter_size * filter_size * filter_numbers
                        + i * filter_size * filter_numbers
                        + j * filter_numbers
                        + filter_number
                    ]
                    , buffer); 
            sum_feature(sum, buffer, &sum); 
        }
    }
    printf("Sum = %f\n", sum);
    *result = sum; 
}
