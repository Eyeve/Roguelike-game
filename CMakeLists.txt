cmake_minimum_required(VERSION 3.27.8)
project(Leslie_ChessEngine)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(${PROJECT_NAME}
        main.cpp
)

include_directories(src)

include_directories(${CMAKE_SOURCE_DIR}/lib/SFML-3.0.0/include)
