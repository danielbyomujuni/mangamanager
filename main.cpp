//
// Created by Daniel on 10/9/23.
//

#include "CommandManager.h"
#include "utils/MangaUpdatesGateway.h"

int main() {
    CommandManager::instance()->registerCommands();
    //CommandManager::instance()->runCommand("set", {"manga", "SHY", "12137220691"});
    //CommandManager::instance()->runCommand("set", {"manga", "SHY", "1213723"});

    //CommandManager::instance()->runCommand("latest",{});

    MangaUpdatesGateway gateway;
    std::cout << gateway.getEnglishVolumeCount("12137220691") << std::endl;

    return 0;
}
