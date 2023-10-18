//
// Created by Daniel Byomujuni on 10/17/23.
//

#include <gtest/gtest.h>
#include "../../src/utils/CSVGateway.h"
#include "cleanup.h"

#define WorkingDirectory std::string("../test/workingDir/")

TEST(CSVGatewayTest, TestSetRecord) {
    CSVGateway gate(WorkingDirectory + "TestSetRecord_");

    gate.setRecord("TestName","TestID",32);

    Manga mg = gate.getRecord("TestName");
    EXPECT_EQ("TestName", mg.title);
    EXPECT_EQ("TestID", mg.id);
    EXPECT_EQ(32, mg.volumes);
    cleanup cleanUp;
    cleanUp.clean();
}

TEST(CSVGatewayTest, TestRecordExists) {
    CSVGateway gate(WorkingDirectory + "TestRecordExists_");

    gate.setRecord("TestName","TestID",32);

    EXPECT_TRUE(gate.doesRecordExist("TestName"));
    cleanup cleanUp;
    cleanUp.clean();
}

TEST(CSVGatewayTest, TestRecordDoesNotExists) {
    CSVGateway gate(WorkingDirectory + "TestRecordExists_");

    EXPECT_FALSE(gate.doesRecordExist("TestName"));
    cleanup cleanUp;
    cleanUp.clean();
}
