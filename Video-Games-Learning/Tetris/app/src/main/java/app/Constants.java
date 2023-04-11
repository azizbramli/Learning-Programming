// Copyright(C) 2023, Charles T, <chalodss@proton.me>

package app;

import java.util.List;

import javafx.scene.paint.Color;

public final class Constants {

  public static final List<Tetromino> TETROMINOS =
      List.of(new Tetromino(Color.YELLOW, new Square(4, 2), new Square(5, 2), new Square(4, 3), new Square(5, 3)),
          new Tetromino(Color.CYAN, new Square(4, 2), new Square(4, 0), new Square(4, 1), new Square(4, 3)),
          new Tetromino(Color.VIOLET, new Square(4, 2), new Square(3, 2), new Square(5, 2), new Square(4, 3)),
          new Tetromino(Color.ORANGE, new Square(4, 1), new Square(5, 1), new Square(4, 2), new Square(4, 3)),
          new Tetromino(Color.BLUE, new Square(4, 1), new Square(3, 1), new Square(4, 2), new Square(4, 3)),
          new Tetromino(Color.RED, new Square(4, 2), new Square(3, 2), new Square(4, 3), new Square(5, 3)),
          new Tetromino(Color.LAWNGREEN, new Square(4, 2), new Square(5, 2), new Square(4, 3), new Square(3, 3)));

  private Constants() {

  }

}
