//
// Created by Daniel Byomujuni on 10/17/23.
//

#include <gtest/gtest.h>
#include "../../src/utils/CSVGateway.h"
#include "cleanup.h"

#define WorkingDirectory std::string("../test/workingDir/")

TEST(CSVGatewayTest, TestSetRecord) {
    CSVGateway gate(WorkingDirectory + "TestCSVGateway_");

    gate.setRecord("TestName","TestID",32);

    Manga mg = gate.getRecord("TestName");
    EXPECT_EQ("TestName", mg.title);
    EXPECT_EQ("TestID", mg.id);
    EXPECT_EQ(32, mg.volumes);
    cleanup cleanUp;
    cleanUp.clean();
}

TEST(CSVGatewayTest, TestRecordExists) {
    CSVGateway gate(WorkingDirectory + "TestCSVGateway_");

    gate.setRecord("TestName","TestID",32);

    EXPECT_TRUE(gate.doesRecordExist("TestName"));
    cleanup cleanUp;
    cleanUp.clean();
}

TEST(CSVGatewayTest, TestRecordDoesNotExists) {
    CSVGateway gate(WorkingDirectory + "TestCSVGateway_");

    EXPECT_FALSE(gate.doesRecordExist("TestName"));
    cleanup cleanUp;
    cleanUp.clean();
}

TEST(CSVGatewayTest, TestAppendRecord) {
    CSVGateway gate(WorkingDirectory + "TestCSVGateway_");

    gate.appendRecord("TestName", "TestID", 0);
    gate.appendRecord("TestName", "TestID", 0);
    EXPECT_EQ(2, gate.allRecords().size());
    cleanup cleanUp;
    cleanUp.clean();
}

TEST(CSVGatewayTest, TestUpdateRecord) {
    CSVGateway gate(WorkingDirectory + "TestCSVGateway_");

    gate.appendRecord("TestName", "TestID", 0);
    gate.updateRecord("TestName", "TestID", 4);
    EXPECT_EQ(1, gate.allRecords().size());
    EXPECT_EQ(4, gate.getRecord("TestName").volumes);
    cleanup cleanUp;
    cleanUp.clean();
}
