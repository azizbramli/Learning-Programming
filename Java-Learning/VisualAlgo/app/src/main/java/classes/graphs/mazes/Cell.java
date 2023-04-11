// Copyright(C) 2023, Charles T, <chalodss@proton.me>

package classes.graphs.mazes;

import java.util.ArrayList;
import java.util.List;

public final class Cell {

  ECell      type;
  int        x;
  int        y;
  boolean    visited;
  List<Cell> adjCells;
  int        weight;
  double     distance;


  public Cell(ECell type, int x, int y, int weight) {
    this.type     = type;
    this.x        = x;
    this.y        = y;
    this.weight   = weight;
    this.visited  = false;
    this.adjCells = new ArrayList<>();
    this.distance = Double.POSITIVE_INFINITY;
  }

  @Override
  public String toString() {
    return " (" + x + ", " + y + ")" + " " + distance;
  }

}
