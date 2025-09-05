#ifndef ROGUELIKE_GAME_CELL_MANAGER_H
#define ROGUELIKE_GAME_CELL_MANAGER_H

#include "TextureManager.h"

struct Cell {

    Cell(): texture(TextureName::None) {}
    explicit Cell(TextureName texture): texture(texture) {}

    TextureName texture;
};



#endif
