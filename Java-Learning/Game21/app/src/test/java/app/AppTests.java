// Copyright(C) 2023, Charles T, <chalodss@proton.me>

package app;

import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.RepeatedTest;

import static org.junit.jupiter.api.Assertions.*;

class AppTests {
    Player p = new Player("Chalodss");
    
    @RepeatedTest(value = 100, name = "{displayName} - {currentRepetition} / {totalRepetitions}")
    @DisplayName("testThrowDice")
    void testThrowDice() {
        var diceRoll = p.throwDice();
        assertTrue(diceRoll >= 1 && diceRoll <= 6, "");
    }
}
