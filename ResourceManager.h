#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <streambuf>
#include <sstream>
#include <map>
#include <exception>


#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

class ResourceManager {
    public:
        static std::string dump();
        static std::string get(std::string filename);
        static bool load(std::string filename);
        static bool unload(std::string filename);
        static bool isLoaded(std::string filename);
        static bool save(std::string filename);
        static bool writeNew(std::string filename, std::string content);
        static bool fileExists(std::string filename);
        static bool write(
                std::string filename,
                std::string content,
                bool append=false
                );
    private:
        static std::map<std::string, std::string> files;
};

#endif
