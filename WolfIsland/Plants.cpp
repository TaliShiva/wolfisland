#include "stdafx.h"
#include "Plants.h"


Grace::Grace()
{
	setEnergy(0);
	grace_coordinates.first = 0;
	grace_coordinates.second = 0;
}


Grace::~Grace()
{
}

int Grace::getEnergy()
{
	return energy;
}

void Grace::setEnergy(int e)
{
	energy = e;
}

std::pair<int, int> Grace::getCoordinates()
{
	return grace_coordinates;
}

void Grace::setCoordinates(std::pair<int,int> my_coordinates)
{
	grace_coordinates = my_coordinates;
}


