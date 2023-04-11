// Copyright(C) 2023, Charles T, <chalodss@proton.me>

package app;

import javafx.animation.AnimationTimer;
import javafx.beans.property.LongProperty;
import javafx.beans.property.SimpleLongProperty;
import javafx.fxml.FXML;
import javafx.scene.canvas.Canvas;
import javafx.scene.control.CheckBox;
import javafx.scene.input.KeyEvent;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.text.Text;

import static app.Collisions.*;

public final class Controller {

  @FXML
  private Pane           board;
  @FXML
  private Text           score;
  @FXML
  private Text           level;
  @FXML
  private CheckBox       aiMode;
  @FXML
  private Canvas         background;

  private LongProperty   timeInterval;

  private AnimationTimer loop;

  private Game           game;


  public Controller() {

  }

  @FXML
  private void initialize() {
    var tetroLayerCanvas = new Canvas(350, 700);

    Renderer.setGcBg(background.getGraphicsContext2D());
    Renderer.renderGrid(10, 350, 700);
    Renderer.setGcTetro(tetroLayerCanvas.getGraphicsContext2D());
    board.getChildren().add(tetroLayerCanvas);
  }

  @FXML
  private void start() {
    init();
    game = new Game();
    game.end.addListener((obs, old, newv) -> score.setFill(Color.RED));

    level.textProperty().bind(game.level.asString());
    score.textProperty().bind(game.score.asString());
    timeInterval.bind(game.time);

    loop.start();
  }

  private void init() {
    timeInterval = new SimpleLongProperty(1_000_000_000L);

    background.setOnKeyPressed(this::getInputs);
    background.requestFocus();
    if (loop != null) {
      loop.stop();
    } else {
      loop = new AnimationTimer() {
        long lastTime;

        @Override
        public void handle(long now) {
          long time = now - lastTime;
          if (time >= timeInterval.get()) {
            game.update();
            game.endGame();
            lastTime = now;
          }
          Renderer.renderTetrominos(game.tetrominos);
        }
      };
    }
  }

  private void getInputs(KeyEvent e) {
    switch (e.getCode()) {
      case J:
        if (isNotLeftCollided(game.curTetro, game.board))
          game.curTetro.move(-1, 0);
        break;
      case K:
        if (isNotBottomCollided(game.curTetro, game.board))
          game.curTetro.move(0, 1);
        break;
      case L:
        if (isNotRightCollided(game.curTetro, game.board))
          game.curTetro.move(1, 0);
        break;
      case C:
        if (isNotTetroCollided(game.curTetro, game.tetrominos))
          game.curTetro.rotate();
        break;
      case SPACE:
        game.dropTetromino();
        break;
      default:
        break;
    }
  }

}
