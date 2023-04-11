// Copyright(C) 2023, Charles T, <chalodss@proton.me>

package app;

import java.util.Random;

public final class Player {

  private static final Random rand = new Random();

  private final String        name;

  public Player(String name) {
    this.name = name;
  }

  int throwDice() {
    return rand.nextInt(6) + 1;
  }

  @Override
  public String toString() {
    return name;
  }

}
