//
// Created by Daniel Byomujuni on 1/15/24.
//

#include "CreateCollectionCommand.h"
#include "../CommandManager.h"

CreateCollectionCommand::CreateCollectionCommand() {
    CommandManager::instance()->addCommand("create-collection", this);
}

int CreateCollectionCommand::execute(std::vector<std::string> args) {
    if (args.size() != 1) {
        //FAIL
        return 1;
    }
    //create collection file.
    //Success
    return 0;
}
