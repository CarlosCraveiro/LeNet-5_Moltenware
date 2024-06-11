#ifndef __LENET_5_FEATURES_H__
#define __LENET_5_FEATURES_H__

typedef float feature_t; // Change to fixed-point representation in the future

/* Encapsulates operations to facilitate later changes */
void multiply_feature(feature_t op1, feature_t op2, feature_t* result);
void divide_feture(feature_t op1, feature_t op2, feature_t* result);
void sum_feature(feature_t op1, feature_t op2, feature_t* result);
void subtract_feature(feature_t op1, feature_t op2, feature_t* result);
void initialize_feature(feature_t* feat);
int greater_than_feature(feature_t op1, feature_t op2);
void exponential_feature(feature_t exponent, feature_t* result);
void log_feature(feature_t input, feature_t* result);

#endif /* __LENET_5_FEATURES_H__ */
