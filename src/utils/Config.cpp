//
// Created by Daniel Byomujuni on 1/9/24.
//

#include <fstream>
#include <vector>
#include <sstream>
#include <cstring>
#include "Config.h"

Config::Config(char *configPath) {
    this->configPath = configPath;
    this->reload();

}

void Config::reload() {
    this->collectionFile = this->getKey("Collection_File");
}

char *Config::getCollectionFile() {
    return this->collectionFile;
}


char *Config::getKey(char *key) {
    std::fstream fin;
    fin.open(this->configPath, std::fstream::in);
    for(std::string line; getline( fin, line );) {
        if (line.starts_with(key)) {
            int start = line.find('=') + 1;

            char *value = new char[256];
            memset(value, '\0', 256*sizeof(char));
            strcpy(value,line.substr(start, line.size() - start).c_str());
            while (value[0] == ' ') { value++;} //Drop whitespace from begining
            fin.close();
            return value;
        }
    }
    fin.close();
    return "";
}

