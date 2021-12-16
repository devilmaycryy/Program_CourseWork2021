#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Person {
protected:
    int x;
    int y;

public:
    int getX();
    int getY();
    void setX(int X);
    void setY(int Y);

    void move(int X, int Y);

};

class Monster : public Person {
public:
    
    Monster(int a, int b);
};

class Princess : public Person {
public:
    
    Princess(int a, int b);
    
};