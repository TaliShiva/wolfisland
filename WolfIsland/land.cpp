#include "stdafx.h"
#include "land.h"

island::island()
{
	//std::vector<std::vector<char>> map;
	createMap();//создаём голую землю, такого-то размера
	createFlora();//порождаем растительность
	createFauna();//порождение животных
	drawMap();
	//changeMap();//функция для изменений при действиях
}

void island::createMap()
{
	for (auto i = 0; i < width; i++) {
		std::vector<mapTitle> raw;
		for (auto j = 0; j < hight; j++) {
			mapTitle mt;
			mt.title_image.push_back('o');//тайтлы заполнены голой землёй
			raw.push_back(mt);
		}
		map.push_back(raw);
	}
	//в конечно счёте получили остров ширины и длины, которые были взяты из полей класса
}

void island::changeMap()
{
	//setMap(map);
}


void island::createFlora()
{
	std::mt19937 gen(std::time(0));
	std::uniform_int_distribution<int> uid1(0, width-1);//диапазон для ширины справна травы
	std::uniform_int_distribution<int> uid2(0, hight-1);//диапазон для длины справна травы
	std::uniform_int_distribution<int> uid3(60, 140);//диапазон энергетической ценности отдельной травы
	int quantity_grace = int(square_fertile_soil);//пока-что заглушка, потом количество генерируемой травы
	//сделаем передаваемым значением из панели управления картой, значение будет в процентах от площади острова
	std::pair<int, int> coordinates;
	for (auto i = 0; i <= quantity_grace; ++i) {
		coordinates.first = uid1(gen);
		coordinates.second = uid2(gen);
		if (map[coordinates.first][coordinates.second].have_grace != true) {//если нет травы в этом татйле, то:
			int energy = uid3(gen);
			Grace grace;
			grace.setEnergy(energy);
			grace.setCoordinates(coordinates);
			graces.push_back(grace);//у нас есть контейнер для хранения объетов травы, куда и заносим этот объёт
			map[coordinates.first][coordinates.second].have_grace = true; //теперь тут есть трава
			map[coordinates.first][coordinates.second].title_image.push_back('g');
		}
	}
}

void island::createFauna()
{
	std::mt19937 gen(std::time(0));
	std::uniform_int_distribution<int> x(0, width - 1);//диапазон для ширины справна травы
	std::uniform_int_distribution<int> y(0, hight - 1);//диапазон для длины справна травы
	std::pair<int, int> r_position;
	r_position.first = x(gen);
	r_position.second = y(gen);
	int rabbit_quantity = 3;//передаваемое значение должно быть - количество кролей
	for (int i = 0; i < rabbit_quantity; i++) {
		Rabbit rabbit;//создали кролика
		rabbit.setPosition(r_position);//установили его начальное положение
		map[rabbit.getPosition().first][rabbit.getPosition().second].title_image.push_back('r');
		//rabbit.setTitlePosition(map[rabbit.getPosition().first][rabbit.getPosition().second].title_image.size());//запоминаем
		//на какой высоте находится изображение кролика
		rabbits.push_back(rabbit);//поместили кролика в контейнер кроликов
	}
}

void island::doActions()
{
	//фаза передвижений кроликов
	for (int i = 0; i < rabbits.size(); i++) {
		auto x = rabbits[i].getPosition().first;
		auto y = rabbits[i].getPosition().second;
		//auto cock = rabbits[i].getTitlePosition();
		map[x][y].title_image.remove('r');
		Sleep(500);
		rabbits[i].doStep(width, hight);
		auto x2 = rabbits[i].getPosition().first;
		auto y2 = rabbits[i].getPosition().second;
		map[x2][y2].title_image.push_back('r');
		//drawMap();
	}

	//фаза питания
	for (int i = 0; i < rabbits.size(); i++) {
		rabbits[i].doEat();
	}


}

void island::sortImages()
{
	for (auto i = 0; i < width; i++)
	{
		for (auto j = 0; j < hight; j++)
		{
		
		}
	}
}


 int island::getWidth()
{
	return width;
}

 int island::getHight()
{
	return hight;
}

 TMap island::getMap()
 {
	 return map;
 }

 void island::setMap(TMap new_map)
 {
	 map = new_map;
 }

 void island::drawMap()
 {
	 system("cls");
	 for (auto i = 0; i < width; i++) {
		 for (auto j = 0; j < hight; j++)
		 {
			// system("color 02");
			//std::cout << map[i][j].title_image.size();
			std::cout << map[i][j].title_image.back() << " ";
		 }
		 std::cout << std::endl;
	 }
 }


island::~island()
{
}
