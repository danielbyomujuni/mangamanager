//
// Created by Daniel Byomujuni on 10/8/23.
//

#include <string>
#include <vector>
#include "CommandManager.h"

void CommandManager::registerCommands() {
    new SetCommand;
}

void CommandManager::addCommand(std::string alias, BaseCommand *cmd) {
    CommandManager::commands.insert({alias, cmd});
}

void CommandManager::runCommand(std::string cmd, std::vector<std::string> args) {
    CommandManager::commands[cmd]->execute(args);
}

CommandManager* CommandManager::instance() {
    if (CommandManager::inst == NULL) {
        CommandManager::inst = new CommandManager();
        return CommandManager::inst;
    }
    return CommandManager::inst;
}