#include <MeggyJrSimple.h>    // Required code, line 1 of 2.
int directionn = 0; // possible values are 0, 1, 2, 3
int marker = 4;

struct Point{
  int xPlayer; // x coordinates of player
  int yPlayer; // y coordinates of player
};

Point p1 = {3, 4};
Point p2 = {4, 4};
Point p3 = {5, 4};

Point snakeArray[64] = {p1, p2, p3};

void setup()           
{
  MeggyJrSimpleSetup();     
}

void loop()                     // the main loop
{
  DisplaySlate();
  delay(425);
  ClearSlate(); 
  
  directions(); //changes the direction of snake
  updateSnake(); // 
  moveHead();


  for(int i = 0; i < marker; i++) //Draws snake
    {
      DrawPx(snakeArray[i].xPlayer, snakeArray[i].yPlayer, Blue);
    }
}

void directions() // all this does is changes the direction based on user input
{
  CheckButtonsPress();
  if(Button_Left)
  {
    directionn = 3;
  }
  if(Button_Right)
  {
    directionn = 1;
  }
  if(Button_Down)
  {
    directionn = 2;
  }
  if(Button_Up)
  {
    directionn = 0;
  }
}

void updateSnake()
{
  for(int i = marker - 1; i > 0; i--)
  {
    snakeArray[i] = snakeArray[i - 1];
  }
}



void moveHead() //uses directions to change head placement
{
  if(directionn == 0) //identifies direction
  {
    if(snakeArray[0].yPlayer < 7) //checks edge of screen
    {
      snakeArray[0].yPlayer ++; //moves snake up
    }
    else
    snakeArray[0].yPlayer = 0; // other wise wrap around screen
  }
  if(directionn == 1)
  {
    if(snakeArray[0].xPlayer < 7)
    {
      snakeArray[0].xPlayer = snakeArray[0].xPlayer + 1;
    }
    else
    snakeArray[0].xPlayer = 0;
  }
  if(directionn == 2)
  {
    if(snakeArray[0].yPlayer > 0)
    {
      snakeArray[0].yPlayer = snakeArray[0].yPlayer - 1;
    }
    else
    snakeArray[0].yPlayer = 7;
  } 
  if(directionn == 3)
  {
    if(snakeArray[0].xPlayer > 0)
    {
      snakeArray[0].xPlayer = snakeArray[0].xPlayer - 1;
    }
    else
    snakeArray[0].xPlayer = 7;
  } 
}
