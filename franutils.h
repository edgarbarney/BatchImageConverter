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
		// If nullable, 0 means don't do it
		bool advanced;			// Did user enable advanced opitons?
		int quality;			// Nullable - 1-100 JPEG Quality
		unsigned short flip;	// Nullable - 1=flip (v), 2=flop (h), 3=both
		double rotation;		// Nullable - Rotation in degrees. Counter Clockwise
		unsigned short negate;	// Nullable - 1=Invert Volors, 2=Invert Grayscale Only
		bool ignoreAnim;		// Should we ignore animations (GIFs etc.)?
	} convFlags;

	std::string QstToStd(QString qstToConv);
	std::string RemoveExtFromFilename(const std::string& filename); // Thanks to olrp

	void ConvertImage(std::string filedir, std::string newext, QString destPath, std::string fileName, bool overwrite, convFlags flags);
	void ReplaceAll(std::string& input, const std::string& from, const std::string& to);
}
#endif // FRANUTILS_H
