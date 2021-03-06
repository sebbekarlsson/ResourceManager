# ResourceManager
> Easily load resources/files in C++

## Install

        make
        sudo make install

## Usage
### Remember to include the header:

        #include <ResourceManager.h>
        #include <string>

### Loading a file into the memory

        ResourceManager::load("example.txt"); // returns true or false

### Getting the content from a loaded file from the RAM

        ResourceManager::get("example.txt"); // returns a string

> This will not read the file from the harddrive/filesystem, it will read the
> loaded file from the RAM.

### Writing to a loaded file inside of the RAM

        ResourceManager::write("example.txt", "Hello World", true); // returns true or false

> This will not write directly to the harddrive/filesystem, it will write to the
> cached/RAM file.<br>
> the <b>third parameter</b> is optional, if set to `true`, it will append to
> the file and not overwrite. (default is `false`)

### Saving/Updating a file from the RAM memory to the filesystem/harddrive

        ResourceManager::save("example.txt"); // returns true or false

> This will write to the harddrive/filesystem.

### Unloading a loaded file, removing it from the RAM

        ResourceManager::unload("example.txt"); // returns true or false

### Compiling your project:

        g++ ... -lresourcemanager
