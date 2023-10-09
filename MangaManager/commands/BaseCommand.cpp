//
// Created by Daniel Byomujuni on 10/8/23.
//

#include "BaseCommand.h"
#include <iostream>

void BaseCommand::incorrectUsage(std::string usage) {
    std::cout << "Usage: " << usage << std::endl;
}