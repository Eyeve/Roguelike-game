cmake_minimum_required(VERSION 3.27.8)
project(Roguelike-game)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Указываем исходники
add_executable(${PROJECT_NAME}
        main.cpp
)

# Подключаем FetchContent
include(FetchContent)

# Загружаем SFML
FetchContent_Declare(
        sfml
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG        2.6.1 # можно указать нужную версию
)

FetchContent_MakeAvailable(sfml)

find_package(X11 REQUIRED)

# Добавляем SFML к нашему проекту
target_link_libraries(${PROJECT_NAME}
        sfml-graphics
        sfml-window
        sfml-system
)

# Если у тебя есть собственные заголовки
target_include_directories(${PROJECT_NAME} PRIVATE src)
