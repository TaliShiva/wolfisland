// WolfIsland.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "land.h"
void mainLoop() {
	
	int grace_create_counter = 0;
	int rabbit_birth_counter = 0;
	island my_land;
	while (true) {
		if (grace_create_counter == 25) {
			my_land.createFlora();
			grace_create_counter = 0;
		}
		grace_create_counter++;
		//вызов какой-то функции из logic которая заставит кролика сделать его кроличьи действия
		my_land.doActions(rabbit_birth_counter);//через жопу всё, но пофиг, декомпозировать времени нет, уже 13е
		rabbit_birth_counter++;
		my_land.drawMap();
		//Sleep(100);
		
		//Sleep(1000);
	}
}

int main()
{

	mainLoop();
	system("PAUSE");

	return 0;

}

