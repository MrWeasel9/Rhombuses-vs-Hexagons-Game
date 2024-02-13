#pragma once

#include <string>

#include "core/gpu/mesh.h"
#include "utils/glm_utils.h"


namespace object2D
{
    Mesh* CreateSquare(const std::string &name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill = false);

    Mesh* CreateRectangle(const std::string& name, glm::vec3 leftBottomCorner, float width, float height, glm::vec3 color, bool fill = false);

    Mesh* CreateGunShape(const std::string& name,glm::vec3 bottomCenter, float rhombusWidth, float rhombusHeight, glm::vec3 color, bool fill = false);
    
    Mesh* CreateStarShape(const std::string& name, glm::vec3 center, float innerRadius, float outerRadius, glm::vec3 color, bool fill);

    Mesh* CreateOverlappingHexagons(const std::string& name, glm::vec3 center, float outerHexRadius, float innerHexRadius, glm::vec3 outerColor, glm::vec3 innerColor);

}
