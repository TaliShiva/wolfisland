#include "stdafx.h"
#include "land.h"

island::island()
{

	createMap();//создаём голую землю, такого-то размера
	createFlora();//порождаем растительность
	createFauna(40, 8);//порождение животных
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
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> uid1(0, width-1);//диапазон для ширины спавна травы
	std::uniform_int_distribution<int> uid2(0, hight-1);//диапазон для длины спавна травы
	std::uniform_int_distribution<int> uid3(60, 140);//диапазон энергетической ценности отдельной травы
	int quantity_grace = int((square_fertile_soil*3)/4);//пока-что заглушка, потом количество генерируемой травы
	//сделаем передаваемым значением из панели управления картой, значение будет в процентах от площади острова
	std::pair<int, int> coordinates;
	for (auto i = 0; i <= quantity_grace; ++i) {
		coordinates.first = uid1(gen);
		coordinates.second = uid2(gen);
		if (map[coordinates.first][coordinates.second].have_grace != true) {//если нет травы в этом тайтле, то:
			int energy = uid3(gen);
			//Grace grace;
			//std::shared_ptr<Grace> grace(new Grace);//наконец-то доросли до умных указателей
			auto grace = std::make_shared<Grace>();
			grace->setEnergy(energy);
			grace->setCoordinates(coordinates);
			//graces.push_back(&grace);//у нас есть контейнер для хранения объетов травы, куда и заносим этот объёт
			map[coordinates.first][coordinates.second].have_grace = true; //теперь тут есть трава
			map[coordinates.first][coordinates.second].title_image.push_back('g'); //заполнение тайтла знаком g 
			//map[coordinates.first][coordinates.second].p_grace(std::make_shared<Grace>(grace));
			map[coordinates.first][coordinates.second].p_grace=grace;
		}
	}
}

void island::createFauna(int rabbit_quantity, int wolf_quantity)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> x_r(0, width - 1);//диапазон для ширины спавна кролей
	std::uniform_int_distribution<int> y_r(0, hight - 1);//диапазон для длины спавна кролей
	std::uniform_int_distribution<int> x_w(0, width - 1);//диапазон для ширины спавна волков
	std::uniform_int_distribution<int> y_w(0, hight - 1);//диапазон для длины спавна волков
	std::uniform_int_distribution<int> w_sex(0, 1);
	std::pair<int, int> r_position;
	std::pair<int, int> w_position;
	
	for (int i = 0; i < rabbit_quantity; i++) {
		r_position.first = x_r(gen);
		r_position.second = y_r(gen);
		//Rabbit rabbit;//создание кролика - заменили на создание через умные указатели
		auto rabbit = std::make_shared<Rabbit>();
		rabbit->setPosition(r_position);//установили его начальное положение
		map[rabbit->getPosition().first][rabbit->getPosition().second].title_image.push_back('r');
		//map[rabbit->getPosition().first][rabbit->getPosition().second].v_p_rabbit.push_back(rabbit);
		map[rabbit->getPosition().first][rabbit->getPosition().second].have_rabbit = true;//заполнение поля наличия кролика на тайтле
		//rabbit.setTitlePosition(map[rabbit.getPosition().first][rabbit.getPosition().second].title_image.size());//запоминаем
		//на какой высоте находится изображение кролика
		rabbits.push_back(rabbit);//поместили кролика в контейнер кроликов
	}
	for (int i = 0; i < wolf_quantity; i++) {
		w_position.first = x_w(gen);
		w_position.second = y_w(gen);
		auto wolf = std::make_shared<Wolf>();
		wolf->setPosition(w_position);
		wolf->setSex(w_sex(gen));
		//wolf->setPosition(w_position);//установили его начальное положение
		map[wolf->getPosition().first][wolf->getPosition().second].title_image.push_back('w');
		wolves.push_back(wolf);//поместили волка в контейнер волков
	}
}

void island::doActions(int &rabbit_birth_counter, int& world_step)
{
	
	//фаза передвижений кроликов
	for (int i = 0; i < rabbits.size(); i++) {
		auto x = rabbits[i]->getPosition().first;
		auto y = rabbits[i]->getPosition().second;
		map[x][y].title_image.remove('r');
		map[x][y].have_rabbit = false;
		rabbits[i]->doStep(width, hight);
		auto x2 = rabbits[i]->getPosition().first;
		auto y2 = rabbits[i]->getPosition().second;
		map[x2][y2].title_image.push_back('r');
		map[x][y].have_rabbit = true;
	}
	//фаза передвижений волков
	for (int i = 0; i < wolves.size(); i++) {
		auto x = wolves[i]->getPosition().first;
		auto y = wolves[i]->getPosition().second;
		map[x][y].title_image.remove('w');
		wolves[i]->doStep(width, hight);
		auto x2 = wolves[i]->getPosition().first;
		auto y2 = wolves[i]->getPosition().second;
		map[x2][y2].title_image.push_back('w');
	}
	
	Sleep(50);

	int rcount = rabbits.size();//кол-во кроликов на данную интерацию
	//фаза питания кролей
	for (int i = 0; i < rabbits.size(); i++) {
		int x = rabbits[i]->getPosition().first;
		int y = rabbits[i]->getPosition().second;
		if (map[x][y].have_grace) {
			int cur_energy = map[x][y].p_grace->getEnergy();
			if (cur_energy > 20) {
				rabbits[i]->doEat(20);
				map[x][y].p_grace->setEnergy(cur_energy - 20);
			}
			else {
				rabbits[i]->doEat(cur_energy);
				map[x][y].p_grace->setEnergy(0);
			}
		}
		else {
			rabbits[i]->doEat(-17);
		}
	}
	//фаза питания волков
	int wcount = wolves.size();
	for (int i = 0; i < wcount; i++) {
		int x = wolves[i]->getPosition().first;
		int y = wolves[i]->getPosition().second;
		if (map[x][y].have_rabbit) {//если на клетке с волком присутствует кролик, то
				wolves[i]->doEat(150); // волк насыщается на 150 
				for (int j = 0; j < rabbits.size(); j++) {//среди кроликов ищем такого, чьи координаты совпадают с координатами волка
					if (rabbits[j]->getPosition() == wolves[i]->getPosition()) {
						map[x][y].title_image.remove('r');//с этой клетки удаляем значёк кролика
						rabbits[j].reset();// уничтожаем кролика
						rabbits.erase(rabbits.begin() + j); // чистим вектор кроликов
						break;
					}
				}
		}
		else {//если нет кролика, то волк голодает
			wolves[i]->doEat(-20);
		}
	}
	//фаза проверки параметров и вызовов деструкторов для травы
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
	
	//фаза размножения кроликов
	if (rabbit_birth_counter == 15) {//раз в 15 ходов начинается брачный сезон для кроликов
		for (int i = 0; i < rcount; i++) {
			auto cur_sat = rabbits[i]->getSatiety();
			auto cur_age = rabbits[i]->getAge();
			if ( cur_sat >= 100 && cur_age > 10) {
				rabbits.push_back(rabbits[i]->doLove(rabbits[i]->getPosition()));
				rabbits[i]->setSatiety(-30);
			}
		}
		rabbit_birth_counter = 0;
	}
	rcount = rabbits.size();//кол-во кроликов на данную интерацию
	// увеличение возраста кролей и их смерть
	for (int i = 0; i < rcount; i++) {
		rabbits[i]->incAge();
		if (rabbits[i]->getAge() == 90 || rabbits[i]->getSatiety()<=0) {
			int x = rabbits[i]->getPosition().first;
			int y = rabbits[i]->getPosition().second;
			map[x][y].title_image.remove('r');
			rabbits[i].reset();
			if (rabbits[i] == 0) {
				rabbits.erase(rabbits.begin() + i);
				i--;
				rcount--;
			}
		}
	}

	//фаза размножения волков
	for (int i = 0; i < wcount; i++) {
			for (int j = i; j < wcount; j++) {//если волки на одной клетке и разного пола, породить нового волчару
				if ((wolves[i]->getPosition() == wolves[j]->getPosition())&&(wolves[i]->getSex()!= wolves[j]->getSex())) {
					wolves.push_back(wolves[i]->doLove(wolves[i]->getPosition()));
					wolves[i]->setSatiety(-50);
					wolves[j]->setSatiety(-50);
				}
			}

	}

	wcount = wolves.size();
	//фаза вырастания и умирания волков 
	for (int i = 0; i < wcount; i++) {
		wolves[i]->incAge();
		if (wolves[i]->getAge() == 800 || wolves[i]->getSatiety() <= 0) {
			int x = wolves[i]->getPosition().first;
			int y = wolves[i]->getPosition().second;
			map[x][y].title_image.remove('w');
			wolves[i].reset();
			if (wolves[i] == 0) {
				wolves.erase(wolves.begin() + i);
				i--;
				wcount--;
			}
		}
	}

	world_step++;
	if (rabbits.size() == 0 || wolves.size() == 0)
	{
		drawMap();
		std::cout<<std::endl;
		std::cout << world_step;
		std::cout << "Экосистема неустойчива, один из видовы вымер" << std::endl;
		system("pause");
	}
	for (int i = 1; i < wolves.size(); i++) {
		if (wolves[0]->getSex() != wolves[i]->getSex()) {
			std::cout << "M+W exist";
		}
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
	 std::cout << std::endl;
	 std::cout << "Rabbits population size " << rabbits.size() << std::endl;
	 std::cout << "Wolves population size " << wolves.size() << std::endl;
 }


island::~island()
{
}
