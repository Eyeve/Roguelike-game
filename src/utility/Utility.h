#ifndef ROGUELIKE_GAME_UTILITY_H
#define ROGUELIKE_GAME_UTILITY_H

#include <utility>


template<typename T>
int enumSize() {
    return std::to_underlying(T::None);
}

#endif