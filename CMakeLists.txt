cmake_minimum_required(VERSION 3.24)
project(MangaUpdates)

set(CMAKE_CXX_STANDARD 17)

add_executable(MangaUpdates main.cpp commands/SetCommand.cpp commands/SetCommand.h commands/BaseCommand.cpp commands/BaseCommand.h CommandManager.cpp CommandManager.h utils/CSVGateway.cpp utils/CSVGateway.h
        commands/LatestCommand.h
        commands/LatestCommand.cpp)