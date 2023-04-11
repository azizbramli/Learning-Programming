// Copyright(C) 2023, Charles T, <chalodss@proton.me>

package classes.gameoflife;

import java.util.BitSet;
import java.util.stream.IntStream;

public final class Game {

  final BitSet[]    grid;
  final BitSet[]    newGrid;
  private final int width;
  private final int height;

  public Game(int width, int height) {
    this.width   = width;
    this.height  = height;
    this.grid    = new BitSet[height + 2];
    this.newGrid = new BitSet[height + 2];

    IntStream.range(0, height + 2).forEach(i -> grid[i] = new BitSet(width + 2));
    IntStream.range(0, height + 2).forEach(i -> newGrid[i] = new BitSet(width + 2));
  }

  private int countNeighbors(int i, int j) {
    var nb = 0;

    nb += grid[i].get(j + 1) ? 1 : 0;
    nb += grid[i].get(j - 1) ? 1 : 0;
    nb += grid[i - 1].get(j - 1) ? 1 : 0;
    nb += grid[i - 1].get(j) ? 1 : 0;
    nb += grid[i - 1].get(j + 1) ? 1 : 0;
    nb += grid[i + 1].get(j - 1) ? 1 : 0;
    nb += grid[i + 1].get(j) ? 1 : 0;
    nb += grid[i + 1].get(j + 1) ? 1 : 0;
    return nb;
  }

  void update() {
    int n = 0;

    for (var i = 1; i <= height; i++) {
      for (var j = 1; j <= width; j++) {
        n = countNeighbors(i, j);
        newGrid[i].set(j, ((grid[i].get(j) && n == 2) || n == 3));
      }
    }
    for (var i = 1; i <= height; i++) {
      for (var j = 1; j <= width; j++) {
        grid[i].set(j, newGrid[i].get(j));
      }
    }
  }

  void resetNewGrid() {
    for (var bitset : newGrid) {
      bitset.clear();
    }
  }

}
