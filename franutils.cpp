#include "franutils.h"
#include <filesystem>
#include <algorithm>
#include <stdio.h>

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

	void ReplaceAll(std::string& input, const std::string& from, const std::string& to)
	{
	  size_t pos = 0;
	  while ((pos = input.find(from, pos)) != std::string::npos)
	  {
		input.replace(pos, from.size(), to);
		pos += to.size();
	  }
	}

	void ConvertImage(std::string filedir, std::string newext, QString destPath, std::string fileName, bool overwrite, convFlags flags)
	{
		Image image;
		try
		{
			std::cout << "Processing: " << filedir << std::endl;

			image.read(filedir);

			// Flags
			if (flags.advanced) // Did user enable advanced opitons?
			{
				if (flags.quality != NULL)
				{
					image.quality(std::clamp(flags.quality, 0 , 100));
				}
				if (flags.flip != NULL)
				{
					switch (flags.flip)
					{
						case 0:
							image.flip();
							break;
						case 1:
							image.flop();
							break;
						case 2:
							image.flip();
							image.flop();
							break;
					}
				}
				if (flags.rotation != NULL)
				{
					image.rotate(flags.rotation);
				}
				if (flags.negate != NULL)
				{
					(flags.negate == 0) ? image.negate() : image.negate(true);
				}
			}
			// Flags End

			newext.insert(0,".");
			std::string finalfile = QstToStd(destPath).append("\\").append(RemoveExtFromFilename(fileName)).append(newext);
			if (!std::filesystem::exists(finalfile) || overwrite)
				image.write(finalfile);
		}
		catch( Exception &error_ )
		{
			std::cout << error_.what() << std::endl;
		}
	}

	std::string RemoveExtFromFilename(const std::string& filename) // Thanks to olrp
	{
		size_t lastdot = filename.find_last_of(".");

		if (lastdot == std::string::npos)
			return filename;

		return filename.substr(0, lastdot);
	}

}
