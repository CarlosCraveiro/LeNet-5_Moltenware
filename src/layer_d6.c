#include <layers.h>
#include <activation.h>

void layer_d6(feature_t* input, feature_t* weights, feature_t* biases, feature_t* output) {
    for(int i = 0; i < D6_OUTPUT_SIZE; i++) {
        feature_t sum;
        initialize_feature(&sum);
        for(int j = 0; j < D6_INPUT_SIZE; j++) {
            feature_t buffer;
            multiply_feature(input[j], weights[j*D6_INPUT_SIZE + i], &buffer);
            sum_feature(sum, buffer, &sum);
        }
        sum_feature(sum, biases[i], &sum);
        ReLU_feature(sum, &sum);
        output[i] = sum;
    }
}
