//=============================================================================================================
/**
* @file     types.h
* @author   Florian Schlembach <florian.schlembach@tu-ilmenau.de>;
*           Christoph Dinh <chdinh@nmr.mgh.harvard.edu>;
*           Matti Hamalainen <msh@nmr.mgh.harvard.edu>;
*           Jens Haueisen <jens.haueisen@tu-ilmenau.de>
* @version  1.0
* @date     January, 2014
*
* @section  LICENSE
*
* Copyright (C) 2014, Florian Schlembach, Christoph Dinh and Matti Hamalainen. All rights reserved.
*
* Redistribution and use in source and binary forms, with or without modification, are permitted provided that
* the following conditions are met:
*     * Redistributions of source code must retain the above copyright notice, this list of conditions and the
*       following disclaimer.
*     * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and
*       the following disclaimer in the documentation and/or other materials provided with the distribution.
*     * Neither the name of the Massachusetts General Hospital nor the names of its contributors may be used
*       to endorse or promote products derived from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
* WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
* PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL MASSACHUSETTS GENERAL HOSPITAL BE LIABLE FOR ANY DIRECT,
* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
* PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
* NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
*
*
* @brief    Contains general application specific types
*
*/

#ifndef TYPES_SETTINGS_H
#define TYPES_SETTINGS_H

//=============================================================================================================
// INCLUDES

//Eigen
#include <Eigen/Core>
#include <Eigen/SparseCore>

//*************************************************************************************************************
// NAMESPACES

using namespace Eigen;

//*************************************************************************************************************

namespace MNE_BROWSE_RAW_QT {

typedef Matrix<double,Dynamic,Dynamic,RowMajor> MatrixXdR;
typedef QPair<const double*,qint32> RowVectorPair;

//maximum values for different types of channels according to FiffChInfo
//#ifndef MAX_MEG_UNIT_T_M
    #define MAX_MEG_UNIT_T_M 1e-10; // kind=FIFFV_MEG_CH && unit=FIFF_UNIT_T_M
    #define MAX_MEG_UNIT_T 1e-11; // kind=FIFFV_MEG_CH && unit=FIFF_UNIT_T
    #define MAX_EEG 1e-4; // kind=FIFFV_EEG_CH
    #define MAX_EOG 1e-3; // kind=FIFFV_EOG_CH
    #define MAX_STIM 5; // kind=FIFFV_STIM_CH
//#endif //MAX_MEG_UNIT_T_M

}


#endif // TYPES_SETTINGS_H
