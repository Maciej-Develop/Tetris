cmake_minimum_required(VERSION 4.1)
project(Tetris)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall -pedantic-errors")

set(RAYLIB_VERSION 6.0)
find_package(raylib ${RAYLIB_VERSION} QUIET) # QUIET or REQUIRED
if (NOT raylib_FOUND) # If there's none, fetch and build raylib
    include(FetchContent)
    FetchContent_Declare(
            raylib
            DOWNLOAD_EXTRACT_TIMESTAMP OFF
            URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
    )
    FetchContent_GetProperties(raylib)
    if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
        set(FETCHCONTENT_QUIET NO)
        FetchContent_MakeAvailable(raylib)
    endif()
endif()

add_executable(Tetris main.cpp
        constants.h
        model/Grid.cpp
        model/Grid.h
        model/Blocks/Block.cpp
        model/Blocks/Block.h
        model/Position.cpp
        model/Position.h
        model/Blocks/LBlock.cpp
        model/Blocks/LBlock.h
        model/Blocks/TBlock.cpp
        model/Blocks/TBlock.h
        model/Blocks/OBlock.cpp
        model/Blocks/OBlock.h
        model/Blocks/IBlock.cpp
        model/Blocks/IBlock.h
        model/Blocks/ZBlock.cpp
        model/Blocks/ZBlock.h
        model/Blocks/JBlock.cpp
        model/Blocks/JBlock.h
        model/Blocks/SBlock.cpp
        model/Blocks/SBlock.h
        model/Game.cpp
        model/Game.h)

target_link_libraries(${PROJECT_NAME} raylib)


