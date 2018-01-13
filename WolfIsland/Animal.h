#pragma once
//#include "EcosystemHeaders.h"

/*
class Animal
{
public:
	virtual bool isALive() = 0;
	virtual int getSatiety() = 0;
	virtual void setSatiety() = 0;
	virtual void nextAction() = 0;
	virtual int getInitiative() = 0;
	virtual int setInitiative() = 0;
	virtual int getAge() = 0;
	//virtual void info() = 0;
	virtual bool getSex() = 0;
	virtual void doEat() = 0;
	virtual void doStep() = 0;
	virtual void doLove() = 0;
	virtual std::pair <int, int> getPosition() = 0;
	virtual ~Animal() = 0;
	};
*/
//class Rabbit : public Animal {
class Rabbit{
public:
	Rabbit();//—оздание кролика проинициализированного значени€ми по умолчанию,в дальнейшем, в 
	//зависимости от параметров, можно быть задавать каких-то иных кроликов
	int getSatiety();// получить значение сытости
	void setSatiety(int);// установить значение сытости
	void nextAction();//изначально подразумевалось следующее действие кролика, но оно было декомпозировано, до
	//передвижени€-> питани€-> размножени€
	int getInitiative();//получение инициативы
	void setInitiative(int);//установка инициативы в зависимости от новых условий
	int getAge();// получить возраст кролика, с каждым итерацией цикла действий, возраст увеличиваетс€ на единичку
	//void info();
	int getTitlePosition();
	void setTitlePosition(int);
	void doEat(int);//кролик ест траву
	void doStep(int,int);//кролик перемешаетс€ на указанную позицию
	std::pair <int, int> getPosition();//получаем текущую позицию кролика
	void setPosition( std::pair <int, int>);//устанавливаем позицию кролика
	void incAge();
	std::shared_ptr<Rabbit> doLove(std::pair <int, int>);//кролик размножаетс€
	~Rabbit();//уничтожение кролика
private:
	std::pair <int, int> rabbit_coordinates;
	//int title_position;
	int age=0;
	int initiative=0;
	int satiety=0;
	
};



/*
class Wolf : public Animal {
	Wolf();
	~Wolf();

};


//ДUДpДqДВДyД{Дy ДxДrДuДВДuДz - ДPДВДyДrДuДД ДOД|ДuДsДЕ)))

class AnimalFactory
{
public:
	virtual Animal* createAnimal() = 0;
	virtual ~AnimalFactory() {}
};

class RabbitFactory : public AnimalFactory
{
	Animal* createAnimal() {
		return new Rabbit;
	}
};
class WolfFactory : public AnimalFactory
{
	Animal* createAnimal() {
		return new Wolf;
	}
 };

*/