#pragma once
#include "components/simple_scene.h"
#include "Transform2D.h"
#include <string>
#include <Core/Engine.h>
#include <vector>

class Shooter {
public:
	Shooter();
	float getPosX();
	float getPosY();
	std::string getShooterColor();
	float getScaleX();
	float getScaleY();
	float getReloadTime();
	int getRowNr();

	void setShooterPos(float x, float y, float z);
	void setShooterColor(std::string color);
	void setScaleX(float scaleX);
	void setScaleY(float scaleY);
	void setReloadTime(float reloadTime);
	void setRowNr(int rowNr);
	~Shooter();

private:
	
	std::string color;
	float posX;
	float posY;
	float posZ;
	float scaleX;
	float scaleY;
	float reloadTime;
	int rowNr;
};