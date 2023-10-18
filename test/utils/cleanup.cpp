//
// Created by Daniel Byomujuni on 10/17/23.
//

#include "cleanup.h"
#include <string>
#include <iostream>
#include <filesystem>

#define WorkingDirectory std::string("../test/workingDir/")

void cleanup::clean() {
    for (const auto& entry : std::filesystem::directory_iterator(WorkingDirectory))
        std::filesystem::remove_all(entry.path());
}