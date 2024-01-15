//
// Created by Daniel Byomujuni on 1/15/24.
//

#ifndef MANGAMANAGER_BASECOMMANDMANAGER_H
#define MANGAMANAGER_BASECOMMANDMANAGER_H


#include <map>
#include <string>
#include "BaseCommand.h"

class BaseCommandManager {
    std::map<std::string, BaseCommand* > commands;
public:
    virtual void registerCommands();
    void addCommand(std::string alias, BaseCommand *cmd);
    void runCommand(std::string cmd, std::vector<std::string> args);
};


#endif //MANGAMANAGER_BASECOMMANDMANAGER_H
