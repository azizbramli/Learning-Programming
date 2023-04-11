// Copyright(C) 2023, Charles T, <chalodss@proton.me>

package app;

enum EState {

  X(1), O(-1), E(0);

  int value;

  EState(int value) {
    this.value = value;
  }

  @Override
  public String toString() {
    return String.valueOf(value);
  }

}
