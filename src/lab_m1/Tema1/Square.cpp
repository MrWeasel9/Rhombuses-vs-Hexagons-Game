#include "Square.h"


Square::Square()
{
	this->position = glm::vec3(0, 0, 0);
	this->hasShooter = false;
	this->disappearShooter = false;
	this->shooter = NULL;
}

glm::vec3 Square::getSquarePos()
{
	return this->position;
}
bool Square::getHasShooter()
{
	return this->hasShooter;
}
Shooter* Square::getShooter()
{
	return this->shooter;
}
bool Square::getDisappearShooter()
{
	return this->disappearShooter;
}
int Square::getRowNr()
{
	return this->rowNr;
}

void Square::setSquarePos(float x, float y, float z)
{
	this->position = glm::vec3(x, y, z);
}
void Square::setHasShooter(bool hasShooter)
{
	this->hasShooter = hasShooter;
}
void Square::setShooter(Shooter* shooter)
{
	this->shooter = shooter;
}
void Square::setDisappearShooter(bool disappearShooter)
{
	this->disappearShooter = disappearShooter;
}
void Square::setRowNr(int rowNr)
{
	this->rowNr = rowNr;
}
Square::~Square()
{
}