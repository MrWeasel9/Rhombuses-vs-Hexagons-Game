#include "Hexagon.h"

// Clasa pentru inamici
Hexagon::Hexagon()
{
	this->color = "";
	this->translateX = 0;
	this->translateY = 0;
	this->disappearShooter = false;
	this->disappearHexagon = false;
	this->scaleX = 1;
	this->scaleY = 1;
	this->lives = 3;
}

float Hexagon::getTranslateX()
{
	return this->translateX;
}
float Hexagon::getTranslateY()
{
	return this->translateY;
}
float Hexagon::getScaleX()
{
	return this->scaleX;
}
float Hexagon::getScaleY()
{
	return this->scaleY;
}
bool Hexagon::getDisappearShooter()
{
	return this->disappearShooter;
}
bool Hexagon::getDisappearHexagon()
{
	return this->disappearHexagon;
}
int Hexagon::getLives()
{
	return this->lives;
}
int Hexagon::getRowNr()
{
	return this->rowNr;
}
std::string Hexagon::getColor()
{
	return this->color;
}

void Hexagon::setTranslateX(float x)
{
	this->translateX = x;
}
void Hexagon::setTranslateY(float y)
{
	this->translateY = y;
}
void Hexagon::setScaleX(float scaleX)
{
	this->scaleX = scaleX;
}
void Hexagon::setScaleY(float scaleY)
{
	this->scaleY = scaleY;
}
void Hexagon::setDisappearShooter(bool disappearShooter)
{
	this->disappearShooter = disappearShooter;
}
void Hexagon::setDisappearHexagon(bool disappearHexagon)
{
	this->disappearHexagon = disappearHexagon;
}
void Hexagon::setLives(int lives)
{
	this->lives = lives;
}
void Hexagon::setRowNr(int rowNr)
{
	this->rowNr = rowNr;
}
void Hexagon::setColor(std::string color)
{
	this->color = color;
}
Hexagon::~Hexagon()
{
}
