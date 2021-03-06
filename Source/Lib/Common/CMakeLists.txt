#
# Copyright(c) 2019 Intel Corporation
#
# This source code is subject to the terms of the BSD 2 Clause License and
# the Alliance for Open Media Patent License 1.0. If the BSD 2 Clause License
# was not distributed with this source code in the LICENSE file, you can
# obtain it at https://www.aomedia.org/license/software-license. If the Alliance for Open
# Media Patent License 1.0 was not distributed with this source code in the
# PATENTS file, you can obtain it at https://www.aomedia.org/license/patent-license.
#

# Libraries Directory CMakeLists.txt

macro(test_apply_compiler_flags)
    foreach(cflag ${ARGV})
        string(REGEX REPLACE "[^A-Za-z0-9]" "_" cflag_var "${cflag}")
        set(test_c_flag "C_FLAG${cflag_var}")
        check_c_compiler_flag(${cflag} "${test_c_flag}")
        if(${test_c_flag})
            set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${cflag}")
        endif()
    endforeach()
    if(CMAKE_BUILD_TYPE MATCHES "[Dd][Ee][Bb][Uu][Gg]")
        message(STATUS "${CMAKE_CURRENT_SOURCE_DIR}: ${CMAKE_C_FLAGS}")
    endif()
endmacro()

add_library(common_lib INTERFACE)

add_subdirectory(Codec)
add_subdirectory(C_DEFAULT)

if(NOT COMPILE_C_ONLY AND HAVE_X86_PLATFORM)
    add_subdirectory(ASM_SSE2)
    add_subdirectory(ASM_SSSE3)
    add_subdirectory(ASM_SSE4_1)
    add_subdirectory(ASM_AVX2)
    add_subdirectory(ASM_AVX512)
endif()
