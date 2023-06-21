#pragma once

class Point
{
public:
    void changePoint(int, int);
    void changePoint(Point);
    void changeX(int);
    void changeY(int);
    int getX();
    int getY();

private:
    int x, y;
};