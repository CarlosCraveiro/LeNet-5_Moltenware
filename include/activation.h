#ifndef __LENET_5_ACTIVATION_H__
#define __LENET_5_ACTIVATION_H__
#include <cnn_features.h>

void ReLU_feature(feature_t input, feature_t* output);
void Softmax_feature(feature_t* input, int input_len, feature_t* output);

#endif /* __LENET_5_ACTIVATION_H__ */
