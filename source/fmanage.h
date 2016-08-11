#ifndef __FMANAGE_H__
#define __FMANAGE_H__

#include <map>
#include <vector>
#include <fstream>

#define DIR_SEPARATOR "/"

class FileManager
{
    public:
        static bool SetContents(std::string filename, std::string content, bool relative = true);

        static std::string GetContents(std::string filename, bool relative = true);

        static std::vector<std::string> GetFilesInFolder(std::string folder);

        static std::string GetCWD();

        static std::string GetFilenameWithoutExt(std::string filename);

        static std::string GetFilenameExt(std::string filename);
};

#endif //FMANAGE_H
