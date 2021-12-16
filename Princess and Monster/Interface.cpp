#include "Interface.h"


Button::Button(Font* font1) {
	convex.setPointCount(4);
	
	


	text.setFont(*font1);
	
	
}

void Button::showbutton(std::string a, RenderWindow* window1, int x1, int y1, int x2, int y2, float p1, float p2, float p3, int p4, Vector2i* localPosition, int m1, int m2, int m3, int m4) {
	text.setString(a);

	convex.setPosition(x1, y1);
	text.setPosition(x2, y2);

	convex.setFillColor(Color(255, 255, 255, 0));
	text.setFillColor(Color::White);

	convex.setPoint(0, Vector2f(p1, p1));
	convex.setPoint(1, Vector2f(p2, p1));
	convex.setPoint(2, Vector2f(p2, p3));
	convex.setPoint(3, Vector2f(p1, p3));
	text.setCharacterSize(p4);

	

	if (localPosition->x > m1 && localPosition->x < m2 && localPosition->y > m3 && localPosition->y < m4) {
		convex.setFillColor(Color(255, 255, 255, 255));
		text.setFillColor(Color::Black);
	}

	window1->draw(convex);
	window1->draw(text);

}








Cell::Cell(float p1, float p2, float p3) {
	convex3.setPointCount(4);
	convex3.setFillColor(Color(255, 255, 255, 150));
	convex3.setPoint(0, Vector2f(p1, p1));
	convex3.setPoint(1, Vector2f(p2, p1));
	convex3.setPoint(2, Vector2f(p2, p3));
	convex3.setPoint(3, Vector2f(p1, p3));
}

void Cell::showall(int x1, int y1, Vector2i* localPosition, RenderWindow* window1, int p1, int p2, int p3, int p4) {
	convex3.setPosition(x1, y1);
	*localPosition = Mouse::getPosition(*window1);

	if (localPosition->x > p1 && localPosition->x < p2 && localPosition->y > p3 && localPosition->y < p4) {
		window1->draw(convex3);
	}
}

void Cell::Move(int x1, int y1, Vector2i* localPosition, RenderWindow* window1, Event* event, Person* obj, int X1, int Y1, bool *move, int* item1, int* item2, Time* time4, Time* time2, Clock* clock2, int *State, int numberX, int numberY, SearchAlgorithm* S1, int* COUNT1, int* COUNT2, int* COUNT3, int* COUNT4) {
	
	*localPosition = Mouse::getPosition(*window1);

	if ((*event).type == Event::MouseButtonPressed && (*localPosition).x > X1 && (*localPosition).x < X1+160 && (*localPosition).y > Y1 && (*localPosition).y < Y1+160)
	{
		if ((*event).mouseButton.button == Mouse::Left)
		{
			
			if ((*move) == 0 && S1->getReady() == 1) {
				if ((*COUNT1) != 0) {
					if (y1 - obj->getY() == 1 && x1 - obj->getX() == 0) {
						(*COUNT1)--;
					}
					else {
						S1->setReady(0);
					}
				}
				else if ((*COUNT2) != 0) {
					if (y1 - obj->getY() == 0 && x1 - obj->getX() == 1) {
						(*COUNT2)--;
					}
					else {
						S1->setReady(0);
					}
				}
				else if ((*COUNT3) != 0) {
					if (y1 - obj->getY() == -1 && x1 - obj->getX() == 0) {
						(*COUNT3)--;
					}
					else {
						S1->setReady(0);
					}
				}
				else if ((*COUNT4) != 0) {
					if (y1 - obj->getY() == 0 && x1 - obj->getX() == -1) {
						(*COUNT4)--;
					}
					else {
						S1->setReady(0);
					}
				}
				
				
			}
			
			

			*time2 = clock2->restart();
			(*obj).move(x1, y1);
			if ((*move) == 0) {
				*move = 1;
				*item1 = 3;
				*item2 = 0;
				
				
			}
			else {
				*move = 0;
				if ((*item1) == (*item2)) {
					*item1 = 2;
				}
				else {
					*item1 = 2;
					*item2 = 0;
				}
				
				*time4 += *time2;
				
				
			}
			
			if (abs(x1 - numberX) <= 2.0 && abs(y1 - numberY) <= 2.0) {
				*State = 2;
				
			}
			else {
				*State = 3;
			}
		}
	}
}






SearchAlgorithm::SearchAlgorithm(float p1, float p2, float p3) {
	active = 0;
	ready = 0;
	convex3.setPointCount(4);
	convex3.setFillColor(Color(255, 0, 0, 150));
	convex3.setPoint(0, Vector2f(p1, p1));
	convex3.setPoint(1, Vector2f(p2, p1));
	convex3.setPoint(2, Vector2f(p2, p3));
	convex3.setPoint(3, Vector2f(p1, p3));
}

int SearchAlgorithm::getActive() {
	return active;
}

void SearchAlgorithm::setActive(int a) {
	active = a;
}

int SearchAlgorithm::getReady() {
	return ready;
}
void SearchAlgorithm::setReady(int a) {
	ready = a;
}

void SearchAlgorithm::show(int x1, int y1, RenderWindow* window1) {
	convex3.setPosition(x1, y1);
	window1->draw(convex3);
}