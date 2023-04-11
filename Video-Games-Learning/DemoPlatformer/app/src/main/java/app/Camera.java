// Copyright(C) 2023, Charles T, <chalodss@proton.me>

package app;

import javafx.scene.layout.Pane;

import static app.Constants.OFFSET_L;
import static app.Constants.OFFSET_R;

public final class Camera {

  private Camera() {

  }

  static void setCameraX(Player player, Pane pane) {
    player.xProperty().addListener((obs, old, newValue) -> {
      var offset = newValue.intValue();
      if (offset > OFFSET_L && offset <= OFFSET_R) {
        pane.setTranslateX(OFFSET_L - offset);
      }
    });
  }

}
