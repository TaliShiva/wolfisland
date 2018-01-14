#include "stdafx.h"
#include "Animal.h"

Rabbit::Rabbit()
{
	age = 0;

	//пока-что закомментировано
	//std::mt19937 gen(std::time(0));
	//std::uniform_int_distribution<int> initrab(4,8);//инициатива кролика
	//std::uniform_int_distribution<int> f_coord();
	//initiative = initrab(gen);
	satiety = 100;
}

int Rabbit::getSatiety()
{
	return satiety;
}

void Rabbit::setSatiety(int my_satiety)
{
	satiety += my_satiety;
}
/*
void Rabbit::nextAction()
{
}
*/
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

void Rabbit::doEat(int eat)
{
	satiety += eat;
}

void Rabbit::doStep(int width, int hight)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> step(1, 9);//пока-что кролики двигаются рандомно - они лишь куски мяса
	std::pair <int, int> new_coordinates = rabbit_coordinates;//хуёвая идея, правда лучше ничего не придумал, кролики 
	//пытаются сделать какой-то шаг, если выходит из граничных условий то стоят на месте
	
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
			default: std::cout << "какая-то хуйня";
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
	/*std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> initrab(4, 8);//инициатива кролика
	initiative = initrab(gen);*/
	new_rabbit->setPosition(coord);
	satiety = 80;
	return new_rabbit;
}

Rabbit::~Rabbit()
{
}




Wolf::Wolf()
{
	age = 0;
	satiety = 300;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> step(0, 1);
	sex = bool(step(gen));
}

int Wolf::getSatiety()
{
	return satiety;
}

void Wolf::setSatiety(int new_satiety)
{
	satiety = new_satiety;
}

int Wolf::getInitiative()
{
	return initiative;
}

void Wolf::setInitiative(int new_initiative)
{
	initiative = new_initiative;
}

int Wolf::getAge()
{
	return age;
}

void Wolf::doEat(int new_satiety)
{
	satiety += new_satiety;
}

void Wolf::doStep(int width, int hight)
{
	//реализация движения, пока-что тупая копипаста
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> step(1, 9);//пока-что кролики двигаются рандомно - они лишь куски мяса
	std::pair <int, int> new_coordinates = wolf_coordinates;//хуёвая идея, правда лучше ничего не придумал, кролики 
															  //пытаются сделать какой-то шаг, если выходит из граничных условий то стоят на месте
	switch (step(gen))
	{
	case 1: {
		new_coordinates.first -= 1;
		new_coordinates.second -= 1;
		break;
	};
	case 2: {
		new_coordinates.first -= 1;
		new_coordinates.second;
		break;
	};
	case 3: {
		new_coordinates.first -= 1;
		new_coordinates.second += 1;
		break;
	};
	case 4: {
		new_coordinates.first;
		new_coordinates.second -= 1;
		break;
	};
	case 5: {
		new_coordinates.first;
		new_coordinates.second;
		break;
	};
	case 6: {
		new_coordinates.first;
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
	default: std::cout << "какая-то хуйня";
	}
	if ((new_coordinates.first > width - 1 || new_coordinates.first < 0)
		|| (new_coordinates.second > hight - 1 || new_coordinates.second < 0))
	{
		setPosition(wolf_coordinates);
	}
	else
		setPosition(new_coordinates);
}

std::pair<int, int> Wolf::getPosition()
{
	return wolf_coordinates;
}

void Wolf::setPosition(std::pair<int, int> new_wolf_coordinates)
{
	wolf_coordinates = new_wolf_coordinates;
}

void Wolf::incAge()
{
	age++;
}

std::shared_ptr<Wolf> Wolf::doLove(std::pair<int, int> coord)
{
	auto new_wolf = std::make_shared<Wolf>();
	new_wolf->age = 0;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> gen_sex(0, 1);//пол волика
	sex = gen_sex(gen);
	new_wolf->setPosition(coord);
	satiety = 200;
	return new_wolf;
}

bool Wolf::getSex()
{
	return sex;
}

void Wolf::setSex(bool new_sex)
{
	sex = new_sex;
}

Wolf::~Wolf()
{
}
