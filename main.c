#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "libs/MazeFile.h"
#include "libs/TileType.h"
#include "libs/Tile.h"
#include "libs/Mouse.h"
#include "libs/Maze.h"
#include "libs/utils.h"

int main() {
  MazeFile mazeFile = openMazeFile("maze.txt");
  Maze maze = createMazeFromMazeFile(mazeFile);

  // printEachTileAdjacentTiles(maze->tiles);
  // printMouseTileIndex(maze->mouse);

  // Clean up:
  fclose(mazeFile);

  return 0;
}
