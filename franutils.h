#ifndef FRANUTILS_H
#define FRANUTILS_H


#include <string>
#include <QString>
#include <Magick++.h>
#include <QString>
#include <iostream>

// Commented out because in C++17 and later, bloody QtWidgets' byte conflicts with std::byte.
// The fix will be provided god knows when
//using namespace std;
using namespace Magick;

namespace franticUtils
{
	typedef struct convFlags // Conversion flags
	{
		// If nullable, null means don't do it
		bool advanced;			// Did user enable advanced opitons?
		int quality;			// Nullable - 1-100 JPEG Quality
		unsigned short flip;	// Nullable - 0=flip (v), 1=flop (h), 2=both
		double rotation;		// Nullable - Rotation in degrees. Counter Clockwise
		unsigned short negate;	// Nullable - 0=Invert Volors, 1=Invert Grayscale Only
	} convFlags;

	std::string QstToStd(QString qstToConv);
	std::string RemoveExtFromFilename(const std::string& filename); // Thanks to olrp

	void ConvertImage(std::string filedir, std::string newext, QString destPath, std::string fileName, bool overwrite, convFlags flags);
	void ReplaceAll(std::string& input, const std::string& from, const std::string& to);
}
#endif // FRANUTILS_H
