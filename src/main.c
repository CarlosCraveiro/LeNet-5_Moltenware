#include <stdio.h>

#include <cnn_features.h>
#include <filters.h>
#include <convolution.h>
#include <layers.h>
#include <c1_params.h>
#include <c3_params.h>
#include <d5_params.h>
#include <d6_params.h>
#include <d7_params.h>
#include <test_image_1.h>

int main(int argc, char* argv[]) {
    
    //total size: 180 kB -> use all in ram at the same time. 
    feature_t output_c1[C1_OUTPUT_CHANNELS*C1_OUTPUT_SIZE*C1_OUTPUT_SIZE];
    feature_t output_p2[P2_OUTPUT_CHANNELS*P2_OUTPUT_SIZE*P2_OUTPUT_SIZE];
    feature_t output_c3[C3_OUTPUT_CHANNELS*C3_OUTPUT_SIZE*C3_OUTPUT_SIZE];
    feature_t output_p4[P4_OUTPUT_CHANNELS*P4_OUTPUT_SIZE*P4_OUTPUT_SIZE];
    feature_t output_flattening[P4_OUTPUT_CHANNELS*P4_OUTPUT_SIZE*P4_OUTPUT_SIZE];
    feature_t output_d5[D5_OUTPUT_CHANNELS*D5_OUTPUT_SIZE];
    feature_t output_d6[D6_OUTPUT_CHANNELS*D6_OUTPUT_SIZE];
    feature_t output_d7[D7_OUTPUT_CHANNELS*D7_OUTPUT_SIZE];
  
    
    /* The Neural Network LeNet 5 */ 
    layer_c1(test_image_1, filters_c1, biases_c1, output_c1);
    layer_p2(output_c1, output_p2);
    layer_c3(output_p2, filters_c3, biases_c3, output_c3);
    layer_p4(output_c3, output_p4);
   
    layer_flattening(output_p4, output_flattening);
 
    layer_d5(output_flattening, weights_d5, biases_d5, output_d5);
    layer_d6(output_d5, weights_d6, biases_d6, output_d6);
    layer_d7(output_d6, weights_d7, biases_d7, output_d7);
    
    /* Interpret Results */
    feature_t sum;
    initialize_feature(&sum);

    int class = 0;
    feature_t class_prob;
    initialize_feature(&class_prob);

    printf("OUTPUT D7 (Probability Vector):\n"); 
    for(int i = 0; i < D7_OUTPUT_SIZE; i++) {
        printf("%f ", output_d7[i]);
        sum_feature(sum, output_d7[i], &sum);
        if(greater_than_feature(output_d7[i], class_prob)) {
            class = i;
            class_prob = output_d7[i];
        }
    }
   
    printf("\n");
    printf("Total sum of probabilities: %f\n" , sum);
    
    printf("Result:\n"); 
    printf("\t Correct label: %d\n", test_label_1);
    printf("\t Predicted label: %d (%f%%)\n", class, class_prob*100);
    
    return 0;
}
