#include "../src/CLG_library.h"

using namespace CLG;

int main()
{
    cls();
    //The code down below renders a nicely coloured rectangle. Try it yourself!
    /*for (int x = 0; x < 256; x++)
        for (int y = 0; y < 256; y++)
            PixelV(x, y, x, y, 255);*/
    windowTitle("CLG Window");
    setPosition(15, 2);
    cout << "A text placed in 15, 2";
    for (int color = 0; color < 15; color++)
    {
        textColor(color);
        setPosition(10, color);
        cout << "A colored text placed in " << color << ", 9";
    }
    setPosition(8, 20);
    textColor(color::aqua);
    cout << "<-A rectangle!";
    printBlockRectangle(5, 5, color::green, 1, 20);
    printHorizontalLine(7, 23, 16, 1, 0);
    setPosition(20, 30);
    return 0;
}
