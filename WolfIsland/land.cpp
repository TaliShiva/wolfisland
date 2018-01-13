#include "stdafx.h"
#include "land.h"

island::island()
{
	//std::vector<std::vector<char>> map;
	createMap();//������ ����� �����, ������-�� �������
	createFlora();//��������� ��������������
	createFauna();//���������� ��������
	drawMap();
	//changeMap();//������� ��� ��������� ��� ���������
}

void island::createMap()
{
	for (auto i = 0; i < width; i++) {
		std::vector<mapTitle> raw;
		for (auto j = 0; j < hight; j++) {
			mapTitle mt;
			mt.title_image.push_back('o');//������ ��������� ����� �����
			raw.push_back(mt);
		}
		map.push_back(raw);
	}
	//� ������� ����� �������� ������ ������ � �����, ������� ���� ����� �� ����� ������
}

void island::changeMap()
{
	//setMap(map);
}


void island::createFlora()
{
	std::mt19937 gen(std::time(0));
	std::uniform_int_distribution<int> uid1(0, width-1);//�������� ��� ������ ������ �����
	std::uniform_int_distribution<int> uid2(0, hight-1);//�������� ��� ����� ������ �����
	std::uniform_int_distribution<int> uid3(60, 140);//�������� �������������� �������� ��������� �����
	int quantity_grace = int(square_fertile_soil);//����-��� ��������, ����� ���������� ������������ �����
	//������� ������������ ��������� �� ������ ���������� ������, �������� ����� � ��������� �� ������� �������
	std::pair<int, int> coordinates;
	for (auto i = 0; i <= quantity_grace; ++i) {
		coordinates.first = uid1(gen);
		coordinates.second = uid2(gen);
		if (map[coordinates.first][coordinates.second].have_grace != true) {//���� ��� ����� � ���� ������, ��:
			int energy = uid3(gen);
			//Grace grace;
			//std::shared_ptr<Grace> grace(new Grace);//�������-�� ������� �� ����� ����������
			auto grace = std::make_shared<Grace>();
			grace->setEnergy(energy);
			grace->setCoordinates(coordinates);
			//graces.push_back(&grace);//� ��� ���� ��������� ��� �������� ������� �����, ���� � ������� ���� �����
			map[coordinates.first][coordinates.second].have_grace = true; //������ ��� ���� �����
			map[coordinates.first][coordinates.second].title_image.push_back('g'); //���������� ������ ������ g 
			//map[coordinates.first][coordinates.second].p_grace(std::make_shared<Grace>(grace));
			map[coordinates.first][coordinates.second].p_grace=grace;
		}
	}
}

void island::createFauna()
{
	std::mt19937 gen(std::time(0));
	std::uniform_int_distribution<int> x(0, width - 1);//�������� ��� ������ ������ ������
	std::uniform_int_distribution<int> y(0, hight - 1);//�������� ��� ����� ������ ������
	std::pair<int, int> r_position;
	r_position.first = x(gen);
	r_position.second = y(gen);
	int rabbit_quantity = 2;//������������ �������� ������ ���� - ���������� ������
	for (int i = 0; i < rabbit_quantity; i++) {
		Rabbit rabbit;//������� �������
		rabbit.setPosition(r_position);//���������� ��� ��������� ���������
		map[rabbit.getPosition().first][rabbit.getPosition().second].title_image.push_back('r');
		//rabbit.setTitlePosition(map[rabbit.getPosition().first][rabbit.getPosition().second].title_image.size());//����������
		//�� ����� ������ ��������� ����������� �������
		rabbits.push_back(rabbit);//��������� ������� � ��������� ��������
	}
}

void island::doActions(int &rabbit_birth_counter)
{
	//���� ������������ ��������
	for (int i = 0; i < rabbits.size(); i++) {
		auto x = rabbits[i].getPosition().first;
		auto y = rabbits[i].getPosition().second;
		//auto cock = rabbits[i].getTitlePosition();
		map[x][y].title_image.remove('r');
		Sleep(250);
		rabbits[i].doStep(width, hight);
		auto x2 = rabbits[i].getPosition().first;
		auto y2 = rabbits[i].getPosition().second;
		map[x2][y2].title_image.push_back('r');
		//drawMap();
	}

	int rcount = rabbits.size();//���-�� �������� �� ������ ���������
	//���� �������
	for (int i = 0; i < rcount; i++) {
		int x = rabbits[i].getPosition().first;
		int y = rabbits[i].getPosition().second;
		if (map[x][y].have_grace) {
			int cur_energy = map[x][y].p_grace->getEnergy();
			if (cur_energy > 20) {
				rabbits[i].doEat(20);
				map[x][y].p_grace->setEnergy(cur_energy - 20);
			}
			else {
				rabbits[i].doEat(cur_energy);
				map[x][y].p_grace->setEnergy(0);
			}
		}
		else {
			rabbits[i].doEat(-20);
		}
	}

	//���� �������� ���������� � ������� ������������
	for (auto i = 0; i < width; i++)
	{
		for (auto j = 0; j < hight; j++)
		{
			if (map[i][j].have_grace == true) {
				if (map[i][j].p_grace->getEnergy() == 0) {
					map[i][j].p_grace.reset();
					map[i][j].have_grace = false;
					map[i][j].title_image.remove('g');
				}
			}
		}
	}

	//���� ����������� 
	/*
	if (rabbit_birth_counter == 10) {
		for (int i = 0; i < rcount; i++) {
			rabbits.push_back(rabbits[i].doLove(rabbits[i].getPosition()));
		}
		rabbit_birth_counter = 0;
	}
	*/
	//� ���������� ����� ����� �������� ���������� �������� ������

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
