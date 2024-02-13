#include "Shooter.h"

// Clasa pentru inamici
Shooter::Shooter()
{
	this->posX = 0;
	this->posY = 0;
	this->color = "";
	this->scaleX = 1;
	this->scaleY = 1;
	this->reloadTime = 0;
}
float Shooter::getPosX()
{
	return this->posX;
}
float Shooter::getPosY()
{
	return this->posY;
}
std::string Shooter::getShooterColor()
{
	return this->color;
}
float Shooter::getReloadTime()
{
	return this->reloadTime;
}
float Shooter::getScaleX()
{
	return this->scaleX;
}
float Shooter::getScaleY()
{
	return this->scaleY;
}
int Shooter::getRowNr()
{
	return this->rowNr;
}
void Shooter::setShooterPos(float x, float y, float z)
{
	this->posX = x;
	this->posY = y;
	this->posZ = z;
}
void Shooter::setShooterColor(std::string color)
{
	this->color = color;
}
void Shooter::setScaleX(float scaleX)
{
	this->scaleX = scaleX;
}
void Shooter::setScaleY(float scaleY)
{
	this->scaleY = scaleY;
}
void Shooter::setReloadTime(float reloadTime)
{
	this->reloadTime = reloadTime;
}
void Shooter::setRowNr(int rowNr)
{
	this->rowNr = rowNr;
}
Shooter::~Shooter()
{
}
