#ifndef __LENET_5_LAYERS_H__
#define __LENET_5_LAYERS_H__
#include <cnn_features.h>
#include <filters.h>

void layer_c1(feature_t* input, feature_t* filters, feature_t* output);
void layer_p2(feature_t* input, feature_t* output);
void layer_c3(feature_t* input, feature_t* filters, feature_t* output);
//void layer_p4(feature_t** input, feature_t** output);
//void layer_d5(feature_t** input, feature_t* output);
//void layer_d6(feature_t* input, feature_t* output);

#endif /* __LENET_5_LAYERS_H__ */
