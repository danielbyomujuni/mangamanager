//
// Created by Daniel Byomujuni on 1/9/24.
//
#include <gtest/gtest.h>
#include "../src/CommandManager.h"


TEST(CommandManagerTest, testCreateCollectionNoArgs) {
    CommandManager::instance()->registerCommands();
    int status = CommandManager::instance()->runCommand("create-collection", {});
    EXPECT_EQ(status, 1);
}

TEST(CommandManagerTest, testCreateCollectionArgs) {
    CommandManager::instance()->registerCommands();
    int status = CommandManager::instance()->runCommand("create-collection", {"test"});
    EXPECT_EQ(status, 0);
}
