//
// Created by Daniel Byomujuni on 10/8/23.
//

#ifndef MANGAMANAGER_COMMANDMANAGER_H
#define MANGAMANAGER_COMMANDMANAGER_H


#include <map>
#include "commands/BaseCommand.h"
#include "commands/SetCommand.h"

class CommandManager {
private:
    std::map<std::string, BaseCommand* > commands;
    inline static CommandManager* inst = NULL;

public:
    static CommandManager* instance();
    void registerCommands();
    void addCommand(std::string alias, BaseCommand *cmd);
    void runCommand(std::string cmd, std::vector<std::string> args);
};


#endif //MANGAMANAGER_COMMANDMANAGER_H
