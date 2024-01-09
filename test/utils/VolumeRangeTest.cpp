//
// Created by Daniel Byomujuni on 1/8/24.
//
#include <gtest/gtest.h>
#include "../../src/utils/MangaUpdatesGateway.h"
#include "../../src/utils/VolumeRange.h"

TEST(VolumeRangeTest, testbasicRange) {
    int arrlen = 0;
    int *volumes = volumeRangeToArray(&arrlen, "1-3");

    EXPECT_EQ(arrlen, 4);

    EXPECT_EQ(volumes[0], 0);
    EXPECT_EQ(volumes[1], 1);
    EXPECT_EQ(volumes[2], 1);
    EXPECT_EQ(volumes[3], 1);

}

TEST(VolumeRangeTest, testdisjoint) {
    int arrlen = 0;
    int *volumes = volumeRangeToArray(&arrlen, "1-3,6");

    EXPECT_EQ(arrlen, 7);

    EXPECT_EQ(volumes[0], 0);
    EXPECT_EQ(volumes[1], 1);
    EXPECT_EQ(volumes[2], 1);
    EXPECT_EQ(volumes[3], 1);
    EXPECT_EQ(volumes[4], 0);
    EXPECT_EQ(volumes[5], 0);
    EXPECT_EQ(volumes[6], 1);

}

TEST(VolumeRangeTest, testonlydisjoint) {
    int arrlen = 0;
    int *volumes = volumeRangeToArray(&arrlen, "1,2,3,6");

    EXPECT_EQ(arrlen, 7);

    EXPECT_EQ(volumes[0], 0);
    EXPECT_EQ(volumes[1], 1);
    EXPECT_EQ(volumes[2], 1);
    EXPECT_EQ(volumes[3], 1);
    EXPECT_EQ(volumes[4], 0);
    EXPECT_EQ(volumes[5], 0);
    EXPECT_EQ(volumes[6], 1);

}

TEST(VolumeRangeTest, testNotInOrder) {
    int arrlen = 0;
    int *volumes = volumeRangeToArray(&arrlen, "1,2,3,8,5");

    EXPECT_EQ(arrlen, 9);

    EXPECT_EQ(volumes[0], 0);
    EXPECT_EQ(volumes[1], 1);
    EXPECT_EQ(volumes[2], 1);
    EXPECT_EQ(volumes[3], 1);
    EXPECT_EQ(volumes[4], 0);
    EXPECT_EQ(volumes[5], 1);
    EXPECT_EQ(volumes[6], 0);
    EXPECT_EQ(volumes[7], 0);
    EXPECT_EQ(volumes[8], 1);

}

TEST(VolumeRangeTest, testNotInRange) {
    int arrlen = 0;
    int *volumes = volumeRangeToArray(&arrlen, "7-9,2-4");

    EXPECT_EQ(arrlen, 10);

    EXPECT_EQ(volumes[0], 0);
    EXPECT_EQ(volumes[1], 0);
    EXPECT_EQ(volumes[2], 1);
    EXPECT_EQ(volumes[3], 1);
    EXPECT_EQ(volumes[4], 1);
    EXPECT_EQ(volumes[5], 0);
    EXPECT_EQ(volumes[6], 0);
    EXPECT_EQ(volumes[7], 1);
    EXPECT_EQ(volumes[8], 1);
    EXPECT_EQ(volumes[9], 1);
}