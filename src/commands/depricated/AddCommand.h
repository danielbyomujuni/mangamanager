//
// Created by Daniel Byomujuni on 10/8/23.
//

#ifndef MANGAMANAGER_ADDCOMMAND_H
#define MANGAMANAGER_ADDCOMMAND_H


#include <string>
#include "../abstract/BaseCommand.h"

class AddCommand: public BaseCommand {
private:
    void mangaCMD(std::string seriesName);
    void volumesCMD(std::string name, std::string count);

public:
    AddCommand();
    int execute(std::vector<std::string> args);
};



#endif //MANGAMANAGER_ADDCOMMAND_H
