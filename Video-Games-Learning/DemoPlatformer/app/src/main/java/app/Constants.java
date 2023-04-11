// Copyright(C) 2023, Charles T, <chalodss@proton.me>

package app;

import javafx.scene.image.Image;

public final class Constants {

  public static final double P_WIDTH           = 48;
  public static final double P_HEIGHT          = 72;
  public static final double P_JUMP            = -15;

  public static final double OFFSET_L          = 600;
  public static final double OFFSET_R          = 1400;
  public static final double RIGHT             = 2000;
  public static final double TILE_SIZE         = 50;

  public static final double GRAVITY           = 0.5;

  public static final Image  BACKGROUND_IMG    = new Image("/assets/background.png");
  public static final Image  PLAYER_IMG        = new Image("/assets/alex.png", 48, 72, false, false);
  public static final Image  EMPTY_IMG         = new Image("/assets/empty.png");
  public static final Image  GRASS_IMG         = new Image("/assets/green.png");
  public static final Image  SKY_IMG           = new Image("/assets/blue.png");
  public static final Image  BLUE_BALL_IMG     = new Image("/assets/blue_ball.png");
  public static final Image  RED_BALL_IMG      = new Image("/assets/red_ball.png");
  public static final Image  YELLOW_SQUARE_IMG = new Image("/assets/yellow_square.png");


  private Constants() {

  }

}
