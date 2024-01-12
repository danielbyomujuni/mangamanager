cmake_minimum_required(VERSION 3.24)
project(mangamanager)

set(CMAKE_CXX_STANDARD 20)

find_package(nlohmann_json 3.2.0 REQUIRED)
set(CMAKE_CXX_FLAGS "-lcurl")

add_executable(mangamanager src/main.cpp src/commands/AddCommand.cpp src/commands/AddCommand.h src/commands/BaseCommand.cpp src/commands/BaseCommand.h src/CommandManager.cpp src/CommandManager.h src/utils/CSVGateway.cpp src/utils/CSVGateway.h src/utils/MangaUpdatesGateway.cpp src/utils/MangaUpdatesGateway.h src/utils/Memory.cpp src/utils/Memory.h src/commands/LatestCommand.cpp src/commands/LatestCommand.h
        src/commands/HelpCommand.cpp
        src/commands/HelpCommand.h src/utils/VolumeRange.h src/utils/VolumeRange.cpp src/utils/Config.cpp src/utils/Config.h)
target_link_libraries(mangamanager PRIVATE nlohmann_json::nlohmann_json)
install(TARGETS mangamanager DESTINATION bin)

if (CMAKE_BUILD_TYPE)
    string(TOLOWER ${CMAKE_BUILD_TYPE} BUILDTYPE_LOWER)
    if(BUILDTYPE_LOWER STREQUAL "debug")
        enable_testing()

        include(FetchContent)
        FetchContent_Declare(googletest URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip)
        FetchContent_MakeAvailable(googletest)

        add_executable(
        MangaUpdatesTest
        test/utils/MangaUpdatesGatewayTest.cpp
                src/commands/AddCommand.cpp src/commands/AddCommand.h src/commands/BaseCommand.cpp src/commands/BaseCommand.h src/CommandManager.cpp src/CommandManager.h src/utils/CSVGateway.cpp src/utils/CSVGateway.h src/utils/MangaUpdatesGateway.cpp src/utils/MangaUpdatesGateway.h src/utils/Memory.cpp src/utils/Memory.h src/commands/LatestCommand.cpp src/commands/LatestCommand.h
        test/utils/CSVGatewayTest.cpp test/utils/cleanup.cpp test/utils/cleanup.h
                src/commands/HelpCommand.cpp
                src/commands/HelpCommand.h src/utils/VolumeRange.h test/utils/VolumeRangeTest.cpp src/utils/VolumeRange.cpp test/CommandManagerTest.cpp src/utils/Config.cpp src/utils/Config.h test/utils/ConfigTest.cpp)
        target_link_libraries(MangaUpdatesTest GTest::gtest_main nlohmann_json::nlohmann_json)

        include(GoogleTest)
        gtest_discover_tests(MangaUpdatesTest)
    endif()
endif()