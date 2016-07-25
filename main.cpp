#include "ResourceManager.h"
#include <string>


int main(int ac, char** av) {
    std::string s;

    // this one returns true or false
    bool ok = ResourceManager::loadFile("example.txt");

    if (ok) {
        // this one returns a std::string
        s = ResourceManager::get("example.txt");

        cout << s << endl;
    }

    return 0;
};
