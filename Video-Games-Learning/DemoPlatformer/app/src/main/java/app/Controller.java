// Copyright(C) 2023, Charles T, <chalodss@proton.me>

package app;

import javafx.fxml.FXML;
import javafx.scene.image.ImageView;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;
import javafx.scene.layout.Pane;
import javafx.scene.text.Text;

import static app.Constants.BACKGROUND_IMG;
import static app.Constants.P_JUMP;
import static app.TileMaps.tileMap;

public final class Controller {

  @FXML
  private Pane   pane;
  @FXML
  private Text   score;
  @FXML
  private Text   level;
  @FXML
  private Text   lives;

  private Player player;
  private Game   game;


  public Controller() {

  }

  @FXML
  private void initialize() {

  }

  @FXML
  private void init() {
    TileMaps.initMap();
    player = new Player(0, 478);
    game   = new Game(player, tileMap);

    pane.getChildren().add(new ImageView(BACKGROUND_IMG));
    pane.getChildren().addAll(tileMap);
    pane.getChildren().add(player);

    pane.setOnKeyPressed(this::handleKeyPressed);
    pane.setOnKeyReleased(this::handleKeyReleased);

    Camera.setCameraX(player, pane);
  }

  @FXML
  private void pause() {

  }

  @FXML
  private void reset() {

  }

  @FXML
  private void start() {
    pane.requestFocus();
    game.start();
  }

  private void handleKeyPressed(KeyEvent e) {
    if (e.getCode() == KeyCode.J) {
      player.velX = -5;
    }
    if (e.getCode() == KeyCode.L) {
      player.velX = 5;
    }
    if (e.getCode() == KeyCode.C && player.canJump()) {
      player.velY += P_JUMP;
    }
  }

  private void handleKeyReleased(KeyEvent e) {
    if (e.getCode() == KeyCode.J || e.getCode() == KeyCode.L) {
      player.velX = 0;
    }
  }

}
