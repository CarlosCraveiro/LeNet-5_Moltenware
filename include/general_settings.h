#ifndef __LENET_5_GENERAL_SETTINGS_H__
#define __LENET_5_GENERAL_SETTINGS_H__

/* Some relevant observations:
 *
 * We are assuming that the stride at convolution layers are 1 and the stride of the pooling 
 * layers are the same size of the filter. Also, we are omitting the flattening layer due to the 
 * way we are storing our data.
 * */

/* Here are the settings of the Neural Network */

#define IMAGE_SIZE 28

/* Filters */
#define CONV_FILTER_SIZE 5
#define POLL_FILTER_SIZE 2
#define C1_NUMBER_OF_FILTERS 6
#define C3_NUMBER_OF_FILTERS 16

/* C1 Layer */
#define C1_INPUT_SIZE ( IMAGE_SIZE )
#define C1_INPUT_CHANNELS 1
#define C1_OUTPUT_SIZE ( C1_INPUT_SIZE - CONV_FILTER_SIZE + 1 )
#define C1_OUTPUT_CHANNELS ( C1_NUMBER_OF_FILTERS )

/* P2 Layer */
#define P2_INPUT_SIZE ( C1_OUTPUT_SIZE )
#define P2_INPUT_CHANNELS ( C1_OUTPUT_CHANNELS )
#define P2_OUTPUT_SIZE ( P2_INPUT_SIZE / 2 )
#define P2_OUTPUT_CHANNELS ( P2_INPUT_CHANNELS )

/* C3 Layer */
#define C3_INPUT_SIZE ( P2_OUTPUT_SIZE )
#define C3_INPUT_CHANNELS ( P2_OUTPUT_CHANNELS )
#define C3_OUTPUT_SIZE ( C3_INPUT_SIZE - CONV_FILTER_SIZE + 1 )
#define C3_OUTPUT_CHANNELS ( C3_NUMBER_OF_FILTERS )

/* P4 Layer */
#define P4_INPUT_SIZE ( C3_OUTPUT_SIZE )
#define P4_INPUT_CHANNELS ( C3_OUTPUT_CHANNELS )
#define P4_OUTPUT_SIZE ( P4_INPUT_SIZE / 2 )
#define P4_OUTPUT_CHANNELS ( P4_INPUT_CHANNELS )

/* Flattening Layer */

/* D5 Layer */
#define D5_INPUT_SIZE ( P4_OUTPUT_SIZE * P4_OUTPUT_SIZE * C3_NUMBER_OF_FILTERS )
#define D5_INPUT_CHANNELS 1
#define D5_OUTPUT_SIZE 120
#define D5_OUTPUT_CHANNELS ( D5_INPUT_CHANNELS )

/* D6 Layer */
#define D6_INPUT_SIZE ( D5_OUTPUT_SIZE )
#define D6_INPUT_CHANNELS ( D5_OUTPUT_CHANNELS )
#define D6_OUTPUT_SIZE 84
#define D6_OUTPUT_CHANNELS ( D6_INPUT_CHANNELS )

/* D7 Layer */
#define D7_INPUT_SIZE ( D6_OUTPUT_SIZE )
#define D7_INPUT_CHANNELS ( D6_OUTPUT_CHANNELS )
#define D7_OUTPUT_SIZE 10
#define D7_OUTPUT_CHANNELS ( D7_INPUT_CHANNELS )

#endif /* __LENET_5_GENERAL_SETTINGS_H__ */
