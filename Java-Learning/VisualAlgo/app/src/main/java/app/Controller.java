// Copyright(C) 2023, Charles T, <chalodss@proton.me>

package app;

import java.io.IOException;

import java.util.Arrays;
import java.util.List;

import javafx.collections.FXCollections;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.control.ComboBox;
import javafx.scene.layout.Pane;
import javafx.scene.layout.VBox;

import classes.fractals.sierpinski.ControllerFST;
import classes.gameoflife.ControllerGOL;
import classes.graphs.mazes.ControllerMaze;

import static utils.Constants.*;

public final class Controller {

  private static final List<String> ALGORITHMS = Arrays.asList(BFS, DFS, DIJKSTRA, GOL, MDS, ST, VKF);

  @FXML
  private VBox                      leftMenu;
  @FXML
  private Pane                      board;
  @FXML
  private ComboBox<String>          cmbAlgorithms;

  private Pane                      newMenu;

  public Controller() {

  }

  @FXML
  private void initialize() {
    cmbAlgorithms.setItems(FXCollections.observableList(ALGORITHMS));
  }

  @FXML
  private void loadInterface() {
    var algorithm = cmbAlgorithms.getValue();

    switch (algorithm) {
      case BFS      -> addMenu("/ViewMaze.fxml", algorithm);
      case DFS      -> addMenu("/ViewMaze.fxml", algorithm);
      case DIJKSTRA -> addMenu("/ViewMaze.fxml", algorithm);
      case GOL      -> addMenu("/ViewGOL.fxml", algorithm);
      case ST       -> addMenu("/ViewFST.fxml", algorithm);
      default       -> throw new IllegalArgumentException();
    }
  }

  private void addMenu(String view, String algorithm) {
    leftMenu.getChildren().remove(newMenu);
    try {
      var loader = new FXMLLoader(getClass().getResource(view));
      setController(loader, algorithm);
      newMenu = loader.load();
      leftMenu.getChildren().add(newMenu);
    } catch (IOException e) {
      e.printStackTrace();
    }
  }

  private void setController(FXMLLoader loader, String algorithm) {
    switch (algorithm) {
      case BFS      -> loader.setController(new ControllerMaze(board, BFS));
      case DFS      -> loader.setController(new ControllerMaze(board, DFS));
      case DIJKSTRA -> loader.setController(new ControllerMaze(board, DIJKSTRA));
      case GOL      -> loader.setController(new ControllerGOL(board));
      case ST       -> loader.setController(new ControllerFST(board));
      default       -> throw new IllegalArgumentException();
    }
  }

}
