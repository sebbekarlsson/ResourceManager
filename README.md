# ResourceManager
> Easily load resources/files in C++

## Install
> There is no good way of installing it currently, I would suggest just to
> perform a:

        git clone https://github.com/plasticboy/vim-markdown.git

> into your project, and include the ResourceManager.h

## Usage
> A small example of loading files and reading them:

        #include "ResourceManager.h"
        #include <string>

        std::string s;

        // this one returns true or false
        bool ok = ResourceManager::loadFile("example.txt");

        if (ok) {
            // this one returns a std::string
            s = ResourceManager::get("example.txt");

            cout << s << endl;

            // It's also possible to erase the file from the memory.
            ResourceManager::unload("example.txt");
        }
