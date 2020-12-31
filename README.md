# Batch Image Converter

This is a project that I'm working on for understanding the basics of the Qt frameworks and Qt Creator.

You can find latest releases [here](https://github.com/edgarbarney/BatchImageConverter/releases).

## Project General Info

Current Qt Version: 6.0.0

Current Used ImageMagick Build: [7.0.10-Q16-HDRI](https://imagemagick.org/download/binaries/ImageMagick-7.0.10-53-Q16-HDRI-x64-static.exe)

Compiler: MSVC2019

## Steps before building

* Make sure you've installed ImageMagick from the link above. If you want to use your own version, make sure you've corrected the ".pro" file.

* This program is mainly developed for Windows. But It should work on Linux as well. Not sure about OSX.

## Steps after building

* ### Libraries (DLLs)
Since this project doesn't (and probably won't) include static libraries of Qt, you'll need to copy necessarry DLLs into your .exe's folder.
I'm doing this step manually by copying them manually from Qt's path
(Example: C:\Qt\6.0.0\msvc2019_64\bin\Qt6Widgets.dll)
But there are ways to [automate](https://forum.qt.io/topic/73235/copying-dlls-into-target-directory/5). And If you want to and have rights to do; you can [configure](https://forum.qt.io/topic/91701/embed-qt-dlls-in-exe) your project to contain static libraries.
