#pragma once
#include <string>
#include <list>
class Score {
public:
	std::string pName;
	int pPoints;
	Score(std::string _name, int _points)
	{
		pName = _name;
		pPoints = _points;
	}
};
std::list<Score*> scores;
std::list<Score*>::iterator scoresIterator;

