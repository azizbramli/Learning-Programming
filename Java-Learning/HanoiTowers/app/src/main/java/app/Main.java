// Copyright(C) 2023, Charles T, <chalodss@proton.me>

package app;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

public class Main extends Application {

  @Override
  public void start(Stage primaryStage) {
    try {
      VBox  root  = FXMLLoader.load(getClass().getResource("/View.fxml"));
      Scene scene = new Scene(root);

      primaryStage.setTitle("Hanoi Towers");
      primaryStage.setResizable(false);
      primaryStage.setScene(scene);
      primaryStage.show();
    } catch (Exception e) {
      e.printStackTrace();
    }
  }

  public static void main(String[] args) {
    launch(args);
  }

}
