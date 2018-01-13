#include "stdafx.h"
#include "Animal.h"

Rabbit::Rabbit()
{
	age = 0;
	std::mt19937 gen(std::time(0));
	std::uniform_int_distribution<int> initrab(4,8);//инициатива кролика
	std::uniform_int_distribution<int> f_coord();
	initiative = initrab(gen);
	satiety = 100;
}

int Rabbit::getSatiety()
{
	return satiety;
}

void Rabbit::setSatiety(int my_satiety)
{
	satiety = my_satiety;
}

void Rabbit::nextAction()
{
}

int Rabbit::getInitiative()
{
	return initiative;
}

void Rabbit::setInitiative(int my_initiative)
{
	initiative = my_initiative;
}

int Rabbit::getAge()
{
	return age;
}
/*
int Rabbit::getTitlePosition()
{
	return title_position;
}

void Rabbit::setTitlePosition(int i)
{
	title_position = i;
}
*/
void Rabbit::doEat(int eat)
{
	satiety += eat;
}


void Rabbit::doStep(int width, int hight)
{
	std::mt19937 gen(std::time(0));
	std::uniform_int_distribution<int> step(1, 9);//пока-что кролики двигаютс€ рандомно - они лишь куски м€са
	std::pair <int, int> new_coordinates = rabbit_coordinates;//хуЄва€ иде€, правда лучше ничего не придумал, кролики 
	//пытаютс€ сделать какой-то шаг, если выходит из граничных условий то сто€т на месте
	
	switch (step(gen))
	{
			case 1: {
				new_coordinates.first -= 1;
				new_coordinates.second -= 1;
				break;
			};
			case 2: {
				new_coordinates.first -= 1;
				new_coordinates.second ;
				break; 
			};
			case 3: {
				new_coordinates.first -= 1;
				new_coordinates.second += 1;
				break;
			};
			case 4: {
				new_coordinates.first ;
				new_coordinates.second -= 1;
				break;
			};
			case 5: {
				new_coordinates.first;
				new_coordinates.second;
				break;
			};
			case 6: {
				new_coordinates.first ;
				new_coordinates.second += 1;
				break;
			};
			case 7: {
				new_coordinates.first += 1;
				new_coordinates.second -= 1;
				break;
			};
			case 8: {
				new_coordinates.first += 1;
				new_coordinates.second;
				break;
			};
			case 9: {
				new_coordinates.first += 1;
				new_coordinates.second += 1;
				break;
			};
			default: std::cout << "кака€-то хуйн€";
	}
	if ((new_coordinates.first > width-1 || new_coordinates.first < 0)
		|| (new_coordinates.second > hight-1 || new_coordinates.second < 0))
	{
		setPosition(rabbit_coordinates);
	}
	else
		setPosition(new_coordinates);
}

std::pair<int, int> Rabbit::getPosition()
{
	return rabbit_coordinates;
}

void Rabbit::setPosition(std::pair<int, int> my_position)
{
	rabbit_coordinates = my_position;
}

void Rabbit::incAge()
{
	age++;
}

std::shared_ptr<Rabbit> Rabbit::doLove(std::pair <int, int> coord)
{
	//Rabbit new_rabbit;
	auto new_rabbit = std::make_shared<Rabbit>();
	new_rabbit->age = 0;
	std::mt19937 gen(std::time(0));
	std::uniform_int_distribution<int> initrab(4, 8);//инициатива кролика
	initiative = initrab(gen);
	new_rabbit->setPosition(coord);
	satiety = 80;
	return new_rabbit;
}

Rabbit::~Rabbit()
{
}
