#include <SFML/Graphics.hpp>
#include <iostream>
#include "Interface.h"
#include "Person.h"
#include "Exception.h"
#include "Score.h"
#include <math.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
using namespace sf;



int main()
{
	//setlocale(LC_ALL, "Ukrainian");


	srand((unsigned)time(0));

	RenderWindow window;
	Font font, font2;
	font.loadFromFile("Beyond Wonderland.ttf");
	font2.loadFromFile("BLKCHCRY.TTF");
	
	Text MainText1, MainText2, MainText3;
	MainText1.setFont(font);
	MainText1.setCharacterSize(170);
	MainText1.setPosition(600, 10);
	MainText1.setString("The Princess");
	MainText1.setFillColor(Color::White);
	MainText2.setFont(font);
	MainText2.setCharacterSize(230);
	MainText2.setPosition(810, 10);
	MainText2.setString("&");
	MainText2.setFillColor(Color(160, 160, 160, 255));
	MainText3.setFont(font);
	MainText3.setCharacterSize(170);
	MainText3.setPosition(580, 150);
	MainText3.setString(" The Monster");
	MainText3.setFillColor(Color::White);
	bool saveTime = false;
	bool readResult = false;



	/* Main menu */
	/*-----------*/

	
	

	window.create(VideoMode(1920, 1080), "Princess and Monster", Style::Fullscreen);
	Button MenuButton(&font2);

	Time time1, time2, time3, time4;
	Clock clock1, clock2, clock3;
	time4 = seconds(0);

	Text MyTime1;
	MyTime1.setFont(font2);
	MyTime1.setCharacterSize(70);
	MyTime1.setFillColor(Color::White);
	MyTime1.setPosition(200, 900);
	


	Text EndText;
	ConvexShape EndShape;
	
	/*-----------*/
	std::string name = "";
	Text nameText, test;



	Vector2i localPosition;
	int State = 0;
	bool move = 0;


	

	/*The Game*/
	/*-----------*/

	
	
	Texture texture1;	

	try
	{
		if (!texture1.loadFromFile("Monster.png")) throw Exception(1);
		else {
			texture1.loadFromFile("Monster.png");
		}

	}
	catch (Exception& e)
	{
		Text error = e.show();
		font2.loadFromFile("BLKCHCRY.TTF");
		error.setFont(font);
		error.setCharacterSize(70);
		error.setFillColor(Color::White);
		error.setPosition(100, 50);
		window.draw(error);
		return -1;
	}

	Sprite MonsterSprite(texture1);

	Texture texture2;

	try
	{
		if (!texture2.loadFromFile("Princess.png")) throw Exception(1);
		else {
			texture2.loadFromFile("Princess.png");
		}

	}
	catch (Exception& e)
	{
		Text error = e.show();
		font2.loadFromFile("BLKCHCRY.TTF");
		error.setFont(font);
		error.setCharacterSize(70);
		error.setFillColor(Color::White);
		error.setPosition(100, 50);
		window.draw(error);
		return -1;
	}
		
	Sprite PrincessSprite(texture2);



	Texture texture3;
	try
	{
		if (!texture3.loadFromFile("Wall.png")) throw Exception(1);
		else {
			texture3.loadFromFile("Wall.png");
		}

	}
	catch (Exception& e)
	{
		Text error = e.show();
		font2.loadFromFile("BLKCHCRY.TTF");
		error.setFont(font);
		error.setCharacterSize(70);
		error.setFillColor(Color::White);
		error.setPosition(100, 50);
		window.draw(error);
		return -1;
	}

		
	Sprite Wall(texture3);


	Texture texture4;
	try
	{
		if (!texture4.loadFromFile("Floor.png")) throw Exception(1);
		else {
			texture4.loadFromFile("Floor.png");
		}

	}
	catch (Exception& e)
	{
		Text error = e.show();
		font2.loadFromFile("BLKCHCRY.TTF");
		error.setFont(font);
		error.setCharacterSize(70);
		error.setFillColor(Color::White);
		error.setPosition(100, 50);
		window.draw(error);
		return -1;
	}

		
	Sprite Floor(texture4);

	Texture texture5;
	try
	{
		if (!texture5.loadFromFile("PrincessFace.png")) throw Exception(1);
		else {
			texture5.loadFromFile("PrincessFace.png");
		}

	}
	catch (Exception& e)
	{
		Text error = e.show();
		font2.loadFromFile("BLKCHCRY.TTF");
		error.setFont(font);
		error.setCharacterSize(70);
		error.setFillColor(Color::White);
		error.setPosition(100, 50);
		window.draw(error);
		return -1;
	}

	
	Sprite PrincessFace(texture5);

	Texture texture6;

	try
	{
		if (!texture6.loadFromFile("MonsterFace.png")) throw Exception(1);
		else {
			texture6.loadFromFile("MonsterFace.png");
		}

	}
	catch (Exception& e)
	{
		Text error = e.show();
		font2.loadFromFile("BLKCHCRY.TTF");
		error.setFont(font);
		error.setCharacterSize(70);
		error.setFillColor(Color::White);
		error.setPosition(100, 50);
		window.draw(error);
		return -1;
	}


	Sprite MonsterFace(texture6);
	

	Cell C1(0.f, 160.f, 160.f);
	SearchAlgorithm S1(0.f, 160.f, 160.f);
	int COUNT1 = 0, COUNT2 = 0, COUNT3 = 0, COUNT4 = 0;
	int prevX = 2, prevY = 2;



	const int rows = 20;
	const int columns = 10;
	int Map[rows][columns];


	try
	{
		if (!rows && !columns) throw Exception(3); //z  -> Exception(3);
		
	}
	catch (Exception& e)
	{
		Text error = e.show();
		font2.loadFromFile("BLKCHCRY.TTF");
		error.setFont(font);
		error.setCharacterSize(70);
		error.setFillColor(Color::White);
		error.setPosition(100, 50);
		window.draw(error);
		return -1;
	}



	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			if (i == 0 || j == 0 || (j == columns - 1) || (i == rows - 1)) {
				Map[i][j] = 1;
			}
			else {
				Map[i][j] = 0;
			}
		}
	}

	int xm = 2, ym = 2;
	Monster object1(xm, ym);
	int xp = 5, yp = 2;
	Princess object2(xp, yp);
	//Exception(8); 

	try
	{
		if (xm == xp && ym == yp) throw Exception(8); //z  -> Exception(8);

	}
	catch (Exception& e)
	{
		Text error = e.show();
		font2.loadFromFile("BLKCHCRY.TTF");
		error.setFont(font);
		error.setCharacterSize(70);
		error.setFillColor(Color::White);
		error.setPosition(100, 50);
		window.draw(error);
		return -1;
	}


    //Map[object2.getX()][object2.getY()] = 2;
	//Map[object1.getX()][object1.getY()] = 3;
	
	
	/*-----------*/
	
	while(window.isOpen()){
		Event event;
		localPosition = Mouse::getPosition(window);		
		

		if (State == 0) {
			window.clear(Color(30, 30, 30, 0));
			window.draw(MainText1);
			window.draw(MainText3);
			window.draw(MainText2);

			MenuButton.showbutton("Play", &window, 1500, 500, 1630, 500, 0.f, 400.f, 100.f, 70, &localPosition, 1500, 1900, 500, 600);
			MenuButton.showbutton("Teaching", &window, 1500, 600, 1580, 600, 0.f, 400.f, 100.f, 70, &localPosition, 1500, 1900, 600, 700);
			MenuButton.showbutton("Results", &window, 1500, 700, 1590, 700, 0.f, 400.f, 100.f, 70, &localPosition, 1500, 1900, 700, 800);
			MenuButton.showbutton("Developers", &window, 1500, 800, 1540, 800, 0.f, 400.f, 100.f, 70, &localPosition, 1500, 1900, 800, 900);
			MenuButton.showbutton("Quit", &window, 1500, 900, 1630, 900, 0.f, 400.f, 100.f, 70, &localPosition, 1500, 1900, 900, 1000);
			
		}
		

		
		
		if(State == 1) {
			window.clear(Color(0, 0, 0, 0));
			time3 = clock3.getElapsedTime();

			try {
				if (time3.asSeconds() == 0) throw Exception(6);
			}
			catch (Exception& e)
			{
				e.show();

				return -1;
			}
			
			

			if (move == 0) {
				
				
				time1 = time3 - time4;

				try {
					if (time1.asSeconds() == 0) throw Exception(7);
				}
				catch (Exception& e)
				{
					e.show();

					return -1;
				}
			
				
				MyTime1.setString(std::to_string((int)time1.asSeconds()));
				MyTime1.setPosition(370, 50);
				window.draw(MyTime1);

				EndShape.setPointCount(4);
				EndShape.setPosition(50, 50);
				EndShape.setFillColor(Color(0, 0, 0, 0));
				EndShape.setOutlineColor(Color(255, 255, 255, 255));
				EndShape.setOutlineThickness(6.f);
				EndShape.setPoint(0, Vector2f(0.f, 0.f));
				EndShape.setPoint(1, Vector2f(440.f, 0.f));
				EndShape.setPoint(2, Vector2f(440.f, 110.f));
				EndShape.setPoint(3, Vector2f(0.f, 110.f));
				window.draw(EndShape);

				EndText.setFont(font2);
				EndText.setCharacterSize(70);
				EndText.setFillColor(Color::White);
				EndText.setPosition(100, 50);
				EndText.setString("Seconds: ");
				window.draw(EndText);





				int X = 565, Y = 145;
				int X2 = 0, Y2 = 0;

				
				for (int i = -2; i < 3; ++i) {
					X = 565;
					for (int j = -2; j < 3; ++j) {
						X2 = object1.getX() + j;
						Y2 = object1.getY() + i;

						try
						{
							if (X2 > rows ||  Y2 == columns) throw Exception(10); //z  -> Exception(10);

						}
						catch (Exception& e)
						{
							Text error = e.show();
							font2.loadFromFile("BLKCHCRY.TTF");
							error.setFont(font);
							error.setCharacterSize(70);
							error.setFillColor(Color::White);
							error.setPosition(100, 50);
							window.draw(error);
							return -1;
						}



						if (X2 >= 0 && X2 < rows && Y2 >= 0 && Y2 < columns) {
							if (Map[X2][Y2] == 0) {
								Floor.setPosition(X, Y);
								window.draw(Floor);
							}
							else if (Map[X2][Y2] == 1) {
								Wall.setPosition(X, Y);
								window.draw(Wall);
							}
							else if (Map[X2][Y2] == 2) {
								Floor.setPosition(X, Y);
								window.draw(Floor);
								PrincessSprite.setPosition(X, Y);
								//z  -> Exception(4);

								try
								{
									if (!X && !Y) throw Exception(4); //z								

								}
								catch (Exception& e)
								{
									Text error = e.show();
									font2.loadFromFile("BLKCHCRY.TTF");
									error.setFont(font);
									error.setCharacterSize(70);
									error.setFillColor(Color::White);
									error.setPosition(100, 50);
									window.draw(error);
									return -1;
								}






								window.draw(PrincessSprite);
								State = 2;
							}
							
						}
						

						
						X += 160;
					}
					Y += 160;
				}

				Floor.setPosition(885, 465);
				window.draw(Floor);

				X = 725, Y = 305;
				for (int i = -1; i < 2; ++i) {
					X = 725;
					for (int j = -1; j < 2; ++j) {
						X2 = object1.getX() + j;
						Y2 = object1.getY() + i;
						if (Map[X2][Y2] == 0 && (i != 0 || j != 0)) {
							C1.showall(X, Y, &localPosition, &window, X, X + 160, Y, Y + 160);
						}
						
						X += 160;
					}
					Y += 160;
				}
				
				

				



				
				MonsterSprite.setPosition(885, 465);
				window.draw(MonsterSprite);

				X = 885, Y = 465;
				MenuButton.showbutton("Help", &window, 1500, 900, 1630, 900, 0.f, 400.f, 100.f, 70, &localPosition, 1500, 1900, 900, 1000);
				if (S1.getActive() == 1) {
					if (S1.getReady() == 0) {
						if (object1.getX() > 3)
							X -= 160;
						if (object1.getX() < 3)
							X += 160;
						if (object1.getY() < 3)
							Y += 160;
						if (object1.getY() > 3)
							Y -= 160;
						S1.show(X, Y, &window);
					}
					else {
						




						if (COUNT1 != 0) {
							S1.show(X, Y + 160, &window);
						}
						else if (COUNT2 != 0) {
							S1.show(X + 160, Y, &window);
						}
						else if (COUNT3 != 0) {
							S1.show(X, Y - 160, &window);
						}
						else if (COUNT4 != 0) {
							S1.show(X - 160, Y, &window);
						}
						if (COUNT1 == 0 && COUNT2 == 0 && COUNT3 == 0 && COUNT4 == 0) {
							S1.setReady(0);
						}

					}



					
				}
				if (object1.getX() == 3 && object1.getY() == 3) {
					S1.setReady(1);
					COUNT1 = 3;
					COUNT2 = 13;
					COUNT3 = 3;
					COUNT4 = 13;
				}
				
				/*
				EndText.setFont(font2);
				EndText.setCharacterSize(70);
				EndText.setFillColor(Color::White);
				EndText.setPosition(200, 200);
				EndText.setString(std::to_string(object1.getY()));
				window.draw(EndText);
				
				EndText.setFont(font2);
				EndText.setCharacterSize(70);
				EndText.setFillColor(Color::White);
				EndText.setPosition(200, 400);
				EndText.setString(std::to_string(COUNT1));
				window.draw(EndText);
				*/

			}
			if (move == 1) {

				MyTime1.setString(std::to_string((int)time1.asSeconds()));
				MyTime1.setPosition(370, 50);
				window.draw(MyTime1);

				EndShape.setPointCount(4);
				EndShape.setPosition(50, 50);
				EndShape.setFillColor(Color(0, 0, 0, 0));
				EndShape.setOutlineColor(Color(255, 255, 255, 255));
				EndShape.setOutlineThickness(6.f);
				EndShape.setPoint(0, Vector2f(0.f, 0.f));
				EndShape.setPoint(1, Vector2f(440.f, 0.f));
				EndShape.setPoint(2, Vector2f(440.f, 110.f));
				EndShape.setPoint(3, Vector2f(0.f, 110.f));
				window.draw(EndShape);

				EndText.setFont(font2);
				EndText.setCharacterSize(70);
				EndText.setFillColor(Color::White);
				EndText.setPosition(100, 50);
				EndText.setString("Seconds: ");
				window.draw(EndText);

				
				time2 = clock2.getElapsedTime();
				//MyTime1.setString(std::to_string((int)time2.asSeconds()));
				//window.draw(MyTime1);

				EndShape.setPointCount(4);
				EndShape.setPosition(50, 1000);
				EndShape.setFillColor(Color(0, 0, 0, 0));
				EndShape.setOutlineColor(Color(255, 255, 255, 255));
				EndShape.setOutlineThickness(6.f);
				EndShape.setPoint(0, Vector2f(0.f, 0.f));
				EndShape.setPoint(1, Vector2f(440.f, 0.f));
				EndShape.setPoint(2, Vector2f(450.f, 30.f));
				EndShape.setPoint(3, Vector2f(10.f, 30.f));
				window.draw(EndShape);

				EndShape.setPosition(55, 1005);
				EndShape.setOutlineThickness(0.f);
				EndShape.setFillColor(Color(255, 255, 255, 255));
				EndShape.setPoint(0, Vector2f(0.f, 0.f));
				EndShape.setPoint(1, Vector2f(time2.asSeconds() * (-20.f) + 430, 0.f));
				EndShape.setPoint(2, Vector2f(time2.asSeconds() * (-20.f) + 437, 20.f));
				EndShape.setPoint(3, Vector2f(7.f, 20.f));
				window.draw(EndShape);
				if ((time2.asSeconds() * (-20.f)) + 430 <= 0) {
					State = 2;
				}

				int X = 565, Y = 145;
				int X2 = 0, Y2 = 0;


				for (int i = -2; i < 3; ++i) {
					X = 565;
					for (int j = -2; j < 3; ++j) {
						X2 = object2.getX() + j;
						Y2 = object2.getY() + i;

						try
						{
							if (X2 > rows || Y2 == columns) throw Exception(9); //z  -> Exception(9);

						}
						catch (Exception& e)
						{
							Text error = e.show();
							font2.loadFromFile("BLKCHCRY.TTF");
							error.setFont(font);
							error.setCharacterSize(70);
							error.setFillColor(Color::White);
							error.setPosition(100, 50);
							window.draw(error);
							return -1;
						}





						if (X2 >= 0 && X2 < rows && Y2 >= 0 && Y2 < columns) {
							if (Map[X2][Y2] == 0) {
								Floor.setPosition(X, Y);
								window.draw(Floor);
							}
							else if (Map[X2][Y2] == 1) {
								Wall.setPosition(X, Y);
								window.draw(Wall);
							}
							else if (Map[X2][Y2] == 3) {
								Floor.setPosition(X, Y);
								window.draw(Floor);
								MonsterSprite.setPosition(X, Y);
								window.draw(MonsterSprite);
								State = 2;
							}

						}


						X += 160;
					}
					Y += 160;
				}
				Floor.setPosition(885, 465);
				window.draw(Floor);

				X = 725, Y = 305;
				for (int i = -1; i < 2; ++i) {
					X = 725;
					for (int j = -1; j < 2; ++j) {
						X2 = object2.getX() + j;
						Y2 = object2.getY() + i;
						if (Map[X2][Y2] == 0 || Map[X2][Y2] == 2) {
							C1.showall(X, Y, &localPosition, &window, X, X + 160, Y, Y + 160);
						}

						X += 160;
					}
					Y += 160;
				}


				
				PrincessSprite.setPosition(885, 465);
				window.draw(PrincessSprite);
			}
		}

		if (State == 2) {
			window.clear(Color(30, 30, 30, 0));

			int X = 565, Y = 145;
			int X2 = 0, Y2 = 0;


			for (int i = -2; i < 3; ++i) {
				X = 565;
				for (int j = -2; j < 3; ++j) {
					X2 = object1.getX() + j;
					Y2 = object1.getY() + i;
					if (X2 >= 0 && X2 < rows && Y2 >= 0 && Y2 < columns) {
						if (Map[X2][Y2] == 0) {
							Floor.setPosition(X, Y);
							window.draw(Floor);
						}
						else if (Map[X2][Y2] == 1) {
							Wall.setPosition(X, Y);
							window.draw(Wall);
						}
						else if (Map[X2][Y2] == 2) {
							Floor.setPosition(X, Y);
							window.draw(Floor);
							PrincessSprite.setPosition(X, Y);
							window.draw(PrincessSprite);
							
						}

					}



					X += 160;
				}
				Y += 160;
			}

			Floor.setPosition(885, 465);
			window.draw(Floor);

			MonsterSprite.setPosition(885, 465);
			window.draw(MonsterSprite);

			


			EndShape.setPointCount(4);
			EndShape.setPosition(0, 0);
			EndShape.setFillColor(Color(0, 0, 0, 200));
			EndShape.setPoint(0, Vector2f(0.f, 0.f));
			EndShape.setPoint(1, Vector2f(1920.f, 0.f));
			EndShape.setPoint(2, Vector2f(1920.f, 1080.f));
			EndShape.setPoint(3, Vector2f(0.f, 1080.f));
			window.draw(EndShape);


			/*EndShape.setPointCount(4);
			EndShape.setPosition(770, 450);
			EndShape.setFillColor(Color(0, 0, 0, 0));
			EndShape.setOutlineColor(Color(255, 255, 255, 255));
			EndShape.setOutlineThickness(6.f);
			EndShape.setPoint(0, Vector2f(0.f, 0.f));
			EndShape.setPoint(1, Vector2f(430.f, 0.f));
			EndShape.setPoint(2, Vector2f(430.f, 140.f));
			EndShape.setPoint(3, Vector2f(0.f, 140.f));
			window.draw(EndShape);*/
			EndText.setFont(font2);
			EndText.setCharacterSize(90);
			EndText.setFillColor(Color::White);
			EndText.setPosition(800, 300);
			EndText.setString("Your Time:");
			window.draw(EndText);

			MyTime1.setString(std::to_string((int)time1.asSeconds()));
			MyTime1.setPosition(1210, 310);
			window.draw(MyTime1);

			EndText.setFont(font2);
			EndText.setCharacterSize(90);
			EndText.setFillColor(Color::White);
			EndText.setPosition(800, 500);
			EndText.setString("Your Nick:");
			window.draw(EndText);

			nameText.setFont(font2);
			nameText.setCharacterSize(70);
			nameText.setFillColor(Color::White);
			nameText.setPosition(1210, 510);
			window.draw(nameText);
			saveTime = true;
			


			MenuButton.showbutton("Back", &window, 100, 900, 170, 900, 0.f, 300.f, 100.f, 70, &localPosition, 100, 400, 900, 1000);

			S1.setActive(0);
			S1.setReady(0);
		}
		if (State == 4) {
			EndShape.setPointCount(4);
			EndShape.setPosition(0, 0);
			EndShape.setFillColor(Color(0, 0, 0, 200));
			EndShape.setPoint(0, Vector2f(0.f, 0.f));
			EndShape.setPoint(1, Vector2f(1920.f, 0.f));
			EndShape.setPoint(2, Vector2f(1920.f, 1080.f));
			EndShape.setPoint(3, Vector2f(0.f, 1080.f));
			window.draw(EndShape);

			if (readResult == true) {
				for (scoresIterator = scores.begin(); scoresIterator != scores.end();)
				{
					delete(*(scoresIterator));
					scoresIterator = scores.erase(scoresIterator);
				}
				readResult = false;
				std::ifstream result;
				result.open("Time6.csv"); //Exception(2)


				try
				{
					if (!result) throw Exception(2);	

				}
				catch (Exception& e)
				{
					Text error = e.show();
					font2.loadFromFile("BLKCHCRY.TTF");
					error.setFont(font);
					error.setCharacterSize(70);
					error.setFillColor(Color::White);
					error.setPosition(100, 50);
					window.draw(error);
					return -1;
				}

				std::string readedName;
				std::string readedPoints;
				int c = 0;
				while (std::getline(result, readedName,';') && std::getline(result, readedPoints,'\n')) {
					c++;
					if (scores.begin() == scores.end()) {
						scores.push_back(new Score(readedName, std::stoi(readedPoints)));
					}
					else {
						for (scoresIterator = scores.begin(); scoresIterator != scores.end(); ) {
							if ((*scoresIterator)->pPoints > std::stoi(readedPoints))
							{
								scoresIterator++;
							}
							else {
								scores.insert(scoresIterator, new Score(readedName, std::stoi(readedPoints)));
								break;
							}
						}
					}
				}
			}
			
			int i = 0;
			Vector2f listStartPosition;
			int listStep = 100;
			for (scoresIterator = scores.begin(); scoresIterator != scores.end(); scoresIterator++) {
				if (i < 4) {
					i++;
					Text nText("", font2, 50);
					nText.setFillColor(Color::White);
					std::ostringstream playerNameString;
					playerNameString << i << ". " + (*scoresIterator)->pName;
					nText.setString(playerNameString.str());
					nText.setPosition(800,20 + (listStep*i));
					window.draw(nText);
					Text pText("", font2, 50);
					pText.setFillColor(Color::White);
					std::ostringstream playerPointsString;
					playerPointsString << (*scoresIterator)->pPoints;
					pText.setString(playerPointsString.str());
					pText.setPosition(1210, 20 + (listStep*i));
					window.draw(pText);
				}
				else { break; }
			}
			MenuButton.showbutton("Back", &window, 100, 900, 170, 900, 0.f, 300.f, 100.f, 70, &localPosition, 100, 400, 900, 1000);
		}

		if (State == 3) {
			time2 = clock2.getElapsedTime();

			
			
			EndShape.setPointCount(4);
			EndShape.setPosition(0, 0);
			EndShape.setFillColor(Color(0, 0, 0, 200));
			EndShape.setPoint(0, Vector2f(0.f, 0.f));
			EndShape.setPoint(1, Vector2f(1920.f, 0.f));
			EndShape.setPoint(2, Vector2f(1920.f, 1080.f));
			EndShape.setPoint(3, Vector2f(0.f, 1080.f));
			window.draw(EndShape);


			EndShape.setPointCount(4);
			EndShape.setPosition(770, 450);
			EndShape.setFillColor(Color(0, 0, 0, 0));
			EndShape.setOutlineColor(Color(255, 255, 255, 255));
			EndShape.setOutlineThickness(6.f);
			EndShape.setPoint(0, Vector2f(0.f, 0.f));
			EndShape.setPoint(1, Vector2f(430.f, 0.f));
			EndShape.setPoint(2, Vector2f(430.f, 150.f));
			EndShape.setPoint(3, Vector2f(0.f, 150.f));
			window.draw(EndShape);

			EndText.setFont(font2);

			EndText.setCharacterSize(100);
			EndText.setFillColor(Color::White);
			EndText.setPosition(800, 450);
			EndText.setString("Ready ?");
			window.draw(EndText);

			if (move == 0) {
				MonsterFace.setPosition(1250, 450);
				window.draw(MonsterFace);
			}
			else {
				PrincessFace.setPosition(1250, 450);
				window.draw(PrincessFace);
			}
			


			MenuButton.showbutton("Yes", &window, 770, 900, 930, 900, 0.f, 430.f, 100.f, 70, &localPosition, 770, 1200, 900, 1000);
		}
		if (State == 5) {
			EndShape.setPointCount(4);
			EndShape.setPosition(0, 0);
			EndShape.setFillColor(Color(0, 0, 0, 200));
			EndShape.setPoint(0, Vector2f(0.f, 0.f));
			EndShape.setPoint(1, Vector2f(1920.f, 0.f));
			EndShape.setPoint(2, Vector2f(1920.f, 1080.f));
			EndShape.setPoint(3, Vector2f(0.f, 1080.f));
			window.draw(EndShape);
			Text developers, developers2, developers3, developers4;
			developers.setFont(font2);
			developers.setCharacterSize(40);
			developers.setPosition(670, 250);
			developers.setString("Developer Yozhikov Anatoly - work with data");
			developers.setFillColor(Color::White);
			window.draw(developers);
			developers2.setFont(font2);
			developers2.setCharacterSize(40);
			developers2.setPosition(670, 350);
			developers2.setString("Developer Yaroslav Kolokol - work on algorithms and interface");
			developers2.setFillColor(Color::White);
			window.draw(developers2);
			developers4.setFont(font2);
			developers4.setCharacterSize(40);
			developers4.setPosition(670, 450);
			developers4.setString("Developer Chernihivtsev Mikhail - work with exceptions");
			developers4.setFillColor(Color::White);
			window.draw(developers4);
			MenuButton.showbutton("Back", &window, 100, 900, 170, 900, 0.f, 300.f, 100.f, 70, &localPosition, 100, 400, 900, 1000);

		}
		if (State == 6) {
			EndShape.setPointCount(4);
			EndShape.setPosition(0, 0);
			EndShape.setFillColor(Color(0, 0, 0, 200));
			EndShape.setPoint(0, Vector2f(0.f, 0.f));
			EndShape.setPoint(1, Vector2f(1920.f, 0.f));
			EndShape.setPoint(2, Vector2f(1920.f, 1080.f));
			EndShape.setPoint(3, Vector2f(0.f, 1080.f));
			window.draw(EndShape);
			Text text;
			text.setFont(font2);
			text.setCharacterSize(35);
			text.setPosition(450, 35);
			text.setString("Game theory is a branch of mathematical economics that studies the resolution \nof conflicts between players and the optimality of their strategies.\nConflict can affect various areas of human interest: most often economics, \nsociology, political science, and often biology, cybernetics, and even military \naffairs.\n\n\nRules \nWe have two players: a monster and a princess. \nEach of them will appear in turn, ie the monster appears first, it makes its \nmove either to the left or to the right, neither up nor down. \nAs soon as the monster did its course, it disappears and the princess appears. \nThe princess moves left or right, or up or down. The main task of the monster \nis to find the princess as soon as possible, and the task of the princess is not \nto get on the monster. \nThe monster will also have its own timer, for which it finds time for the \nprincess.");
			text.setFillColor(Color::White);
			window.draw(text);
			MenuButton.showbutton("Back", &window, 100, 900, 170, 900, 0.f, 300.f, 100.f, 70, &localPosition, 100, 400, 900, 1000);
		}



		while(window.pollEvent(event)) {
			if (event.type == Event::MouseButtonPressed && localPosition.x > 1500 && localPosition.x < 1900 && localPosition.y > 900 && localPosition.y < 1000 && State == 0)
			{
				if (event.mouseButton.button == Mouse::Left)
				{
					window.close();
				}
			}
			if (event.type == Event::MouseButtonPressed && localPosition.x > 1500 && localPosition.x < 1900 && localPosition.y > 700 && localPosition.y < 800 && State == 0)
			{
				if (event.mouseButton.button == Mouse::Left)
				{
					State = 4;
					if (readResult == false) {
						readResult = true;
					}
				}
			}

			if (event.type == Event::MouseButtonPressed && localPosition.x > 1500 && localPosition.x < 1900 && localPosition.y > 900 && localPosition.y < 1000 && State == 1 && move == 0)
			{
				if (event.mouseButton.button == Mouse::Left)
				{
					if (S1.getActive() == 0) {
						S1.setActive(1);
					}
					else {
						S1.setActive(0);
					}
					
				}
			}

			if (event.type == Event::TextEntered && State == 2) {
				if (event.text.unicode < 128)
					name += static_cast<char>(event.text.unicode);
				nameText.setString(name);
			}
			if (event.type == Event::MouseButtonPressed && localPosition.x > 1500 && localPosition.x < 1900 && localPosition.y > 800 && localPosition.y < 900) {
				if (event.mouseButton.button == Mouse::Left) {
					State = 5;
				}
			}
			if (event.type == Event::MouseButtonPressed && localPosition.x > 1500 && localPosition.x < 1900 && localPosition.y > 600 && localPosition.y < 700) {
				if (event.mouseButton.button == Mouse::Left) {
					if (event.mouseButton.button == Mouse::Left) {
						State = 6;

					}
				}
			}
			if (event.type == Event::MouseButtonPressed && localPosition.x > 100 && localPosition.x < 400 && localPosition.y > 900 && localPosition.y < 1000 && State == 4) {
				if (event.mouseButton.button == Mouse::Left) {
					State = 0;
				}
			}
			if (event.type == Event::MouseButtonPressed && localPosition.x > 100 && localPosition.x < 400 && localPosition.y > 900 && localPosition.y < 1000 && State == 5) {
				if (event.mouseButton.button == Mouse::Left) {
					State = 0;
				}
			}
			if (event.type == Event::MouseButtonPressed && localPosition.x > 100 && localPosition.x < 400 && localPosition.y > 900 && localPosition.y < 1000 && State == 6) {
				if (event.mouseButton.button == Mouse::Left) {
					State = 0;
				}
			}
			if (event.type == Event::MouseButtonPressed && localPosition.x > 1500 && localPosition.x < 1900 && localPosition.y > 500 && localPosition.y < 600 && State == 0)
			{
				if (event.mouseButton.button == Mouse::Left)
				{
					State = 3;
					time3 = clock3.restart();
					time2 = clock2.restart();
					time4 = seconds(0);
					move = 0;

					//object1.setX((rand() % 9) + 1);
					//object1.setY((rand() % 19) + 1);

					//object2.setX((rand() % 9) + 1);
					//object2.setY((rand() % 19) + 1);

					object1.setX(2);
					object1.setY(2);

					object2.setX(5);
					object2.setY(2);

					//std::cout <<"Monster "<< abs(obj->getX() - obj2->getX() << std::endl;
					//std::cout << object1.getY() << std::endl;
					//std::cout << "Princess " << object2.getX() << std::endl;
					//std::cout << object2.getY() << std::endl;

					Map[object2.getX()][object2.getY()] = 2;
					Map[object1.getX()][object1.getY()] = 3;
					
				}
			}


			/*The Game*/
			/*--------------------------------*/

			if (event.type == Event::MouseButtonPressed && localPosition.x > 100 && localPosition.x < 400 && localPosition.y > 900 && localPosition.y < 1000 && State == 2)
			{
				if (event.mouseButton.button == Mouse::Left)
				{
					if (saveTime) {
						saveTime = false;
						std::ofstream myFile;
						myFile.open("Time6.csv", std::ios_base::app);
						myFile << name << "," << (int)time1.asSeconds() << std::endl;
						name = "";
						nameText.setString("");
						myFile.close();
					}
					State = 0;

					Map[object1.getX()][object1.getY()] = 0;
					Map[object2.getX()][object2.getY()] = 0;
				}
			}
			if (event.type == Event::MouseButtonPressed && localPosition.x > 770 && localPosition.x < 1200 && localPosition.y > 900 && localPosition.y < 1000 && State == 3)
			{
				if (event.mouseButton.button == Mouse::Left)
				{
					State = 1;
					time4 += time2;
					time2 = clock2.restart();
					
				}
			}

			int X, Y, X2, Y2;
			
			
			if (State == 1) {
				
				if (move == 0) {
					X = 725, Y = 305;
					for (int i = -1; i < 2; ++i) {
						X = 725;
						for (int j = -1; j < 2; ++j) {
							X2 = object1.getX() + j;
							Y2 = object1.getY() + i;
							if (Map[X2][Y2] == 0 && (i != 0 || j != 0)) {
								C1.Move(X2, Y2, &localPosition, &window, &event, &object1, X, Y, &move, &Map[X2][Y2], &Map[object1.getX()][object1.getY()], &time4, &time2, &clock2, &State, object2.getX(), object2.getY(), &S1, &COUNT1, &COUNT2, &COUNT3, &COUNT4);
								
								
								

							}


							X += 160;
						}
						Y += 160;
					}



				}
				else {
					X = 725, Y = 305;
					for (int i = -1; i < 2; ++i) {
						X = 725;
						for (int j = -1; j < 2; ++j) {
							X2 = object2.getX() + j;
							Y2 = object2.getY() + i;
							if (Map[X2][Y2] == 0 || Map[X2][Y2] == 2) {
								C1.Move(X2, Y2, &localPosition, &window, &event, &object2, X, Y, &move, &Map[X2][Y2], &Map[object2.getX()][object2.getY()], &time4, &time2, &clock2, &State, object1.getX(), object1.getY(), &S1, &COUNT1, &COUNT2, &COUNT3, &COUNT4);

							}

							X += 160;
						}
						Y += 160;
					}
				}
			}
			
			

			

			/*--------------------------------*/
		}

		

		
		window.display();
	}


	return 0;
}