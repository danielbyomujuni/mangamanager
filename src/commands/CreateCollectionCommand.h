//
// Created by Daniel Byomujuni on 1/15/24.
//

#ifndef MANGAMANAGER_CREATECOLLECTIONCOMMAND_H
#define MANGAMANAGER_CREATECOLLECTIONCOMMAND_H


#include "abstract/BaseCommand.h"

class CreateCollectionCommand: public BaseCommand {
public:
    CreateCollectionCommand();
    void execute(std::vector<std::string> args);
};


#endif //MANGAMANAGER_CREATECOLLECTIONCOMMAND_H
