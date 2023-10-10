cmake_minimum_required(VERSION 3.24)
project(MangaUpdates)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "-lcurl")

add_executable(MangaUpdates main.cpp commands/SetCommand.cpp commands/SetCommand.h commands/BaseCommand.cpp commands/BaseCommand.h CommandManager.cpp CommandManager.h utils/CSVGateway.cpp utils/CSVGateway.h utils/MangaUpdatesGateway.cpp utils/MangaUpdatesGateway.h utils/Memory.cpp utils/Memory.h)