//
// Created by Daniel Byomujuni on 1/15/24.
//

#include "BaseCommandManager.h"

void BaseCommandManager::addCommand(std::string alias, BaseCommand *cmd) {
    this->commands.insert({alias, cmd});
}

void BaseCommandManager::runCommand(std::string cmd, std::vector<std::string> args) {
    if (this->commands[cmd] == NULL) {
        printf("mangamanager: unknown command: %s\n", cmd.c_str());
        printf("Try 'mangamanager --help' for more information\n");
        exit(0);
    }
    this->commands[cmd]->execute(args);
}
