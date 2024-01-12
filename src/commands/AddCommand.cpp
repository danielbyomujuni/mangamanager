//
// Created by Daniel Byomujuni on 10/8/23.
//
#include <vector>
#include <iostream>
#include "AddCommand.h"
#include "../CommandManager.h"
#include "../utils/CSVGateway.h"

#define documents getenv("HOME") + "/Documents/"

AddCommand::AddCommand() {
    CommandManager::instance()->addCommand("add", this);
}

void AddCommand::execute(std::vector<std::string> args) {
    if (args.size() == 0) {
        this->incorrectUsage("add OPERATION [ARGUMENTS]");
        return;
    }
    if (args.at(0) == "series") {
        this->mangaCMD(args.at(1));
        return;
    }

    if (args.at(0) == "volumes") {
        //std::cout << args.at(1) << std::endl;
        this->volumesCMD(args.at(1), args.at(2));
        return;
    }
}

void AddCommand::mangaCMD(std::string seriesName) {
    CSVGateway gate;
    gate.setRecord(seriesName, 0, 0);
}

void AddCommand::volumesCMD(std::string name, std::string count) {
    //std::cout << name << std::endl;
    CSVGateway csv;
    Manga rec = csv.getRecord(name);

    csv.setRecord(name, rec.id, stoi(count));
}