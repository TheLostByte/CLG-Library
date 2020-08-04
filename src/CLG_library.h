#ifndef CLG_LIBRARY_H_INCLUDED
#define CLG_LIBRARY_H_INCLUDED

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include "CLG_setPosition.cpp"
#include "GotoLine.cpp"

using namespace std;

namespace CLG
{
    namespace color
    {
        const short black = 0;
        const short blue = 1;
        const short green = 2;
        const short aqua = 3;
        const short red = 4;
        const short purple = 5;
        const short yellow = 6;
        const short white = 7;
        const short gray = 8;
        const short light_blue = 9;
        const short light_green = 10;
        const short light_aqua = 11;
        const short light_red = 12;
        const short light_purple = 13;
        const short light_yellow = 14;
        const short bright_white = 15;
    }

    void windowTitle (string title)
    {
        string str(title);
        SetConsoleTitle(str.c_str());
    }
    void printRectangle(int length, int width, int column, int line)
    {
        COORD coord;
        coord.X = column;
        coord.Y = line;
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        setPosition2(column, line);
        cout<<(char)201;
        for (int i = 0; i < width; i++)
        {
            cout << (char)205; 
        }
        cout << (char)187;
        cout<<endl;
        for (int i = 0; i < length; i++)
        {
            line++;
            setPosition2(column, line);
            cout << (char)186;
            for (int i = 0; i < width; i++)
            {
                cout<<(char)000;
            }
            cout<<(char)186;
            cout<<endl;
        }
        setPosition2(column, line);
        column++;
        cout<<(char)200;
        for (int i = 0; i < width; i++)
        {
            cout << (char)205;
        }
        cout << (char)188;
        cout<<endl;
    }

    void printBlockRectangle(int length, int width, int color, int column, int line)
    {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, color);
        COORD coord;
        coord.X = column;
        coord.Y = line;
        bool firstTime = true;
        if (!SetConsoleCursorPosition(hConsole, coord))
        {

        }
        for (int i=0; i<width; i++)
        {
            if (!firstTime == true)
            {
                line = line + 1;
            }
            setPosition2(column, line);
            for (int i = 0; i<length; i++)
            {
                cout<<(char)219;
            }
            firstTime = false;
        }

        SetConsoleTextAttribute(hConsole, 15);
    }

    void setPosition (int length, int width)
    {
        COORD coord;
        coord.X = length;
        coord.Y = width;
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        if (!SetConsoleCursorPosition(hConsole, coord))
        {
         //error...
        }
    }
    void printHorizontalLine(int length, int column, int line, bool leftConnector, bool rightConnector)
    {
        setPosition2(column, line);
        for (int i = 0; i < length; i++)
        {
            cout<<(char)205;
        }
        if (rightConnector==true&&leftConnector==false)
        {
            column = column + length;
            setPosition2(column, line);
            cout<<(char)185;
        }
        if (rightConnector==true&&leftConnector==false)
        {
            column = column - 1;
            setPosition2(column, line);
            cout<<(char)204;
            column = column + length + 1;
            setPosition2(column, line);
            cout<<(char)185;
        }
        if (rightConnector==false&&leftConnector==true)
        {
            column = column - 1;
            setPosition2(column, line);
            cout<<(char)204;
        }
    }

    void printVerticalLine(int width, int column, int line, bool leftConnector, bool rightConnector)
    {
        setPosition2(column, line);
        for (int i = 0; i < width; i++)
        {
            line = line + 1;
            setPosition2(column, line);
            cout<<(char)186;
            cout<<endl;
        }
        if (leftConnector==true&&rightConnector==false)
        {
            line = line - width;
            setPosition2(column, line);
            cout<<(char)203;
        }
        if (leftConnector==false&&rightConnector==true)
        {
            line = line + 1;
            setPosition2(column, line);
            cout<<(char)202;
        }
        if (leftConnector==true&&rightConnector==true)
        {
            line = line - width;
            setPosition2(column, line);
            cout<<(char)203;
            line = line + width + 1;
            setPosition2(column, line);
            cout<<(char)202;
        }
    }

    void clsCustom(char charFill, int colorValue)
    {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, colorValue);
        HANDLE                     hStdOut;
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        DWORD                      count;
        DWORD                      cellCount;
        COORD                      homeCoords = { 0, 0 };

        hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
        if (hStdOut == INVALID_HANDLE_VALUE) return;

         if (!GetConsoleScreenBufferInfo( hStdOut, &csbi )) return;
  cellCount = csbi.dwSize.X *csbi.dwSize.Y;

  if (!FillConsoleOutputCharacter(
    hStdOut,
    (TCHAR) charFill,
    cellCount,
    homeCoords,
    &count
    )) return;

  if (!FillConsoleOutputAttribute(
    hStdOut,
    csbi.wAttributes,
    cellCount,
    homeCoords,
    &count
    )) return;

  SetConsoleCursorPosition( hStdOut, homeCoords );
    }

void cls(void)
{
    HANDLE hStdOut;
CONSOLE_SCREEN_BUFFER_INFO csbi;
  DWORD                      count;
  DWORD                      cellCount;
  COORD                      homeCoords = { 0, 0 };

  hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
  if (hStdOut == INVALID_HANDLE_VALUE) return;

  if (!GetConsoleScreenBufferInfo( hStdOut, &csbi )) return;
  cellCount = csbi.dwSize.X *csbi.dwSize.Y;

  if (!FillConsoleOutputCharacter(
    hStdOut,
    (TCHAR) ' ',
    cellCount,
    homeCoords,
    &count
    )) return;

  if (!FillConsoleOutputAttribute(
    hStdOut,
    csbi.wAttributes,
    cellCount,
    homeCoords,
    &count
    )) return;

  SetConsoleCursorPosition( hStdOut, homeCoords );
    }



void PixelV(int x, int y, int red, int green, int blue)
{
    //NOTE: If you are compiling your program in codeblocks, you have to go to settings->compiler->linker settings and in link libraries add gdi32.
    //Otherwise this function won't work
    HWND console = GetConsoleWindow();
    HDC dc = GetDC(console);

    COLORREF COLOR= RGB(red,green,blue);

    SetPixel(dc,x,y,COLOR);

    ReleaseDC(console, dc);
}

void textColor(int colorValue)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, colorValue);
}
void readFile(string fileName)
{
    string line;
    int x;
    int y;
    int color;
    int lineType = 1;
    int lineNum = 1;
    fstream file;
    file.open(fileName);
    while (getline(file, line))
    {
        if (lineType == 1)
        {
            GotoLine(file, lineNum);
            string line1;
            file >> line1;
            stringstream l1(line1);
            l1 >> x;
            lineType++;
            lineNum++;
        }
        if (lineType == 2)
        {
            GotoLine(file, lineNum);
            string line2;
            file >> line2;
            stringstream l2(line2);
            l2 >> y;
            lineType++;
            lineNum++;
        }
        if (lineType == 3)
        {
            GotoLine(file, lineNum);
            string line3;
            file >> line3;
            stringstream l3(line3);
            l3 >> color;
            lineType = 1;
            lineNum++;
        }
        printBlockRectangle(1, 1, color, x, y);
    }
    Sleep(300);
    file.close();
}
}

#endif // CLG_LIBRARY_H_INCLUDED
