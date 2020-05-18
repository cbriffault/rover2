#include "gtest/gtest.h"

#include <string>

std::string u8MoveRover(int x, int y, char FaceDirection, char ArrayCommands);

/*TEST(should, pass) {
    ASSERT_EQ(1+1, 2);
 }*/

/*TEST(should, fail) {
    ASSERT_EQ("Oui", "NON");
}
 */


TEST(MoverRover_F, pass)
{
  ASSERT_EQ(u8MoveRover(100, 100, 'N', 'f'), "101:100");
}
TEST(MoverRover_b, pass)
{
  ASSERT_EQ(u8MoveRover(100, 100, 'N', 'b'), "99:100");
}
TEST(MoverRover_r, pass)
{
  ASSERT_EQ(u8MoveRover(100, 100, 'N', 'r'), "100:101");
}
TEST(MoverRover_l, pass)
{
  ASSERT_EQ(u8MoveRover(100, 100, 'N', 'l'), "100:99");
}


std::string u8MoveRover(int x, int y, char FaceDirection, char ArrayCommands)
{
  std::string output;
  std::stringstream ss_x;
  std::stringstream ss_y;

  if (ArrayCommands == 'f')
  {
    x = x + 1;
  }
  else if (ArrayCommands == 'b')
  {
    x = x - 1;
  }
  else if (ArrayCommands == 'r')
  {
    y = y + 1;
  }
  else if (ArrayCommands == 'l')
  {
    y = y - 1;
  }
  ss_x << x;
  ss_y << y;
  output = ss_x.str() + ":" + ss_y.str();
  return output;
}
