typedef FILE* MazeFile;

MazeFile openMazeFile(char* name){
  MazeFile mazeFile = fopen(name, "r");

  if (mazeFile == NULL) {
    puts("Fatal error: Can't open maze file!");
    exit(1);
  }

  return mazeFile;
}
