typedef int TileIndex;
typedef int AdjacentTilesSize;

struct tile {
  TileType type;
  TileIndex index;
  AdjacentTilesSize adjacentTilesSize;
  struct tile** adjacentTiles;
};

typedef struct tile* Tile;
