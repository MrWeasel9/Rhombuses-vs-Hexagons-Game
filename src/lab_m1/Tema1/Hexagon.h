#pragma once
#include "components/simple_scene.h"
#include "Transform2D.h"
#include <string>
#include <Core/Engine.h>
#include <vector>

class Hexagon {
public:
	Hexagon();
	float getTranslateX();
	float getTranslateY();
	float getScaleX();
	float getScaleY();
	bool getDisappearShooter();
	bool getDisappearHexagon();
	int getLives();
	int getRowNr();
	std::string getColor();

	void setTranslateX(float x);
	void setTranslateY(float y);
	void setScaleX(float scaleX);
	void setScaleY(float scaleY);
	void setDisappearShooter(bool disappearShooter);
	void setDisappearHexagon(bool disappearHexagon);
	void setLives(int lives);
	void setRowNr(int rowNr);
	void setColor(std::string color);
	~Hexagon();

private:
	std::string color;
	float translateX;
	float translateY;
	bool disappearShooter;
	bool disappearHexagon;
	float scaleX;
	float scaleY;
	int lives;
	int rowNr;
};