# ResourceManager
> Easily load resources/files in C++

## Install
> There is no good way of installing it currently, I would suggest just to
> perform a:

        git clone https://github.com/plasticboy/vim-markdown.git

> into your project, and include the ResourceManager.h

## Usage
### Remember to include the header:

        #include "ResourceManager.h"
        #include <string>

### Loading a file into the memory

        ResourceManager::load("example.txt"); // returns true or false

### Getting the content from a loaded file from the RAM

        ResourceManager::get("example.txt"); // returns a string

> This will not read the file from the harddrive/filesystem, it will read the
> loaded file from the RAM.

### Writing to a loaded file inside of the RAM

        ResourceManager::write("example.txt", "Hello World"); // returns true or false

> This will not write directly to the harddrive/filesystem, it will write to the
> cached/RAM file.

### Saving/Updating a file from the RAM memory to the filesystem/harddrive

        ResourceManager::save("example.txt"); // returns true or false

> This will write to the harddrive/filesystem.

### Unloading a loaded file, removing it from the RAM

        ResourceManager::unload("example.txt"); // returns true or false
