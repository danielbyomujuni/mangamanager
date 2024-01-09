//
// Created by Daniel Byomujuni on 1/9/24.
//
#include <gtest/gtest.h>
#include "../src/CommandManager.h"


TEST(CommandManagerTest, testCollection) {
    CommandManager::instance()->registerCommands();
    CommandManager::instance()->runCommand("collection", {});
}
