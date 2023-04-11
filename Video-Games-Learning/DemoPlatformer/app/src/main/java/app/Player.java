// Copyright(C) 2023, Charles T, <chalodss@proton.me>

package app;

import java.util.function.Predicate;

import javafx.scene.image.ImageView;

import static app.Collisions.collide;
import static app.Constants.PLAYER_IMG;
import static app.Constants.GRAVITY;
import static app.TileMaps.tileMap;

public final class Player extends ImageView {

  double velX;
  double velY;

  public Player(double x, double y) {
    setX(x);
    setY(y);
    setImage(PLAYER_IMG);
  }

  void moveX() {
    setX(getX() + velX);
  }

  void moveY() {
    velY += GRAVITY;
    setY(getY() + velY);
  }

  boolean canJump() {
    Predicate<MapEntity> pr = tile -> collide(this, tile);
    var                  op = tileMap.stream().filter(pr);

    setY(getY() + 1);
    return op.count() > 0;
  }

}
