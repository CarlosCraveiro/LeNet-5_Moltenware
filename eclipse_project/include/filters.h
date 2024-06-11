#ifndef __LENET_5_FILTERS_H__
#define __LENET_5_FILTERS_H__

#include <cnn_features.h>

typedef struct Filter filter_t;

struct Filter {
    feature_t* filters;
    int size;
    int number;
    int channels;
    int channel_number;
    int numbers;
};

#endif /* __LENET_5_FILTERS_H__ */
