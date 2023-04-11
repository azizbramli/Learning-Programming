// Copyright(C) 2023, Charles T, <chalodss@proton.me>

package app;

public abstract class Player {

  protected String name;

  protected Player(String name) {
    this.name = name;
  }

  abstract int getMatches(int[] packets);

}
