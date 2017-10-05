typedef enum { MOUSE, EMPTY, WALL, CHEESE } TileType;
typedef int TileIndex;
typedef int AdjacentTilesSize;

struct tile {
  TileType type;
  TileIndex index;
  AdjacentTilesSize adjacentTilesSize;
  struct tile** adjacentTiles;
};

typedef struct tile* Tile;

TileType getTileTypeFromChar(char c) {
  switch (c) {
    case 'M':
      return MOUSE;

    case 'E':
      return EMPTY;

    case 'W':
      return WALL;

    case 'C':
      return CHEESE;
  }
}
