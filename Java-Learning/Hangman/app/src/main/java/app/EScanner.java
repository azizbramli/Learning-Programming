// Copyright(C) 2023, Charles T, <chalodss@proton.me>

package app;

import java.util.Scanner;

public enum EScanner {
  ;

  private static final Scanner sc = new Scanner(System.in);

  public static String get() {
    return sc.nextLine();
  }

}
