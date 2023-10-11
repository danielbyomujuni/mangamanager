//
// Created by Daniel on 10/9/23.
//

#include "CommandManager.h"
#include "utils/MangaUpdatesGateway.h"
#include "utils/CSVGateway.h"

int main() {
    CommandManager::instance()->registerCommands();
    //CommandManager::instance()->runCommand("set", {"manga", "SHY", "12137220691"});
    //CommandManager::instance()->runCommand("set", {"manga", "SHY", "1213723"});

    //CommandManager::instance()->runCommand("set", {"volumes", "SHY", "4"});

    CommandManager::instance()->runCommand("latest",{});

    //MangaUpdatesGateway gateway;
    //std::cout << gateway.getEnglishVolumeCount("12137220691") << std::endl;

    //CSVGateway csv;
    //std::cout << csv.getRecord("SHY").title << std::endl;
    //std::cout << csv.getRecord("SHY").id << std::endl;
    //std::cout << csv.getRecord("SHY").volumes << std::endl;

    return 0;
}
