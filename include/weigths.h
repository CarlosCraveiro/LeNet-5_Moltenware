#ifndef __WEIGTHS_H__
#define __WEIGTHS_H__

typedef float feature_t; // Change to fixed-point representation in the future 

/* Encapsulates operations to facilitate later changes */
void multiply_feature(feature_t op1, feature_t op2, feature_t* result);
void divide_feture(feature_t op1, feature_t op2, feature_t* result);
void sum_feature(feature_t op1, feature_t op2, feature_t* result);
void subtract_feature(feature_t op1, feature_t op2, feature_t* result);
void initialize_feature(feature_t* feat);

#endif /* __WEIGTHS_H__ */
