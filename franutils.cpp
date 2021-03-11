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

			std::list<Image> frames;
			readImages(&frames, filedir);

			std::cout << "Processing: " << filedir << std::endl;

			if(frames.size() == 1 || flags.ignoreAnim)
			{
				image = frames.front();

				// Flags
				if (flags.advanced) // Did user enable advanced opitons?
				{
					if (flags.quality != 0)
					{
						image.quality(std::clamp(flags.quality, 0 , 100));
						std::cout << "Quality: " << flags.quality << std::endl;
					}
					if (flags.flip != 0)
					{
						switch (flags.flip)
						{
							case 1:
								image.flip();
								std::cout << "Flip: " << flags.quality << std::endl;
								break;
							case 2:
								image.flop();
								std::cout << "Flop: " << flags.quality << std::endl;
								break;
							case 3:
								image.flip();
								image.flop();
								std::cout << "FlipFlop: " << flags.quality << std::endl;
								break;
						}
					}
					if (flags.rotation != 0)
					{
						image.rotate(flags.rotation);
						std::cout << "Rotate: " << flags.quality << std::endl;
					}
					if (flags.negate != 0)
					{
						(flags.negate == 1) ? image.negate() : image.negate(true);
					}
				}
				// Flags End
				newext.insert(0,".");
				std::string finalfile = QstToStd(destPath).append("\\").append(RemoveExtFromFilename(fileName)).append(newext);
				if (!std::filesystem::exists(finalfile) || overwrite)
					image.write(finalfile);
			}
			else
			{
				for(Image& _image : frames)
				{
					// Flags
					if (flags.advanced) // Did user enable advanced opitons?
					{
						if (flags.quality != 0)
						{
							_image.quality(std::clamp(flags.quality, 0 , 100));
							std::cout << "Quality: " << flags.quality << std::endl;
						}
						if (flags.flip != 0)
						{
							switch (flags.flip)
							{
								case 1:
									_image.flip();
									std::cout << "Flip: " << flags.quality << std::endl;
									break;
								case 2:
									_image.flop();
									std::cout << "Flop: " << flags.quality << std::endl;
									break;
								case 3:
									_image.flip();
									_image.flop();
									std::cout << "FlipFlop: " << flags.quality << std::endl;
									break;
							}
						}
						if (flags.rotation != 0)
						{
							image.rotate(flags.rotation);
							std::cout << "Rotate: " << flags.quality << std::endl;
						}
						if (flags.negate != 0)
						{
							(flags.negate == 1) ? _image.negate() : _image.negate(true);
						}
					}
					// Flags End
				}
				newext.insert(0,".");
				std::string finalfile = QstToStd(destPath).append("\\").append(RemoveExtFromFilename(fileName)).append(newext);
				if (!std::filesystem::exists(finalfile) || overwrite)
				{
					writeImages(frames.begin(), frames.end(), finalfile);
				}

			}


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
