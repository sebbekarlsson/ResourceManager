#include "ResourceManager.h"
#include <string>


int main(int ac, char** av) {
    std::string s;

    // this one returns true or false
    bool ok = ResourceManager::load("example.txt");

    if (ok) {
        // this one returns a std::string
        s = ResourceManager::get("example.txt");

        std::cout << s << std::endl;

        // It's also possible to erase the file from the memory.
        ResourceManager::unload("example.txt");
    }

    ResourceManager::load("example2.txt");
    ResourceManager::write("example2.txt", "Hello World");
    ResourceManager::save("example2.txt");
    std::cout << ResourceManager::get("example2.txt") << std::endl;

    return 0;
};
