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

TEST(VolumeRangeTest, testbasicArray) {
    char *volumes = volumeArrayToRange(4, new int[] {0,1,1,1});

    EXPECT_STREQ(volumes, "1-3");
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

TEST(VolumeRangeTest, testdisjointToRange) {
    char *volumes = volumeArrayToRange(7, new int[] {0,1,1,1, 0, 0 , 1});

    EXPECT_STREQ(volumes, "1-3,6");
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

TEST(VolumeRangeTest, testLargeRangeSet) {
    char *volumes = volumeArrayToRange(10, new int[] {0,0,1,1, 1, 0 , 0,1,1,1});
    EXPECT_STREQ(volumes, "2-4,7-9");
}

TEST(VolumeRangeTest, testLargeOddRangeSet) {
    char *volumes = volumeArrayToRange(10, new int[] {0,1,0,1, 0, 1 , 0,1,0,1});
    EXPECT_STREQ(volumes, "1,3,5,7,9");
}

TEST(VolumeRangeTest, testLargeEvenRangeSet) {
    char *volumes = volumeArrayToRange(10, new int[] {1,0,1, 0, 1 , 0,1,0,1,0});
    EXPECT_STREQ(volumes, "0,2,4,6,8");
}

TEST(VolumeRangeTest, addBasicVolArray) {
    int arrlen = 4;
    int *arr1 = new int[] {0,1,1,0};
    int *arr2 = new int[] {0,0,1,1};

    addVolumeArrays(&arr1, &arrlen, arr2, 4);

    EXPECT_EQ(arrlen, 4);

    EXPECT_EQ(arr1[0], 0);
    EXPECT_EQ(arr1[1], 1);
    EXPECT_EQ(arr1[2], 1);
    EXPECT_EQ(arr1[3], 1);
}

TEST(VolumeRangeTest, addBasicVolArraySizeDif) {
    int arrlen = 6;
    int *arr1 = new int[] {0,1,1,0,0,1};
    int *arr2 = new int[] {0,0,1,1};

    addVolumeArrays(&arr1, &arrlen, arr2, 4);

    EXPECT_EQ(arrlen, 6);

    EXPECT_EQ(arr1[0], 0);
    EXPECT_EQ(arr1[1], 1);
    EXPECT_EQ(arr1[2], 1);
    EXPECT_EQ(arr1[3], 1);
    EXPECT_EQ(arr1[4], 0);
    EXPECT_EQ(arr1[5], 1);
}

TEST(VolumeRangeTest, addBasicVolArraySizeDifSwap) {
    int arrlen = 4;
    int *arr1 = new int[] {0,1,1,0,0,1};
    int *arr2 = new int[] {0,0,1,1};

    addVolumeArrays(&arr2, &arrlen, arr1, 6);

    EXPECT_EQ(arrlen, 6);

    EXPECT_EQ(arr2[0], 0);
    EXPECT_EQ(arr2[1], 1);
    EXPECT_EQ(arr2[2], 1);
    EXPECT_EQ(arr2[3], 1);
    EXPECT_EQ(arr2[4], 0);
    EXPECT_EQ(arr2[5], 1);
}