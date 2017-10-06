typedef enum { MOUSE, EMPTY, WALL, CHEESE } TileType;
typedef char TileTypeChar;

TileType getTileTypeFromTileTypeChar(TileTypeChar c) {
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

TileType* getTileTypesFromMazeFile(MazeFile mazeFile){
  int size = 0;
  char c;
  TileType* tileTypes = (TileType*) malloc(sizeof(TileType) * MAX_NUM_OF_TILES_IN_MAZEFILE);

  while ((!feof(mazeFile)) && (size < MAX_NUM_OF_TILES_IN_MAZEFILE)) {
    switch (c = fgetc(mazeFile)) {
      case 'M':
      case 'E':
      case 'W':
      case 'C':
        size++;
        tileTypes[size - 1] = getTileTypeFromTileTypeChar(c);
    }
  }

  return tileTypes;
}
