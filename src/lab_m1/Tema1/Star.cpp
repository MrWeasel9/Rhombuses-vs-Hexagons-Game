#include "Star.h"

// Clasa pentru inamici
Star::Star()
{
	this->position = glm::vec3(0, 0, 0);
	this->color = "";
	this->translateX = 0;
	this->translateY = 0;
	this->angularStep = 0;
}
glm::vec3 Star::getStarPos()
{
	return this->position;
}
float Star::getTranslateX()
{
	return this->translateX;
}
float Star::getTranslateY()
{
	return this->translateY;
}
float Star::getAngularStep()
{
	return this->angularStep;
}
std::string Star::getColor()
{
	return this->color;
}

void Star::setStarPos(float x, float y, float z)
{
	this->position = glm::vec3(x, y, z);
}
void Star::setTranslateX(float x) {
	this->translateX = x;
}
void Star::setTranslateY(float y) {
	this->translateY = y;
}
void Star::setAngularStep(float angularStep) {
	this->angularStep = angularStep;
}
void Star::setColor(std::string color) {
	this->color = color;
}

Star::~Star()
{
}
