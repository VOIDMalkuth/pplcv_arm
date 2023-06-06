// Licensed to the Apache Software Foundation (ASF) under one
// or more contributor license agreements.  See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  The ASF licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License.  You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.  See the License for the
// specific language governing permissions and limitations
// under the License.

#ifndef __ST_HPC_PPL_CV_ARM_TRANSPOSE_H_
#define __ST_HPC_PPL_CV_ARM_TRANSPOSE_H_

#include "ppl/common/retcode.h"

namespace ppl {
namespace cv {
namespace arm {

/**
* @brief Transposes an image.
* @tparam T The data type of input and output image, currently only \a uint8_t(uchar) and \a float are supported.
* @tparam nc The number of channels of input image and output image, 1, 3 and 4 are supported.
* @param height            input image's height
* @param width             input image's width
* @param inWidthStride     input image's width stride, usually it equals to `width * nc`
* @param inData            input image data
* @param outWidthStride    output image's width stride, usually it equals to `height * nc`
* @param outData           output image data
* @warning All input parameters must be valid, or undefined behaviour may occur.
* @remark The fllowing table show which data type and channels are supported.
* <table>
* <tr><th>Data type(T)<th>channels
* <tr><td>float<td>1
* <tr><td>float<td>3
* <tr><td>float<td>4
* <tr><td>uint8_t(uchar)<td>1
* <tr><td>uint8_t(uchar)<td>3
* <tr><td>uint8_t(uchar)<td>4
* </table>
* <table>
* <caption align="left">Requirements</caption>
* <tr><td>arm platforms supported<td> All 
* <tr><td>Header files<td> #include &lt;ppl/cv/arm/transpose.h&gt;
* <tr><td>Project<td> ppl.cv
* @since ppl.cv-v1.0.0
* ###Example
* @code{.cpp}
* #include <ppl/cv/arm/transpose.h>
* int main(int argc, char** argv) {
*     const int W = 640;
*     const int H = 480;
*     const int C = 3;
*     float* dev_iImage = (float*)malloc(W * H * C * sizeof(float));
*     float* dev_oImage = (float*)malloc(H * W * C * sizeof(float));
*
*     ppl::cv::arm::Transpose<float, 3>(H, W, W * C, dev_iImage, H * C, dev_oImage);
*
*     free(dev_iImage);
*     free(dev_oImage);
*     return 0;
* }
* @endcode
***************************************************************************************************/

template <typename T, int nc>
::ppl::common::RetCode Transpose(int height,
                                 int width,
                                 int inWidthStride,
                                 const T *inData,
                                 int outWidthStride,
                                 T *outData);

}
}
} // namespace ppl::cv::arm
#endif //! __ST_HPC_PPL_CV_ARM_TRANSPOSE_H_
