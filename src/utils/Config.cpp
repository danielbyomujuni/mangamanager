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
}

char *Config::getKey(char *key) {
    std::fstream fin;

    fin.open(this->configPath, std::fstream::in);
    // Read the Data from the file
    // as String Vector

    for(std::string line; getline( fin, line );) {
        printf("%s \n", line.data());
        if (line.starts_with(key)) {
            int start = line.find('=') + 1;

            char *value = new char[256];
            memset(value, '\0', 256*sizeof(char));

            strcpy(value,line.substr(start, line.size() - start).c_str());

            while (value[0] == ' ') { value++;} //Drop whitespace from begining

            return value;
        }
    }
    return "";
}

char *Config::getCollectionFile() {
    char* value = this->getKey("Collection_File");
    return value;
}


