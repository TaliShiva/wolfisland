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
	Rabbit();//�������� ������� ���������������������� ���������� �� ���������,� ����������, � 
	//����������� �� ����������, ����� ���� �������� �����-�� ���� ��������
	int getSatiety();// �������� �������� �������
	void setSatiety(int);// ���������� �������� �������
	//void nextAction();//���������� ��������������� ��������� �������� �������, �� ��� ���� ���������������, ��
	//������������-> �������-> �����������
	int getInitiative();//��������� ����������
	void setInitiative(int);//��������� ���������� � ����������� �� ����� �������
	int getAge();// �������� ������� �������, � ������ ��������� ����� ��������, ������� ������������� �� ��������
	//void info();
	void doEat(int);//������ ��� �����
	void doStep(int,int);//������ ������������ �� ��������� �������
	std::pair <int, int> getPosition();//�������� ������� ������� �������
	void setPosition( std::pair <int, int>);//������������� ������� �������
	void incAge();
	std::shared_ptr<Rabbit> doLove(std::pair <int, int>);//������ ������������
	~Rabbit();//����������� �������
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
	int getSatiety();// �������� �������� �������
	void setSatiety(int);// ���������� �������� �������
	int getInitiative();//��������� ����������
	void setInitiative(int);//��������� ���������� � ����������� �� ����� �������
	int getAge();// �������� ������� �����, � ������ ��������� ����� ��������, ������� ������������� �� ��������
	void doEat(int);//���� ��� ��������
	void doStep(int, int);//������ ������������ �� ��������� �������
	std::pair <int, int> getPosition();//�������� ������� ������� �����
	void setPosition(std::pair <int, int>);//������������� ������� �����
	void incAge();
	std::shared_ptr<Wolf> doLove(std::pair <int, int>);//���� ������������
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


//��������� ����� ��� ���������� ������
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