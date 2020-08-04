# Documentation
Here you can find CLG documentation.

## CLG Functions:
All of the CLG functions are stored in CLG namespace, and color values are in color namespace.

## What are columns and lines?
In the CLG library, a console is splitted to columns and lines. One column or line is equal to one ASCII character.
![A ASCII character](/img/character.png)
A column is, obviously, a vertical line of those ASCII characters, and a line is a horizontal linemeasoured in ASCII character.
It can be little bit confusing, but when you will experiment with CLG, you will understand a lot more about this system.

## How to represent colors?
There are three ways to represent color in CLG:
1. Using CLG color namespace
2. Using color values (for example 2 stands for green; useful in rectangles and customCls)
3. Using hex color values (for example 0x4a stands for red and light green; useful in colorizing text)

## What is readFile?
When you have to draw something bigger, it's very time-consuming to write many printBlockRectangle functions, so in CLG we can read graphics files.
But they aren't common image formats, they're just txt files with three values:
column
line
color
and these values are repeated 130 times. So the file consists of 390 lines.
When we load a file to our program, the readFile function will render 130 ASCII characters with these three values.
You can find example use of this function in the "examples" folder

**windowTitle(string title)** - sets console window 

**printRectangle(int length, int width, int column, int line)** - prints a ASCII rectangle with specified length, width, column and line

**printBlockRectangle(int length, int width, int color, int column, int line)** - same as above, but has a color.

**setPosition (int length, int width)** - sets cursors position with specified location

**printHorizontalLine(int length, int column, int line, bool leftConnector, bool rightConnector)** - prints a horizontal line

**printVerticalLine(int width, int column, int line, bool leftConnector, bool rightConnector)** - same as above but vertical

**clsCustom(char charFill, int colorValue)** - clears the console window with a custom character and/or color

**cls()** - clears the console window

**PixelV(int x, int y, int red, int green, int blue)** - prints a pixel at a specified location (note that it's not column and line, it's represented in pixels) and a specified color (RGB)
NOTE: If you are compiling your program in codeblocks, you have to go to settings->compiler->linker settings and in link libraries add gdi32.
NOTE: It's very slow when it comes to render bigger things and it can be easily "destroyed" by, for example, resizing the window

**textColor(int colorValue)** - sets the text color

**readFile(string fileName)** - reads a file (see: "What is readFile?")

