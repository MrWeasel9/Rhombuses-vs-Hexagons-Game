#include "lab_m1/Tema1/Tema1.h"

#include <vector>
#include <iostream>

#include "lab_m1/Tema1/transform2D.h"
#include "lab_m1/Tema1/object2D.h"

using namespace std;
using namespace m1;

Tema1::Tema1() {}

Tema1::~Tema1() {}

void Tema1::CreateMeshes(glm::vec3 center, float squareSide, float starSize, float hexRadius)
{
	Mesh* orangeShooter = object2D::CreateGunShape("orangeShooter", center, squareSide / 1.9, squareSide, orange, true);
	AddMeshToList(orangeShooter);

	Mesh* blueShooter = object2D::CreateGunShape("blueShooter", center, squareSide / 1.9, squareSide, blue, true);
	AddMeshToList(blueShooter);

	Mesh* purpleShooter = object2D::CreateGunShape("purpleShooter", center, squareSide / 1.9, squareSide, purple, true);
	AddMeshToList(purpleShooter);

	Mesh* yellowShooter = object2D::CreateGunShape("yellowShooter", center, squareSide / 1.9, squareSide, yellow, true);
	AddMeshToList(yellowShooter);

	Mesh* starShape = object2D::CreateStarShape("starShape", center, starSize / 2, starSize, white, true);
	AddMeshToList(starShape);

	Mesh* orangeStar = object2D::CreateStarShape("orangeStar", center, starSize / 2, starSize, orange, true);
	AddMeshToList(orangeStar);

	Mesh* blueStar = object2D::CreateStarShape("blueStar", center, starSize / 2, starSize, blue, true);
	AddMeshToList(blueStar);

	Mesh* yellowStar = object2D::CreateStarShape("yellowStar", center, starSize / 2, starSize, yellow, true);
	AddMeshToList(yellowStar);

	Mesh* purpleStar = object2D::CreateStarShape("purpleStar", center, starSize / 2, starSize, purple, true);
	AddMeshToList(purpleStar);

	Mesh* pinkStarShape = object2D::CreateStarShape("pinkStarShape", center, starSize, starSize * 2, pink, true);
	AddMeshToList(pinkStarShape);

	Mesh* baseRectangle = object2D::CreateRectangle("baseRectangle", center, squareSide / 2, squareSide * 4, red, true);
	AddMeshToList(baseRectangle);

	Mesh* square = object2D::CreateSquare("square", center, squareSide, green, true);
	AddMeshToList(square);

	Mesh* outlineSquare = object2D::CreateSquare("outlineSquare", center, squareSide, black, false);
	AddMeshToList(outlineSquare);

	Mesh* redSquare = object2D::CreateSquare("redSquare", center, squareSide / 1.5, red, true);
	AddMeshToList(redSquare);

	Mesh* orangeHexagon = object2D::CreateOverlappingHexagons("orangeHexagon", center, hexRadius, hexRadius / 1.4, orange, turqoise);
	AddMeshToList(orangeHexagon);

	Mesh* blueHexagon = object2D::CreateOverlappingHexagons("blueHexagon", center, hexRadius, hexRadius / 1.4, blue, turqoise);
	AddMeshToList(blueHexagon);

	Mesh* yellowHexagon = object2D::CreateOverlappingHexagons("yellowHexagon", center, hexRadius, hexRadius / 1.4, yellow, turqoise);
	AddMeshToList(yellowHexagon);

	Mesh* purpleHexagon = object2D::CreateOverlappingHexagons("purpleHexagon", center, hexRadius, hexRadius / 1.4, purple, turqoise);
	AddMeshToList(purpleHexagon);
}

void Tema1::RenderMeshes()
{
	// shooters
	modelMatrix = glm::mat3(1);
	modelMatrix *= transform2D::Translate(100, 650);
	RenderMesh2D(meshes["orangeShooter"], shaders["VertexColor"], modelMatrix);
	modelMatrix = glm::mat3(1);
	modelMatrix *= transform2D::Translate(55, 600);
	RenderMesh2D(meshes["outlineSquare"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	modelMatrix *= transform2D::Translate(300, 650);
	RenderMesh2D(meshes["blueShooter"], shaders["VertexColor"], modelMatrix);
	modelMatrix = glm::mat3(1);
	modelMatrix *= transform2D::Translate(255, 600);
	RenderMesh2D(meshes["outlineSquare"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	modelMatrix *= transform2D::Translate(500, 650);
	RenderMesh2D(meshes["yellowShooter"], shaders["VertexColor"], modelMatrix);
	modelMatrix = glm::mat3(1);
	modelMatrix *= transform2D::Translate(455, 600);
	RenderMesh2D(meshes["outlineSquare"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	modelMatrix *= transform2D::Translate(700, 650);
	RenderMesh2D(meshes["purpleShooter"], shaders["VertexColor"], modelMatrix);
	modelMatrix = glm::mat3(1);
	modelMatrix *= transform2D::Translate(655, 600);
	RenderMesh2D(meshes["outlineSquare"], shaders["VertexColor"], modelMatrix);

	// stars
	for (auto iterator : pinkStarsVector) {
		modelMatrix = glm::mat3(1);
		modelMatrix *= transform2D::Translate(iterator->getStarPos().x, iterator->getStarPos().y);
		RenderMesh2D(meshes["pinkStarShape"], shaders["VertexColor"], modelMatrix);
	}
	for (auto iterator : pointStarsVector) {
		modelMatrix = glm::mat3(1);
		modelMatrix *= transform2D::Translate(iterator->getStarPos().x, iterator->getStarPos().y);
		RenderMesh2D(meshes["starShape"], shaders["VertexColor"], modelMatrix);
	}
	// 1 Star Value
	modelMatrix = glm::mat3(1);
	modelMatrix *= transform2D::Translate(75, 575);
	RenderMesh2D(meshes["starShape"], shaders["VertexColor"], modelMatrix);

	// 2 Star Value
	modelMatrix = glm::mat3(1);
	modelMatrix *= transform2D::Translate(275, 575);
	RenderMesh2D(meshes["starShape"], shaders["VertexColor"], modelMatrix);
	modelMatrix = glm::mat3(1);
	modelMatrix *= transform2D::Translate(315, 575);
	RenderMesh2D(meshes["starShape"], shaders["VertexColor"], modelMatrix);

	// 2 Star Value
	modelMatrix = glm::mat3(1);
	modelMatrix *= transform2D::Translate(475, 575);
	RenderMesh2D(meshes["starShape"], shaders["VertexColor"], modelMatrix);
	modelMatrix = glm::mat3(1);
	modelMatrix *= transform2D::Translate(515, 575);
	RenderMesh2D(meshes["starShape"], shaders["VertexColor"], modelMatrix);

	// 3 Star Value
	modelMatrix = glm::mat3(1);
	modelMatrix *= transform2D::Translate(675, 575);
	RenderMesh2D(meshes["starShape"], shaders["VertexColor"], modelMatrix);
	modelMatrix = glm::mat3(1);
	modelMatrix *= transform2D::Translate(715, 575);
	RenderMesh2D(meshes["starShape"], shaders["VertexColor"], modelMatrix);
	modelMatrix = glm::mat3(1);
	modelMatrix *= transform2D::Translate(755, 575);
	RenderMesh2D(meshes["starShape"], shaders["VertexColor"], modelMatrix);


	// rectangles
	for (int i = 0; i < numSquares; i++) {
		modelMatrix = glm::mat3(1);
		float squareX = gridSquaresVector[i]->getSquarePos().x;
		float squareY = gridSquaresVector[i]->getSquarePos().y;
		modelMatrix *= transform2D::Translate(squareX, squareY);
		RenderMesh2D(meshes["square"], shaders["VertexColor"], modelMatrix);
	}
	for (auto redSquare : remainingLivesVector) {
		modelMatrix = glm::mat3(1);
		modelMatrix *= transform2D::Translate(redSquare->getSquarePos().x, redSquare->getSquarePos().y);
		RenderMesh2D(meshes["redSquare"], shaders["VertexColor"], modelMatrix);
	}

	modelMatrix = glm::mat3(1);
	modelMatrix *= transform2D::Translate(5, 15);
	RenderMesh2D(meshes["baseRectangle"], shaders["VertexColor"], modelMatrix);

}

void Tema1::Init()
{
	glm::ivec2 resolution = window->GetResolution();
	auto camera = GetSceneCamera();
	camera->SetOrthographic(0, (float)resolution.x, 0, (float)resolution.y, 0.01f, 400);
	camera->SetPosition(glm::vec3(0, 0, 50));
	camera->SetRotation(glm::vec3(0, 0, 0));
	camera->Update();
	GetCameraInput()->SetActive(false);

	// Create meshes and add them to the list
	CreateMeshes(center, squareSide, starSize, hexRadius);

	// spawn 5 initial pink stars
	for (int i = 0; i < numPinkStars; i++) {
		float randomX = static_cast<float>(rand() % 1000);
		float randomY = static_cast<float>(rand() % 650);
		Star* star = new Star();
		star->setStarPos(randomX, randomY, 0.2f);
		pinkStarsVector.push_back(star);
	}
	// spawn 3 player hearts
	for (int i = 0; i < numLives; i++) {
		Square* lifeSquare = new Square();
		lifeSquare->setSquarePos(825 + i * 100, 620, 0);
		remainingLivesVector.push_back(lifeSquare);
	}
	// spawn 5 initial point stars
	for (int i = 0; i < numPointStars; i++) {
		currentPointStarPos = 850 + i * 50;
		Star* star = new Star();
		star->setStarPos(currentPointStarPos, 575, 0.2f);
		pointStarsVector.push_back(star);
	}
	// spawn the 3x3 grid of squares
	for (int i = 0; i < numSquares; i++) {
		Square* square = new Square();
		square->setSquarePos(squarePositions[i].x, squarePositions[i].y, 0);
		square->setHasShooter(false);
		if (i < 3) {
			square->setRowNr(1);
		}
		else if (i < 6) {
			square->setRowNr(2);
		}
		else {
			square->setRowNr(3);
		}
		gridSquaresVector.push_back(square);
	}
}

void Tema1::FrameStart()
{
	// Clears the color buffer (using the previously set color) and depth buffer
	glClearColor(0.2f, 0.2f, 0.2f, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glm::ivec2 resolution = window->GetResolution();
	// Sets the screen area where to draw
	glViewport(0, 0, resolution.x, resolution.y);
}

void Tema1::Update(float deltaTimeSeconds)
{
	timeElapsed += deltaTimeSeconds;

	RenderMeshes();

	for (auto iterator : gridSquaresVector) {
		Shooter* shooter = iterator->getShooter();

		// check if the shooter has been set to disappear
		if (iterator->getDisappearShooter()) {
			iterator->setHasShooter(false);
			// shrink the shooter until it disappears
			if (shooter->getScaleX() < 0.1 && shooter->getScaleY() < 0.1) {
				iterator->setDisappearShooter(false);
				delete shooter;
				iterator->setShooter(NULL);

			}
			else {
				shooter->setScaleX(shooter->getScaleX() - deltaTimeSeconds * 0.8);
				shooter->setScaleY(shooter->getScaleY() - deltaTimeSeconds * 0.8);
				modelMatrix = glm::mat3(1);
				modelMatrix *= transform2D::Translate(shooter->getPosX(), shooter->getPosY());
				modelMatrix *= transform2D::Scale(shooter->getScaleX(), shooter->getScaleY());
				RenderMesh2D(meshes[shooter->getShooterColor() + "Shooter"], shaders["VertexColor"], modelMatrix);
			}
		}
		// check if the grid square has a shooter
		if (iterator->getHasShooter()) {
			shooter->setReloadTime(shooter->getReloadTime() + deltaTimeSeconds);
			modelMatrix = glm::mat3(1);
			modelMatrix *= transform2D::Translate(shooter->getPosX(), shooter->getPosY());
			RenderMesh2D(meshes[shooter->getShooterColor() + "Shooter"], shaders["VertexColor"], modelMatrix);
			// check if the shooter can shoot
			if (shooter->getReloadTime() >= 2.0f) {
				// check if there are enemies in the same row as the shooter
				if (shooter->getRowNr() == 1 && row1HasEnemy) {
					Star* star = new Star();
					star->setTranslateX(shooter->getPosX() + 40);
					star->setTranslateY(shooter->getPosY());
					
					star->setColor(shooter->getShooterColor());
					
					shootingStarsVector.push_back(star);
					shooter->setReloadTime(0);
				}
				else if (shooter->getRowNr() == 2 && row2HasEnemy) {
					Star* star = new Star();
					star->setTranslateX(shooter->getPosX() + 40);
					star->setTranslateY(shooter->getPosY());
					star->setColor(shooter->getShooterColor());
					shootingStarsVector.push_back(star);
					shooter->setReloadTime(0);

				}
				else if (shooter->getRowNr() == 3 && row3HasEnemy) {
					Star* star = new Star();
					star->setTranslateX(shooter->getPosX() + 40);
					star->setTranslateY(shooter->getPosY());
					star->setColor(shooter->getShooterColor());
					shootingStarsVector.push_back(star);
					shooter->setReloadTime(0);

				}
			}

			// check if hexagons are colliding with shooters
			for (auto hexagon : hexagonsVector) {
				if (hexagon->getTranslateX() <= shooter->getPosX() + 25 && hexagon->getTranslateX() >= shooter->getPosX() - 25 &&
					hexagon->getTranslateY() <= shooter->getPosY() + 25 && hexagon->getTranslateY() >= shooter->getPosY() - 25) {
					iterator->setHasShooter(false);
					iterator->setDisappearShooter(true);
					break;
				}

			}

		}


	}

	for (auto hexagon : hexagonsVector) {
		// inform the rest of the program that there is an enemy in the row
		if (hexagon->getRowNr() == 1) {
			row1HasEnemy = true;
		}
		else if (hexagon->getRowNr() == 2) {
			row2HasEnemy = true;
		}
		else if (hexagon->getRowNr() == 3) {
			row3HasEnemy = true;
		}
		// check if a hexagon has reached the red base
		if (hexagon->getTranslateX() <= 5) {
			if (hexagon->getRowNr() == 1) {
				row1HasEnemy = false;
			}
			else if (hexagon->getRowNr() == 2) {
				row2HasEnemy = false;
			}
			else if (hexagon->getRowNr() == 3) {
				row3HasEnemy = false;
			}
			hexagonsVector.erase(std::remove(hexagonsVector.begin(), hexagonsVector.end(), hexagon), hexagonsVector.end());
			numHexagons--;
			remainingLivesVector.pop_back();
			numLives--;
			if (numLives == 0) {
				cout << "GAME OVER!" << endl;
				exit(0);
			}
		}
		if (hexagon->getDisappearHexagon()) {
			//when the hexagon is hit by a star, it shrinks until it disappears
			if (hexagon->getScaleX() < 0.1 && hexagon->getScaleY() < 0.1) {
				if (hexagon->getRowNr() == 1) {
					row1HasEnemy = false;
				}
				else if (hexagon->getRowNr() == 2) {
					row2HasEnemy = false;
				}
				else if (hexagon->getRowNr() == 3) {
					row3HasEnemy = false;
				}
				hexagonsVector.erase(std::remove(hexagonsVector.begin(), hexagonsVector.end(), hexagon), hexagonsVector.end());
				numHexagons--;
				break;
			}
			else { // shrink the hexagon
				hexagon->setScaleX(hexagon->getScaleX() - deltaTimeSeconds);
				hexagon->setScaleY(hexagon->getScaleY() - deltaTimeSeconds);
				modelMatrix = glm::mat3(1);
				modelMatrix *= transform2D::Translate(hexagon->getTranslateX(), hexagon->getTranslateY());
				modelMatrix *= transform2D::Scale(hexagon->getScaleX(), hexagon->getScaleY());
				RenderMesh2D(meshes["hexagon"], shaders["VertexColor"], modelMatrix);
			}
		}
		else { // render the moving hexagon
			modelMatrix = glm::mat3(1);
			modelMatrix *= transform2D::Translate(hexagon->getTranslateX(), hexagon->getTranslateY());
			hexagon->setTranslateX(hexagon->getTranslateX() - deltaTimeSeconds * 50);
			RenderMesh2D(meshes[hexagon->getColor() + "Hexagon"], shaders["VertexColor"], modelMatrix);
		}
	}

	for (auto star : shootingStarsVector) {
		// render the moving stars
		modelMatrix = glm::mat3(1);
		modelMatrix *= transform2D::Translate(star->getTranslateX(), star->getTranslateY());
		modelMatrix *= transform2D::Rotate(star->getAngularStep());
		star->setAngularStep(star->getAngularStep() - deltaTimeSeconds * 3);
		star->setTranslateX(star->getTranslateX() + deltaTimeSeconds * 150);
		RenderMesh2D(meshes[star->getColor() + "Star"], shaders["VertexColor"], modelMatrix);

		for (auto hexagon : hexagonsVector) {
			// check if any star has hit a hexagon
			if (hexagon->getTranslateX() <= star->getTranslateX() + 25 && hexagon->getTranslateX() >= star->getTranslateX() - 25 &&
				hexagon->getTranslateY() <= star->getTranslateY() + 25 && hexagon->getTranslateY() >= star->getTranslateY() - 25) {
				// remove the star and decrease the hexagon's lives if the colors match
				if (hexagon->getColor() == star->getColor()) {
					hexagon->setLives(hexagon->getLives() - 1);
				}
				shootingStarsVector.erase(std::remove(shootingStarsVector.begin(), shootingStarsVector.end(), star), shootingStarsVector.end());
				// if the hexagon has no more lives, set it to disappear
				if (hexagon->getLives() == 0) {
					hexagon->setDisappearHexagon(true);
				}

			}
		}
	}
	// render the shooter that is being dragged to the cursor's position
	if (draggedShooter != nullptr) {
		modelMatrix = glm::mat3(1);
		modelMatrix *= transform2D::Translate(draggedShooter->getPosX(), draggedShooter->getPosY());
		RenderMesh2D(meshes[draggedShooter->getShooterColor() + "Shooter"], shaders["VertexColor"], modelMatrix);
	}

	// after 4 seconds spawn a pink star and a hexagon
	if (timeElapsed >= 4.0f) {
		timeElapsed = 0.0f;
		if (numPinkStars < 6) {
			float randomX = static_cast<float>(rand() % 1000);
			float randomY = static_cast<float>(rand() % 600);
			Star* star = new Star();
			star->setStarPos(randomX, randomY, 0.2f);
			pinkStarsVector.push_back(star);
			numPinkStars += 1;
		}
		if (numHexagons < 3) {
			Hexagon* hexagon = new Hexagon();
			int i = rand() % 3;
			float hexagonYPos = hexagonsYPositions[i];
			hexagon->setRowNr(3 - i);
			hexagon->setTranslateX(1280);
			hexagon->setTranslateY(hexagonYPos);
			int j = rand() % 4;
			hexagon->setColor(hexagonsColors[j]);
			hexagonsVector.push_back(hexagon);
			numHexagons += 1;
		}
	}

}

void Tema1::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
	int cursorPosX = mouseX;
	int cursorPosY = 720 - mouseY;
	if (draggedShooter != nullptr) {
		// Update the position of the dragged shooter
		draggedShooter->setShooterPos(cursorPosX, cursorPosY, 1.0f);
	}
}


void Tema1::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
	int cursorPosX = mouseX;
	int cursorPosY = 720 - mouseY;
	if (button == 1) {
		int pointsRemaining = pointStarsVector.size();
		// Check which type of shooter the player wants to drag and check if they have the required number of stars
		if (cursorPosX >= 50 && cursorPosX <= 150 && cursorPosY >= 600 && cursorPosY <= 700 && pointsRemaining >= 1) {
			draggedShooter = new Shooter();
			draggedShooter->setShooterPos(cursorPosX, cursorPosY, 0.3f);
			draggedShooter->setShooterColor("orange");
		}
		else if (cursorPosX >= 250 && cursorPosX <= 350 && cursorPosY >= 600 && cursorPosY <= 700 && pointsRemaining >= 2) {
			draggedShooter = new Shooter();
			draggedShooter->setShooterPos(cursorPosX, cursorPosY, 0.3f);
			draggedShooter->setShooterColor("blue");
		}
		else if (cursorPosX >= 450 && cursorPosX <= 550 && cursorPosY >= 600 && cursorPosY <= 700 && pointsRemaining >= 2) {
			draggedShooter = new Shooter();
			draggedShooter->setShooterPos(cursorPosX, cursorPosY, 0.3f);
			draggedShooter->setShooterColor("yellow");
		}
		else if (cursorPosX >= 650 && cursorPosX <= 750 && cursorPosY >= 600 && cursorPosY <= 700 && pointsRemaining >= 3) {
			draggedShooter = new Shooter();
			draggedShooter->setShooterPos(cursorPosX, cursorPosY, 0.3f);
			draggedShooter->setShooterColor("purple");
		}

		// loop through the pink stars and check if the player clicked on one
		std::vector<Star*>::iterator iter = pinkStarsVector.begin();
		while (iter != pinkStarsVector.end()) {
			Star* star = *iter;
			glm::vec3 position = star->getStarPos();
			if (cursorPosX >= position.x - 25 && cursorPosX <= position.x + 25 &&
				cursorPosY >= position.y - 25 && cursorPosY <= position.y + 25) {
				iter = pinkStarsVector.erase(iter);
				numPinkStars -= 1;
				// only add a point star if the player has less than 9
				if (pointStarsVector.size() < maxPointStars) {
					Star* pointStar = new Star();
					pointStar->setStarPos(currentPointStarPos + 50, 575, 0.2f);
					currentPointStarPos += 50;
					pointStarsVector.push_back(pointStar);
				}
			}
			else {
				++iter;
			}
		}
	}
	if(button == 2) {
		for (auto square : gridSquaresVector) {
			// check if the player clicked on a square that has a shooter
			if (cursorPosX <= square->getSquarePos().x + 100 && cursorPosY <= square->getSquarePos().y + 100 &&
				cursorPosX >= square->getSquarePos().x && cursorPosY >= square->getSquarePos().y && square->getHasShooter()) {
				square->setDisappearShooter(true);
				break;
			}
		}
	}
}

void Tema1::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
	int cursorPosX = mouseX;
	int cursorPosY = 720 - mouseY;

	if (draggedShooter != nullptr) {
		for (auto square : gridSquaresVector) {
			// check if the player released the shooter on a square that doesn't have a shooter
			if (cursorPosX <= square->getSquarePos().x + 100 && cursorPosY <= square->getSquarePos().y + 100 &&
				cursorPosX >= square->getSquarePos().x && cursorPosY >= square->getSquarePos().y && !square->getHasShooter()) {

				// remove the amount of stars required for the shooter
				if (draggedShooter->getShooterColor() == "orange") {
					pointStarsVector.pop_back();
					currentPointStarPos -= 50;
				}
				else if (draggedShooter->getShooterColor() == "blue") {
					pointStarsVector.pop_back();
					pointStarsVector.pop_back();
					currentPointStarPos -= 100;
				}
				else if (draggedShooter->getShooterColor() == "yellow") {
					pointStarsVector.pop_back();
					pointStarsVector.pop_back();
					currentPointStarPos -= 100;
				}
				else if (draggedShooter->getShooterColor() == "purple") {
					pointStarsVector.pop_back();
					pointStarsVector.pop_back();
					pointStarsVector.pop_back();
					currentPointStarPos -= 150;
				}
				square->setHasShooter(true);
				draggedShooter->setShooterPos(square->getSquarePos().x + 40, square->getSquarePos().y + 50, 0.3f);

				Shooter* shooter = new Shooter();
				shooter->setShooterPos(square->getSquarePos().x + 40, square->getSquarePos().y + 50, 0.3f);
				shooter->setShooterColor(draggedShooter->getShooterColor());
				shooter->setRowNr(square->getRowNr());
				square->setShooter(shooter);

				break;
			}
		}

		draggedShooter = nullptr;
	}
}

void Tema1::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) {}

void Tema1::OnWindowResize(int width, int height) {}

void Tema1::FrameEnd() {}

void Tema1::OnInputUpdate(float deltaTime, int mods) {}

void Tema1::OnKeyPress(int key, int mods) {}

void Tema1::OnKeyRelease(int key, int mods) {}