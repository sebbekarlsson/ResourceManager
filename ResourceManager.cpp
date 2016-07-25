#include "ResourceManager.h"


map<string, string> ResourceManager::files;

/**
 * Get the contents of a file stored in the ResourceManager::files
 *
 * @param string filename
 *
 * @return string
 */
string ResourceManager::get(string filename) {
    if (ResourceManager::files.at(filename).empty()) {
        return "";
    }

    return ResourceManager::files.at(filename);
}

/**
 * Load a file into the ResourceManager::files
 *
 * @param string filename
 *
 * @return bool
 */
bool ResourceManager::loadFile(string filename) {
    ifstream inFile;
    inFile.open(filename);

    stringstream strStream;
    strStream << inFile.rdbuf();
    string content = strStream.str();

    ResourceManager::files.insert(pair<string, string>(filename, content));

    return !ResourceManager::get(filename).empty();
}
