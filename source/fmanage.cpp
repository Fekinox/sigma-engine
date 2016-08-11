#include "fmanage.h"
#include "stringify.h"

#include <sys/param.h>
#include <dirent.h>
#include <stdio.h>

bool FileManager::SetContents(std::string filename, std::string content, bool relative)
{
    //If filename is invalid break out
    if(filename == "") return false;

    //If relative is set, set filename to a new path leading to a file
    if(relative) filename = GetCWD() + DIR_SEPARATOR + filename;

    std::ofstream fileHandle;

    fileHandle.open(filename.c_str());

    if(!fileHandle.is_open()) return false;

    fileHandle << content;
    fileHandle.close();

    return true;
}

std::string FileManager::GetContents(std::string filename, bool relative)
{
    //If filename is invalid return nothing
    if(filename == "") return "";

    //If relative is set, set filename to a new path leading to a file
    if(relative) filename = GetCWD() + DIR_SEPARATOR + filename;

    std::string content;
    std::ifstream fileHandle;

    fileHandle.open(filename.c_str());

    if(fileHandle.is_open())
    {
        while(fileHandle.good())
        {
            std::string buffer;
            getline(fileHandle, buffer);
            if(buffer == "") continue;

            content += buffer + "\n";
        }

        fileHandle.close();
    }

    return content;
}

std::vector<std::string> FileManager::GetFilesInFolder(std::string folder)
{
    std::vector<std::string> list;

    std::string cwd = GetCWD();
    std::string path = cwd;

    //If folder isn't null, build a path to the folder
    if(folder != "") path += DIR_SEPARATOR + folder;

    #ifdef __APPLE__
        NSError* error;

        NSString* pathNS = [NSString stringWithUTF8String:path.c_str()];
        NSArray* directoryContents = [[NSFileManager defaultManager] contentsOfDirectoryAtPath:pathNS error:&Error];

        for(id file in directoryContents)
        {
            std::string filename = path + DIR_SEPARATOR + [File cStringUsingEncoding:1];
            List.push_back(filename);
        }
    #else
        DIR* dirHandle = NULL;
        dirent* fileHandle = NULL;

        if((dirHandle = opendir(folder.c_str())) != NULL)
        {
            while((fileHandle = readdir(dirHandle)) != NULL)
            {
                if(std::string(fileHandle->d_name) == ".") continue;
                if(std::string(fileHandle->d_name) == "..") continue;

                std::string filename = path + DIR_SEPARATOR + fileHandle->d_name;

                list.push_back(filename);
            }
            closedir(dirHandle);
        }
        else
        {
            printf("Unable to open directory!");
        }
    #endif

    return list;
}

std::string FileManager::GetCWD()
{
    std::string cwd;

    #ifdef __APPLE__
        NSString* resourcePath = [[NSBundle mainBundle] resourcePath];
        cwd = [resourcePath cStringUsingEncoding:1];
    #else
        char buffer[MAXPATHLEN];
        cwd = (getcwd(buffer, MAXPATHLEN) ? std::string(buffer) : std::string(""));
    #endif

    return cwd;
}

std::string FileManager::GetFilenameWithoutExt(std::string filename)
{
    std::vector<std::string> parts = Stringify::Explode(filename, DIR_SEPARATOR);
    std::string newFilename = parts[parts.size() - 1];

    parts = Stringify::Explode(newFilename, ".");
    newFilename = parts[0];

    return newFilename;
}

std::string FileManager::GetFilenameExt(std::string filename)
{
    std::vector<std::string> parts = Stringify::Explode(filename, DIR_SEPARATOR);

    return (parts.size() <= 1 ? "" : parts[parts.size() - 1]);
}
