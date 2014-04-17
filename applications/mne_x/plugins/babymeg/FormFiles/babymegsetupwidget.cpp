//=============================================================================================================
/**
* @file     babymegsetupwidget.cpp
* @author   Christoph Dinh <chdinh@nmr.mgh.harvard.edu>;
*           Matti Hamalainen <msh@nmr.mgh.harvard.edu>
* @version  1.0
* @date     February, 2013
*
* @section  LICENSE
*
* Copyright (C) 2013, Christoph Dinh and Matti Hamalainen. All rights reserved.
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
* @brief    Contains the implementation of the RTServerSetupWidget class.
*
*/

//*************************************************************************************************************
//=============================================================================================================
// INCLUDES
//=============================================================================================================

#include "babymegsetupwidget.h"
#include "babymegaboutwidget.h"

#include "babymegsquidcontroldgl.h"

#include "../babymeg.h"


//*************************************************************************************************************
//=============================================================================================================
// QT INCLUDES
//=============================================================================================================

#include <QDir>
#include <QDebug>
#include <QComboBox>


//*************************************************************************************************************
//=============================================================================================================
// USED NAMESPACES
//=============================================================================================================

using namespace BabyMEGPlugin;


//*************************************************************************************************************
//=============================================================================================================
// DEFINE MEMBER METHODS
//=============================================================================================================

BabyMEGSetupWidget::BabyMEGSetupWidget(BabyMEG* p_pBabyMEG, QWidget* parent)
: QWidget(parent)
, m_pBabyMEG(p_pBabyMEG)
, m_bIsInit(false)
{
    ui.setupUi(this);

    //Record data checkbox
    connect(ui.m_qCheckBox_RecordData, &QCheckBox::stateChanged, this, &BabyMEGSetupWidget::checkedRecordDataChanged);

    //Fiff record file
    connect(ui.m_qPushButton_FiffRecordFile, &QPushButton::released, this, &BabyMEGSetupWidget::pressedFiffRecordFile);


    connect(m_pBabyMEG, &BabyMEG::cmdConnectionChanged, this, &BabyMEGSetupWidget::cmdConnectionChanged);

    //rt server fiffInfo received
    connect(m_pBabyMEG, &BabyMEG::fiffInfoAvailable, this, &BabyMEGSetupWidget::fiffInfoReceived);

    //About
    connect(ui.m_qPushButton_About, &QPushButton::released, this, &BabyMEGSetupWidget::showAboutDialog);

    //SQUID Control
    connect(ui.m_qPushButtonSqdCtrl, &QPushButton::released, this, &BabyMEGSetupWidget::showSqdCtrlDialog);

    this->init();
}


//*************************************************************************************************************

BabyMEGSetupWidget::~BabyMEGSetupWidget()
{

}


//*************************************************************************************************************

void BabyMEGSetupWidget::init()
{
    checkedRecordDataChanged();
}


//*************************************************************************************************************

void BabyMEGSetupWidget::checkedRecordDataChanged()
{
    if(ui.m_qCheckBox_RecordData->checkState() == Qt::Checked)
    {
        ui.m_qComboBox_SubjectSelection->setEnabled(true);
        ui.m_qPushButton_NewSubject->setEnabled(true);
        ui.m_qLineEdit_FiffRecordFile->setEnabled(true);
        ui.m_qPushButton_FiffRecordFile->setEnabled(true);
    }
    else
    {
        ui.m_qComboBox_SubjectSelection->setEnabled(false);
        ui.m_qPushButton_NewSubject->setEnabled(false);
        ui.m_qLineEdit_FiffRecordFile->setEnabled(false);
        ui.m_qPushButton_FiffRecordFile->setEnabled(false);
    }
}


//*************************************************************************************************************

void BabyMEGSetupWidget::pressedFiffRecordFile()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Fiff Record File"), "", tr("Fiff Record File (*.fif)"));

    ui.m_qLineEdit_FiffRecordFile->setText(fileName);
}


//*************************************************************************************************************

void BabyMEGSetupWidget::cmdConnectionChanged(bool p_bConnectionStatus)
{

}


//*************************************************************************************************************

void BabyMEGSetupWidget::fiffInfoReceived()
{
    if(m_pBabyMEG->m_pFiffInfo)
        this->ui.m_qLabel_sps->setText(QString("%1").arg(m_pBabyMEG->m_pFiffInfo->sfreq));
}


//*************************************************************************************************************

void BabyMEGSetupWidget::showAboutDialog()
{
    BabyMEGAboutWidget aboutDialog(this);
    aboutDialog.exec();
}


//*************************************************************************************************************

void BabyMEGSetupWidget::showSqdCtrlDialog()
{
    BabyMEGSQUIDControlDgl SQUIDCtrlDlg(m_pBabyMEG,this);
    SQUIDCtrlDlg.exec();
}
