// Copyright(C) 2023, Charles T, <chalodss@proton.me>

package app;

import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;

public final class Computer extends Rectangle {

  public Computer(double x, double y, double w, double h) {
    super(x, y, w, h);
    setFill(Color.WHITE);
  }

}
