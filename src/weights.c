#include <weigths.h>

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
