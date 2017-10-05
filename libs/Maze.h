#define MAX_NUM_OF_TILES 64

struct maze {
  Tile tiles[MAX_NUM_OF_TILES];
  Mouse mouse;
};

typedef struct maze* Maze;

char* getTilesCharsFromMazeFile(MazeFile mazeFile){
  int size = 0;
  char c;
  char* tilesChars = (char*) malloc(sizeof(char) * MAX_NUM_OF_TILES);

  while ((!feof(mazeFile)) && (size<MAX_NUM_OF_TILES)) {
    switch (c = fgetc(mazeFile)) {
      case 'M':
      case 'E':
      case 'W':
      case 'C':
        size++;
        tilesChars[size - 1] = c;
    }
  }

  return tilesChars;
}

bool isValidMazeIndex (TileIndex index) {
  return (!(index <  0) && !(index > MAX_NUM_OF_TILES));
}

void addAdjacentTile(Tile tile, Tile adjacentTile) {
  tile->adjacentTilesSize++;
  int size = tile->adjacentTilesSize;

  tile->adjacentTiles = (Tile*) realloc(tile->adjacentTiles, size);
  tile->adjacentTiles[size - 1] = adjacentTile;
}

void generateAdjacentTilesForTile(Tile tile, Maze maze) {
  TileIndex tileIndex = tile->index;
  TileIndex top, right, bottom, left;

  // top
  top = tileIndex - 8;
  if(isValidMazeIndex(top)){
    addAdjacentTile(tile, maze->tiles[top]);
  }

  // right
  right = tileIndex + 1;
  if (isValidMazeIndex(right) && !(right % 8 == 0)) {
    addAdjacentTile(tile, maze->tiles[right]);
  }

  // bottom
  bottom = tileIndex + 8;
  if(isValidMazeIndex(bottom)){
    addAdjacentTile(tile, maze->tiles[bottom]);
  }

  // left
  left = tileIndex - 1;
  if (isValidMazeIndex(left) && !(left % 8 == 7)) {
    addAdjacentTile(tile, maze->tiles[left]);
  }
}

Maze createMazeFromMazeFile(MazeFile mazeFile) {
  char* tilesChars = getTilesCharsFromMazeFile(mazeFile);
  Maze maze = (Maze) malloc(sizeof(struct maze));
  int i;

  for (i = 0; i < MAX_NUM_OF_TILES; i++) {
    // Tile allocation
    maze->tiles[i] = (Tile) malloc(sizeof(struct tile));

    // Assign tile defaults: type, index, adjacentTilesSize and adjacentTiles
    maze->tiles[i]->type = getTileTypeFromChar(tilesChars[i]);
    maze->tiles[i]->index = i;
    maze->tiles[i]->adjacentTilesSize = 0;
    maze->tiles[i]->adjacentTiles = (Tile*) malloc(sizeof(Tile) * 0);

    // Assign mouse if current tile is of MOUSE type
    if (maze->tiles[i]->type == MOUSE) {
      maze->mouse = maze->tiles[i];
    }
  }

  // Generate adjacent tiles for each tile
  for (i = 0; i < MAX_NUM_OF_TILES; i++) {
    generateAdjacentTilesForTile(maze->tiles[i], maze);
  }

  // Clean up:
  free(tilesChars);

  return maze;
}
