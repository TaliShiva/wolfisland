#include "stdafx.h"
#include "EcosystemHeaders.h"
#pragma once


class mapTitle {
public:
	//int number_entites;
	std::list<char> title_image;//Тайтл содержит стэк изображений, и показывает нам верхнее
	bool have_grace;
};

typedef std::vector<std::vector <mapTitle>> TMap;

class island
{
	public:
		island();
		int getWidth();
		int getHight();
		void setMap(TMap);
		void drawMap();
		void changeMap();
		void createMap();
		void createFlora();
		void createFauna();
		void doActions();
		void sortImages();
		TMap getMap();
		~island();

	private:
		TMap map;
		const int width = 6;
		const int hight = 5;
		const int square_fertile_soil = width*hight;
		std::vector<Grace> graces;
		std::vector<Rabbit> rabbits;
};

