//
// Created by Daniel Byomujuni on 1/9/24.
//
#include <gtest/gtest.h>
#include "../../src/utils/Config.h"

#define WorkingDirectory "../test/testFiles/"

TEST(ConfigTest, testGetCollection) {
    std::string path = WorkingDirectory;
    path.append( "TestConfig1.conf");

    Config cfg = *new Config(path.data());
    EXPECT_STREQ("../test/workingDir/test.csv", cfg.getCollectionFile());

}