//
// Created by Daniel Byomujuni on 10/8/23.
//
#include <vector>
#include <iostream>
#include "SetCommand.h"
#include "../CommandManager.h"
#include "../utils/CSVGateway.h"

SetCommand::SetCommand() {
    CommandManager::instance()->addCommand("set", this);
}

void SetCommand::execute(std::vector<std::string> args) {
    if (args.size() == 0) {
        this->incorrectUsage("mangaupdates set [type]");
        return;
    }
    if (args.at(0) == "manga") {
        this->Manga(args.at(1), args.at(2));
        return;
    }
}

void SetCommand::Manga(std::string name, std::string id) {
    CSVGateway gate;
    gate.setRecord(name, id);
    std::cout << name << id << std::endl;
}