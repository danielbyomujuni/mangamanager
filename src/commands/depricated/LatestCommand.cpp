//
// Created by Daniel Byomujuni on 10/8/23.
//
#include <vector>
#include <iostream>
#include "LatestCommand.h"
#include "../../CommandManager.h"
#include "../../utils/CSVGateway.h"
#include "../../utils/MangaUpdatesGateway.h"

#define NOT_UP_TO_DATE "\033[91m"
#define UP_TO_DATE "\033[92m"
#define DEFAULT "\033[39m"

LatestCommand::LatestCommand() {
    CommandManager::instance()->addCommand("collection", this);
}

int LatestCommand::execute(std::vector<std::string> args) {
    CSVGateway csv;
    //MangaUpdatesGateway gate;
    std::vector<Manga> mangas = csv.allRecords();

    //Printing The Header//

    //printf("%-30s | %-15s | %-13s | %-16s", "Title", "Id", "Volumes Owned", "Volumes Released \n"); //Header with Release amounts
    printf("%-30s | %-15s | %-13s", "Title", "Id", "Volumes Owned\n");

    //for (int i = 0; i < 30+3+15+3+13+3+16; i++) { //Header with Release amounts
    for (int i = 0; i < 30+3+15+3+13; i++) {
        std::cout << "-";
    }

    std::cout << std::endl;
    for (Manga mg : mangas) {
        printf("%-30s | %-15s ",
               mg.title.c_str(),
               mg.id.c_str());


        /*int released = gate.getEnglishVolumeCount(mg.id);
        if (mg.volumes < released) {
            std::cout << NOT_UP_TO_DATE;
        } else {
            std::cout << UP_TO_DATE;
        }
        printf("| %-13d | %-16d \n",
               mg.volumes,
               gate.getEnglishVolumeCount(mg.id));*/

        printf("| %-13d\n", mg.volumes);
        //std::cout << DEFAULT;
    }
    return 0;
}

