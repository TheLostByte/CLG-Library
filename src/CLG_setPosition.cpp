#include <iostream>

using namespace std;

void setPosition2 (int length, int width)
{
    COORD coord;
    coord.X = length;
    coord.Y = width;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (!SetConsoleCursorPosition(hConsole, coord))
    {
         //to do (error)
    }
}
