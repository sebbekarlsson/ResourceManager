#include "ResourceManager.h"


std::map<std::string, std::string> ResourceManager::files;

/**
 * Check if a file has been loaded to the RAM/cache
 *
 * @param string filename
 *
 * @return bool
 */
bool ResourceManager::isLoaded(std::string filename) {
    return ResourceManager::files.find(filename) != ResourceManager::files.end();
}

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
bool ResourceManager::load(std::string filename) {
    std::ifstream inFile;
    inFile.open(filename);

    if (!inFile.good()) { return false; }

    std::stringstream strStream;
    strStream << inFile.rdbuf();
    std::string content = strStream.str();

    ResourceManager::files.insert(std::pair<std::string, std::string>(filename, content));

    return true;
}

/**
 * Unload a file from the memory/erase it from memory.
 *
 * @param string filename
 *
 * @return bool
 */
bool ResourceManager::unload(std::string filename) {
    if (!ResourceManager::isLoaded(filename)) { return false; }

    ResourceManager::files.erase(filename);

    return true;
}

/**
 * Write to the cached file in the RAM memory.
 *
 * @param string filename
 * @param string content
 *
 * @return bool
 */
bool ResourceManager::write(
        std::string filename,
        std::string content,
        bool append
) {
    if (!ResourceManager::isLoaded(filename)) { return false; }

    if (append) {
        ResourceManager::files[filename] += content;
    } else {
        ResourceManager::files[filename] = content;
    }

    return true;
}

/**
 * Save a cached file from the RAM memory to the filesystem/harddrive
 *
 * @param string filename
 *
 * @return bool
 */
bool ResourceManager::save(std::string filename) {
    if (!ResourceManager::isLoaded(filename)) { return false; }

    std::ofstream myfile;

    myfile.open(filename, std::ofstream::out | std::ofstream::trunc);
    myfile << ResourceManager::get(filename);
    myfile.close();

    return true;
}
