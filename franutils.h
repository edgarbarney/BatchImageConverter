#ifndef FRANUTILS_H
#define FRANUTILS_H

#include <string>
#include <QString>
#include <Magick++.h>
#include <QString>
#include <iostream>

using namespace std;
using namespace Magick;

namespace franticUtils
{
	std::string QstToStd(QString qstToConv);
	void ConvertImage(string filedir, string newext, QString destPath, string fileName);
	void ReplaceAll(std::string& input, const std::string& from, const std::string& to);
}
#endif // FRANUTILS_H
