// Copyright(C) 2023, Charles T, <chalodss@proton.me>

package app;

import java.util.List;

import javafx.animation.AnimationTimer;

import static app.Collisions.*;

public final class Game extends AnimationTimer {

  final Player          player;
  final List<MapEntity> tileMap;


  public Game(Player player, List<MapEntity> tileMap) {
    this.player  = player;
    this.tileMap = tileMap;
  }

  @Override
  public void handle(long time) {
    updatePlayer();
  }

  void updatePlayer() {
    player.moveY();
    collisionPlatformY(player, tileMap);
    player.moveX();
    collisionPlatformX(player, tileMap);
  }

}
