//
// Created by Daniel Byomujuni on 10/8/23.
//
#include <vector>
#include <iostream>
#include "SetCommand.h"
#include "../CommandManager.h"
#include "../utils/CSVGateway.h"

#define documents getenv("HOME") + "/Documents/"

SetCommand::SetCommand() {
    CommandManager::instance()->addCommand("set", this);
}

void SetCommand::execute(std::vector<std::string> args) {
    if (args.size() == 0) {
        this->incorrectUsage("mangaupdates set [type]");
        return;
    }
    if (args.at(0) == "manga") {
        this->MangaCMD(args.at(1), args.at(2));
        return;
    }

    if (args.at(0) == "volumes") {
        //std::cout << args.at(1) << std::endl;
        this->VolumesCMD(args.at(1), args.at(2));
        return;
    }
}

void SetCommand::MangaCMD(std::string name, std::string id) {
    CSVGateway gate;
    gate.setRecord(name, id, 0);
}

void SetCommand::VolumesCMD(std::string name, std::string count) {
    //std::cout << name << std::endl;
    CSVGateway csv;
    Manga rec = csv.getRecord(name);

    csv.setRecord(name, rec.id, stoi(count));
}