//
// Created by Daniel Byomujuni on 10/8/23.
//

#include <string>
#include <vector>
#include "CommandManager.h"
#include "commands/depricated/LatestCommand.h"
#include "commands/depricated/HelpCommand.h"

void CommandManager::registerCommands() {
    //new AddCommand;
    //new LatestCommand;
    //new HelpCommand;
}

CommandManager* CommandManager::instance() {
    if (CommandManager::inst == NULL) {
        CommandManager::inst = new CommandManager();
        return CommandManager::inst;
    }
    return CommandManager::inst;
}