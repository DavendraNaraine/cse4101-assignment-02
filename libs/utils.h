// For testing validity of each tile's adjacent tiles
void printEachTileAdjacentTiles(Tile* tiles) {
  int i, j;
  for (i = 0; i < MAX_NUM_OF_TILES; i++) {
    printf("Index: %d\n", tiles[i]->index);

    for (j = 0; j < tiles[i]->adjacentTilesSize; j++) {
      printf("%d\n", tiles[i]->adjacentTiles[j]->index);
    }
    getchar();
  }
}

// For testing validity of mouse tile
void printMouseTileIndex(Tile mouseTile) {
  printf("Mouse Tile Index:\t%d\n", mouseTile->index);
}
