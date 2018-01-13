#include "stdafx.h"
#include "EcosystemHeaders.h"
#pragma once


class mapTitle {
public:
	//int number_entites;
	std::list<char> title_image;//Òàéòë ñîäåðæèò ñòýê èçîáðàæåíèé, è ïîêàçûâàåò íàì âåðõíåå
	bool have_grace;
	std::shared_ptr<Grace> p_grace;
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
		void doActions(int&);
		void sortImages();
		TMap getMap();
		~island();

	private:
		TMap map;
		const int width = 2;
		const int hight = 2;
		const int square_fertile_soil = width*hight;
		std::vector<Grace> graces;
		std::vector<Rabbit> rabbits;
};

