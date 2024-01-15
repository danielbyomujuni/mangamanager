//
// Created by Daniel on 1/8/24.
//

#ifndef MANGAMANAGER_HELPCOMMAND_H
#define MANGAMANAGER_HELPCOMMAND_H


#include "../abstract/BaseCommand.h"

class HelpCommand: public BaseCommand  {
public:
    HelpCommand();
    void execute(std::vector<std::string> args);
};


#endif //MANGAMANAGER_HELPCOMMAND_H
