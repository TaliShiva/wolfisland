#pragma once
class Grace
{
public:
	Grace();
	int getEnergy();//�������� �������� ������� ����������� ��������, ���� ������� ����� �� 0, �� �������� ����
	void setEnergy(int e);//������������� �������� �������
	std::pair<int, int> getCoordinates();//�������� ���������� ����������� ��������
	void setCoordinates(std::pair<int, int>);//���������� ���������� ���������� ��������
	~Grace();
private:
	std::pair<int, int> grace_coordinates;
	bool immortality = false;//���� �� �������,� ������, ����� ������� ����� ������������ ����� �����
	int energy;
};

