cmake_minimum_required(VERSION 3.24)
project(MangaUpdates)

set(CMAKE_CXX_STANDARD 17)

find_package(nlohmann_json 3.2.0 REQUIRED)
set(CMAKE_CXX_FLAGS "-lcurl")

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

FetchContent_MakeAvailable(googletest)

add_executable(MangaUpdates src/main.cpp src/commands/SetCommand.cpp src/commands/SetCommand.h src/commands/BaseCommand.cpp src/commands/BaseCommand.h src/CommandManager.cpp src/CommandManager.h src/utils/CSVGateway.cpp src/utils/CSVGateway.h src/utils/MangaUpdatesGateway.cpp src/utils/MangaUpdatesGateway.h src/utils/Memory.cpp src/utils/Memory.h src/commands/LatestCommand.cpp src/commands/LatestCommand.h)
target_link_libraries(MangaUpdates PRIVATE nlohmann_json::nlohmann_json)


enable_testing()

add_executable(
        MangaUpdatesTest
        test/utils/MangaUpdatesGatewayTest.cpp
        src/commands/SetCommand.cpp src/commands/SetCommand.h src/commands/BaseCommand.cpp src/commands/BaseCommand.h src/CommandManager.cpp src/CommandManager.h src/utils/CSVGateway.cpp src/utils/CSVGateway.h src/utils/MangaUpdatesGateway.cpp src/utils/MangaUpdatesGateway.h src/utils/Memory.cpp src/utils/Memory.h src/commands/LatestCommand.cpp src/commands/LatestCommand.h
)
target_link_libraries(
        MangaUpdatesTest
        GTest::gtest_main
        nlohmann_json::nlohmann_json
)

include(GoogleTest)
gtest_discover_tests(MangaUpdatesTest)
