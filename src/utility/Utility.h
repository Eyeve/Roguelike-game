#ifndef ROGUELIKE_GAME_UTILITY_H
#define ROGUELIKE_GAME_UTILITY_H

#include <utility>


template<typename T>
consteval int enumSize() {
    return std::to_underlying(T::None);
}

/*
{
  "tile": "Ceil",
  "up": [
  ],
  "right": [
  ],
  "down": [
  ],
  "left": [
  ]
}
 */

#endif