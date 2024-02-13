#pragma once
#include "components/simple_scene.h"
#include "Transform2D.h"
#include <string>
#include <Core/Engine.h>
#include <vector>
#include "Shooter.h"

class Square {
public:
	Square();
	glm::vec3 getSquarePos();
	bool Square::getHasShooter();
	Shooter* getShooter();
	bool getDisappearShooter();
	int getRowNr();

	void setSquarePos(float x, float y, float z);
	void setHasShooter(bool hasShooter);
	void setShooter(Shooter* shooter);
	void setDisappearShooter(bool disappearShooter);
	void setRowNr(int rowNr);
	~Square();

private:
	bool hasShooter;
	bool disappearShooter;
	glm::vec3 position;
	Shooter* shooter;
	int rowNr;
};