#include "franutils.h"
#include <filesystem>
#include <algorithm>

namespace franticUtils
{
	std::string QstToStd(QString qstToConv)
    {
    #if defined(Q_OS_WIN)
        return qstToConv.toLocal8Bit().constData();
    #else
        return qstToConv.toUtf8().constData();
    #endif
    }

	void ReplaceAll(std::string& input, const std::string& from, const std::string& to) {
	  size_t pos = 0;
	  while ((pos = input.find(from, pos)) != std::string::npos) {
		input.replace(pos, from.size(), to);
		pos += to.size();
	  }
	}

	void ConvertImage(string filedir, string newext, QString destPath, string fileName)
	{
		InitializeMagick("");
		Image image;
		try
		{
			replace(filedir.begin(),filedir.end(),'/','\\');
			ReplaceAll(filedir,"\\","\\\\");
			cout << filedir << endl;
			image.read(filedir);
			newext.insert(0,".");
			image.write(QstToStd(destPath).append(fileName).append(newext));
		}
		catch( Exception &error_ )
		{
			cout << error_.what() << endl;
		}

	}

}
