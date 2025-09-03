cmake_minimum_required(VERSION 3.27.8)
project(Roguelike-game)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SOURCES
        main.cpp
        src/UI/Window.cpp
        src/UI/Window.h
        src/UI/TextureManager.cpp
        src/UI/TextureManager.h
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE
        src
        src/UI
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

target_link_libraries(${PROJECT_NAME}
        sfml-graphics
        sfml-window
        sfml-system
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
