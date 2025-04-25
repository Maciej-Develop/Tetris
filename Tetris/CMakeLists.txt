cmake_minimum_required(VERSION 3.30)
project(Tetris)

set(CMAKE_CXX_STANDARD 23)

include(FetchContent)

# define a function for adding git dependencies
function(include_dependency libName gitURL gitTag)
    # setup the declare
    FetchContent_Declare(${libName}
            GIT_REPOSITORY ${gitURL}
            GIT_TAG        ${gitTag}
            GIT_SHALLOW    TRUE
            GIT_PROGRESS   TRUE
    )

    FetchContent_MakeAvailable(${libName})
endfunction()

# add raylib support
set(LIB1 raylib)
find_package(${LIB1} QUIET)
if (NOT ${LIB1}_FOUND)
    message(STATUS "Getting ${LIB1} from Github")
    include_dependency(${LIB1} https://github.com/raysan5/raylib.git 5.0)
else()
    message(STATUS "Using local ${LIB1}")
endif()

add_executable(Tetris main.cpp
        model/Grid.cpp
        model/Grid.h
        model/blocks/Block.cpp
        model/blocks/Block.h
        model/utils/Position.cpp
        model/utils/Position.h
        model/utils/Colors.cpp
        model/utils/Colors.h
        model/blocks/LBlock.cpp
        model/blocks/LBlock.h
        model/blocks/JBlock.cpp
        model/blocks/JBlock.h
        model/blocks/IBlock.cpp
        model/blocks/IBlock.h
        model/blocks/OBlock.cpp
        model/blocks/OBlock.h
        model/blocks/SBlock.cpp
        model/blocks/SBlock.h
        model/blocks/TBlock.cpp
        model/blocks/TBlock.h
        model/blocks/ZBlock.cpp
        model/blocks/ZBlock.h)

# set the include directory
target_include_directories(Tetris PRIVATE ${raylib_INCLUDE_DIRS})

# link all libraries to the project
target_link_libraries(Tetris PRIVATE ${LIB1})