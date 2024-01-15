//
// Created by Daniel Byomujuni on 10/8/23.
//

#ifndef MANGAMANAGER_BASECOMMAND_H
#define MANGAMANAGER_BASECOMMAND_H

#include <string>
#include <iostream>
#include <vector>

class BaseCommand {
public:
    void incorrectUsage(std::string usage);
    virtual int execute(std::vector<std::string> args)  { std::cout << "unimplemented\n"; }
};


#endif //MANGAMANAGER_BASECOMMAND_H
