#pragma once

#include "components/simple_scene.h"
#include "Shooter.h"
#include "Star.h"
#include "Square.h"
#include "Hexagon.h"
#include <string>

namespace m1
{
    class Tema1 : public gfxc::SimpleScene
    {
    public:
        Tema1();
        ~Tema1();

        void Init() override;

    private:
        void FrameStart() override;
        void Update(float deltaTimeSeconds) override;
        void FrameEnd() override;

        void OnInputUpdate(float deltaTime, int mods) override;
        void OnKeyPress(int key, int mods) override;
        void OnKeyRelease(int key, int mods) override;
        void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
        void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
        void OnWindowResize(int width, int height) override;
        void CreateMeshes(glm::vec3 center, float squareSide, float starSize, float hexRadius);
        void RenderMeshes();

    protected:
        // colors
        glm::vec3 orange = glm::vec3(1.0f, 0.5f, 0.0f);
        glm::vec3 yellow = glm::vec3(1.0f, 1.0f, 0.0f);
        glm::vec3 green = glm::vec3(0.4f, 0.9f, 0.4f);
        glm::vec3 blue = glm::vec3(0.0f, 0.0f, 1.0f);
        glm::vec3 purple = glm::vec3(0.5f, 0.0f, 1.0f);
        glm::vec3 red = glm::vec3(1.0f, 0.0f, 0.0f);
        glm::vec3 white = glm::vec3(1.0f, 1.0f, 1.0f);
        glm::vec3 pink = glm::vec3(1.0f, 0.0f, 1.0f);
        glm::vec3 black = glm::vec3(0.0f, 0.0f, 0.0f);
        glm::vec3 grey = glm::vec3(0.2f, 0.2f, 0.2f);
        glm::vec3 turqoise = glm::vec3(0.0f, 1.0f, 1.0f);

        glm::vec3 center = glm::vec3(0, 0, 0);
        glm::mat3 modelMatrix;
       
        float timeElapsed = 0.0f;
        float squareSide = 100;
        float starSize = 20;
        float hexRadius = 35;
        float currentPointStarPos;

        int numPinkStars = 5;
        int numPointStars = 5;
        int maxPointStars = 9;
        int numHexagons = 0;
        int numSquares = 9;
        int numLives = 3;
       
        bool row1HasEnemy = false;
        bool row2HasEnemy = false;
        bool row3HasEnemy = false;

        Shooter* draggedShooter = nullptr;

        std::vector<Star*> pinkStarsVector;
        std::vector<Star*> shootingStarsVector;
        std::vector<Star*> pointStarsVector;
       
        std::vector<Shooter*> gridShootersVector;
        std::vector<Hexagon*> hexagonsVector;
        std::vector<Square*> gridSquaresVector;
        std::vector<Square*> remainingLivesVector;
        
        std::vector<float> hexagonsYPositions = { 65, 200, 335 };
        std::vector<std::string> hexagonsColors = { "orange", "blue", "yellow", "purple" };
        std::vector<glm::vec3> squarePositions = {
            { 85, 285, 0 },     // Top-Left square
            { 225, 285, 0 },    // Top-Center square
            { 365, 285, 0 },    // Top-Right square
            { 85, 150, 0 },     // Middle-Left square
            { 225, 150, 0 },    // Middle-Center square
            { 365, 150, 0 },    // Middle-Right square
            { 85, 15, 0 },      // Bottom-Left square
            { 225, 15, 0 },     // Bottom-Center square
            { 365, 15, 0 }      // Bottom-Right square
        };
    };
}
