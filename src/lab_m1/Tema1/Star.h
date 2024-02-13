#pragma once
#include "components/simple_scene.h"
#include "Transform2D.h"
#include <string>
#include <Core/Engine.h>
#include <vector>

class Star {
public:
	Star();
	glm::vec3 getStarPos();
	float getTranslateX();
	float getTranslateY();
	float getAngularStep();
	std::string getColor();
	
	void setStarPos(float x, float y, float z);
	void setTranslateX(float x);
	void setTranslateY(float y);
	void setAngularStep(float angularStep);
	void setColor(std::string color);
	~Star();

private:
	std::string color;
	glm::vec3 position;
	float translateX;
	float translateY;
	float angularStep;
};