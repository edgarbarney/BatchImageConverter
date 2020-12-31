QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    franutils.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    franutils.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    BatchImageConverter_en_GB.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

unix|win32: LIBS += -L'C:/Program Files/ImageMagick-7.0.10-Q16-HDRI/lib/' -lCORE_RL_Magick++_

INCLUDEPATH += 'C:/Program Files/ImageMagick-7.0.10-Q16-HDRI/include'
DEPENDPATH += 'C:/Program Files/ImageMagick-7.0.10-Q16-HDRI/include'

win32:!win32-g++: PRE_TARGETDEPS += 'C:/Program Files/ImageMagick-7.0.10-Q16-HDRI/lib/CORE_RL_Magick++_.lib'
else:unix|win32-g++: PRE_TARGETDEPS += 'C:/Program Files/ImageMagick-7.0.10-Q16-HDRI/lib/libCORE_RL_Magick++_.a'

unix|win32: LIBS += -L'C:/Program Files/ImageMagick-7.0.10-Q16-HDRI/lib/' -lCORE_RL_MagickCore_

INCLUDEPATH += 'C:/Program Files/ImageMagick-7.0.10-Q16-HDRI/include'
DEPENDPATH += 'C:/Program Files/ImageMagick-7.0.10-Q16-HDRI/include'

win32:!win32-g++: PRE_TARGETDEPS += 'C:/Program Files/ImageMagick-7.0.10-Q16-HDRI/lib/CORE_RL_MagickCore_.lib'
else:unix|win32-g++: PRE_TARGETDEPS += 'C:/Program Files/ImageMagick-7.0.10-Q16-HDRI/lib/libCORE_RL_MagickCore_.a'

unix|win32: LIBS += -L'C:/Program Files/ImageMagick-7.0.10-Q16-HDRI/lib/' -lCORE_RL_MagickWand_

INCLUDEPATH += 'C:/Program Files/ImageMagick-7.0.10-Q16-HDRI/include'
DEPENDPATH += 'C:/Program Files/ImageMagick-7.0.10-Q16-HDRI/include'

win32:!win32-g++: PRE_TARGETDEPS += 'C:/Program Files/ImageMagick-7.0.10-Q16-HDRI/lib/CORE_RL_MagickWand_.lib'
else:unix|win32-g++: PRE_TARGETDEPS += 'C:/Program Files/ImageMagick-7.0.10-Q16-HDRI/lib/libCORE_RL_MagickWand_.a'
