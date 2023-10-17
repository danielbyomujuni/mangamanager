//
// Created by Daniel on 10/17/23.
//

#include <gtest/gtest.h>
#include "../../src/utils/MangaUpdatesGateway.h"

//These Mangas is chosen as it is completed so it will never change
#define MAYO_CHIKI_ID "30271685851"
#define AKAME_GA_KILL_ID "54773004994"

// Demonstrate some basic assertions.
TEST(MangaUpdatesGatewayTest, GetEnglishVolumeCountForMayoChiki) {
// Expect two strings not to be equal.
    MangaUpdatesGateway gate;
    EXPECT_EQ(7, gate.getEnglishVolumeCount(MAYO_CHIKI_ID));
}

TEST(MangaUpdatesGatewayTest, GetEnglishVolumeCountForAkameGaKill) {
// Expect two strings not to be equal.
    MangaUpdatesGateway gate;
    EXPECT_EQ(15, gate.getEnglishVolumeCount(AKAME_GA_KILL_ID));
}

