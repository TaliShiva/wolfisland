// WolfIsland.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "land.h"
void mainLoop() {
	int world_step = 0;
	int grace_create_counter = 0;
	int rabbit_birth_counter = 0;
	island my_land;
	while (true) {
		if (grace_create_counter == 20) {
			my_land.createFlora();
			grace_create_counter = 0;
		}
		grace_create_counter++;
		//вызов какой-то функции из logic которая заставит кролика сделать его кроличьи действия
		my_land.doActions(rabbit_birth_counter, world_step);//через жопу всё, но пофиг, декомпозировать времени нет, уже 13е
		rabbit_birth_counter++;
		my_land.drawMap();
		std::cout<< "World age " << world_step << std::endl;
	}
}

int main()
{

	mainLoop();
	system("PAUSE");

	return 0;

}

