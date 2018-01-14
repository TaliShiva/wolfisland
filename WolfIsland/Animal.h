#pragma once
/*
class Animal
{
public:
	virtual int getSatiety() = 0;
	virtual void setSatiety() = 0;
	virtual void nextAction() = 0;
	virtual int getInitiative() = 0;
	virtual int setInitiative() = 0;
	virtual int getAge() = 0;
	virtual bool getSex() = 0;
	virtual void doEat() = 0;
	virtual void doStep() = 0;
	virtual void doLove() = 0;
	virtual std::pair <int, int> getPosition() = 0;
	virtual ~Animal() = 0;
	};
*/
//class Rabbit : public Animal {

class Rabbit {
public:
	Rabbit();//Создание кролика проинициализированного значениями по умолчанию,в дальнейшем, в 
	//зависимости от параметров, можно быть задавать каких-то иных кроликов
	int getSatiety();// получить значение сытости
	void setSatiety(int);// установить значение сытости
	//void nextAction();//изначально подразумевалось следующее действие кролика, но оно было декомпозировано, до
	//передвижения-> питания-> размножения
	int getInitiative();//получение инициативы
	void setInitiative(int);//установка инициативы в зависимости от новых условий
	int getAge();// получить возраст кролика, с каждым итерацией цикла действий, возраст увеличивается на единичку
	//void info();
	void doEat(int);//кролик ест траву
	void doStep(int,int);//кролик перемешается на указанную позицию
	std::pair <int, int> getPosition();//получаем текущую позицию кролика
	void setPosition( std::pair <int, int>);//устанавливаем позицию кролика
	void incAge();
	std::shared_ptr<Rabbit> doLove(std::pair <int, int>);//кролик размножается
	~Rabbit();//уничтожение кролика
private:
	std::pair <int, int> rabbit_coordinates;
	//int title_position;
	int age=0;
	int initiative=0;
	int satiety=0;
	
};

class Wolf{
public:
	Wolf();
	int getSatiety();// получить значение сытости
	void setSatiety(int);// установить значение сытости
	int getInitiative();//получение инициативы
	void setInitiative(int);//установка инициативы в зависимости от новых условий
	int getAge();// получить возраст волка, с каждым итерацией цикла действий, возраст увеличивается на единичку
	void doEat(int);//волк ест кроликов
	void doStep(int, int);//кролик перемешается на указанную позицию
	std::pair <int, int> getPosition();//получаем текущую позицию волка
	void setPosition(std::pair <int, int>);//устанавливаем позицию волка
	void incAge();
	std::shared_ptr<Wolf> doLove(std::pair <int, int>);//волк размножается
	bool getSex();
	void setSex(bool);
	~Wolf();
private:
	std::pair <int, int> wolf_coordinates;
	int age = 0;
	int initiative = 0;
	bool sex;
	int satiety = 0;
};


//Фабричный метод для порождения зверей
/*
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