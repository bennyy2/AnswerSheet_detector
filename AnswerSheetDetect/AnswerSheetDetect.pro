TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

INCLUDEPATH += C:\opencv\build\install\include

LIBS += C:\opencv\build\bin\libopencv_core331.dll
LIBS += C:\opencv\build\bin\libopencv_highgui331.dll
LIBS += C:\opencv\build\bin\libopencv_imgcodecs331.dll
LIBS += C:\opencv\build\bin\libopencv_imgproc331.dll
LIBS += C:\opencv\build\bin\libopencv_features2d331.dll
LIBS += C:\opencv\build\bin\libopencv_calib3d331.dll

HEADERS +=
