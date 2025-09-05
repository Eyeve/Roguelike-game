cmake_minimum_required(VERSION 3.27.8)
project(Roguelike-game)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(${PROJECT_NAME}
        main.cpp
        src/UI/Window.cpp
        src/UI/Window.h
        src/UI/TextureManager.cpp
        src/UI/TextureManager.h
        src/world/Chunk.cpp
        src/world/Chunk.h
        src/world/generator/WorldGenerator.cpp
        src/world/generator/WorldGenerator.h
        src/world/generator/WorldGeneratorInterface.h
        src/world/World.cpp
        src/world/World.h
        src/world/generator/TestRoomGenerator.cpp
        src/world/generator/TestRoomGenerator.h
        src/world/CellManager.h
        src/world/BiomeManager.h
        src/world/BiomeManager.cpp
        src/world/CellManager.cpp
        src/utility/ManagerInterface.h
        src/utility/Utility.h
)

include_directories(${PROJECT_NAME}
        src
        src/UI
        src/world
        src/world/generator
        src/utility
)

include(FetchContent)

if(WIN32)
    set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
endif()

FetchContent_Declare(
        sfml
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG        2.6.1
)

FetchContent_MakeAvailable(sfml)

FetchContent_Declare(
        magic_enum
        GIT_REPOSITORY https://github.com/Neargye/magic_enum.git
        GIT_TAG        v0.9.5
)

FetchContent_MakeAvailable(magic_enum)

target_link_libraries(${PROJECT_NAME}
        sfml-graphics
        sfml-window
        sfml-system
        magic_enum::magic_enum
)

if(WIN32)
    target_compile_definitions(${PROJECT_NAME} PRIVATE SFML_STATIC)

    target_link_libraries(${PROJECT_NAME}
            sfml-main
            opengl32
            winmm
            gdi32
    )
elseif(UNIX AND NOT APPLE)
    find_package(X11 REQUIRED)
endif()
