//
// Created by Daniel on 1/8/24.
//

#include "HelpCommand.h"
#include "../../CommandManager.h"

void HelpCommand::execute(std::vector<std::string> args) {
    printf("mangamanager [OPTION] COMMAND [ARGUMENTS]\n\n");
    printf("\e[1mManage your manga collection from the terminal\e[0m\n\n");

    printf("\e[1m\e[4mCOMMANDS:\e[0m\n");
    printf("  %-34s %-60s\n", "collection", "Shows a table of your current manga collection");
    printf("  %-34s %-60s\n", "add OPERATION [ARGUMENTS]", "");
    //ADD
    printf("    add operations:\n");
    printf("      %-30s %-60s\n", "series <SERIESNAME>", "adds the series to be recorded in the collection");
    printf("      %-30s %-60s\n", "volume <SERIESNAME> <VOLUMERANGE>", "adds the volumes of the series to be recorded in the collection");
    //REMOVE
    /*
    printf("  %-34s %-60s\n", "rm OPERATION [ARGUMENTS]", "");
    printf("    add operations:\n");
    printf("      %-30s %-60s\n", "series <SERIESNAME>", "removes the series from the collection");
    printf("      %-30s %-60s\n", "volume <SERIESNAME> <VOLUMERANGE>", "removes the volumes of the series from the collection");
     */
    //FLAGS
    printf("\e[1m\e[4mFLAGS:\e[0m\n");
    printf("  %-34s %-60s\n", "--help, -h", "Lists all available commands");
    printf("  %-34s %-60s\n", "-j", "Outputs the Result as JSON");
}

HelpCommand::HelpCommand() {
    CommandManager::instance()->addCommand("-h", this);
    CommandManager::instance()->addCommand("--help", this);
    CommandManager::instance()->addCommand("help", this);
}
