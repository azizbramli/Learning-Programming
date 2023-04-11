// Copyright(C) 2023, Charles T, <chalodss@proton.me>

package app;

import javafx.animation.Animation;
import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.application.Platform;
import javafx.beans.binding.Bindings;
import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.layout.Pane;
import javafx.util.Duration;

public final class Controller {

  @FXML
  private Pane        pane;
  @FXML
  private Label       time;

  private Chronometer chrono;

  private Timeline    timeline;


  public Controller() {
    chrono   = new Chronometer();
    timeline = new Timeline(new KeyFrame(Duration.millis(10), e -> chrono.update()));
    timeline.setCycleCount(Animation.INDEFINITE);
  }

  @FXML
  private void initialize() {
    time.textProperty().bind(Bindings.format("%02d:%02d:%02d:%d%d", chrono.hh, chrono.mm, chrono.ss, chrono.th, chrono.hd));
  }

  @FXML
  private void start() {
    timeline.play();
  }

  @FXML
  private void stop() {
    timeline.stop();
  }

  @FXML
  private void reset() {
    chrono.reset();
  }

  @FXML
  private void exit() {
    stop();
    Platform.exit();
    System.exit(0);
  }

}
