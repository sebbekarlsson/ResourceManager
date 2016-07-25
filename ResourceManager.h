#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <streambuf>
#include <sstream>
#include <map>


#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

using namespace std;

class ResourceManager {
    public:
        static string get(string filename);
        static bool loadFile(string filename);

    private:
        static map<string, string> files; 
};

#endif
