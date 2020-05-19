#include "gtest/gtest.h"

#include <string>


   enum enuDirection
{
  NORTH,
  EAST,
  SOUTH,
  WEST
};

enum enuOrder
{
  FORWARD,
  BACKWARD
};

class Rover
{

    struct stCoordMask
    {
        int Xmask;
        int Ymask;
    };

  public:
    Rover(int X, int Y, enuDirection direction)
    {
      this->m_CoordX = X;
      this->m_CoordY = Y;
      this->m_Direction = direction;
    }

    void move(enuOrder Order)
    {
      this->m_CoordY += m_MoveTable[this->m_Direction][Order].Ymask;
      this->m_CoordX += m_MoveTable[this->m_Direction][Order].Xmask;
    }

    int getCoordX(void)
    {
      return m_CoordX;
    }
    int getCoordY(void)
    {
      return m_CoordY;
    }
    enuDirection getDirection(void)
    {
      return m_Direction;
    }

  private:
    int m_CoordX;
    int m_CoordY;
    enuDirection m_Direction;
    stCoordMask m_MoveTable[4][2] = {
                                      { { 0, 1 }, { 0, -1 } },
                                      { { 1, 0 }, { -1, 0 } },
                                      { { 0, -1 }, { 0, 1 } },
                                      { { -1, 0 }, { 1, 0 } }

    };

};


TEST(Initial, CreateRover)
{
  Rover myRover(4, 5, NORTH);
  ASSERT_EQ(myRover.getCoordX(), 4);
  ASSERT_EQ(myRover.getCoordY(), 5);
  ASSERT_EQ(myRover.getDirection(), NORTH);
}

TEST(MoveForward, FacingNorth)
{
  Rover myRover(4, 5, NORTH);
  myRover.move(FORWARD);
  ASSERT_EQ(myRover.getCoordX(), 4);
  ASSERT_EQ(myRover.getCoordY(), 6);
  ASSERT_EQ(myRover.getDirection(), NORTH);
}

TEST(MoveForward, FacingEast)
{
  Rover myRover(4, 5, EAST);
  myRover.move(FORWARD);
  ASSERT_EQ(myRover.getCoordX(), 5);
  ASSERT_EQ(myRover.getCoordY(), 5);
  ASSERT_EQ(myRover.getDirection(), EAST);
}

TEST(MoveForward, FacingSouth)
{
  Rover myRover(4, 5, SOUTH);
  myRover.move(FORWARD);
  ASSERT_EQ(myRover.getCoordX(), 4);
  ASSERT_EQ(myRover.getCoordY(), 4);
  ASSERT_EQ(myRover.getDirection(), SOUTH);
}

TEST(MoveForward, FacingWest)
{
  Rover myRover(4, 5, WEST);
  myRover.move(FORWARD);
  ASSERT_EQ(myRover.getCoordX(), 3);
  ASSERT_EQ(myRover.getCoordY(), 5);
  ASSERT_EQ(myRover.getDirection(), WEST);
}

TEST(MoveBackward, FacingNorth)
 {
 Rover myRover(4, 5, NORTH);
 myRover.move(BACKWARD);
 ASSERT_EQ(myRover.getCoordX(), 4);
  ASSERT_EQ(myRover.getCoordY(), 4);
 ASSERT_EQ(myRover.getDirection(), NORTH);
}

/*TEST(should, fail) {
    ASSERT_EQ("Oui", "NON");
}
 */


