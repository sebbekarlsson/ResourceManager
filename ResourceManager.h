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
        static bool loadFile(std::string filename);

    private:
        static std::map<std::string, std::string> files; 
};

#endif
