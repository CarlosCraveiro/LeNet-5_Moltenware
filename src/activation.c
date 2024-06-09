#include <activation.h>

void ReLU_feature(feature_t input, feature_t* output) {
    feature_t zero;
    initialize_feature(&zero);
    *output = (greater_than_feature(input, zero))? input : zero;
}

void Softmax_feature(feature_t* input, int input_len, feature_t* output) {
    feature_t acc = input[0];
    for (int i = 1; i < input_len; i++) {
        if (greater_than_feature(input[i], acc)) {
        acc = input[i];
        }
    }

    feature_t sum;
    initialize_feature(&sum);
    for (int i = 0; i < input_len; i++) {
        feature_t buffer;
        subtract_feature(input[i], acc, &buffer);
        exponential_feature(buffer, &buffer);
        sum_feature(sum, buffer, &sum);
    }

    feature_t offset;
    log_feature(sum, &offset);
    sum_feature(offset, acc, &offset);
    for (int i = 0; i < input_len; i++) {
        feature_t buffer;
        subtract_feature(input[i], offset, &buffer);
        exponential_feature(buffer, &buffer);
        output[i] = buffer;
    } 
}
