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
        static std::string get(std::string filename);
        static bool load(std::string filename);
        static bool unload(std::string filename);
        static bool isLoaded(std::string filename);
        static bool save(std::string filename);
        static bool write(std::string filename, std::string content);
    private:
        static std::map<std::string, std::string> files;
};

#endif
