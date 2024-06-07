#ifndef __LENET_5_CONVOLUTION_H__
#define __LENET_5_CONVOLUTION_H__

#include <cnn_features.h>
#include <filters.h>

void convolution(feature_t* batch, filter_t filter, feature_t* result);

#endif /* __LENET5_CONVOLUTION_H__ */
