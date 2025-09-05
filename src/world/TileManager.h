#ifndef ROGUELIKE_GAME_TILE_MANAGER_H
#define ROGUELIKE_GAME_TILE_MANAGER_H


enum class TileType {
    Ceil,
    Down,
    Floor,
    InDownLeft,
    InDownRight,
    InUpLeft,
    InUpRight,
    Left,
    OutDownLeft,
    OutDownRight,
    OutUpLeft,
    OutUpRight,
    Right,
    Up,

    None
};

struct Tile {

    TileType type;

    Tile(): type(TileType::None) {}
    explicit Tile(TileType type): type(type) {}
};


// class CellManager: public ManagerInterface<CellType, Cell> {
//
// public:
//     CellManager() = default;
//
// protected:
//     int init() override;
//     const Cell& getHandler(CellType key) override;
// };


#endif
