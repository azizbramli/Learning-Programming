// Copyright(C) 2023, Charles T, <chalodss@proton.me>

package app;

public final class Square {

  int x;
  int y;

  public Square(int x, int y) {
    this.x = x;
    this.y = y;
  }

  public Square(Square s) {
    this.x = s.x;
    this.y = s.y;
  }

}
