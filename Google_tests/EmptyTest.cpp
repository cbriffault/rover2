#include "gtest/gtest.h"

#include <string>
#include <stdlib.h>

#include "Game.h"


TEST(Game, Addplayer)
{
  Game aGame;
  ASSERT_EQ(aGame.add("Chet"), true);
  ASSERT_EQ(aGame.add("Pat"), true);
  ASSERT_EQ(aGame.add("Sue"), true);
}

/*TEST(should, fail) {
    ASSERT_EQ("Oui", "NON");
}
 */


