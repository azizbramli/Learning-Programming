// Copyright(C) 2023, Charles T, <chalodss@proton.me>

package app;

public final class Constants {

    private Constants() {

    }

    private static final String[] MAN = {
        """    
            ------
            |    |
            |
            |
            |
            |
            |
            |
            --------""",
            """
                ------
                |    |
                |    0
                |
                |
                |
                |
                |
                --------""",
                """ 
                    ------
                    |    |
                    |    0
                    |    |
                    |    |
                    |
                    |
                    |
                    --------""",
                    """
                        ------
                        |    |
                        |    0
                        | -- |
                        |    |
                        |
                        |
                        |
                        --------""",
                        """
                            ------
                            |    |
                            |    0
                            | -- | --
                            |    |
                            |
                            |
                            |
                            --------""",
                            """
                                ------
                                |    |
                                |    0
                                | -- | --
                                |    |
                                |   |
                                |   |
                                |
                                --------""",
                                """
                                    ------
                                    |    |
                                    |    0
                                    | -- | --
                                    |    |
                                    |   | |
                                    |   | |
                                    |
                                    --------"""
    };

    public static String[] getMan() {
      return MAN;
    }

}
