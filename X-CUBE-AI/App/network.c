/**
  ******************************************************************************
  * @file    network.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Tue Jan 17 07:34:10 2023
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */


#include "network.h"

#include "ai_platform_interface.h"
#include "ai_math_helpers.h"

#include "core_common.h"
#include "core_convert.h"

#include "layers.h"



/*
#define AI_TOOLS_VERSION_MAJOR 6
#define AI_TOOLS_VERSION_MINOR 0
#define AI_TOOLS_VERSION_MICRO 0
#define AI_TOOLS_VERSION_EXTRA "RC6"

*/

/*
#define AI_TOOLS_API_VERSION_MAJOR 1
#define AI_TOOLS_API_VERSION_MINOR 4
#define AI_TOOLS_API_VERSION_MICRO 0
*/

#undef AI_NET_OBJ_INSTANCE
#define AI_NET_OBJ_INSTANCE g_network
 
#undef AI_NETWORK_MODEL_SIGNATURE
#define AI_NETWORK_MODEL_SIGNATURE     "83c7559f4146e51ccea1d16e5c97bdb9"

#ifndef AI_TOOLS_REVISION_ID
#define AI_TOOLS_REVISION_ID     ""
#endif

#undef AI_TOOLS_DATE_TIME
#define AI_TOOLS_DATE_TIME   "Tue Jan 17 07:34:10 2023"

#undef AI_TOOLS_COMPILE_TIME
#define AI_TOOLS_COMPILE_TIME    __DATE__ " " __TIME__

#undef AI_NETWORK_N_BATCHES
#define AI_NETWORK_N_BATCHES         (1)

/**  Forward network declaration section  *************************************/
AI_STATIC ai_network AI_NET_OBJ_INSTANCE;


/**  Forward network array declarations  **************************************/
AI_STATIC ai_array input_1_output_array;   /* Array #0 */
AI_STATIC ai_array conv2d_1_output_array;   /* Array #1 */
AI_STATIC ai_array conv2d_3_output_array;   /* Array #2 */
AI_STATIC ai_array conv2d_4_output_array;   /* Array #3 */
AI_STATIC ai_array conv2d_6_output_array;   /* Array #4 */
AI_STATIC ai_array conv2d_7_output_array;   /* Array #5 */
AI_STATIC ai_array conv2d_9_output_array;   /* Array #6 */
AI_STATIC ai_array conv2d_10_output_array;   /* Array #7 */
AI_STATIC ai_array conv2d_12_output_array;   /* Array #8 */
AI_STATIC ai_array conv2d_13_output_array;   /* Array #9 */
AI_STATIC ai_array conv2d_15_output_array;   /* Array #10 */
AI_STATIC ai_array conv2d_16_output_array;   /* Array #11 */
AI_STATIC ai_array conv2d_18_output_array;   /* Array #12 */
AI_STATIC ai_array conv2d_19_output_array;   /* Array #13 */
AI_STATIC ai_array conv2d_21_output_array;   /* Array #14 */
AI_STATIC ai_array conv2d_22_output_array;   /* Array #15 */
AI_STATIC ai_array conv2d_23_output_array;   /* Array #16 */
AI_STATIC ai_array conv2d_24_output_array;   /* Array #17 */
AI_STATIC ai_array conv2d_26_output_array;   /* Array #18 */
AI_STATIC ai_array conv2d_27_output_array;   /* Array #19 */
AI_STATIC ai_array conv2d_28_output_array;   /* Array #20 */
AI_STATIC ai_array conv2d_29_output_array;   /* Array #21 */
AI_STATIC ai_array conv2d_31_output_array;   /* Array #22 */
AI_STATIC ai_array conv2d_32_output_array;   /* Array #23 */
AI_STATIC ai_array conv2d_33_output_array;   /* Array #24 */
AI_STATIC ai_array conv2d_34_output_array;   /* Array #25 */
AI_STATIC ai_array conv2d_36_output_array;   /* Array #26 */
AI_STATIC ai_array conv2d_37_output_array;   /* Array #27 */
AI_STATIC ai_array conv2d_38_output_array;   /* Array #28 */
AI_STATIC ai_array conv2d_39_output_array;   /* Array #29 */
AI_STATIC ai_array conv2d_41_output_array;   /* Array #30 */
AI_STATIC ai_array conv2d_42_output_array;   /* Array #31 */
AI_STATIC ai_array conv2d_43_output_array;   /* Array #32 */
AI_STATIC ai_array conv2d_44_output_array;   /* Array #33 */
AI_STATIC ai_array conv2d_46_output_array;   /* Array #34 */
AI_STATIC ai_array conv2d_47_output_array;   /* Array #35 */
AI_STATIC ai_array conv2d_48_output_array;   /* Array #36 */
AI_STATIC ai_array conv2d_49_output_array;   /* Array #37 */
AI_STATIC ai_array conv2d_51_output_array;   /* Array #38 */
AI_STATIC ai_array conv2d_52_output_array;   /* Array #39 */
AI_STATIC ai_array conv2d_53_output_array;   /* Array #40 */
AI_STATIC ai_array conv2d_54_output_array;   /* Array #41 */
AI_STATIC ai_array dense_57_output_array;   /* Array #42 */
AI_STATIC ai_array dense_57_fmt_output_array;   /* Array #43 */
AI_STATIC ai_array nl_58_output_array;   /* Array #44 */
AI_STATIC ai_array conv2d_1_weights_array;   /* Array #45 */
AI_STATIC ai_array conv2d_1_bias_array;   /* Array #46 */
AI_STATIC ai_array conv2d_3_weights_array;   /* Array #47 */
AI_STATIC ai_array conv2d_3_bias_array;   /* Array #48 */
AI_STATIC ai_array conv2d_4_weights_array;   /* Array #49 */
AI_STATIC ai_array conv2d_4_bias_array;   /* Array #50 */
AI_STATIC ai_array conv2d_6_weights_array;   /* Array #51 */
AI_STATIC ai_array conv2d_6_bias_array;   /* Array #52 */
AI_STATIC ai_array conv2d_7_weights_array;   /* Array #53 */
AI_STATIC ai_array conv2d_7_bias_array;   /* Array #54 */
AI_STATIC ai_array conv2d_9_weights_array;   /* Array #55 */
AI_STATIC ai_array conv2d_9_bias_array;   /* Array #56 */
AI_STATIC ai_array conv2d_10_weights_array;   /* Array #57 */
AI_STATIC ai_array conv2d_10_bias_array;   /* Array #58 */
AI_STATIC ai_array conv2d_12_weights_array;   /* Array #59 */
AI_STATIC ai_array conv2d_12_bias_array;   /* Array #60 */
AI_STATIC ai_array conv2d_13_weights_array;   /* Array #61 */
AI_STATIC ai_array conv2d_13_bias_array;   /* Array #62 */
AI_STATIC ai_array conv2d_15_weights_array;   /* Array #63 */
AI_STATIC ai_array conv2d_15_bias_array;   /* Array #64 */
AI_STATIC ai_array conv2d_16_weights_array;   /* Array #65 */
AI_STATIC ai_array conv2d_16_bias_array;   /* Array #66 */
AI_STATIC ai_array conv2d_18_weights_array;   /* Array #67 */
AI_STATIC ai_array conv2d_18_bias_array;   /* Array #68 */
AI_STATIC ai_array conv2d_19_weights_array;   /* Array #69 */
AI_STATIC ai_array conv2d_19_bias_array;   /* Array #70 */
AI_STATIC ai_array conv2d_21_weights_array;   /* Array #71 */
AI_STATIC ai_array conv2d_21_bias_array;   /* Array #72 */
AI_STATIC ai_array conv2d_22_weights_array;   /* Array #73 */
AI_STATIC ai_array conv2d_22_bias_array;   /* Array #74 */
AI_STATIC ai_array conv2d_23_weights_array;   /* Array #75 */
AI_STATIC ai_array conv2d_23_bias_array;   /* Array #76 */
AI_STATIC ai_array conv2d_24_weights_array;   /* Array #77 */
AI_STATIC ai_array conv2d_24_bias_array;   /* Array #78 */
AI_STATIC ai_array conv2d_26_weights_array;   /* Array #79 */
AI_STATIC ai_array conv2d_26_bias_array;   /* Array #80 */
AI_STATIC ai_array conv2d_27_weights_array;   /* Array #81 */
AI_STATIC ai_array conv2d_27_bias_array;   /* Array #82 */
AI_STATIC ai_array conv2d_28_weights_array;   /* Array #83 */
AI_STATIC ai_array conv2d_28_bias_array;   /* Array #84 */
AI_STATIC ai_array conv2d_29_weights_array;   /* Array #85 */
AI_STATIC ai_array conv2d_29_bias_array;   /* Array #86 */
AI_STATIC ai_array conv2d_31_weights_array;   /* Array #87 */
AI_STATIC ai_array conv2d_31_bias_array;   /* Array #88 */
AI_STATIC ai_array conv2d_32_weights_array;   /* Array #89 */
AI_STATIC ai_array conv2d_32_bias_array;   /* Array #90 */
AI_STATIC ai_array conv2d_33_weights_array;   /* Array #91 */
AI_STATIC ai_array conv2d_33_bias_array;   /* Array #92 */
AI_STATIC ai_array conv2d_34_weights_array;   /* Array #93 */
AI_STATIC ai_array conv2d_34_bias_array;   /* Array #94 */
AI_STATIC ai_array conv2d_36_weights_array;   /* Array #95 */
AI_STATIC ai_array conv2d_36_bias_array;   /* Array #96 */
AI_STATIC ai_array conv2d_37_weights_array;   /* Array #97 */
AI_STATIC ai_array conv2d_37_bias_array;   /* Array #98 */
AI_STATIC ai_array conv2d_38_weights_array;   /* Array #99 */
AI_STATIC ai_array conv2d_38_bias_array;   /* Array #100 */
AI_STATIC ai_array conv2d_39_weights_array;   /* Array #101 */
AI_STATIC ai_array conv2d_39_bias_array;   /* Array #102 */
AI_STATIC ai_array conv2d_41_weights_array;   /* Array #103 */
AI_STATIC ai_array conv2d_41_bias_array;   /* Array #104 */
AI_STATIC ai_array conv2d_42_weights_array;   /* Array #105 */
AI_STATIC ai_array conv2d_42_bias_array;   /* Array #106 */
AI_STATIC ai_array conv2d_43_weights_array;   /* Array #107 */
AI_STATIC ai_array conv2d_43_bias_array;   /* Array #108 */
AI_STATIC ai_array conv2d_44_weights_array;   /* Array #109 */
AI_STATIC ai_array conv2d_44_bias_array;   /* Array #110 */
AI_STATIC ai_array conv2d_46_weights_array;   /* Array #111 */
AI_STATIC ai_array conv2d_46_bias_array;   /* Array #112 */
AI_STATIC ai_array conv2d_47_weights_array;   /* Array #113 */
AI_STATIC ai_array conv2d_47_bias_array;   /* Array #114 */
AI_STATIC ai_array conv2d_48_weights_array;   /* Array #115 */
AI_STATIC ai_array conv2d_48_bias_array;   /* Array #116 */
AI_STATIC ai_array conv2d_49_weights_array;   /* Array #117 */
AI_STATIC ai_array conv2d_49_bias_array;   /* Array #118 */
AI_STATIC ai_array conv2d_51_weights_array;   /* Array #119 */
AI_STATIC ai_array conv2d_51_bias_array;   /* Array #120 */
AI_STATIC ai_array conv2d_52_weights_array;   /* Array #121 */
AI_STATIC ai_array conv2d_52_bias_array;   /* Array #122 */
AI_STATIC ai_array conv2d_53_weights_array;   /* Array #123 */
AI_STATIC ai_array conv2d_53_bias_array;   /* Array #124 */
AI_STATIC ai_array conv2d_54_weights_array;   /* Array #125 */
AI_STATIC ai_array conv2d_54_bias_array;   /* Array #126 */
AI_STATIC ai_array dense_57_weights_array;   /* Array #127 */
AI_STATIC ai_array dense_57_bias_array;   /* Array #128 */
AI_STATIC ai_array conv2d_1_scratch0_array;   /* Array #129 */
AI_STATIC ai_array conv2d_3_scratch0_array;   /* Array #130 */
AI_STATIC ai_array conv2d_4_scratch0_array;   /* Array #131 */
AI_STATIC ai_array conv2d_6_scratch0_array;   /* Array #132 */
AI_STATIC ai_array conv2d_7_scratch0_array;   /* Array #133 */
AI_STATIC ai_array conv2d_9_scratch0_array;   /* Array #134 */
AI_STATIC ai_array conv2d_10_scratch0_array;   /* Array #135 */
AI_STATIC ai_array conv2d_12_scratch0_array;   /* Array #136 */
AI_STATIC ai_array conv2d_13_scratch0_array;   /* Array #137 */
AI_STATIC ai_array conv2d_15_scratch0_array;   /* Array #138 */
AI_STATIC ai_array conv2d_16_scratch0_array;   /* Array #139 */
AI_STATIC ai_array conv2d_18_scratch0_array;   /* Array #140 */
AI_STATIC ai_array conv2d_19_scratch0_array;   /* Array #141 */
AI_STATIC ai_array conv2d_21_scratch0_array;   /* Array #142 */
AI_STATIC ai_array conv2d_22_scratch0_array;   /* Array #143 */
AI_STATIC ai_array conv2d_23_scratch0_array;   /* Array #144 */
AI_STATIC ai_array conv2d_24_scratch0_array;   /* Array #145 */
AI_STATIC ai_array conv2d_26_scratch0_array;   /* Array #146 */
AI_STATIC ai_array conv2d_27_scratch0_array;   /* Array #147 */
AI_STATIC ai_array conv2d_28_scratch0_array;   /* Array #148 */
AI_STATIC ai_array conv2d_29_scratch0_array;   /* Array #149 */
AI_STATIC ai_array conv2d_31_scratch0_array;   /* Array #150 */
AI_STATIC ai_array conv2d_32_scratch0_array;   /* Array #151 */
AI_STATIC ai_array conv2d_33_scratch0_array;   /* Array #152 */
AI_STATIC ai_array conv2d_34_scratch0_array;   /* Array #153 */
AI_STATIC ai_array conv2d_36_scratch0_array;   /* Array #154 */
AI_STATIC ai_array conv2d_37_scratch0_array;   /* Array #155 */
AI_STATIC ai_array conv2d_38_scratch0_array;   /* Array #156 */
AI_STATIC ai_array conv2d_39_scratch0_array;   /* Array #157 */
AI_STATIC ai_array conv2d_41_scratch0_array;   /* Array #158 */
AI_STATIC ai_array conv2d_42_scratch0_array;   /* Array #159 */
AI_STATIC ai_array conv2d_43_scratch0_array;   /* Array #160 */
AI_STATIC ai_array conv2d_44_scratch0_array;   /* Array #161 */
AI_STATIC ai_array conv2d_46_scratch0_array;   /* Array #162 */
AI_STATIC ai_array conv2d_47_scratch0_array;   /* Array #163 */
AI_STATIC ai_array conv2d_48_scratch0_array;   /* Array #164 */
AI_STATIC ai_array conv2d_49_scratch0_array;   /* Array #165 */
AI_STATIC ai_array conv2d_51_scratch0_array;   /* Array #166 */
AI_STATIC ai_array conv2d_52_scratch0_array;   /* Array #167 */
AI_STATIC ai_array conv2d_53_scratch0_array;   /* Array #168 */
AI_STATIC ai_array conv2d_54_scratch0_array;   /* Array #169 */
AI_STATIC ai_array conv2d_54_scratch1_array;   /* Array #170 */


/**  Forward network tensor declarations  *************************************/
AI_STATIC ai_tensor input_1_output;   /* Tensor #0 */
AI_STATIC ai_tensor conv2d_1_output;   /* Tensor #1 */
AI_STATIC ai_tensor conv2d_3_output;   /* Tensor #2 */
AI_STATIC ai_tensor conv2d_4_output;   /* Tensor #3 */
AI_STATIC ai_tensor conv2d_6_output;   /* Tensor #4 */
AI_STATIC ai_tensor conv2d_7_output;   /* Tensor #5 */
AI_STATIC ai_tensor conv2d_9_output;   /* Tensor #6 */
AI_STATIC ai_tensor conv2d_10_output;   /* Tensor #7 */
AI_STATIC ai_tensor conv2d_12_output;   /* Tensor #8 */
AI_STATIC ai_tensor conv2d_13_output;   /* Tensor #9 */
AI_STATIC ai_tensor conv2d_15_output;   /* Tensor #10 */
AI_STATIC ai_tensor conv2d_16_output;   /* Tensor #11 */
AI_STATIC ai_tensor conv2d_18_output;   /* Tensor #12 */
AI_STATIC ai_tensor conv2d_19_output;   /* Tensor #13 */
AI_STATIC ai_tensor conv2d_21_output;   /* Tensor #14 */
AI_STATIC ai_tensor conv2d_22_output;   /* Tensor #15 */
AI_STATIC ai_tensor conv2d_23_output;   /* Tensor #16 */
AI_STATIC ai_tensor conv2d_24_output;   /* Tensor #17 */
AI_STATIC ai_tensor conv2d_26_output;   /* Tensor #18 */
AI_STATIC ai_tensor conv2d_27_output;   /* Tensor #19 */
AI_STATIC ai_tensor conv2d_28_output;   /* Tensor #20 */
AI_STATIC ai_tensor conv2d_29_output;   /* Tensor #21 */
AI_STATIC ai_tensor conv2d_31_output;   /* Tensor #22 */
AI_STATIC ai_tensor conv2d_32_output;   /* Tensor #23 */
AI_STATIC ai_tensor conv2d_33_output;   /* Tensor #24 */
AI_STATIC ai_tensor conv2d_34_output;   /* Tensor #25 */
AI_STATIC ai_tensor conv2d_36_output;   /* Tensor #26 */
AI_STATIC ai_tensor conv2d_37_output;   /* Tensor #27 */
AI_STATIC ai_tensor conv2d_38_output;   /* Tensor #28 */
AI_STATIC ai_tensor conv2d_39_output;   /* Tensor #29 */
AI_STATIC ai_tensor conv2d_41_output;   /* Tensor #30 */
AI_STATIC ai_tensor conv2d_42_output;   /* Tensor #31 */
AI_STATIC ai_tensor conv2d_43_output;   /* Tensor #32 */
AI_STATIC ai_tensor conv2d_44_output;   /* Tensor #33 */
AI_STATIC ai_tensor conv2d_46_output;   /* Tensor #34 */
AI_STATIC ai_tensor conv2d_47_output;   /* Tensor #35 */
AI_STATIC ai_tensor conv2d_48_output;   /* Tensor #36 */
AI_STATIC ai_tensor conv2d_49_output;   /* Tensor #37 */
AI_STATIC ai_tensor conv2d_51_output;   /* Tensor #38 */
AI_STATIC ai_tensor conv2d_52_output;   /* Tensor #39 */
AI_STATIC ai_tensor conv2d_53_output;   /* Tensor #40 */
AI_STATIC ai_tensor conv2d_54_output;   /* Tensor #41 */
AI_STATIC ai_tensor dense_57_output;   /* Tensor #42 */
AI_STATIC ai_tensor dense_57_fmt_output;   /* Tensor #43 */
AI_STATIC ai_tensor nl_58_output;   /* Tensor #44 */
AI_STATIC ai_tensor conv2d_1_weights;   /* Tensor #45 */
AI_STATIC ai_tensor conv2d_1_bias;   /* Tensor #46 */
AI_STATIC ai_tensor conv2d_3_weights;   /* Tensor #47 */
AI_STATIC ai_tensor conv2d_3_bias;   /* Tensor #48 */
AI_STATIC ai_tensor conv2d_4_weights;   /* Tensor #49 */
AI_STATIC ai_tensor conv2d_4_bias;   /* Tensor #50 */
AI_STATIC ai_tensor conv2d_6_weights;   /* Tensor #51 */
AI_STATIC ai_tensor conv2d_6_bias;   /* Tensor #52 */
AI_STATIC ai_tensor conv2d_7_weights;   /* Tensor #53 */
AI_STATIC ai_tensor conv2d_7_bias;   /* Tensor #54 */
AI_STATIC ai_tensor conv2d_9_weights;   /* Tensor #55 */
AI_STATIC ai_tensor conv2d_9_bias;   /* Tensor #56 */
AI_STATIC ai_tensor conv2d_10_weights;   /* Tensor #57 */
AI_STATIC ai_tensor conv2d_10_bias;   /* Tensor #58 */
AI_STATIC ai_tensor conv2d_12_weights;   /* Tensor #59 */
AI_STATIC ai_tensor conv2d_12_bias;   /* Tensor #60 */
AI_STATIC ai_tensor conv2d_13_weights;   /* Tensor #61 */
AI_STATIC ai_tensor conv2d_13_bias;   /* Tensor #62 */
AI_STATIC ai_tensor conv2d_15_weights;   /* Tensor #63 */
AI_STATIC ai_tensor conv2d_15_bias;   /* Tensor #64 */
AI_STATIC ai_tensor conv2d_16_weights;   /* Tensor #65 */
AI_STATIC ai_tensor conv2d_16_bias;   /* Tensor #66 */
AI_STATIC ai_tensor conv2d_18_weights;   /* Tensor #67 */
AI_STATIC ai_tensor conv2d_18_bias;   /* Tensor #68 */
AI_STATIC ai_tensor conv2d_19_weights;   /* Tensor #69 */
AI_STATIC ai_tensor conv2d_19_bias;   /* Tensor #70 */
AI_STATIC ai_tensor conv2d_21_weights;   /* Tensor #71 */
AI_STATIC ai_tensor conv2d_21_bias;   /* Tensor #72 */
AI_STATIC ai_tensor conv2d_22_weights;   /* Tensor #73 */
AI_STATIC ai_tensor conv2d_22_bias;   /* Tensor #74 */
AI_STATIC ai_tensor conv2d_23_weights;   /* Tensor #75 */
AI_STATIC ai_tensor conv2d_23_bias;   /* Tensor #76 */
AI_STATIC ai_tensor conv2d_24_weights;   /* Tensor #77 */
AI_STATIC ai_tensor conv2d_24_bias;   /* Tensor #78 */
AI_STATIC ai_tensor conv2d_26_weights;   /* Tensor #79 */
AI_STATIC ai_tensor conv2d_26_bias;   /* Tensor #80 */
AI_STATIC ai_tensor conv2d_27_weights;   /* Tensor #81 */
AI_STATIC ai_tensor conv2d_27_bias;   /* Tensor #82 */
AI_STATIC ai_tensor conv2d_28_weights;   /* Tensor #83 */
AI_STATIC ai_tensor conv2d_28_bias;   /* Tensor #84 */
AI_STATIC ai_tensor conv2d_29_weights;   /* Tensor #85 */
AI_STATIC ai_tensor conv2d_29_bias;   /* Tensor #86 */
AI_STATIC ai_tensor conv2d_31_weights;   /* Tensor #87 */
AI_STATIC ai_tensor conv2d_31_bias;   /* Tensor #88 */
AI_STATIC ai_tensor conv2d_32_weights;   /* Tensor #89 */
AI_STATIC ai_tensor conv2d_32_bias;   /* Tensor #90 */
AI_STATIC ai_tensor conv2d_33_weights;   /* Tensor #91 */
AI_STATIC ai_tensor conv2d_33_bias;   /* Tensor #92 */
AI_STATIC ai_tensor conv2d_34_weights;   /* Tensor #93 */
AI_STATIC ai_tensor conv2d_34_bias;   /* Tensor #94 */
AI_STATIC ai_tensor conv2d_36_weights;   /* Tensor #95 */
AI_STATIC ai_tensor conv2d_36_bias;   /* Tensor #96 */
AI_STATIC ai_tensor conv2d_37_weights;   /* Tensor #97 */
AI_STATIC ai_tensor conv2d_37_bias;   /* Tensor #98 */
AI_STATIC ai_tensor conv2d_38_weights;   /* Tensor #99 */
AI_STATIC ai_tensor conv2d_38_bias;   /* Tensor #100 */
AI_STATIC ai_tensor conv2d_39_weights;   /* Tensor #101 */
AI_STATIC ai_tensor conv2d_39_bias;   /* Tensor #102 */
AI_STATIC ai_tensor conv2d_41_weights;   /* Tensor #103 */
AI_STATIC ai_tensor conv2d_41_bias;   /* Tensor #104 */
AI_STATIC ai_tensor conv2d_42_weights;   /* Tensor #105 */
AI_STATIC ai_tensor conv2d_42_bias;   /* Tensor #106 */
AI_STATIC ai_tensor conv2d_43_weights;   /* Tensor #107 */
AI_STATIC ai_tensor conv2d_43_bias;   /* Tensor #108 */
AI_STATIC ai_tensor conv2d_44_weights;   /* Tensor #109 */
AI_STATIC ai_tensor conv2d_44_bias;   /* Tensor #110 */
AI_STATIC ai_tensor conv2d_46_weights;   /* Tensor #111 */
AI_STATIC ai_tensor conv2d_46_bias;   /* Tensor #112 */
AI_STATIC ai_tensor conv2d_47_weights;   /* Tensor #113 */
AI_STATIC ai_tensor conv2d_47_bias;   /* Tensor #114 */
AI_STATIC ai_tensor conv2d_48_weights;   /* Tensor #115 */
AI_STATIC ai_tensor conv2d_48_bias;   /* Tensor #116 */
AI_STATIC ai_tensor conv2d_49_weights;   /* Tensor #117 */
AI_STATIC ai_tensor conv2d_49_bias;   /* Tensor #118 */
AI_STATIC ai_tensor conv2d_51_weights;   /* Tensor #119 */
AI_STATIC ai_tensor conv2d_51_bias;   /* Tensor #120 */
AI_STATIC ai_tensor conv2d_52_weights;   /* Tensor #121 */
AI_STATIC ai_tensor conv2d_52_bias;   /* Tensor #122 */
AI_STATIC ai_tensor conv2d_53_weights;   /* Tensor #123 */
AI_STATIC ai_tensor conv2d_53_bias;   /* Tensor #124 */
AI_STATIC ai_tensor conv2d_54_weights;   /* Tensor #125 */
AI_STATIC ai_tensor conv2d_54_bias;   /* Tensor #126 */
AI_STATIC ai_tensor dense_57_weights;   /* Tensor #127 */
AI_STATIC ai_tensor dense_57_bias;   /* Tensor #128 */
AI_STATIC ai_tensor conv2d_1_scratch0;   /* Tensor #129 */
AI_STATIC ai_tensor conv2d_3_scratch0;   /* Tensor #130 */
AI_STATIC ai_tensor conv2d_4_scratch0;   /* Tensor #131 */
AI_STATIC ai_tensor conv2d_6_scratch0;   /* Tensor #132 */
AI_STATIC ai_tensor conv2d_7_scratch0;   /* Tensor #133 */
AI_STATIC ai_tensor conv2d_9_scratch0;   /* Tensor #134 */
AI_STATIC ai_tensor conv2d_10_scratch0;   /* Tensor #135 */
AI_STATIC ai_tensor conv2d_12_scratch0;   /* Tensor #136 */
AI_STATIC ai_tensor conv2d_13_scratch0;   /* Tensor #137 */
AI_STATIC ai_tensor conv2d_15_scratch0;   /* Tensor #138 */
AI_STATIC ai_tensor conv2d_16_scratch0;   /* Tensor #139 */
AI_STATIC ai_tensor conv2d_18_scratch0;   /* Tensor #140 */
AI_STATIC ai_tensor conv2d_19_scratch0;   /* Tensor #141 */
AI_STATIC ai_tensor conv2d_21_scratch0;   /* Tensor #142 */
AI_STATIC ai_tensor conv2d_22_scratch0;   /* Tensor #143 */
AI_STATIC ai_tensor conv2d_23_scratch0;   /* Tensor #144 */
AI_STATIC ai_tensor conv2d_24_scratch0;   /* Tensor #145 */
AI_STATIC ai_tensor conv2d_26_scratch0;   /* Tensor #146 */
AI_STATIC ai_tensor conv2d_27_scratch0;   /* Tensor #147 */
AI_STATIC ai_tensor conv2d_28_scratch0;   /* Tensor #148 */
AI_STATIC ai_tensor conv2d_29_scratch0;   /* Tensor #149 */
AI_STATIC ai_tensor conv2d_31_scratch0;   /* Tensor #150 */
AI_STATIC ai_tensor conv2d_32_scratch0;   /* Tensor #151 */
AI_STATIC ai_tensor conv2d_33_scratch0;   /* Tensor #152 */
AI_STATIC ai_tensor conv2d_34_scratch0;   /* Tensor #153 */
AI_STATIC ai_tensor conv2d_36_scratch0;   /* Tensor #154 */
AI_STATIC ai_tensor conv2d_37_scratch0;   /* Tensor #155 */
AI_STATIC ai_tensor conv2d_38_scratch0;   /* Tensor #156 */
AI_STATIC ai_tensor conv2d_39_scratch0;   /* Tensor #157 */
AI_STATIC ai_tensor conv2d_41_scratch0;   /* Tensor #158 */
AI_STATIC ai_tensor conv2d_42_scratch0;   /* Tensor #159 */
AI_STATIC ai_tensor conv2d_43_scratch0;   /* Tensor #160 */
AI_STATIC ai_tensor conv2d_44_scratch0;   /* Tensor #161 */
AI_STATIC ai_tensor conv2d_46_scratch0;   /* Tensor #162 */
AI_STATIC ai_tensor conv2d_47_scratch0;   /* Tensor #163 */
AI_STATIC ai_tensor conv2d_48_scratch0;   /* Tensor #164 */
AI_STATIC ai_tensor conv2d_49_scratch0;   /* Tensor #165 */
AI_STATIC ai_tensor conv2d_51_scratch0;   /* Tensor #166 */
AI_STATIC ai_tensor conv2d_52_scratch0;   /* Tensor #167 */
AI_STATIC ai_tensor conv2d_53_scratch0;   /* Tensor #168 */
AI_STATIC ai_tensor conv2d_54_scratch0;   /* Tensor #169 */
AI_STATIC ai_tensor conv2d_54_scratch1;   /* Tensor #170 */


/**  Forward network tensor chain declarations  *******************************/
AI_STATIC_CONST ai_tensor_chain conv2d_1_chain;   /* Chain #0 */
AI_STATIC_CONST ai_tensor_chain conv2d_3_chain;   /* Chain #1 */
AI_STATIC_CONST ai_tensor_chain conv2d_4_chain;   /* Chain #2 */
AI_STATIC_CONST ai_tensor_chain conv2d_6_chain;   /* Chain #3 */
AI_STATIC_CONST ai_tensor_chain conv2d_7_chain;   /* Chain #4 */
AI_STATIC_CONST ai_tensor_chain conv2d_9_chain;   /* Chain #5 */
AI_STATIC_CONST ai_tensor_chain conv2d_10_chain;   /* Chain #6 */
AI_STATIC_CONST ai_tensor_chain conv2d_12_chain;   /* Chain #7 */
AI_STATIC_CONST ai_tensor_chain conv2d_13_chain;   /* Chain #8 */
AI_STATIC_CONST ai_tensor_chain conv2d_15_chain;   /* Chain #9 */
AI_STATIC_CONST ai_tensor_chain conv2d_16_chain;   /* Chain #10 */
AI_STATIC_CONST ai_tensor_chain conv2d_18_chain;   /* Chain #11 */
AI_STATIC_CONST ai_tensor_chain conv2d_19_chain;   /* Chain #12 */
AI_STATIC_CONST ai_tensor_chain conv2d_21_chain;   /* Chain #13 */
AI_STATIC_CONST ai_tensor_chain conv2d_22_chain;   /* Chain #14 */
AI_STATIC_CONST ai_tensor_chain conv2d_23_chain;   /* Chain #15 */
AI_STATIC_CONST ai_tensor_chain conv2d_24_chain;   /* Chain #16 */
AI_STATIC_CONST ai_tensor_chain conv2d_26_chain;   /* Chain #17 */
AI_STATIC_CONST ai_tensor_chain conv2d_27_chain;   /* Chain #18 */
AI_STATIC_CONST ai_tensor_chain conv2d_28_chain;   /* Chain #19 */
AI_STATIC_CONST ai_tensor_chain conv2d_29_chain;   /* Chain #20 */
AI_STATIC_CONST ai_tensor_chain conv2d_31_chain;   /* Chain #21 */
AI_STATIC_CONST ai_tensor_chain conv2d_32_chain;   /* Chain #22 */
AI_STATIC_CONST ai_tensor_chain conv2d_33_chain;   /* Chain #23 */
AI_STATIC_CONST ai_tensor_chain conv2d_34_chain;   /* Chain #24 */
AI_STATIC_CONST ai_tensor_chain conv2d_36_chain;   /* Chain #25 */
AI_STATIC_CONST ai_tensor_chain conv2d_37_chain;   /* Chain #26 */
AI_STATIC_CONST ai_tensor_chain conv2d_38_chain;   /* Chain #27 */
AI_STATIC_CONST ai_tensor_chain conv2d_39_chain;   /* Chain #28 */
AI_STATIC_CONST ai_tensor_chain conv2d_41_chain;   /* Chain #29 */
AI_STATIC_CONST ai_tensor_chain conv2d_42_chain;   /* Chain #30 */
AI_STATIC_CONST ai_tensor_chain conv2d_43_chain;   /* Chain #31 */
AI_STATIC_CONST ai_tensor_chain conv2d_44_chain;   /* Chain #32 */
AI_STATIC_CONST ai_tensor_chain conv2d_46_chain;   /* Chain #33 */
AI_STATIC_CONST ai_tensor_chain conv2d_47_chain;   /* Chain #34 */
AI_STATIC_CONST ai_tensor_chain conv2d_48_chain;   /* Chain #35 */
AI_STATIC_CONST ai_tensor_chain conv2d_49_chain;   /* Chain #36 */
AI_STATIC_CONST ai_tensor_chain conv2d_51_chain;   /* Chain #37 */
AI_STATIC_CONST ai_tensor_chain conv2d_52_chain;   /* Chain #38 */
AI_STATIC_CONST ai_tensor_chain conv2d_53_chain;   /* Chain #39 */
AI_STATIC_CONST ai_tensor_chain conv2d_54_chain;   /* Chain #40 */
AI_STATIC_CONST ai_tensor_chain dense_57_chain;   /* Chain #41 */
AI_STATIC_CONST ai_tensor_chain dense_57_fmt_chain;   /* Chain #42 */
AI_STATIC_CONST ai_tensor_chain nl_58_chain;   /* Chain #43 */


/**  Forward network layer declarations  **************************************/
AI_STATIC ai_layer_conv2d conv2d_1_layer; /* Layer #0 */
AI_STATIC ai_layer_conv2d conv2d_3_layer; /* Layer #1 */
AI_STATIC ai_layer_conv2d conv2d_4_layer; /* Layer #2 */
AI_STATIC ai_layer_conv2d conv2d_6_layer; /* Layer #3 */
AI_STATIC ai_layer_conv2d conv2d_7_layer; /* Layer #4 */
AI_STATIC ai_layer_conv2d conv2d_9_layer; /* Layer #5 */
AI_STATIC ai_layer_conv2d conv2d_10_layer; /* Layer #6 */
AI_STATIC ai_layer_conv2d conv2d_12_layer; /* Layer #7 */
AI_STATIC ai_layer_conv2d conv2d_13_layer; /* Layer #8 */
AI_STATIC ai_layer_conv2d conv2d_15_layer; /* Layer #9 */
AI_STATIC ai_layer_conv2d conv2d_16_layer; /* Layer #10 */
AI_STATIC ai_layer_conv2d conv2d_18_layer; /* Layer #11 */
AI_STATIC ai_layer_conv2d conv2d_19_layer; /* Layer #12 */
AI_STATIC ai_layer_conv2d conv2d_21_layer; /* Layer #13 */
AI_STATIC ai_layer_conv2d conv2d_22_layer; /* Layer #14 */
AI_STATIC ai_layer_conv2d conv2d_23_layer; /* Layer #15 */
AI_STATIC ai_layer_conv2d conv2d_24_layer; /* Layer #16 */
AI_STATIC ai_layer_conv2d conv2d_26_layer; /* Layer #17 */
AI_STATIC ai_layer_conv2d conv2d_27_layer; /* Layer #18 */
AI_STATIC ai_layer_conv2d conv2d_28_layer; /* Layer #19 */
AI_STATIC ai_layer_conv2d conv2d_29_layer; /* Layer #20 */
AI_STATIC ai_layer_conv2d conv2d_31_layer; /* Layer #21 */
AI_STATIC ai_layer_conv2d conv2d_32_layer; /* Layer #22 */
AI_STATIC ai_layer_conv2d conv2d_33_layer; /* Layer #23 */
AI_STATIC ai_layer_conv2d conv2d_34_layer; /* Layer #24 */
AI_STATIC ai_layer_conv2d conv2d_36_layer; /* Layer #25 */
AI_STATIC ai_layer_conv2d conv2d_37_layer; /* Layer #26 */
AI_STATIC ai_layer_conv2d conv2d_38_layer; /* Layer #27 */
AI_STATIC ai_layer_conv2d conv2d_39_layer; /* Layer #28 */
AI_STATIC ai_layer_conv2d conv2d_41_layer; /* Layer #29 */
AI_STATIC ai_layer_conv2d conv2d_42_layer; /* Layer #30 */
AI_STATIC ai_layer_conv2d conv2d_43_layer; /* Layer #31 */
AI_STATIC ai_layer_conv2d conv2d_44_layer; /* Layer #32 */
AI_STATIC ai_layer_conv2d conv2d_46_layer; /* Layer #33 */
AI_STATIC ai_layer_conv2d conv2d_47_layer; /* Layer #34 */
AI_STATIC ai_layer_conv2d conv2d_48_layer; /* Layer #35 */
AI_STATIC ai_layer_conv2d conv2d_49_layer; /* Layer #36 */
AI_STATIC ai_layer_conv2d conv2d_51_layer; /* Layer #37 */
AI_STATIC ai_layer_conv2d conv2d_52_layer; /* Layer #38 */
AI_STATIC ai_layer_conv2d conv2d_53_layer; /* Layer #39 */
AI_STATIC ai_layer_conv2d_nl_pool conv2d_54_layer; /* Layer #40 */
AI_STATIC ai_layer_dense dense_57_layer; /* Layer #41 */
AI_STATIC ai_layer_nl dense_57_fmt_layer; /* Layer #42 */
AI_STATIC ai_layer_nl nl_58_layer; /* Layer #43 */




/**  Array declarations section  **********************************************/
/* Array#0 */
AI_ARRAY_OBJ_DECLARE(
  input_1_output_array, AI_ARRAY_FORMAT_S8|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 3072, AI_STATIC)

/* Array#1 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_1_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#2 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#3 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 57344, AI_STATIC)

/* Array#4 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_6_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 14336, AI_STATIC)

/* Array#5 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_7_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 26624, AI_STATIC)

/* Array#6 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 26624, AI_STATIC)

/* Array#7 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_10_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 20480, AI_STATIC)

/* Array#8 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_12_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5120, AI_STATIC)

/* Array#9 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_13_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 10240, AI_STATIC)

/* Array#10 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_15_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 10240, AI_STATIC)

/* Array#11 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_16_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6656, AI_STATIC)

/* Array#12 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_18_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1664, AI_STATIC)

/* Array#13 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_19_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3328, AI_STATIC)

/* Array#14 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_21_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3328, AI_STATIC)

/* Array#15 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_22_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 512, AI_STATIC)

/* Array#16 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_23_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 512, AI_STATIC)

/* Array#17 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_24_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2560, AI_STATIC)

/* Array#18 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_26_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2560, AI_STATIC)

/* Array#19 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_27_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 512, AI_STATIC)

/* Array#20 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_28_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 512, AI_STATIC)

/* Array#21 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_29_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2560, AI_STATIC)

/* Array#22 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_31_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2560, AI_STATIC)

/* Array#23 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_32_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 512, AI_STATIC)

/* Array#24 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_33_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 512, AI_STATIC)

/* Array#25 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_34_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2560, AI_STATIC)

/* Array#26 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_36_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2560, AI_STATIC)

/* Array#27 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_37_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 640, AI_STATIC)

/* Array#28 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_38_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 512, AI_STATIC)

/* Array#29 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_39_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3328, AI_STATIC)

/* Array#30 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_41_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3328, AI_STATIC)

/* Array#31 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_42_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 640, AI_STATIC)

/* Array#32 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_43_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 640, AI_STATIC)

/* Array#33 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_44_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3328, AI_STATIC)

/* Array#34 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_46_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 832, AI_STATIC)

/* Array#35 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_47_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 192, AI_STATIC)

/* Array#36 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_48_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 192, AI_STATIC)

/* Array#37 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_49_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 832, AI_STATIC)

/* Array#38 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_51_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 832, AI_STATIC)

/* Array#39 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_52_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 480, AI_STATIC)

/* Array#40 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_53_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 384, AI_STATIC)

/* Array#41 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_54_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 720, AI_STATIC)

/* Array#42 */
AI_ARRAY_OBJ_DECLARE(
  dense_57_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 100, AI_STATIC)

/* Array#43 */
AI_ARRAY_OBJ_DECLARE(
  dense_57_fmt_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 100, AI_STATIC)

/* Array#44 */
AI_ARRAY_OBJ_DECLARE(
  nl_58_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 100, AI_STATIC)

/* Array#45 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_1_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 432, AI_STATIC)

/* Array#46 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_1_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 16, AI_STATIC)

/* Array#47 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 144, AI_STATIC)

/* Array#48 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 16, AI_STATIC)

/* Array#49 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 896, AI_STATIC)

/* Array#50 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 56, AI_STATIC)

/* Array#51 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_6_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 504, AI_STATIC)

/* Array#52 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_6_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 56, AI_STATIC)

/* Array#53 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_7_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5824, AI_STATIC)

/* Array#54 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_7_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 104, AI_STATIC)

/* Array#55 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 936, AI_STATIC)

/* Array#56 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 104, AI_STATIC)

/* Array#57 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_10_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 8320, AI_STATIC)

/* Array#58 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_10_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 80, AI_STATIC)

/* Array#59 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_12_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 720, AI_STATIC)

/* Array#60 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_12_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 80, AI_STATIC)

/* Array#61 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_13_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12800, AI_STATIC)

/* Array#62 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_13_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 160, AI_STATIC)

/* Array#63 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_15_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1440, AI_STATIC)

/* Array#64 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_15_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 160, AI_STATIC)

/* Array#65 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_16_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16640, AI_STATIC)

/* Array#66 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_16_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 104, AI_STATIC)

/* Array#67 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_18_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 936, AI_STATIC)

/* Array#68 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_18_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 104, AI_STATIC)

/* Array#69 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_19_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 21632, AI_STATIC)

/* Array#70 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_19_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 208, AI_STATIC)

/* Array#71 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_21_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1872, AI_STATIC)

/* Array#72 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_21_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 208, AI_STATIC)

/* Array#73 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_22_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6656, AI_STATIC)

/* Array#74 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_22_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 32, AI_STATIC)

/* Array#75 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_23_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1024, AI_STATIC)

/* Array#76 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_23_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 32, AI_STATIC)

/* Array#77 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_24_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5120, AI_STATIC)

/* Array#78 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_24_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 160, AI_STATIC)

/* Array#79 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_26_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1440, AI_STATIC)

/* Array#80 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_26_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 160, AI_STATIC)

/* Array#81 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_27_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5120, AI_STATIC)

/* Array#82 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_27_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 32, AI_STATIC)

/* Array#83 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_28_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1024, AI_STATIC)

/* Array#84 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_28_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 32, AI_STATIC)

/* Array#85 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_29_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5120, AI_STATIC)

/* Array#86 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_29_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 160, AI_STATIC)

/* Array#87 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_31_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1440, AI_STATIC)

/* Array#88 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_31_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 160, AI_STATIC)

/* Array#89 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_32_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5120, AI_STATIC)

/* Array#90 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_32_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 32, AI_STATIC)

/* Array#91 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_33_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1024, AI_STATIC)

/* Array#92 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_33_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 32, AI_STATIC)

/* Array#93 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_34_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5120, AI_STATIC)

/* Array#94 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_34_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 160, AI_STATIC)

/* Array#95 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_36_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1440, AI_STATIC)

/* Array#96 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_36_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 160, AI_STATIC)

/* Array#97 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_37_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6400, AI_STATIC)

/* Array#98 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_37_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 40, AI_STATIC)

/* Array#99 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_38_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1280, AI_STATIC)

/* Array#100 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_38_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 32, AI_STATIC)

/* Array#101 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_39_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6656, AI_STATIC)

/* Array#102 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_39_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 208, AI_STATIC)

/* Array#103 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_41_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1872, AI_STATIC)

/* Array#104 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_41_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 208, AI_STATIC)

/* Array#105 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_42_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 8320, AI_STATIC)

/* Array#106 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_42_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 40, AI_STATIC)

/* Array#107 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_43_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1600, AI_STATIC)

/* Array#108 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_43_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 40, AI_STATIC)

/* Array#109 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_44_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 8320, AI_STATIC)

/* Array#110 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_44_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 208, AI_STATIC)

/* Array#111 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_46_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1872, AI_STATIC)

/* Array#112 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_46_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 208, AI_STATIC)

/* Array#113 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_47_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9984, AI_STATIC)

/* Array#114 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_47_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 48, AI_STATIC)

/* Array#115 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_48_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2304, AI_STATIC)

/* Array#116 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_48_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 48, AI_STATIC)

/* Array#117 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_49_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9984, AI_STATIC)

/* Array#118 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_49_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 208, AI_STATIC)

/* Array#119 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_51_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1872, AI_STATIC)

/* Array#120 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_51_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 208, AI_STATIC)

/* Array#121 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_52_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 24960, AI_STATIC)

/* Array#122 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_52_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 120, AI_STATIC)

/* Array#123 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_53_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 11520, AI_STATIC)

/* Array#124 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_53_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 96, AI_STATIC)

/* Array#125 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_54_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 69120, AI_STATIC)

/* Array#126 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_54_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 720, AI_STATIC)

/* Array#127 */
AI_ARRAY_OBJ_DECLARE(
  dense_57_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 72000, AI_STATIC)

/* Array#128 */
AI_ARRAY_OBJ_DECLARE(
  dense_57_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 100, AI_STATIC)

/* Array#129 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_1_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1196, AI_STATIC)

/* Array#130 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 593, AI_STATIC)

/* Array#131 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 624, AI_STATIC)

/* Array#132 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_6_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2073, AI_STATIC)

/* Array#133 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_7_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1264, AI_STATIC)

/* Array#134 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3849, AI_STATIC)

/* Array#135 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_10_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1216, AI_STATIC)

/* Array#136 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_12_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2961, AI_STATIC)

/* Array#137 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_13_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1920, AI_STATIC)

/* Array#138 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_15_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5921, AI_STATIC)

/* Array#139 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_16_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1680, AI_STATIC)

/* Array#140 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_18_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3849, AI_STATIC)

/* Array#141 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_19_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2496, AI_STATIC)

/* Array#142 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_21_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 7697, AI_STATIC)

/* Array#143 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_22_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#144 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_23_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 448, AI_STATIC)

/* Array#145 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_24_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1728, AI_STATIC)

/* Array#146 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_26_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5921, AI_STATIC)

/* Array#147 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_27_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 960, AI_STATIC)

/* Array#148 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_28_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 448, AI_STATIC)

/* Array#149 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_29_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1728, AI_STATIC)

/* Array#150 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_31_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5921, AI_STATIC)

/* Array#151 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_32_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 960, AI_STATIC)

/* Array#152 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_33_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 448, AI_STATIC)

/* Array#153 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_34_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1728, AI_STATIC)

/* Array#154 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_36_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5921, AI_STATIC)

/* Array#155 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_37_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1040, AI_STATIC)

/* Array#156 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_38_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 480, AI_STATIC)

/* Array#157 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_39_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2208, AI_STATIC)

/* Array#158 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_41_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 7697, AI_STATIC)

/* Array#159 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_42_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1232, AI_STATIC)

/* Array#160 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_43_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 560, AI_STATIC)

/* Array#161 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_44_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2240, AI_STATIC)

/* Array#162 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_46_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 7697, AI_STATIC)

/* Array#163 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_47_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1312, AI_STATIC)

/* Array#164 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_48_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 672, AI_STATIC)

/* Array#165 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_49_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2272, AI_STATIC)

/* Array#166 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_51_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 7697, AI_STATIC)

/* Array#167 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_52_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2032, AI_STATIC)

/* Array#168 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_53_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1440, AI_STATIC)

/* Array#169 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_54_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 7584, AI_STATIC)

/* Array#170 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_54_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2880, AI_STATIC)

/**  Array metadata declarations section  *************************************/
/* Int quant #0 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(input_1_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.9960784316062927f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #1 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_1_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.99909907579422f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #2 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_3_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(1.1676899194717407f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #3 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_4_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(1.0864888429641724f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #4 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_6_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(1.6433099508285522f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #5 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_7_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(1.333738088607788f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #6 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_9_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.7306711077690125f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #7 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_10_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.5024625658988953f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #8 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_12_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.593917965888977f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #9 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_13_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.36309757828712463f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #10 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_15_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.30726149678230286f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #11 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_16_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.14691750705242157f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #12 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_18_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.2556875944137573f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #13 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_19_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.07359917461872101f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #14 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_21_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.17124532163143158f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #15 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_22_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.17114388942718506f),
    AI_PACK_INTQ_ZP(23)))

/* Int quant #16 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_23_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.2927060127258301f),
    AI_PACK_INTQ_ZP(-11)))

/* Int quant #17 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_24_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.08722033351659775f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #18 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_26_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.14912854135036469f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #19 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_27_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.10723646730184555f),
    AI_PACK_INTQ_ZP(5)))

/* Int quant #20 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_28_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.1632021963596344f),
    AI_PACK_INTQ_ZP(2)))

/* Int quant #21 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_29_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.048582229763269424f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #22 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_31_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.09763998538255692f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #23 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_32_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.08083923906087875f),
    AI_PACK_INTQ_ZP(7)))

/* Int quant #24 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_33_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.10940076410770416f),
    AI_PACK_INTQ_ZP(-10)))

/* Int quant #25 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_34_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.03812381997704506f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #26 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_36_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0605301558971405f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #27 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_37_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.052350398153066635f),
    AI_PACK_INTQ_ZP(-6)))

/* Int quant #28 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_38_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.07178016752004623f),
    AI_PACK_INTQ_ZP(16)))

/* Int quant #29 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_39_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.033161841332912445f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #30 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_41_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.047502413392066956f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #31 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_42_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.05371754616498947f),
    AI_PACK_INTQ_ZP(-10)))

/* Int quant #32 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_43_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.062031444162130356f),
    AI_PACK_INTQ_ZP(23)))

/* Int quant #33 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_44_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.017114590853452682f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #34 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_46_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0539691336452961f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #35 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_47_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.04078643023967743f),
    AI_PACK_INTQ_ZP(-2)))

/* Int quant #36 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_48_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.054582178592681885f),
    AI_PACK_INTQ_ZP(15)))

/* Int quant #37 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_49_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.015552074648439884f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #38 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_51_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.028823519125580788f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #39 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_52_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.027252497151494026f),
    AI_PACK_INTQ_ZP(1)))

/* Int quant #40 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_53_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.042736683040857315f),
    AI_PACK_INTQ_ZP(-20)))

/* Int quant #41 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_54_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.04687463492155075f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #42 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(dense_57_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.1559937745332718f),
    AI_PACK_INTQ_ZP(-37)))

/* Int quant #43 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_1_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003810351947322488f, 0.0014150534989312291f, 0.000290560070425272f, 0.0013934113085269928f, 0.001321277697570622f, 0.0012738220393657684f, 0.0013785253977403045f, 0.0007443500799126923f, 0.000714180467184633f, 0.0003341487026773393f, 0.0013302465667948127f, 0.002126686042174697f, 0.001690393197350204f, 6.610010675253419e-22f, 2.1571273973346284e-22f, 2.989532667217371e-22f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #44 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_1_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00379540934227407f, 0.0014095042133703828f, 0.0002894206263590604f, 0.0013879470061510801f, 0.001316096168011427f, 0.0012688266579061747f, 0.001373119419440627f, 0.0007414310821332037f, 0.0007113797473721206f, 0.0003328383027110249f, 0.001325029879808426f, 0.0021183460485190153f, 0.0016837641596794128f, 6.584089084561091e-22f, 2.148668031640273e-22f, 2.9778090582060833e-22f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #45 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_3_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.008521826937794685f, 0.008109032176434994f, 0.011772953905165195f, 0.02021889202296734f, 0.003939968999475241f, 0.00906750001013279f, 0.006747405510395765f, 0.009649762883782387f, 0.020053265616297722f, 0.015293224714696407f, 0.006434336304664612f, 0.005534604657441378f, 0.00941152311861515f, 7.493065863961144e-22f, 1.0316880943096926e-21f, 1.7482795461154605e-21f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #46 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_3_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.008514149114489555f, 0.00810172688215971f, 0.0117623470723629f, 0.02020067721605301f, 0.003936419263482094f, 0.009059330448508263f, 0.00674132676795125f, 0.009641068987548351f, 0.02003519982099533f, 0.015279446728527546f, 0.006428539287298918f, 0.005529618356376886f, 0.009403044357895851f, 7.486315234096369e-22f, 1.030758626836725e-21f, 1.746704550608307e-21f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #47 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_4_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 56,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.004745293874293566f, 0.0017124811420217156f, 0.00396176939830184f, 0.004144989885389805f, 0.005318771116435528f, 0.0008303287322632968f, 0.006967958528548479f, 0.006136830430477858f, 0.005909369792789221f, 0.003253680421039462f, 0.0039137848652899265f, 0.003032451728358865f, 0.006654264871031046f, 0.0001241078571183607f, 0.007261909078806639f, 0.0045241969637572765f, 0.00474688271060586f, 0.004208806902170181f, 0.0035810668487101793f, 0.0025860934983938932f, 0.0026039686053991318f, 0.0018100488232448697f, 0.0020695924758911133f, 0.0025897722225636244f, 0.006242859642952681f, 5.953519998839768e-23f, 0.006321771070361137f, 0.0038009367417544127f, 0.004996458068490028f, 0.0017972560599446297f, 0.0032187842298299074f, 0.006608332507312298f, 0.0038191264029592276f, 0.004665603395551443f, 0.004653265234082937f, 0.003955748397856951f, 0.00309511530213058f, 0.0049947043880820274f, 1.0629143643819612e-21f, 1.3177926217991306e-21f, 0.006340413354337215f, 0.0023351176641881466f, 0.003116287523880601f, 1.949114053632093e-23f, 1.008849125910366e-23f, 0.0035272901877760887f, 0.0019923606887459755f, 0.0035304566845297813f, 1.771922641456246e-23f, 0.005578776355832815f, 9.7942839436708e-22f, 1.3430713476516886e-23f, 0.00446882750838995f, 0.0030145111959427595f, 0.0026561066042631865f, 0.0019297745311632752f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #48 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_4_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 56,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.005541031714528799f, 0.0019996468909084797f, 0.004626118112355471f, 0.00484006293118f, 0.006210675463080406f, 0.0009695664630271494f, 0.008136414922773838f, 0.0071659148670732975f, 0.0069003114476799965f, 0.003799289930611849f, 0.00457008695229888f, 0.003540963400155306f, 0.007770117837935686f, 0.00014491949696093798f, 0.008479657582938671f, 0.005282859317958355f, 0.005542886909097433f, 0.004914581310003996f, 0.004181575495749712f, 0.0030197552405297756f, 0.003040627809241414f, 0.002113575814291835f, 0.0024166423827409744f, 0.0030240509659051895f, 0.007289724424481392f, 6.951865126252754e-23f, 0.007381868548691273f, 0.0044383155182003975f, 0.005834313575178385f, 0.00209863786585629f, 0.0037585420068353415f, 0.007716483436524868f, 0.004459555260837078f, 0.005447978153824806f, 0.005433571059256792f, 0.004619087558239698f, 0.003614134853705764f, 0.005832266062498093f, 1.2411544188254493e-21f, 1.5387731348439442e-21f, 0.007403636816889048f, 0.002726693404838443f, 0.0036388575099408627f, 2.2759608992261423e-23f, 1.1780229502759992e-23f, 0.004118781071156263f, 0.00232645939104259f, 0.004122478887438774f, 2.0690562521942407e-23f, 0.0065142810344696045f, 1.1436686794760174e-21f, 1.5682908205479254e-23f, 0.005218205042183399f, 0.0035200142301619053f, 0.003101508831605315f, 0.00225337827578187f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #49 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_6_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 56,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007241965737193823f, 0.010050531476736069f, 0.011177252978086472f, 0.008811140432953835f, 0.003807940287515521f, 0.018965154886245728f, 0.010613066144287586f, 0.007574991323053837f, 0.012102131731808186f, 0.008793255314230919f, 0.010147194378077984f, 0.013012760318815708f, 0.0080474354326725f, 0.0018295879708603024f, 0.004691195674240589f, 0.007818837650120258f, 0.007522201631218195f, 0.006881824694573879f, 0.008116871118545532f, 0.012515570968389511f, 0.01037075836211443f, 0.010307269170880318f, 0.011856880970299244f, 0.01706216298043728f, 0.009163976646959782f, 2.4410521948578576e-22f, 0.006389131303876638f, 0.009858278557658195f, 0.004825405310839415f, 0.012704755179584026f, 0.009547144174575806f, 0.005373641382902861f, 0.006321672350168228f, 0.008878235705196857f, 0.008090096525847912f, 0.007379009388387203f, 0.0075524006970226765f, 0.0057222587056458f, 3.760643113442861e-24f, 3.400957644972362e-24f, 0.005003525875508785f, 0.005750974640250206f, 0.007537813391536474f, 1.9231199508453571e-22f, 6.314510953222318e-23f, 0.006850379519164562f, 0.01204738300293684f, 0.010657094419002533f, 3.4775444899456697e-22f, 0.008485410362482071f, 9.541042301263813e-24f, 2.3301557696325706e-22f, 0.00560746481642127f, 0.010666889138519764f, 0.008817816153168678f, 0.01316190604120493f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #50 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_6_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 56,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00786831509321928f, 0.010919790714979172f, 0.01214396022260189f, 0.00957320537418127f, 0.004137284588068724f, 0.020605430006980896f, 0.011530977673828602f, 0.00823014322668314f, 0.013148831203579903f, 0.009553773328661919f, 0.011024813167750835f, 0.014138218946754932f, 0.008743449114263058f, 0.0019878270104527473f, 0.00509693194180727f, 0.008495080284774303f, 0.008172787725925446f, 0.007477025967091322f, 0.00881888996809721f, 0.01359802857041359f, 0.011267713271081448f, 0.011198733001947403f, 0.012882368639111519f, 0.018537849187850952f, 0.009956558234989643f, 2.6521758593374984e-22f, 0.00694171991199255f, 0.010710909962654114f, 0.0052427491173148155f, 0.013803575187921524f, 0.010372865945100784f, 0.005838401615619659f, 0.006868426688015461f, 0.009646103717386723f, 0.00878979917615652f, 0.008017211221158504f, 0.008205599151551723f, 0.006217170041054487f, 4.085896775552726e-24f, 3.695102577284836e-24f, 0.005436275154352188f, 0.006248369812965393f, 0.008189749903976917f, 2.0894484328119487e-22f, 6.860645668794066e-23f, 0.00744286086410284f, 0.013089347630739212f, 0.011578814126551151f, 3.7783132979526676e-22f, 0.009219303727149963f, 1.0366235773196589e-23f, 2.5316881476821723e-22f, 0.00609244778752327f, 0.011589456349611282f, 0.009580458514392376f, 0.014300264418125153f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #51 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_7_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 104,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.002656655153259635f, 0.0018650077981874347f, 0.0023157759569585323f, 0.004557100124657154f, 0.001971998019143939f, 0.0021054954268038273f, 0.0017594029195606709f, 0.0016229987377300858f, 0.0027816342189908028f, 0.001938194502145052f, 0.002866619499400258f, 0.003332854015752673f, 4.5357004962868e-14f, 0.002061574487015605f, 0.004117170348763466f, 0.0059009576216340065f, 0.0037396601401269436f, 0.0035296299029141665f, 0.0018411512719467282f, 3.35398581228219e-05f, 0.002997875679284334f, 0.0024189564865082502f, 0.0021362612023949623f, 0.006526401732116938f, 0.002473444677889347f, 0.003177609294652939f, 0.0031141170766204596f, 0.0013850715477019548f, 0.0017458192305639386f, 9.774253703653812e-05f, 0.0014473285991698503f, 0.0022673537023365498f, 0.003189947921782732f, 0.003840629244223237f, 0.0027520046569406986f, 0.0018549204105511308f, 0.0022404894698411226f, 0.0020968534518033266f, 0.0021283405367285013f, 0.0016442943597212434f, 0.0011989582562819123f, 0.002743229502812028f, 0.0016217835946008563f, 0.0031831050291657448f, 0.00190876389387995f, 0.008949119597673416f, 0.001955188810825348f, 0.0015990122919902205f, 0.0024217066820710897f, 0.0022905520163476467f, 0.004076898563653231f, 0.0017706867074593902f, 0.003630465129390359f, 0.0031980895437300205f, 0.0022188560105860233f, 0.0030395667999982834f, 0.0027938622515648603f, 0.0025531307328492403f, 0.0027771908789873123f, 0.0021348167210817337f, 0.0019542633090168238f, 0.00215567322447896f, 0.0018236696487292647f, 0.0021331384778022766f, 0.001879399293102324f, 0.003370567224919796f, 0.001257516909390688f, 0.0022086557000875473f, 0.0016666797455400229f, 0.0035605207085609436f, 0.003872944973409176f, 0.0015902300365269184f, 0.001610034960322082f, 0.002872526179999113f, 1.399971177925909e-21f, 0.002243681810796261f, 0.0020516333170235157f, 0.003103110007941723f, 4.077411235453535e-22f, 0.0018191722920164466f, 0.006054823286831379f, 0.002995070768520236f, 0.0023695221170783043f, 0.002346160588786006f, 0.002733440138399601f, 0.002209125319495797f, 1.9542368153764024e-21f, 0.0031685305293649435f, 3.2389312366975416e-17f, 0.0017132110660895705f, 0.002853797748684883f, 0.0013635460054501891f, 0.005151291377842426f, 0.003495393320918083f, 0.0022414221893996f, 1.521859572071884e-23f, 0.0027962112799286842f, 1.1832443011505767e-11f, 0.003213095013052225f, 0.002909546485170722f, 0.0017417294438928366f, 0.0059331078082323074f, 2.7263019959741097e-19f, 7.396728764425334e-14f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #52 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_7_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 104,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0043657077476382256f, 0.0030647858511656523f, 0.0038055377081036568f, 0.007488728035241365f, 0.00324060395359993f, 0.003459981642663479f, 0.0028912443667650223f, 0.0026670899242162704f, 0.004571087192744017f, 0.003185054287314415f, 0.004710744135081768f, 0.005476912017911673f, 7.453561964680666e-14f, 0.003387805772945285f, 0.006765787024050951f, 0.009697102010250092f, 0.006145420949906111f, 0.005800276063382626f, 0.003025582293048501f, 5.511638300959021e-05f, 0.004926438909024f, 0.003975095227360725f, 0.003510539187118411f, 0.010724901221692562f, 0.004064636304974556f, 0.005221797153353691f, 0.005117459688335657f, 0.0022761018481105566f, 0.002868922194465995f, 0.00016062128997873515f, 0.002378409495577216f, 0.0037259648088365793f, 0.005242072977125645f, 0.00631134444847703f, 0.004522396717220545f, 0.0030482092406600714f, 0.0036818187218159437f, 0.003445780137553811f, 0.003497523255646229f, 0.0027020853012800217f, 0.001970259938389063f, 0.004507976118475199f, 0.002665093168616295f, 0.005230828188359737f, 0.003136690706014633f, 0.01470617763698101f, 0.0032129811588674784f, 0.0026276728603988886f, 0.003979614470154047f, 0.0037640868686139584f, 0.00669960817322135f, 0.0029097869992256165f, 0.005965979304164648f, 0.005255452357232571f, 0.0036462682764977217f, 0.004994950257241726f, 0.00459118140861392f, 0.004195584915578365f, 0.004563785623759031f, 0.00350816547870636f, 0.0032114603091031313f, 0.0035424393136054277f, 0.0029968544840812683f, 0.0035054075997322798f, 0.003088435623794794f, 0.00553888687863946f, 0.0020664900075644255f, 0.003629505867138505f, 0.002738871378824115f, 0.005851039197295904f, 0.006364448927342892f, 0.0026132408529520035f, 0.0026457863859832287f, 0.004720450844615698f, 2.3005865870886966e-21f, 0.003687064629048109f, 0.0033714694436639547f, 0.005099371541291475f, 6.700450233266769e-22f, 0.002989463973790407f, 0.009949951432645321f, 0.004921829793602228f, 0.0038938592188060284f, 0.00385546893812716f, 0.004491889383643866f, 0.0036302777007222176f, 3.211416848828108e-21f, 0.0052068778313696384f, 5.3225677668553413e-17f, 0.002815336687490344f, 0.004689674358814955f, 0.002240728819742799f, 0.008465168066322803f, 0.005744014400988817f, 0.003683351445943117f, 2.5008869158656369e-23f, 0.004595041740685701f, 1.9444371460175525e-11f, 0.005280110985040665f, 0.00478128669783473f, 0.0028622013051062822f, 0.009749935008585453f, 4.480159090097457e-19f, 1.2155117949490257e-13f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #53 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_9_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 104,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.015115238726139069f, 0.02162812650203705f, 0.009083830751478672f, 0.004873428959399462f, 0.022151494398713112f, 0.00878896377980709f, 0.013637970201671124f, 0.018806830048561096f, 0.011484986171126366f, 0.009976360946893692f, 0.008289024233818054f, 0.010355183854699135f, 3.8457088127061625e-14f, 0.012489547953009605f, 0.0040313187055289745f, 0.005913719534873962f, 0.006836321670562029f, 0.009855501353740692f, 0.014279017224907875f, 0.0016968667041510344f, 0.011476322077214718f, 0.008141056634485722f, 0.004595115315169096f, 0.003631350351497531f, 0.015576301142573357f, 0.012438180856406689f, 0.00924973376095295f, 0.01137852855026722f, 0.011270499788224697f, 0.002770701888948679f, 0.01212076935917139f, 0.00795775093138218f, 0.01041241455823183f, 0.011576120741665363f, 0.008950372226536274f, 0.01150327268987894f, 0.007186377886682749f, 0.007516122423112392f, 0.005435310769826174f, 0.011482203379273415f, 0.008209058083593845f, 0.00880113709717989f, 0.012047057040035725f, 0.008516961708664894f, 0.015037613920867443f, 0.00416038790717721f, 0.013583827763795853f, 0.007957781665027142f, 0.009578634053468704f, 0.007038472685962915f, 0.007240538951009512f, 0.01255993265658617f, 0.009472236037254333f, 0.014183680526912212f, 0.012177410535514355f, 0.014892318286001682f, 0.01567774824798107f, 0.009546860121190548f, 0.014451856724917889f, 0.01313536986708641f, 0.010929079726338387f, 0.015615997835993767f, 0.010618653148412704f, 0.008149919100105762f, 0.0084574269130826f, 0.007710827514529228f, 0.013907374814152718f, 0.01792532578110695f, 0.012357010506093502f, 0.009590547531843185f, 0.008415591903030872f, 0.009016268886625767f, 0.011901372112333775f, 0.009128057397902012f, 5.339255942277332e-24f, 0.009470713324844837f, 0.013204357586801052f, 0.005058365408331156f, 1.0868397015328603e-24f, 0.018587583675980568f, 0.005573711358010769f, 0.008378124795854092f, 0.0077379499562084675f, 0.011309299618005753f, 0.005276765674352646f, 0.011689962819218636f, 2.254537330306512e-23f, 0.010253113694489002f, 5.068502881304374e-17f, 0.01608910597860813f, 0.012320703826844692f, 0.012015993706882f, 0.009524978697299957f, 0.013963689096271992f, 0.011279045604169369f, 6.982003399364542e-23f, 0.011665159836411476f, 4.673130979404583e-11f, 0.008713594637811184f, 0.0037765142042189837f, 0.010297113098204136f, 0.008547959849238396f, 2.1542055312625947e-19f, 6.204048098824508e-14f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #54 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_9_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 104,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0201597698032856f, 0.02884625643491745f, 0.012115451507270336f, 0.006499877665191889f, 0.029544292017817497f, 0.011722175404429436f, 0.018189480528235435f, 0.025083385407924652f, 0.015317963436245918f, 0.013305852189660072f, 0.011055387556552887f, 0.013811103068292141f, 5.129168370956484e-14f, 0.016657786443829536f, 0.005376723129302263f, 0.00788735318928957f, 0.009117862209677696f, 0.01314465794712305f, 0.01904447004199028f, 0.0022631757892668247f, 0.01530640758574009f, 0.010858037509024143f, 0.0061286804266273975f, 0.004843270406126976f, 0.020774705335497856f, 0.016589274629950523f, 0.012336722575128078f, 0.015175976790487766f, 0.01503189466893673f, 0.0036953906528651714f, 0.01616593264043331f, 0.01061355508863926f, 0.013887434266507626f, 0.015439513139426708f, 0.011937452480196953f, 0.015342352911829948f, 0.009584746323525906f, 0.010024539195001125f, 0.00724928081035614f, 0.015314252115786076f, 0.010948733426630497f, 0.011738412082195282f, 0.016067618504166603f, 0.011359396390616894f, 0.020056238397955894f, 0.005548867862671614f, 0.0181172676384449f, 0.010613596066832542f, 0.012775389477610588f, 0.009387479163706303f, 0.009656982496380806f, 0.016751660034060478f, 0.012633481994271278f, 0.01891731470823288f, 0.01624147593975067f, 0.019862452521920204f, 0.020910009741783142f, 0.012733010575175285f, 0.019274991005659103f, 0.017519142478704453f, 0.014576530084013939f, 0.020827651023864746f, 0.014162502251565456f, 0.010869857855141163f, 0.011279992759227753f, 0.010284224525094032f, 0.018548795953392982f, 0.02390768937766552f, 0.01648101583123207f, 0.012791278772056103f, 0.01122419536113739f, 0.012025341391563416f, 0.015873312950134277f, 0.012174437753856182f, 7.121168876009478e-24f, 0.012631450779736042f, 0.017611155286431313f, 0.0067465347237885f, 1.449559523475292e-24f, 0.024790968745946884f, 0.0074338712729513645f, 0.011174224317073822f, 0.010320398956537247f, 0.015083643607795238f, 0.007037823554128408f, 0.015591348521411419f, 3.006962328037176e-23f, 0.013674967922270298f, 6.760055470239794e-17f, 0.02145865373313427f, 0.016432592645287514f, 0.01602618768811226f, 0.012703826650977135f, 0.018623903393745422f, 0.015043293125927448f, 9.312164091489161e-23f, 0.015558267943561077f, 6.232733079647446e-11f, 0.011621653102338314f, 0.005036880727857351f, 0.013733651489019394f, 0.011400739662349224f, 2.873145941747879e-19f, 8.27457541504803e-14f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #55 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_10_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 80,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003374881576746702f, 0.00158806296531111f, 0.00026787162641994655f, 3.406943505979143e-05f, 0.001945973839610815f, 0.0027199138421565294f, 0.0029343608766794205f, 3.963549534091726e-05f, 0.0014858340146020055f, 0.002089110901579261f, 0.0020943002309650183f, 0.0009978836169466376f, 0.002041572006419301f, 0.0030909175984561443f, 0.0026671835221350193f, 0.0013577964855358005f, 0.0021586939692497253f, 0.002850522752851248f, 0.004876214079558849f, 0.0019408805528655648f, 0.0010701639112085104f, 0.0016941892681643367f, 0.0037272966001182795f, 0.001782566076144576f, 0.0005805519758723676f, 0.002103534061461687f, 0.0021245309617370367f, 0.0011349727865308523f, 0.0019079832127317786f, 0.003060546237975359f, 0.001464522909373045f, 0.002491240855306387f, 0.002387835644185543f, 3.996067971456796e-05f, 0.0028035463765263557f, 0.0009292915347032249f, 0.0030743773095309734f, 0.003479248844087124f, 0.0033036116510629654f, 0.0019105860264971852f, 1.989079237318947e-06f, 0.0017085983417928219f, 0.0015087269712239504f, 0.0028799432329833508f, 0.0009928338695317507f, 0.003599356161430478f, 0.002748357132077217f, 0.002525005955249071f, 0.002928917296230793f, 0.0033697865437716246f, 0.0035986145958304405f, 0.0007906836690381169f, 0.0027573045808821917f, 0.0016851592808961868f, 0.002378541976213455f, 0.0006893450045026839f, 0.003057507798075676f, 0.002896026009693742f, 0.0024208263494074345f, 0.0026872155722230673f, 0.003087177174165845f, 0.0031034748535603285f, 0.0023627663031220436f, 0.0037093921564519405f, 0.0008931429474614561f, 0.0021204908844083548f, 0.0030466935131698847f, 0.004027258139103651f, 0.0018568532541394234f, 0.0019624929409474134f, 0.0025297317188233137f, 0.0001558672374812886f, 0.003470583353191614f, 0.0046004317700862885f, 0.0035059733781963587f, 0.0024472170043736696f, 0.0030615993309766054f, 0.00209910050034523f, 0.0023030529264360666f, 0.003187292953953147f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #56 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_10_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 80,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.002465928439050913f, 0.0011603516759350896f, 0.000195726053789258f, 2.4893552108551376e-05f, 0.0014218668220564723f, 0.001987362513318658f, 0.0021440526470541954f, 2.8960510462638922e-05f, 0.0010856559965759516f, 0.0015264529502019286f, 0.0015302447136491537f, 0.0007291247020475566f, 0.0014917176449671388f, 0.002258444204926491f, 0.0019488339312374592f, 0.0009921026648953557f, 0.0015772953629493713f, 0.0020827946718782187f, 0.0035629088524729013f, 0.0014181453734636307f, 0.0007819378515705466f, 0.001237895106896758f, 0.0027234279550611973f, 0.0013024695217609406f, 0.00042419254896230996f, 0.0015369915636256337f, 0.0015523333568125963f, 0.0008292918209917843f, 0.0013941081706434488f, 0.002236252650618553f, 0.0010700846323743463f, 0.0018202777719125152f, 0.001744722481817007f, 2.9198114134487696e-05f, 0.002048470312729478f, 0.0006790064508095384f, 0.0022463586647063494f, 0.00254218652844429f, 0.0024138535372912884f, 0.0013960100477561355f, 1.4533627563650953e-06f, 0.0012484234757721424f, 0.0011023832485079765f, 0.0021042912267148495f, 0.0007254350348375738f, 0.002629945520311594f, 0.002008145209401846f, 0.0018449488561600447f, 0.0021400752011686563f, 0.002462205709889531f, 0.0026294037234038115f, 0.0005777297192253172f, 0.002014682861045003f, 0.0012312971521168947f, 0.0017379318596795201f, 0.0005036844522692263f, 0.0022340326104313135f, 0.002116042422130704f, 0.0017688279040157795f, 0.0019634708296507597f, 0.0022557112388312817f, 0.002267619362100959f, 0.001726405113004148f, 0.0027103456668555737f, 0.000652593735139817f, 0.0015493814134970307f, 0.002226131036877632f, 0.0029426012188196182f, 0.0013567489804700017f, 0.0014339368790388107f, 0.0018484018510207534f, 0.00011388769053155556f, 0.002535854931920767f, 0.0033614025451242924f, 0.0025617133360356092f, 0.0017881107050925493f, 0.002237022155895829f, 0.0015337520744651556f, 0.0016827742801979184f, 0.002328862901777029f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #57 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_12_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 80,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003264068625867367f, 0.008206367492675781f, 2.969396700791549e-05f, 8.14106095018767e-23f, 0.006623853463679552f, 0.00432141637429595f, 0.00561713520437479f, 3.452673216775004e-11f, 0.006216385401785374f, 0.005370393395423889f, 0.004283854737877846f, 0.00782008282840252f, 0.007100257556885481f, 0.005417004693299532f, 0.005352850537747145f, 0.0055225747637450695f, 0.0058463215827941895f, 0.006034908350557089f, 0.003982289228588343f, 0.010807427577674389f, 0.009093414060771465f, 0.004874073434621096f, 0.005304393358528614f, 0.008924833498895168f, 0.010799522511661053f, 0.004568193107843399f, 0.004229245241731405f, 0.012938491068780422f, 0.004290763288736343f, 0.005632238928228617f, 0.011244385503232479f, 0.005159691907465458f, 0.005136043298989534f, 5.608587596087067e-13f, 0.004783258773386478f, 0.007405976299196482f, 0.0064193676225841045f, 0.005532500799745321f, 0.010573869571089745f, 0.005223629530519247f, 2.9405828172457404e-05f, 0.005104884505271912f, 0.01002920139580965f, 0.0054695336148142815f, 0.007226923946291208f, 0.006111606024205685f, 0.004934384021908045f, 0.0040208930149674416f, 0.005168787203729153f, 0.006579363252967596f, 0.004320312757045031f, 0.009550348855555058f, 0.00495766568928957f, 0.005035542417317629f, 0.0070040482096374035f, 0.010785352438688278f, 0.003951507154852152f, 0.00367143121547997f, 0.006652177777141333f, 0.004771557170897722f, 0.0039597973227500916f, 0.004168075043708086f, 0.006252861116081476f, 0.004999920260161161f, 0.011363586410880089f, 0.005833124741911888f, 0.005196947604417801f, 0.00594673678278923f, 0.008031602948904037f, 0.005629229359328747f, 0.00522640673443675f, 0.015463016927242279f, 0.005813551601022482f, 0.0039378805086016655f, 0.004879881627857685f, 0.006263162940740585f, 0.004707104992121458f, 0.004809637553989887f, 0.006259184330701828f, 0.004334385972470045f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #58 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_12_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 80,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.001640072325244546f, 0.004123392514884472f, 1.4920106877980288e-05f, 4.09057827059476e-23f, 0.003328238381072879f, 0.0021713499445468187f, 0.0028224000707268715f, 1.734839008560307e-11f, 0.0031235008500516415f, 0.002698421711102128f, 0.002152476692572236f, 0.003929298836737871f, 0.003567613661289215f, 0.0027218421455472708f, 0.002689606975764036f, 0.0027748870197683573f, 0.002937557641416788f, 0.0030323155224323273f, 0.0020009512081742287f, 0.005430327728390694f, 0.0045691002160310745f, 0.0024490393698215485f, 0.00266525917686522f, 0.0044843945652246475f, 0.005426355637609959f, 0.00229534599930048f, 0.002125037368386984f, 0.0065011074766516685f, 0.0021559479646384716f, 0.0028299891855567694f, 0.005649882834404707f, 0.002592551987618208f, 0.0025806694757193327f, 2.818105449518826e-13f, 0.002403408521786332f, 0.0037212257739156485f, 0.0032254918478429317f, 0.002779874484986067f, 0.0053129736334085464f, 0.0026246781926602125f, 1.4775328054383863e-05f, 0.002565013477578759f, 0.005039298441261053f, 0.0027482358273118734f, 0.003631258849054575f, 0.0030708531849086285f, 0.002479343209415674f, 0.0020203483290970325f, 0.002597121987491846f, 0.0033058838453143835f, 0.002170795341953635f, 0.004798692651093006f, 0.0024910413194447756f, 0.002530171535909176f, 0.0035192719660699368f, 0.005419235676527023f, 0.0019854845013469458f, 0.0018447567708790302f, 0.0033424703869968653f, 0.002397528849542141f, 0.0019896498415619135f, 0.00209430162794888f, 0.003141828579828143f, 0.0025122726801782846f, 0.005709776654839516f, 0.0029309268575161695f, 0.002611271571367979f, 0.002988012507557869f, 0.004035579971969128f, 0.0028284769505262375f, 0.002626073779538274f, 0.007769586984068155f, 0.00292109209112823f, 0.0019786376506090164f, 0.0024519579019397497f, 0.003147004870697856f, 0.002365143969655037f, 0.002416662871837616f, 0.003145005786791444f, 0.002177866641432047f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #59 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_13_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 160,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0017708835657685995f, 0.0017421653028577566f, 0.0011503715068101883f, 0.001160758314654231f, 3.50327136402484e-05f, 0.0017590851057320833f, 0.0015372465131804347f, 0.0014878663932904601f, 0.0012809676118195057f, 0.003078389447182417f, 0.0016625465359538794f, 0.0008625100599601865f, 0.002243063412606716f, 0.0018116190331056714f, 0.000887861882802099f, 0.001619397778995335f, 0.002961956663057208f, 0.0014366082614287734f, 0.0011684125056490302f, 0.000833387253805995f, 0.0022363269235938787f, 0.0016950293211266398f, 0.0017441895324736834f, 0.0014623294118791819f, 0.0017673514084890485f, 0.0015662898076698184f, 0.0024095172993838787f, 0.0010557333007454872f, 0.0011066454462707043f, 0.0010434342548251152f, 0.001955789979547262f, 0.0012288594152778387f, 0.001045944751240313f, 0.0025919396430253983f, 0.0016055681044235826f, 0.0018987004877999425f, 0.0022229054011404514f, 0.0027569145895540714f, 0.002207512501627207f, 0.0018753386102616787f, 0.0012648145202547312f, 0.0015099338488653302f, 0.0015504856128245592f, 0.00252109719440341f, 0.0019007375231012702f, 0.002029100665822625f, 0.0009511969401501119f, 0.0013846935471519828f, 0.0011976456735283136f, 0.0011837438214570284f, 0.001844846410676837f, 0.00128713040612638f, 0.00196439353749156f, 1.930697908392176e-05f, 0.0012913314858451486f, 0.003203497501090169f, 0.001741016749292612f, 0.0017402354860678315f, 0.0013921525096520782f, 0.0018604891374707222f, 1.2688968126894906e-05f, 0.0022969371639192104f, 0.0021540976595133543f, 0.0015264750691130757f, 0.001791597343981266f, 0.0010740142315626144f, 0.0012122291373088956f, 0.0022004239726811647f, 0.0015024066669866443f, 0.0024603826459497213f, 0.0011316980235278606f, 0.002101029735058546f, 0.0009469910874031484f, 0.00014379670028574765f, 0.0020879902876913548f, 0.0021210135892033577f, 0.001381979207508266f, 0.0018839887343347073f, 0.0007745993789285421f, 0.0023612508084625006f, 0.0014927322044968605f, 0.0012604605872184038f, 0.0017519211396574974f, 0.0015415129018947482f, 0.0016576142515987158f, 0.002495975000783801f, 0.0025072693824768066f, 0.0015893200179561973f, 0.0017052605981007218f, 0.002007406437769532f, 0.001132174045778811f, 0.0007133763283491135f, 0.0025515842717140913f, 0.0012482545571401715f, 0.001584625686518848f, 0.00202288874424994f, 0.0014488339656963944f, 0.0016492350259795785f, 0.0019592142198234797f, 0.0015379732940346003f, 0.0014376722974702716f, 0.0014838776551187038f, 0.0018381697591394186f, 0.0014796771574765444f, 0.0018789003370329738f, 0.0006169849075376987f, 0.002345873275771737f, 0.0014837190974503756f, 0.0019412186229601502f, 0.00206340616568923f, 0.0018384091090410948f, 0.0010475937742739916f, 0.0012076855637133121f, 0.0015446941833943129f, 0.0034769864287227392f, 0.0010145929409191012f, 0.0011535658268257976f, 0.0012889804784208536f, 0.0017122155986726284f, 0.0010218595853075385f, 0.001412743586115539f, 0.0012399812694638968f, 0.0014930644538253546f, 0.0012601310154423118f, 0.001761426217854023f, 0.0020643386524170637f, 0.0024628443643450737f, 0.0012588058598339558f, 0.001346852513961494f, 0.0014067216543480754f, 0.0008607857162132859f, 0.002659518038854003f, 0.0010875548468902707f, 0.0023286782670766115f, 0.001532526221126318f, 0.001057348563335836f, 0.0009135820437222719f, 0.0020885972771793604f, 0.0016816550632938743f, 0.0011614201357588172f, 0.005048862658441067f, 0.001336275483481586f, 0.0013266566675156355f, 0.0012719797668978572f, 0.0012458221754059196f, 0.0013644980499520898f, 0.0009019113495014608f, 0.004807265941053629f, 0.0013755495892837644f, 0.003142107278108597f, 0.001279412186704576f, 0.001945595839060843f, 0.0015514265978708863f, 0.001494217780418694f, 0.0012720796512439847f, 0.0012329199817031622f, 0.0019759039860218763f, 0.0012245732359588146f, 0.001612048246897757f, 0.003246219363063574f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #60 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_13_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 160,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0010517595801502466f, 0.001034703222103417f, 0.000683226331602782f, 0.0006893952377140522f, 2.080655758618377e-05f, 0.001044752192683518f, 0.0009129983372986317f, 0.0008836705819703639f, 0.0007607896695844829f, 0.0018283107783645391f, 0.0009874162496998906f, 0.0005122602451592684f, 0.001332195708528161f, 0.001075953128747642f, 0.0005273171118460596f, 0.0009617894538678229f, 0.001759159262292087f, 0.0008532274514436722f, 0.0006939411978237331f, 0.0004949636640958488f, 0.001328194746747613f, 0.0010067083640024066f, 0.0010359054431319237f, 0.0008685037028044462f, 0.0010496617760509253f, 0.0009302476537413895f, 0.001431055599823594f, 0.0006270189769566059f, 0.000657256634440273f, 0.0006197143229655921f, 0.0011615788098424673f, 0.0007298417040146887f, 0.0006212053704075515f, 0.001539399498142302f, 0.0009535757708363235f, 0.0011276723816990852f, 0.0013202234404161572f, 0.0016373811522498727f, 0.001311081345193088f, 0.0011137973051518202f, 0.000751196057535708f, 0.0008967768517322838f, 0.0009208612609654665f, 0.001497324905358255f, 0.0011288821697235107f, 0.0012051193043589592f, 0.0005649329395964742f, 0.0008223943877965212f, 0.0007113032625056803f, 0.0007030467386357486f, 0.0010956873884424567f, 0.0007644498837180436f, 0.001166688627563417f, 1.1466761861811392e-05f, 0.0007669449551030993f, 0.0019026147201657295f, 0.001034021144732833f, 0.0010335571132600307f, 0.0008268243982456625f, 0.0011049779132008553f, 7.536206339864293e-06f, 0.0013641922269016504f, 0.0012793573550879955f, 0.0009066009661182761f, 0.0010640618856996298f, 0.0006378763355314732f, 0.0007199646788649261f, 0.0013068713014945388f, 0.0008923063287511468f, 0.0014612654922530055f, 0.0006721357931382954f, 0.0012478393036872149f, 0.0005624350160360336f, 8.540344424545765e-05f, 0.0012400948908179998f, 0.0012597080785781145f, 0.0008207822684198618f, 0.0011189347133040428f, 0.00046004849718883634f, 0.001402389258146286f, 0.0008865604759193957f, 0.0007486101821996272f, 0.0010404974455013871f, 0.0009155322331935167f, 0.0009844868909567595f, 0.001482404419220984f, 0.0014891123864799738f, 0.0009439256973564625f, 0.0010127848945558071f, 0.0011922348057851195f, 0.0006724185077473521f, 0.0004236870154272765f, 0.0015154317952692509f, 0.0007413608254864812f, 0.0009411376668140292f, 0.0012014299863949418f, 0.0008604885078966618f, 0.0009795103687793016f, 0.001163612469099462f, 0.000913429947104305f, 0.0008538594120182097f, 0.0008813015883788466f, 0.0010917220497503877f, 0.0008788068662397563f, 0.0011159126879647374f, 0.00036643841303884983f, 0.0013932562433183193f, 0.0008812074083834887f, 0.0011529246112331748f, 0.0012254939647391438f, 0.0010918641928583384f, 0.0006221847725100815f, 0.0007172661717049778f, 0.0009174216538667679f, 0.0020650445949286222f, 0.000602584972511977f, 0.0006851234938949347f, 0.0007655486697331071f, 0.0010169156594201922f, 0.000606900779530406f, 0.000839053769595921f, 0.0007364471675828099f, 0.0008867577998898923f, 0.0007484144298359752f, 0.0010461426572874188f, 0.0012260478688403964f, 0.00146272755227983f, 0.0007476274040527642f, 0.0007999198860488832f, 0.000835477258078754f, 0.0005112360813654959f, 0.001579535542987287f, 0.0006459183641709387f, 0.0013830438256263733f, 0.0009101948817260563f, 0.0006279782974161208f, 0.0005425927811302245f, 0.0012404554290696979f, 0.0009987651137635112f, 0.0006897882558405399f, 0.002998610259965062f, 0.00079363799886778f, 0.0007879252079874277f, 0.0007554516196250916f, 0.0007399161695502698f, 0.0008103998843580484f, 0.0005356613546609879f, 0.002855121623724699f, 0.0008169636130332947f, 0.0018661539070308208f, 0.0007598658557981253f, 0.001155524281784892f, 0.0009214201127178967f, 0.000887442787643522f, 0.0007555109332315624f, 0.0007322533056139946f, 0.00117352488450706f, 0.0007272960501722991f, 0.000957424403168261f, 0.001927988021634519f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #61 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_15_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 160,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.01087827980518341f, 0.007788741961121559f, 0.01323026791214943f, 0.012059055268764496f, 0.0011610918445512652f, 0.005451847333461046f, 0.010066238231956959f, 0.007033109664916992f, 0.006506905425339937f, 0.010959045961499214f, 0.011677301488816738f, 0.009004623629152775f, 0.0047694044187664986f, 0.009592853486537933f, 0.01941652223467827f, 0.010885982774198055f, 0.008098592981696129f, 0.012732580304145813f, 0.008179991506040096f, 0.024393822997808456f, 0.01557935494929552f, 0.010601140558719635f, 0.012703167274594307f, 0.009791317395865917f, 0.008169601671397686f, 0.00504135200753808f, 0.012945078313350677f, 0.011546729132533073f, 0.010708032175898552f, 0.013848427683115005f, 0.004062972962856293f, 0.009886286221444607f, 0.012965518049895763f, 0.006722407881170511f, 0.007906030863523483f, 0.011035229079425335f, 0.010904648341238499f, 0.0062672533094882965f, 0.004730315413326025f, 0.01094092708081007f, 0.009112346917390823f, 0.011799659579992294f, 0.009638394229114056f, 0.02021355926990509f, 0.005375921260565519f, 0.008757944218814373f, 0.01353179756551981f, 0.006990330759435892f, 0.00984080322086811f, 0.006815472152084112f, 0.006916327401995659f, 0.010829436592757702f, 0.008064348250627518f, 0.0009379831608384848f, 0.011754901148378849f, 0.00426164036616683f, 0.00912571232765913f, 0.010929218493402004f, 0.008776291273534298f, 0.0103601710870862f, 4.308280404075049e-05f, 0.004667359869927168f, 0.007965067401528358f, 0.009303797967731953f, 0.012138129211962223f, 0.012388707138597965f, 0.00988201517611742f, 0.010475225746631622f, 0.015728184953331947f, 0.007353840861469507f, 0.014874087646603584f, 0.009458576329052448f, 0.006474732421338558f, 0.0034529846161603928f, 0.0068976618349552155f, 0.010714934207499027f, 0.01097446121275425f, 0.007890141569077969f, 0.022687062621116638f, 0.0042478167451918125f, 0.012589066289365292f, 0.006580313201993704f, 0.011956878937780857f, 0.019750110805034637f, 0.005337528884410858f, 0.01198576856404543f, 0.009119725786149502f, 0.011900518089532852f, 0.01146178599447012f, 0.0068231066688895226f, 0.009616975672543049f, 0.020274076610803604f, 0.009058492258191109f, 0.01096746139228344f, 0.019385740160942078f, 0.005528850015252829f, 0.012946379370987415f, 0.008081258274614811f, 0.009624753147363663f, 0.008913585916161537f, 0.0071478597819805145f, 0.015910128131508827f, 0.008627895265817642f, 0.010124677792191505f, 0.006149830762296915f, 0.016817418858408928f, 0.0078101917169988155f, 0.007500896230340004f, 0.008084932342171669f, 0.013398537412285805f, 0.012220322154462337f, 0.008609160780906677f, 0.01072593405842781f, 0.007254341151565313f, 0.009198538027703762f, 0.011213047429919243f, 0.0091177923604846f, 0.011843771673738956f, 0.012217462994158268f, 0.01198342815041542f, 0.003868058556690812f, 0.008969354443252087f, 0.008826857432723045f, 0.007886409759521484f, 0.009911672212183475f, 0.011534719727933407f, 0.0064302184619009495f, 0.008261032402515411f, 0.007650585379451513f, 0.01460825465619564f, 0.009631522931158543f, 0.010926829650998116f, 0.014049227349460125f, 0.010228168219327927f, 0.008072223514318466f, 0.01603621244430542f, 0.01394197903573513f, 0.006102759391069412f, 0.01042367797344923f, 0.008178284391760826f, 0.004654937423765659f, 0.01700347475707531f, 0.008999917656183243f, 0.010308700613677502f, 0.01280718483030796f, 0.010645096190273762f, 0.01635768823325634f, 0.013514498248696327f, 0.008072096854448318f, 0.00899139977991581f, 0.009822056628763676f, 0.007741850335150957f, 0.008275500498712063f, 0.01528597716242075f, 0.008002355694770813f, 0.0075669847428798676f, 0.008428419008851051f, 0.01062416285276413f, 0.011693987064063549f, 0.009173693135380745f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #62 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_15_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 160,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0039498768746852875f, 0.0028280734550207853f, 0.004803878255188465f, 0.0043786135502159595f, 0.000421589647885412f, 0.001979552675038576f, 0.0036550266668200493f, 0.0025537051260471344f, 0.002362641505897045f, 0.003979202825576067f, 0.0042399996891617775f, 0.0032695571426302195f, 0.0017317591700702906f, 0.0034831417724490166f, 0.0070500923320651054f, 0.003952674102038145f, 0.0029405795503407717f, 0.004623169079422951f, 0.002970135072246194f, 0.00885733775794506f, 0.005656825844198465f, 0.0038492484018206596f, 0.004612489137798548f, 0.00355520355515182f, 0.0029663625173270702f, 0.0018305027624592185f, 0.004700326360762119f, 0.004192589316517115f, 0.0038880605716258287f, 0.005028330720961094f, 0.0014752555871382356f, 0.0035896864719688892f, 0.00470774807035923f, 0.0024408900644630194f, 0.0028706607408821583f, 0.004006864968687296f, 0.003959451336413622f, 0.002275624545291066f, 0.0017175660468637943f, 0.003972623962908983f, 0.003308671060949564f, 0.004284427966922522f, 0.003499677637591958f, 0.007339494302868843f, 0.0019519840134307742f, 0.003179988358169794f, 0.004913363140076399f, 0.00253817206248641f, 0.0035731717944145203f, 0.0024746814742684364f, 0.002511301776394248f, 0.003932142164558172f, 0.0029281452298164368f, 0.0003405794268473983f, 0.004268175922334194f, 0.0015473912935703993f, 0.0033135239500552416f, 0.003968372941017151f, 0.0031866501085460186f, 0.003761752974241972f, 1.5643261576769873e-05f, 0.0016947070835158229f, 0.002892096759751439f, 0.003378186607733369f, 0.00440732529386878f, 0.004498309455811977f, 0.0035881358198821545f, 0.003803529078140855f, 0.0057108658365905285f, 0.0026701618917286396f, 0.005400745198130608f, 0.0034343861043453217f, 0.0023509596940129995f, 0.0012537703150883317f, 0.0025045243091881275f, 0.003890566760674119f, 0.003984800074249506f, 0.0028648911975324154f, 0.008237617090344429f, 0.0015423719305545092f, 0.004571059253066778f, 0.0023892957251518965f, 0.004341513849794865f, 0.007171217352151871f, 0.001938043860718608f, 0.004352003335952759f, 0.003311350243166089f, 0.0043210494332015514f, 0.004161746706813574f, 0.0024774535559117794f, 0.0034919006284326315f, 0.007361467927694321f, 0.00328911654651165f, 0.00398225849494338f, 0.007038915529847145f, 0.002007512142881751f, 0.004700799006968737f, 0.002934285206720233f, 0.0034947246313095093f, 0.0032365014776587486f, 0.0025953706353902817f, 0.0057769292034208775f, 0.003132767975330353f, 0.0036762459203600883f, 0.0022329885978251696f, 0.0061063640750944614f, 0.0028358616400510073f, 0.002723557176068425f, 0.0029356193263083696f, 0.004864976275712252f, 0.004437169525772333f, 0.0031259653624147177f, 0.0038945607375353575f, 0.0026340337935835123f, 0.003339966991916299f, 0.004071430303156376f, 0.0033106482587754726f, 0.004300444852560759f, 0.004436131101101637f, 0.0043511539697647095f, 0.001404482638463378f, 0.0032567509915679693f, 0.0032050106674432755f, 0.0028635363560169935f, 0.003598904237151146f, 0.004188228864222765f, 0.0023347968235611916f, 0.002999560907483101f, 0.002777908928692341f, 0.005304221995174885f, 0.003497182624414563f, 0.0039675054140388966f, 0.005101240240037441f, 0.0037138231564313173f, 0.0029310048557817936f, 0.005822709761559963f, 0.005062298849225044f, 0.00221589719876647f, 0.0037848122883588076f, 0.0029695152770727873f, 0.0016901964554563165f, 0.006173920352011919f, 0.0032678483985364437f, 0.003743064124137163f, 0.004650257993489504f, 0.0038652087096124887f, 0.005939437076449394f, 0.0049070813693106174f, 0.00293095875531435f, 0.0032647554762661457f, 0.0035663649905472994f, 0.002811047015711665f, 0.003004814265295863f, 0.005550301168113947f, 0.0029056358616799116f, 0.0027475538663566113f, 0.0030603385530412197f, 0.0038576077204197645f, 0.0042460584081709385f, 0.003330945735797286f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #63 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_16_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 104,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(1.3346409843961737e-07f, 0.0017042990075424314f, 0.0020509709138423204f, 0.002630756702274084f, 0.0022973644081503153f, 0.0018402970163151622f, 0.00162826559972018f, 0.002074888674542308f, 0.0019823950715363026f, 2.23524097009431e-07f, 0.0015950247179716825f, 0.003113168990239501f, 3.803305662586354e-05f, 0.0014372445875778794f, 0.0012160016922280192f, 0.0018400391563773155f, 0.0016883158823475242f, 0.001947750337421894f, 0.003957126755267382f, 0.0031739166006445885f, 0.0019526364048942924f, 0.0014895129716023803f, 0.0018113611731678247f, 0.002381172962486744f, 0.0021283822134137154f, 0.0016336542321369052f, 0.0017831994919106364f, 7.695783097005915e-06f, 0.001045506913214922f, 0.00210739066824317f, 0.001600779709406197f, 0.0031853937543928623f, 0.00013941273209638894f, 0.002617762889713049f, 0.0026855526957660913f, 0.0010492823785170913f, 0.001902306918054819f, 0.002694504801183939f, 0.0011517564998939633f, 0.0013789524091407657f, 0.0015738846268504858f, 0.0009678054484538734f, 5.194596974789079e-10f, 9.229079167560883e-10f, 0.0016018792521208525f, 0.0023903045803308487f, 0.0019151869928464293f, 0.0025409869849681854f, 0.002250039717182517f, 0.001464693807065487f, 0.002238516230136156f, 0.0035380967892706394f, 0.0015471470542252064f, 0.001684357412159443f, 0.002442027209326625f, 0.0016423601191490889f, 0.0017558424733579159f, 0.001492013456299901f, 0.0021095804404467344f, 0.0018353140912950039f, 0.0014336471213027835f, 0.0022600030060857534f, 0.0012159718899056315f, 1.6321457678714069e-06f, 0.002509979298338294f, 0.002450699219480157f, 0.00239347736351192f, 0.004132209811359644f, 0.0020454097539186478f, 0.0016494219889864326f, 0.0019271651981398463f, 0.0020499785896390676f, 2.12978629861027e-05f, 0.002319361548870802f, 0.0017632099334150553f, 0.0017025178531184793f, 0.0015922040911391377f, 5.250329060402237e-10f, 0.0017378373304381967f, 0.00217282772064209f, 0.0023895681370049715f, 0.002134284470230341f, 0.0011222525499761105f, 0.0019905446097254753f, 0.0017235312843695283f, 0.0012698472710326314f, 0.0023577092215418816f, 0.002792036160826683f, 0.0009633979061618447f, 1.2482790225476492e-05f, 0.0011026404099538922f, 0.0020380504429340363f, 0.0013444408541545272f, 0.001066299737431109f, 2.547343910919153e-06f, 0.00035640838905237615f, 0.001268800930120051f, 0.0015445977915078402f, 0.001644169562496245f, 0.0017650109948590398f, 0.002577288309112191f, 1.3508247320714872e-05f, 0.0022208404261618853f, 7.86611753511579e-09f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #64 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_16_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 104,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(4.1008377138496144e-08f, 0.0005236654542386532f, 0.0006301843677647412f, 0.0008083302527666092f, 0.0007058916380628943f, 0.0005654524429701269f, 0.0005003033438697457f, 0.000637533375993371f, 0.0006091136601753533f, 6.868035029583552e-08f, 0.0004900897038169205f, 0.0009565569926053286f, 1.1686093785101548e-05f, 0.000441609910922125f, 0.00037363049341365695f, 0.0005653731641359627f, 0.0005187544738873839f, 0.0005984687013551593f, 0.001215872704051435f, 0.0009752223850227892f, 0.0005999699933454394f, 0.0004576699866447598f, 0.0005565615720115602f, 0.0007316427654586732f, 0.0006539698806591332f, 0.0005019590607844293f, 0.000547908537555486f, 2.364617785133305e-06f, 0.0003212440060451627f, 0.0006475200061686337f, 0.0004918579943478107f, 0.0009787488961592317f, 4.28361636295449e-05f, 0.0008043377310968935f, 0.0008251669351011515f, 0.0003224040847271681f, 0.000584505673032254f, 0.0008279175963252783f, 0.0003538904129527509f, 0.0004236989771015942f, 0.00048359413631260395f, 0.0002973693481180817f, 1.5960996413433293e-10f, 2.835740808837528e-10f, 0.0004921958316117525f, 0.0007344485493376851f, 0.0005884632118977606f, 0.0007807474466972053f, 0.0006913505494594574f, 0.0004500439972616732f, 0.0006878098356537521f, 0.0010871209669858217f, 0.00047537870705127716f, 0.0005175381666049361f, 0.0007503409287892282f, 0.0005046340520493686f, 0.0005395027692429721f, 0.0004584382986649871f, 0.0006481928285211325f, 0.000563921348657459f, 0.00044050454744137824f, 0.0006944119231775403f, 0.00037362135481089354f, 5.014955490878492e-07f, 0.000771220016758889f, 0.000753005500882864f, 0.0007354234112426639f, 0.0012696689227595925f, 0.0006284756818786263f, 0.0005068038590252399f, 0.0005921436822973192f, 0.0006298794760368764f, 6.544013103848556e-06f, 0.0007126504788175225f, 0.0005417665233835578f, 0.0005231181858107448f, 0.000489222991745919f, 1.6132239988309038e-10f, 0.0005339704803191125f, 0.0006676262710243464f, 0.0007342222961597145f, 0.0006557834567502141f, 0.0003448250063229352f, 0.0006116176955401897f, 0.0005295748123899102f, 0.0003901751770172268f, 0.000724433280993253f, 0.0008578852284699678f, 0.00029601508867926896f, 3.835480583802564e-06f, 0.0003387989418115467f, 0.00062621443066746f, 0.0004130949091631919f, 0.0003276328498031944f, 7.827006811567117e-07f, 0.00010951057629426941f, 0.0003898536670021713f, 0.0004745954356621951f, 0.0005051899934187531f, 0.0005423199036158621f, 0.0007919014897197485f, 4.150564109295374e-06f, 0.000682378769852221f, 2.416955080519756e-09f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #65 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_18_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 104,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(2.586477876320714e-07f, 0.005082533694803715f, 0.007644679397344589f, 0.005530699156224728f, 0.007064230740070343f, 0.005232787691056728f, 0.004954237025231123f, 0.004378253594040871f, 0.006269048899412155f, 4.452272605703911e-06f, 0.0075188749469816685f, 0.005244834814220667f, 0.0009344112477265298f, 0.005292198620736599f, 0.006926925852894783f, 0.0041822828352451324f, 0.00401302007958293f, 0.0056031327694654465f, 0.005088047590106726f, 0.00616021454334259f, 0.008433702401816845f, 0.005249971058219671f, 0.0065344530157744884f, 0.004751329310238361f, 0.00679136672988534f, 0.003873836249113083f, 0.010657262988388538f, 0.0003131582052446902f, 0.007576692383736372f, 0.004830280784517527f, 0.00888795219361782f, 0.005748172290623188f, 0.0029964055866003036f, 0.006059399805963039f, 0.004631908610463142f, 0.004991068970412016f, 0.006820309441536665f, 0.008316812105476856f, 0.00599741842597723f, 0.010089547373354435f, 0.004590754397213459f, 0.006354816723614931f, 4.4642125551774825e-09f, 4.297577405054653e-09f, 0.005721359513700008f, 0.005924042779952288f, 0.0038579755928367376f, 0.004483209922909737f, 0.005383013281971216f, 0.004727730993181467f, 0.006769247353076935f, 0.005254640243947506f, 0.005231310613453388f, 0.0055304234847426414f, 0.005474003963172436f, 0.005342199467122555f, 0.00571483327075839f, 0.004814191721379757f, 0.004903734661638737f, 0.003823608625680208f, 0.005744533613324165f, 0.006032252684235573f, 0.0052504995837807655f, 6.056275196897332e-06f, 0.0037059613969177008f, 0.004785254132002592f, 0.0047017475590109825f, 0.0062127807177603245f, 0.005029007792472839f, 0.005005638115108013f, 0.0035506642889231443f, 0.005220153369009495f, 0.00031859910814091563f, 0.005001133307814598f, 0.005136977881193161f, 0.007977589964866638f, 0.00442527187988162f, 2.7397666357842354e-09f, 0.00540369376540184f, 0.004008511546999216f, 0.0066895014606416225f, 0.005734199192374945f, 0.005071053747087717f, 0.005029380787163973f, 0.004660571925342083f, 0.00705207884311676f, 0.005739751737564802f, 0.00691424822434783f, 0.007631554268300533f, 0.0011332686990499496f, 0.00048648176016286016f, 0.006263553164899349f, 0.007771972566843033f, 0.008922450244426727f, 2.073750329145696e-05f, 0.056249625980854034f, 0.0072597903199493885f, 0.004679710138589144f, 0.004936814773827791f, 0.005339450668543577f, 0.005789356771856546f, 0.0005875116330571473f, 0.007165831513702869f, 5.1896211772373135e-08f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #66 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_18_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 104,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(3.7999889457296376e-08f, 0.0007467131945304573f, 0.0011231371900066733f, 0.0008125565364025533f, 0.0010378591250628233f, 0.0007687881006859243f, 0.0007278641569428146f, 0.0006432420923374593f, 0.0009210330317728221f, 6.541167749674059e-07f, 0.0011046543950214982f, 0.000770558079238981f, 0.00013728137128055096f, 0.0007775166304782033f, 0.001017686678096652f, 0.0006144505459815264f, 0.0005895828944630921f, 0.0008231982938013971f, 0.00074752327054739f, 0.0009050433873198926f, 0.0012390585616230965f, 0.0007713126833550632f, 0.0009600255289115012f, 0.0006980534526519477f, 0.0009977706940844655f, 0.0005691343685612082f, 0.001565738464705646f, 4.600842294166796e-05f, 0.0011131487553939223f, 0.000709652784280479f, 0.0013057957403361797f, 0.000844507128931582f, 0.00044022445217706263f, 0.0008902319241315126f, 0.0006805084412917495f, 0.0007332754321396351f, 0.0010020228801295161f, 0.0012218853225931525f, 0.0008811257430352271f, 0.0014823311939835548f, 0.000674462178722024f, 0.0009336338262073696f, 6.558709686466102e-10f, 6.313893852194497e-10f, 0.0008405678672716022f, 0.0008703455678187311f, 0.0005668041412718594f, 0.0006586620002053678f, 0.0007908588740974665f, 0.0006945864297449589f, 0.0009945209603756666f, 0.0007719986606389284f, 0.0007685711025260389f, 0.0008125160238705575f, 0.0008042270201258361f, 0.0007848626119084656f, 0.0008396090706810355f, 0.000707289029378444f, 0.0007204444846138358f, 0.0005617550341412425f, 0.0008439725497737527f, 0.0008862435352057219f, 0.0007713903323747218f, 8.897728775991709e-07f, 0.0005444706184789538f, 0.0007030376000329852f, 0.0006907690549269319f, 0.0009127662633545697f, 0.0007388492813333869f, 0.0007354158442467451f, 0.0005216547288000584f, 0.0007669319165870547f, 4.68077851110138e-05f, 0.000734754023142159f, 0.0007547119748778641f, 0.0011720475740730762f, 0.0006501498864963651f, 4.025196842505352e-10f, 0.0007938971975818276f, 0.0005889205494895577f, 0.000982804922387004f, 0.0008424542611464858f, 0.0007450265693478286f, 0.0007389041129499674f, 0.0006847195909358561f, 0.0010360738961026073f, 0.000843270041514188f, 0.001015824149362743f, 0.001121208886615932f, 0.00016649701865389943f, 7.147268479457125e-05f, 0.0009202256333082914f, 0.001141838845796883f, 0.001310864114202559f, 3.046702204301255e-06f, 0.008264054544270039f, 0.001066590310074389f, 0.0006875313702039421f, 0.0007253045332618058f, 0.000784458767157048f, 0.0008505578734911978f, 8.631574746686965e-05f, 0.0010527861304581165f, 7.62446195068378e-09f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #67 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_19_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 208,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0018043556483462453f, 0.001958034699782729f, 0.003535406431183219f, 0.0013042326318100095f, 0.0009506111382506788f, 0.0011317087337374687f, 0.0013769195647910237f, 2.676733004136622e-07f, 0.00015972772962413728f, 0.0013897912576794624f, 0.0011130026541650295f, 0.0018461302388459444f, 0.0006702358368784189f, 0.0018979517044499516f, 0.002128677209839225f, 0.0017847355920821428f, 0.0011644173646345735f, 0.001006113481707871f, 0.0015946471830829978f, 0.0018564957426860929f, 0.001500797807238996f, 0.004444414749741554f, 0.002855355851352215f, 0.0022418333683162928f, 0.0019610519520938396f, 0.0013283219886943698f, 0.001675977953709662f, 0.0001593946508364752f, 0.0019329108763486147f, 0.0021023715380579233f, 0.0011332270223647356f, 0.0013262947322800756f, 0.002753117121756077f, 0.002115629380568862f, 0.0016791541129350662f, 0.0016190953319892287f, 0.001266840030439198f, 0.0016568070277571678f, 0.0009466319461353123f, 0.0012169171823188663f, 0.001440957305021584f, 0.0009495466947555542f, 0.001413644989952445f, 0.0015275028999894857f, 0.001614848617464304f, 0.0012586958473548293f, 0.0013207498705014586f, 0.0015593193238601089f, 1.3599013755083433e-06f, 2.757116419616068e-07f, 0.0023490386083722115f, 0.0015737697249278426f, 0.0012573421699926257f, 0.0013112375745549798f, 2.8265701985219494e-05f, 0.0016786056803539395f, 0.0013449788093566895f, 0.0012757102958858013f, 0.001313564251177013f, 0.0017914402997121215f, 9.762840636540204e-05f, 1.3337611562747043e-05f, 0.0031267323065549135f, 0.003871927037835121f, 0.001053868094459176f, 0.0018644011579453945f, 0.0024136477150022984f, 0.0014223292237147689f, 0.0018432002980262041f, 0.0014711973490193486f, 0.0008813554304651916f, 0.001490949303843081f, 0.0005772003205493093f, 0.0012779667740687728f, 0.0027711119037121534f, 0.0015174857107922435f, 0.0012547102523967624f, 0.0012385268928483129f, 0.0009312463225796819f, 3.5215470006733085e-07f, 0.0010855495929718018f, 0.0011215601116418839f, 0.0011416305787861347f, 0.0014355720486491919f, 0.001096924184821546f, 9.514388693787623e-06f, 0.0009554988355375826f, 0.0013634482165798545f, 0.001696467399597168f, 0.001120376749895513f, 0.0014047332806512713f, 0.0013807832729071379f, 0.0016635480569675565f, 0.0011478756787255406f, 0.0013973494060337543f, 0.0011000928934663534f, 0.001252261339686811f, 0.0015390542102977633f, 0.001683201757259667f, 0.0013472248101606965f, 9.058660452865297e-07f, 0.0020531443879008293f, 0.0016100254142656922f, 0.0008993053925223649f, 1.1917197753064102e-06f, 0.003152492456138134f, 0.001055517583154142f, 0.001082942122593522f, 0.0011939267860725522f, 0.001321379910223186f, 0.001021814881823957f, 0.0013700192794203758f, 0.0018701365916058421f, 0.000918672070838511f, 0.0017161049181595445f, 0.0011428245343267918f, 0.00018432967772241682f, 0.002125999191775918f, 0.0015708130085840821f, 0.001227242755703628f, 0.0016960024368017912f, 0.001353332307189703f, 0.0013783479807898402f, 0.0005987000768072903f, 0.0018967671785503626f, 0.0014253963017836213f, 0.0014498569071292877f, 5.634163358081423e-07f, 3.5393182770349085e-05f, 1.914720115792079e-07f, 0.0009852637303993106f, 0.002673637354746461f, 0.0016102769877761602f, 0.0016393986297771335f, 0.0018697077175602317f, 0.001155038014985621f, 0.0011862000683322549f, 0.001848819782026112f, 0.0011349691776558757f, 0.0009012034279294312f, 0.00013538770144805312f, 0.000879147439263761f, 4.3573612629188574e-07f, 0.0014202372403815389f, 0.0014766217209398746f, 0.0010893252911046147f, 1.5370673054349027e-06f, 0.0016946358373388648f, 0.001335775014013052f, 0.0014780799392610788f, 0.0013875584118068218f, 0.0015907255001366138f, 0.0015497459098696709f, 1.0316618499928154e-05f, 0.0018352054757997394f, 0.0018778713420033455f, 0.0001132171310018748f, 0.0013424446806311607f, 0.0015731548191979527f, 0.0018513279501348734f, 0.0014359250199049711f, 0.0020914783235639334f, 0.0019503498915582895f, 0.0014241928001865745f, 0.0014166577020660043f, 0.002291471464559436f, 0.001598162343725562f, 0.0008324075606651604f, 0.001560928183607757f, 3.752616248675622e-05f, 2.8352764047667733e-07f, 0.0018186151282861829f, 7.669031560908479e-07f, 0.0012945961207151413f, 0.0014740817714482546f, 0.001233772374689579f, 1.7390733773936518e-05f, 0.0008854560437612236f, 0.0010307690827175975f, 0.0015073542017489672f, 0.0014780414057895541f, 0.0019406015053391457f, 0.001521456171758473f, 0.00025582537637092173f, 0.0016513947630301118f, 0.002592328703030944f, 0.0013990855077281594f, 0.0010600729146972299f, 0.001245698076672852f, 0.0015391870401799679f, 0.0014189741341397166f, 0.001802828162908554f, 0.0019417066359892488f, 4.240255293552764e-06f, 0.0010908956173807383f, 0.0014858837239444256f, 0.0013181279646232724f, 0.0010718201519921422f, 0.0012873916421085596f, 0.001245518564246595f, 0.0018738816725090146f, 0.0019509636331349611f, 0.0011336683528497815f, 0.001201437204144895f, 0.0010737907141447067f, 0.0014599676942452788f, 0.0016963803209364414f, 0.0012329285964369774f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #68 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_19_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 208,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0004613513592630625f, 0.0005006451974622905f, 0.0009039595606736839f, 0.0003334761131554842f, 0.00024305947590619326f, 0.0002893638738896698f, 0.0003520612372085452f, 6.84407410744825e-08f, 4.084039755980484e-05f, 0.000355352385668084f, 0.0002845809794962406f, 0.00047203261055983603f, 0.00017137099348474294f, 0.0004852827114518732f, 0.0005442763795144856f, 0.00045633476111106575f, 0.0002977270632982254f, 0.00025725073646754026f, 0.00040773150976747274f, 0.00047468292177654803f, 0.00038373537245206535f, 0.0011363817611709237f, 0.0007300790748558939f, 0.0005732089630328119f, 0.0005014166818000376f, 0.0003396354441065341f, 0.0004285267787054181f, 4.075523611390963e-05f, 0.0004942213417962193f, 0.0005375503096729517f, 0.00028975208988413215f, 0.0003391171048860997f, 0.0007039378979243338f, 0.0005409402074292302f, 0.00042933886288665235f, 0.00041398260509595275f, 0.0003239152720198035f, 0.0004236249951645732f, 0.00024204204964917153f, 0.0003111506230197847f, 0.0003684349067043513f, 0.0002427873114356771f, 0.00036145150079391897f, 0.00039056353853084147f, 0.00041289677028544247f, 0.0003218329220544547f, 0.00033769936999306083f, 0.0003986986121162772f, 3.4770991419463826e-07f, 7.049604988651481e-08f, 0.000600620056502521f, 0.0004023934016004205f, 0.00032148679019883275f, 0.00033526719198562205f, 7.227189144032309e-06f, 0.0004291986406315118f, 0.0003438943822402507f, 0.0003261833044234663f, 0.0003358620742801577f, 0.00045804906403645873f, 2.496237175364513e-05f, 3.4102617973985616e-06f, 0.0007994666812010109f, 0.000990003696642816f, 0.0002694609866011888f, 0.0004767042410094291f, 0.0006171397981233895f, 0.000363671948434785f, 0.00047128344886004925f, 0.00037616692134179175f, 0.0002253516431665048f, 0.00038121725083328784f, 0.00014758296310901642f, 0.0003267602587584406f, 0.0007085389224812388f, 0.0003880022850353271f, 0.00032081385143101215f, 0.0003166759561281651f, 0.00023810812854208052f, 9.004158840753007e-08f, 0.0002775615721475333f, 0.00028676900546997786f, 0.0002919007674790919f, 0.0003670579753816128f, 0.0002804699179250747f, 2.4327111987076933e-06f, 0.0002443091943860054f, 0.0003486167988739908f, 0.0004337656719144434f, 0.00028646644204854965f, 0.0003591728745959699f, 0.00035304916673339903f, 0.00042534861131571233f, 0.00029349757824093103f, 0.0003572849091142416f, 0.00028128011035732925f, 0.00032018768251873553f, 0.0003935170825570822f, 0.0004303737950976938f, 0.000344468659022823f, 2.3161871354204777e-07f, 0.0005249635432846844f, 0.00041166352457366884f, 0.00022994122991804034f, 3.047079530915653e-07f, 0.0008060532272793353f, 0.00026988275931216776f, 0.00027689486159943044f, 0.00030527226044796407f, 0.00033786045969463885f, 0.000261265377048403f, 0.00035029693390242755f, 0.000478170724818483f, 0.0002348930574953556f, 0.00043878675205633044f, 0.000292206066660583f, 4.7130812163231894e-05f, 0.0005435916245914996f, 0.00040163740050047636f, 0.00031379074789583683f, 0.0004336467827670276f, 0.00034603028325363994f, 0.0003524264902807772f, 0.00015308018191717565f, 0.00048497982788830996f, 0.0003644561511464417f, 0.0003707104187924415f, 1.4405856063604006e-07f, 9.04959779290948e-06f, 4.895701977147837e-08f, 0.000251919700531289f, 0.0006836159154772758f, 0.0004117278440389782f, 0.0004191738844383508f, 0.000478061061585322f, 0.0002953288785647601f, 0.0003032966342289001f, 0.00047272027586586773f, 0.0002901975531131029f, 0.00023042653629090637f, 3.461695450823754e-05f, 0.00022478708706330508f, 1.1141231937017437e-07f, 0.0003631370491348207f, 0.0003775538643822074f, 0.0002785269753076136f, 3.930090315407142e-07f, 0.00043329736217856407f, 0.00034154110471718013f, 0.0003779267135541886f, 0.00035478148492984474f, 0.00040672876639291644f, 0.0003962508053518832f, 2.6378313577879453e-06f, 0.00046923928312025964f, 0.0004801484174095094f, 2.8948215913260356e-05f, 0.00034324644366279244f, 0.0004022361827082932f, 0.00047336157876998186f, 0.0003671482263598591f, 0.0005347650730982423f, 0.0004986802814528346f, 0.00036414843634702265f, 0.00036222179187461734f, 0.0005859008524566889f, 0.0004086302942596376f, 0.00021283628302626312f, 0.0003991099656559527f, 9.594974471838214e-06f, 7.24945010688316e-08f, 0.0004649973416235298f, 1.9608762613643194e-07f, 0.00033101215376518667f, 0.0003769044124055654f, 0.00031546028912998736f, 4.446595085028093e-06f, 0.00022640012321062386f, 0.00026355485897511244f, 0.00038541178219020367f, 0.0003779168473556638f, 0.0004961877129971981f, 0.0003890174557454884f, 6.54113755444996e-05f, 0.0004222411662340164f, 0.0006628262926824391f, 0.0003577288007363677f, 0.00027104749460704625f, 0.00031850955565460026f, 0.00039355101762339473f, 0.0003628140839282423f, 0.0004609607858583331f, 0.000496470311190933f, 1.0841806670214282e-06f, 0.00027892846264876425f, 0.0003799220430664718f, 0.00033702896325848997f, 0.000274051126325503f, 0.0003291700850240886f, 0.00031846365891397f, 0.00047912829904817045f, 0.0004988372093066573f, 0.0002898649254348129f, 0.0003071925893891603f, 0.00027455497183836997f, 0.00037329562474042177f, 0.00043374340748414397f, 0.0003152445424348116f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #69 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_21_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 208,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.011213025078177452f, 0.011933497153222561f, 0.012765941210091114f, 0.010804965160787106f, 0.012895235791802406f, 0.008728685788810253f, 0.008203164674341679f, 5.627355221804464e-07f, 0.05521427094936371f, 0.008725589141249657f, 0.01669834554195404f, 0.007973721250891685f, 0.021527035161852837f, 0.010208453051745892f, 0.006685341242700815f, 0.007180481217801571f, 0.005425197537988424f, 0.007659912109375f, 0.006020685657858849f, 0.006160383578389883f, 0.012501467019319534f, 0.006198318675160408f, 0.010929986834526062f, 0.01091177761554718f, 0.0145959984511137f, 0.006108110770583153f, 0.009564872831106186f, 0.04856099188327789f, 0.010129851289093494f, 0.0048146964982151985f, 0.009731904603540897f, 0.011221159249544144f, 0.009332946501672268f, 0.009558319114148617f, 0.008205429650843143f, 0.016018042340874672f, 0.00995959248393774f, 0.01246581319719553f, 0.013769510202109814f, 0.014734858646988869f, 0.01098947785794735f, 0.01671459712088108f, 0.01285124383866787f, 0.011330143548548222f, 0.0038915209006518126f, 0.0074847061187028885f, 0.012197366915643215f, 0.010820257477462292f, 1.1029445886379108e-05f, 2.3599648102390347e-06f, 0.0072066644206643105f, 0.009596417658030987f, 0.00600966764613986f, 0.011891990900039673f, 0.03886483982205391f, 0.011453409679234028f, 0.016261037439107895f, 0.007715445011854172f, 0.006643933709710836f, 0.007663322612643242f, 6.150060926302103e-06f, 0.00028786336770281196f, 0.006608293857425451f, 0.005123859737068415f, 0.012915529310703278f, 0.010184155777096748f, 0.011329127475619316f, 0.01568802073597908f, 0.011611605063080788f, 0.008590797893702984f, 0.015125611796975136f, 0.011654705740511417f, 0.01415139902383089f, 0.009958961978554726f, 0.006021439563483f, 0.013862568885087967f, 0.010112148709595203f, 0.010758409276604652f, 0.01900426484644413f, 3.264656925239251e-06f, 0.012864075601100922f, 0.015363981015980244f, 0.014538604766130447f, 0.0036036474630236626f, 0.011255295015871525f, 0.005356343928724527f, 0.018562696874141693f, 0.007610993459820747f, 0.016334302723407745f, 0.012824377045035362f, 0.014300699345767498f, 0.009507780894637108f, 0.008926503360271454f, 0.005893125664442778f, 0.009273874573409557f, 0.0060405367985367775f, 0.013297751545906067f, 0.008949583396315575f, 0.013030686415731907f, 0.01004945207387209f, 1.5541187167400494e-05f, 0.015672873705625534f, 0.011297781951725483f, 0.01826624758541584f, 4.009355052403407e-06f, 0.008207977749407291f, 0.014554491266608238f, 0.0111825130879879f, 0.017605716362595558f, 0.011957992799580097f, 0.012765161693096161f, 0.02290317602455616f, 0.01492222398519516f, 0.01990904100239277f, 0.009794407524168491f, 0.010830282233655453f, 7.029029802652076e-05f, 0.01088723260909319f, 0.008838123641908169f, 0.013234870508313179f, 0.004931789357215166f, 0.009389796294271946f, 0.014632456004619598f, 0.010094628669321537f, 0.006233979947865009f, 0.00868119765073061f, 0.016985148191452026f, 4.4588305172510445e-06f, 0.0010952218435704708f, 2.888376002374571e-06f, 0.011609319597482681f, 0.008991659618914127f, 0.00987941399216652f, 0.006814524531364441f, 0.0049043516628444195f, 0.014318762347102165f, 0.00626798253506422f, 0.005781842395663261f, 0.012887433171272278f, 0.01697709411382675f, 0.008385942317545414f, 0.016397185623645782f, 9.78322987066349e-07f, 0.011515362188220024f, 0.011707236059010029f, 0.016282357275485992f, 6.127015240053879e-06f, 0.013592940755188465f, 0.01619134098291397f, 0.0070985485799610615f, 0.011408287100493908f, 0.01306809950619936f, 0.007806419860571623f, 0.0006309662712737918f, 0.01553377415984869f, 0.009884683415293694f, 0.02684439904987812f, 0.009523357264697552f, 0.011946704238653183f, 0.008078529499471188f, 0.016194311901926994f, 0.010581830516457558f, 0.010626780800521374f, 0.012254706583917141f, 0.006893474608659744f, 0.013341364450752735f, 0.013848992995917797f, 0.022327423095703125f, 0.012098369188606739f, 0.01102590374648571f, 5.469312895911571e-07f, 0.012366344220936298f, 2.739471028689877e-06f, 0.00900852121412754f, 0.011155230924487114f, 0.010067484341561794f, 0.00031993366428650916f, 0.01229663286358118f, 0.014169244095683098f, 0.005723803304135799f, 0.014879448339343071f, 0.0073171393014490604f, 0.011081745848059654f, 0.11479820311069489f, 0.015545767731964588f, 0.006285153795033693f, 0.008225214667618275f, 0.011049728840589523f, 0.010210578329861164f, 0.006581045687198639f, 0.014307823032140732f, 0.009378080256283283f, 0.012940620072185993f, 1.156357211584691e-05f, 0.008910776115953922f, 0.013924303464591503f, 0.003984373528510332f, 0.01711656153202057f, 0.006378077436238527f, 0.019244417548179626f, 0.0154911819845438f, 0.0042430562898516655f, 0.011292063631117344f, 0.012793296948075294f, 0.008694673888385296f, 0.010171975940465927f, 0.014360003173351288f, 0.020628219470381737f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #70 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_21_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 208,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0008252693805843592f, 0.0008782955119386315f, 0.0009395627421326935f, 0.0007952364976517856f, 0.0009490787051618099f, 0.0006424240418709815f, 0.0006037461571395397f, 4.1416871709998304e-08f, 0.004063724540174007f, 0.0006421961588785052f, 0.0012289844453334808f, 0.00058685929980129f, 0.001584372017532587f, 0.0007513337186537683f, 0.0004920355859212577f, 0.0005284774815663695f, 0.00039929006015881896f, 0.0005637631984427571f, 0.0004431174893397838f, 0.0004533991450443864f, 0.0009200976346619427f, 0.00045619113370776176f, 0.0008044380228966475f, 0.0008030978497117758f, 0.0010742534650489688f, 0.00044955190969631076f, 0.0007039667689241469f, 0.0035740488674491644f, 0.0007455486920662224f, 0.0003543576749507338f, 0.0007162601687014103f, 0.0008258680463768542f, 0.0006868971395306289f, 0.000703484402038157f, 0.0006039128638803959f, 0.0011789146810770035f, 0.0007330178050324321f, 0.0009174735751003027f, 0.0010134245967492461f, 0.0010844734497368336f, 0.0008088165195658803f, 0.0012301804963499308f, 0.0009458409622311592f, 0.0008338892366737127f, 0.0002864127163775265f, 0.0005508681642822921f, 0.0008977161487564445f, 0.0007963620009832084f, 8.117581273836549e-07f, 1.7369146121382073e-07f, 0.0005304045625962317f, 0.0007062884396873415f, 0.0004423065693117678f, 0.0008752407156862319f, 0.00286042015068233f, 0.0008429614827036858f, 0.0011967989848926663f, 0.0005678503657691181f, 0.0004889880656264722f, 0.0005640142480842769f, 4.5263939796313934e-07f, 2.1186506273807026e-05f, 0.0004863649664912373f, 0.0003771118354052305f, 0.0009505723137408495f, 0.0007495454628951848f, 0.0008338144398294389f, 0.0011546253226697445f, 0.000854604528285563f, 0.0006322756526060402f, 0.0011132325744256377f, 0.0008577767293900251f, 0.0010415313299745321f, 0.0007329713553190231f, 0.0004431729903444648f, 0.0010202736593782902f, 0.0007442457717843354f, 0.0007918100454844534f, 0.0013986981939524412f, 2.402760514996771e-07f, 0.0009467853233218193f, 0.0011307763634249568f, 0.0010700293350964785f, 0.00026522547705098987f, 0.0008283804054372013f, 0.0003942225011996925f, 0.001366199110634625f, 0.0005601628217846155f, 0.0012021912261843681f, 0.0009438635897822678f, 0.0010525196557864547f, 0.0006997648160904646f, 0.0006569832912646234f, 0.00043372917571105063f, 0.0006825494929216802f, 0.0004445785307325423f, 0.0009787034941837192f, 0.0006586819654330611f, 0.0009590477566234767f, 0.0007396313594654202f, 1.1438185083534336e-06f, 0.0011535105295479298f, 0.0008315074373967946f, 0.0013443807838484645f, 2.950852149297134e-07f, 0.0006041004089638591f, 0.0010711984941735864f, 0.0008230237290263176f, 0.0012957662111148238f, 0.0008800983778201044f, 0.0009395053493790329f, 0.001685654860921204f, 0.0010982634266838431f, 0.001465289038605988f, 0.0007208603201434016f, 0.0007970998412929475f, 5.173307727091014e-06f, 0.0008012913167476654f, 0.0006504785851575434f, 0.0009740755194798112f, 0.00036297563929110765f, 0.0006910812808200717f, 0.0010769367218017578f, 0.0007429563556797802f, 0.0004588157753460109f, 0.0006389289628714323f, 0.0012500928714871407f, 3.281662372955907e-07f, 8.06074240244925e-05f, 2.1258209415009333e-07f, 0.000854436366353184f, 0.0006617787294089794f, 0.0007271167123690248f, 0.0005015433998778462f, 0.00036095624091103673f, 0.0010538491187617183f, 0.00046131835551932454f, 0.00042553883395157754f, 0.0009485044283792377f, 0.001249500084668398f, 0.0006171984132379293f, 0.001206819317303598f, 7.200376472837888e-08f, 0.0008475211798213422f, 0.0008616428822278976f, 0.0011983680306002498f, 4.509432756094611e-07f, 0.0010004292707890272f, 0.0011916693765670061f, 0.000522447342518717f, 0.0008396405028179288f, 0.0009618013282306492f, 0.0005745460512116551f, 4.643859574571252e-05f, 0.0011432729661464691f, 0.0007275045500136912f, 0.0019757256377488375f, 0.0007009112159721553f, 0.0008792675798758864f, 0.0005945730954408646f, 0.001191888004541397f, 0.0007788140210323036f, 0.0007821223116479814f, 0.0009019362623803318f, 0.000507354037836194f, 0.0009819134138524532f, 0.0010192744666710496f, 0.0016432799166068435f, 0.0008904300048016012f, 0.0008114973898045719f, 4.025369193527695e-08f, 0.000910152739379555f, 2.0162281089142198e-07f, 0.0006630197167396545f, 0.0008210157975554466f, 0.0007409585523419082f, 2.3546854208689183e-05f, 0.0009050220251083374f, 0.0010428447276353836f, 0.0004212672065477818f, 0.0010951150907203555f, 0.0005385354161262512f, 0.0008156073745340109f, 0.008449053391814232f, 0.001144155627116561f, 0.0004625821311492473f, 0.0006053689867258072f, 0.0008132508955895901f, 0.0007514901226386428f, 0.0004843595379497856f, 0.0010530439903959632f, 0.0006902189925312996f, 0.0009524189517833292f, 8.510693874086428e-07f, 0.0006558257737196982f, 0.0010248172329738736f, 0.0002932466159109026f, 0.0012597647728398442f, 0.00046942124026827514f, 0.001416373299434781f, 0.0011401382507756352f, 0.00031228543957695365f, 0.0008310865378007293f, 0.0009415760869160295f, 0.0006399208214133978f, 0.0007486490067094564f, 0.001056884415447712f, 0.001518219942227006f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #71 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_22_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0022125490941107273f, 0.0018343795090913773f, 0.0019362661987543106f, 0.0020034105982631445f, 0.0016053294530138373f, 0.0016878212336450815f, 0.0017993903020396829f, 0.0017138617113232613f, 0.0017811337020248175f, 0.0017971948254853487f, 0.0018255745526403189f, 0.002040918916463852f, 0.002133256522938609f, 0.0019044113578274846f, 0.0015060491859912872f, 0.0015636809403076768f, 0.0018533476395532489f, 0.0015642333310097456f, 0.0016539983917027712f, 0.0019059496698901057f, 0.0015776567161083221f, 0.0014989483170211315f, 0.0021118023432791233f, 0.0016710878117009997f, 0.0018655897583812475f, 0.002070855349302292f, 0.002322740387171507f, 0.002184850163757801f, 0.0029756997246295214f, 0.001960895722731948f, 0.001630214392207563f, 0.0015139805618673563f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #72 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_22_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00037888868246227503f, 0.0003141289053019136f, 0.00033157653524540365f, 0.00034307470195926726f, 0.0002749051491264254f, 0.0002890314790420234f, 0.000308137183310464f, 0.0002934907970484346f, 0.00030501082073897123f, 0.00030776122002862394f, 0.00031262109405361116f, 0.000349497830029577f, 0.00036531020305119455f, 0.00032612154609523714f, 0.0002579038846306503f, 0.0002677730517461896f, 0.00031737712561152875f, 0.000267867639195174f, 0.0002832394966389984f, 0.00032638496486470103f, 0.0002701663179323077f, 0.0002566878974903375f, 0.00036163628101348877f, 0.00028616597410291433f, 0.0003194735327269882f, 0.0003546242951415479f, 0.00039775841287337244f, 0.000374145369278267f, 0.0005095746601000428f, 0.00033579423325136304f, 0.00027916659018956125f, 0.00025926210219040513f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #73 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_23_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.019264934584498405f, 0.017550505697727203f, 0.016149532049894333f, 0.01593954861164093f, 0.015653008595108986f, 0.015345180407166481f, 0.015291674062609673f, 0.01503022201359272f, 0.014562907628715038f, 0.014369828626513481f, 0.0142125329002738f, 0.013611573725938797f, 0.013442582450807095f, 0.013196244835853577f, 0.013098765164613724f, 0.012818075716495514f, 0.01274142600595951f, 0.012347870506346226f, 0.012234184890985489f, 0.012013769708573818f, 0.011788262985646725f, 0.011415531858801842f, 0.011319388635456562f, 0.011193756945431232f, 0.010739163495600224f, 0.010285438038408756f, 0.010161921381950378f, 0.010062630288302898f, 0.009890073910355568f, 0.009616474620997906f, 0.009386781603097916f, 0.00922743696719408f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #74 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_23_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00037888868246227503f, 0.0003141289053019136f, 0.00033157653524540365f, 0.00034307470195926726f, 0.0002749051491264254f, 0.0002890314790420234f, 0.000308137183310464f, 0.0002934907970484346f, 0.00030501082073897123f, 0.00030776122002862394f, 0.00031262109405361116f, 0.000349497830029577f, 0.00036531020305119455f, 0.00032612154609523714f, 0.0002579038846306503f, 0.0002677730517461896f, 0.00031737712561152875f, 0.000267867639195174f, 0.0002832394966389984f, 0.00032638496486470103f, 0.0002701663179323077f, 0.0002566878974903375f, 0.00036163628101348877f, 0.00028616597410291433f, 0.0003194735327269882f, 0.0003546242951415479f, 0.00039775841287337244f, 0.000374145369278267f, 0.0005095746601000428f, 0.00033579423325136304f, 0.00027916659018956125f, 0.00025926210219040513f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #75 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_24_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 160,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0012929344084113836f, 0.001269593951292336f, 0.0009728735312819481f, 0.0013306494802236557f, 0.0007692572544328868f, 0.001167609472759068f, 1.2561433493374352e-07f, 0.0011456276988610625f, 0.0012090455275028944f, 0.001374475541524589f, 0.0009663568926043808f, 0.001367206801660359f, 0.0010042140493169427f, 0.000963683589361608f, 8.160122751121879e-12f, 9.301474165113177e-06f, 4.183415391878498e-09f, 0.001080789603292942f, 1.1782487485678672e-10f, 2.796707136709653e-11f, 0.000772159721236676f, 0.0018002612050622702f, 0.001191226881928742f, 1.2441777244021068e-06f, 0.0015874927630648017f, 0.002026056172326207f, 0.0011264170752838254f, 0.0007512504234910011f, 0.0013525463873520494f, 0.0013268408365547657f, 5.4760093917138875e-06f, 0.000824740796815604f, 0.001307235681451857f, 0.0010526718106120825f, 0.0011932103661820292f, 0.0010500968201085925f, 0.0012230046559125185f, 1.0751591977831154e-10f, 0.0015055183321237564f, 5.149018420524953e-07f, 8.901760622029298e-13f, 0.0011617470299825072f, 0.0012650133576244116f, 0.0014740383485332131f, 0.001080655143596232f, 4.11967196467522e-11f, 0.0015084458282217383f, 0.0011873998446390033f, 0.00119058508425951f, 0.0015991884283721447f, 0.0010033970465883613f, 0.001273110625334084f, 3.5056609704042785e-07f, 0.001472080359235406f, 0.0010620401008054614f, 1.1342580520656842e-12f, 0.0011209016665816307f, 0.0016628808807581663f, 0.0010323396418243647f, 0.0014383839443325996f, 0.0013170248130336404f, 0.0012225903337821364f, 0.001088240765966475f, 1.863825933867691e-11f, 1.35701685999301e-10f, 7.60644103259267e-10f, 0.0015043985331431031f, 2.6599319968845236e-10f, 0.0017951105255633593f, 0.0016558612696826458f, 4.7522766521979065e-07f, 0.0014509533066302538f, 0.0015752726467326283f, 0.0014699635794386268f, 5.281488029140746e-06f, 0.0014746783999726176f, 1.9439983844904418e-08f, 2.3076880850680936e-08f, 0.0010718718403950334f, 0.0020163285080343485f, 0.0011826464906334877f, 0.0010473862057551742f, 0.0012570730177685618f, 0.000818927597720176f, 0.0012437434634193778f, 5.223623755767903e-09f, 1.8257902922869107e-07f, 2.2115829168001255e-09f, 0.0010098350467160344f, 0.0012062923051416874f, 0.0010068921837955713f, 0.0016451663104817271f, 0.0009325100108981133f, 0.0010301026050001383f, 0.001006432925350964f, 0.0008879460510797799f, 7.896527876027903e-10f, 0.0015740683302283287f, 0.0009330774191766977f, 0.0010658872779458761f, 0.0018024276942014694f, 4.7705007091281004e-06f, 2.594553227591636e-14f, 0.0016485733212903142f, 0.0010145953856408596f, 0.0006676570628769696f, 5.546662009692227e-07f, 0.0021708449348807335f, 0.0017966247396543622f, 1.990057626244379e-06f, 0.0015148125821724534f, 1.857321518805577e-09f, 0.0011640231823548675f, 0.0012094241101294756f, 0.0010227665770798922f, 0.0012368191964924335f, 2.798825278205186e-07f, 0.0015206336975097656f, 1.0658933206286747e-05f, 0.0008893219637684524f, 0.0009285823325626552f, 0.001050155726261437f, 0.0014777310425415635f, 4.9970264037746404e-11f, 1.3945936419568206e-11f, 0.0016445126384496689f, 0.0010435227304697037f, 0.0008949357434175909f, 0.0011483883718028665f, 0.0010123706888407469f, 0.001940230024047196f, 0.0015907626366242766f, 0.0015917450655251741f, 0.000973852351307869f, 0.0012850880157202482f, 0.0010604830458760262f, 0.000887727364897728f, 0.0010788043728098273f, 0.002074108924716711f, 0.0008830305887386203f, 0.0014147870242595673f, 0.0009502592729404569f, 0.0014300936600193381f, 2.582750994406524e-06f, 0.0013645053841173649f, 0.001965581439435482f, 1.884642025773431e-10f, 0.0014605774777010083f, 2.1911617409386963e-07f, 0.0017808222910389304f, 0.0009528655791655183f, 0.0009471217636018991f, 0.0017051668837666512f, 0.0009137138840742409f, 7.701271564908296e-11f, 0.001614099950529635f, 0.0008801311487331986f, 2.7066907336325066e-14f, 2.3519785941061855e-07f, 0.0008937789243645966f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #76 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_24_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 160,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00037844968028366566f, 0.0003716177889145911f, 0.00028476593433879316f, 0.00038948911242187023f, 0.00022516622266266495f, 0.00034176631015725434f, 3.6768071254300594e-08f, 0.000335332122631371f, 0.00035389489494264126f, 0.00040231726597994566f, 0.00028285846929065883f, 0.0004001896595582366f, 0.0002939394908025861f, 0.0002820759837049991f, 2.388516901624671e-12f, 2.7225974008615594e-06f, 1.2245108260700022e-09f, 0.00031635360210202634f, 3.448804783423576e-11f, 8.186129725473723e-12f, 0.00022601579257752746f, 0.0005269472603686154f, 0.0003486792847979814f, 3.6417830528989725e-07f, 0.0004646686720661819f, 0.0005930387997068465f, 0.00032970905886031687f, 0.00021989551896695048f, 0.00039589847438037395f, 0.00038837429019622505f, 1.6028608342821826e-06f, 0.0002414065966149792f, 0.0003826357424259186f, 0.0003081233589909971f, 0.0003492598480079323f, 0.00030736965709365904f, 0.00035798081080429256f, 3.1470555328372285e-11f, 0.0004406742809806019f, 1.5071486814122181e-07f, 2.605598842155693e-13f, 0.0003400503483135253f, 0.0003702770045492798f, 0.0004314598918426782f, 0.00031631425372324884f, 1.2058527787406348e-11f, 0.00044153115595690906f, 0.0003475590783637017f, 0.00034849141957238317f, 0.0004680920683313161f, 0.0002937003446277231f, 0.00037264713319018483f, 1.0261280181111943e-07f, 0.0004308867792133242f, 0.0003108655218966305f, 3.3200414531302236e-13f, 0.00032809466938488185f, 0.00048673522542230785f, 0.00030217203311622143f, 0.0004210236365906894f, 0.0003855010727420449f, 0.00035785953514277935f, 0.0003185346140526235f, 5.455530558556854e-12f, 3.9720698952194766e-11f, 2.2264509680347544e-10f, 0.0004403464845381677f, 7.785781047653373e-11f, 0.0005254396237432957f, 0.00048468055319972336f, 1.391019992524889e-07f, 0.00042470276821404696f, 0.00046109178219921887f, 0.0004302671877667308f, 1.5459232827197411e-06f, 0.0004316472331993282f, 5.6902003109371435e-09f, 6.7547416549018635e-09f, 0.0003137433377560228f, 0.0005901914555579424f, 0.0003461677406448871f, 0.00030657622846774757f, 0.00036795283085666597f, 0.00023970502661541104f, 0.0003640512004494667f, 1.528986048882075e-09f, 5.344197973045084e-08f, 6.473436231502205e-10f, 0.00029558478854596615f, 0.0003530890098772943f, 0.0002947234024759382f, 0.0004815500578843057f, 0.000272951292572543f, 0.0003015172260347754f, 0.00029458897188305855f, 0.0002599071594886482f, 2.3113612412917206e-10f, 0.0004607392766047269f, 0.00027311735902912915f, 0.00031199160730466247f, 0.0005275814328342676f, 1.3963542642159155e-06f, 7.594413548820279e-15f, 0.00048254732973873615f, 0.00029697816353291273f, 0.0001954272302100435f, 1.6235412658716086e-07f, 0.0006354193901643157f, 0.0005258828750811517f, 5.825018547511718e-07f, 0.0004433947615325451f, 5.436491812282895e-10f, 0.00034071659320034087f, 0.0003540057223290205f, 0.0002993699163198471f, 0.00036202440969645977f, 8.192329659095776e-08f, 0.0004450986161828041f, 3.1199338081933092e-06f, 0.00026030989829450846f, 0.00027180163306184113f, 0.00030738688656128943f, 0.00043254074989818037f, 1.462659680873113e-11f, 4.082059343324396e-12f, 0.00048135872930288315f, 0.0003054453700315207f, 0.0002619530714582652f, 0.00033614019048400223f, 0.00029632699443027377f, 0.000567917013540864f, 0.00046562578063458204f, 0.00046591335558332503f, 0.00028505243244580925f, 0.000376152980607003f, 0.0003104097559116781f, 0.00025984313106164336f, 0.0003157725150231272f, 0.0006071041570976377f, 0.00025846835342235863f, 0.00041411665733903646f, 0.00027814661734737456f, 0.0004185970174148679f, 7.559867185591429e-07f, 0.0003993989375885576f, 0.0005753375007770956f, 5.516460552246194e-11f, 0.0004275198152754456f, 6.413662134718834e-08f, 0.000521257403306663f, 0.00027890948695130646f, 0.0002772282459773123f, 0.0004991125897504389f, 0.00026744953356683254f, 2.254208451846207e-11f, 0.00047245676978491247f, 0.0002576196857262403f, 7.922646439177845e-15f, 6.884382486305185e-08f, 0.00026161447749473155f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #77 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_26_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 160,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007088111713528633f, 0.005142001435160637f, 0.007793435361236334f, 0.006966568995267153f, 0.006794738117605448f, 0.019889062270522118f, 1.0608371212583734e-06f, 0.005760698113590479f, 0.005837416276335716f, 0.006164463236927986f, 0.007525136694312096f, 0.01274657342582941f, 0.008879469707608223f, 0.005488838069140911f, 1.3699034961955903e-10f, 0.00013365874474402517f, 3.093888686911406e-11f, 0.006925933063030243f, 1.2390191095335013e-09f, 1.5051069279792273e-09f, 0.011647511273622513f, 0.008487686514854431f, 0.006844023708254099f, 0.00027089318609796464f, 0.013303570449352264f, 0.007837538607418537f, 0.009711931459605694f, 0.012422027066349983f, 0.004328403156250715f, 0.009094765409827232f, 8.582979353377596e-05f, 0.011369354091584682f, 0.013762681744992733f, 0.006562436930835247f, 0.015901103615760803f, 0.008130956441164017f, 0.009715825319290161f, 8.586211186489834e-10f, 0.012140319682657719f, 1.01768519016332e-05f, 8.563144117401666e-12f, 0.008331820368766785f, 0.009821276180446148f, 0.010092278011143208f, 0.01215149275958538f, 4.841382850173659e-10f, 0.006139799952507019f, 0.009721470065414906f, 0.006531432271003723f, 0.014300115406513214f, 0.005651966203004122f, 0.006695417687296867f, 2.1019695850554854e-06f, 0.011198457330465317f, 0.012866957113146782f, 2.4580623994574502e-11f, 0.0067508225329220295f, 0.008262000977993011f, 0.006006110459566116f, 0.011443208903074265f, 0.009443110786378384f, 0.006755550857633352f, 0.005674549378454685f, 2.8337361211890066e-13f, 3.5172478818346065e-10f, 2.3671981708162093e-08f, 0.005101856309920549f, 2.8489961501065864e-09f, 0.010579679161310196f, 0.008872867561876774f, 4.5115430111764e-06f, 0.007305979263037443f, 0.005561475176364183f, 0.008162901736795902f, 0.00010067994298879057f, 0.006892568897455931f, 3.813717057710164e-07f, 1.237107909446422e-07f, 0.01007505040615797f, 0.007699969224631786f, 0.01260332204401493f, 0.010991698130965233f, 0.010486282408237457f, 0.009061023592948914f, 0.005623030476272106f, 8.926623706884129e-08f, 7.249910595419351e-06f, 1.1905363805908564e-08f, 0.010137984529137611f, 0.01058023888617754f, 0.015370949171483517f, 0.005522184073925018f, 0.010891154408454895f, 0.016276439651846886f, 0.010403070598840714f, 0.013073761947453022f, 8.481603863685905e-09f, 0.008202794007956982f, 0.009614294394850731f, 0.006556241307407618f, 0.012222028337419033f, 0.0008864635601639748f, 7.022610357815262e-12f, 0.007034679874777794f, 0.009225532412528992f, 0.008423754014074802f, 4.477908532862784e-06f, 0.008441464975476265f, 0.008799015544354916f, 7.5195866884314455e-06f, 0.011575189419090748f, 2.175411317750786e-08f, 0.012116747908294201f, 0.009891162626445293f, 0.013161464594304562f, 0.007376836147159338f, 3.4265887904894043e-08f, 0.007918077521026134f, 0.08907581120729446f, 0.009722979739308357f, 0.007630871143192053f, 0.009516285732388496f, 0.009982749819755554f, 3.52109874590667e-09f, 6.009146652496966e-11f, 0.010356531478464603f, 0.01074270810931921f, 0.008914617821574211f, 0.005051374901086092f, 0.010801330208778381f, 0.004179871641099453f, 0.00945175439119339f, 0.0075131612829864025f, 0.009214375168085098f, 0.010155151598155499f, 0.014653014950454235f, 0.010824449360370636f, 0.013134482316672802f, 0.006712545175105333f, 0.004627337213605642f, 0.00759514607489109f, 0.011376209557056427f, 0.008047929033637047f, 6.920447776792571e-05f, 0.007164011709392071f, 0.0070329089649021626f, 1.653963632719524e-09f, 0.009721462614834309f, 1.0534087095948053e-06f, 0.010185498744249344f, 0.005815030075609684f, 0.016648385673761368f, 0.009256572462618351f, 0.014292401261627674f, 5.411690540135794e-10f, 0.005742974579334259f, 0.0045510525815188885f, 2.4860450503760845e-11f, 1.3472185855789576e-06f, 0.01238834299147129f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #78 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_26_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 160,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0006182274664752185f, 0.00044848708785139024f, 0.0006797460373491049f, 0.0006076264544390142f, 0.0005926393205299973f, 0.001734730671159923f, 9.252656951730387e-08f, 0.0005024499841965735f, 0.0005091414204798639f, 0.0005376665503717959f, 0.0006563449278473854f, 0.0011117603862658143f, 0.000774470332544297f, 0.00047873827861621976f, 1.1948344223744467e-11f, 1.1657760296657216e-05f, 2.698500060557829e-12f, 0.0006040821899659932f, 1.0806765898818682e-10f, 1.312759345672987e-10f, 0.0010158998193219304f, 0.000740298826713115f, 0.0005969380144961178f, 2.3627393602509983e-05f, 0.0011603418970480561f, 0.0006835927488282323f, 0.0008470779284834862f, 0.0010834533022716641f, 0.00037752476055175066f, 0.000793248473200947f, 7.486103186238324e-06f, 0.0009916388662531972f, 0.0012003857409581542f, 0.0005723779322579503f, 0.0013868996175006032f, 0.0007091847364790738f, 0.0008474175119772553f, 7.488921982545804e-11f, 0.0010588826844468713f, 8.876284027792281e-07f, 7.468802594619295e-13f, 0.0007267041364684701f, 0.0008566149626858532f, 0.0008802518714219332f, 0.0010598571971058846f, 4.2226701302272573e-11f, 0.0005355154280550778f, 0.0008479098323732615f, 0.0005696737207472324f, 0.0012472608359530568f, 0.000492966384626925f, 0.0005839765653945506f, 1.8333449247620592e-07f, 0.0009767331648617983f, 0.001122260233387351f, 2.1439302156506246e-12f, 0.0005888089654035866f, 0.000720614509191364f, 0.0005238549783825874f, 0.000998080475255847f, 0.0008236313005909324f, 0.0005892214248888195f, 0.0004949360736645758f, 2.4715940286166443e-14f, 3.0677554246905103e-11f, 2.064678206181725e-09f, 0.0004449856060091406f, 2.484903949273587e-10f, 0.0009227631380781531f, 0.00077389448415488f, 3.934982828468492e-07f, 0.0006372299394570291f, 0.0004850737168453634f, 0.0007119710207916796f, 8.781337783148047e-06f, 0.0006011721561662853f, 3.32633689481554e-08f, 1.079009681603793e-08f, 0.000878749240655452f, 0.000671593879815191f, 0.0010992659954354167f, 0.0009586995583958924f, 0.0009146170341409743f, 0.0007903054938651621f, 0.0004904426168650389f, 7.785830646866998e-09f, 6.323396064544795e-07f, 1.0383898185750695e-09f, 0.0008842383977025747f, 0.0009228119743056595f, 0.0013406593352556229f, 0.000481646740809083f, 0.0009499301086179912f, 0.0014196365373209119f, 0.0009073592955246568f, 0.00114029785618186f, 7.39768302171484e-10f, 0.000715450441930443f, 0.0008385619730688632f, 0.0005718375323340297f, 0.0010660093976184726f, 7.731765072094277e-05f, 6.125144337044974e-13f, 0.0006135671283118427f, 0.0008046540315262973f, 0.0007347226492129266f, 3.9056467926457117e-07f, 0.0007362673641182482f, 0.000767453049775213f, 6.558608447448933e-07f, 0.001009591855108738f, 1.8974009030614525e-09f, 0.0010568267898634076f, 0.0008627105271443725f, 0.0011479472741484642f, 0.0006434101378545165f, 2.9886821906188743e-09f, 0.0006906173657625914f, 0.007769221905618906f, 0.0008480415563099086f, 0.0006655671168118715f, 0.0008300135959871113f, 0.000870698771905154f, 3.0711141962846966e-10f, 5.241197666844277e-12f, 0.0009033001260831952f, 0.0009369825711473823f, 0.0007775359554216266f, 0.0004405826039146632f, 0.0009420956484973431f, 0.00036456980160437524f, 0.0008243851480074227f, 0.0006553004495799541f, 0.0008036808576434851f, 0.0008857357315719128f, 0.0012780408142134547f, 0.0009441120782867074f, 0.0011455939384177327f, 0.0005854704068042338f, 0.00040359789272770286f, 0.0006624512025155127f, 0.0009922367753461003f, 0.0007019430631771684f, 6.036037575540831e-06f, 0.0006248474819585681f, 0.0006134126451797783f, 1.4425925731753608e-10f, 0.0008479091920889914f, 9.187866112370102e-08f, 0.0008883826085366309f, 0.0005071888444945216f, 0.0014520777622237802f, 0.0008073613280430436f, 0.0012465879553928971f, 4.7200944541803125e-11f, 0.0005009041633456945f, 0.0003969443205278367f, 2.1683366907554458e-12f, 1.1750485384709464e-07f, 0.0010805154452100396f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #79 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_27_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00230594864115119f, 0.0020916324574500322f, 0.0021927698981016874f, 0.0019584146793931723f, 0.0022948244586586952f, 0.002264994429424405f, 0.0019991733133792877f, 0.002143977442756295f, 0.001989658921957016f, 0.0018026122124865651f, 0.002314263489097357f, 0.0018043196760118008f, 0.0019188845762982965f, 0.0020434027537703514f, 0.002136962953954935f, 0.0017376153264194727f, 0.0025842206086963415f, 0.002280439715832472f, 0.0020794603042304516f, 0.0018351561157032847f, 0.0027520337607711554f, 0.0020180519204586744f, 0.003075491636991501f, 0.0018577544251456857f, 0.001923288102261722f, 0.0026857645716518164f, 0.0018587352242320776f, 0.002674153773114085f, 0.002092645037919283f, 0.0021275002509355545f, 0.0019240293186157942f, 0.001923352712765336f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #80 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_27_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00037888868246227503f, 0.0003141289053019136f, 0.00033157653524540365f, 0.00034307470195926726f, 0.0002749051491264254f, 0.0002890314790420234f, 0.000308137183310464f, 0.0002934907970484346f, 0.00030501082073897123f, 0.00030776122002862394f, 0.00031262109405361116f, 0.000349497830029577f, 0.00036531020305119455f, 0.00032612154609523714f, 0.0002579038846306503f, 0.0002677730517461896f, 0.00031737712561152875f, 0.000267867639195174f, 0.0002832394966389984f, 0.00032638496486470103f, 0.0002701663179323077f, 0.0002566878974903375f, 0.00036163628101348877f, 0.00028616597410291433f, 0.0003194735327269882f, 0.0003546242951415479f, 0.00039775841287337244f, 0.000374145369278267f, 0.0005095746601000428f, 0.00033579423325136304f, 0.00027916659018956125f, 0.00025926210219040513f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #81 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_28_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.015074489638209343f, 0.014168942347168922f, 0.014098173007369041f, 0.013575080782175064f, 0.01341572031378746f, 0.013246902264654636f, 0.01297337468713522f, 0.012965086847543716f, 0.012636742554605007f, 0.012521175667643547f, 0.012351565062999725f, 0.012076704762876034f, 0.011829476803541183f, 0.011813380755484104f, 0.011577977798879147f, 0.011368513107299805f, 0.011057732626795769f, 0.01078721135854721f, 0.010551141574978828f, 0.01040002703666687f, 0.010173897258937359f, 0.010068981908261776f, 0.009941672906279564f, 0.009806880727410316f, 0.009328310377895832f, 0.009061871096491814f, 0.008935336023569107f, 0.00856107845902443f, 0.00826324988156557f, 0.007945284247398376f, 0.00786316953599453f, 0.007559078745543957f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #82 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_28_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00037888868246227503f, 0.0003141289053019136f, 0.00033157653524540365f, 0.00034307470195926726f, 0.0002749051491264254f, 0.0002890314790420234f, 0.000308137183310464f, 0.0002934907970484346f, 0.00030501082073897123f, 0.00030776122002862394f, 0.00031262109405361116f, 0.000349497830029577f, 0.00036531020305119455f, 0.00032612154609523714f, 0.0002579038846306503f, 0.0002677730517461896f, 0.00031737712561152875f, 0.000267867639195174f, 0.0002832394966389984f, 0.00032638496486470103f, 0.0002701663179323077f, 0.0002566878974903375f, 0.00036163628101348877f, 0.00028616597410291433f, 0.0003194735327269882f, 0.0003546242951415479f, 0.00039775841287337244f, 0.000374145369278267f, 0.0005095746601000428f, 0.00033579423325136304f, 0.00027916659018956125f, 0.00025926210219040513f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #83 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_29_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 160,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(2.5004865165101364e-06f, 0.0010616499930620193f, 0.0010796170681715012f, 0.001489684684202075f, 0.0014468446606770158f, 1.362048603244237e-12f, 0.001326573546975851f, 0.001098282285965979f, 4.46258741765293e-12f, 0.0014341215137392282f, 4.703403638783854e-11f, 6.432375130316359e-07f, 0.0022979199420660734f, 0.001133797923102975f, 0.0018292980967089534f, 0.0008017902728170156f, 1.5294936428489336e-09f, 0.001632285420782864f, 3.066658109673881e-07f, 1.3265238907322896e-10f, 7.822410275082348e-09f, 0.001028270460665226f, 0.0009374350192956626f, 2.5660856408649124e-05f, 4.1377123081998146e-13f, 0.0019187465077266097f, 0.0012927809730172157f, 6.044489782652818e-05f, 0.0013771983794867992f, 0.0016309835482388735f, 3.733375933734351e-06f, 0.0011264934437349439f, 0.0015496358973905444f, 2.076339447598663e-11f, 0.0013996571069583297f, 0.0013068930711597204f, 1.635505775254842e-08f, 0.0013783610193058848f, 0.0008922446868382394f, 0.0012071591336280107f, 0.0015893281670287251f, 0.001214370597153902f, 3.1995194688105855e-11f, 0.001189108588732779f, 1.916493873321823e-12f, 9.193803271045908e-05f, 2.14034692747056e-11f, 0.0011328385444357991f, 7.27738079149276e-05f, 0.0016423596534878016f, 3.78947370336391e-05f, 0.001441011787392199f, 2.012868387593625e-12f, 0.0013624471612274647f, 5.245166789791256e-08f, 0.0009538230369798839f, 0.0014616360422223806f, 0.0013655548682436347f, 2.2434031166085333e-07f, 0.001239739009179175f, 0.001189925940707326f, 1.2063457871525074e-12f, 0.0013907243264839053f, 0.0020202479790896177f, 0.001015861751511693f, 0.001706092618405819f, 0.0013391278916969895f, 0.001576669281348586f, 0.0016499093035236f, 0.0009020491852425039f, 0.0015145705547183752f, 0.0013924280647188425f, 0.0009398029651492834f, 0.0010713490191847086f, 2.47773719944111e-12f, 0.0013022648636251688f, 0.0019622279796749353f, 0.0014553687069565058f, 0.00131670490372926f, 0.001261395402252674f, 0.0016582752577960491f, 0.0010434702271595597f, 4.887632167083211e-05f, 0.0008804287645034492f, 0.0017763995565474033f, 1.9477641721721284e-10f, 1.791599334166616e-11f, 0.0013873580610379577f, 0.0015741412062197924f, 0.001024482655338943f, 0.001500252983532846f, 0.0016091055003926158f, 0.001618478330783546f, 0.00162718805950135f, 0.00165953126270324f, 0.0013640340184792876f, 0.001264715101569891f, 0.00111412035766989f, 0.001307756989262998f, 0.001196265104226768f, 4.888572879835351e-11f, 0.0018464199965819716f, 2.7275933248138706e-12f, 0.0013463437790051103f, 3.652310051616148e-11f, 0.001410286407917738f, 0.0014639608561992645f, 0.0010935529135167599f, 1.0890266821661498e-07f, 5.964458250673488e-05f, 0.001293415785767138f, 0.0006964963977225125f, 0.0014247398357838392f, 0.0010590782621875405f, 0.0016258647665381432f, 0.0015530569944530725f, 0.001115722581744194f, 0.0014022891409695148f, 2.717868291535197e-11f, 4.38007750458002e-14f, 0.0014359154738485813f, 0.0016438603634014726f, 0.0013073100708425045f, 0.0018157559679821134f, 7.120620204581485e-10f, 0.0012565362267196178f, 0.00209194328635931f, 1.186351472788616e-12f, 3.814711404832166e-13f, 0.0012212746078148484f, 2.285790105815977e-05f, 0.0008124747546389699f, 0.001549075823277235f, 0.001567586325109005f, 0.0010843949858099222f, 0.001280861790291965f, 4.386178087401049e-09f, 0.0012945861089974642f, 1.6769630747148767e-05f, 0.0003916177374776453f, 6.626712689694614e-08f, 0.0016937191830947995f, 0.0014570303028449416f, 0.001118084997870028f, 0.0015341438120231032f, 0.000986207858659327f, 2.628094080137089e-05f, 3.117253330464642e-11f, 0.0013055856106802821f, 3.720985205291072e-06f, 0.0015100223245099187f, 0.001984410220757127f, 0.0010474720038473606f, 0.00134207122027874f, 0.0015306629939004779f, 0.001114983344450593f, 0.0012446226319298148f, 0.0013831875985488296f, 1.1279122524854301e-08f, 0.0011958280811086297f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #84 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_29_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 160,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(4.0808490098243055e-07f, 0.00017326361557934433f, 0.00017619587015360594f, 0.00024311980814673007f, 0.00023612822405993938f, 2.2228932290788844e-13f, 0.00021649971313308924f, 0.00017924208077602088f, 7.283040815396491e-13f, 0.00023405178217217326f, 7.676057706129669e-12f, 1.0497777225282334e-07f, 0.0003750255855266005f, 0.0001850383123382926f, 0.00029854546301066875f, 0.0001308539358433336f, 2.496167161858409e-10f, 0.00026639256975613534f, 5.0048534205870965e-08f, 2.1649161630055147e-11f, 1.2766345758308262e-09f, 0.0001678160042501986f, 0.0001529914588900283f, 4.18790796175017e-06f, 6.75283735721878e-14f, 0.0003131436533294618f, 0.00021098469733260572f, 9.864739695331082e-06f, 0.00022476179583463818f, 0.0002661801117938012f, 6.092951707614702e-07f, 0.00018384620489086956f, 0.0002529039920773357f, 3.388631606218717e-12f, 0.000228427117690444f, 0.0002132878144038841f, 2.669181320413827e-09f, 0.00022495155280921608f, 0.00014561628631781787f, 0.00019701101700775325f, 0.00025938183534890413f, 0.0001981879468075931f, 5.221685930867359e-12f, 0.00019406512728892267f, 3.127760095193721e-13f, 1.5004488886916079e-05f, 3.4930931844950885e-12f, 0.00018488173373043537f, 1.187684483738849e-05f, 0.00026803670334629714f, 6.184504400152946e-06f, 0.0002351762814214453f, 3.2850453043561934e-13f, 0.00022235437063500285f, 8.5602271937546e-09f, 0.00015566601359751076f, 0.0002385422121733427f, 0.00022286154853645712f, 3.661283187739173e-08f, 0.000202328126761131f, 0.0001941985246958211f, 1.968782802801508e-13f, 0.00022696926316712052f, 0.0003297089133411646f, 0.0001657908724155277f, 0.0002784380631055683f, 0.00021854860824532807f, 0.0002573158999439329f, 0.00026926881400868297f, 0.00014721641491632909f, 0.00024718124768696725f, 0.00022724732116330415f, 0.00015337791410274804f, 0.00017484651471022516f, 4.0437214666143306e-13f, 0.0002125324826920405f, 0.00032023992389440536f, 0.00023751937260385603f, 0.00021488913625944406f, 0.00020586249593179673f, 0.0002706341620068997f, 0.00017029664013534784f, 7.976723281899467e-06f, 0.00014368791016750038f, 0.00028991230647079647f, 3.1787940335537e-11f, 2.92392954466536e-12f, 0.00022641988471150398f, 0.0002569032949395478f, 0.00016719782433938235f, 0.0002448445884510875f, 0.00026260953745804727f, 0.00026413920568302274f, 0.00026556066586636007f, 0.0002708391402848065f, 0.0002226133510703221f, 0.00020640427828766406f, 0.00018182689382229f, 0.00021342880791053176f, 0.00019523309310898185f, 7.97825867870916e-12f, 0.00030133980908431113f, 4.451492343141017e-13f, 0.00021972626564092934f, 5.960650376057863e-12f, 0.00023016183695290238f, 0.00023892162425909191f, 0.00017847023264039308f, 1.7773155391864748e-08f, 9.734127161209472e-06f, 0.00021108829241711646f, 0.0001136697392212227f, 0.0002325206733075902f, 0.00017284389468841255f, 0.00026534468634054065f, 0.0002534623199608177f, 0.00018208837718702853f, 0.00022885666112415493f, 4.435620707538002e-12f, 7.148382939455109e-15f, 0.00023434455215465277f, 0.00026828161207959056f, 0.00021335587371140718f, 0.0002963353763334453f, 1.1621008322304505e-10f, 0.00020506947475951165f, 0.00034140973002649844f, 1.9361517055414834e-13f, 6.225692839945465e-14f, 0.00019931470160372555f, 3.730459638973116e-06f, 0.00013259766274131835f, 0.0002528125769458711f, 0.0002558335254434496f, 0.0001769756490830332f, 0.00020903945551253855f, 7.1583389216201e-10f, 0.000211279300856404f, 2.7368405426386744e-06f, 6.39128775219433e-05f, 1.0814940942793783e-08f, 0.0002764186938293278f, 0.00023779054754413664f, 0.0001824739301810041f, 0.00025037562591023743f, 0.00016095128376036882f, 4.289107437216444e-06f, 5.087425706401527e-12f, 0.00021307443967089057f, 6.07272966135497e-07f, 0.00024643895449116826f, 0.000323860120261088f, 0.00017094973009079695f, 0.00021902896696701646f, 0.00024980754824355245f, 0.00018196772725787014f, 0.00020312514971010387f, 0.00022573924798052758f, 1.8407775304041252e-09f, 0.00019516177417244762f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #85 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_31_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 160,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(5.7735313021112233e-05f, 0.008539686910808086f, 0.0071993302553892136f, 0.006972011178731918f, 0.012259896844625473f, 1.0295824089123773e-11f, 0.007198867853730917f, 0.008367246016860008f, 3.05819189416745e-11f, 0.007030677981674671f, 3.7468157465525564e-09f, 2.905869678215822e-06f, 0.0067133307456970215f, 0.014806672930717468f, 0.009326868690550327f, 0.008259285241365433f, 1.3025041489811429e-08f, 0.010273797437548637f, 2.3580569177283905e-06f, 3.9607236934635637e-10f, 7.899614473672045e-08f, 0.0148036889731884f, 0.008138655684888363f, 0.0007224026485346258f, 1.627484084998354e-11f, 0.007518594618886709f, 0.011883247643709183f, 0.10068659484386444f, 0.004471344407647848f, 0.007767760660499334f, 0.0033529605716466904f, 0.00623940397053957f, 0.006918568629771471f, 8.0693347837002e-11f, 0.010406714864075184f, 0.01204248983412981f, 7.567262372276673e-08f, 0.011960295960307121f, 0.006587434094399214f, 0.008739745244383812f, 0.010282129980623722f, 0.004040990024805069f, 8.111183252834664e-11f, 0.013593819923698902f, 1.745368086170096e-11f, 0.004948276560753584f, 1.71036310114836e-10f, 0.006250032689422369f, 0.009196662344038486f, 0.011409728787839413f, 2.310832769580884e-06f, 0.006067152600735426f, 1.5229907612823723e-11f, 0.005625797901302576f, 6.362360638334508e-10f, 0.007038469426333904f, 0.006923116743564606f, 0.010183706879615784f, 1.8204702882940182e-06f, 0.008677832782268524f, 0.013681991957128048f, 4.3961362328204245e-12f, 0.007998940534889698f, 0.00976653303951025f, 0.008895508013665676f, 0.007774936500936747f, 0.007201018743216991f, 0.004498679656535387f, 0.013680713251233101f, 0.008129523135721684f, 0.008918649516999722f, 0.008825406432151794f, 0.007616756949573755f, 0.008905640803277493f, 1.3199608940583918e-11f, 0.007534664124250412f, 0.005160162691026926f, 0.006936096586287022f, 0.01157110370695591f, 0.008371753618121147f, 0.007371662184596062f, 0.01016467995941639f, 5.1078482101729605e-06f, 0.007627103012055159f, 0.0062719290144741535f, 3.123295844176255e-09f, 5.007796399780773e-10f, 0.006733120884746313f, 0.01122300885617733f, 0.010333782993257046f, 0.003876875853165984f, 0.009183002635836601f, 0.005115174222737551f, 0.008247481659054756f, 0.010893388651311398f, 0.004449165891855955f, 0.007257035002112389f, 0.007963646203279495f, 0.012443775311112404f, 0.005147424526512623f, 4.455644186940333e-10f, 0.005840229336172342f, 4.688200646923643e-14f, 0.00691179046407342f, 5.847032302774835e-10f, 0.009571423754096031f, 0.010601062327623367f, 0.011391385458409786f, 1.4191927633078194e-08f, 0.0012563603231683373f, 0.009126062504947186f, 0.008724506013095379f, 0.008002005517482758f, 0.008645898662507534f, 0.011404008604586124f, 0.01015072874724865f, 0.008523660711944103f, 0.006084355525672436f, 1.890540168858479e-09f, 2.911835919952588e-12f, 0.012828728184103966f, 0.007559684105217457f, 0.00750485947355628f, 0.007124118506908417f, 1.0629155866581641e-07f, 0.017591459676623344f, 0.005388486664742231f, 1.0134075870138481e-11f, 5.147044249143029e-12f, 0.0072888885624706745f, 0.0003077381697949022f, 0.007978715002536774f, 0.014437242411077023f, 0.0055954549461603165f, 0.00764198275282979f, 0.008106604218482971f, 4.480266990736226e-10f, 0.00526499655097723f, 0.027033401653170586f, 3.3569569495739415e-05f, 3.0976278253547207e-07f, 0.008601351641118526f, 0.007114847656339407f, 0.005401251371949911f, 0.010412936098873615f, 0.003489898284897208f, 0.0033087870106101036f, 3.298344930513508e-09f, 0.008188178762793541f, 6.147429667180404e-05f, 0.011192809790372849f, 0.009523080661892891f, 0.006445842795073986f, 0.006919459439814091f, 0.006995702628046274f, 0.008749077096581459f, 0.006144093815237284f, 0.013035951182246208f, 6.304408373125625e-08f, 0.005608253180980682f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #86 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_31_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 160,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(2.8049103093508165e-06f, 0.0004148770240135491f, 0.0003497595025692135f, 0.0003387158503755927f, 0.0005956131499260664f, 5.001940701909735e-13f, 0.00034973706351593137f, 0.00040649945731274784f, 1.4857378565283352e-12f, 0.0003415660175960511f, 1.820286699150131e-10f, 1.411736292311616e-07f, 0.00032614858355373144f, 0.000719341158401221f, 0.00045312006841413677f, 0.0004012544814031571f, 6.32785546184067e-10f, 0.000499123998451978f, 1.1455966131279638e-07f, 1.9242078416747965e-11f, 3.8378087374724146e-09f, 0.0007191962213255465f, 0.00039539404679089785f, 3.5095930797979236e-05f, 7.906680410223188e-13f, 0.00036527009797282517f, 0.0005773146403953433f, 0.004891579505056143f, 0.0002172278764192015f, 0.0003773751377593726f, 0.00016289429913740605f, 0.00030312416492961347f, 0.0003361194976605475f, 3.920262552081777e-12f, 0.0005055814399383962f, 0.0005850510206073523f, 3.6763447841536845e-09f, 0.0005810578586533666f, 0.0003200322389602661f, 0.0004245963064022362f, 0.0004995287745259702f, 0.00019632031035143882f, 3.940593511220225e-12f, 0.0006604180671274662f, 8.479387439593034e-13f, 0.0002403983089607209f, 8.309325449928906e-12f, 0.00030364052508957684f, 0.0004467943508643657f, 0.0005543100414797664f, 1.1226541118958266e-07f, 0.00029475579503923655f, 7.39902876380899e-13f, 0.0002733138098847121f, 3.090976780084631e-11f, 0.0003419445420149714f, 0.000336340453941375f, 0.0004947471898049116f, 8.844250487527461e-08f, 0.00042158845462836325f, 0.0006647016853094101f, 2.1357409926963528e-13f, 0.00038860636414028704f, 0.00047447995166294277f, 0.000432163622463122f, 0.00037772374344058335f, 0.00034984154626727104f, 0.00021855588420294225f, 0.0006646395777352154f, 0.00039495035889558494f, 0.0004332878743298352f, 0.0004287579213269055f, 0.0003700390225276351f, 0.0004326558846514672f, 6.412664453267491e-13f, 0.0003660507791209966f, 0.0002506922173779458f, 0.00033697104663588107f, 0.0005621500313282013f, 0.00040671846363693476f, 0.00035813177237287164f, 0.0004938227939419448f, 2.4815065557959315e-07f, 0.00037054167478345335f, 0.0003047042991966009f, 1.5173667877732555e-10f, 2.432899194604321e-11f, 0.00032711002859286964f, 0.0005452387849800289f, 0.0005020382232032716f, 0.00018834727234207094f, 0.0004461307544261217f, 0.000248506577918306f, 0.0004006810486316681f, 0.0005292251007631421f, 0.0002161503944080323f, 0.0003525629290379584f, 0.0003868916828650981f, 0.0006045463378541172f, 0.0002500733535271138f, 2.164651270730733e-11f, 0.0002837313513737172f, 2.277632419893003e-15f, 0.00033579018781892955f, 2.8406187124740967e-11f, 0.0004650010960176587f, 0.0005150232464075089f, 0.0005534188821911812f, 6.894754767117206e-10f, 6.103678606450558e-05f, 0.00044336446444503963f, 0.00042385596316307783f, 0.0003887552593369037f, 0.0004200370458420366f, 0.0005540321581065655f, 0.0004931450239382684f, 0.00041409843834117055f, 0.00029559156973846257f, 9.184665528128022e-11f, 1.4146348751697263e-13f, 0.0006232482264749706f, 0.0003672663006000221f, 0.0003646028053481132f, 0.0003461055748630315f, 5.163880878455984e-09f, 0.0008546323515474796f, 0.000261784705799073f, 4.923359896852331e-13f, 2.500548867360314e-13f, 0.0003541104670148343f, 1.4950606782804243e-05f, 0.0003876237606164068f, 0.0007013934082351625f, 0.0002718396717682481f, 0.0003712645557243377f, 0.0003938369045499712f, 2.176613576876374e-11f, 0.00025578527129255235f, 0.00131334294565022f, 1.6308845260937233e-06f, 1.5048966517383633e-08f, 0.00041787285590544343f, 0.0003456551639828831f, 0.0002624048211146146f, 0.0005058836541138589f, 0.0001695470418781042f, 0.00016074825543910265f, 1.6024094551259083e-10f, 0.00039779997314326465f, 2.9865584565413883e-06f, 0.0005437716608867049f, 0.00046265250421129167f, 0.0003131534031126648f, 0.00033616277505643666f, 0.00033986681955866516f, 0.0004250496858730912f, 0.0002984937746077776f, 0.0006333155906759202f, 3.0628222180695275e-09f, 0.00027246144600212574f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #87 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_32_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.001829022541642189f, 0.002306467154994607f, 0.0017132805660367012f, 0.0018317472422495484f, 0.0019460349576547742f, 0.0025192073080688715f, 0.0021930616348981857f, 0.0018995865248143673f, 0.0021376728545874357f, 0.0017530578188598156f, 0.002360293176025152f, 0.0024126041680574417f, 0.0020726900547742844f, 0.0022884136997163296f, 0.002362331375479698f, 0.0022308509796857834f, 0.0015956423012539744f, 0.0023641062434762716f, 0.002066137734800577f, 0.0021574252750724554f, 0.0019780222792178392f, 0.00247907149605453f, 0.0023226288612931967f, 0.0022294174414128065f, 0.0021024097222834826f, 0.002796506742015481f, 0.0019835904240608215f, 0.002260644221678376f, 0.0021785255521535873f, 0.002621177351102233f, 0.0019366972846910357f, 0.002235191874206066f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #88 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_32_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00037888868246227503f, 0.0003141289053019136f, 0.00033157653524540365f, 0.00034307470195926726f, 0.0002749051491264254f, 0.0002890314790420234f, 0.000308137183310464f, 0.0002934907970484346f, 0.00030501082073897123f, 0.00030776122002862394f, 0.00031262109405361116f, 0.000349497830029577f, 0.00036531020305119455f, 0.00032612154609523714f, 0.0002579038846306503f, 0.0002677730517461896f, 0.00031737712561152875f, 0.000267867639195174f, 0.0002832394966389984f, 0.00032638496486470103f, 0.0002701663179323077f, 0.0002566878974903375f, 0.00036163628101348877f, 0.00028616597410291433f, 0.0003194735327269882f, 0.0003546242951415479f, 0.00039775841287337244f, 0.000374145369278267f, 0.0005095746601000428f, 0.00033579423325136304f, 0.00027916659018956125f, 0.00025926210219040513f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #89 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_33_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.012918583117425442f, 0.01250532642006874f, 0.011998019181191921f, 0.011932202614843845f, 0.011713847517967224f, 0.011593499220907688f, 0.011513514444231987f, 0.011369982734322548f, 0.01124491635710001f, 0.010961486957967281f, 0.010830250568687916f, 0.010784347541630268f, 0.010511226952075958f, 0.010356881655752659f, 0.010222682729363441f, 0.009958748705685139f, 0.009827702306210995f, 0.009699500165879726f, 0.009663687087595463f, 0.00912807323038578f, 0.009052041918039322f, 0.008793924003839493f, 0.008590779267251492f, 0.008435933850705624f, 0.008165489882230759f, 0.007864103652536869f, 0.007715319283306599f, 0.007188756018877029f, 0.0069889710284769535f, 0.006924556102603674f, 0.006602164823561907f, 0.006336296908557415f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #90 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_33_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00037888868246227503f, 0.0003141289053019136f, 0.00033157653524540365f, 0.00034307470195926726f, 0.0002749051491264254f, 0.0002890314790420234f, 0.000308137183310464f, 0.0002934907970484346f, 0.00030501082073897123f, 0.00030776122002862394f, 0.00031262109405361116f, 0.000349497830029577f, 0.00036531020305119455f, 0.00032612154609523714f, 0.0002579038846306503f, 0.0002677730517461896f, 0.00031737712561152875f, 0.000267867639195174f, 0.0002832394966389984f, 0.00032638496486470103f, 0.0002701663179323077f, 0.0002566878974903375f, 0.00036163628101348877f, 0.00028616597410291433f, 0.0003194735327269882f, 0.0003546242951415479f, 0.00039775841287337244f, 0.000374145369278267f, 0.0005095746601000428f, 0.00033579423325136304f, 0.00027916659018956125f, 0.00025926210219040513f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #91 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_34_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 160,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0010221687844023108f, 0.0011597590055316687f, 0.001302486751228571f, 0.0014189586509019136f, 0.0009757166262716055f, 0.0007706568576395512f, 0.0017707203514873981f, 0.0010124605614691973f, 0.0013835789868608117f, 0.0008454596973024309f, 0.0013064347440376878f, 0.0010943859815597534f, 0.0010693189688026905f, 0.0013702180003747344f, 0.0016788388602435589f, 0.0014470615424215794f, 0.0013168297009542584f, 0.0017950782785192132f, 0.001904777018353343f, 0.0011881610844284296f, 0.0008411749149672687f, 0.0018105126218870282f, 0.0010570751037448645f, 0.0008112823124974966f, 0.0013774668332189322f, 0.0017793242586776614f, 0.0015954156406223774f, 0.0009404618758708239f, 0.0012558134039863944f, 0.0009108989615924656f, 0.0010278403060510755f, 0.0010616055224090815f, 0.0012863822048529983f, 0.0010676300153136253f, 0.0012837762478739023f, 0.0016265807207673788f, 0.0009746506111696362f, 0.00173161830753088f, 0.0012061669258400798f, 0.0014295215951278806f, 0.0014157947152853012f, 0.0011478783562779427f, 0.001283653313294053f, 0.0013111819280311465f, 0.0011611314257606864f, 0.0018366175936535f, 0.0009634354501031339f, 0.0016290261410176754f, 0.001132305827923119f, 0.0012371705379337072f, 0.0010995966149494052f, 0.0010078205959871411f, 7.285916217369959e-05f, 0.0008671353571116924f, 2.6845596948987804e-05f, 0.001645894255489111f, 0.0014052558690309525f, 0.0008152995724231005f, 0.0017157037509605289f, 0.001433838508091867f, 0.0012195960152894258f, 0.0009060532902367413f, 0.0016674025682732463f, 0.0011886338470503688f, 0.001119772787205875f, 0.0015870386268943548f, 0.0013377948198467493f, 0.0012535164132714272f, 0.0009562450577504933f, 0.0014049105811864138f, 0.0009841799037531018f, 0.001065754098817706f, 0.001273412723094225f, 0.0010384254856035113f, 0.000971219502389431f, 0.0015857277903705835f, 0.0010583280818536878f, 0.0014411023585125804f, 0.0011943498393520713f, 0.0020160521380603313f, 0.001356875873170793f, 0.0009700570954009891f, 0.0011221726890653372f, 0.0011567999608814716f, 0.001331042847596109f, 0.0015491596423089504f, 0.0009910792578011751f, 0.002371660666540265f, 0.002378180855885148f, 0.0013178945519030094f, 0.0016420844476670027f, 6.472640961874276e-05f, 0.0009276660857722163f, 0.0011902360711246729f, 0.001181749626994133f, 0.0014590021455660462f, 0.0018616514280438423f, 0.0011473159538581967f, 0.0013905999949201941f, 0.001061792834661901f, 0.001075830077752471f, 0.001611436135135591f, 0.0014656735584139824f, 0.00228871894069016f, 0.0014753577997907996f, 0.001708720694296062f, 0.0013680278789252043f, 0.0016730049392208457f, 0.0012347663287073374f, 0.000988990650512278f, 0.0017177574336528778f, 0.0011217338033020496f, 0.0012087589129805565f, 0.0013897405005991459f, 0.0010310349753126502f, 0.001357496134005487f, 0.0008580084540881217f, 0.001406853785738349f, 0.0010216373484581709f, 0.0017371075227856636f, 0.001022343640215695f, 0.001179746352136135f, 0.0010934090241789818f, 0.001654126332141459f, 0.0015183431096374989f, 0.001206426415592432f, 0.0012036935659125447f, 0.0008972461218945682f, 0.0017976327799260616f, 0.0012020474532619119f, 0.0010121389059349895f, 0.0010072296718135476f, 0.0012358286185190082f, 0.0020050667226314545f, 0.0015143196796998382f, 8.8568362116348e-05f, 0.0014612929662689567f, 0.0008936537196859717f, 0.0011740660993382335f, 0.001738320686854422f, 0.0007079224451445043f, 0.0016330612124875188f, 0.0014539234107360244f, 0.0007866122759878635f, 0.0010651185875758529f, 0.001743584405630827f, 0.0012244106037542224f, 0.000691902416292578f, 0.0011996377725154161f, 0.0016712566139176488f, 0.001343563082627952f, 0.001101706875488162f, 0.0014508366584777832f, 0.0012866888428106904f, 0.0011545218294486403f, 0.0006462968303821981f, 0.0009044961188919842f, 0.0013600306119769812f, 0.0010880752233788371f, 0.0009371553314849734f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #92 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_34_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 160,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00011182604794157669f, 0.00012687852722592652f, 0.00014249305240809917f, 0.00015523516049142927f, 0.00010674414806999266f, 8.431044989265501e-05f, 0.00019371816597413272f, 0.0001107639618567191f, 0.00015136459842324257f, 9.249393770005554e-05f, 0.0001429249532520771f, 0.00011972666106885299f, 0.00011698430898832157f, 0.0001499029021942988f, 0.00018366625590715557f, 0.00015830964548513293f, 0.00014406217087525874f, 0.0001963829417945817f, 0.00020838406635448337f, 0.00012998572492506355f, 9.202517685480416e-05f, 0.00019807145872619003f, 0.00011564482701942325f, 8.875490311766043e-05f, 0.00015069592336658388f, 0.00019465942750684917f, 0.00017453968757763505f, 0.0001028872502502054f, 0.00013738694542553276f, 9.965304343495518e-05f, 0.0001124465125030838f, 0.00011614045797614381f, 0.00014073119382373989f, 0.00011679953604470938f, 0.00014044610725250095f, 0.00017794917221181095f, 0.00010662752174539492f, 0.00018944036855828017f, 0.00013195558858569711f, 0.00015639075718354434f, 0.00015488902863580734f, 0.00012557876470964402f, 0.0001404326467309147f, 0.00014344431110657752f, 0.00012702865933533758f, 0.00020092737395316362f, 0.00010540057701291516f, 0.00017821670917328447f, 0.00012387512833811343f, 0.00013534740719478577f, 0.00012029671052005142f, 0.00011025634012185037f, 7.970847946126014e-06f, 9.486527414992452e-05f, 2.9369289222813677e-06f, 0.00018006209575105458f, 0.0001537360658403486f, 8.919439278542995e-05f, 0.00018769930466078222f, 0.00015686302504036576f, 0.0001334247353952378f, 9.912292443914339e-05f, 0.00018241511133965105f, 0.0001300374569837004f, 0.00012250400322955102f, 0.00017362323706038296f, 0.00014635577099397779f, 0.0001371356484014541f, 0.00010461393685545772f, 0.00015369828906841576f, 0.00010767003550427034f, 0.00011659431038424373f, 0.0001393123238813132f, 0.000113604539365042f, 0.00010625215509207919f, 0.0001734798279358074f, 0.00011578189878491685f, 0.00015765770513098687f, 0.00013066278188489377f, 0.0002205576456617564f, 0.00014844325778540224f, 0.0001061249859048985f, 0.0001227665488841012f, 0.00012655480531975627f, 0.00014561710122507066f, 0.00016947924450505525f, 0.0001084248287952505f, 0.0002594614925328642f, 0.0002601747983135283f, 0.00014417867350857705f, 0.0001796452997950837f, 7.081118837959366e-06f, 0.00010148737783310935f, 0.00013021273480262607f, 0.00012928430805914104f, 0.0001596159563632682f, 0.00020366608805488795f, 0.00012551723921205848f, 0.00015213270671665668f, 0.00011616094707278535f, 0.00011769663251470774f, 0.00017629234935157f, 0.00016034580767154694f, 0.00025038758758455515f, 0.0001614052744116634f, 0.0001869353436632082f, 0.00014966329035814852f, 0.00018302802345715463f, 0.00013508438132703304f, 0.00010819633462233469f, 0.00018792397167999297f, 0.00012271854211576283f, 0.00013223914720583707f, 0.00015203867224045098f, 0.0001127960131270811f, 0.0001485111133661121f, 9.38667799346149e-05f, 0.00015391087799798697f, 0.00011176790576428175f, 0.0001900408969959244f, 0.00011184517643414438f, 0.00012906515621580184f, 0.00011961978452745825f, 0.00018096268468070775f, 0.0001661079004406929f, 0.00013198396482039243f, 0.00013168499572202563f, 9.815941302804276e-05f, 0.00019666239677462727f, 0.0001315049157710746f, 0.0001107287680497393f, 0.00011019169323844835f, 0.00013520059292204678f, 0.00021935583208687603f, 0.00016566773410886526f, 9.689446414995473e-06f, 0.00015986656944733113f, 9.776640217751265e-05f, 0.00012844373122788966f, 0.00019017361046280712f, 7.744725735392421e-05f, 0.00017865814152173698f, 0.0001590603351360187f, 8.605598122812808e-05f, 0.0001165247886092402f, 0.00019074947340413928f, 0.00013395145651884377f, 7.569465378765017e-05f, 0.0001312412932747975f, 0.00018283675308339298f, 0.00014698682934977114f, 0.00012052757665514946f, 0.0001587226433912292f, 0.00014076473598834127f, 0.00012630557466764003f, 7.070536958053708e-05f, 9.89525651675649e-05f, 0.00014878838555887341f, 0.00011903626000275835f, 0.00010252551146550104f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #93 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_36_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 160,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.010337664745748043f, 0.008884239941835403f, 0.00706552155315876f, 0.008538524620234966f, 0.007111311424523592f, 0.00426918501034379f, 0.013776923529803753f, 0.010184275917708874f, 0.0051550786010921f, 0.01374544482678175f, 0.0058875191025435925f, 0.006302608642727137f, 0.008751748129725456f, 0.00911793764680624f, 0.00669862562790513f, 0.010612965561449528f, 0.011044822633266449f, 0.010377103462815285f, 0.003484377171844244f, 0.011598920449614525f, 0.006262976676225662f, 0.011459903791546822f, 0.009137565270066261f, 0.010569938458502293f, 0.005282285623252392f, 0.012349674478173256f, 0.007181068416684866f, 0.015250963158905506f, 0.007466027978807688f, 0.01122988760471344f, 0.006228387355804443f, 0.010697565972805023f, 0.009556223638355732f, 0.009377861395478249f, 0.006743129342794418f, 0.006679398939013481f, 0.007139507215470076f, 0.007085738237947226f, 0.01280435360968113f, 0.005642614793032408f, 0.00928300991654396f, 0.004883487243205309f, 0.01304387766867876f, 0.006409947294741869f, 0.021210385486483574f, 0.010692876763641834f, 0.008146915584802628f, 0.00742556294426322f, 0.008983730338513851f, 0.006230088882148266f, 0.004801219794899225f, 0.011611432768404484f, 0.025890646502375603f, 0.010452386923134327f, 0.0027851597405970097f, 0.005362161435186863f, 0.005251812282949686f, 0.00898520927876234f, 0.005403400864452124f, 0.01005920022726059f, 0.011509561911225319f, 0.006741568446159363f, 0.005324333440512419f, 0.010069616138935089f, 0.006442171521484852f, 0.007504657376557589f, 0.00795148964971304f, 0.014977078884840012f, 0.006466350983828306f, 0.007939180359244347f, 0.009203286841511726f, 0.009487480856478214f, 0.006614276207983494f, 0.0052454122342169285f, 0.007521678693592548f, 0.006697157397866249f, 0.007010449189692736f, 0.010182893835008144f, 0.00924565177410841f, 0.008772997185587883f, 0.007455961778759956f, 0.006827161181718111f, 0.009196740575134754f, 0.006272078026086092f, 0.007778554689139128f, 0.005950288847088814f, 0.004164065700024366f, 0.0054824878461658955f, 0.007860627956688404f, 0.01241347473114729f, 0.01232173666357994f, 0.01544263493269682f, 0.008517022244632244f, 0.008926893584430218f, 0.0064846063032746315f, 0.010765223763883114f, 0.009962130337953568f, 0.010424830950796604f, 0.007389007601886988f, 0.010310953482985497f, 0.007002411410212517f, 0.008748806081712246f, 0.008857755921781063f, 0.012219333089888096f, 0.007407225668430328f, 0.0057409233413636684f, 0.006252877414226532f, 0.008484388701617718f, 0.00528249004855752f, 0.006953350733965635f, 0.01031950581818819f, 0.006985252257436514f, 0.006742732133716345f, 0.003616986097767949f, 0.006216694135218859f, 0.005666603334248066f, 0.007863739505410194f, 0.008899908512830734f, 0.00805208832025528f, 0.00809802208095789f, 0.016989532858133316f, 0.012127653695642948f, 0.008514502085745335f, 0.007185200694948435f, 0.00552190188318491f, 0.007604872342199087f, 0.008866698481142521f, 0.007200538646429777f, 0.009808545000851154f, 0.004914914257824421f, 0.009194218553602695f, 0.00887464638799429f, 0.00880784634500742f, 0.008555705659091473f, 0.006511195562779903f, 0.005262114107608795f, 0.005992827005684376f, 0.007522547151893377f, 0.00968057382851839f, 0.008671591989696026f, 0.008379005827009678f, 0.010586597956717014f, 0.008366497233510017f, 0.009883151389658451f, 0.005830890964716673f, 0.008468566462397575f, 0.0049589830450713634f, 0.0049158609472215176f, 0.010050219483673573f, 0.009572763927280903f, 0.012895136140286922f, 0.022364063188433647f, 0.007593248970806599f, 0.013102850876748562f, 0.00891474261879921f, 0.007266947999596596f, 0.011024200357496738f, 0.008177601732313633f, 0.007937145419418812f, 0.008877893909811974f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #94 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_36_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 160,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00039411126635968685f, 0.00033870115294121206f, 0.00026936468202620745f, 0.0003255211631767452f, 0.0002711103588808328f, 0.00016275764210149646f, 0.0005252289702184498f, 0.00038826349191367626f, 0.00019653128401841968f, 0.000524028844665736f, 0.00022445472131948918f, 0.00024027952167671174f, 0.0003336500667501241f, 0.0003476106212474406f, 0.0002553772064857185f, 0.00040460677701048553f, 0.00042107084300369024f, 0.00039561482844874263f, 0.0001328377693425864f, 0.00044219515984877944f, 0.0002387685963185504f, 0.0004368953232187778f, 0.0003483588807284832f, 0.0004029664269182831f, 0.0002013808989431709f, 0.0004708167689386755f, 0.0002737697504926473f, 0.0005814249743707478f, 0.000284633511910215f, 0.0004281262226868421f, 0.00023744991631247103f, 0.0004078320926055312f, 0.000364319741493091f, 0.00035751989344134927f, 0.00025707384338602424f, 0.0002546441974118352f, 0.0002721852797549218f, 0.00027013540966436267f, 0.00048815086483955383f, 0.00021511802333407104f, 0.000353903800714761f, 0.00018617718887981027f, 0.0004972824244759977f, 0.000244371680309996f, 0.000808620941825211f, 0.0004076533077750355f, 0.00031059153843671083f, 0.0002830908342730254f, 0.0003424941096454859f, 0.0002375147887505591f, 0.00018304084369447082f, 0.0004426721716299653f, 0.0009870503563433886f, 0.0003984849317930639f, 0.00010618093074299395f, 0.00020442607637960464f, 0.00020021914679091424f, 0.00034255051286891103f, 0.00020599827985279262f, 0.00038349514943547547f, 0.0004387884691823274f, 0.0002570143551565707f, 0.00020298392337281257f, 0.00038389224209822714f, 0.0002456001820974052f, 0.0002861061948351562f, 0.0003031411615666002f, 0.0005709834513254464f, 0.0002465219877194613f, 0.00030267189140431583f, 0.00035086445859633386f, 0.00036169899976812303f, 0.00025216146605089307f, 0.0001999751548282802f, 0.00028675512294285f, 0.00025532121071591973f, 0.0002672651025932282f, 0.0003882108139805496f, 0.0003524795756675303f, 0.0003344601718708873f, 0.00028424974880181253f, 0.00026027747662737966f, 0.00035061489325016737f, 0.0002391155721852556f, 0.0002965482126455754f, 0.00022684774012304842f, 0.0001587500883033499f, 0.00020901337848044932f, 0.00029967716545797884f, 0.00047324906336143613f, 0.00046975165605545044f, 0.0005887322477065027f, 0.0003247014246881008f, 0.00034032727126032114f, 0.00024721797672100365f, 0.0004104114486835897f, 0.0003797944518737495f, 0.00039743437082506716f, 0.0002816971973516047f, 0.00039309292333200574f, 0.00026695866836234927f, 0.00033353790058754385f, 0.00033769148285500705f, 0.0004658476682379842f, 0.0002823917311616242f, 0.00021886592730879784f, 0.00023838356719352305f, 0.00032345729414373636f, 0.0002013886987697333f, 0.0002650882815942168f, 0.0003934189735446125f, 0.00026630450156517327f, 0.00025705870939418674f, 0.00013789332297164947f, 0.00023700413294136524f, 0.0002160325675504282f, 0.0002997957926709205f, 0.0003392985090613365f, 0.0003069763770326972f, 0.0003087275254074484f, 0.0006477058632299304f, 0.0004623524728231132f, 0.00032460535294376314f, 0.0002739272895269096f, 0.00021051599469501525f, 0.00028992677107453346f, 0.00033803240512497723f, 0.0002745120436884463f, 0.0003739391977433115f, 0.00018737530626822263f, 0.0003505187341943383f, 0.00033833543420769274f, 0.0003357887617312372f, 0.0003261761739850044f, 0.00024823163403198123f, 0.00020061188843101263f, 0.00022846946376375854f, 0.00028678824310190976f, 0.00036906046443618834f, 0.00033059422275982797f, 0.00031943971407599747f, 0.0004036015598103404f, 0.0003189628478139639f, 0.00037678348599001765f, 0.00022229584283195436f, 0.00032285411725752056f, 0.0001890553830889985f, 0.00018741139501798898f, 0.00038315277197398245f, 0.00036495033418759704f, 0.0004916118341498077f, 0.0008526035235263407f, 0.0002894836652558297f, 0.0004995307535864413f, 0.00033986405469477177f, 0.000277043815003708f, 0.00042028463212773204f, 0.00031176142510958016f, 0.0003025943005923182f, 0.0003384592419024557f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #95 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_37_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 40,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0022202092222869396f, 0.00222390191629529f, 0.0017068202141672373f, 0.002173447050154209f, 0.0024942720774561167f, 0.0018140926258638501f, 0.0017584322486072779f, 0.001932212384417653f, 0.0024138465523719788f, 0.0016533068846911192f, 0.001985859824344516f, 0.0015018908306956291f, 0.0016265107551589608f, 0.0015403159195557237f, 0.002245984273031354f, 0.0018681398360058665f, 0.0016159244114533067f, 0.0019760990981012583f, 0.0026397176552563906f, 0.0023420893121510744f, 0.002056465018540621f, 0.0019181702518835664f, 0.0023638694547116756f, 0.0039780945517122746f, 0.002256946172565222f, 0.0019144220277667046f, 0.0018128207884728909f, 0.0023801082279533148f, 0.0021058565471321344f, 0.002212108811363578f, 0.0017151950160041451f, 0.0021321196109056473f, 0.005814452655613422f, 4.857392492346551e-16f, 1.4346529606662495e-12f, 3.739424414561654e-07f, 1.976048125129637e-08f, 1.496219733396545e-13f, 4.912343183052434e-14f, 2.0170937674052897e-15f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #96 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_37_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 40,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0001343896146863699f, 0.0001346131321042776f, 0.00010331409430364147f, 0.0001315590925514698f, 0.00015097868163138628f, 0.00010980731167364866f, 0.00010643817950040102f, 0.00011695711873471737f, 0.0001461105130147189f, 0.00010007492528529838f, 0.00012020440772175789f, 9.090968524105847e-05f, 9.845294698607177e-05f, 9.323556150775403e-05f, 0.00013594978372566402f, 0.00011307879321975634f, 9.781215339899063e-05f, 0.00011961358541157097f, 0.00015978251758497208f, 0.0001417670282535255f, 0.00012447814515326172f, 0.00011610714136622846f, 0.00014308538811746985f, 0.00024079468857962638f, 0.00013661330740433186f, 0.000115880262455903f, 0.00010973032476613298f, 0.00014406832633540034f, 0.00012746782158501446f, 0.00013389928790275007f, 0.00010382102482253686f, 0.00012905753101222217f, 0.000351949711330235f, 2.94018734841238e-17f, 8.683976931642134e-14f, 2.2634793594988878e-08f, 1.1961049928288503e-09f, 9.056641443467694e-15f, 2.9734490219969663e-15f, 1.2209499508170969e-16f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #97 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_38_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.011857245117425919f, 0.011683562770485878f, 0.01142173446714878f, 0.011056286282837391f, 0.01103372685611248f, 0.010855408385396004f, 0.010693944059312344f, 0.01055506244301796f, 0.010500945150852203f, 0.010178843513131142f, 0.010097336024045944f, 0.01004053745418787f, 0.009876210242509842f, 0.009799866937100887f, 0.009445149451494217f, 0.009369504638016224f, 0.009126460179686546f, 0.009030927903950214f, 0.008768155239522457f, 0.00863339751958847f, 0.00852045789361f, 0.008317681029438972f, 0.008224239572882652f, 0.007497228216379881f, 0.007192653603851795f, 0.007109619677066803f, 0.00693908566609025f, 0.006575355771929026f, 0.006424898747354746f, 0.006204549688845873f, 0.005821664351969957f, 0.005701292306184769f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #98 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_38_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00037888868246227503f, 0.0003141289053019136f, 0.00033157653524540365f, 0.00034307470195926726f, 0.0002749051491264254f, 0.0002890314790420234f, 0.000308137183310464f, 0.0002934907970484346f, 0.00030501082073897123f, 0.00030776122002862394f, 0.00031262109405361116f, 0.000349497830029577f, 0.00036531020305119455f, 0.00032612154609523714f, 0.0002579038846306503f, 0.0002677730517461896f, 0.00031737712561152875f, 0.000267867639195174f, 0.0002832394966389984f, 0.00032638496486470103f, 0.0002701663179323077f, 0.0002566878974903375f, 0.00036163628101348877f, 0.00028616597410291433f, 0.0003194735327269882f, 0.0003546242951415479f, 0.00039775841287337244f, 0.000374145369278267f, 0.0005095746601000428f, 0.00033579423325136304f, 0.00027916659018956125f, 0.00025926210219040513f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #99 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_39_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 208,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0013556454796344042f, 6.741795004927553e-06f, 0.0018309425795450807f, 0.001715999678708613f, 0.0014711440308019519f, 0.0013005236396566033f, 0.0017397177871316671f, 0.0014768521068617702f, 0.000892836891580373f, 6.363802640407812e-08f, 0.0012657782062888145f, 0.0009578305180184543f, 0.0011695505818352103f, 0.0010126506676897407f, 0.0010675849625840783f, 0.0019908223766833544f, 0.0008852658211253583f, 0.0010451796697452664f, 0.0011549420887604356f, 0.0011411621235311031f, 0.0010435961885377765f, 0.001635901047848165f, 0.002005226444453001f, 0.0012965832138434052f, 0.0013625632273033261f, 0.0015170312253758311f, 9.02065949048847e-05f, 7.0673125129872005e-09f, 1.5217065993056167e-05f, 0.0023596654646098614f, 0.001372120575979352f, 0.0010307921329513192f, 0.001957220258191228f, 0.00166318379342556f, 0.0001240471174241975f, 0.0017490024911239743f, 0.001067434553988278f, 0.0014502775156870484f, 0.0012868436751887202f, 0.001575327361933887f, 0.0012445398606359959f, 2.193340151279699e-05f, 0.0022041506599634886f, 0.0010111985029652715f, 0.0018782735569402575f, 0.0012636510655283928f, 0.0019656075164675713f, 9.332011927654094e-07f, 0.0013347194762900472f, 0.0009234194876626134f, 0.0006816504173912108f, 0.001806057640351355f, 0.0014382301596924663f, 0.0016488718101754785f, 0.0010079997591674328f, 0.0012148001696914434f, 0.0029853873420506716f, 0.0014268000377342105f, 0.0010799462907016277f, 0.0017903967527672648f, 0.001325709861703217f, 0.0016842044424265623f, 0.001277643023058772f, 0.0017005970003083348f, 0.0015521382447332144f, 0.0012257798807695508f, 0.0015751351602375507f, 0.0017834613099694252f, 0.001128754927776754f, 0.0008727667154744267f, 0.0018040608847513795f, 0.0014531860360875726f, 0.0010648169554769993f, 0.0013177550863474607f, 0.0010780699085444212f, 0.0017636920092627406f, 0.0006264032563194633f, 0.0011198994470760226f, 0.000778437708504498f, 0.001323973061516881f, 0.0016594170592725277f, 0.0012013788800686598f, 0.0016175705241039395f, 2.8113841835875064e-05f, 0.0014421137748286128f, 0.0012326710857450962f, 7.781190106470603e-06f, 0.0008112344075925648f, 7.36740548745729e-06f, 0.0023469096049666405f, 0.0018107587238773704f, 0.0011919669341295958f, 0.0016599755035713315f, 0.0019562493544071913f, 0.002763938158750534f, 0.001372338505461812f, 0.0016871184343472123f, 0.0016331349033862352f, 0.000992520130239427f, 0.0014637408312410116f, 1.4285664065027959e-06f, 0.0012383692665025592f, 0.001682013156823814f, 0.001441375003196299f, 2.2482447548100026e-06f, 0.0010774321854114532f, 0.002181654330343008f, 0.001475444994866848f, 0.0013293358497321606f, 0.0020815900061279535f, 0.0016232850030064583f, 0.0009171371348202229f, 0.001593110733665526f, 0.001682767877355218f, 6.378968100761995e-05f, 0.0018900047289207578f, 0.0012615484884008765f, 7.103499683580594e-06f, 8.717300943317241e-07f, 0.0018902876181527972f, 0.0011132737854495645f, 0.0013324498431757092f, 6.235196451598313e-06f, 0.001871214248239994f, 5.15846977577894e-07f, 0.0011994900414720178f, 1.2774814877047902e-06f, 0.0009937445865944028f, 0.0011596030090004206f, 5.7992547226604074e-05f, 0.0015557080041617155f, 0.0016230149194598198f, 0.00133247091434896f, 0.0014272189000621438f, 0.0017216175328940153f, 1.3756915961948835e-07f, 0.0013743317686021328f, 0.0017170205246657133f, 0.001146870432421565f, 0.0017336460296064615f, 0.0007358060101978481f, 0.0016304871533066034f, 0.0014384445967152715f, 0.0008932322962209582f, 0.0012863274896517396f, 0.002101584104821086f, 0.0017202728195115924f, 1.670778692641761e-05f, 9.257415456431772e-08f, 0.001520604477263987f, 0.0013283896259963512f, 0.0010490604909136891f, 0.001501325168646872f, 0.001650782534852624f, 0.0019133148016408086f, 0.0015668519772589207f, 0.0016368180513381958f, 0.0012192453723400831f, 0.0019449439132586122f, 6.976887902965245e-07f, 0.0011035475181415677f, 2.104202849295689e-06f, 0.00016282041906379163f, 4.5964570745127276e-05f, 0.0010609414894133806f, 0.0012020766735076904f, 0.0011898630764335394f, 0.001787068322300911f, 0.0012399377301335335f, 0.0014668225776404142f, 0.0021602632477879524f, 0.0001209757465403527f, 6.882292655063793e-05f, 0.0019474857253953815f, 0.0012102295877411962f, 0.0021330465096980333f, 0.0009887187043204904f, 5.999555469315965e-06f, 0.0010971607407554984f, 0.0012675971956923604f, 3.786351589951664e-05f, 0.0012541512260213494f, 0.0012803833233192563f, 0.0009868743363767862f, 0.0017078304663300514f, 0.0018110702512785792f, 0.0012030216166749597f, 0.0013979770010337234f, 0.001463455380871892f, 0.0018088663928210735f, 3.7307872844394296e-06f, 0.0014424039982259274f, 0.0011669384548440576f, 0.001583392033353448f, 0.0022157784551382065f, 2.9537106456700712e-05f, 0.0014540563570335507f, 0.0012755568604916334f, 0.0012003722367808223f, 0.0014930447796359658f, 3.4261091059306636e-05f, 0.0012125265784561634f, 0.0013402525801211596f, 0.001874145702458918f, 0.00010136811761185527f, 0.001806485466659069f, 0.001279702759347856f, 0.0010873524006456137f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #100 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_39_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 208,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(9.730846068123356e-05f, 4.839271809942147e-07f, 0.0001314253604505211f, 0.00012317474465817213f, 0.00010559896327322349f, 9.335180220659822e-05f, 0.00012487723142839968f, 0.000106008694274351f, 6.408798071788624e-05f, 4.567948241884778e-09f, 9.085777128348127e-05f, 6.875323742860928e-05f, 8.395053737331182e-05f, 7.268823537742719e-05f, 7.663142605451867e-05f, 0.00014290156832430512f, 6.354453216772527e-05f, 7.502317021135241e-05f, 8.290193363791332e-05f, 8.191281085601076e-05f, 7.490951247746125e-05f, 0.00011742525384761393f, 0.0001439354964531958f, 9.306896390626207e-05f, 9.780501568457112e-05f, 0.00010889275290537626f, 6.475044301623711e-06f, 5.072928743743432e-10f, 1.0922835826931987e-06f, 0.00016937717737164348f, 9.849104390013963e-05f, 7.399043533951044e-05f, 0.00014048960292711854f, 0.00011938361421925947f, 8.904123205866199e-06f, 0.00012554369459394366f, 7.662062853341922e-05f, 0.00010410116374259815f, 9.236985351890326e-05f, 0.00011307726526865736f, 8.933327626436949e-05f, 1.5743831909276196e-06f, 0.00015821430133655667f, 7.25840000086464e-05f, 0.00013482279609888792f, 9.070508531294763e-05f, 0.0001410916302120313f, 6.698533638882509e-08f, 9.580639016348869e-05f, 6.62832026137039e-05f, 4.8928981414064765e-05f, 0.00012963911285623908f, 0.00010323640162823722f, 0.00011835629265988246f, 7.235439261421561e-05f, 8.719856123207137e-05f, 0.00021429160551633686f, 0.00010241594281978905f, 7.751872908556834e-05f, 0.00012851497740484774f, 9.51596739469096e-05f, 0.00012089248048141599f, 9.170942939817905e-05f, 0.00012206914107082412f, 0.00011141274444526061f, 8.79866856848821e-05f, 0.00011306346277706325f, 0.0001280171563848853f, 8.102221909211949e-05f, 6.264734111027792e-05f, 0.0001294957910431549f, 0.00010430994007037953f, 7.643274147994816e-05f, 9.458867862122133e-05f, 7.738403655821458e-05f, 0.0001265981118194759f, 4.49633298558183e-05f, 8.038656960707158e-05f, 5.587638952420093e-05f, 9.503500768914819e-05f, 0.0001191132323583588f, 8.62351807882078e-05f, 0.00011610948422458023f, 2.0180161754979054e-06f, 0.00010351516539230943f, 8.848133438732475e-05f, 5.585351345871459e-07f, 5.823054016218521e-05f, 5.288335955810908e-07f, 0.00016846157086547464f, 0.0001299765717703849f, 8.555958629585803e-05f, 0.00011915332288481295f, 0.00014041989925317466f, 0.00019839593733195215f, 9.850668720901012e-05f, 0.00012110164243495092f, 0.00011722670024028048f, 7.124325929908082e-05f, 0.0001050675637088716f, 1.0254273519194612e-07f, 8.889035234460607e-05f, 0.00012073518882971257f, 0.00010346213821321726f, 1.6137938985139044e-07f, 7.733826350886375e-05f, 0.0001565995189594105f, 0.0001059076894307509f, 9.541994950268418e-05f, 0.00014941688277758658f, 0.00011651966633507982f, 6.583226058864966e-05f, 0.00011435375199653208f, 0.00012078935833415017f, 4.5788337956764735e-06f, 0.0001356648572254926f, 9.055416012415662e-05f, 5.098904125588888e-07f, 6.257292994860109e-08f, 0.00013568515714723617f, 7.991097663762048e-05f, 9.56434741965495e-05f, 4.4756345118912577e-07f, 0.00013431606930680573f, 3.7027582777682255e-08f, 8.609959331806749e-05f, 9.169783510287743e-08f, 7.133115286706015e-05f, 8.32364967209287e-05f, 4.16271495851106e-06f, 0.00011166898184455931f, 0.00011650028318399563f, 9.564498759573326e-05f, 0.00010244601435260847f, 0.0001235779927810654f, 9.874737472159723e-09f, 9.864976163953543e-05f, 0.00012324802810326219f, 8.232254913309589e-05f, 0.0001244414015673101f, 5.281627818476409e-05f, 0.00011703663767548278f, 0.00010325179755454883f, 6.411636422853917e-05f, 9.233280434273183e-05f, 0.00015085206541698426f, 0.00012348146992735565f, 1.1992877944067004e-06f, 6.6449881153118895e-09f, 0.00010914924496319145f, 9.535202843835577e-05f, 7.530173752456903e-05f, 0.00010776537237688899f, 0.00011849344446090981f, 0.00013733805099036545f, 0.00011246890062466264f, 0.00011749107216019183f, 8.751763380132616e-05f, 0.00013960839714854956f, 5.008021730645851e-08f, 7.921282667666674e-05f, 1.5104002670796035e-07f, 1.1687277037708554e-05f, 3.2993445984175196e-06f, 7.615455979248509e-05f, 8.628526848042384e-05f, 8.540857379557565e-05f, 0.00012827606406062841f, 8.900294051272795e-05f, 0.00010528876737225801f, 0.00015506405907217413f, 8.683658961672336e-06f, 4.940121016261401e-06f, 0.00013979084906168282f, 8.687048102729023e-05f, 0.00015311043534893543f, 7.097039633663371e-05f, 4.306490950511943e-07f, 7.875438313931227e-05f, 9.098833834286779e-05f, 2.7178496111446293e-06f, 9.002318256534636e-05f, 9.190612763632089e-05f, 7.083800301188603e-05f, 0.00012258836068212986f, 0.00012999892351217568f, 8.635309495730326e-05f, 0.000100347024272196f, 0.00010504707461223006f, 0.0001298407296417281f, 2.6779653694575245e-07f, 0.00010353600373491645f, 8.376303594559431e-05f, 0.0001136561477323994f, 0.0001590489555383101f, 2.1201783511060057e-06f, 0.0001043724114424549f, 9.155968291452155e-05f, 8.616292325314134e-05f, 0.00010717100667534396f, 2.4592668523837347e-06f, 8.703536150278524e-05f, 9.62035555858165e-05f, 0.00013452649000100791f, 7.276220458152238e-06f, 0.00012966983194928616f, 9.185727685689926e-05f, 7.805033965269104e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #101 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_41_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 208,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.009212838485836983f, 1.5247931628437073e-07f, 0.00635435339063406f, 0.011460475623607635f, 0.01082906685769558f, 0.011365246959030628f, 0.011926394887268543f, 0.006411991082131863f, 0.006477003451436758f, 9.246299441656447e-07f, 0.010887691751122475f, 0.005536707583814859f, 0.00451058940961957f, 0.007389318197965622f, 0.010521270334720612f, 0.0066840569488704205f, 0.00819762796163559f, 0.01051295455545187f, 0.01011037826538086f, 0.02073611505329609f, 0.010477496311068535f, 0.009384803473949432f, 0.005897473078221083f, 0.008535678498446941f, 0.00934700109064579f, 0.011777692474424839f, 0.0062011489644646645f, 1.2295868145884015e-06f, 0.0471566803753376f, 0.008360275998711586f, 0.00782640092074871f, 0.00999494455754757f, 0.008004922419786453f, 0.00927621778100729f, 0.02285717986524105f, 0.008776610717177391f, 0.00796154048293829f, 0.009167545475065708f, 0.005917607340961695f, 0.008179045282304287f, 0.015262551605701447f, 0.0009004406747408211f, 0.009781688451766968f, 0.006309139542281628f, 0.00958943646401167f, 0.011557386256754398f, 0.0055012451484799385f, 3.344647439007531e-06f, 0.007598545867949724f, 0.01196011807769537f, 0.004276363644748926f, 0.004948494024574757f, 0.004943445790559053f, 0.009112733416259289f, 0.00952376052737236f, 0.013344102539122105f, 0.006470304913818836f, 0.008760558441281319f, 0.006319459527730942f, 0.0072891865856945515f, 0.011508635245263577f, 0.0069753145799040794f, 0.005356146022677422f, 0.0035098257940262556f, 0.0063854483887553215f, 0.008503096178174019f, 0.003836926771327853f, 0.00846127886325121f, 0.011779279448091984f, 0.011933114379644394f, 0.011401399970054626f, 0.012663809582591057f, 0.008009442128241062f, 0.001165852532722056f, 0.005324213765561581f, 0.005678055342286825f, 0.019948195666074753f, 0.013576848432421684f, 0.017927028238773346f, 0.005848931614309549f, 0.00653019780293107f, 0.012388228438794613f, 0.00632486492395401f, 0.014003022573888302f, 0.01087609026581049f, 0.006227664649486542f, 8.136610267683864e-05f, 0.009083990007638931f, 1.6489984773215838e-05f, 0.011119966395199299f, 0.007013852708041668f, 0.007192992139607668f, 0.012613529339432716f, 0.018145017325878143f, 0.007548957597464323f, 0.007718370296061039f, 0.007520356215536594f, 0.008015761151909828f, 0.00528843654319644f, 0.013080966658890247f, 1.8136810467694886e-05f, 0.007434561848640442f, 0.01007059309631586f, 0.008916023187339306f, 6.674715405097231e-05f, 0.010639430955052376f, 0.008577137254178524f, 0.006707734894007444f, 0.008063170127570629f, 0.00434110825881362f, 0.009022717364132404f, 0.008113649673759937f, 0.0063785952515900135f, 0.021371934562921524f, 0.008235051296651363f, 0.012632190249860287f, 0.008252608589828014f, 2.188270809710957e-05f, 3.4419711028021993e-06f, 0.008157677948474884f, 0.015022793784737587f, 0.0107178445905447f, 1.0908728427239112e-06f, 0.008565428666770458f, 1.562142642796971e-06f, 0.009367791004478931f, 3.60095214091416e-06f, 0.0042245895601809025f, 0.011384711600840092f, 0.00844571366906166f, 0.010639923624694347f, 0.006819951813668013f, 0.007661760319024324f, 0.008052989840507507f, 0.008053268305957317f, 9.043613431458652e-07f, 0.010759458877146244f, 0.0065964991226792336f, 0.009279183112084866f, 0.006392632145434618f, 0.010709899477660656f, 0.01027777697890997f, 0.012276062741875648f, 0.012536419555544853f, 0.010001162998378277f, 0.011437058448791504f, 0.01070480514317751f, 3.0312841772683896e-05f, 1.090994601327111e-06f, 0.01723760925233364f, 0.005268515553325415f, 0.008081923238933086f, 0.012294184416532516f, 0.007845534943044186f, 0.006311751436442137f, 0.007372765801846981f, 0.009079151786863804f, 0.007645499426871538f, 0.00763131445273757f, 7.182177341746865e-06f, 0.008230647072196007f, 3.423312955419533e-05f, 0.017089609056711197f, 0.0014768289402127266f, 0.010082623921334743f, 0.004679171368479729f, 0.014310632832348347f, 0.009672763757407665f, 0.006313461344689131f, 0.009378924034535885f, 0.00980281364172697f, 0.00767500652000308f, 0.03362166881561279f, 0.006000836845487356f, 0.005776233971118927f, 0.015680775046348572f, 0.00792974978685379f, 0.00011786256800405681f, 0.007007530890405178f, 0.009694928303360939f, 0.0006529674283228815f, 0.006906233727931976f, 0.005764451343566179f, 0.012660904787480831f, 0.005760819185525179f, 0.01150242518633604f, 0.0037783035077154636f, 0.01286329235881567f, 0.01343980710953474f, 0.00714148348197341f, 0.0002560638531576842f, 0.010100186802446842f, 0.013428580947220325f, 0.010964012704789639f, 0.008311641402542591f, 0.0005815847543999553f, 0.0068212030455470085f, 0.011911816895008087f, 0.016544686630368233f, 0.007877090014517307f, 0.00020847348787356168f, 0.007743893191218376f, 0.007265254855155945f, 0.006846684962511063f, 0.01037296187132597f, 0.008110761642456055f, 0.007387988734990358f, 0.01145073864609003f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #102 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_41_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 208,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00030551469535566866f, 5.056494778443721e-09f, 0.00021072206436656415f, 0.0003800504782702774f, 0.00035911178565584123f, 0.0003768925089389086f, 0.00039550120709463954f, 0.00021263342932797968f, 0.00021478935377672315f, 3.0662430816619235e-08f, 0.0003610558924265206f, 0.00018360742251388729f, 0.0001495794567745179f, 0.0002450433967169374f, 0.0003489046939648688f, 0.00022165563132148236f, 0.00027184843202121556f, 0.00034862893517129123f, 0.00033527874620631337f, 0.000687647785525769f, 0.0003474530822131783f, 0.000311217358103022f, 0.00019557106134016067f, 0.000283058820059523f, 0.0003099637688137591f, 0.0003905699704773724f, 0.00020564152509905398f, 4.0775361753730976e-08f, 0.0015638023614883423f, 0.00027724215760827065f, 0.0002595378609839827f, 0.0003314507775940001f, 0.00026545795844867826f, 0.00030761645757593215f, 0.0007579861558042467f, 0.00029104857821948826f, 0.0002640193561092019f, 0.0003040126757696271f, 0.00019623876141849905f, 0.0002712321875151247f, 0.0005061342963017523f, 2.9860269933124073e-05f, 0.0003243788087274879f, 0.00020922267867717892f, 0.00031800338183529675f, 0.0003832642105408013f, 0.00018243142403662205f, 1.1091466944890271e-07f, 0.0002519817790016532f, 0.00039661955088377f, 0.00014181209553498775f, 0.00016410117677878588f, 0.00016393377154599875f, 0.00030219502514228225f, 0.00031582542578689754f, 0.00044251501094549894f, 0.00021456721879076213f, 0.00029051624005660415f, 0.00020956491061951965f, 0.0002417228533886373f, 0.0003816475218627602f, 0.0002313142758794129f, 0.0001776196586433798f, 0.00011639228614512831f, 0.00021175322763156146f, 0.00028197834035381675f, 0.0001272395602427423f, 0.0002805916010402143f, 0.0003906225902028382f, 0.00039572405512444675f, 0.00037809141213074327f, 0.0004199552349746227f, 0.00026560784317553043f, 3.866181577905081e-05f, 0.00017656073032412678f, 0.000188294769031927f, 0.0006615188904106617f, 0.0004502332885749638f, 0.0005944932927377522f, 0.00019396134302951396f, 0.00021655338059645146f, 0.0004108164575882256f, 0.00020974416111130267f, 0.0004643660213332623f, 0.000360671168891713f, 0.00020652082457672805f, 2.6982497729477473e-06f, 0.00030124184559099376f, 5.46838236914482e-07f, 0.00036875857040286064f, 0.00023259226873051375f, 0.0002385328698437661f, 0.000418287847423926f, 0.0006017221603542566f, 0.00025033732526935637f, 0.00025595538318157196f, 0.0002493888605386019f, 0.0002658173907548189f, 0.0001753742981236428f, 0.00043378895497880876f, 6.014500399942335e-07f, 0.00024654375738464296f, 0.0003339594113640487f, 0.00029567175079137087f, 2.213458628830267e-06f, 0.0003528231172822416f, 0.00028443365590646863f, 0.0002224408381152898f, 0.00026738957967609167f, 0.0001439591433154419f, 0.00029920993256382644f, 0.0002690635737963021f, 0.00021152597037144005f, 0.0007087326957844198f, 0.0002730894775595516f, 0.0004189066821709275f, 0.00027367169968783855f, 7.25670872725459e-07f, 1.1414209666327224e-07f, 0.00027052362565882504f, 0.0004981834790669382f, 0.00035542345722205937f, 3.6175350714984233e-08f, 0.00028404538170434535f, 5.180352502520691e-08f, 0.00031065320945344865f, 1.1941421007577446e-07f, 0.00014009517326485366f, 0.0003775380027946085f, 0.00028007541550323367f, 0.0003528394445311278f, 0.00022616215574089438f, 0.0002540780697017908f, 0.00026705197524279356f, 0.00026706120115704834f, 2.999028581029961e-08f, 0.0003568034735508263f, 0.00021875205857213587f, 0.00030771479941904545f, 0.00021199145703576505f, 0.00035515998024493456f, 0.00034083001082763076f, 0.00040709684253670275f, 0.0004157307557761669f, 0.00033165697823278606f, 0.0003792739298660308f, 0.0003549910616129637f, 1.0052297056972748e-06f, 3.617939015043703e-08f, 0.000571630836930126f, 0.0001747136702761054f, 0.00026801147032529116f, 0.0004076977784279734f, 0.0002601723826956004f, 0.0002093093062285334f, 0.0002444944984745234f, 0.0003010813961736858f, 0.00025353883393108845f, 0.00025306842871941626f, 2.381742234547346e-07f, 0.00027294340543448925f, 1.1352335604897235e-06f, 0.0005667228833772242f, 4.8974365199683234e-05f, 0.0003343583666719496f, 0.00015516993880737573f, 0.00047456694301217794f, 0.00032076664501801133f, 0.0002093660004902631f, 0.0003110223915427923f, 0.0003250793379265815f, 0.00025451736291870475f, 0.001114956452511251f, 0.00019899879407603294f, 0.00019155055633746088f, 0.0005200033774599433f, 0.0002629650989547372f, 3.9085398384486325e-06f, 0.0002323826338397339f, 0.00032150166225619614f, 2.1653602743754163e-05f, 0.000229023426072672f, 0.000191159822861664f, 0.00041985890129581094f, 0.0001910393766593188f, 0.0003814416122622788f, 0.00012529549712780863f, 0.0004265704483259469f, 0.0004456887545529753f, 0.00023682473693042994f, 8.491549124300946e-06f, 0.0003349407925270498f, 0.00044531645835377276f, 0.0003635868488345295f, 0.0002756293397396803f, 1.9286420865682885e-05f, 0.00022620365780312568f, 0.0003950177924707532f, 0.0005486522568389773f, 0.00026121881091967225f, 6.913364813954104e-06f, 0.00025680175167508423f, 0.00024092923558782786f, 0.00022704868752043694f, 0.0003439865249674767f, 0.00026896779309026897f, 0.00024499930441379547f, 0.0003797275712713599f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #103 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_42_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 40,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0022321606520563364f, 0.0018193557625636458f, 0.0017419616924598813f, 0.0016449631657451391f, 0.0016643299022689462f, 0.0016728456830605865f, 0.0018804343417286873f, 0.0015817417297512293f, 0.0017988152103498578f, 0.0016857320442795753f, 0.0016833149129524827f, 0.0026903089601546526f, 0.0017977866809815168f, 0.0018267423147335649f, 0.0017228731885552406f, 0.0015176563756540418f, 0.0018997197039425373f, 0.002446699421852827f, 0.0018425376620143652f, 0.0021499888971447945f, 0.0021955356933176517f, 0.0019258628599345684f, 0.0018808005843311548f, 0.0020492300391197205f, 0.0024602224584668875f, 0.0024488046765327454f, 0.0017288562376052141f, 0.0020773643627762794f, 0.003322065342217684f, 0.001864858902990818f, 0.002065576147288084f, 0.002076003234833479f, 0.0022922747302800417f, 0.0017088653985410929f, 0.001876599038951099f, 0.002199936890974641f, 0.0018263700185343623f, 0.0019024250796064734f, 0.0014767165994271636f, 0.0022106708493083715f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #104 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_42_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 40,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0001343896146863699f, 0.0001346131321042776f, 0.00010331409430364147f, 0.0001315590925514698f, 0.00015097868163138628f, 0.00010980731167364866f, 0.00010643817950040102f, 0.00011695711873471737f, 0.0001461105130147189f, 0.00010007492528529838f, 0.00012020440772175789f, 9.090968524105847e-05f, 9.845294698607177e-05f, 9.323556150775403e-05f, 0.00013594978372566402f, 0.00011307879321975634f, 9.781215339899063e-05f, 0.00011961358541157097f, 0.00015978251758497208f, 0.0001417670282535255f, 0.00012447814515326172f, 0.00011610714136622846f, 0.00014308538811746985f, 0.00024079468857962638f, 0.00013661330740433186f, 0.000115880262455903f, 0.00010973032476613298f, 0.00014406832633540034f, 0.00012746782158501446f, 0.00013389928790275007f, 0.00010382102482253686f, 0.00012905753101222217f, 0.000351949711330235f, 2.94018734841238e-17f, 8.683976931642134e-14f, 2.2634793594988878e-08f, 1.1961049928288503e-09f, 9.056641443467694e-15f, 2.9734490219969663e-15f, 1.2209499508170969e-16f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #105 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_43_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 40,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.011764081194996834f, 0.011480930261313915f, 0.011213920079171658f, 0.01115096639841795f, 0.010789330117404461f, 0.010556528344750404f, 0.010373139753937721f, 0.010345450602471828f, 0.010222789831459522f, 0.010083706118166447f, 0.009979279711842537f, 0.00967119075357914f, 0.00948101095855236f, 0.00932397972792387f, 0.009177801199257374f, 0.00903786439448595f, 0.00887033250182867f, 0.008793255314230919f, 0.008678796701133251f, 0.008498857729136944f, 0.008131954818964005f, 0.008113475516438484f, 0.007902021519839764f, 0.00777417840436101f, 0.00769894989207387f, 0.0074828374199569225f, 0.007188606541603804f, 0.006871831603348255f, 0.00668215099722147f, 0.006399939768016338f, 0.006226490717381239f, 0.006062931381165981f, 0.005662139039486647f, 0.005652448162436485f, 0.0054375892505049706f, 0.005325185600668192f, 0.0052439067512750626f, 0.005122201517224312f, 0.004865225870162249f, 0.004690875299274921f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #106 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_43_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 40,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0001343896146863699f, 0.0001346131321042776f, 0.00010331409430364147f, 0.0001315590925514698f, 0.00015097868163138628f, 0.00010980731167364866f, 0.00010643817950040102f, 0.00011695711873471737f, 0.0001461105130147189f, 0.00010007492528529838f, 0.00012020440772175789f, 9.090968524105847e-05f, 9.845294698607177e-05f, 9.323556150775403e-05f, 0.00013594978372566402f, 0.00011307879321975634f, 9.781215339899063e-05f, 0.00011961358541157097f, 0.00015978251758497208f, 0.0001417670282535255f, 0.00012447814515326172f, 0.00011610714136622846f, 0.00014308538811746985f, 0.00024079468857962638f, 0.00013661330740433186f, 0.000115880262455903f, 0.00010973032476613298f, 0.00014406832633540034f, 0.00012746782158501446f, 0.00013389928790275007f, 0.00010382102482253686f, 0.00012905753101222217f, 0.000351949711330235f, 2.94018734841238e-17f, 8.683976931642134e-14f, 2.2634793594988878e-08f, 1.1961049928288503e-09f, 9.056641443467694e-15f, 2.9734490219969663e-15f, 1.2209499508170969e-16f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #107 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_44_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 208,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.001895645633339882f, 1.3847444279235788e-05f, 0.0017040023813024163f, 0.0016145247500389814f, 5.244510975899175e-05f, 0.0014554098015651107f, 1.0340460221414105e-06f, 0.00029773343703709543f, 1.859222902567126e-05f, 0.0013377852737903595f, 0.0011757795000448823f, 0.0013922605430707335f, 0.0016344599425792694f, 0.001936060143634677f, 0.0010974310571327806f, 0.0009145098738372326f, 0.0012675111647695303f, 0.0025332935620099306f, 0.001181921223178506f, 0.001680048881098628f, 0.0014574972447007895f, 0.0013027829118072987f, 0.0015136799775063992f, 0.0027699624188244343f, 0.0014980760170146823f, 0.0026692606043070555f, 0.001179611193947494f, 0.0013155557680875063f, 0.0019411779940128326f, 0.0013768887147307396f, 1.959438122867141e-05f, 8.33630019769771e-06f, 0.0012284459080547094f, 0.0023249611258506775f, 0.0018911699298769236f, 0.0013766804477199912f, 0.0017137525137513876f, 0.0012494685361161828f, 0.001406339113600552f, 0.0028123087249696255f, 0.0013068607077002525f, 0.0018280640942975879f, 0.0017829956486821175f, 0.0016681154957041144f, 0.001159536768682301f, 0.001500135287642479f, 0.0015610757982358336f, 0.0016761526931077242f, 0.00127184868324548f, 0.0015186197124421597f, 0.0016337089473381639f, 0.0018478308338671923f, 0.0016069074627012014f, 0.001399324624799192f, 0.0014342869399115443f, 0.0012318278895691037f, 0.0020126302260905504f, 0.0018692106241360307f, 0.0018470928771421313f, 0.0013479263288900256f, 0.0017564339796081185f, 8.402385901717935e-06f, 0.001196088152937591f, 0.00010609612218104303f, 0.001418731058947742f, 0.0033093905076384544f, 0.0017590790521353483f, 0.0016376994317397475f, 0.0013212296180427074f, 0.0008716399897821248f, 0.0006380293634720147f, 1.9840167908569128e-07f, 4.133476522838464e-06f, 0.0016228852327913046f, 0.0018589914543554187f, 0.001447506481781602f, 0.002082857536152005f, 0.0013526665279641747f, 0.0005412577884271741f, 0.002329366747289896f, 0.0010108590358868241f, 1.4602872397517785e-05f, 0.002877730643376708f, 0.00017069395107682794f, 0.0014023692347109318f, 3.686313357320614e-05f, 0.0008245300850830972f, 0.0016574825858697295f, 0.0014162808656692505f, 0.0014081792905926704f, 0.0019135469337925315f, 0.0014775539748370647f, 0.0009685102850198746f, 0.0013225636212155223f, 0.0013463865034282207f, 0.0020468351431190968f, 0.001707967952825129f, 5.5274012993322685e-06f, 0.0012512515531852841f, 0.0012475857511162758f, 0.0011674038833007216f, 0.0017041617538779974f, 2.2116988475318067e-05f, 0.00016981796943582594f, 0.0012419542763382196f, 0.0010369529481977224f, 0.001462977146729827f, 0.0007488799165003002f, 0.0020144737791270018f, 0.0006231411243788898f, 0.0012660964857786894f, 0.00147278793156147f, 0.0016875930596143007f, 0.0013449456309899688f, 0.0013992578024044633f, 1.880600848380709e-06f, 0.0019438706804066896f, 0.0017960488330572844f, 0.0015892734518274665f, 0.00139142875559628f, 0.001130883116275072f, 0.0015240147477015853f, 1.3900516933063045e-06f, 0.0016273350920528173f, 0.0016533688176423311f, 0.0028457222506403923f, 0.0008833457832224667f, 0.0011032841866835952f, 0.0013893404975533485f, 0.0011649868683889508f, 0.0018134101992473006f, 0.0012647847179323435f, 0.0014237163122743368f, 0.0014512843918055296f, 0.0014323546783998609f, 0.0017026476562023163f, 0.0005346254911273718f, 0.0010608528973534703f, 0.0016829072264954448f, 3.604353878472466e-06f, 9.918270734488033e-06f, 0.0014844306278973818f, 0.0012222685618326068f, 0.0011414256878197193f, 0.0017178006237372756f, 0.0012804418802261353f, 0.0012215987080708146f, 0.0016394909471273422f, 0.0016671490157023072f, 0.0015730602899566293f, 6.008262971590739e-06f, 0.0020909993909299374f, 0.0012376323575153947f, 0.0016594771295785904f, 0.0023728685919195414f, 0.0017120428383350372f, 0.0017600007122382522f, 3.9702274534647586e-07f, 0.0015801831614226103f, 0.001757320947945118f, 0.0017272867262363434f, 0.0008559699053876102f, 0.0013639298267662525f, 0.0023720033932477236f, 0.0022084664087742567f, 0.0015778231900185347f, 0.002188875339925289f, 1.3933578884461895e-05f, 0.0018065718468278646f, 0.0012251882581040263f, 0.0016877521993592381f, 5.4392152378568426e-05f, 0.0009822073625400662f, 0.0010237046517431736f, 0.0010585890850052238f, 0.002096861135214567f, 2.725591002672445e-06f, 0.0016083557857200503f, 0.001981436973437667f, 0.0020533320493996143f, 0.001818888122215867f, 0.001300938194617629f, 0.0015181502094492316f, 0.001719389809295535f, 0.0014725119108334184f, 0.0017693008994683623f, 0.0017611075891181827f, 0.0004252845246810466f, 6.65370243950747e-05f, 0.001955352956429124f, 0.0017413552850484848f, 0.0015952354297041893f, 0.0021414807997643948f, 0.0016586588462814689f, 0.0016437293961644173f, 0.0016547463601455092f, 4.31763801316265e-05f, 0.0015592626295983791f, 9.51374604483135e-05f, 0.002319669583812356f, 0.0015881662257015705f, 4.245047603035346e-05f, 0.0013316726544871926f, 0.002750204410403967f, 0.0015641392674297094f, 0.0015157681191340089f, 0.0018977849977090955f, 3.29696194967255e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #108 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_44_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 208,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00011758963955799118f, 8.589769890932075e-07f, 0.00010570172889856622f, 0.00010015130101237446f, 3.253245949963457e-06f, 9.028117347043008e-05f, 6.414337150317806e-08f, 1.8468834241502918e-05f, 1.1533028327903594e-06f, 8.298475586343557e-05f, 7.29352977941744e-05f, 8.636392885819077e-05f, 0.00010138790821656585f, 0.00012009660713374615f, 6.807523459428921e-05f, 5.672836778103374e-05f, 7.862554775783792e-05f, 0.000157143862452358f, 7.331628148676828e-05f, 0.00010421586193842813f, 9.041065641213208e-05f, 8.081350824795663e-05f, 9.389575279783458e-05f, 0.0001718247658573091f, 9.292781760450453e-05f, 0.00016557809431105852f, 7.317298877751455e-05f, 8.160582365235314e-05f, 0.0001204140717163682f, 8.54103927849792e-05f, 1.2154678188380785e-06f, 5.171127668290865e-07f, 7.62022755225189e-05f, 0.00014422069943975657f, 0.00011731200356734917f, 8.539747796021402e-05f, 0.00010630654287524521f, 7.750633812975138e-05f, 8.723724749870598e-05f, 0.0001744515757309273f, 8.106645691441372e-05f, 0.00011339745833538473f, 0.00011060179531341419f, 0.00010347561328671873f, 7.192773773567751e-05f, 9.305556159233674e-05f, 9.683578537078574e-05f, 0.00010397416917840019f, 7.889461267041042e-05f, 9.42021724767983e-05f, 0.00010134132753591985f, 0.00011462361726444215f, 9.967879304895177e-05f, 8.680213068146259e-05f, 8.897088991943747e-05f, 7.641206320840865e-05f, 0.0001248463522642851f, 0.00011594983516260982f, 0.0001145778369391337f, 8.361381333088502e-05f, 0.00010895413288380951f, 5.212121436670714e-07f, 7.419507892336696e-05f, 6.581295565410983e-06f, 8.800593786872923e-05f, 0.00020528626919258386f, 0.00010911821300396696f, 0.00010158886288991198f, 8.195778355002403e-05f, 5.406908894656226e-05f, 3.9577884308528155e-05f, 1.2307142860379372e-08f, 2.5640551370997855e-07f, 0.00010066991671919823f, 0.0001153159246314317f, 8.97909194463864e-05f, 0.00012920265726279467f, 8.390785660594702e-05f, 3.35750009980984e-05f, 0.0001444939844077453f, 6.270504673011601e-05f, 9.058372825165861e-07f, 0.00017850978474598378f, 1.0588391887722537e-05f, 8.699098543729633e-05f, 2.2866734070703387e-06f, 5.1146791520295665e-05f, 0.00010281604045303538f, 8.785395039012656e-05f, 8.735139272175729e-05f, 0.00011870008165715262f, 9.165480878436938e-05f, 6.007809133734554e-05f, 8.204053301597014e-05f, 8.351830183528364e-05f, 0.0001269681379199028f, 0.00010594772174954414f, 3.4287268135813065e-07f, 7.761693996144459e-05f, 7.738954445812851e-05f, 7.241575076477602e-05f, 0.00010571161692496389f, 1.371948769701703e-06f, 1.0534054126765113e-05f, 7.704021845711395e-05f, 6.432368536479771e-05f, 9.075058187590912e-05f, 4.645410444936715e-05f, 0.00012496071576606482f, 3.8654343370581046e-05f, 7.853779243305326e-05f, 9.135916479863226e-05f, 0.00010468383698025718f, 8.34289166959934e-05f, 8.67979833856225e-05f, 1.1665638766089614e-07f, 0.00012058110587531701f, 0.00011141150025650859f, 9.858492558123544e-05f, 8.63123350427486e-05f, 7.015031587798148e-05f, 9.453683742322028e-05f, 8.622691183290954e-08f, 0.0001009459447232075f, 0.00010256085806759074f, 0.0001765242632245645f, 5.479521496454254e-05f, 6.843831215519458e-05f, 8.618279389338568e-05f, 7.226581510622054e-05f, 0.00011248845112277195f, 7.845642539905384e-05f, 8.831518061924726e-05f, 9.002526348922402e-05f, 8.885102579370141e-05f, 0.0001056176915881224f, 3.316359288874082e-05f, 6.580623448826373e-05f, 0.00010439316247357056f, 2.235832710084651e-07f, 6.152446303531178e-07f, 9.208137635141611e-05f, 7.581908721476793e-05f, 7.08042862243019e-05f, 0.00010655765072442591f, 7.942765660118312e-05f, 7.577753422083333e-05f, 0.0001016999885905534f, 0.00010341565939597785f, 9.757919906405732e-05f, 3.727012369836302e-07f, 0.0001297077105846256f, 7.677212124690413e-05f, 0.00010293976083630696f, 0.0001471924624638632f, 0.00010620048851706088f, 0.00010917538747889921f, 2.462789439050539e-08f, 9.802104614209384e-05f, 0.00010900915367528796f, 0.00010714608652051538f, 5.309705011313781e-05f, 8.46065377118066e-05f, 0.00014713879500050098f, 0.00013699436385650188f, 9.787465387489647e-05f, 0.0001357791043119505f, 8.64320043092448e-07f, 0.00011206426279386505f, 7.600020035170019e-05f, 0.00010469370317878202f, 3.3740236631274456e-06f, 6.092774128774181e-05f, 6.350188050419092e-05f, 6.566580850630999e-05f, 0.0001300713192904368f, 1.6907235078633676e-07f, 9.97686292976141e-05f, 0.00012291139864828438f, 0.00012737115321215242f, 0.00011282826017122716f, 8.069907198660076e-05f, 9.417304681846872e-05f, 0.00010665623267414048f, 9.134203719440848e-05f, 0.0001097522908821702f, 0.00010924405069090426f, 2.6381012503406964e-05f, 4.127387910557445e-06f, 0.00012129337119404227f, 0.00010801878670463338f, 9.895475523080677e-05f, 0.0001328391517745331f, 0.00010288900375599042f, 0.00010196290531894192f, 0.00010264630691381171f, 2.6782931854540948e-06f, 9.67233136179857e-05f, 5.9015142142015975e-06f, 0.0001438924518879503f, 9.851624781731516e-05f, 2.6332643301429925e-06f, 8.260557660833001e-05f, 0.00017059914534911513f, 9.702581883175299e-05f, 9.402528667123988e-05f, 0.00011772234574891627f, 2.045153223662055e-06f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #109 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_46_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 208,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007735850755125284f, 0.0001927188568515703f, 0.006041064392775297f, 0.012069330550730228f, 0.0004286965122446418f, 0.010601045563817024f, 9.695912922325078e-06f, 0.00014755666779819876f, 8.20253771962598e-05f, 0.010144554078578949f, 0.009780320338904858f, 0.010986552573740482f, 0.009784744121134281f, 0.004469046834856272f, 0.010669984854757786f, 0.009158764965832233f, 0.011807185597717762f, 0.005272452719509602f, 0.004977463744580746f, 0.008701704442501068f, 0.006304761860519648f, 0.007717170752584934f, 0.00889954250305891f, 0.011742495000362396f, 0.014916245825588703f, 0.007357154507189989f, 0.007402231451123953f, 0.010979595594108105f, 0.008314929902553558f, 0.007344577927142382f, 0.008326083421707153f, 0.00040880817687138915f, 0.024405673146247864f, 0.00643101567402482f, 0.00960202980786562f, 0.006702892482280731f, 0.005481300409883261f, 0.013349225744605064f, 0.00553529430180788f, 0.006489296909421682f, 0.00886409543454647f, 0.007320791017264128f, 0.0058076754212379456f, 0.00945209339261055f, 0.013030474074184895f, 0.006638732273131609f, 0.006696708966046572f, 0.0058219884522259235f, 0.009886923246085644f, 0.008039006032049656f, 0.009834020398557186f, 0.0072630331851542f, 0.007033324800431728f, 0.010241891257464886f, 0.00984408799558878f, 0.007482122629880905f, 0.005236286204308271f, 0.008389891125261784f, 0.00810242723673582f, 0.006185752339661121f, 0.010518567636609077f, 0.0002778065390884876f, 0.0130230113863945f, 0.0014380698557943106f, 0.00956461951136589f, 0.006884761620312929f, 0.00819327961653471f, 0.008543337695300579f, 0.007545168045908213f, 0.006823198404163122f, 0.01210614014416933f, 4.8076894927362446e-06f, 0.0036798713263124228f, 0.0057258326560258865f, 0.007720561698079109f, 0.006318686529994011f, 0.007118656765669584f, 0.006703801918774843f, 0.0001588583254488185f, 0.009738089516758919f, 0.011571679264307022f, 0.0001459778140997514f, 0.006724219769239426f, 2.1152562112547457e-05f, 0.009246410802006721f, 0.04444634169340134f, 0.011172164231538773f, 0.010027887299656868f, 0.0070245275273919106f, 0.006914160214364529f, 0.010094874538481236f, 0.008660351857542992f, 0.008616833947598934f, 0.007700566668063402f, 0.0094600860029459f, 0.010984277352690697f, 0.009205998852849007f, 5.2192757721059024e-05f, 0.016161879524588585f, 0.006263835821300745f, 0.011144467629492283f, 0.0077848853543400764f, 0.002733898814767599f, 3.508450754452497e-05f, 0.006986116990447044f, 0.010031855665147305f, 0.007917817682027817f, 0.007391547784209251f, 0.006730161141604185f, 0.008689072914421558f, 0.007154058665037155f, 0.008084158413112164f, 0.005145396571606398f, 0.008672833442687988f, 0.01391085796058178f, 0.0001521243539173156f, 0.006074835080653429f, 0.014304612763226032f, 0.011853571981191635f, 0.006109948270022869f, 0.008366860449314117f, 0.0104520283639431f, 6.108810794103192e-06f, 0.008349896408617496f, 0.015787702053785324f, 0.006991216447204351f, 0.007118001580238342f, 0.006936198100447655f, 0.007804546970874071f, 0.009622227400541306f, 0.007630109321326017f, 0.008511345833539963f, 0.013846893794834614f, 0.004888935945928097f, 0.006629270501434803f, 0.008815358392894268f, 0.016974302008748055f, 0.006116255186498165f, 0.008592016994953156f, 0.0007315175025723875f, 0.0002222581533715129f, 0.007813779637217522f, 0.008231491781771183f, 0.014066118746995926f, 0.009410570375621319f, 0.006887658499181271f, 0.006947791203856468f, 0.005536278244107962f, 0.007983251474797726f, 0.004649959038943052f, 2.788488200167194e-05f, 0.0057147713378071785f, 0.00663400674238801f, 0.012279980815947056f, 0.00654986035078764f, 0.006665545515716076f, 0.009644236415624619f, 2.867060402422794e-06f, 0.008702326565980911f, 0.0063833799213171005f, 0.009182708337903023f, 0.003892862005159259f, 0.007690716069191694f, 0.005258353892713785f, 0.004372362047433853f, 0.01030118390917778f, 0.004396785516291857f, 2.6059092306240927e-06f, 0.00400176364928484f, 0.010817746631801128f, 0.0067542134784162045f, 0.03809446841478348f, 0.014123949222266674f, 0.013328123837709427f, 0.014397192746400833f, 0.005780329927802086f, 1.2309081284911372e-05f, 0.006185146514326334f, 0.016814231872558594f, 0.007771954871714115f, 0.005460250191390514f, 0.007674040738493204f, 0.0056257713586091995f, 0.0031909681856632233f, 0.005861888639628887f, 0.008658802136778831f, 0.008786533959209919f, 0.028782034292817116f, 0.028984583914279938f, 0.007657504640519619f, 0.007895302027463913f, 0.005009253043681383f, 0.017295056954026222f, 0.009712954051792622f, 0.006888009142130613f, 0.006992654874920845f, 0.0006231441511772573f, 0.00468089897185564f, 0.0017977561801671982f, 0.0063006691634655f, 0.008717173710465431f, 0.0004641433188226074f, 0.004528839141130447f, 0.008032364770770073f, 0.0051870220340788364f, 0.00771209504455328f, 0.005943045020103455f, 0.002986471401527524f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #110 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_46_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 208,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00013239591498859227f, 3.298304363852367e-06f, 0.00010339034633943811f, 0.00020656165725085884f, 7.336965609283652e-06f, 0.0001814325514715165f, 1.6594158580574003e-07f, 2.5253721105400473e-06f, 1.4038307654118398e-06f, 0.00017361989011988044f, 0.00016738618433009833f, 0.00018803034618031234f, 0.00016746189794503152f, 7.6485906902235e-05f, 0.00018261242075823247f, 0.00015674851601943374f, 0.00020207515626680106f, 9.023587335832417e-05f, 8.518725371686742e-05f, 0.00014892610488459468f, 0.00010790341912070289f, 0.00013207622396294028f, 0.00015231202996801585f, 0.00020096800290048122f, 0.0002552854421082884f, 0.00012591469567269087f, 0.00012668616545852274f, 0.00018791128240991384f, 0.00014230662782210857f, 0.00012569944374263287f, 0.00014249750529415905f, 6.9965844886610284e-06f, 0.00041769311064854264f, 0.00011006420390913263f, 0.00016433480777777731f, 0.00011471725883893669f, 9.381021664012223e-05f, 0.00022846653882879764f, 9.47342996369116e-05f, 0.00011106166493846104f, 0.00015170536062214524f, 0.00012529233936220407f, 9.93959911284037e-05f, 0.00016176870849449188f, 0.0002230112295364961f, 0.00011361918586771935f, 0.000114611437311396f, 9.964095079340041e-05f, 0.00016921064525377005f, 0.00013758429849985987f, 0.0001683052396401763f, 0.00012430384231265634f, 0.00012037247506668791f, 0.00017528577882330865f, 0.00016847753431648016f, 0.00012805346341338009f, 8.961689309217036e-05f, 0.00014358955377247185f, 0.00013866972585674375f, 0.00010586662392597646f, 0.00018002098659053445f, 4.754545443574898e-06f, 0.00022288350737653673f, 2.4611978005850688e-05f, 0.00016369455261155963f, 0.00011782987712649629f, 0.0001402246271027252f, 0.00014621572336181998f, 0.00012913245882373303f, 0.00011677624570438638f, 0.0002071916387649253f, 8.22816375034563e-08f, 6.29794885753654e-05f, 9.799528197618201e-05f, 0.000132134257000871f, 0.00010814173583639786f, 0.0001218328980030492f, 0.00011473282938823104f, 2.7187952582607977e-06f, 0.0001666634198045358f, 0.00019804455223493278f, 2.4983505682030227e-06f, 0.00011508227180456743f, 3.620174595653225e-07f, 0.00015824854199308902f, 0.0007606809376738966f, 0.0001912070147227496f, 0.00017162319272756577f, 0.00012022191367577761f, 0.0001183330241474323f, 0.00017276965081691742f, 0.00014821837248746306f, 0.00014747359091416f, 0.00013179205416236073f, 0.00016190549649763852f, 0.00018799141980707645f, 0.00015755690401419997f, 8.932577202358516e-07f, 0.0002766039688140154f, 0.0001072029845090583f, 0.00019073300063610077f, 0.00013323512393981218f, 4.678955883719027e-05f, 6.004569854667352e-07f, 0.00011956453090533614f, 0.00017169110651593655f, 0.00013551021402236074f, 0.0001265033206436783f, 0.00011518395331222564f, 0.00014870992163196206f, 0.00012243878154549748f, 0.00013835706340614706f, 8.806135883787647e-05f, 0.00014843199460301548f, 0.00023807864636182785f, 2.6035461360152112e-06f, 0.00010396831930847839f, 0.0002448176092002541f, 0.0002028690360020846f, 0.00010456926247570664f, 0.00014319538604468107f, 0.00017888218280859292f, 1.0454979815222032e-07f, 0.00014290506078395993f, 0.0002702000492718071f, 0.00011965180601691827f, 0.00012182168575236574f, 0.00011871019523823634f, 0.00013357162242755294f, 0.00016468048852402717f, 0.00013058619515504688f, 0.00014566820755135268f, 0.00023698392033111304f, 8.367213740712032e-05f, 0.00011345725215505809f, 0.00015087125939317048f, 0.00029050823650322855f, 0.00010467720858287066f, 0.00014704884961247444f, 1.2519622941908892e-05f, 3.8038574530219194e-06f, 0.00013372964167501777f, 0.00014087861927691847f, 0.00024073586973827332f, 0.00016105806571431458f, 0.00011787945550167933f, 0.0001189086033264175f, 9.475113620283082e-05f, 0.00013663008576259017f, 7.958214700920507e-05f, 4.772383590534446e-07f, 9.780597611097619e-05f, 0.0001135383135988377f, 0.00021016685059294105f, 0.00011209818330826238f, 0.00011407808779040352f, 0.00016505716484971344f, 4.906856432285167e-08f, 0.00014893675688654184f, 0.00010924893285846338f, 0.00015715829795226455f, 6.662474334007129e-05f, 0.00013162345567252487f, 8.999457350000739e-05f, 7.483118679374456e-05f, 0.00017630054207984358f, 7.524918328272179e-05f, 4.459906932652302e-08f, 6.84885453665629e-05f, 0.00018514131079427898f, 0.00011559559789020568f, 0.0006519712624140084f, 0.0002417256182525307f, 0.00022810538939666003f, 0.0002464020508341491f, 9.892797970678657e-05f, 2.106648935296107e-07f, 0.00010585624841041863f, 0.0002877686929423362f, 0.0001330138329649344f, 9.344994759885594e-05f, 0.00013133806351106614f, 9.628277621231973e-05f, 5.461211549118161e-05f, 0.00010032382851932198f, 0.00014819185889791697f, 0.0001503779349150136f, 0.0004925927496515214f, 0.000496059306897223f, 0.00013105505786370486f, 0.00013512486475519836f, 8.573131344746798e-05f, 0.0002959978301078081f, 0.00016623323608655483f, 0.00011788545816671103f, 0.00011967642785748467f, 1.0664856745279394e-05f, 8.01116693764925e-05f, 3.076786015299149e-05f, 0.00010783337347675115f, 0.00014919086243025959f, 7.943623131723143e-06f, 7.750922668492422e-05f, 0.0001374706334900111f, 8.87737623997964e-05f, 0.00013198934902902693f, 0.00010171278699999675f, 5.11122343596071e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #111 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_47_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.004156976006925106f, 0.0028578685596585274f, 0.0023142762947827578f, 0.0028559225611388683f, 0.0019370578229427338f, 0.002132908208295703f, 0.00258450279943645f, 0.0017032651230692863f, 0.001952223014086485f, 0.0014333358267322183f, 0.003133642952889204f, 0.0017327617388218641f, 0.0017378194024786353f, 0.0018718915525823832f, 0.001819973113015294f, 0.002019121078774333f, 0.0018427905160933733f, 0.0019376606214791536f, 0.0016025231452658772f, 0.002778734313324094f, 0.0016467849491164088f, 0.0017724689096212387f, 0.002449589315801859f, 0.0020882475655525923f, 0.0014267688384279609f, 0.002034896519035101f, 0.0024154584389179945f, 0.001941154827363789f, 0.0019576288759708405f, 0.002081893850117922f, 0.001548724714666605f, 0.0022459886968135834f, 0.0016906223027035594f, 0.0019316385732963681f, 0.003052332904189825f, 0.0021216985769569874f, 0.0019144557882100344f, 0.0034200751688331366f, 0.0018646358512341976f, 0.0018263141391798854f, 0.0020494607742875814f, 0.0016535944305360317f, 0.0022047427482903004f, 0.0020708793308585882f, 0.0018298299983143806f, 0.002314308425411582f, 0.0016091977013275027f, 0.0020173857919871807f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #112 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_47_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0002243483904749155f, 0.0001542366953799501f, 0.00012489948130678385f, 0.00015413165965583175f, 0.00010454133007442579f, 0.00011511120828799903f, 0.00013948338164482266f, 9.192374272970483e-05f, 0.00010535978799453005f, 7.735589315416291e-05f, 0.00016912000137381256f, 9.351564949611202e-05f, 9.378860704600811e-05f, 0.00010102436499437317f, 9.822237188927829e-05f, 0.00010897021275013685f, 9.9453805887606e-05f, 0.00010457386815687642f, 8.648678340250626e-05f, 0.00014996588288340718f, 8.887556032277644e-05f, 9.5658608188387e-05f, 0.00013220221444498748f, 0.0001127009090851061f, 7.700148125877604e-05f, 0.00010982160165440291f, 0.00013036020391155034f, 0.00010476244642632082f, 0.00010565153206698596f, 0.00011235800775466487f, 8.358333434443921e-05f, 0.00012121406325604767f, 9.124141797656193e-05f, 0.00010424885840620846f, 0.00016473176947329193f, 0.00011450623424025252f, 0.00010332152305636555f, 0.00018457850092090666f, 0.00010063278023153543f, 9.85645892797038e-05f, 0.00011060762335546315f, 8.924306166591123e-05f, 0.00011898805678356439f, 0.00011176356201758608f, 9.875433897832409e-05f, 0.00012490122753661126f, 8.684700878802687e-05f, 0.0001088765638996847f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #113 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_48_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.016195472329854965f, 0.01403102558106184f, 0.013425725512206554f, 0.013292611576616764f, 0.012988467700779438f, 0.012443617917597294f, 0.012112976051867008f, 0.01207816693931818f, 0.011945859529078007f, 0.011890790425240993f, 0.0115238968282938f, 0.011459875851869583f, 0.011297116056084633f, 0.01102809514850378f, 0.010667620226740837f, 0.010602281428873539f, 0.010449712164700031f, 0.010243615135550499f, 0.010131516493856907f, 0.009885715320706367f, 0.009832006879150867f, 0.009637264534831047f, 0.009296304546296597f, 0.009160996414721012f, 0.008856826461851597f, 0.008781506679952145f, 0.008498123846948147f, 0.008060148917138577f, 0.0075776283629238605f, 0.0074405609630048275f, 0.007195906713604927f, 0.006815094966441393f, 0.006793034728616476f, 0.006536351516842842f, 0.006141785532236099f, 0.005977423395961523f, 0.005892506800591946f, 0.0058507611975073814f, 0.00561840133741498f, 0.005501225125044584f, 0.00536965299397707f, 0.005235210061073303f, 0.005138859618455172f, 0.005105681251734495f, 0.0048154015094041824f, 0.004798021633177996f, 0.004649471491575241f, 0.0045610470697283745f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #114 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_48_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0002243483904749155f, 0.0001542366953799501f, 0.00012489948130678385f, 0.00015413165965583175f, 0.00010454133007442579f, 0.00011511120828799903f, 0.00013948338164482266f, 9.192374272970483e-05f, 0.00010535978799453005f, 7.735589315416291e-05f, 0.00016912000137381256f, 9.351564949611202e-05f, 9.378860704600811e-05f, 0.00010102436499437317f, 9.822237188927829e-05f, 0.00010897021275013685f, 9.9453805887606e-05f, 0.00010457386815687642f, 8.648678340250626e-05f, 0.00014996588288340718f, 8.887556032277644e-05f, 9.5658608188387e-05f, 0.00013220221444498748f, 0.0001127009090851061f, 7.700148125877604e-05f, 0.00010982160165440291f, 0.00013036020391155034f, 0.00010476244642632082f, 0.00010565153206698596f, 0.00011235800775466487f, 8.358333434443921e-05f, 0.00012121406325604767f, 9.124141797656193e-05f, 0.00010424885840620846f, 0.00016473176947329193f, 0.00011450623424025252f, 0.00010332152305636555f, 0.00018457850092090666f, 0.00010063278023153543f, 9.85645892797038e-05f, 0.00011060762335546315f, 8.924306166591123e-05f, 0.00011898805678356439f, 0.00011176356201758608f, 9.875433897832409e-05f, 0.00012490122753661126f, 8.684700878802687e-05f, 0.0001088765638996847f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #115 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_49_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 208,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(8.396519319830986e-07f, 0.0009941552998498082f, 0.0013569480506703258f, 0.0012307586148381233f, 0.001598387723788619f, 0.0008846020791679621f, 0.0015107758808881044f, 0.0007879421464167535f, 0.0008288396638818085f, 0.0007332468521781266f, 0.0007709701894782484f, 0.001537351869046688f, 0.001469108508899808f, 9.683528787718387e-07f, 0.001631563762202859f, 0.0010487617691978812f, 0.0012013759696856141f, 0.0013097909977659583f, 4.265416908566522e-09f, 0.0009690812439657748f, 2.7916339604416862e-06f, 0.001062976778484881f, 0.0014741101767867804f, 0.0016913596773520112f, 0.0014131921343505383f, 7.84668543474254e-08f, 0.0006586953531950712f, 0.0014654510887339711f, 0.0016843173652887344f, 0.0009173760190606117f, 0.0009970153914764524f, 5.561317095725826e-08f, 0.0008731655543670058f, 0.001207508728839457f, 0.0012248872080817819f, 0.0009922957979142666f, 0.0006313076592050493f, 0.0008824538672342896f, 0.0016362759051844478f, 0.001124903908930719f, 0.00200459617190063f, 0.000996878370642662f, 0.0014802736695855856f, 0.002057387726381421f, 0.0009160583140328526f, 0.0007818729500286281f, 0.001411637756973505f, 0.0013724148739129305f, 0.001068678917363286f, 1.7343836589134298e-07f, 0.0011808748822659254f, 2.5689932954264805e-06f, 0.0013746165204793215f, 1.2692700693150982e-05f, 0.0010494395392015576f, 1.359385493060472e-07f, 0.0008805418619886041f, 0.0006489337538369f, 0.0015269467839971185f, 0.0014033071929588914f, 0.0007162709953263402f, 0.0011330826673656702f, 3.4781633129199463e-09f, 4.425619408721104e-06f, 9.703090597668051e-08f, 0.0012275147018954158f, 0.0011129979975521564f, 0.0007541661616414785f, 0.0012163239298388362f, 0.001405239338055253f, 0.0013571185991168022f, 1.7323654901701957e-06f, 0.0008473629713989794f, 1.0733175770383241e-07f, 9.993424043841515e-08f, 0.0012766129802912474f, 0.0009511960088275373f, 0.0006441618897952139f, 0.001048219739459455f, 0.0011395120527595282f, 0.0014369995333254337f, 0.002006214577704668f, 2.4738307047300623e-07f, 0.001920072827488184f, 0.0011242114705964923f, 0.0010642261477187276f, 0.0011925525031983852f, 0.0008685780921950936f, 4.431115030456567e-08f, 0.0009976215660572052f, 0.0013896396849304438f, 0.001361649832688272f, 0.0013678019167855382f, 0.0015650258865207434f, 0.0010329406941309571f, 0.0014413472963497043f, 0.0015537209110334516f, 0.0015448960475623608f, 0.0010668861214071512f, 0.0009689459693618119f, 0.001099868561141193f, 3.472675598459318e-05f, 0.00156449677888304f, 0.002067935187369585f, 0.0014380450593307614f, 0.0010178027441725135f, 0.0015290816081687808f, 0.0011065948056057096f, 0.0014289428945630789f, 0.0010303991148248315f, 0.0019099577330052853f, 0.0007830460090190172f, 1.2176989002909977e-05f, 0.0014748376561328769f, 0.0010014030849561095f, 0.0010739010758697987f, 9.564274478179868e-06f, 0.0007394897402264178f, 0.0009757168008945882f, 0.0011194702237844467f, 2.4500849349351483e-08f, 0.0004489341808948666f, 0.0010290847858414054f, 0.0005189526127651334f, 0.0008725422085262835f, 0.001051919418387115f, 0.0011532084317877889f, 0.001210276153869927f, 6.474018210411714e-09f, 0.0007850606343708932f, 2.768651938822586e-07f, 0.001523196930065751f, 0.0010891938582062721f, 0.0014952447963878512f, 0.001128060044720769f, 0.0009795273654162884f, 0.0009604176739230752f, 0.0013018770841881633f, 0.0008109784685075283f, 0.001407153089530766f, 0.001232184236869216f, 0.00012048669304931536f, 0.001588865416124463f, 0.001260108663700521f, 4.111265923256724e-07f, 0.0014519537799060345f, 1.4486695363302715e-05f, 0.0010558207286521792f, 0.0005402067326940596f, 1.992227938174551e-09f, 0.0009428468183614314f, 0.0010986075503751636f, 0.0009630770655348897f, 0.00020399010099936277f, 0.00133131246548146f, 6.103155556047568e-06f, 0.0021284620743244886f, 0.0008153427042998374f, 0.001370545127429068f, 0.001287681283429265f, 0.0009783426066860557f, 0.0009230779251083732f, 9.849284197116503e-07f, 0.0017056729411706328f, 0.001114303944632411f, 0.0011787719558924437f, 0.002025713212788105f, 6.912852404639125e-05f, 0.0011824036482721567f, 0.0010955078760161996f, 0.0010451242560520768f, 0.0008790681604295969f, 0.0008323653601109982f, 0.0013446264201775193f, 0.0010225545847788453f, 0.0010246876627206802f, 1.2502205493092333e-07f, 0.0012605881784111261f, 0.0013500791974365711f, 0.0011353971203789115f, 0.001483126892708242f, 7.866530359024182e-05f, 0.0008860958623699844f, 0.0009652589214965701f, 0.00013870021211914718f, 0.0010425637010484934f, 0.0011935968650504947f, 0.0010255041997879744f, 0.0009713732870295644f, 0.0011672279797494411f, 0.001076935208402574f, 1.3854059943696484e-06f, 0.0011303732171654701f, 0.001349749742075801f, 0.0011398503556847572f, 0.001042950083501637f, 9.227845154669012e-09f, 0.0010122620733454823f, 0.0015235509490594268f, 0.0001350551756331697f, 0.0012994571588933468f, 0.0010417200392112136f, 8.915286571209435e-07f, 0.0016069968696683645f, 2.6589943580290765e-09f, 0.0010602056281641126f, 2.7896525978121645e-08f, 0.0016890972619876266f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #116 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_49_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 208,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(4.5830031325522214e-08f, 5.4263160564005375e-05f, 7.406518125208095e-05f, 6.717748328810558e-05f, 8.724348299438134e-05f, 4.828350938623771e-05f, 8.246143988799304e-05f, 4.300759974285029e-05f, 4.5239874452818185e-05f, 4.00222088501323e-05f, 4.208123209537007e-05f, 8.391201117774472e-05f, 8.018714288482442e-05f, 5.2854808529900765e-08f, 8.905430149752647e-05f, 5.724370203097351e-05f, 6.557371671078727e-05f, 7.149124576244503e-05f, 2.3281575278755184e-10f, 5.2894563850713894e-05f, 1.5237345962759719e-07f, 5.801958832307719e-05f, 8.04601440904662e-05f, 9.231809235643595e-05f, 7.713510422036052e-05f, 4.282891818974122e-09f, 3.595302769099362e-05f, 7.998751243576407e-05f, 9.193371079163626e-05f, 5.0072379963239655e-05f, 5.4419273510575294e-05f, 3.0354880831140463e-09f, 4.7659279516665265e-05f, 6.590845441678539e-05f, 6.685701373498887e-05f, 5.416166823124513e-05f, 3.4458145819371566e-05f, 4.816625369130634e-05f, 8.931150659918785e-05f, 6.139970355434343e-05f, 0.00010941522486973554f, 5.4411793826147914e-05f, 8.07965625426732e-05f, 0.00011229670781176537f, 5.000045712222345e-05f, 4.2676329030655324e-05f, 7.705026655457914e-05f, 7.490939606213942e-05f, 5.83308246859815e-05f, 9.466643469124847e-09f, 6.445472536142915e-05f, 1.402212461698582e-07f, 7.502956577809528e-05f, 6.927952540536353e-07f, 5.7280696637462825e-05f, 7.419822090071193e-09f, 4.8061894631246105e-05f, 3.5420216590864584e-05f, 8.334407903021201e-05f, 7.659556285943836e-05f, 3.909563019988127e-05f, 6.184611993376166e-05f, 1.8984573635361102e-10f, 2.4155994537977676e-07f, 5.2961581786803436e-09f, 6.700043013552204e-05f, 6.0749855038011447e-05f, 4.116403215448372e-05f, 6.638961349381134e-05f, 7.670102786505595e-05f, 7.407448720186949e-05f, 9.45562845799941e-08f, 4.6250916057033464e-05f, 5.858401319613904e-09f, 5.454628748680079e-09f, 6.968031811993569e-05f, 5.1918348617618904e-05f, 3.515975913614966e-05f, 5.721411798731424e-05f, 6.219705392140895e-05f, 7.843456842238083e-05f, 0.00010950356227112934f, 1.3502706508461415e-08f, 0.00010480175842531025f, 6.136191223049536e-05f, 5.808778223581612e-05f, 6.509211380034685e-05f, 4.7408884711330757e-05f, 2.418599098774621e-09f, 5.4452357289846987e-05f, 7.584955892525613e-05f, 7.432181155309081e-05f, 7.46576115489006e-05f, 8.542252180632204e-05f, 5.638015500153415e-05f, 7.867187377996743e-05f, 8.480546966893598e-05f, 8.432379399891943e-05f, 5.8232970332028344e-05f, 5.2887182391714305e-05f, 6.003322050673887e-05f, 1.8954619918076787e-06f, 8.539364353055134e-05f, 0.00011287241068203002f, 7.849163375794888e-05f, 5.5553889978909865e-05f, 8.346060349140316e-05f, 6.0400354414014146e-05f, 7.79948168201372e-05f, 5.624142795568332e-05f, 0.0001042496514855884f, 4.274035745766014e-05f, 6.646465635640197e-07f, 8.04998489911668e-05f, 5.465876165544614e-05f, 5.861586032551713e-05f, 5.220389311944018e-07f, 4.036296013509855e-05f, 5.3256750106811523e-05f, 6.110312097007409e-05f, 1.337309707416523e-09f, 2.4503806344000623e-05f, 5.616969065158628e-05f, 2.8325564926490188e-05f, 4.7625253500882536e-05f, 5.7416054914938286e-05f, 6.294462946243584e-05f, 6.605951057281345e-05f, 3.53366030880764e-10f, 4.285031900508329e-05f, 1.5111904616560423e-08f, 8.313940634252504e-05f, 5.9450572734931484e-05f, 8.161371806636453e-05f, 6.157197640277445e-05f, 5.3464736993191764e-05f, 5.242168845143169e-05f, 7.105928671080619e-05f, 4.4264972530072555e-05f, 7.680548151256517e-05f, 6.725529965478927e-05f, 6.5764261307776906e-06f, 8.672373951412737e-05f, 6.877947453176603e-05f, 2.2440184821448383e-08f, 7.925079989945516e-05f, 7.907153758424101e-07f, 5.7628996728453785e-05f, 2.9485659979400225e-05f, 1.0874014189088399e-10f, 5.146263356436975e-05f, 5.99643935856875e-05f, 5.256684380583465e-05f, 1.1134224223496858e-05f, 7.266593456733972e-05f, 3.3312352343273233e-07f, 0.00011617609561653808f, 4.4503180106403306e-05f, 7.480733620468527e-05f, 7.028444815659896e-05f, 5.340007191989571e-05f, 5.0383605412207544e-05f, 5.375953904263042e-08f, 9.30993483052589e-05f, 6.08211375947576e-05f, 6.43399398541078e-05f, 0.00011056783841922879f, 3.7731854263256537e-06f, 6.453816604334861e-05f, 5.9795205743284896e-05f, 5.704515933757648e-05f, 4.79814552818425e-05f, 4.543231625575572e-05f, 7.339264266192913e-05f, 5.581325603998266e-05f, 5.5929685913724825e-05f, 6.823976050895908e-09f, 6.880564615130424e-05f, 7.36902657081373e-05f, 6.197244510985911e-05f, 8.095229713944718e-05f, 4.2937235775752924e-06f, 4.836504376726225e-05f, 5.26859330420848e-05f, 7.57055977373966e-06f, 5.6905399105744436e-05f, 6.514911365229636e-05f, 5.5974254792090505e-05f, 5.301967030391097e-05f, 6.370984920067713e-05f, 5.878146839677356e-05f, 7.561848036630181e-08f, 6.169823609525338e-05f, 7.367227954091504e-05f, 6.221551302587613e-05f, 5.692648846888915e-05f, 5.036758787824169e-10f, 5.525146843865514e-05f, 8.31587312859483e-05f, 7.371605533990078e-06f, 7.092720625223592e-05f, 5.685934957000427e-05f, 4.866157610194932e-08f, 8.771339344093576e-05f, 1.4513371060509428e-10f, 5.7868332078214735e-05f, 1.5226531147050082e-09f, 9.219460480380803e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #117 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_51_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 208,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(5.537232027563732e-06f, 0.013272291049361229f, 0.010819279588758945f, 0.015220137313008308f, 0.01401328481733799f, 0.010838869027793407f, 0.007619461975991726f, 0.016688721254467964f, 0.01229431014508009f, 0.01874169521033764f, 0.019695576280355453f, 0.01599547639489174f, 0.006616727914661169f, 5.9952344599878415e-06f, 0.010847650468349457f, 0.007099800743162632f, 0.011088390834629536f, 0.010759683325886726f, 1.5248352269736642e-07f, 0.01237263809889555f, 5.451383458421333e-06f, 0.013961872085928917f, 0.008025355637073517f, 0.010246966034173965f, 0.010794964618980885f, 1.1752018735933234e-07f, 0.018229929730296135f, 0.010480182245373726f, 0.01200109627097845f, 0.015217965468764305f, 0.013141477480530739f, 8.137060802937413e-08f, 0.015248234383761883f, 0.012774063274264336f, 0.007552516181021929f, 0.013098613359034061f, 0.049829017370939255f, 0.009784196503460407f, 0.016926607117056847f, 0.016976479440927505f, 0.009250923991203308f, 0.01487040612846613f, 0.013113700784742832f, 0.008950239047408104f, 0.013646249659359455f, 0.014436420984566212f, 0.009069077670574188f, 0.008080875501036644f, 0.009169100783765316f, 5.882563982595457e-07f, 0.013505840674042702f, 1.0416096301923972e-05f, 0.008197813294827938f, 0.00011902988626388833f, 0.015127693302929401f, 3.5409831866672903e-07f, 0.0139737194404006f, 0.012941009365022182f, 0.00745745562016964f, 0.007434263359755278f, 0.019461248070001602f, 0.01506783813238144f, 7.917162925252796e-09f, 0.017433984205126762f, 2.456432923736429e-07f, 0.0067144837230443954f, 0.0074940891936421394f, 0.013367957435548306f, 0.008552235551178455f, 0.014922422356903553f, 0.011211501434445381f, 5.449174295790726e-06f, 0.021263496950268745f, 9.852359426076873e-07f, 2.9954259161968366e-07f, 0.008479231968522072f, 0.013375074602663517f, 0.018971960991621017f, 0.012146675027906895f, 0.008738762699067593f, 0.010396163910627365f, 0.017045266926288605f, 9.790018111743848e-07f, 0.02058981917798519f, 0.011098377406597137f, 0.008690579794347286f, 0.0123403025791049f, 0.011724348179996014f, 1.4674995441055216e-07f, 0.012056917883455753f, 0.008460788056254387f, 0.007022506091743708f, 0.010654376819729805f, 0.00875617004930973f, 0.010614397004246712f, 0.009461851790547371f, 0.013939248397946358f, 0.014061643742024899f, 0.013820880092680454f, 0.015752123668789864f, 0.011822742410004139f, 0.0006067609647288918f, 0.009285090491175652f, 0.008977014571428299f, 0.009293735958635807f, 0.008590767160058022f, 0.006959305144846439f, 0.009703722782433033f, 0.01161443255841732f, 0.015590030699968338f, 0.005459775682538748f, 0.013225695118308067f, 0.010199793614447117f, 0.008306817151606083f, 0.01838942989706993f, 0.016350097954273224f, 0.0009614722221158445f, 0.01934051513671875f, 0.013088461942970753f, 0.012401221320033073f, 1.0219408608236336e-07f, 0.0005195371340960264f, 0.01193954423069954f, 0.08155756443738937f, 0.020169734954833984f, 0.012388764880597591f, 0.013108945451676846f, 0.010593734681606293f, 3.1322002769229584e-08f, 0.009756352752447128f, 4.260115474608028e-06f, 0.009360656142234802f, 0.009113998152315617f, 0.01781953126192093f, 0.010919768363237381f, 0.011699202470481396f, 0.010313156060874462f, 0.011367746628820896f, 0.018592892214655876f, 0.009388974867761135f, 0.03670576214790344f, 0.004287388641387224f, 0.0087448600679636f, 0.032533787190914154f, 4.323817393014906e-06f, 0.010861159302294254f, 0.00014831896987743676f, 0.013446898199617863f, 0.04248209670186043f, 6.626071247239906e-09f, 0.016299329698085785f, 0.011099458672106266f, 0.01986379362642765f, 0.020343270152807236f, 0.009306586347520351f, 5.991004218230955e-05f, 0.012452147901058197f, 0.01362614892423153f, 0.008495255373418331f, 0.012384721077978611f, 0.01161971129477024f, 0.013901789672672749f, 2.0853814930887893e-05f, 0.007522731088101864f, 0.011377574875950813f, 0.010555675253272057f, 0.01204401534050703f, 0.04893914610147476f, 0.013576618395745754f, 0.00941741093993187f, 0.011606722138822079f, 0.0106342239305377f, 0.013090597465634346f, 0.00849830824881792f, 0.011682819575071335f, 0.010340876877307892f, 2.3197478640213376e-06f, 0.009187491610646248f, 0.011200320906937122f, 0.009976648725569248f, 0.01064625009894371f, 0.016953593119978905f, 0.011353892274200916f, 0.01048571802675724f, 0.037572771310806274f, 0.013241294771432877f, 0.021524040028452873f, 0.011269739829003811f, 0.013805919326841831f, 0.009516065008938313f, 0.013721681199967861f, 3.864512837026268e-05f, 0.01083033811300993f, 0.010681187734007835f, 0.010023429989814758f, 0.020509446039795876f, 1.8925196343388961e-07f, 0.008939024060964584f, 0.011552980169653893f, 0.0016900324262678623f, 0.011494268663227558f, 0.009489710442721844f, 8.094640179479029e-06f, 0.016330979764461517f, 5.7262543151637146e-08f, 0.015243745408952236f, 1.048737772180175e-07f, 0.011107762344181538f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #118 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_51_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 208,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(8.611544899395085e-08f, 0.00020641165610868484f, 0.00016826223873067647f, 0.00023670471273362637f, 0.0002179356524720788f, 0.00016856689762789756f, 0.00011849844304379076f, 0.0002595442347228527f, 0.00019120202341582626f, 0.00029147224267944694f, 0.0003063070762436837f, 0.00024876283714547753f, 0.00010290384670952335f, 9.323833438656948e-08f, 0.00016870346735231578f, 0.00011041662946809083f, 0.0001724474859656766f, 0.00016733539814595133f, 2.371435048331705e-09f, 0.0001924201933434233f, 8.47803249826029e-08f, 0.00021713608293794096f, 0.00012481093290261924f, 0.00015936157433316112f, 0.00016788409266155213f, 1.8276826718732764e-09f, 0.00028351321816444397f, 0.00016298858099617064f, 0.00018664194794837385f, 0.00023667093773838133f, 0.00020437724015209824f, 1.2654817194146517e-09f, 0.00023714167764410377f, 0.0001986631832551211f, 0.0001174572971649468f, 0.00020371061691548675f, 0.0007749446085654199f, 0.00015216456085909158f, 0.0002632438554428518f, 0.00026401947252452374f, 0.0001438710605725646f, 0.00023126567248255014f, 0.00020394525199662894f, 0.00013919478806201369f, 0.00021222748910076916f, 0.0002245162904728204f, 0.00014104296860750765f, 0.00012567438534460962f, 0.0001425985392415896f, 9.148607205133885e-09f, 0.00021004384325351566f, 1.6199190611132508e-07f, 0.00012749301095027477f, 1.8511616417526966e-06f, 0.00023526701261289418f, 5.50696332979328e-09f, 0.0002173203247366473f, 0.00020125955052208155f, 0.00011597890988923609f, 0.00011561821884242818f, 0.00030266278190538287f, 0.00023433614114765078f, 1.2312831310090644e-10f, 0.0002711346314754337f, 3.820262772791239e-09f, 0.00010442415077704936f, 0.00011654863192234188f, 0.00020789947302546352f, 0.0001330049999523908f, 0.00023207462800201029f, 0.0001743621105561033f, 8.474596313590155e-08f, 0.0003306914877612144f, 1.5322463298161892e-08f, 4.6585086899142425e-09f, 0.00013186964497435838f, 0.00020801015489269048f, 0.0002950533526018262f, 0.00018890599312726408f, 0.00013590589514933527f, 0.0001616819208720699f, 0.00026508927112445235f, 1.5225509741867427e-08f, 0.0003202143998350948f, 0.00017260279855690897f, 0.00013515654427465051f, 0.0001919173082569614f, 0.00018233794253319502f, 2.282266153841306e-09f, 0.00018751008610706776f, 0.00013158281217329204f, 0.00010921453940682113f, 0.00016569766739849f, 0.00013617660442832857f, 0.00016507589316461235f, 0.0001471514260629192f, 0.00021678423217963427f, 0.00021868773910682648f, 0.00021494335669558495f, 0.00024497820413671434f, 0.0001838681782828644f, 9.43639224715298e-06f, 0.00014440242375712842f, 0.00013961120566818863f, 0.0001445368689019233f, 0.00013360424782149494f, 0.00010823163029272109f, 0.0001509130233898759f, 0.00018062852905131876f, 0.00024245731765404344f, 8.491084008710459e-05f, 0.00020568699983414263f, 0.00015862795407883823f, 0.00012918823631480336f, 0.0002859937958419323f, 0.00025427795480936766f, 1.495288779551629e-05f, 0.0003007851482834667f, 0.0002035527431871742f, 0.00019286472524981946f, 1.5893300009395261e-09f, 8.079879989963956e-06f, 0.0001856846793089062f, 0.0012683892855420709f, 0.00031368123018182814f, 0.0001926709956023842f, 0.00020387129916343838f, 0.00016475455777253956f, 4.871221204183485e-10f, 0.00015173152496572584f, 6.625363369039405e-08f, 0.0001455776218790561f, 0.00014174157695379108f, 0.00027713068993762136f, 0.00016982505621854216f, 0.0001819468743633479f, 0.0001603909768164158f, 0.0001767920475685969f, 0.00028915805160067976f, 0.00014601803559344262f, 0.0005708507378585637f, 6.667778507107869e-05f, 0.0001360007154289633f, 0.0005059678805992007f, 6.724432921600965e-08f, 0.00016891355335246772f, 2.3066677385941148e-06f, 0.00020912715990561992f, 0.0006606847164221108f, 1.0304915254444325e-10f, 0.00025348839699290693f, 0.00017261960601899773f, 0.00030892319045960903f, 0.0003163800574839115f, 0.0001447367249056697f, 9.317254239249451e-07f, 0.00019365672778803855f, 0.00021191488485783339f, 0.00013211884652264416f, 0.0001926081022247672f, 0.00018071061640512198f, 0.00021620167535729706f, 3.243200978886307e-07f, 0.0001169940733234398f, 0.00017694490088615566f, 0.0001641626440687105f, 0.0001873094297479838f, 0.0007611052715219557f, 0.00021114457922521979f, 0.00014646028284914792f, 0.0001805086067179218f, 0.00016538424824830145f, 0.00020358595065772533f, 0.00013216632942203432f, 0.0001816920848796144f, 0.00016082209185697138f, 3.6076890808089956e-08f, 0.00014288455713540316f, 0.00017418822972103953f, 0.00015515758423134685f, 0.00016557126946281642f, 0.0002636635326780379f, 0.00017657657735981047f, 0.00016307467012666166f, 0.0005843345425091684f, 0.00020592960936482996f, 0.0003347434685565531f, 0.00017526783631183207f, 0.0002147106861229986f, 0.00014799454947933555f, 0.00021340060629881918f, 6.010119477650733e-07f, 0.00016843422781676054f, 0.0001661146234255284f, 0.0001558851363370195f, 0.000318964448524639f, 2.94326074623541e-09f, 0.00013902036880608648f, 0.00017967280291486531f, 2.62835110333981e-05f, 0.0001787597284419462f, 0.00014758468023501337f, 1.2588844811034505e-07f, 0.00025398063007742167f, 8.905513548818078e-10f, 0.0002370718721067533f, 1.631004775681788e-09f, 0.00017274875426664948f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #119 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_52_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 120,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003994797356426716f, 0.0016918065957725048f, 0.0017586209578439593f, 0.00218504318036139f, 0.0018263804959133267f, 0.002194600412622094f, 0.0018960542511194944f, 0.002440493321046233f, 0.0017635221593081951f, 0.0021886355243623257f, 0.0015215736348181963f, 0.001561802695505321f, 0.0023333937861025333f, 0.0016568657010793686f, 0.0016318084672093391f, 0.0019210970494896173f, 0.0015203868970274925f, 0.002104873536154628f, 0.0020610278006643057f, 0.0018480241997167468f, 0.0015893133822828531f, 0.001967528136447072f, 0.0019255293300375342f, 0.0016534443711861968f, 0.0016756519908085465f, 0.0019735447131097317f, 0.001569631160236895f, 0.0015103609766811132f, 0.0017793340375646949f, 0.0016839820891618729f, 0.0014411576557904482f, 0.0016009092796593904f, 0.0015400536358356476f, 0.0018685717368498445f, 0.0018076178384944797f, 0.0018547207582741976f, 0.0021367203444242477f, 0.0016724145971238613f, 0.0034113111905753613f, 0.00181644840631634f, 0.001897043315693736f, 0.0020433301106095314f, 0.002110100584104657f, 0.0018688869895413518f, 0.002072828123345971f, 0.0018580724718049169f, 0.001725854934193194f, 0.002415660535916686f, 0.0015789087628945708f, 0.0018431489588692784f, 0.0022242111153900623f, 0.002402564510703087f, 0.00217297556810081f, 0.0016433647833764553f, 0.001664761221036315f, 0.0019314627861604095f, 0.0024943877942860126f, 0.0020903092809021473f, 0.0018504064064472914f, 0.0019765517208725214f, 0.0021577277220785618f, 0.001752045121975243f, 0.0019671472255140543f, 0.0020663698669523f, 0.001957234926521778f, 0.002263041213154793f, 0.0019392042886465788f, 0.0014236835995689034f, 0.002518309745937586f, 0.0016763213789090514f, 0.0019368748180568218f, 0.002232912927865982f, 0.0019143796525895596f, 0.0021856985986232758f, 0.0017831198638305068f, 0.002168676583096385f, 0.0015547610819339752f, 0.002012574579566717f, 0.0017119846306741238f, 0.001807240187190473f, 0.0014975036028772593f, 0.0017668077489361167f, 0.001977077219635248f, 0.0018988499650731683f, 0.0014690863899886608f, 0.0017057680524885654f, 0.0018199161859229207f, 0.0019226453732699156f, 0.0018195295706391335f, 0.0018600646872073412f, 0.0017402803059667349f, 0.0016562740784138441f, 0.0019839799497276545f, 0.0018253593007102609f, 0.0016558083007112145f, 0.0018183619249612093f, 3.194636124647515e-13f, 7.495436910032183e-11f, 1.9061323157897048e-13f, 9.41927954159331e-16f, 7.956447288938028e-16f, 0.007873870432376862f, 1.3227756936399614e-14f, 4.368000102242253e-13f, 8.801679385328498e-10f, 8.357202041509026e-09f, 8.195217406439543e-16f, 4.585167315274141e-12f, 6.734133006270921e-15f, 3.2536854256730785e-15f, 9.897936636971139e-11f, 4.662138763933399e-08f, 1.0415385459476567e-13f, 9.831030981692981e-14f, 7.119330082058783e-13f, 3.19238058210658e-09f, 0.003811339847743511f, 0.003329657716676593f, 1.8082112413289608e-12f, 2.325581784437536e-12f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #120 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_52_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 120,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00011514411744428799f, 4.876382081420161e-05f, 5.068964310339652e-05f, 6.298063090071082e-05f, 5.264271385385655e-05f, 6.325610593194142e-05f, 5.465095455292612e-05f, 7.034360896795988e-05f, 5.0830913096433505e-05f, 6.308417505351827e-05f, 4.385710781207308e-05f, 4.501664807321504e-05f, 6.725662387907505e-05f, 4.7756700951140374e-05f, 4.703446393250488e-05f, 5.537277684197761e-05f, 4.382289989735e-05f, 6.0669863160001114e-05f, 5.940607297816314e-05f, 5.326656173565425e-05f, 4.580960376188159e-05f, 5.671108374372125e-05f, 5.550053174374625e-05f, 4.765808625961654e-05f, 4.8298188630724326e-05f, 5.68845025554765e-05f, 4.52422937087249e-05f, 4.353391705080867e-05f, 5.1286668167449534e-05f, 4.853829159401357e-05f, 4.1539235098753124e-05f, 4.6143839426804334e-05f, 4.438976611709222e-05f, 5.385881377151236e-05f, 5.210190647630952e-05f, 5.345957833924331e-05f, 6.15878016105853e-05f, 4.820487447432242e-05f, 9.832599607761949e-05f, 5.235643402556889e-05f, 5.46794653928373e-05f, 5.889596286579035e-05f, 6.08205227763392e-05f, 5.3867901442572474e-05f, 5.974620216875337e-05f, 5.3556188504444435e-05f, 4.974521289113909e-05f, 6.962783663766459e-05f, 4.5509706978918985e-05f, 5.312603752827272e-05f, 6.410959031200036e-05f, 6.925036723259836e-05f, 6.263280374696478e-05f, 4.7367557272082195e-05f, 4.79842783533968e-05f, 5.567155312746763e-05f, 7.189703319454566e-05f, 6.025006950949319e-05f, 5.33352249476593e-05f, 5.697117740055546e-05f, 6.219330680323765e-05f, 5.050010440754704e-05f, 5.6700104323681444e-05f, 5.9560050431173295e-05f, 5.64143992960453e-05f, 6.522881449200213e-05f, 5.589469219557941e-05f, 4.1035571484826505e-05f, 7.258654659381136e-05f, 4.831748083233833e-05f, 5.5827549658715725e-05f, 6.43604071228765e-05f, 5.517915997188538e-05f, 6.299952656263486e-05f, 5.139578934176825e-05f, 6.250889418879524e-05f, 4.481368523556739e-05f, 5.8009482017951086e-05f, 4.934542084811255e-05f, 5.2091021643718705e-05f, 4.316332342568785e-05f, 5.092561696073972e-05f, 5.6986322306329384e-05f, 5.473153942148201e-05f, 4.2344239773228765e-05f, 4.9166239477926865e-05f, 5.245638749329373e-05f, 5.5417403928004205e-05f, 5.244524436420761e-05f, 5.361361036193557e-05f, 5.016100112698041e-05f, 4.773964610649273e-05f, 5.718528336728923e-05f, 5.261327896732837e-05f, 4.772622196469456e-05f, 5.2411589422263205e-05f, 9.208065523448345e-15f, 2.1604486862697447e-12f, 5.494144110609932e-15f, 2.7149679051823622e-17f, 2.2933281389289723e-17f, 0.00022695265943184495f, 3.8127049362460513e-16f, 1.2590113074805419e-14f, 2.5369538067532282e-11f, 2.408839794298956e-10f, 2.3621500622017517e-17f, 1.3216065340628663e-13f, 1.9410141151158557e-16f, 9.378266735682848e-17f, 2.85293360116623e-12f, 1.3437924106796117e-09f, 3.002080641438293e-15f, 2.8336491986679594e-15f, 2.052041499776055e-14f, 9.201564510341598e-11f, 0.00010985622793668881f, 9.59724493441172e-05f, 5.211901128233422e-14f, 6.70314498352198e-14f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #121 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_53_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.015132813714444637f, 0.014621805399656296f, 0.014389126561582088f, 0.014160020276904106f, 0.014071094803512096f, 0.013962614350020885f, 0.01375782024115324f, 0.013549501076340675f, 0.013273333199322224f, 0.013139757327735424f, 0.013053392060101032f, 0.012933543883264065f, 0.012890361249446869f, 0.01266541425138712f, 0.012422704137861729f, 0.01231548935174942f, 0.01224124152213335f, 0.012048124335706234f, 0.011845920234918594f, 0.011794179677963257f, 0.011724015697836876f, 0.011459174565970898f, 0.011296838521957397f, 0.011288600973784924f, 0.011130139231681824f, 0.011018004268407822f, 0.010926946997642517f, 0.010921154171228409f, 0.010776421055197716f, 0.010637671686708927f, 0.010486048646271229f, 0.010321108624339104f, 0.009875445626676083f, 0.009842390194535255f, 0.009687709622085094f, 0.009646930731832981f, 0.009353891015052795f, 0.009196705184876919f, 0.008866388350725174f, 0.008730476722121239f, 0.008257824927568436f, 0.008064419031143188f, 0.007809877395629883f, 0.007691035978496075f, 0.007407253608107567f, 0.007196526974439621f, 0.006956837605684996f, 0.006829813122749329f, 0.006520483642816544f, 0.006414191331714392f, 0.00622691260650754f, 0.006186013109982014f, 0.006034339312463999f, 0.005929560866206884f, 0.00582399545237422f, 0.005665848031640053f, 0.005480905994772911f, 0.005289330147206783f, 0.005140057764947414f, 0.005062050186097622f, 0.004921027459204197f, 0.004895638208836317f, 0.004702484235167503f, 0.0046621281653642654f, 0.004502289928495884f, 0.004390432965010405f, 0.004376217257231474f, 0.004276467952877283f, 0.004222674295306206f, 0.004165369085967541f, 0.004081742838025093f, 0.003968471195548773f, 0.003956994973123074f, 0.003907494712620974f, 0.0038105319254100323f, 0.0037308239843696356f, 0.0036662451457232237f, 0.0036197640001773834f, 0.0036062852013856173f, 0.0034938764292746782f, 0.0034294752404093742f, 0.0033361625391989946f, 0.0032960553653538227f, 0.0032578064128756523f, 0.0032291016541421413f, 0.003182384418323636f, 0.0031250545289367437f, 0.0031042227055877447f, 0.0030447947792708874f, 0.003018708201125264f, 0.002980615245178342f, 0.002932442119345069f, 0.002888317685574293f, 0.0028747310861945152f, 0.0028269770555198193f, 0.0027961800806224346f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #122 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_53_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00041240695281885564f, 0.00039848071173764765f, 0.0003921396273653954f, 0.00038589592440985143f, 0.0003834724775515497f, 0.00038051611045375466f, 0.0003749349561985582f, 0.0003692577301990241f, 0.00036173147964291275f, 0.00035809120163321495f, 0.000355737516656518f, 0.0003524713683873415f, 0.000351294525898993f, 0.00034516415325924754f, 0.0003385496966075152f, 0.0003356278466526419f, 0.0003336044028401375f, 0.00032834146986715496f, 0.00032283092150464654f, 0.0003214208409190178f, 0.00031950869015417993f, 0.0003122911148238927f, 0.0003078670706599951f, 0.00030764256371185184f, 0.0003033240791410208f, 0.0003002681187354028f, 0.0002977865806315094f, 0.0002976287214551121f, 0.0002936843957286328f, 0.00028990310966037214f, 0.000285771006019786f, 0.0002812759776134044f, 0.000269130541710183f, 0.0002682297199498862f, 0.00026401429204270244f, 0.00026290296227671206f, 0.0002549169003032148f, 0.0002506331948097795f, 0.00024163121997844428f, 0.0002379272918915376f, 0.00022504634398501366f, 0.00021977555297780782f, 0.00021283865498844534f, 0.00020959993707947433f, 0.00020186616166029125f, 0.00019612333562690765f, 0.0001895911991596222f, 0.00018612945859786123f, 0.00017769946134649217f, 0.000174802727997303f, 0.00016969892021734267f, 0.0001685843017185107f, 0.00016445081564597785f, 0.0001615953369764611f, 0.00015871842333581299f, 0.00015440850984305143f, 0.00014936838124413043f, 0.0001441474596504122f, 0.00014007941354066133f, 0.000137953509693034f, 0.0001341102906735614f, 0.00013341836165636778f, 0.00012815443915314972f, 0.00012705463450402021f, 0.00012269864964764565f, 0.00011965026351390406f, 0.00011926284787477925f, 0.0001165444336947985f, 0.00011507842282298952f, 0.00011351671128068119f, 0.00011123768490506336f, 0.00010815075074788183f, 0.00010783799370983616f, 0.00010648898751242086f, 0.00010384651250205934f, 0.00010167426808038726f, 9.991433762479573e-05f, 9.864760795608163e-05f, 9.828027395997196e-05f, 9.521685569779947e-05f, 9.346176375402138e-05f, 9.091875836020336e-05f, 8.982574217952788e-05f, 8.87833593878895e-05f, 8.800108480500057e-05f, 8.672792318975553e-05f, 8.51655422593467e-05f, 8.45978211145848e-05f, 8.29782584332861e-05f, 8.226733916671947e-05f, 8.122920553432778e-05f, 7.991636812221259e-05f, 7.87138706073165e-05f, 7.83435971243307e-05f, 7.704218296566978e-05f, 7.62028867029585e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #123 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_54_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 720,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0036841135006397963f, 0.004051798488944769f, 0.004468550439924002f, 0.0046426234766840935f, 0.00518829096108675f, 0.004372349474579096f, 0.003727068193256855f, 0.0036342451348900795f, 0.005810669623315334f, 0.0054724570363759995f, 0.003633987158536911f, 0.0033417907543480396f, 0.00459368247538805f, 0.003472154727205634f, 0.0058944313786923885f, 0.003481803461909294f, 0.004225623328238726f, 0.004180762451142073f, 0.00398816866800189f, 0.004030120093375444f, 0.00450464803725481f, 0.003388218116015196f, 0.0044854143634438515f, 0.0035108313895761967f, 0.0038011441938579082f, 0.004670427646487951f, 0.004421981517225504f, 0.007265712600201368f, 0.004036807920783758f, 0.00395641615614295f, 0.005301391705870628f, 0.00322280777618289f, 0.004256767220795155f, 0.00388721632771194f, 0.00519146304577589f, 0.004255954176187515f, 0.004168808460235596f, 0.0038328994996845722f, 0.003035177243873477f, 0.0055579207837581635f, 0.0030940042342990637f, 0.0034661642275750637f, 0.004031870514154434f, 0.004093189723789692f, 0.0048539540730416775f, 0.0037368773482739925f, 0.0036639655008912086f, 0.00334676681086421f, 0.008331919088959694f, 0.0034205473493784666f, 0.0037907641381025314f, 0.0037942640483379364f, 0.004324932117015123f, 0.00409404281526804f, 0.004632205236703157f, 0.0036042581778019667f, 0.004207978490740061f, 0.0038661202415823936f, 0.004690540488809347f, 0.004122829530388117f, 0.006139704026281834f, 0.005570294801145792f, 0.007548406254500151f, 0.004433272872120142f, 0.0036093853414058685f, 0.0051102046854794025f, 0.004081949591636658f, 0.0045587909407913685f, 0.003566131927073002f, 0.005559972953051329f, 0.004151213448494673f, 0.0063546812161803246f, 0.006177213508635759f, 0.004542786628007889f, 0.003101666457951069f, 0.0042942967265844345f, 0.003647126955911517f, 0.003872394096106291f, 0.0050645861774683f, 0.006577538326382637f, 0.003680406603962183f, 0.0028243858832865953f, 0.005274263210594654f, 0.004578453488647938f, 0.004563836846500635f, 0.0041057756170630455f, 0.0039634741842746735f, 0.003393961815163493f, 0.003952598199248314f, 0.006106559652835131f, 0.003902039024978876f, 0.005023680627346039f, 0.006574841216206551f, 0.006214536726474762f, 0.0032260732259601355f, 0.0045523736625909805f, 0.003521349746733904f, 0.003956290893256664f, 0.006144174840301275f, 0.004818940535187721f, 0.005968750454485416f, 0.003246507840231061f, 0.007299601100385189f, 0.004650019109249115f, 0.004418043419718742f, 0.004939676728099585f, 0.005470239091664553f, 0.0036719695199280977f, 0.0035293817054480314f, 0.00379758863709867f, 0.00621400773525238f, 0.0064127761870622635f, 0.004078729078173637f, 0.008448871783912182f, 0.005046026315540075f, 0.0030895222444087267f, 0.0032738312147557735f, 0.003247109241783619f, 0.004155461210757494f, 0.0031869332306087017f, 0.004838472697883844f, 0.0029160217382013798f, 0.003884263103827834f, 0.004481340758502483f, 0.005571533460170031f, 0.005481962114572525f, 0.0034437694121152163f, 0.0070605771616101265f, 0.0034390108194202185f, 0.004636197350919247f, 0.003658516565337777f, 0.0033213684801012278f, 0.004653980955481529f, 0.004661061801016331f, 0.004131356719881296f, 0.0049668243154883385f, 0.0031023449264466763f, 0.006299054250121117f, 0.005099747329950333f, 0.004947747103869915f, 0.0029662041924893856f, 0.0045472243800759315f, 0.004202751908451319f, 0.005803116597235203f, 0.004029516130685806f, 0.005147512070834637f, 0.005007648840546608f, 0.004115660674870014f, 0.003854132257401943f, 0.003964612726122141f, 0.005548734683543444f, 0.002897771541029215f, 0.0028798533603549004f, 0.0038280999287962914f, 0.0024944476317614317f, 0.0033654107246547937f, 0.002898551756516099f, 0.004409423563629389f, 0.003421755274757743f, 0.003411098150536418f, 0.003299043281003833f, 0.0050050741992890835f, 0.004245749209076166f, 0.0052360775880515575f, 0.003688215045258403f, 0.004383407067507505f, 0.0033010602928698063f, 0.003741864114999771f, 0.004401362966746092f, 0.005748795345425606f, 0.0052337744273245335f, 0.0045854393392801285f, 0.003917395602911711f, 0.005862991325557232f, 0.0036091762594878674f, 0.0028535176534205675f, 0.0048203617334365845f, 0.007928626611828804f, 0.0038156677037477493f, 0.004715904593467712f, 0.005760147701948881f, 0.003952788654714823f, 0.005447442177683115f, 0.0044649443589150906f, 0.004260227084159851f, 0.005136053543537855f, 0.0030947159975767136f, 0.005457253661006689f, 0.004398096818476915f, 0.0045877923257648945f, 0.004206815734505653f, 0.0036150654777884483f, 0.0038301185704767704f, 0.0061675445176661015f, 0.004506694618612528f, 0.003747260430827737f, 0.005797930993139744f, 0.0056921043433249f, 0.003579686861485243f, 0.005781858693808317f, 0.004531240090727806f, 0.005327899474650621f, 0.0035088653676211834f, 0.003989571705460548f, 0.003631013911217451f, 0.005368407350033522f, 0.005902657750993967f, 0.0036946844775229692f, 0.0043918839655816555f, 0.003623227821663022f, 0.0052559273317456245f, 0.0021814347710460424f, 0.002639997052028775f, 0.002787603996694088f, 0.004839637782424688f, 0.0032109650783240795f, 0.003367518074810505f, 0.005369149148464203f, 0.004063171800225973f, 0.005164979491382837f, 0.004475787747651339f, 0.002919125836342573f, 0.004256086423993111f, 0.002773212268948555f, 0.0033741064835339785f, 0.0029459716752171516f, 0.005033939145505428f, 0.005087935831397772f, 0.00436927005648613f, 0.0049504986964166164f, 0.003950775135308504f, 0.00419924920424819f, 0.007143051829189062f, 0.0025906693190336227f, 0.007238584104925394f, 0.0034588181879371405f, 0.003994812723249197f, 0.003090835874900222f, 0.003068861085921526f, 0.006551634520292282f, 0.0040633357129991055f, 0.004400229547172785f, 0.005083749536424875f, 0.0035802556667476892f, 0.005896489601582289f, 0.004408624488860369f, 0.005602552089840174f, 0.005024862941354513f, 0.005387953948229551f, 0.003303531324490905f, 0.00687263673171401f, 0.004256562329828739f, 0.004811115562915802f, 0.0046509685926139355f, 0.0039627631194889545f, 0.004602131433784962f, 0.005957141984254122f, 0.005328077357262373f, 0.003291043220087886f, 0.003871339373290539f, 0.004722315352410078f, 0.004547292832285166f, 0.006349300034344196f, 0.0035086434800177813f, 0.0038581264670938253f, 0.0037760946433991194f, 0.003529544221237302f, 0.004790240433067083f, 0.006738806143403053f, 0.00573117146268487f, 0.003748428774997592f, 0.00595762487500906f, 0.005307712126523256f, 0.006254236679524183f, 0.004250648431479931f, 0.0038985188584774733f, 0.004254312254488468f, 0.003154350910335779f, 0.003235826501622796f, 0.005031721666455269f, 0.0040800729766488075f, 0.0057658604346215725f, 0.004005961120128632f, 0.0054288748651742935f, 0.003236944554373622f, 0.003934533800929785f, 0.0034902775660157204f, 0.0031796011608093977f, 0.004221450071781874f, 0.00414523109793663f, 0.004090593196451664f, 0.0037342465948313475f, 0.003535711672157049f, 0.0067854980006814f, 0.0036286397371441126f, 0.00382483028806746f, 0.00370930228382349f, 0.00272866222076118f, 0.0032262252643704414f, 0.0036837838124483824f, 0.004550797864794731f, 0.007731306366622448f, 0.003897070186212659f, 0.0039651840925216675f, 0.0029881992377340794f, 0.004031469579786062f, 0.0037828569766134024f, 0.0036071669310331345f, 0.004959518555551767f, 0.004798704292625189f, 0.0036967333871871233f, 0.005142358597368002f, 0.0033181982580572367f, 0.004130849149078131f, 0.003749554045498371f, 0.003148754360154271f, 0.0028965005185455084f, 0.003574782283976674f, 0.003634537337347865f, 0.0029400212224572897f, 0.004470174200832844f, 0.005202011670917273f, 0.004307442344725132f, 0.004815757740288973f, 0.005421479232609272f, 0.005112720187753439f, 0.004378057550638914f, 0.00267143826931715f, 0.006100854370743036f, 0.0048065707087516785f, 0.004474498797208071f, 0.004756910726428032f, 0.005273289978504181f, 0.0037248143926262856f, 0.004688875284045935f, 0.00289148255251348f, 0.005590671207755804f, 0.0028786989860236645f, 0.0025452750269323587f, 0.004359336569905281f, 0.0040921964682638645f, 0.003437562147155404f, 0.0032765790820121765f, 0.003034343244507909f, 0.005480192136019468f, 0.0031784833408892155f, 0.005468306131660938f, 0.005592790432274342f, 0.0037404249887913465f, 0.004227860365062952f, 0.0031862633768469095f, 0.0037670538295060396f, 0.005257163196802139f, 0.00526392413303256f, 0.004685179330408573f, 0.003995589446276426f, 0.0038100117817521095f, 0.0032885409891605377f, 0.0037379716522991657f, 0.004939591512084007f, 0.004031651187688112f, 0.005823140032589436f, 0.003647739067673683f, 0.004365416243672371f, 0.005429275333881378f, 0.00578058697283268f, 0.004077211022377014f, 0.0029402594082057476f, 0.0052499729208648205f, 0.0037950531113892794f, 0.0036395846400409937f, 0.0035326334182173014f, 0.004669182933866978f, 0.0026007797569036484f, 0.0035773226991295815f, 0.0029662763699889183f, 0.00483379140496254f, 0.0036489481572061777f, 0.0038863266818225384f, 0.003366720164194703f, 0.005559563171118498f, 0.0030877450481057167f, 0.0036402528639882803f, 0.0039151511155068874f, 0.0059527684934437275f, 0.0025398489087820053f, 0.004037464968860149f, 0.0037743274588137865f, 0.004758196417242289f, 0.0035175983794033527f, 0.003630046034231782f, 0.004390927962958813f, 0.004591823555529118f, 0.004678964149206877f, 0.0030988671351224184f, 0.0036567039787769318f, 0.003761014901101589f, 0.004296842962503433f, 0.006451115477830172f, 0.0055229319259524345f, 0.0036901263520121574f, 0.005176021717488766f, 0.00379524496383965f, 0.0033600791357457638f, 0.00413402309641242f, 0.0048719970509409904f, 0.003198526334017515f, 0.004894573241472244f, 0.005611797329038382f, 0.0044487714767456055f, 0.003623195691034198f, 0.004383492283523083f, 0.003310139523819089f, 0.003525935811921954f, 0.005267820321023464f, 0.004778517410159111f, 0.00402746582403779f, 0.0036616134457290173f, 0.0037582966033369303f, 0.004394928924739361f, 0.0033865224104374647f, 0.00416167126968503f, 0.004292793106287718f, 0.0057276091538369656f, 0.0029878616333007812f, 0.0031381642911583185f, 0.004227994009852409f, 0.0048921070992946625f, 0.005217525642365217f, 0.0037440250162035227f, 0.003871150314807892f, 0.003897873917594552f, 0.00577063811942935f, 0.00583544559776783f, 0.0036429071333259344f, 0.0045854696072638035f, 0.005142784211784601f, 0.0030297618359327316f, 0.005980693269520998f, 0.004031416028738022f, 0.00534810358658433f, 0.003453986020758748f, 0.0037973737344145775f, 0.004977107979357243f, 0.004249221179634333f, 0.003851969027891755f, 0.003709156531840563f, 0.0060903350822627544f, 0.003297340590506792f, 0.006354805547744036f, 0.005626174155622721f, 0.0047013722360134125f, 0.0035569313913583755f, 0.004157479386776686f, 0.005248671397566795f, 0.004205999430269003f, 0.003465519519522786f, 0.0039708358235657215f, 0.0036892739590257406f, 0.004329375922679901f, 0.005633668974041939f, 0.0033963313326239586f, 0.003088137833401561f, 0.006052711978554726f, 0.00521094398573041f, 0.004401497542858124f, 0.0027559958398342133f, 0.005310533102601767f, 0.004014734178781509f, 0.0037497286684811115f, 0.003162187524139881f, 0.005707919597625732f, 0.004599529318511486f, 0.003739223349839449f, 0.003856068477034569f, 0.0031820309814065695f, 0.00528411939740181f, 0.003568072337657213f, 0.0028030057437717915f, 0.004432066343724728f, 0.00530449440702796f, 0.007018738426268101f, 0.0044700028374791145f, 0.004786653444170952f, 0.005429144948720932f, 0.004381153266876936f, 0.004034983925521374f, 0.005089269019663334f, 0.0038324350025504827f, 0.004589388612657785f, 0.0035735645797103643f, 0.0031244417186826468f, 0.0035223178565502167f, 0.0036559151485562325f, 0.003908759448677301f, 0.0030608465895056725f, 0.00451124319806695f, 0.003470032010227442f, 0.004487232305109501f, 0.003363337367773056f, 0.005066481418907642f, 0.0055987234227359295f, 0.0049042245373129845f, 0.0031481836922466755f, 0.00285512488335371f, 0.004988843109458685f, 0.0035502822138369083f, 0.004518279805779457f, 0.004856238141655922f, 0.004348370246589184f, 0.003712849924340844f, 0.003643608884885907f, 0.0035549579188227654f, 0.0056078736670315266f, 0.0032073433976620436f, 0.003939151298254728f, 0.007168308831751347f, 0.003288362640887499f, 0.0047547887079417706f, 0.005573689471930265f, 0.00374968652613461f, 0.006401555147022009f, 0.00460146926343441f, 0.003562325146049261f, 0.004130397457629442f, 0.003699212335050106f, 0.003315792651847005f, 0.007051551248878241f, 0.003129665507003665f, 0.00339496904052794f, 0.0029541829135268927f, 0.005398111417889595f, 0.002700059674680233f, 0.0047278874553740025f, 0.004544068593531847f, 0.004483665805310011f, 0.0032826391980051994f, 0.004133365582674742f, 0.007093938998878002f, 0.005810904782265425f, 0.006482501979917288f, 0.005705543328076601f, 0.004104294814169407f, 0.003965732175856829f, 0.0032805006485432386f, 0.0034107069950550795f, 0.004519371781498194f, 0.003814729629084468f, 0.0032542538829147816f, 0.004337650258094072f, 0.003582336474210024f, 0.005539597477763891f, 0.0032230867072939873f, 0.005059400573372841f, 0.004959241021424532f, 0.0046011838130652905f, 0.00546229025349021f, 0.003128479002043605f, 0.00434864079579711f, 0.003369018668308854f, 0.004321913234889507f, 0.004716636147350073f, 0.004208463244140148f, 0.0054151746444404125f, 0.00584828294813633f, 0.004971463233232498f, 0.00435552466660738f, 0.005135308485478163f, 0.006131199654191732f, 0.003911786247044802f, 0.004060663282871246f, 0.0035852373111993074f, 0.006742917001247406f, 0.003658005967736244f, 0.0030532879754900932f, 0.004052118398249149f, 0.0026943024713546038f, 0.0034536311868578196f, 0.004187901969999075f, 0.003537532640621066f, 0.004726568702608347f, 0.00450937682762742f, 0.006034632679075003f, 0.00820967648178339f, 0.004054291173815727f, 0.004297629464417696f, 0.00480863731354475f, 0.005655613727867603f, 0.004841495770961046f, 0.004503573756664991f, 0.004079200327396393f, 0.0037537026219069958f, 0.004430856555700302f, 0.003731661709025502f, 0.0033099662978202105f, 0.003665114752948284f, 0.004563286434859037f, 0.003576752031221986f, 0.004430676344782114f, 0.0035690381191670895f, 0.003904546843841672f, 0.0033943583257496357f, 0.004661492072045803f, 0.002985313069075346f, 0.0034633914474397898f, 0.003860695054754615f, 0.0037102296482771635f, 0.003851100569590926f, 0.00377218727953732f, 0.004770273342728615f, 0.0044125718995928764f, 0.0029918404761701822f, 0.00492099579423666f, 0.005190072115510702f, 0.004953610710799694f, 0.004410350229591131f, 0.0042709242552518845f, 0.0039638313464820385f, 0.0037489314563572407f, 0.004321864806115627f, 0.0047492459416389465f, 0.003996395971626043f, 0.003688566852360964f, 0.0048216222785413265f, 0.005554851144552231f, 0.0037170122377574444f, 0.004436313174664974f, 0.004662719089537859f, 0.004137431737035513f, 0.005740359425544739f, 0.0033126131165772676f, 0.0029885652475059032f, 0.004761152435094118f, 0.004374256823211908f, 0.006091950926929712f, 0.003982179332524538f, 0.004959600977599621f, 0.0046338182874023914f, 0.008189653977751732f, 0.006328101735562086f, 0.0040049864910542965f, 0.004179129842668772f, 0.0035555399954319f, 0.0030381667893379927f, 0.0029084431007504463f, 0.004367615096271038f, 0.003824724815785885f, 0.0047547100111842155f, 0.005100524052977562f, 0.005407667253166437f, 0.004260479938238859f, 0.0034073754213750362f, 0.003998067229986191f, 0.004612107295542955f, 0.00455879420042038f, 0.004847715143114328f, 0.0047809891402721405f, 0.003550120396539569f, 0.003710942342877388f, 0.0047002858482301235f, 0.004456451162695885f, 0.005701753776520491f, 0.0068531096912920475f, 0.0033065853640437126f, 0.0041232337243855f, 0.0046081459149718285f, 0.006935573648661375f, 0.005894080735743046f, 0.00472837733104825f, 0.004668479785323143f, 0.005993026774376631f, 0.004521374125033617f, 0.005635865963995457f, 0.00626393174752593f, 0.003306497121229768f, 0.003285785438492894f, 0.003113797400146723f, 0.004394153598695993f, 0.004007452167570591f, 0.0036235481966286898f, 0.003506237408146262f, 0.005356850102543831f, 0.005452018231153488f, 0.004425255581736565f, 0.002663878258317709f, 0.004174708854407072f, 0.004097133409231901f, 0.0031297283712774515f, 0.00386870838701725f, 0.003241230035200715f, 0.003795618424192071f, 0.0041794003918766975f, 0.003427055198699236f, 0.004642973653972149f, 0.003832451067864895f, 0.005941404029726982f, 0.003740921849384904f, 0.004519682843238115f, 0.003031573025509715f, 0.004159032832831144f, 0.0031356182880699635f, 0.004004137124866247f, 0.0038487801793962717f, 0.004083083476871252f, 0.003969112411141396f, 0.003518390003591776f, 0.0028762398287653923f, 0.003920745104551315f, 0.004019409883767366f, 0.010287570767104626f, 0.003710725111886859f, 0.0033415118232369423f, 0.004324136767536402f, 0.005961296614259481f, 0.004169884137809277f, 0.004708444233983755f, 0.0034479086752980947f, 0.003922796342521906f, 0.006298384629189968f, 0.0029714428819715977f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #124 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_54_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 720,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00015744678967166692f, 0.00017316042794845998f, 0.00019097102631349117f, 0.000198410329176113f, 0.0002217303408542648f, 0.00018685971735976636f, 0.00015928252832964063f, 0.00015531558892689645f, 0.00024832875351421535f, 0.00023387465626001358f, 0.00015530455857515335f, 0.00014281705080065876f, 0.00019631875329650939f, 0.00014838838251307607f, 0.0002519084373489022f, 0.00014880072558298707f, 0.00018058912246488035f, 0.00017867192218545824f, 0.00017044109699781984f, 0.00017223396571353078f, 0.00019251371850259602f, 0.00014480120444204658f, 0.0001916917390190065f, 0.00015004129090812057f, 0.00016244829748757184f, 0.00019959858036600053f, 0.00018898081907536834f, 0.0003105124633293599f, 0.00017251977988053113f, 0.00016908410179894418f, 0.0002265638904646039f, 0.00013773211685474962f, 0.00018192011339124292f, 0.0001661267306189984f, 0.00022186590649653226f, 0.00018188536341767758f, 0.00017816104809753597f, 0.00016380540910176933f, 0.00012971341493539512f, 0.0002375270996708423f, 0.00013222747656982392f, 0.00014813235611654818f, 0.0001723087771097198f, 0.00017492935876362026f, 0.00020744190260302275f, 0.00015970173990353942f, 0.00015658573829568923f, 0.00014302971248980612f, 0.00035607858444564044f, 0.0001461828505853191f, 0.00016200468235183507f, 0.00016215426148846745f, 0.00018483324674889445f, 0.00017496581131126732f, 0.00019796508422587067f, 0.00015403404540847987f, 0.00017983504221774638f, 0.0001652251521591097f, 0.00020045814744662493f, 0.0001761960593285039f, 0.00026239058934152126f, 0.00023805591627024114f, 0.000322593841701746f, 0.00018946337513625622f, 0.0001542531535960734f, 0.0002183931937906891f, 0.00017444898549001664f, 0.0001948276039911434f, 0.0001524046529084444f, 0.00023761480406392366f, 0.00017740909243002534f, 0.0002715779992286116f, 0.00026399362832307816f, 0.0001941436348715797f, 0.00013255493831820786f, 0.00018352399638388306f, 0.0001558661024319008f, 0.0001654932857491076f, 0.0002164436154998839f, 0.0002811021695379168f, 0.00015728837752249092f, 0.0001207048844662495f, 0.00022540451027452946f, 0.00019566791888792068f, 0.00019504324882291257f, 0.00017546722665429115f, 0.00016938573389779776f, 0.00014504666614811867f, 0.0001689209311734885f, 0.00026097410591319203f, 0.00016676020459271967f, 0.0002146954502677545f, 0.0002809869183693081f, 0.0002655886928550899f, 0.00013787166972178966f, 0.00019455334404483438f, 0.00015049081412144005f, 0.00016907874669414014f, 0.0002625816559884697f, 0.0002059455291600898f, 0.0002550845965743065f, 0.00013874497381038964f, 0.00031196072814054787f, 0.00019872639677487314f, 0.00018881252617575228f, 0.00021110540546942502f, 0.00023377987963613123f, 0.00015692779561504722f, 0.00015083406469784677f, 0.00016229634638875723f, 0.000265566079178825f, 0.00027406078879721463f, 0.00017431135347578675f, 0.00036107675987295806f, 0.0002156504342565313f, 0.00013203592970967293f, 0.00013991269224788994f, 0.00013877067249268293f, 0.00017759062757249922f, 0.00013619895617011935f, 0.0002067802706733346f, 0.0001246211031684652f, 0.00016600052185822278f, 0.0001915176399052143f, 0.00023810885613784194f, 0.00023428087297361344f, 0.0001471752766519785f, 0.0003017456620000303f, 0.00014697191363666207f, 0.00019813569088000804f, 0.00015635286399628967f, 0.000141944270581007f, 0.00019889570830855519f, 0.00019919831538572907f, 0.0001765604829415679f, 0.00021226560056675225f, 0.00013258392573334277f, 0.00026920068194158375f, 0.00021794628992211074f, 0.00021145030041225255f, 0.00012676573533099145f, 0.000194333289982751f, 0.00017961167031899095f, 0.0002480059629306197f, 0.00017220815061591566f, 0.00021998758893460035f, 0.0002140103024430573f, 0.00017588968330528587f, 0.0001647128228796646f, 0.00016943439550232142f, 0.0002371345181018114f, 0.0001238411496160552f, 0.00012307538418099284f, 0.0001636002998566255f, 0.00010660442057996988f, 0.00014382648805622011f, 0.00012387448805384338f, 0.00018844414444174618f, 0.00014623446622863412f, 0.0001457790203858167f, 0.00014099017425905913f, 0.00021390027541201562f, 0.00018144924251828343f, 0.00022377258574124426f, 0.00015762208204250783f, 0.00018733227625489235f, 0.00014107636525295675f, 0.00015991486725397408f, 0.00018809965695254505f, 0.00024568443768657744f, 0.00022367415658663958f, 0.00019596646598074585f, 0.00016741649596951902f, 0.0002505648008082062f, 0.00015424421872012317f, 0.00012194988084957004f, 0.000206006268854253f, 0.0003388432087376714f, 0.00016306898032780737f, 0.00020154211961198598f, 0.0002461695985402912f, 0.00016892908024601638f, 0.00023280561435967684f, 0.00019081690697930753f, 0.00018206797540187836f, 0.00021949788788333535f, 0.0001322578900726512f, 0.000233224913245067f, 0.00018796007498167455f, 0.00019606701971497387f, 0.0001797853474272415f, 0.000154495908645913f, 0.00016368656361009926f, 0.000263580383034423f, 0.0001926011755131185f, 0.00016014548600651324f, 0.0002477843372616917f, 0.00024326166021637619f, 0.00015298393554985523f, 0.0002470974577590823f, 0.00019365016487427056f, 0.00022769675706513226f, 0.00014995726814959198f, 0.00017050106544047594f, 0.00015517749125137925f, 0.00022942792566027492f, 0.00025226001162081957f, 0.00015789855387993157f, 0.00018769454618450254f, 0.0001548447326058522f, 0.00022462090419139713f, 9.32272887439467e-05f, 0.00011282471677986905f, 0.00011913295020349324f, 0.00020683006732724607f, 0.00013722600124310702f, 0.00014391654985956848f, 0.0002294596197316423f, 0.0001736464910209179f, 0.00022073408763390034f, 0.0001912803272716701f, 0.000124753758427687f, 0.0001818910095607862f, 0.00011851789167849347f, 0.00014419811486732215f, 0.0001259010605281219f, 0.0002151338558178395f, 0.00021744149853475392f, 0.00018672810983844101f, 0.00021156789443921298f, 0.00016884302021935582f, 0.00017946198931895196f, 0.00030527033959515393f, 0.000110716609924566f, 0.00030935308313928545f, 0.0001478184130974114f, 0.00017072504851967096f, 0.00013209207099862397f, 0.00013115294859744608f, 0.00027999511803500354f, 0.00017365349049214274f, 0.00018805121362674981f, 0.00021726259728893638f, 0.00015300825180020183f, 0.00025199641822837293f, 0.0001884099910967052f, 0.00023943449195940048f, 0.00021474597451742738f, 0.00023026327835395932f, 0.000141181968501769f, 0.00029371370328590274f, 0.00018191135313827544f, 0.00020561112614814192f, 0.00019876696751452982f, 0.00016935534949880093f, 0.00019667982996907085f, 0.000254588492680341f, 0.00022770435316488147f, 0.00014064827701076865f, 0.00016544820391573012f, 0.00020181608851999044f, 0.00019433621491771191f, 0.0002713480207603425f, 0.0001499477803008631f, 0.00016488353139720857f, 0.00016137775673996657f, 0.0001508410059614107f, 0.00020471899188123643f, 0.00028799421852454543f, 0.00024493125965818763f, 0.00016019541362766176f, 0.00025460912729613483f, 0.00022683401766698807f, 0.00026728532975539565f, 0.00018165861547458917f, 0.00016660976689308882f, 0.0001818151940824464f, 0.00013480649795383215f, 0.000138288494781591f, 0.00021503909374587238f, 0.0001743687898851931f, 0.00024641375057399273f, 0.00017120149277616292f, 0.000232012098422274f, 0.00013833626871928573f, 0.00016814892296679318f, 0.00014916287909727544f, 0.00013588560977950692f, 0.00018041077419184148f, 0.00017715342983137816f, 0.00017481838585808873f, 0.00015958931180648506f, 0.0001511045848019421f, 0.00028998966445215046f, 0.00015507602074649185f, 0.0001634605578146875f, 0.00015852328215260059f, 0.00011661397002171725f, 0.0001378781598759815f, 0.00015743270341772586f, 0.00019448601233307272f, 0.00033041040296666324f, 0.00016654784849379212f, 0.00016945881361607462f, 0.00012770573084708303f, 0.0001722916349535808f, 0.00016166675777640194f, 0.00015415834786836058f, 0.00021195337467361242f, 0.00020508070883806795f, 0.00015798612730577588f, 0.00021976734569761902f, 0.0001418087922502309f, 0.0001765387860359624f, 0.00016024350770749152f, 0.0001345673226751387f, 0.0001237868273165077f, 0.00015277434431482106f, 0.0001553280744701624f, 0.00012564675125759095f, 0.00019104042439721525f, 0.00022231672483030707f, 0.00018408580217510462f, 0.00020580951240845025f, 0.0002316960453754291f, 0.00021850070334039629f, 0.00018710365111473948f, 0.00011416841152822599f, 0.0002607302740216255f, 0.00020541688718367368f, 0.0001912252337206155f, 0.00020329459221102297f, 0.00022536292090080678f, 0.00015918620920274407f, 0.000200386974029243f, 0.00012357237574178725f, 0.0002389267465332523f, 0.00012302605318836868f, 0.00010877661406993866f, 0.00018630358681548387f, 0.00017488689627498388f, 0.0001469100097892806f, 0.00014003012620378286f, 0.00012967776274308562f, 0.0002342052321182564f, 0.0001358378358418122f, 0.0002336972684133798f, 0.00023901731765363365f, 0.00015985335630830377f, 0.00018068472854793072f, 0.00013617033255286515f, 0.0001609913888387382f, 0.00022467371309176087f, 0.00022496265592053533f, 0.0002002290275413543f, 0.00017075824143830687f, 0.0001628272730158642f, 0.00014054133498575538f, 0.0001597485097590834f, 0.0002111017529387027f, 0.00017229940567631274f, 0.00024886170285753906f, 0.0001558922667754814f, 0.00018656341126188636f, 0.00023202922602649778f, 0.0002470431209076196f, 0.00017424648103769869f, 0.0001256569375982508f, 0.00022436643484979868f, 0.00016218797827605158f, 0.00015554377750959247f, 0.00015097303548827767f, 0.00019954539311584085f, 0.0001111486999434419f, 0.00015288290160242468f, 0.00012676880578510463f, 0.000206580210942775f, 0.00015594394062645733f, 0.00016608870646450669f, 0.0001438824547221884f, 0.0002375972835579887f, 0.00013195998326409608f, 0.00015557232836727053f, 0.00016732056974433362f, 0.00025440158788114786f, 0.0001085447147488594f, 0.00017254786507692188f, 0.00016130223229993135f, 0.00020334952569101006f, 0.0001503304811194539f, 0.000155136120156385f, 0.00018765369895845652f, 0.00019623931439127773f, 0.00019996341143269092f, 0.00013243530702311546f, 0.00015627540415152907f, 0.0001607332960702479f, 0.00018363281560596079f, 0.0002756992762442678f, 0.000236031788517721f, 0.00015770376194268465f, 0.00022120600624475628f, 0.00016219618555624038f, 0.00014359863416757435f, 0.00017667443898972124f, 0.00020821299403905869f, 0.00013669440522789955f, 0.0002091778296744451f, 0.0002398296055616811f, 0.0001901257346617058f, 0.00015484336472582072f, 0.00018733591423369944f, 0.00014146437752060592f, 0.0001506867993157357f, 0.00022512917348649353f, 0.000204217983991839f, 0.00017212053353432566f, 0.00015648521366529167f, 0.00016061712813097984f, 0.00018782468396238983f, 0.00014472873590420932f, 0.00017785602540243417f, 0.0001834597351262346f, 0.00024477901752106845f, 0.0001276912953471765f, 0.00013411472900770605f, 0.00018069043289870024f, 0.00020907243015244603f, 0.00022297973919194192f, 0.0001600072137080133f, 0.00016544012760277838f, 0.0001665822055656463f, 0.00024661794304847717f, 0.0002493875799700618f, 0.00015568576054647565f, 0.00019596776110120118f, 0.00021978553559165448f, 0.00012948196672368795f, 0.0002555949904490262f, 0.00017228935030288994f, 0.00022856020950712264f, 0.00014761190686840564f, 0.00016228716413024813f, 0.00021270508295856416f, 0.00018159761384595186f, 0.00016462037456221879f, 0.00015851705393288285f, 0.00026028070715256035f, 0.00014091740013100207f, 0.0002715832961257547f, 0.0002404440165264532f, 0.0002009210584219545f, 0.0001520114456070587f, 0.00017767687677405775f, 0.00022431080287788063f, 0.0001797504664864391f, 0.00014810480934102088f, 0.00016970034630503505f, 0.00015766733849886805f, 0.00018502316379453987f, 0.00024076431873254478f, 0.00014514793292619288f, 0.0001319767616223544f, 0.00025867283693514764f, 0.00022269846522249281f, 0.00018810540495906025f, 0.00011778211774071679f, 0.00022695456573273987f, 0.0001715764228720218f, 0.00016025097284000367f, 0.000135141410282813f, 0.00024393755302298814f, 0.00019656862423289567f, 0.00015980200259946287f, 0.00016479557962156832f, 0.00013598945224657655f, 0.00022582573001272976f, 0.00015248756972141564f, 0.00011979116970906034f, 0.00018941181770060211f, 0.00022669650206808f, 0.00029995760996825993f, 0.00019103309023194015f, 0.0002045656874543056f, 0.00023202365264296532f, 0.0001872359571279958f, 0.00017244182527065277f, 0.0002174984838347882f, 0.00016378556028939784f, 0.00019613525364547968f, 0.0001527222921140492f, 0.00013352827227208763f, 0.0001505321852164343f, 0.00015624168736394495f, 0.00016704741574358195f, 0.00013081042561680079f, 0.00019279557454865426f, 0.0001482976513216272f, 0.00019176943169441074f, 0.0001437378814443946f, 0.00021652461146004498f, 0.00023927087022457272f, 0.00020959028915967792f, 0.00013454293366521597f, 0.00012201856588944793f, 0.0002132066001649946f, 0.00015172729035839438f, 0.00019309628987684846f, 0.00020753951685037464f, 0.00018583492783363909f, 0.0001586748840054497f, 0.0001557157520437613f, 0.0001519271027063951f, 0.00023966192384250462f, 0.00013707121252082288f, 0.00016834626148920506f, 0.00030634974245913327f, 0.00014053370978217572f, 0.0002032039046753198f, 0.00023820099886506796f, 0.00016024916840251535f, 0.000273581244982779f, 0.00019665152649395168f, 0.00015224196249619126f, 0.0001765194901963696f, 0.0001580920652486384f, 0.0001417059829691425f, 0.00030135991983115673f, 0.00013375152775552124f, 0.00014508971071336418f, 0.00012625197996385396f, 0.00023069737653713673f, 0.0001153915945906192f, 0.00020205423061270267f, 0.0001941984228324145f, 0.0001916170003823936f, 0.0001402891066391021f, 0.00017664633924141526f, 0.0003031714295502752f, 0.0002483387943357229f, 0.0002770406426861882f, 0.00024383599520660937f, 0.00017540394037496299f, 0.0001694822421995923f, 0.00014019772061146796f, 0.0001457623002352193f, 0.00019314295786898583f, 0.00016302888980135322f, 0.00013907601532991976f, 0.0001853767898865044f, 0.00015309717855416238f, 0.00023674401745665818f, 0.00013774403487332165f, 0.0002162220043828711f, 0.0002119415148627013f, 0.0001966393319889903f, 0.000233440165175125f, 0.00013370081433095038f, 0.0001858464820543304f, 0.0001439806801499799f, 0.00018470422946847975f, 0.0002015733771258965f, 0.00017985576414503157f, 0.00023142660211306065f, 0.00024993621627800167f, 0.0002124638413079083f, 0.0001861406781245023f, 0.00021946604829281569f, 0.00026202714070677757f, 0.0001671767677180469f, 0.00017353927250951529f, 0.00015322114631999284f, 0.00028816991834901273f, 0.00015633103612344712f, 0.0001304874022025615f, 0.00017317410674877465f, 0.00011514555080793798f, 0.00014759674377273768f, 0.0001789770321920514f, 0.00015118240844458342f, 0.0002019978710450232f, 0.00019271580094937235f, 0.0002579001884441823f, 0.0003508543304633349f, 0.00017326696251984686f, 0.00018366643053013831f, 0.00020550520275719464f, 0.0002417021751170978f, 0.00020690947712864727f, 0.00019246780721005052f, 0.0001743314933264628f, 0.0001604207936907187f, 0.00018936011474579573f, 0.00015947884821798652f, 0.0001414569851476699f, 0.00015663485100958496f, 0.00019501973292790353f, 0.00015285851259250194f, 0.00018935241678263992f, 0.00015252885350491852f, 0.0001668673794483766f, 0.00014506361912935972f, 0.00019921670900657773f, 0.00012758237426169217f, 0.0001480138598708436f, 0.00016499329649377614f, 0.00015856290701776743f, 0.00016458326717838645f, 0.00016121077351272106f, 0.00020386565302032977f, 0.00018857869144994766f, 0.00012786133447661996f, 0.00021030704374425113f, 0.00022180646192282438f, 0.00021170088439248502f, 0.00018848374020308256f, 0.00018252513837069273f, 0.00016940099885687232f, 0.00016021689225453883f, 0.00018470216309651732f, 0.0002029670140473172f, 0.00017079271492548287f, 0.00015763711417093873f, 0.0002060601400444284f, 0.00023739591415505856f, 0.00015885276661720127f, 0.0001895933091873303f, 0.00019926915410906076f, 0.0001768201036611572f, 0.0002453239285387099f, 0.00014157009718474f, 0.0001277213596040383f, 0.00020347586541902274f, 0.00018694122263696045f, 0.0002603497705422342f, 0.00017018512880895287f, 0.00021195689623709768f, 0.00019803401664830744f, 0.0003499986487440765f, 0.00027044207672588527f, 0.00017115984519477934f, 0.00017860214575193822f, 0.0001519519864814356f, 0.00012984116619918495f, 0.0001242972066393122f, 0.00018665738753043115f, 0.0001634560467209667f, 0.0002032005286309868f, 0.00021797948284074664f, 0.00023110576148610562f, 0.00018207878747489303f, 0.00014561992429662496f, 0.0001708641357254237f, 0.00019710617198143154f, 0.0001948277495102957f, 0.0002071752678602934f, 0.0002043236163444817f, 0.00015172036364674568f, 0.0001585933641763404f, 0.0002008746232604608f, 0.00019045393855776638f, 0.00024367404694203287f, 0.00029287918005138636f, 0.00014131248462945223f, 0.00017621333245187998f, 0.00019693687499966472f, 0.00029640342108905315f, 0.000251893448876217f, 0.00020207515626680106f, 0.00019951534341089427f, 0.00025612208992242813f, 0.00019322853768244386f, 0.00024085822224151343f, 0.0002676996518857777f, 0.00014130871568340808f, 0.0001404235663358122f, 0.00013307337940204889f, 0.00018779154925141484f, 0.00017126521561294794f, 0.00015485842595808208f, 0.00014984495646785945f, 0.0002289340045535937f, 0.00023300117754843086f, 0.00018912075029220432f, 0.00011384532263036817f, 0.0001784132036846131f, 0.0001750978990457952f, 0.00013375420530792326f, 0.00016533576126676053f, 0.00013851941912434995f, 0.00016221213445533067f, 0.00017861371452454478f, 0.00014646096678916365f, 0.00019842528854496777f, 0.00016378624422941357f, 0.0002539159031584859f, 0.00015987458755262196f, 0.00019315625831950456f, 0.00012955936836078763f, 0.00017774326261132956f, 0.00013400592433754355f, 0.00017112353816628456f, 0.00016448409587610513f, 0.0001744974433677271f, 0.0001696266990620643f, 0.00015036431432235986f, 0.00012292094470467418f, 0.00016755964315962046f, 0.00017177624977193773f, 0.0004396566655486822f, 0.0001585840800544247f, 0.00014280513278208673f, 0.00018479926802683622f, 0.00025476605514995754f, 0.00017820701759774238f, 0.00020122328714933246f, 0.00014735218428540975f, 0.00016764730389695615f, 0.0002691720728762448f, 0.00012698961654677987f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #125 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(dense_57_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003385048359632492f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #126 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(dense_57_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00015867290494497865f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #127 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_54_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.04687463492155075f),
    AI_PACK_INTQ_ZP(-128)))

/**  Tensor declarations section  *********************************************/
/* Tensor #0 */
AI_TENSOR_OBJ_DECLARE(
  input_1_output, AI_STATIC,
  0, 0x1,
  AI_SHAPE_INIT(4, 1, 3, 32, 32), AI_STRIDE_INIT(4, 1, 1, 3, 96),
  1, &input_1_output_array, &input_1_output_intq)

/* Tensor #1 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_1_output, AI_STATIC,
  1, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 32, 32), AI_STRIDE_INIT(4, 1, 1, 16, 512),
  1, &conv2d_1_output_array, &conv2d_1_output_intq)

/* Tensor #2 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_output, AI_STATIC,
  2, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 32, 32), AI_STRIDE_INIT(4, 1, 1, 16, 512),
  1, &conv2d_3_output_array, &conv2d_3_output_intq)

/* Tensor #3 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_output, AI_STATIC,
  3, 0x1,
  AI_SHAPE_INIT(4, 1, 56, 32, 32), AI_STRIDE_INIT(4, 1, 1, 56, 1792),
  1, &conv2d_4_output_array, &conv2d_4_output_intq)

/* Tensor #4 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_6_output, AI_STATIC,
  4, 0x1,
  AI_SHAPE_INIT(4, 1, 56, 16, 16), AI_STRIDE_INIT(4, 1, 1, 56, 896),
  1, &conv2d_6_output_array, &conv2d_6_output_intq)

/* Tensor #5 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_output, AI_STATIC,
  5, 0x1,
  AI_SHAPE_INIT(4, 1, 104, 16, 16), AI_STRIDE_INIT(4, 1, 1, 104, 1664),
  1, &conv2d_7_output_array, &conv2d_7_output_intq)

/* Tensor #6 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_output, AI_STATIC,
  6, 0x1,
  AI_SHAPE_INIT(4, 1, 104, 16, 16), AI_STRIDE_INIT(4, 1, 1, 104, 1664),
  1, &conv2d_9_output_array, &conv2d_9_output_intq)

/* Tensor #7 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_10_output, AI_STATIC,
  7, 0x1,
  AI_SHAPE_INIT(4, 1, 80, 16, 16), AI_STRIDE_INIT(4, 1, 1, 80, 1280),
  1, &conv2d_10_output_array, &conv2d_10_output_intq)

/* Tensor #8 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_12_output, AI_STATIC,
  8, 0x1,
  AI_SHAPE_INIT(4, 1, 80, 8, 8), AI_STRIDE_INIT(4, 1, 1, 80, 640),
  1, &conv2d_12_output_array, &conv2d_12_output_intq)

/* Tensor #9 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_13_output, AI_STATIC,
  9, 0x1,
  AI_SHAPE_INIT(4, 1, 160, 8, 8), AI_STRIDE_INIT(4, 1, 1, 160, 1280),
  1, &conv2d_13_output_array, &conv2d_13_output_intq)

/* Tensor #10 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_15_output, AI_STATIC,
  10, 0x1,
  AI_SHAPE_INIT(4, 1, 160, 8, 8), AI_STRIDE_INIT(4, 1, 1, 160, 1280),
  1, &conv2d_15_output_array, &conv2d_15_output_intq)

/* Tensor #11 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_16_output, AI_STATIC,
  11, 0x1,
  AI_SHAPE_INIT(4, 1, 104, 8, 8), AI_STRIDE_INIT(4, 1, 1, 104, 832),
  1, &conv2d_16_output_array, &conv2d_16_output_intq)

/* Tensor #12 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_18_output, AI_STATIC,
  12, 0x1,
  AI_SHAPE_INIT(4, 1, 104, 4, 4), AI_STRIDE_INIT(4, 1, 1, 104, 416),
  1, &conv2d_18_output_array, &conv2d_18_output_intq)

/* Tensor #13 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_19_output, AI_STATIC,
  13, 0x1,
  AI_SHAPE_INIT(4, 1, 208, 4, 4), AI_STRIDE_INIT(4, 1, 1, 208, 832),
  1, &conv2d_19_output_array, &conv2d_19_output_intq)

/* Tensor #14 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_21_output, AI_STATIC,
  14, 0x1,
  AI_SHAPE_INIT(4, 1, 208, 4, 4), AI_STRIDE_INIT(4, 1, 1, 208, 832),
  1, &conv2d_21_output_array, &conv2d_21_output_intq)

/* Tensor #15 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_22_output, AI_STATIC,
  15, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 4, 4), AI_STRIDE_INIT(4, 1, 1, 32, 128),
  1, &conv2d_22_output_array, &conv2d_22_output_intq)

/* Tensor #16 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_23_output, AI_STATIC,
  16, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 4, 4), AI_STRIDE_INIT(4, 1, 1, 32, 128),
  1, &conv2d_23_output_array, &conv2d_23_output_intq)

/* Tensor #17 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_24_output, AI_STATIC,
  17, 0x1,
  AI_SHAPE_INIT(4, 1, 160, 4, 4), AI_STRIDE_INIT(4, 1, 1, 160, 640),
  1, &conv2d_24_output_array, &conv2d_24_output_intq)

/* Tensor #18 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_26_output, AI_STATIC,
  18, 0x1,
  AI_SHAPE_INIT(4, 1, 160, 4, 4), AI_STRIDE_INIT(4, 1, 1, 160, 640),
  1, &conv2d_26_output_array, &conv2d_26_output_intq)

/* Tensor #19 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_27_output, AI_STATIC,
  19, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 4, 4), AI_STRIDE_INIT(4, 1, 1, 32, 128),
  1, &conv2d_27_output_array, &conv2d_27_output_intq)

/* Tensor #20 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_28_output, AI_STATIC,
  20, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 4, 4), AI_STRIDE_INIT(4, 1, 1, 32, 128),
  1, &conv2d_28_output_array, &conv2d_28_output_intq)

/* Tensor #21 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_29_output, AI_STATIC,
  21, 0x1,
  AI_SHAPE_INIT(4, 1, 160, 4, 4), AI_STRIDE_INIT(4, 1, 1, 160, 640),
  1, &conv2d_29_output_array, &conv2d_29_output_intq)

/* Tensor #22 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_31_output, AI_STATIC,
  22, 0x1,
  AI_SHAPE_INIT(4, 1, 160, 4, 4), AI_STRIDE_INIT(4, 1, 1, 160, 640),
  1, &conv2d_31_output_array, &conv2d_31_output_intq)

/* Tensor #23 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_32_output, AI_STATIC,
  23, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 4, 4), AI_STRIDE_INIT(4, 1, 1, 32, 128),
  1, &conv2d_32_output_array, &conv2d_32_output_intq)

/* Tensor #24 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_33_output, AI_STATIC,
  24, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 4, 4), AI_STRIDE_INIT(4, 1, 1, 32, 128),
  1, &conv2d_33_output_array, &conv2d_33_output_intq)

/* Tensor #25 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_34_output, AI_STATIC,
  25, 0x1,
  AI_SHAPE_INIT(4, 1, 160, 4, 4), AI_STRIDE_INIT(4, 1, 1, 160, 640),
  1, &conv2d_34_output_array, &conv2d_34_output_intq)

/* Tensor #26 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_36_output, AI_STATIC,
  26, 0x1,
  AI_SHAPE_INIT(4, 1, 160, 4, 4), AI_STRIDE_INIT(4, 1, 1, 160, 640),
  1, &conv2d_36_output_array, &conv2d_36_output_intq)

/* Tensor #27 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_37_output, AI_STATIC,
  27, 0x1,
  AI_SHAPE_INIT(4, 1, 40, 4, 4), AI_STRIDE_INIT(4, 1, 1, 40, 160),
  1, &conv2d_37_output_array, &conv2d_37_output_intq)

/* Tensor #28 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_38_output, AI_STATIC,
  28, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 4, 4), AI_STRIDE_INIT(4, 1, 1, 32, 128),
  1, &conv2d_38_output_array, &conv2d_38_output_intq)

/* Tensor #29 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_39_output, AI_STATIC,
  29, 0x1,
  AI_SHAPE_INIT(4, 1, 208, 4, 4), AI_STRIDE_INIT(4, 1, 1, 208, 832),
  1, &conv2d_39_output_array, &conv2d_39_output_intq)

/* Tensor #30 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_41_output, AI_STATIC,
  30, 0x1,
  AI_SHAPE_INIT(4, 1, 208, 4, 4), AI_STRIDE_INIT(4, 1, 1, 208, 832),
  1, &conv2d_41_output_array, &conv2d_41_output_intq)

/* Tensor #31 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_42_output, AI_STATIC,
  31, 0x1,
  AI_SHAPE_INIT(4, 1, 40, 4, 4), AI_STRIDE_INIT(4, 1, 1, 40, 160),
  1, &conv2d_42_output_array, &conv2d_42_output_intq)

/* Tensor #32 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_43_output, AI_STATIC,
  32, 0x1,
  AI_SHAPE_INIT(4, 1, 40, 4, 4), AI_STRIDE_INIT(4, 1, 1, 40, 160),
  1, &conv2d_43_output_array, &conv2d_43_output_intq)

/* Tensor #33 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_44_output, AI_STATIC,
  33, 0x1,
  AI_SHAPE_INIT(4, 1, 208, 4, 4), AI_STRIDE_INIT(4, 1, 1, 208, 832),
  1, &conv2d_44_output_array, &conv2d_44_output_intq)

/* Tensor #34 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_46_output, AI_STATIC,
  34, 0x1,
  AI_SHAPE_INIT(4, 1, 208, 2, 2), AI_STRIDE_INIT(4, 1, 1, 208, 416),
  1, &conv2d_46_output_array, &conv2d_46_output_intq)

/* Tensor #35 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_47_output, AI_STATIC,
  35, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 2, 2), AI_STRIDE_INIT(4, 1, 1, 48, 96),
  1, &conv2d_47_output_array, &conv2d_47_output_intq)

/* Tensor #36 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_48_output, AI_STATIC,
  36, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 2, 2), AI_STRIDE_INIT(4, 1, 1, 48, 96),
  1, &conv2d_48_output_array, &conv2d_48_output_intq)

/* Tensor #37 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_49_output, AI_STATIC,
  37, 0x1,
  AI_SHAPE_INIT(4, 1, 208, 2, 2), AI_STRIDE_INIT(4, 1, 1, 208, 416),
  1, &conv2d_49_output_array, &conv2d_49_output_intq)

/* Tensor #38 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_51_output, AI_STATIC,
  38, 0x1,
  AI_SHAPE_INIT(4, 1, 208, 2, 2), AI_STRIDE_INIT(4, 1, 1, 208, 416),
  1, &conv2d_51_output_array, &conv2d_51_output_intq)

/* Tensor #39 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_52_output, AI_STATIC,
  39, 0x1,
  AI_SHAPE_INIT(4, 1, 120, 2, 2), AI_STRIDE_INIT(4, 1, 1, 120, 240),
  1, &conv2d_52_output_array, &conv2d_52_output_intq)

/* Tensor #40 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_53_output, AI_STATIC,
  40, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 2, 2), AI_STRIDE_INIT(4, 1, 1, 96, 192),
  1, &conv2d_53_output_array, &conv2d_53_output_intq)

/* Tensor #41 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_54_output, AI_STATIC,
  41, 0x1,
  AI_SHAPE_INIT(4, 1, 720, 1, 1), AI_STRIDE_INIT(4, 1, 1, 720, 720),
  1, &conv2d_54_output_array, &conv2d_54_output_intq)

/* Tensor #42 */
AI_TENSOR_OBJ_DECLARE(
  dense_57_output, AI_STATIC,
  42, 0x1,
  AI_SHAPE_INIT(4, 1, 100, 1, 1), AI_STRIDE_INIT(4, 1, 1, 100, 100),
  1, &dense_57_output_array, &dense_57_output_intq)

/* Tensor #43 */
AI_TENSOR_OBJ_DECLARE(
  dense_57_fmt_output, AI_STATIC,
  43, 0x0,
  AI_SHAPE_INIT(4, 1, 100, 1, 1), AI_STRIDE_INIT(4, 4, 4, 400, 400),
  1, &dense_57_fmt_output_array, NULL)

/* Tensor #44 */
AI_TENSOR_OBJ_DECLARE(
  nl_58_output, AI_STATIC,
  44, 0x0,
  AI_SHAPE_INIT(4, 1, 100, 1, 1), AI_STRIDE_INIT(4, 4, 4, 400, 400),
  1, &nl_58_output_array, NULL)

/* Tensor #45 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_1_weights, AI_STATIC,
  45, 0x1,
  AI_SHAPE_INIT(4, 3, 3, 3, 16), AI_STRIDE_INIT(4, 1, 3, 9, 27),
  1, &conv2d_1_weights_array, &conv2d_1_weights_intq)

/* Tensor #46 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_1_bias, AI_STATIC,
  46, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv2d_1_bias_array, &conv2d_1_bias_intq)

/* Tensor #47 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_weights, AI_STATIC,
  47, 0x1,
  AI_SHAPE_INIT(4, 16, 3, 3, 1), AI_STRIDE_INIT(4, 1, 16, 48, 144),
  1, &conv2d_3_weights_array, &conv2d_3_weights_intq)

/* Tensor #48 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_bias, AI_STATIC,
  48, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv2d_3_bias_array, &conv2d_3_bias_intq)

/* Tensor #49 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_weights, AI_STATIC,
  49, 0x1,
  AI_SHAPE_INIT(4, 16, 1, 1, 56), AI_STRIDE_INIT(4, 1, 16, 16, 16),
  1, &conv2d_4_weights_array, &conv2d_4_weights_intq)

/* Tensor #50 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_bias, AI_STATIC,
  50, 0x1,
  AI_SHAPE_INIT(4, 1, 56, 1, 1), AI_STRIDE_INIT(4, 4, 4, 224, 224),
  1, &conv2d_4_bias_array, &conv2d_4_bias_intq)

/* Tensor #51 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_6_weights, AI_STATIC,
  51, 0x1,
  AI_SHAPE_INIT(4, 56, 3, 3, 1), AI_STRIDE_INIT(4, 1, 56, 168, 504),
  1, &conv2d_6_weights_array, &conv2d_6_weights_intq)

/* Tensor #52 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_6_bias, AI_STATIC,
  52, 0x1,
  AI_SHAPE_INIT(4, 1, 56, 1, 1), AI_STRIDE_INIT(4, 4, 4, 224, 224),
  1, &conv2d_6_bias_array, &conv2d_6_bias_intq)

/* Tensor #53 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_weights, AI_STATIC,
  53, 0x1,
  AI_SHAPE_INIT(4, 56, 1, 1, 104), AI_STRIDE_INIT(4, 1, 56, 56, 56),
  1, &conv2d_7_weights_array, &conv2d_7_weights_intq)

/* Tensor #54 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_bias, AI_STATIC,
  54, 0x1,
  AI_SHAPE_INIT(4, 1, 104, 1, 1), AI_STRIDE_INIT(4, 4, 4, 416, 416),
  1, &conv2d_7_bias_array, &conv2d_7_bias_intq)

/* Tensor #55 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_weights, AI_STATIC,
  55, 0x1,
  AI_SHAPE_INIT(4, 104, 3, 3, 1), AI_STRIDE_INIT(4, 1, 104, 312, 936),
  1, &conv2d_9_weights_array, &conv2d_9_weights_intq)

/* Tensor #56 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_bias, AI_STATIC,
  56, 0x1,
  AI_SHAPE_INIT(4, 1, 104, 1, 1), AI_STRIDE_INIT(4, 4, 4, 416, 416),
  1, &conv2d_9_bias_array, &conv2d_9_bias_intq)

/* Tensor #57 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_10_weights, AI_STATIC,
  57, 0x1,
  AI_SHAPE_INIT(4, 104, 1, 1, 80), AI_STRIDE_INIT(4, 1, 104, 104, 104),
  1, &conv2d_10_weights_array, &conv2d_10_weights_intq)

/* Tensor #58 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_10_bias, AI_STATIC,
  58, 0x1,
  AI_SHAPE_INIT(4, 1, 80, 1, 1), AI_STRIDE_INIT(4, 4, 4, 320, 320),
  1, &conv2d_10_bias_array, &conv2d_10_bias_intq)

/* Tensor #59 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_12_weights, AI_STATIC,
  59, 0x1,
  AI_SHAPE_INIT(4, 80, 3, 3, 1), AI_STRIDE_INIT(4, 1, 80, 240, 720),
  1, &conv2d_12_weights_array, &conv2d_12_weights_intq)

/* Tensor #60 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_12_bias, AI_STATIC,
  60, 0x1,
  AI_SHAPE_INIT(4, 1, 80, 1, 1), AI_STRIDE_INIT(4, 4, 4, 320, 320),
  1, &conv2d_12_bias_array, &conv2d_12_bias_intq)

/* Tensor #61 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_13_weights, AI_STATIC,
  61, 0x1,
  AI_SHAPE_INIT(4, 80, 1, 1, 160), AI_STRIDE_INIT(4, 1, 80, 80, 80),
  1, &conv2d_13_weights_array, &conv2d_13_weights_intq)

/* Tensor #62 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_13_bias, AI_STATIC,
  62, 0x1,
  AI_SHAPE_INIT(4, 1, 160, 1, 1), AI_STRIDE_INIT(4, 4, 4, 640, 640),
  1, &conv2d_13_bias_array, &conv2d_13_bias_intq)

/* Tensor #63 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_15_weights, AI_STATIC,
  63, 0x1,
  AI_SHAPE_INIT(4, 160, 3, 3, 1), AI_STRIDE_INIT(4, 1, 160, 480, 1440),
  1, &conv2d_15_weights_array, &conv2d_15_weights_intq)

/* Tensor #64 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_15_bias, AI_STATIC,
  64, 0x1,
  AI_SHAPE_INIT(4, 1, 160, 1, 1), AI_STRIDE_INIT(4, 4, 4, 640, 640),
  1, &conv2d_15_bias_array, &conv2d_15_bias_intq)

/* Tensor #65 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_16_weights, AI_STATIC,
  65, 0x1,
  AI_SHAPE_INIT(4, 160, 1, 1, 104), AI_STRIDE_INIT(4, 1, 160, 160, 160),
  1, &conv2d_16_weights_array, &conv2d_16_weights_intq)

/* Tensor #66 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_16_bias, AI_STATIC,
  66, 0x1,
  AI_SHAPE_INIT(4, 1, 104, 1, 1), AI_STRIDE_INIT(4, 4, 4, 416, 416),
  1, &conv2d_16_bias_array, &conv2d_16_bias_intq)

/* Tensor #67 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_18_weights, AI_STATIC,
  67, 0x1,
  AI_SHAPE_INIT(4, 104, 3, 3, 1), AI_STRIDE_INIT(4, 1, 104, 312, 936),
  1, &conv2d_18_weights_array, &conv2d_18_weights_intq)

/* Tensor #68 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_18_bias, AI_STATIC,
  68, 0x1,
  AI_SHAPE_INIT(4, 1, 104, 1, 1), AI_STRIDE_INIT(4, 4, 4, 416, 416),
  1, &conv2d_18_bias_array, &conv2d_18_bias_intq)

/* Tensor #69 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_19_weights, AI_STATIC,
  69, 0x1,
  AI_SHAPE_INIT(4, 104, 1, 1, 208), AI_STRIDE_INIT(4, 1, 104, 104, 104),
  1, &conv2d_19_weights_array, &conv2d_19_weights_intq)

/* Tensor #70 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_19_bias, AI_STATIC,
  70, 0x1,
  AI_SHAPE_INIT(4, 1, 208, 1, 1), AI_STRIDE_INIT(4, 4, 4, 832, 832),
  1, &conv2d_19_bias_array, &conv2d_19_bias_intq)

/* Tensor #71 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_21_weights, AI_STATIC,
  71, 0x1,
  AI_SHAPE_INIT(4, 208, 3, 3, 1), AI_STRIDE_INIT(4, 1, 208, 624, 1872),
  1, &conv2d_21_weights_array, &conv2d_21_weights_intq)

/* Tensor #72 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_21_bias, AI_STATIC,
  72, 0x1,
  AI_SHAPE_INIT(4, 1, 208, 1, 1), AI_STRIDE_INIT(4, 4, 4, 832, 832),
  1, &conv2d_21_bias_array, &conv2d_21_bias_intq)

/* Tensor #73 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_22_weights, AI_STATIC,
  73, 0x1,
  AI_SHAPE_INIT(4, 208, 1, 1, 32), AI_STRIDE_INIT(4, 1, 208, 208, 208),
  1, &conv2d_22_weights_array, &conv2d_22_weights_intq)

/* Tensor #74 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_22_bias, AI_STATIC,
  74, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_22_bias_array, &conv2d_22_bias_intq)

/* Tensor #75 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_23_weights, AI_STATIC,
  75, 0x1,
  AI_SHAPE_INIT(4, 32, 1, 1, 32), AI_STRIDE_INIT(4, 1, 32, 32, 32),
  1, &conv2d_23_weights_array, &conv2d_23_weights_intq)

/* Tensor #76 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_23_bias, AI_STATIC,
  76, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_23_bias_array, &conv2d_23_bias_intq)

/* Tensor #77 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_24_weights, AI_STATIC,
  77, 0x1,
  AI_SHAPE_INIT(4, 32, 1, 1, 160), AI_STRIDE_INIT(4, 1, 32, 32, 32),
  1, &conv2d_24_weights_array, &conv2d_24_weights_intq)

/* Tensor #78 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_24_bias, AI_STATIC,
  78, 0x1,
  AI_SHAPE_INIT(4, 1, 160, 1, 1), AI_STRIDE_INIT(4, 4, 4, 640, 640),
  1, &conv2d_24_bias_array, &conv2d_24_bias_intq)

/* Tensor #79 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_26_weights, AI_STATIC,
  79, 0x1,
  AI_SHAPE_INIT(4, 160, 3, 3, 1), AI_STRIDE_INIT(4, 1, 160, 480, 1440),
  1, &conv2d_26_weights_array, &conv2d_26_weights_intq)

/* Tensor #80 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_26_bias, AI_STATIC,
  80, 0x1,
  AI_SHAPE_INIT(4, 1, 160, 1, 1), AI_STRIDE_INIT(4, 4, 4, 640, 640),
  1, &conv2d_26_bias_array, &conv2d_26_bias_intq)

/* Tensor #81 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_27_weights, AI_STATIC,
  81, 0x1,
  AI_SHAPE_INIT(4, 160, 1, 1, 32), AI_STRIDE_INIT(4, 1, 160, 160, 160),
  1, &conv2d_27_weights_array, &conv2d_27_weights_intq)

/* Tensor #82 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_27_bias, AI_STATIC,
  82, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_27_bias_array, &conv2d_27_bias_intq)

/* Tensor #83 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_28_weights, AI_STATIC,
  83, 0x1,
  AI_SHAPE_INIT(4, 32, 1, 1, 32), AI_STRIDE_INIT(4, 1, 32, 32, 32),
  1, &conv2d_28_weights_array, &conv2d_28_weights_intq)

/* Tensor #84 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_28_bias, AI_STATIC,
  84, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_28_bias_array, &conv2d_28_bias_intq)

/* Tensor #85 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_29_weights, AI_STATIC,
  85, 0x1,
  AI_SHAPE_INIT(4, 32, 1, 1, 160), AI_STRIDE_INIT(4, 1, 32, 32, 32),
  1, &conv2d_29_weights_array, &conv2d_29_weights_intq)

/* Tensor #86 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_29_bias, AI_STATIC,
  86, 0x1,
  AI_SHAPE_INIT(4, 1, 160, 1, 1), AI_STRIDE_INIT(4, 4, 4, 640, 640),
  1, &conv2d_29_bias_array, &conv2d_29_bias_intq)

/* Tensor #87 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_31_weights, AI_STATIC,
  87, 0x1,
  AI_SHAPE_INIT(4, 160, 3, 3, 1), AI_STRIDE_INIT(4, 1, 160, 480, 1440),
  1, &conv2d_31_weights_array, &conv2d_31_weights_intq)

/* Tensor #88 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_31_bias, AI_STATIC,
  88, 0x1,
  AI_SHAPE_INIT(4, 1, 160, 1, 1), AI_STRIDE_INIT(4, 4, 4, 640, 640),
  1, &conv2d_31_bias_array, &conv2d_31_bias_intq)

/* Tensor #89 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_32_weights, AI_STATIC,
  89, 0x1,
  AI_SHAPE_INIT(4, 160, 1, 1, 32), AI_STRIDE_INIT(4, 1, 160, 160, 160),
  1, &conv2d_32_weights_array, &conv2d_32_weights_intq)

/* Tensor #90 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_32_bias, AI_STATIC,
  90, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_32_bias_array, &conv2d_32_bias_intq)

/* Tensor #91 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_33_weights, AI_STATIC,
  91, 0x1,
  AI_SHAPE_INIT(4, 32, 1, 1, 32), AI_STRIDE_INIT(4, 1, 32, 32, 32),
  1, &conv2d_33_weights_array, &conv2d_33_weights_intq)

/* Tensor #92 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_33_bias, AI_STATIC,
  92, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_33_bias_array, &conv2d_33_bias_intq)

/* Tensor #93 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_34_weights, AI_STATIC,
  93, 0x1,
  AI_SHAPE_INIT(4, 32, 1, 1, 160), AI_STRIDE_INIT(4, 1, 32, 32, 32),
  1, &conv2d_34_weights_array, &conv2d_34_weights_intq)

/* Tensor #94 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_34_bias, AI_STATIC,
  94, 0x1,
  AI_SHAPE_INIT(4, 1, 160, 1, 1), AI_STRIDE_INIT(4, 4, 4, 640, 640),
  1, &conv2d_34_bias_array, &conv2d_34_bias_intq)

/* Tensor #95 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_36_weights, AI_STATIC,
  95, 0x1,
  AI_SHAPE_INIT(4, 160, 3, 3, 1), AI_STRIDE_INIT(4, 1, 160, 480, 1440),
  1, &conv2d_36_weights_array, &conv2d_36_weights_intq)

/* Tensor #96 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_36_bias, AI_STATIC,
  96, 0x1,
  AI_SHAPE_INIT(4, 1, 160, 1, 1), AI_STRIDE_INIT(4, 4, 4, 640, 640),
  1, &conv2d_36_bias_array, &conv2d_36_bias_intq)

/* Tensor #97 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_37_weights, AI_STATIC,
  97, 0x1,
  AI_SHAPE_INIT(4, 160, 1, 1, 40), AI_STRIDE_INIT(4, 1, 160, 160, 160),
  1, &conv2d_37_weights_array, &conv2d_37_weights_intq)

/* Tensor #98 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_37_bias, AI_STATIC,
  98, 0x1,
  AI_SHAPE_INIT(4, 1, 40, 1, 1), AI_STRIDE_INIT(4, 4, 4, 160, 160),
  1, &conv2d_37_bias_array, &conv2d_37_bias_intq)

/* Tensor #99 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_38_weights, AI_STATIC,
  99, 0x1,
  AI_SHAPE_INIT(4, 40, 1, 1, 32), AI_STRIDE_INIT(4, 1, 40, 40, 40),
  1, &conv2d_38_weights_array, &conv2d_38_weights_intq)

/* Tensor #100 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_38_bias, AI_STATIC,
  100, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_38_bias_array, &conv2d_38_bias_intq)

/* Tensor #101 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_39_weights, AI_STATIC,
  101, 0x1,
  AI_SHAPE_INIT(4, 32, 1, 1, 208), AI_STRIDE_INIT(4, 1, 32, 32, 32),
  1, &conv2d_39_weights_array, &conv2d_39_weights_intq)

/* Tensor #102 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_39_bias, AI_STATIC,
  102, 0x1,
  AI_SHAPE_INIT(4, 1, 208, 1, 1), AI_STRIDE_INIT(4, 4, 4, 832, 832),
  1, &conv2d_39_bias_array, &conv2d_39_bias_intq)

/* Tensor #103 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_41_weights, AI_STATIC,
  103, 0x1,
  AI_SHAPE_INIT(4, 208, 3, 3, 1), AI_STRIDE_INIT(4, 1, 208, 624, 1872),
  1, &conv2d_41_weights_array, &conv2d_41_weights_intq)

/* Tensor #104 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_41_bias, AI_STATIC,
  104, 0x1,
  AI_SHAPE_INIT(4, 1, 208, 1, 1), AI_STRIDE_INIT(4, 4, 4, 832, 832),
  1, &conv2d_41_bias_array, &conv2d_41_bias_intq)

/* Tensor #105 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_42_weights, AI_STATIC,
  105, 0x1,
  AI_SHAPE_INIT(4, 208, 1, 1, 40), AI_STRIDE_INIT(4, 1, 208, 208, 208),
  1, &conv2d_42_weights_array, &conv2d_42_weights_intq)

/* Tensor #106 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_42_bias, AI_STATIC,
  106, 0x1,
  AI_SHAPE_INIT(4, 1, 40, 1, 1), AI_STRIDE_INIT(4, 4, 4, 160, 160),
  1, &conv2d_42_bias_array, &conv2d_42_bias_intq)

/* Tensor #107 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_43_weights, AI_STATIC,
  107, 0x1,
  AI_SHAPE_INIT(4, 40, 1, 1, 40), AI_STRIDE_INIT(4, 1, 40, 40, 40),
  1, &conv2d_43_weights_array, &conv2d_43_weights_intq)

/* Tensor #108 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_43_bias, AI_STATIC,
  108, 0x1,
  AI_SHAPE_INIT(4, 1, 40, 1, 1), AI_STRIDE_INIT(4, 4, 4, 160, 160),
  1, &conv2d_43_bias_array, &conv2d_43_bias_intq)

/* Tensor #109 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_44_weights, AI_STATIC,
  109, 0x1,
  AI_SHAPE_INIT(4, 40, 1, 1, 208), AI_STRIDE_INIT(4, 1, 40, 40, 40),
  1, &conv2d_44_weights_array, &conv2d_44_weights_intq)

/* Tensor #110 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_44_bias, AI_STATIC,
  110, 0x1,
  AI_SHAPE_INIT(4, 1, 208, 1, 1), AI_STRIDE_INIT(4, 4, 4, 832, 832),
  1, &conv2d_44_bias_array, &conv2d_44_bias_intq)

/* Tensor #111 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_46_weights, AI_STATIC,
  111, 0x1,
  AI_SHAPE_INIT(4, 208, 3, 3, 1), AI_STRIDE_INIT(4, 1, 208, 624, 1872),
  1, &conv2d_46_weights_array, &conv2d_46_weights_intq)

/* Tensor #112 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_46_bias, AI_STATIC,
  112, 0x1,
  AI_SHAPE_INIT(4, 1, 208, 1, 1), AI_STRIDE_INIT(4, 4, 4, 832, 832),
  1, &conv2d_46_bias_array, &conv2d_46_bias_intq)

/* Tensor #113 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_47_weights, AI_STATIC,
  113, 0x1,
  AI_SHAPE_INIT(4, 208, 1, 1, 48), AI_STRIDE_INIT(4, 1, 208, 208, 208),
  1, &conv2d_47_weights_array, &conv2d_47_weights_intq)

/* Tensor #114 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_47_bias, AI_STATIC,
  114, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &conv2d_47_bias_array, &conv2d_47_bias_intq)

/* Tensor #115 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_48_weights, AI_STATIC,
  115, 0x1,
  AI_SHAPE_INIT(4, 48, 1, 1, 48), AI_STRIDE_INIT(4, 1, 48, 48, 48),
  1, &conv2d_48_weights_array, &conv2d_48_weights_intq)

/* Tensor #116 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_48_bias, AI_STATIC,
  116, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &conv2d_48_bias_array, &conv2d_48_bias_intq)

/* Tensor #117 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_49_weights, AI_STATIC,
  117, 0x1,
  AI_SHAPE_INIT(4, 48, 1, 1, 208), AI_STRIDE_INIT(4, 1, 48, 48, 48),
  1, &conv2d_49_weights_array, &conv2d_49_weights_intq)

/* Tensor #118 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_49_bias, AI_STATIC,
  118, 0x1,
  AI_SHAPE_INIT(4, 1, 208, 1, 1), AI_STRIDE_INIT(4, 4, 4, 832, 832),
  1, &conv2d_49_bias_array, &conv2d_49_bias_intq)

/* Tensor #119 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_51_weights, AI_STATIC,
  119, 0x1,
  AI_SHAPE_INIT(4, 208, 3, 3, 1), AI_STRIDE_INIT(4, 1, 208, 624, 1872),
  1, &conv2d_51_weights_array, &conv2d_51_weights_intq)

/* Tensor #120 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_51_bias, AI_STATIC,
  120, 0x1,
  AI_SHAPE_INIT(4, 1, 208, 1, 1), AI_STRIDE_INIT(4, 4, 4, 832, 832),
  1, &conv2d_51_bias_array, &conv2d_51_bias_intq)

/* Tensor #121 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_52_weights, AI_STATIC,
  121, 0x1,
  AI_SHAPE_INIT(4, 208, 1, 1, 120), AI_STRIDE_INIT(4, 1, 208, 208, 208),
  1, &conv2d_52_weights_array, &conv2d_52_weights_intq)

/* Tensor #122 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_52_bias, AI_STATIC,
  122, 0x1,
  AI_SHAPE_INIT(4, 1, 120, 1, 1), AI_STRIDE_INIT(4, 4, 4, 480, 480),
  1, &conv2d_52_bias_array, &conv2d_52_bias_intq)

/* Tensor #123 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_53_weights, AI_STATIC,
  123, 0x1,
  AI_SHAPE_INIT(4, 120, 1, 1, 96), AI_STRIDE_INIT(4, 1, 120, 120, 120),
  1, &conv2d_53_weights_array, &conv2d_53_weights_intq)

/* Tensor #124 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_53_bias, AI_STATIC,
  124, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &conv2d_53_bias_array, &conv2d_53_bias_intq)

/* Tensor #125 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_54_weights, AI_STATIC,
  125, 0x1,
  AI_SHAPE_INIT(4, 96, 1, 1, 720), AI_STRIDE_INIT(4, 1, 96, 96, 96),
  1, &conv2d_54_weights_array, &conv2d_54_weights_intq)

/* Tensor #126 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_54_bias, AI_STATIC,
  126, 0x1,
  AI_SHAPE_INIT(4, 1, 720, 1, 1), AI_STRIDE_INIT(4, 4, 4, 2880, 2880),
  1, &conv2d_54_bias_array, &conv2d_54_bias_intq)

/* Tensor #127 */
AI_TENSOR_OBJ_DECLARE(
  dense_57_weights, AI_STATIC,
  127, 0x1,
  AI_SHAPE_INIT(4, 720, 100, 1, 1), AI_STRIDE_INIT(4, 1, 720, 72000, 72000),
  1, &dense_57_weights_array, &dense_57_weights_intq)

/* Tensor #128 */
AI_TENSOR_OBJ_DECLARE(
  dense_57_bias, AI_STATIC,
  128, 0x1,
  AI_SHAPE_INIT(4, 1, 100, 1, 1), AI_STRIDE_INIT(4, 4, 4, 400, 400),
  1, &dense_57_bias_array, &dense_57_bias_intq)

/* Tensor #129 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_1_scratch0, AI_STATIC,
  129, 0x0,
  AI_SHAPE_INIT(4, 1, 1196, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1196, 1196),
  1, &conv2d_1_scratch0_array, NULL)

/* Tensor #130 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_scratch0, AI_STATIC,
  130, 0x0,
  AI_SHAPE_INIT(4, 1, 593, 1, 1), AI_STRIDE_INIT(4, 1, 1, 593, 593),
  1, &conv2d_3_scratch0_array, NULL)

/* Tensor #131 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_scratch0, AI_STATIC,
  131, 0x0,
  AI_SHAPE_INIT(4, 1, 624, 1, 1), AI_STRIDE_INIT(4, 1, 1, 624, 624),
  1, &conv2d_4_scratch0_array, NULL)

/* Tensor #132 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_6_scratch0, AI_STATIC,
  132, 0x0,
  AI_SHAPE_INIT(4, 1, 2073, 1, 1), AI_STRIDE_INIT(4, 1, 1, 2073, 2073),
  1, &conv2d_6_scratch0_array, NULL)

/* Tensor #133 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_scratch0, AI_STATIC,
  133, 0x0,
  AI_SHAPE_INIT(4, 1, 1264, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1264, 1264),
  1, &conv2d_7_scratch0_array, NULL)

/* Tensor #134 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_scratch0, AI_STATIC,
  134, 0x0,
  AI_SHAPE_INIT(4, 1, 3849, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3849, 3849),
  1, &conv2d_9_scratch0_array, NULL)

/* Tensor #135 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_10_scratch0, AI_STATIC,
  135, 0x0,
  AI_SHAPE_INIT(4, 1, 1216, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1216, 1216),
  1, &conv2d_10_scratch0_array, NULL)

/* Tensor #136 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_12_scratch0, AI_STATIC,
  136, 0x0,
  AI_SHAPE_INIT(4, 1, 2961, 1, 1), AI_STRIDE_INIT(4, 1, 1, 2961, 2961),
  1, &conv2d_12_scratch0_array, NULL)

/* Tensor #137 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_13_scratch0, AI_STATIC,
  137, 0x0,
  AI_SHAPE_INIT(4, 1, 1920, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1920, 1920),
  1, &conv2d_13_scratch0_array, NULL)

/* Tensor #138 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_15_scratch0, AI_STATIC,
  138, 0x0,
  AI_SHAPE_INIT(4, 1, 5921, 1, 1), AI_STRIDE_INIT(4, 1, 1, 5921, 5921),
  1, &conv2d_15_scratch0_array, NULL)

/* Tensor #139 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_16_scratch0, AI_STATIC,
  139, 0x0,
  AI_SHAPE_INIT(4, 1, 1680, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1680, 1680),
  1, &conv2d_16_scratch0_array, NULL)

/* Tensor #140 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_18_scratch0, AI_STATIC,
  140, 0x0,
  AI_SHAPE_INIT(4, 1, 3849, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3849, 3849),
  1, &conv2d_18_scratch0_array, NULL)

/* Tensor #141 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_19_scratch0, AI_STATIC,
  141, 0x0,
  AI_SHAPE_INIT(4, 1, 2496, 1, 1), AI_STRIDE_INIT(4, 1, 1, 2496, 2496),
  1, &conv2d_19_scratch0_array, NULL)

/* Tensor #142 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_21_scratch0, AI_STATIC,
  142, 0x0,
  AI_SHAPE_INIT(4, 1, 7697, 1, 1), AI_STRIDE_INIT(4, 1, 1, 7697, 7697),
  1, &conv2d_21_scratch0_array, NULL)

/* Tensor #143 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_22_scratch0, AI_STATIC,
  143, 0x0,
  AI_SHAPE_INIT(4, 1, 1152, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1152, 1152),
  1, &conv2d_22_scratch0_array, NULL)

/* Tensor #144 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_23_scratch0, AI_STATIC,
  144, 0x0,
  AI_SHAPE_INIT(4, 1, 448, 1, 1), AI_STRIDE_INIT(4, 1, 1, 448, 448),
  1, &conv2d_23_scratch0_array, NULL)

/* Tensor #145 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_24_scratch0, AI_STATIC,
  145, 0x0,
  AI_SHAPE_INIT(4, 1, 1728, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1728, 1728),
  1, &conv2d_24_scratch0_array, NULL)

/* Tensor #146 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_26_scratch0, AI_STATIC,
  146, 0x0,
  AI_SHAPE_INIT(4, 1, 5921, 1, 1), AI_STRIDE_INIT(4, 1, 1, 5921, 5921),
  1, &conv2d_26_scratch0_array, NULL)

/* Tensor #147 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_27_scratch0, AI_STATIC,
  147, 0x0,
  AI_SHAPE_INIT(4, 1, 960, 1, 1), AI_STRIDE_INIT(4, 1, 1, 960, 960),
  1, &conv2d_27_scratch0_array, NULL)

/* Tensor #148 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_28_scratch0, AI_STATIC,
  148, 0x0,
  AI_SHAPE_INIT(4, 1, 448, 1, 1), AI_STRIDE_INIT(4, 1, 1, 448, 448),
  1, &conv2d_28_scratch0_array, NULL)

/* Tensor #149 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_29_scratch0, AI_STATIC,
  149, 0x0,
  AI_SHAPE_INIT(4, 1, 1728, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1728, 1728),
  1, &conv2d_29_scratch0_array, NULL)

/* Tensor #150 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_31_scratch0, AI_STATIC,
  150, 0x0,
  AI_SHAPE_INIT(4, 1, 5921, 1, 1), AI_STRIDE_INIT(4, 1, 1, 5921, 5921),
  1, &conv2d_31_scratch0_array, NULL)

/* Tensor #151 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_32_scratch0, AI_STATIC,
  151, 0x0,
  AI_SHAPE_INIT(4, 1, 960, 1, 1), AI_STRIDE_INIT(4, 1, 1, 960, 960),
  1, &conv2d_32_scratch0_array, NULL)

/* Tensor #152 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_33_scratch0, AI_STATIC,
  152, 0x0,
  AI_SHAPE_INIT(4, 1, 448, 1, 1), AI_STRIDE_INIT(4, 1, 1, 448, 448),
  1, &conv2d_33_scratch0_array, NULL)

/* Tensor #153 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_34_scratch0, AI_STATIC,
  153, 0x0,
  AI_SHAPE_INIT(4, 1, 1728, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1728, 1728),
  1, &conv2d_34_scratch0_array, NULL)

/* Tensor #154 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_36_scratch0, AI_STATIC,
  154, 0x0,
  AI_SHAPE_INIT(4, 1, 5921, 1, 1), AI_STRIDE_INIT(4, 1, 1, 5921, 5921),
  1, &conv2d_36_scratch0_array, NULL)

/* Tensor #155 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_37_scratch0, AI_STATIC,
  155, 0x0,
  AI_SHAPE_INIT(4, 1, 1040, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1040, 1040),
  1, &conv2d_37_scratch0_array, NULL)

/* Tensor #156 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_38_scratch0, AI_STATIC,
  156, 0x0,
  AI_SHAPE_INIT(4, 1, 480, 1, 1), AI_STRIDE_INIT(4, 1, 1, 480, 480),
  1, &conv2d_38_scratch0_array, NULL)

/* Tensor #157 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_39_scratch0, AI_STATIC,
  157, 0x0,
  AI_SHAPE_INIT(4, 1, 2208, 1, 1), AI_STRIDE_INIT(4, 1, 1, 2208, 2208),
  1, &conv2d_39_scratch0_array, NULL)

/* Tensor #158 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_41_scratch0, AI_STATIC,
  158, 0x0,
  AI_SHAPE_INIT(4, 1, 7697, 1, 1), AI_STRIDE_INIT(4, 1, 1, 7697, 7697),
  1, &conv2d_41_scratch0_array, NULL)

/* Tensor #159 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_42_scratch0, AI_STATIC,
  159, 0x0,
  AI_SHAPE_INIT(4, 1, 1232, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1232, 1232),
  1, &conv2d_42_scratch0_array, NULL)

/* Tensor #160 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_43_scratch0, AI_STATIC,
  160, 0x0,
  AI_SHAPE_INIT(4, 1, 560, 1, 1), AI_STRIDE_INIT(4, 1, 1, 560, 560),
  1, &conv2d_43_scratch0_array, NULL)

/* Tensor #161 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_44_scratch0, AI_STATIC,
  161, 0x0,
  AI_SHAPE_INIT(4, 1, 2240, 1, 1), AI_STRIDE_INIT(4, 1, 1, 2240, 2240),
  1, &conv2d_44_scratch0_array, NULL)

/* Tensor #162 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_46_scratch0, AI_STATIC,
  162, 0x0,
  AI_SHAPE_INIT(4, 1, 7697, 1, 1), AI_STRIDE_INIT(4, 1, 1, 7697, 7697),
  1, &conv2d_46_scratch0_array, NULL)

/* Tensor #163 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_47_scratch0, AI_STATIC,
  163, 0x0,
  AI_SHAPE_INIT(4, 1, 1312, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1312, 1312),
  1, &conv2d_47_scratch0_array, NULL)

/* Tensor #164 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_48_scratch0, AI_STATIC,
  164, 0x0,
  AI_SHAPE_INIT(4, 1, 672, 1, 1), AI_STRIDE_INIT(4, 1, 1, 672, 672),
  1, &conv2d_48_scratch0_array, NULL)

/* Tensor #165 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_49_scratch0, AI_STATIC,
  165, 0x0,
  AI_SHAPE_INIT(4, 1, 2272, 1, 1), AI_STRIDE_INIT(4, 1, 1, 2272, 2272),
  1, &conv2d_49_scratch0_array, NULL)

/* Tensor #166 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_51_scratch0, AI_STATIC,
  166, 0x0,
  AI_SHAPE_INIT(4, 1, 7697, 1, 1), AI_STRIDE_INIT(4, 1, 1, 7697, 7697),
  1, &conv2d_51_scratch0_array, NULL)

/* Tensor #167 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_52_scratch0, AI_STATIC,
  167, 0x0,
  AI_SHAPE_INIT(4, 1, 2032, 1, 1), AI_STRIDE_INIT(4, 1, 1, 2032, 2032),
  1, &conv2d_52_scratch0_array, NULL)

/* Tensor #168 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_53_scratch0, AI_STATIC,
  168, 0x0,
  AI_SHAPE_INIT(4, 1, 1440, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1440, 1440),
  1, &conv2d_53_scratch0_array, NULL)

/* Tensor #169 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_54_scratch0, AI_STATIC,
  169, 0x0,
  AI_SHAPE_INIT(4, 1, 7584, 1, 1), AI_STRIDE_INIT(4, 1, 1, 7584, 7584),
  1, &conv2d_54_scratch0_array, NULL)

/* Tensor #170 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_54_scratch1, AI_STATIC,
  170, 0x1,
  AI_SHAPE_INIT(4, 1, 720, 2, 2), AI_STRIDE_INIT(4, 1, 1, 720, 1440),
  1, &conv2d_54_scratch1_array, &conv2d_54_scratch1_intq)



/**  Layer declarations section  **********************************************/


AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_1_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &input_1_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_1_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_1_weights, &conv2d_1_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_1_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_1_layer, 0,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_1_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_3_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_3_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_1_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_3_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_3_weights, &conv2d_3_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_3_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_3_layer, 2,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_3_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_4_layer, AI_STATIC, 
  .groups = 16, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_4_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_3_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_4_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_4_weights, &conv2d_4_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_4_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_4_layer, 4,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_4_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_6_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_6_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_4_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_6_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_6_weights, &conv2d_6_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_6_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_6_layer, 5,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_6_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_7_layer, AI_STATIC, 
  .groups = 56, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_7_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_6_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_7_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_7_weights, &conv2d_7_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_7_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_7_layer, 7,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_7_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_9_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_9_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_7_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_9_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_9_weights, &conv2d_9_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_9_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_9_layer, 8,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_9_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_10_layer, AI_STATIC, 
  .groups = 104, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_10_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_9_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_10_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_10_weights, &conv2d_10_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_10_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_10_layer, 10,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_10_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_12_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_12_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_10_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_12_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_12_weights, &conv2d_12_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_12_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_12_layer, 11,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_12_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_13_layer, AI_STATIC, 
  .groups = 80, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_13_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_12_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_13_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_13_weights, &conv2d_13_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_13_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_13_layer, 13,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_13_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_15_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_15_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_13_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_15_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_15_weights, &conv2d_15_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_15_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_15_layer, 14,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_15_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_16_layer, AI_STATIC, 
  .groups = 160, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_16_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_15_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_16_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_16_weights, &conv2d_16_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_16_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_16_layer, 16,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_16_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_18_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_18_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_16_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_18_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_18_weights, &conv2d_18_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_18_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_18_layer, 17,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_18_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_19_layer, AI_STATIC, 
  .groups = 104, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_19_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_18_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_19_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_19_weights, &conv2d_19_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_19_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_19_layer, 19,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_19_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_21_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_21_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_19_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_21_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_21_weights, &conv2d_21_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_21_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_21_layer, 20,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_21_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_22_layer, AI_STATIC, 
  .groups = 208, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_22_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_21_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_22_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_22_weights, &conv2d_22_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_22_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_22_layer, 22,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_22_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_23_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_23_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_22_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_23_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_23_weights, &conv2d_23_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_23_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_23_layer, 23,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_23_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_24_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_24_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_23_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_24_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_24_weights, &conv2d_24_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_24_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_24_layer, 24,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_24_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_26_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_26_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_24_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_26_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_26_weights, &conv2d_26_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_26_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_26_layer, 25,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_26_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_27_layer, AI_STATIC, 
  .groups = 160, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_27_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_26_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_27_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_27_weights, &conv2d_27_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_27_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_27_layer, 27,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_27_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_28_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_28_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_27_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_28_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_28_weights, &conv2d_28_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_28_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_28_layer, 28,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_28_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_29_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_29_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_28_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_29_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_29_weights, &conv2d_29_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_29_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_29_layer, 29,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_29_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_31_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_31_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_29_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_31_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_31_weights, &conv2d_31_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_31_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_31_layer, 30,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_31_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_32_layer, AI_STATIC, 
  .groups = 160, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_32_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_31_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_32_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_32_weights, &conv2d_32_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_32_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_32_layer, 32,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_32_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_33_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_33_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_32_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_33_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_33_weights, &conv2d_33_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_33_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_33_layer, 33,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_33_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_34_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_34_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_33_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_34_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_34_weights, &conv2d_34_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_34_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_34_layer, 34,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_34_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_36_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_36_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_34_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_36_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_36_weights, &conv2d_36_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_36_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_36_layer, 35,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_36_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_37_layer, AI_STATIC, 
  .groups = 160, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_37_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_36_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_37_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_37_weights, &conv2d_37_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_37_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_37_layer, 37,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_37_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_38_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_38_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_37_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_38_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_38_weights, &conv2d_38_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_38_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_38_layer, 38,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_38_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_39_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_39_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_38_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_39_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_39_weights, &conv2d_39_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_39_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_39_layer, 39,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_39_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_41_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_41_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_39_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_41_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_41_weights, &conv2d_41_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_41_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_41_layer, 40,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_41_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_42_layer, AI_STATIC, 
  .groups = 208, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_42_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_41_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_42_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_42_weights, &conv2d_42_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_42_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_42_layer, 42,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_42_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_43_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_43_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_42_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_43_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_43_weights, &conv2d_43_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_43_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_43_layer, 43,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_43_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_44_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_44_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_43_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_44_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_44_weights, &conv2d_44_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_44_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_44_layer, 44,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_44_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_46_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_46_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_44_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_46_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_46_weights, &conv2d_46_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_46_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_46_layer, 45,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_46_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_47_layer, AI_STATIC, 
  .groups = 208, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_47_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_46_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_47_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_47_weights, &conv2d_47_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_47_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_47_layer, 47,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_47_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_48_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_48_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_47_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_48_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_48_weights, &conv2d_48_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_48_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_48_layer, 48,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_48_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_49_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_49_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_48_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_49_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_49_weights, &conv2d_49_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_49_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_49_layer, 49,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_49_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_51_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_51_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_49_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_51_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_51_weights, &conv2d_51_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_51_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_51_layer, 50,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_51_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_52_layer, AI_STATIC, 
  .groups = 208, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_52_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_51_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_52_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_52_weights, &conv2d_52_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_52_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_52_layer, 52,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_52_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_53_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_53_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_52_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_53_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_53_weights, &conv2d_53_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_53_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_53_layer, 53,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_53_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_54_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_54_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_53_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_54_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_54_weights, &conv2d_54_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_54_scratch0, &conv2d_54_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_54_layer, 55,
  OPTIMIZED_CONV2D_TYPE, 0x0, NULL,
  conv2d_nl_pool, forward_conv2d_nl_pool_integer_SSSA_ch,
  &conv2d_54_chain,
  &AI_NET_OBJ_INSTANCE, &dense_57_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .pool_size = AI_SHAPE_2D_INIT(2, 2), 
  .pool_stride = AI_SHAPE_2D_INIT(2, 2), 
  .pool_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .pool_func = pool_func_ap_array_integer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_57_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_54_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_57_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &dense_57_weights, &dense_57_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_57_layer, 57,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense_integer_SSSA,
  &dense_57_chain,
  &AI_NET_OBJ_INSTANCE, &dense_57_fmt_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_57_fmt_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_57_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_57_fmt_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_57_fmt_layer, 57,
  NL_TYPE, 0x0, NULL,
  nl, node_convert,
  &dense_57_fmt_chain,
  &AI_NET_OBJ_INSTANCE, &nl_58_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_58_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_57_fmt_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_58_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_58_layer, 58,
  NL_TYPE, 0x0, NULL,
  nl, forward_sm,
  &nl_58_chain,
  &AI_NET_OBJ_INSTANCE, &nl_58_layer, AI_STATIC, 
  .nl_params = NULL, 
)


AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 371368, 1,
                     NULL),
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 60768, 1,
                     NULL),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_IN_NUM, &input_1_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_OUT_NUM, &nl_58_output),
  &conv2d_1_layer, 0, NULL)



AI_DECLARE_STATIC
ai_bool network_configure_activations(
  ai_network* net_ctx, const ai_buffer* activation_buffer)
{
  AI_ASSERT(net_ctx &&  activation_buffer && activation_buffer->data)

  ai_ptr activations = AI_PTR(AI_PTR_ALIGN(activation_buffer->data, 4));
  AI_ASSERT(activations)
  AI_UNUSED(net_ctx)

  {
    /* Updating activations (byte) offsets */
    input_1_output_array.data = AI_PTR(NULL);
    input_1_output_array.data_start = AI_PTR(NULL);
    conv2d_1_output_array.data = AI_PTR(activations + 26780);
    conv2d_1_output_array.data_start = AI_PTR(activations + 26780);
    conv2d_3_output_array.data = AI_PTR(activations + 43760);
    conv2d_3_output_array.data_start = AI_PTR(activations + 43760);
    conv2d_4_output_array.data = AI_PTR(activations + 952);
    conv2d_4_output_array.data_start = AI_PTR(activations + 952);
    conv2d_6_output_array.data = AI_PTR(activations + 0);
    conv2d_6_output_array.data_start = AI_PTR(activations + 0);
    conv2d_7_output_array.data = AI_PTR(activations + 15600);
    conv2d_7_output_array.data_start = AI_PTR(activations + 15600);
    conv2d_9_output_array.data = AI_PTR(activations + 12064);
    conv2d_9_output_array.data_start = AI_PTR(activations + 12064);
    conv2d_10_output_array.data = AI_PTR(activations + 38688);
    conv2d_10_output_array.data_start = AI_PTR(activations + 38688);
    conv2d_12_output_array.data = AI_PTR(activations + 2964);
    conv2d_12_output_array.data_start = AI_PTR(activations + 2964);
    conv2d_13_output_array.data = AI_PTR(activations + 8084);
    conv2d_13_output_array.data_start = AI_PTR(activations + 8084);
    conv2d_15_output_array.data = AI_PTR(activations + 18324);
    conv2d_15_output_array.data_start = AI_PTR(activations + 18324);
    conv2d_16_output_array.data = AI_PTR(activations + 1680);
    conv2d_16_output_array.data_start = AI_PTR(activations + 1680);
    conv2d_18_output_array.data = AI_PTR(activations + 0);
    conv2d_18_output_array.data_start = AI_PTR(activations + 0);
    conv2d_19_output_array.data = AI_PTR(activations + 4160);
    conv2d_19_output_array.data_start = AI_PTR(activations + 4160);
    conv2d_21_output_array.data = AI_PTR(activations + 0);
    conv2d_21_output_array.data_start = AI_PTR(activations + 0);
    conv2d_22_output_array.data = AI_PTR(activations + 4480);
    conv2d_22_output_array.data_start = AI_PTR(activations + 4480);
    conv2d_23_output_array.data = AI_PTR(activations + 448);
    conv2d_23_output_array.data_start = AI_PTR(activations + 448);
    conv2d_24_output_array.data = AI_PTR(activations + 2688);
    conv2d_24_output_array.data_start = AI_PTR(activations + 2688);
    conv2d_26_output_array.data = AI_PTR(activations + 0);
    conv2d_26_output_array.data_start = AI_PTR(activations + 0);
    conv2d_27_output_array.data = AI_PTR(activations + 3520);
    conv2d_27_output_array.data_start = AI_PTR(activations + 3520);
    conv2d_28_output_array.data = AI_PTR(activations + 448);
    conv2d_28_output_array.data_start = AI_PTR(activations + 448);
    conv2d_29_output_array.data = AI_PTR(activations + 2688);
    conv2d_29_output_array.data_start = AI_PTR(activations + 2688);
    conv2d_31_output_array.data = AI_PTR(activations + 0);
    conv2d_31_output_array.data_start = AI_PTR(activations + 0);
    conv2d_32_output_array.data = AI_PTR(activations + 3520);
    conv2d_32_output_array.data_start = AI_PTR(activations + 3520);
    conv2d_33_output_array.data = AI_PTR(activations + 448);
    conv2d_33_output_array.data_start = AI_PTR(activations + 448);
    conv2d_34_output_array.data = AI_PTR(activations + 2688);
    conv2d_34_output_array.data_start = AI_PTR(activations + 2688);
    conv2d_36_output_array.data = AI_PTR(activations + 0);
    conv2d_36_output_array.data_start = AI_PTR(activations + 0);
    conv2d_37_output_array.data = AI_PTR(activations + 3600);
    conv2d_37_output_array.data_start = AI_PTR(activations + 3600);
    conv2d_38_output_array.data = AI_PTR(activations + 480);
    conv2d_38_output_array.data_start = AI_PTR(activations + 480);
    conv2d_39_output_array.data = AI_PTR(activations + 3200);
    conv2d_39_output_array.data_start = AI_PTR(activations + 3200);
    conv2d_41_output_array.data = AI_PTR(activations + 14228);
    conv2d_41_output_array.data_start = AI_PTR(activations + 14228);
    conv2d_42_output_array.data = AI_PTR(activations + 1232);
    conv2d_42_output_array.data_start = AI_PTR(activations + 1232);
    conv2d_43_output_array.data = AI_PTR(activations + 560);
    conv2d_43_output_array.data_start = AI_PTR(activations + 560);
    conv2d_44_output_array.data = AI_PTR(activations + 3440);
    conv2d_44_output_array.data_start = AI_PTR(activations + 3440);
    conv2d_46_output_array.data = AI_PTR(activations + 0);
    conv2d_46_output_array.data_start = AI_PTR(activations + 0);
    conv2d_47_output_array.data = AI_PTR(activations + 2144);
    conv2d_47_output_array.data_start = AI_PTR(activations + 2144);
    conv2d_48_output_array.data = AI_PTR(activations + 672);
    conv2d_48_output_array.data_start = AI_PTR(activations + 672);
    conv2d_49_output_array.data = AI_PTR(activations + 3136);
    conv2d_49_output_array.data_start = AI_PTR(activations + 3136);
    conv2d_51_output_array.data = AI_PTR(activations + 0);
    conv2d_51_output_array.data_start = AI_PTR(activations + 0);
    conv2d_52_output_array.data = AI_PTR(activations + 2864);
    conv2d_52_output_array.data_start = AI_PTR(activations + 2864);
    conv2d_53_output_array.data = AI_PTR(activations + 1440);
    conv2d_53_output_array.data_start = AI_PTR(activations + 1440);
    conv2d_54_output_array.data = AI_PTR(activations + 0);
    conv2d_54_output_array.data_start = AI_PTR(activations + 0);
    dense_57_output_array.data = AI_PTR(activations + 720);
    dense_57_output_array.data_start = AI_PTR(activations + 720);
    dense_57_fmt_output_array.data = AI_PTR(activations + 0);
    dense_57_fmt_output_array.data_start = AI_PTR(activations + 0);
    nl_58_output_array.data = AI_PTR(NULL);
    nl_58_output_array.data_start = AI_PTR(NULL);
    conv2d_1_scratch0_array.data = AI_PTR(activations + 43164);
    conv2d_1_scratch0_array.data_start = AI_PTR(activations + 43164);
    conv2d_3_scratch0_array.data = AI_PTR(activations + 43164);
    conv2d_3_scratch0_array.data_start = AI_PTR(activations + 43164);
    conv2d_4_scratch0_array.data = AI_PTR(activations + 60144);
    conv2d_4_scratch0_array.data_start = AI_PTR(activations + 60144);
    conv2d_6_scratch0_array.data = AI_PTR(activations + 58692);
    conv2d_6_scratch0_array.data_start = AI_PTR(activations + 58692);
    conv2d_7_scratch0_array.data = AI_PTR(activations + 14336);
    conv2d_7_scratch0_array.data_start = AI_PTR(activations + 14336);
    conv2d_9_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_9_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_10_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_10_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_12_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_12_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_13_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_13_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_15_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_15_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_16_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_16_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_18_scratch0_array.data = AI_PTR(activations + 8336);
    conv2d_18_scratch0_array.data_start = AI_PTR(activations + 8336);
    conv2d_19_scratch0_array.data = AI_PTR(activations + 1664);
    conv2d_19_scratch0_array.data_start = AI_PTR(activations + 1664);
    conv2d_21_scratch0_array.data = AI_PTR(activations + 7488);
    conv2d_21_scratch0_array.data_start = AI_PTR(activations + 7488);
    conv2d_22_scratch0_array.data = AI_PTR(activations + 3328);
    conv2d_22_scratch0_array.data_start = AI_PTR(activations + 3328);
    conv2d_23_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_23_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_24_scratch0_array.data = AI_PTR(activations + 960);
    conv2d_24_scratch0_array.data_start = AI_PTR(activations + 960);
    conv2d_26_scratch0_array.data = AI_PTR(activations + 5248);
    conv2d_26_scratch0_array.data_start = AI_PTR(activations + 5248);
    conv2d_27_scratch0_array.data = AI_PTR(activations + 2560);
    conv2d_27_scratch0_array.data_start = AI_PTR(activations + 2560);
    conv2d_28_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_28_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_29_scratch0_array.data = AI_PTR(activations + 960);
    conv2d_29_scratch0_array.data_start = AI_PTR(activations + 960);
    conv2d_31_scratch0_array.data = AI_PTR(activations + 5248);
    conv2d_31_scratch0_array.data_start = AI_PTR(activations + 5248);
    conv2d_32_scratch0_array.data = AI_PTR(activations + 2560);
    conv2d_32_scratch0_array.data_start = AI_PTR(activations + 2560);
    conv2d_33_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_33_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_34_scratch0_array.data = AI_PTR(activations + 960);
    conv2d_34_scratch0_array.data_start = AI_PTR(activations + 960);
    conv2d_36_scratch0_array.data = AI_PTR(activations + 5248);
    conv2d_36_scratch0_array.data_start = AI_PTR(activations + 5248);
    conv2d_37_scratch0_array.data = AI_PTR(activations + 2560);
    conv2d_37_scratch0_array.data_start = AI_PTR(activations + 2560);
    conv2d_38_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_38_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_39_scratch0_array.data = AI_PTR(activations + 992);
    conv2d_39_scratch0_array.data_start = AI_PTR(activations + 992);
    conv2d_41_scratch0_array.data = AI_PTR(activations + 6528);
    conv2d_41_scratch0_array.data_start = AI_PTR(activations + 6528);
    conv2d_42_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_42_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_43_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_43_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_44_scratch0_array.data = AI_PTR(activations + 1200);
    conv2d_44_scratch0_array.data_start = AI_PTR(activations + 1200);
    conv2d_46_scratch0_array.data = AI_PTR(activations + 6768);
    conv2d_46_scratch0_array.data_start = AI_PTR(activations + 6768);
    conv2d_47_scratch0_array.data = AI_PTR(activations + 832);
    conv2d_47_scratch0_array.data_start = AI_PTR(activations + 832);
    conv2d_48_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_48_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_49_scratch0_array.data = AI_PTR(activations + 864);
    conv2d_49_scratch0_array.data_start = AI_PTR(activations + 864);
    conv2d_51_scratch0_array.data = AI_PTR(activations + 3968);
    conv2d_51_scratch0_array.data_start = AI_PTR(activations + 3968);
    conv2d_52_scratch0_array.data = AI_PTR(activations + 832);
    conv2d_52_scratch0_array.data_start = AI_PTR(activations + 832);
    conv2d_53_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_53_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_54_scratch0_array.data = AI_PTR(activations + 1824);
    conv2d_54_scratch0_array.data_start = AI_PTR(activations + 1824);
    conv2d_54_scratch1_array.data = AI_PTR(activations + 9408);
    conv2d_54_scratch1_array.data_start = AI_PTR(activations + 9408);
    
  }
  return true;
}



AI_DECLARE_STATIC
ai_bool network_configure_weights(
  ai_network* net_ctx, const ai_buffer* weights_buffer)
{
  AI_ASSERT(net_ctx &&  weights_buffer && weights_buffer->data)

  ai_ptr weights = AI_PTR(weights_buffer->data);
  AI_ASSERT(weights)
  AI_UNUSED(net_ctx)

  {
    /* Updating weights (byte) offsets */
    
    conv2d_1_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_1_weights_array.data = AI_PTR(weights + 0);
    conv2d_1_weights_array.data_start = AI_PTR(weights + 0);
    conv2d_1_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_1_bias_array.data = AI_PTR(weights + 432);
    conv2d_1_bias_array.data_start = AI_PTR(weights + 432);
    conv2d_3_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_3_weights_array.data = AI_PTR(weights + 496);
    conv2d_3_weights_array.data_start = AI_PTR(weights + 496);
    conv2d_3_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_3_bias_array.data = AI_PTR(weights + 640);
    conv2d_3_bias_array.data_start = AI_PTR(weights + 640);
    conv2d_4_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_4_weights_array.data = AI_PTR(weights + 704);
    conv2d_4_weights_array.data_start = AI_PTR(weights + 704);
    conv2d_4_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_4_bias_array.data = AI_PTR(weights + 1600);
    conv2d_4_bias_array.data_start = AI_PTR(weights + 1600);
    conv2d_6_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_6_weights_array.data = AI_PTR(weights + 1824);
    conv2d_6_weights_array.data_start = AI_PTR(weights + 1824);
    conv2d_6_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_6_bias_array.data = AI_PTR(weights + 2328);
    conv2d_6_bias_array.data_start = AI_PTR(weights + 2328);
    conv2d_7_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_7_weights_array.data = AI_PTR(weights + 2552);
    conv2d_7_weights_array.data_start = AI_PTR(weights + 2552);
    conv2d_7_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_7_bias_array.data = AI_PTR(weights + 8376);
    conv2d_7_bias_array.data_start = AI_PTR(weights + 8376);
    conv2d_9_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_9_weights_array.data = AI_PTR(weights + 8792);
    conv2d_9_weights_array.data_start = AI_PTR(weights + 8792);
    conv2d_9_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_9_bias_array.data = AI_PTR(weights + 9728);
    conv2d_9_bias_array.data_start = AI_PTR(weights + 9728);
    conv2d_10_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_10_weights_array.data = AI_PTR(weights + 10144);
    conv2d_10_weights_array.data_start = AI_PTR(weights + 10144);
    conv2d_10_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_10_bias_array.data = AI_PTR(weights + 18464);
    conv2d_10_bias_array.data_start = AI_PTR(weights + 18464);
    conv2d_12_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_12_weights_array.data = AI_PTR(weights + 18784);
    conv2d_12_weights_array.data_start = AI_PTR(weights + 18784);
    conv2d_12_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_12_bias_array.data = AI_PTR(weights + 19504);
    conv2d_12_bias_array.data_start = AI_PTR(weights + 19504);
    conv2d_13_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_13_weights_array.data = AI_PTR(weights + 19824);
    conv2d_13_weights_array.data_start = AI_PTR(weights + 19824);
    conv2d_13_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_13_bias_array.data = AI_PTR(weights + 32624);
    conv2d_13_bias_array.data_start = AI_PTR(weights + 32624);
    conv2d_15_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_15_weights_array.data = AI_PTR(weights + 33264);
    conv2d_15_weights_array.data_start = AI_PTR(weights + 33264);
    conv2d_15_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_15_bias_array.data = AI_PTR(weights + 34704);
    conv2d_15_bias_array.data_start = AI_PTR(weights + 34704);
    conv2d_16_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_16_weights_array.data = AI_PTR(weights + 35344);
    conv2d_16_weights_array.data_start = AI_PTR(weights + 35344);
    conv2d_16_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_16_bias_array.data = AI_PTR(weights + 51984);
    conv2d_16_bias_array.data_start = AI_PTR(weights + 51984);
    conv2d_18_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_18_weights_array.data = AI_PTR(weights + 52400);
    conv2d_18_weights_array.data_start = AI_PTR(weights + 52400);
    conv2d_18_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_18_bias_array.data = AI_PTR(weights + 53336);
    conv2d_18_bias_array.data_start = AI_PTR(weights + 53336);
    conv2d_19_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_19_weights_array.data = AI_PTR(weights + 53752);
    conv2d_19_weights_array.data_start = AI_PTR(weights + 53752);
    conv2d_19_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_19_bias_array.data = AI_PTR(weights + 75384);
    conv2d_19_bias_array.data_start = AI_PTR(weights + 75384);
    conv2d_21_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_21_weights_array.data = AI_PTR(weights + 76216);
    conv2d_21_weights_array.data_start = AI_PTR(weights + 76216);
    conv2d_21_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_21_bias_array.data = AI_PTR(weights + 78088);
    conv2d_21_bias_array.data_start = AI_PTR(weights + 78088);
    conv2d_22_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_22_weights_array.data = AI_PTR(weights + 78920);
    conv2d_22_weights_array.data_start = AI_PTR(weights + 78920);
    conv2d_22_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_22_bias_array.data = AI_PTR(weights + 85576);
    conv2d_22_bias_array.data_start = AI_PTR(weights + 85576);
    conv2d_23_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_23_weights_array.data = AI_PTR(weights + 85704);
    conv2d_23_weights_array.data_start = AI_PTR(weights + 85704);
    conv2d_23_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_23_bias_array.data = AI_PTR(weights + 86728);
    conv2d_23_bias_array.data_start = AI_PTR(weights + 86728);
    conv2d_24_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_24_weights_array.data = AI_PTR(weights + 86856);
    conv2d_24_weights_array.data_start = AI_PTR(weights + 86856);
    conv2d_24_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_24_bias_array.data = AI_PTR(weights + 91976);
    conv2d_24_bias_array.data_start = AI_PTR(weights + 91976);
    conv2d_26_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_26_weights_array.data = AI_PTR(weights + 92616);
    conv2d_26_weights_array.data_start = AI_PTR(weights + 92616);
    conv2d_26_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_26_bias_array.data = AI_PTR(weights + 94056);
    conv2d_26_bias_array.data_start = AI_PTR(weights + 94056);
    conv2d_27_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_27_weights_array.data = AI_PTR(weights + 94696);
    conv2d_27_weights_array.data_start = AI_PTR(weights + 94696);
    conv2d_27_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_27_bias_array.data = AI_PTR(weights + 99816);
    conv2d_27_bias_array.data_start = AI_PTR(weights + 99816);
    conv2d_28_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_28_weights_array.data = AI_PTR(weights + 99944);
    conv2d_28_weights_array.data_start = AI_PTR(weights + 99944);
    conv2d_28_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_28_bias_array.data = AI_PTR(weights + 100968);
    conv2d_28_bias_array.data_start = AI_PTR(weights + 100968);
    conv2d_29_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_29_weights_array.data = AI_PTR(weights + 101096);
    conv2d_29_weights_array.data_start = AI_PTR(weights + 101096);
    conv2d_29_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_29_bias_array.data = AI_PTR(weights + 106216);
    conv2d_29_bias_array.data_start = AI_PTR(weights + 106216);
    conv2d_31_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_31_weights_array.data = AI_PTR(weights + 106856);
    conv2d_31_weights_array.data_start = AI_PTR(weights + 106856);
    conv2d_31_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_31_bias_array.data = AI_PTR(weights + 108296);
    conv2d_31_bias_array.data_start = AI_PTR(weights + 108296);
    conv2d_32_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_32_weights_array.data = AI_PTR(weights + 108936);
    conv2d_32_weights_array.data_start = AI_PTR(weights + 108936);
    conv2d_32_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_32_bias_array.data = AI_PTR(weights + 114056);
    conv2d_32_bias_array.data_start = AI_PTR(weights + 114056);
    conv2d_33_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_33_weights_array.data = AI_PTR(weights + 114184);
    conv2d_33_weights_array.data_start = AI_PTR(weights + 114184);
    conv2d_33_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_33_bias_array.data = AI_PTR(weights + 115208);
    conv2d_33_bias_array.data_start = AI_PTR(weights + 115208);
    conv2d_34_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_34_weights_array.data = AI_PTR(weights + 115336);
    conv2d_34_weights_array.data_start = AI_PTR(weights + 115336);
    conv2d_34_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_34_bias_array.data = AI_PTR(weights + 120456);
    conv2d_34_bias_array.data_start = AI_PTR(weights + 120456);
    conv2d_36_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_36_weights_array.data = AI_PTR(weights + 121096);
    conv2d_36_weights_array.data_start = AI_PTR(weights + 121096);
    conv2d_36_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_36_bias_array.data = AI_PTR(weights + 122536);
    conv2d_36_bias_array.data_start = AI_PTR(weights + 122536);
    conv2d_37_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_37_weights_array.data = AI_PTR(weights + 123176);
    conv2d_37_weights_array.data_start = AI_PTR(weights + 123176);
    conv2d_37_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_37_bias_array.data = AI_PTR(weights + 129576);
    conv2d_37_bias_array.data_start = AI_PTR(weights + 129576);
    conv2d_38_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_38_weights_array.data = AI_PTR(weights + 129736);
    conv2d_38_weights_array.data_start = AI_PTR(weights + 129736);
    conv2d_38_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_38_bias_array.data = AI_PTR(weights + 131016);
    conv2d_38_bias_array.data_start = AI_PTR(weights + 131016);
    conv2d_39_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_39_weights_array.data = AI_PTR(weights + 131144);
    conv2d_39_weights_array.data_start = AI_PTR(weights + 131144);
    conv2d_39_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_39_bias_array.data = AI_PTR(weights + 137800);
    conv2d_39_bias_array.data_start = AI_PTR(weights + 137800);
    conv2d_41_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_41_weights_array.data = AI_PTR(weights + 138632);
    conv2d_41_weights_array.data_start = AI_PTR(weights + 138632);
    conv2d_41_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_41_bias_array.data = AI_PTR(weights + 140504);
    conv2d_41_bias_array.data_start = AI_PTR(weights + 140504);
    conv2d_42_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_42_weights_array.data = AI_PTR(weights + 141336);
    conv2d_42_weights_array.data_start = AI_PTR(weights + 141336);
    conv2d_42_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_42_bias_array.data = AI_PTR(weights + 149656);
    conv2d_42_bias_array.data_start = AI_PTR(weights + 149656);
    conv2d_43_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_43_weights_array.data = AI_PTR(weights + 149816);
    conv2d_43_weights_array.data_start = AI_PTR(weights + 149816);
    conv2d_43_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_43_bias_array.data = AI_PTR(weights + 151416);
    conv2d_43_bias_array.data_start = AI_PTR(weights + 151416);
    conv2d_44_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_44_weights_array.data = AI_PTR(weights + 151576);
    conv2d_44_weights_array.data_start = AI_PTR(weights + 151576);
    conv2d_44_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_44_bias_array.data = AI_PTR(weights + 159896);
    conv2d_44_bias_array.data_start = AI_PTR(weights + 159896);
    conv2d_46_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_46_weights_array.data = AI_PTR(weights + 160728);
    conv2d_46_weights_array.data_start = AI_PTR(weights + 160728);
    conv2d_46_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_46_bias_array.data = AI_PTR(weights + 162600);
    conv2d_46_bias_array.data_start = AI_PTR(weights + 162600);
    conv2d_47_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_47_weights_array.data = AI_PTR(weights + 163432);
    conv2d_47_weights_array.data_start = AI_PTR(weights + 163432);
    conv2d_47_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_47_bias_array.data = AI_PTR(weights + 173416);
    conv2d_47_bias_array.data_start = AI_PTR(weights + 173416);
    conv2d_48_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_48_weights_array.data = AI_PTR(weights + 173608);
    conv2d_48_weights_array.data_start = AI_PTR(weights + 173608);
    conv2d_48_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_48_bias_array.data = AI_PTR(weights + 175912);
    conv2d_48_bias_array.data_start = AI_PTR(weights + 175912);
    conv2d_49_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_49_weights_array.data = AI_PTR(weights + 176104);
    conv2d_49_weights_array.data_start = AI_PTR(weights + 176104);
    conv2d_49_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_49_bias_array.data = AI_PTR(weights + 186088);
    conv2d_49_bias_array.data_start = AI_PTR(weights + 186088);
    conv2d_51_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_51_weights_array.data = AI_PTR(weights + 186920);
    conv2d_51_weights_array.data_start = AI_PTR(weights + 186920);
    conv2d_51_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_51_bias_array.data = AI_PTR(weights + 188792);
    conv2d_51_bias_array.data_start = AI_PTR(weights + 188792);
    conv2d_52_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_52_weights_array.data = AI_PTR(weights + 189624);
    conv2d_52_weights_array.data_start = AI_PTR(weights + 189624);
    conv2d_52_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_52_bias_array.data = AI_PTR(weights + 214584);
    conv2d_52_bias_array.data_start = AI_PTR(weights + 214584);
    conv2d_53_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_53_weights_array.data = AI_PTR(weights + 215064);
    conv2d_53_weights_array.data_start = AI_PTR(weights + 215064);
    conv2d_53_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_53_bias_array.data = AI_PTR(weights + 226584);
    conv2d_53_bias_array.data_start = AI_PTR(weights + 226584);
    conv2d_54_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_54_weights_array.data = AI_PTR(weights + 226968);
    conv2d_54_weights_array.data_start = AI_PTR(weights + 226968);
    conv2d_54_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_54_bias_array.data = AI_PTR(weights + 296088);
    conv2d_54_bias_array.data_start = AI_PTR(weights + 296088);
    dense_57_weights_array.format |= AI_FMT_FLAG_CONST;
    dense_57_weights_array.data = AI_PTR(weights + 298968);
    dense_57_weights_array.data_start = AI_PTR(weights + 298968);
    dense_57_bias_array.format |= AI_FMT_FLAG_CONST;
    dense_57_bias_array.data = AI_PTR(weights + 370968);
    dense_57_bias_array.data_start = AI_PTR(weights + 370968);
  }

  return true;
}


/**  PUBLIC APIs SECTION  *****************************************************/

AI_API_ENTRY
ai_bool ai_network_get_info(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if ( report && net_ctx )
  {
    ai_network_report r = {
      .model_name        = AI_NETWORK_MODEL_NAME,
      .model_signature   = AI_NETWORK_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = AI_STRUCT_INIT,

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 9703992,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .activations       = AI_STRUCT_INIT,
      .params            = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0x0,
    };

    if (!ai_platform_api_get_network_report(network, &r)) return false;

    *report = r;
    return true;
  }

  return false;
}

AI_API_ENTRY
ai_error ai_network_get_error(ai_handle network)
{
  return ai_platform_network_get_error(network);
}

AI_API_ENTRY
ai_error ai_network_create(
  ai_handle* network, const ai_buffer* network_config)
{
  return ai_platform_network_create(
    network, network_config, 
    &AI_NET_OBJ_INSTANCE,
    AI_TOOLS_API_VERSION_MAJOR, AI_TOOLS_API_VERSION_MINOR, AI_TOOLS_API_VERSION_MICRO);
}

AI_API_ENTRY
ai_handle ai_network_destroy(ai_handle network)
{
  return ai_platform_network_destroy(network);
}

AI_API_ENTRY
ai_bool ai_network_init(
  ai_handle network, const ai_network_params* params)
{
  ai_network* net_ctx = ai_platform_network_init(network, params);
  if ( !net_ctx ) return false;

  ai_bool ok = true;
  ok &= network_configure_weights(net_ctx, &params->params);
  ok &= network_configure_activations(net_ctx, &params->activations);

  ok &= ai_platform_network_post_init(network);

  return ok;
}


AI_API_ENTRY
ai_i32 ai_network_run(
  ai_handle network, const ai_buffer* input, ai_buffer* output)
{
  return ai_platform_network_process(network, input, output);
}

AI_API_ENTRY
ai_i32 ai_network_forward(ai_handle network, const ai_buffer* input)
{
  return ai_platform_network_process(network, input, NULL);
}



#undef AI_NETWORK_MODEL_SIGNATURE
#undef AI_NET_OBJ_INSTANCE
#undef AI_TOOLS_DATE_TIME
#undef AI_TOOLS_COMPILE_TIME

