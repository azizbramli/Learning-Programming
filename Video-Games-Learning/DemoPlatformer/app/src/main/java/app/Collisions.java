// Copyright(C) 2023, Charles T, <chalodss@proton.me>

package app;

import java.util.function.Predicate;
import java.util.List;

import static app.Constants.P_HEIGHT;
import static app.Constants.P_WIDTH;
import static app.Constants.TILE_SIZE;

public final class Collisions {

  private Collisions() {

  }

  static boolean collide(Player p, MapEntity e) {
    return p.getX() + P_WIDTH > e.getX() &&
           p.getX() < e.getX() + TILE_SIZE &&
           p.getY() + P_HEIGHT > e.getY() &&
           p.getY() < e.getY() + TILE_SIZE;
  }

  static void collisionPlatformX(Player p, List<MapEntity> tileMap) {
    Predicate<MapEntity> pr = tile -> collide(p, tile);
    var                  op = tileMap.stream().filter(pr).findFirst();

    if (op.isPresent()) {
      var e = op.get();
      if (p.velX > 0) {
        p.setX(e.getX() - P_WIDTH);
      } else if (p.velX < 0) {
        p.setX(e.getX() + TILE_SIZE);
      }
    }
  }

  static void collisionPlatformY(Player p, List<MapEntity> tileMap) {
    Predicate<MapEntity> pr = tile -> collide(p, tile);
    var                  op = tileMap.stream().filter(pr).findFirst();

    if (op.isPresent()) {
      var e = op.get();
      if (p.velY > 0) {
        p.setY(e.getY() - P_HEIGHT);
      } else if (p.velY < 0) {
        p.setY(e.getY() + TILE_SIZE);
      }
      p.velY = 0;
    }
  }

}
