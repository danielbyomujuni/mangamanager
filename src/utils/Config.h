//
// Created by Daniel Byomujuni on 1/9/24.
//

#ifndef MANGAMANAGER_CONFIG_H
#define MANGAMANAGER_CONFIG_H


#include <string>

class Config {
private:
    char *collectionFile;
    char *configPath;
    char *getKey(char* key);

public:
    Config(char *configPath);

    char *getCollectionFile();
    void reload();
};


#endif //MANGAMANAGER_CONFIG_H
