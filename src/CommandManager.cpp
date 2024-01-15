//
// Created by Daniel Byomujuni on 10/8/23.
//

#include <vector>
#include "CommandManager.h"
#include "commands/CreateCollectionCommand.h"

void CommandManager::registerCommands() {
    new CreateCollectionCommand;

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