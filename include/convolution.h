#ifndef __CONVOLUTION_H__
#define __CONVOLUTION_H__

#include <weigths.h>

void convolution(feature_t* batch, feature_t* filter, int size, feature_t* result);

#endif /* __CONVOLUTION_H__ */
