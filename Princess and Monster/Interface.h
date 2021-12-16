#pragma once
#include <SFML/Graphics.hpp>
#include "Person.h"
#include <math.h>
#include <iostream>

using namespace sf;

class Button {
private:
	ConvexShape convex;
	Text text;
public:
	Button(Font* font1);
	void showbutton(std::string a, RenderWindow* window1, int x1, int y1, int x2, int y2, float p1, float p2, float p3, int p4, Vector2i* localPosition, int m1, int m2, int m3, int m4);
	
	

};











class SearchAlgorithm {
private:
	int active;
	int ready;
	ConvexShape convex3;
public:
	SearchAlgorithm(float p1, float p2, float p3);
	int getActive();
	void setActive(int a);
	int getReady();
	void setReady(int a);
	void show(int x1, int y1, RenderWindow* window1);

};


class Cell {
private:
	ConvexShape convex3;
public:
	Cell(float p1, float p2, float p3);
	void showall(int x1, int y1, Vector2i* localPosition, RenderWindow* window1, int p1, int p2, int p3, int p4);
	void Move(int x1, int y1, Vector2i* localPosition, RenderWindow* window1, Event* event, Person* obj, int X1, int Y1, bool* move, int* item1, int* item2, Time* time4, Time* time2, Clock* clock2, int* State, int numberX, int numberY, SearchAlgorithm* S1, int* COUNT1, int* COUNT2, int* COUNT3, int* COUNT4);

};