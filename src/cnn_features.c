#include <cnn_features.h>
#include <math.h>
void multiply_feature(feature_t op1, feature_t op2, feature_t* result) {
    *result = op1 * op2;
}

void divide_feture(feature_t op1, feature_t op2, feature_t* result) {
    *result = op1 / op2;
}

void sum_feature(feature_t op1, feature_t op2, feature_t* result) {
    *result = op1 + op2;
}

void subtract_feature(feature_t op1, feature_t op2, feature_t* result) {
    *result = op1 - op2;
}

void initialize_feature(feature_t* feat) {
    *feat = 0;
}

int greater_than_feature(feature_t op1, feature_t op2) {
    return op1 > op2;
}

void exponential_feature(feature_t exponent, feature_t* result) {
   *result = expf(exponent); 
}

void log_feature(feature_t input, feature_t* result) {
    *result = logf(input);
}
