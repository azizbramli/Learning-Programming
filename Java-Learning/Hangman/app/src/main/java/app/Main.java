// Copyright(C) 2023, Charles T, <chalodss@proton.me>

package app;

public class Main {

  public static void main(String[] args) {
    char resp;

    do {
      new Game(args[0]).run();
      System.out.println("Another game? y / n");
      resp = EScanner.get().charAt(0);
    } while (resp == 'y');
  }

}
