#ifndef __FMANAGE_H__
#define __FMANAGE_H__

#include <unordered_map>
#include <vector>
#include <fstream>

#include <sys/param.h>
#include <dirent.h>

#define DIR_SEPARATOR "/"

class FileManager
{
	public:
		static bool SetContents(std::string filename, std::string content, bool relative = true);

		static std::string GetContents(std::string filename, bool relative = true);

		static std::vector<std::string> GetFilesInFolder(const std::string folder);

		static std::string GetCWD();

		static std::string GetFilenameWithoutExt(const std::string filename);

		static std::string GetFilenameExt(const std::string filename);
};

#endif //FMANAGE_H
