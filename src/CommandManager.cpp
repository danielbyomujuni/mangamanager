//
// Created by Daniel Byomujuni on 10/8/23.
//

#include <string>
#include <vector>
#include "CommandManager.h"
#include "commands/LatestCommand.h"

void CommandManager::registerCommands() {
    new SetCommand;
    new LatestCommand;
}

void CommandManager::addCommand(std::string alias, BaseCommand *cmd) {
    CommandManager::commands.insert({alias, cmd});
}

void CommandManager::runCommand(std::string cmd, std::vector<std::string> args) {
    if (CommandManager::commands[cmd] == NULL) {
        printf("mangamanager: unknown command: %s", cmd.c_str());
        printf("Try 'mangamanager --help' for more information");
        exit(0)
    }
    CommandManager::commands[cmd]->execute(args);
}

CommandManager* CommandManager::instance() {
    if (CommandManager::inst == NULL) {
        CommandManager::inst = new CommandManager();
        return CommandManager::inst;
    }
    return CommandManager::inst;
}