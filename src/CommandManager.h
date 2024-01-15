//
// Created by Daniel Byomujuni on 10/8/23.
//

#ifndef MANGAMANAGER_COMMANDMANAGER_H
#define MANGAMANAGER_COMMANDMANAGER_H


#include <map>
#include "commands/abstract/BaseCommand.h"
#include "commands/depricated/AddCommand.h"
#include "commands/abstract/BaseCommandManager.h"

class CommandManager: public BaseCommandManager {
private:
    inline static CommandManager* inst = NULL;

public:
    static CommandManager* instance();
    void registerCommands();
};


#endif //MANGAMANAGER_COMMANDMANAGER_H
