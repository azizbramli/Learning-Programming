// Copyright(C) 2023, Charles T, <chalodss@proton.me>

package app;

public final class Cell {

  int    num;
  EState state;

  public Cell(int num, EState state) {
    this.num   = num;
    this.state = state;
  }

  @Override
  public String toString() {
    return "[" + num + ", " + state + "] ";
  }

}
