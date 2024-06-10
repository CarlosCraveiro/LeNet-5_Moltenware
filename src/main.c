#include <cnn_features.h>
#include <filters.h>
#include <convolution.h>
#include <layers.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_image(char* filename, int size, feature_t* image) {
    /* Open Image File */
    FILE* fd;
    fd = fopen(filename, "r");
    if (!fd) {
        printf("Cannot open file %s\n", filename);
        exit(1);
    }

    /* Initialize Image */
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if(fscanf(fd, "%f,", &image[i * size + j]) < 0) /* exit(1) */;
        }
    }
    
    fclose(fd);
}

void read_image_label(char* filename, int* label) { 
    FILE* fd;
    fd = fopen(filename, "r");
    if (!fd) {
        printf("Cannot open file %s\n", filename);
        exit(1);
    }

    if(fscanf(fd, "%d,", label) < 0) /* exit(1) */;
         
    fclose(fd);
}

void read_filters(char* filename, int num, int channels, int size, feature_t* filters) {
    
    FILE* fd = fopen(filename, "r");
    if (!fd) {
        printf("Cannot open file %s\n", filename);
        exit(1);
    }

    for(int i = 0; i < channels; i++) {
        for(int j = 0; j < size; j++) {
            for(int k = 0; k < size; k++) {
                for(int l = 0; l < num; l++) {
                    if(
                        (fscanf(fd, "%f," 
                            , &filters[ i*size*size*num + j*num*size + k*num + l ])) < 0
                    ) /* exit(1) */; 
                }
            }
        }
    } 
    
    fclose(fd); 
}

void read_weights(char* filename, int input_size, int output_size, feature_t* weights) {
    
    FILE* fd = fopen(filename, "r");
    if (!fd) {
        printf("Cannot open file %s\n", filename);
        exit(1);
    }

    for(int i = 0; i < input_size; i++) {
        for(int j = 0; j < output_size; j++) {
            if((fscanf(fd, "%f,", &weights[ i*output_size + j])) < 0) /* exit(1) */; 
        }
    } 
    
    fclose(fd); 
}

void read_biases(char* filename, int num, feature_t* biases) {
    FILE* fd = fopen(filename, "r");
    if (!fd) {
        printf("Cannot open file %s\n", filename);
        exit(1);
    }
    
    for(int i = 0; i < num; i++) {
        if((fscanf(fd, "%f", &biases[i])) < 0) /* exit(1) */;
    }
    
    fclose(fd);
}

void print_filters(char* logfilename, int num, int channels, int size, feature_t* filters) {
    FILE* fd = fopen(logfilename, "w+");
    if (!fd) {
        printf("Cannot open file %s\n", logfilename);
        exit(1);
    }

    for(int i = 0; i < channels; i++) {
        for(int j = 0; j < size; j++) {
            for(int k = 0; k < size; k++) {
                for(int l = 0; l < num; l++) {
                    char fmt_string[10];

                    if(l != (num - 1)) {
                        strcpy(fmt_string, "%.8f,");
                    } else {
                        strcpy(fmt_string, "%.8f");
                    }
                    
                    fprintf(fd, fmt_string, filters[ i*size*size*num + j*num*size + k*num + l ]); 
                }
                fprintf(fd, "\n");
            }
        }
    }
    
    fclose(fd);
}

void print_weights(char* logfilename, int input_size, int output_size, feature_t* weights) {
    FILE* fd = fopen(logfilename, "w+");
    if (!fd) {
        printf("Cannot open file %s\n", logfilename);
        exit(1);
    }

    for(int i = 0; i < input_size; i++) {
        for(int j = 0; j < output_size; j++) {
            char fmt_string[10];
            if(j != (input_size - 1)) {
                strcpy(fmt_string, "%.8f,");
            } else {
                strcpy(fmt_string, "%.8f");
            }
            fprintf(fd, "%f,", weights[ i*output_size + j]); 
        }
    } 
    
    fclose(fd);
}

void print_biases(char* logfilename, int num, feature_t* biases) {
    FILE* fd = fopen(logfilename, "w+");
    if (!fd) {
        printf("Cannot open file %s\n", logfilename);
        exit(1);
    }
    
    for(int i = 0; i < num; i++) {
        fprintf(fd, "%.8f\n", biases[i]);
    }
    
    fclose(fd);
}

void print_featuremaps(char* logfilename, int size_h, int size_v, int channels, feature_t* feat_map) {
    FILE* fd = fopen(logfilename, "w+");
    if (!fd) {
        printf("Cannot open file %s\n", logfilename);
        exit(1);
    }
    
    for(int i = 0; i < channels; i++) {
        fprintf(fd, "Channel %d\n", i);
        for(int j = 0; j < size_v; j++) {
            for(int k = 0; k < size_h; k++) {
                char fmt_string[10];
                if(k != (size_h - 1)) {
                    strcpy(fmt_string, "%.8f, ");
                } else {
                    strcpy(fmt_string, "%.8f");
                }

                fprintf(fd, fmt_string, feat_map[i*size_v*size_h + j*size_h + k]);
            }
            fprintf(fd, "\n");
        }
        fprintf(fd, "\n");
    }  
    
    fclose(fd);
}

int main(int argc, char* argv[]) {
    feature_t filters_c1[C1_NUMBER_OF_FILTERS*C1_INPUT_CHANNELS*CONV_FILTER_SIZE*CONV_FILTER_SIZE];
    feature_t biases_c1[C1_NUMBER_OF_FILTERS];
    feature_t filters_c3[C3_NUMBER_OF_FILTERS*C3_INPUT_CHANNELS*CONV_FILTER_SIZE*CONV_FILTER_SIZE];
    feature_t biases_c3[C3_NUMBER_OF_FILTERS];
    feature_t weights_d5[D5_INPUT_SIZE*D5_OUTPUT_SIZE];
    feature_t biases_d5[D5_OUTPUT_SIZE];
    feature_t weights_d6[D6_INPUT_SIZE*D6_OUTPUT_SIZE];
    feature_t biases_d6[D6_OUTPUT_SIZE];
    feature_t weights_d7[D7_INPUT_SIZE*D7_OUTPUT_SIZE];
    feature_t biases_d7[D7_OUTPUT_SIZE];

    feature_t image[IMAGE_SIZE*IMAGE_SIZE];
    int image_label;
    feature_t output_c1[C1_OUTPUT_CHANNELS*C1_OUTPUT_SIZE*C1_OUTPUT_SIZE];
    feature_t output_p2[P2_OUTPUT_CHANNELS*P2_OUTPUT_SIZE*P2_OUTPUT_SIZE];
    feature_t output_c3[C3_OUTPUT_CHANNELS*C3_OUTPUT_SIZE*C3_OUTPUT_SIZE];
    feature_t output_p4[P4_OUTPUT_CHANNELS*P4_OUTPUT_SIZE*P4_OUTPUT_SIZE];
    feature_t output_d5[D5_OUTPUT_CHANNELS*D5_OUTPUT_SIZE];
    feature_t output_d6[D6_OUTPUT_CHANNELS*D6_OUTPUT_SIZE];
    feature_t output_d7[D7_OUTPUT_CHANNELS*D7_OUTPUT_SIZE];
     
    char c1_filters_filename[42] = "weights/c1_filters.csv";
    char c1_biases_filename[42] = "weights/c1_biases.csv";
    char c3_filters_filename[42] = "weights/c3_filters.csv";
    char c3_biases_filename[42] = "weights/c3_biases.csv";
    char d5_weights_filename[42] = "weights/d5_weights.csv";
    char d5_biases_filename[42] = "weights/d5_biases.csv";
    char d6_weights_filename[42] = "weights/d6_weights.csv";
    char d6_biases_filename[42] = "weights/d6_biases.csv";
    char d7_weights_filename[42] = "weights/d7_weights.csv";
    char d7_biases_filename[42] = "weights/d7_biases.csv";

    /* DEBUG Files */
    char c1_filters_logfilename[42]    =   "debug/log_c1_filters.csv";
    char c1_biases_logfilename[42]     =   "debug/log_c1_biases.csv";
    char c1_output_logfilename[42]     =   "debug/log_c1_output.csv";
    char p2_output_logfilename[42]     =   "debug/log_p2_output.csv";
    char c3_filters_logfilename[42]    =   "debug/log_c3_filters.csv";
    char c3_biases_logfilename[42]     =   "debug/log_c3_biases.csv";
    char c3_output_logfilename[42]     =   "debug/log_c3_output.csv";
    char p4_output_logfilename[42]     =   "debug/log_p4_output.csv";
    char d5_weights_logfilename[42]    =   "debug/log_d5_weights.csv";
    char d5_biases_logfilename[42]     =   "debug/log_d5_biases.csv";
    char d5_output_logfilename[42]     =   "debug/log_d5_output.csv";
    char d6_weights_logfilename[42]    =   "debug/log_d6_weights.csv";
    char d6_biases_logfilename[42]     =   "debug/log_d6_biases.csv";
    char d6_output_logfilename[42]     =   "debug/log_d6_output.csv";
    char d7_weights_logfilename[42]    =   "debug/log_d7_weights.csv";
    char d7_biases_logfilename[42]     =   "debug/log_d7_biases.csv";
    char d7_output_logfilename[42]     =   "debug/log_d7_output.csv";

    if(argc != 3) {
        printf("Incorrect number of arguments!\n\n");
        printf("Correct usage:\n");
        printf("\t%s <input_image_file_in_csv_format> <input_image_label_file>\n", argv[0]);
        return 1;
    }

    read_image(argv[1], IMAGE_SIZE, image);
    read_image_label(argv[2], &image_label);
    
    /* Reads Layer C1 Parameters */ 
    read_filters(
        c1_filters_filename, 
        C1_NUMBER_OF_FILTERS,
        C1_INPUT_CHANNELS,
        CONV_FILTER_SIZE,
        filters_c1
    );
     
    read_biases(c1_biases_filename, C1_NUMBER_OF_FILTERS, biases_c1);
    
    /* Reads Layer C3 Parameters */ 
    read_filters(
        c3_filters_filename, 
        C3_NUMBER_OF_FILTERS,
        C3_INPUT_CHANNELS,
        CONV_FILTER_SIZE,
        filters_c3
    );
     
    read_biases(c3_biases_filename, C3_NUMBER_OF_FILTERS, biases_c3);

    /* Reads Layer D5 Parameters */
    read_weights(d5_weights_filename, D5_INPUT_SIZE, D5_OUTPUT_SIZE, weights_d5);
    read_biases(d5_biases_filename, D5_OUTPUT_SIZE, biases_d5);
    
    /* Reads Layer D6 Parameters */
    read_weights(d6_weights_filename, D6_INPUT_SIZE, D6_OUTPUT_SIZE, weights_d6);
    read_biases(d6_biases_filename, D5_OUTPUT_SIZE, biases_d6);

    /* Reads Layer D7 Parameters */
    read_weights(d7_weights_filename, D7_INPUT_SIZE, D7_OUTPUT_SIZE, weights_d7);
    read_biases(d7_biases_filename, D7_OUTPUT_SIZE, biases_d7);

    /* DEBUG */
    print_filters(c1_filters_logfilename, C1_NUMBER_OF_FILTERS, C1_INPUT_CHANNELS, CONV_FILTER_SIZE, filters_c1);
    print_biases(c1_biases_logfilename, C1_NUMBER_OF_FILTERS, biases_c1);
    print_filters(c3_filters_logfilename, C3_NUMBER_OF_FILTERS, C3_INPUT_CHANNELS, CONV_FILTER_SIZE, filters_c3);
    print_biases(c3_biases_logfilename, C3_NUMBER_OF_FILTERS, biases_c3);
    print_weights(d5_weights_logfilename, D5_INPUT_SIZE, D5_OUTPUT_SIZE, weights_d5);
    print_biases(d5_biases_logfilename, D5_OUTPUT_SIZE, biases_d5);
    print_weights(d6_weights_logfilename, D6_INPUT_SIZE, D6_OUTPUT_SIZE, weights_d6);
    print_biases(d6_biases_logfilename, D6_OUTPUT_SIZE, biases_d6);
    print_weights(d7_weights_logfilename, D7_INPUT_SIZE, D7_OUTPUT_SIZE, weights_d7);
    print_biases(d7_biases_logfilename, D7_OUTPUT_SIZE, biases_d7);
    /* END DEBUG */
    
    /* The Neural Network LeNet 5 */ 
    layer_c1(image, filters_c1, biases_c1, output_c1);
    layer_p2(output_c1, output_p2);
    layer_c3(output_p2, filters_c3, biases_c3, output_c3);
    layer_p4(output_c3, output_p4);
    layer_d5(output_p4, weights_d5, biases_d5, output_d5);
    layer_d6(output_d5, weights_d6, biases_d6, output_d6);
    layer_d7(output_d6, weights_d7, biases_d7, output_d7);
    
    /* DEBUG */
    print_featuremaps(c1_output_logfilename, C1_OUTPUT_SIZE, C1_OUTPUT_SIZE, C1_OUTPUT_CHANNELS, output_c1);
    print_featuremaps(p2_output_logfilename, P2_OUTPUT_SIZE, P2_OUTPUT_SIZE, P2_OUTPUT_CHANNELS, output_p2);
    print_featuremaps(c3_output_logfilename, C3_OUTPUT_SIZE, C3_OUTPUT_SIZE, C3_OUTPUT_CHANNELS, output_c3);
    print_featuremaps(p4_output_logfilename, P4_OUTPUT_SIZE, P4_OUTPUT_SIZE, P4_OUTPUT_CHANNELS, output_p4);
    print_featuremaps(d5_output_logfilename, D5_OUTPUT_SIZE, 1, D5_OUTPUT_CHANNELS, output_d5);
    print_featuremaps(d6_output_logfilename, D6_OUTPUT_SIZE, 1, D6_OUTPUT_CHANNELS, output_d6);
    print_featuremaps(d7_output_logfilename, D7_OUTPUT_SIZE, 1, D7_OUTPUT_CHANNELS, output_d7);
    /* END DEBUG */

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
    printf("\t Correct label: %d\n", image_label);
    printf("\t Predicted label: %d (%f%%)\n", class, class_prob*100);
    
    return 0;
}
