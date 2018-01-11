#pragma once
class Grace
{
public:
	Grace();
	int getEnergy();//получаем значение энергии конкретного растени€, если энерги€ упадЄт до 0, то растение умрЄт
	void setEnergy(int e);//устанавливаем значение энергии
	std::pair<int, int> getCoordinates();//получить координаты конкретного растени€
	void setCoordinates(std::pair<int, int>);//установить координаты некоторого растени€
	~Grace();
private:
	std::pair<int, int> grace_coordinates;
	bool immortality = false;//поле на будущее,в случае, когда система имеет безграничное число травы
	int energy;
};

