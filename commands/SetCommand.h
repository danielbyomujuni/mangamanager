//
// Created by Daniel Byomujuni on 10/8/23.
//

#ifndef MANGAMANAGER_SETCOMMAND_H
#define MANGAMANAGER_SETCOMMAND_H


#include <string>
#include "BaseCommand.h"

class SetCommand: public BaseCommand {
    void MangaCMD(std::string name, std::string id);
    void VolumesCMD(std::string name, std::string count);

public:
    SetCommand();
    void execute(std::vector<std::string> args);
};


#endif //MANGAMANAGER_SETCOMMAND_H
