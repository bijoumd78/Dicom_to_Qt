#-------------------------------------------------
#
# Project created by QtCreator 2014-11-13T12:10:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DicomToQTImage
TEMPLATE = app

SOURCES += main.cpp\
        dialog.cpp

HEADERS  += dialog.h

FORMS    += dialog.ui

# GDCM
INCLUDEPATH += C:/gdcm-2.4.4/Source/Common
INCLUDEPATH += C:/gdcm-2.4.4/Source/DataDictionary
INCLUDEPATH += C:/gdcm-2.4.4/Source/DataStructureAndEncodingDefinition
INCLUDEPATH += C:/gdcm-2.4.4/Source/InformationObjectDefinition
INCLUDEPATH += C:/gdcm-2.4.4/Source/MediaStorageAndFileFormat
INCLUDEPATH += C:/gdcm-2.4.4/Source/MessageExchangeDefinition
INCLUDEPATH += C:/gdcm-2.4.4_Build/Source/Common

LIBS += -L"C:/gdcm-2.4.4_Build/bin/Debug" \
    -lgdcmcharls \
    -lgdcmCommon \
    -lgdcmDICT \
    -lgdcmDSED \
    -lgdcmexpat \
    -lgdcmgetopt \
    -lgdcmIOD \
    -lgdcmjpeg8 \
    -lgdcmjpeg12 \
    -lgdcmjpeg16 \
    -lgdcmMEXD \
    -lgdcmMSFF \
    -lgdcmopenjpeg \
    -lgdcmzlib \
    -lsocketxx

