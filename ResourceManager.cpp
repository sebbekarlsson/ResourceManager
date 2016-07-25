#include "ResourceManager.h"


std::map<std::string, std::string> ResourceManager::files;

/**
 * Get the contents of a file stored in the ResourceManager::files
 *
 * @param string filename
 *
 * @return string
 */
std::string ResourceManager::get(std::string filename) {
    try {
        return ResourceManager::files.at(filename);
    } catch(std::exception &e) {
        throw std::runtime_error(std::string("No such file: " + filename));
    }
}

/**
 * Load a file into the ResourceManager::files
 *
 * @param string filename
 *
 * @return bool
 */
bool ResourceManager::loadFile(std::string filename) {
    std::ifstream inFile;
    inFile.open(filename);

    std::stringstream strStream;
    strStream << inFile.rdbuf();
    std::string content = strStream.str();

    ResourceManager::files.insert(std::pair<std::string, std::string>(filename, content));

    return !ResourceManager::get(filename).empty();
}
