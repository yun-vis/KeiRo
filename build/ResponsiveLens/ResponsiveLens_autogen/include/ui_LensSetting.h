/********************************************************************************
** Form generated from reading UI file 'LensSetting.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LENSSETTING_H
#define UI_LENSSETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LensSetting
{
public:
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_3;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_data;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QLabel *lbl_Data;
    QLineEdit *lineEdit_Data;
    QPushButton *btn_BrowseData;
    QGroupBox *groupBox_parameter;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lbl_Increase;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *le_Increase;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lbl_ZeroIncrease;
    QSlider *hSlider_Increase;
    QLabel *lbl_MaxIncrease;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *lbl_SiblingRatio;
    QSpacerItem *horizontalSpacer_7;
    QLineEdit *le_SiblingRatio;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_4;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *lbl_ZeroRatio;
    QSlider *hSlider_SiblingRatio;
    QLabel *lbl_MaxRatio;
    QWidget *horizontalLayoutWidget_6;
    QHBoxLayout *horizontalLayout_7;
    QLabel *lbl_MinSize;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *le_MinSize;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_6;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *horizontalLayout_6;
    QLabel *lbl_ZeroMin;
    QSlider *hSlider_MinSize;
    QLabel *lbl_MaxMin;
    QGroupBox *groupBox_attribute;
    QScrollArea *scrollArea_NodeInfo;
    QWidget *scrollAreaWidgetContents_NodeInfo;
    QLabel *label_SelectedNodes;
    QLabel *label_FontSizes;
    QScrollArea *scrollArea_FontsizeInfo;
    QWidget *scrollAreaWidgetContents_FontsizeInfo;

    void setupUi(QWidget *LensSetting)
    {
        if (LensSetting->objectName().isEmpty())
            LensSetting->setObjectName(QString::fromUtf8("LensSetting"));
        LensSetting->setEnabled(true);
        LensSetting->resize(500, 540);
        LensSetting->setMinimumSize(QSize(500, 540));
        LensSetting->setMaximumSize(QSize(500, 540));
        LensSetting->setFocusPolicy(Qt::TabFocus);
        gridLayout = new QGridLayout(LensSetting);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        scrollArea = new QScrollArea(LensSetting);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setMaximumSize(QSize(16777215, 570));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 474, 510));
        scrollAreaWidgetContents_3->setMinimumSize(QSize(0, 510));
        scrollAreaWidgetContents_3->setMaximumSize(QSize(16777215, 510));
        layoutWidget = new QWidget(scrollAreaWidgetContents_3);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 776, 561));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        groupBox_data = new QGroupBox(layoutWidget);
        groupBox_data->setObjectName(QString::fromUtf8("groupBox_data"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_data->sizePolicy().hasHeightForWidth());
        groupBox_data->setSizePolicy(sizePolicy);
        groupBox_data->setMinimumSize(QSize(0, 60));
        groupBox_data->setMaximumSize(QSize(460, 60));
        layoutWidget1 = new QWidget(groupBox_data);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 20, 441, 33));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lbl_Data = new QLabel(layoutWidget1);
        lbl_Data->setObjectName(QString::fromUtf8("lbl_Data"));

        horizontalLayout->addWidget(lbl_Data);

        lineEdit_Data = new QLineEdit(layoutWidget1);
        lineEdit_Data->setObjectName(QString::fromUtf8("lineEdit_Data"));

        horizontalLayout->addWidget(lineEdit_Data);

        btn_BrowseData = new QPushButton(layoutWidget1);
        btn_BrowseData->setObjectName(QString::fromUtf8("btn_BrowseData"));

        horizontalLayout->addWidget(btn_BrowseData);


        verticalLayout->addWidget(groupBox_data);

        groupBox_parameter = new QGroupBox(layoutWidget);
        groupBox_parameter->setObjectName(QString::fromUtf8("groupBox_parameter"));
        groupBox_parameter->setMinimumSize(QSize(0, 220));
        groupBox_parameter->setMaximumSize(QSize(460, 220));
        horizontalLayoutWidget = new QWidget(groupBox_parameter);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 30, 441, 31));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        lbl_Increase = new QLabel(horizontalLayoutWidget);
        lbl_Increase->setObjectName(QString::fromUtf8("lbl_Increase"));
        lbl_Increase->setEnabled(false);

        horizontalLayout_2->addWidget(lbl_Increase);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        le_Increase = new QLineEdit(horizontalLayoutWidget);
        le_Increase->setObjectName(QString::fromUtf8("le_Increase"));
        le_Increase->setEnabled(false);
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(le_Increase->sizePolicy().hasHeightForWidth());
        le_Increase->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(le_Increase);

        label_3 = new QLabel(horizontalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setEnabled(false);

        horizontalLayout_2->addWidget(label_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        horizontalLayoutWidget_2 = new QWidget(groupBox_parameter);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 60, 441, 31));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        lbl_ZeroIncrease = new QLabel(horizontalLayoutWidget_2);
        lbl_ZeroIncrease->setObjectName(QString::fromUtf8("lbl_ZeroIncrease"));
        lbl_ZeroIncrease->setEnabled(false);

        horizontalLayout_3->addWidget(lbl_ZeroIncrease);

        hSlider_Increase = new QSlider(horizontalLayoutWidget_2);
        hSlider_Increase->setObjectName(QString::fromUtf8("hSlider_Increase"));
        hSlider_Increase->setEnabled(false);
        hSlider_Increase->setMaximum(20);
        hSlider_Increase->setSliderPosition(20);
        hSlider_Increase->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(hSlider_Increase);

        lbl_MaxIncrease = new QLabel(horizontalLayoutWidget_2);
        lbl_MaxIncrease->setObjectName(QString::fromUtf8("lbl_MaxIncrease"));
        lbl_MaxIncrease->setEnabled(false);

        horizontalLayout_3->addWidget(lbl_MaxIncrease);

        horizontalLayoutWidget_3 = new QWidget(groupBox_parameter);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(10, 90, 441, 31));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        lbl_SiblingRatio = new QLabel(horizontalLayoutWidget_3);
        lbl_SiblingRatio->setObjectName(QString::fromUtf8("lbl_SiblingRatio"));
        lbl_SiblingRatio->setEnabled(false);
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lbl_SiblingRatio->sizePolicy().hasHeightForWidth());
        lbl_SiblingRatio->setSizePolicy(sizePolicy2);

        horizontalLayout_4->addWidget(lbl_SiblingRatio);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);

        le_SiblingRatio = new QLineEdit(horizontalLayoutWidget_3);
        le_SiblingRatio->setObjectName(QString::fromUtf8("le_SiblingRatio"));
        le_SiblingRatio->setEnabled(false);
        sizePolicy1.setHeightForWidth(le_SiblingRatio->sizePolicy().hasHeightForWidth());
        le_SiblingRatio->setSizePolicy(sizePolicy1);
        le_SiblingRatio->setMinimumSize(QSize(100, 0));
        le_SiblingRatio->setBaseSize(QSize(100, 0));

        horizontalLayout_4->addWidget(le_SiblingRatio);

        label_4 = new QLabel(horizontalLayoutWidget_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setEnabled(false);

        horizontalLayout_4->addWidget(label_4);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        horizontalLayoutWidget_4 = new QWidget(groupBox_parameter);
        horizontalLayoutWidget_4->setObjectName(QString::fromUtf8("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(10, 120, 441, 31));
        horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        lbl_ZeroRatio = new QLabel(horizontalLayoutWidget_4);
        lbl_ZeroRatio->setObjectName(QString::fromUtf8("lbl_ZeroRatio"));
        lbl_ZeroRatio->setEnabled(false);

        horizontalLayout_5->addWidget(lbl_ZeroRatio);

        hSlider_SiblingRatio = new QSlider(horizontalLayoutWidget_4);
        hSlider_SiblingRatio->setObjectName(QString::fromUtf8("hSlider_SiblingRatio"));
        hSlider_SiblingRatio->setEnabled(false);
        hSlider_SiblingRatio->setMaximum(100);
        hSlider_SiblingRatio->setSliderPosition(100);
        hSlider_SiblingRatio->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(hSlider_SiblingRatio);

        lbl_MaxRatio = new QLabel(horizontalLayoutWidget_4);
        lbl_MaxRatio->setObjectName(QString::fromUtf8("lbl_MaxRatio"));
        lbl_MaxRatio->setEnabled(false);
        sizePolicy2.setHeightForWidth(lbl_MaxRatio->sizePolicy().hasHeightForWidth());
        lbl_MaxRatio->setSizePolicy(sizePolicy2);

        horizontalLayout_5->addWidget(lbl_MaxRatio);

        horizontalLayoutWidget_6 = new QWidget(groupBox_parameter);
        horizontalLayoutWidget_6->setObjectName(QString::fromUtf8("horizontalLayoutWidget_6"));
        horizontalLayoutWidget_6->setGeometry(QRect(10, 150, 441, 31));
        horizontalLayout_7 = new QHBoxLayout(horizontalLayoutWidget_6);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        lbl_MinSize = new QLabel(horizontalLayoutWidget_6);
        lbl_MinSize->setObjectName(QString::fromUtf8("lbl_MinSize"));
        lbl_MinSize->setEnabled(false);
        sizePolicy2.setHeightForWidth(lbl_MinSize->sizePolicy().hasHeightForWidth());
        lbl_MinSize->setSizePolicy(sizePolicy2);

        horizontalLayout_7->addWidget(lbl_MinSize);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_3);

        le_MinSize = new QLineEdit(horizontalLayoutWidget_6);
        le_MinSize->setObjectName(QString::fromUtf8("le_MinSize"));
        le_MinSize->setEnabled(false);
        sizePolicy1.setHeightForWidth(le_MinSize->sizePolicy().hasHeightForWidth());
        le_MinSize->setSizePolicy(sizePolicy1);
        le_MinSize->setMinimumSize(QSize(100, 0));
        le_MinSize->setBaseSize(QSize(100, 0));

        horizontalLayout_7->addWidget(le_MinSize);

        label_5 = new QLabel(horizontalLayoutWidget_6);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setEnabled(false);

        horizontalLayout_7->addWidget(label_5);

        horizontalSpacer_6 = new QSpacerItem(38, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_6);

        horizontalLayoutWidget_5 = new QWidget(groupBox_parameter);
        horizontalLayoutWidget_5->setObjectName(QString::fromUtf8("horizontalLayoutWidget_5"));
        horizontalLayoutWidget_5->setGeometry(QRect(10, 180, 441, 31));
        horizontalLayout_6 = new QHBoxLayout(horizontalLayoutWidget_5);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        lbl_ZeroMin = new QLabel(horizontalLayoutWidget_5);
        lbl_ZeroMin->setObjectName(QString::fromUtf8("lbl_ZeroMin"));
        lbl_ZeroMin->setEnabled(false);

        horizontalLayout_6->addWidget(lbl_ZeroMin);

        hSlider_MinSize = new QSlider(horizontalLayoutWidget_5);
        hSlider_MinSize->setObjectName(QString::fromUtf8("hSlider_MinSize"));
        hSlider_MinSize->setEnabled(false);
        hSlider_MinSize->setMaximum(100);
        hSlider_MinSize->setSliderPosition(100);
        hSlider_MinSize->setOrientation(Qt::Horizontal);

        horizontalLayout_6->addWidget(hSlider_MinSize);

        lbl_MaxMin = new QLabel(horizontalLayoutWidget_5);
        lbl_MaxMin->setObjectName(QString::fromUtf8("lbl_MaxMin"));
        lbl_MaxMin->setEnabled(false);
        sizePolicy2.setHeightForWidth(lbl_MaxMin->sizePolicy().hasHeightForWidth());
        lbl_MaxMin->setSizePolicy(sizePolicy2);

        horizontalLayout_6->addWidget(lbl_MaxMin);


        verticalLayout->addWidget(groupBox_parameter);

        groupBox_attribute = new QGroupBox(layoutWidget);
        groupBox_attribute->setObjectName(QString::fromUtf8("groupBox_attribute"));
        groupBox_attribute->setMaximumSize(QSize(460, 280));
        scrollArea_NodeInfo = new QScrollArea(groupBox_attribute);
        scrollArea_NodeInfo->setObjectName(QString::fromUtf8("scrollArea_NodeInfo"));
        scrollArea_NodeInfo->setGeometry(QRect(240, 50, 211, 171));
        sizePolicy1.setHeightForWidth(scrollArea_NodeInfo->sizePolicy().hasHeightForWidth());
        scrollArea_NodeInfo->setSizePolicy(sizePolicy1);
        scrollArea_NodeInfo->setMaximumSize(QSize(450, 16777215));
        scrollArea_NodeInfo->setWidgetResizable(true);
        scrollAreaWidgetContents_NodeInfo = new QWidget();
        scrollAreaWidgetContents_NodeInfo->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_NodeInfo"));
        scrollAreaWidgetContents_NodeInfo->setGeometry(QRect(0, 0, 209, 169));
        scrollArea_NodeInfo->setWidget(scrollAreaWidgetContents_NodeInfo);
        label_SelectedNodes = new QLabel(groupBox_attribute);
        label_SelectedNodes->setObjectName(QString::fromUtf8("label_SelectedNodes"));
        label_SelectedNodes->setGeometry(QRect(240, 30, 151, 18));
        label_FontSizes = new QLabel(groupBox_attribute);
        label_FontSizes->setObjectName(QString::fromUtf8("label_FontSizes"));
        label_FontSizes->setGeometry(QRect(10, 30, 141, 16));
        scrollArea_FontsizeInfo = new QScrollArea(groupBox_attribute);
        scrollArea_FontsizeInfo->setObjectName(QString::fromUtf8("scrollArea_FontsizeInfo"));
        scrollArea_FontsizeInfo->setGeometry(QRect(10, 50, 211, 171));
        scrollArea_FontsizeInfo->setWidgetResizable(true);
        scrollAreaWidgetContents_FontsizeInfo = new QWidget();
        scrollAreaWidgetContents_FontsizeInfo->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_FontsizeInfo"));
        scrollAreaWidgetContents_FontsizeInfo->setGeometry(QRect(0, 0, 209, 169));
        scrollArea_FontsizeInfo->setWidget(scrollAreaWidgetContents_FontsizeInfo);

        verticalLayout->addWidget(groupBox_attribute);

        scrollArea->setWidget(scrollAreaWidgetContents_3);

        gridLayout->addWidget(scrollArea, 0, 1, 1, 1);


        retranslateUi(LensSetting);

        QMetaObject::connectSlotsByName(LensSetting);
    } // setupUi

    void retranslateUi(QWidget *LensSetting)
    {
        LensSetting->setWindowTitle(QCoreApplication::translate("LensSetting", "Setting", nullptr));
        groupBox_data->setTitle(QCoreApplication::translate("LensSetting", "Data", nullptr));
        lbl_Data->setText(QCoreApplication::translate("LensSetting", "Data:", nullptr));
        btn_BrowseData->setText(QCoreApplication::translate("LensSetting", "Browse", nullptr));
        groupBox_parameter->setTitle(QCoreApplication::translate("LensSetting", "Parameters", nullptr));
        lbl_Increase->setText(QCoreApplication::translate("LensSetting", "Increase selected by", nullptr));
        label_3->setText(QCoreApplication::translate("LensSetting", "%        ", nullptr));
        lbl_ZeroIncrease->setText(QCoreApplication::translate("LensSetting", "0%", nullptr));
        lbl_MaxIncrease->setText(QCoreApplication::translate("LensSetting", "20%            ", nullptr));
        lbl_SiblingRatio->setText(QCoreApplication::translate("LensSetting", "Sibling ratio               ", nullptr));
        label_4->setText(QCoreApplication::translate("LensSetting", "%        ", nullptr));
        lbl_ZeroRatio->setText(QCoreApplication::translate("LensSetting", "0%", nullptr));
        lbl_MaxRatio->setText(QCoreApplication::translate("LensSetting", "100%          ", nullptr));
        lbl_MinSize->setText(QCoreApplication::translate("LensSetting", "Minimum size            ", nullptr));
        label_5->setText(QCoreApplication::translate("LensSetting", "<html><head/><body><p>\302\267 10<span style=\" vertical-align:super;\">-2 </span>%</p></body></html>", nullptr));
        lbl_ZeroMin->setText(QCoreApplication::translate("LensSetting", "<html><head/><body><p>0%</p></body></html>", nullptr));
        lbl_MaxMin->setText(QCoreApplication::translate("LensSetting", "<html><head/><body><p>100 \302\267 10<span style=\" vertical-align:super;\">-2</span> %</p></body></html>", nullptr));
        groupBox_attribute->setTitle(QCoreApplication::translate("LensSetting", "Attributes", nullptr));
        label_SelectedNodes->setText(QCoreApplication::translate("LensSetting", "Selected nodes", nullptr));
        label_FontSizes->setText(QCoreApplication::translate("LensSetting", "Font sizes by levels", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LensSetting: public Ui_LensSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LENSSETTING_H
