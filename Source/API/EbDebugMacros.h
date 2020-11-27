/*
* Copyright(c) 2020 Intel Corporation
*
* This source code is subject to the terms of the BSD 2 Clause License and
* the Alliance for Open Media Patent License 1.0. If the BSD 2 Clause License
* was not distributed with this source code in the LICENSE file, you can
* obtain it at https://www.aomedia.org/license/software-license. If the Alliance for Open
* Media Patent License 1.0 was not distributed with this source code in the
* PATENTS file, you can obtain it at https://www.aomedia.org/license/patent-license.
*/


/*
* This file contains only debug macros that are used during the development
* and are supposed to be cleaned up every tag cycle
* all macros must have the following format:
* - enabling a feature should be prefixed by ENABLE_
* - disableing a feature should be prefixed by DISABLE_
* - tuning a feature should be prefixed by TUNE_
* - adding a new feature should be prefixed by FEATURE_
* - bug fixes should be prefixed by FIX_
* - all macros must have a coherent comment explaining what the MACRO is doing
* - #if 0 / #if 1 are not to be used
*/


#ifndef EbDebugMacros_h
#define EbDebugMacros_h

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

// undefining this macro would allow the AVX512 optimization to be enabled by default
#ifndef NON_AVX512_SUPPORT
#define NON_AVX512_SUPPORT
#endif


#define FEATURE_OPT_TF                               1 // Add the ability to perform luma only @ tf, control tf_16x16 using tf_32x32 pred error, apply tf @ base only
#define TUNE_CFL_REF_ONLY                            1 // CFL only @ REF
#define FEATURE_GM_OPT                               1 // GM @ REF, bipred only, rotzoom model omly
#define TUNE_HME_ME_TUNING                           1 // HME/ME:HME_L1=8x3 instead of 16x16, HME_L2=8x3 instead of 16x16, MAX_ME=64x32 instead 64x64
#define FEATURE_DC_ONLY_AT_NON_REF                       1 // use only intra dc at non reference frame
#define TUNE_PALETTE_LEVEL                       1 // palette level will only be 6 for temporal layer == 0, not encode preset <=M3
#define FEATURE_MDS0_ELIMINATE_CAND                  1 // Eliminate candidates based on the estimated cost of the distortion in mds0.
#define TUNE_TPL_TOWARD_CHROMA                       1 //Tune TPL for better chroma. Only for 240P
#define TUNE_LOW_DELAY                               1 // Tuning the 0B, 1B and 3B settings to support mingop 1, 2 and 4

#define FEATURE_RE_ENCODE         1 // Add re-encode support
#define FIX_VBR_LAST_GOP_BITS     1 // Fix 2nd pass last small group too big frame size error
#define FIX_ONE_MIN_QP_ALLOWED    1 // Set default min_qp_allowed=1 for VBR good quality
#define FIX_ALLOW_SB128_2PASS_VBR 1 // To allow SB128x128 for 2pass VBR
#define FIX_2PASS_VBR_4L_SUPPORT  1 // Add 2pass VBR 4L support
#define FIX_FIRST_PASS_HME        1 // Fix the hme/me based reference pruning level for the first pass


#define FEATURE_FIRST_PASS_RESTRUCTURE 1 // Restructure the first pass and move it to PD.
#define FEATURE_LAP_ENABLED_VBR        1 // Support for LAD enabled VBR
#define TUNE_VBR_CODE_UPDATE           1 // Updated the 2 PASS VBR code based on the lastest aom


#define TUNE_NEW_PRESETS                             1 // Preset tuning for M0-M7
#define FIX_VALID_BLOCK_DERIVATION_OPT 1 // Initialize avail_blk_flag to false
#define FIX_INTERPOLATION_SEARCH 1 // Fix initialization for interpolation search
#define FIX_IRC_IDX 1 // Fix initial_rate_control_reorder_queue[] index error

//FOR DEBUGGING - Do not remove
#define NO_ENCDEC         0 // bypass encDec to test cmpliance of MD. complained achieved when skip_flag is OFF. Port sample code from VCI-SW_AV1_Candidate1 branch
#define DEBUG_TPL         0 // Prints to debug TPL
#ifdef __cplusplus
}
#endif // __cplusplus

#endif // EbDebugMacros_h
