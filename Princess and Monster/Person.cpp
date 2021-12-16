#include "Person.h"

int Person::getX() {
	return x;
}

int Person::getY() {
	return y;
}
void Person::setX(int X) {
	x = X;
}
void Person::setY(int Y) {
	y = Y;
}

void Person::move(int X, int Y) {
	x = X;
	y = Y;
}








Monster::Monster(int a, int b) {
	x = a;
	y = b;

}

Princess::Princess(int a, int b) {
	x = a;
	y = b;

}

