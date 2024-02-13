#include "object2D.h"

#include <vector>

#include "core/engine.h"
#include "utils/gl_utils.h"

Mesh* object2D::CreateSquare(
	const std::string& name,
	glm::vec3 leftBottomCorner,
	float length,
	glm::vec3 color,
	bool fill)
{
	glm::vec3 corner = leftBottomCorner;

	std::vector<VertexFormat> vertices =
	{
		VertexFormat(corner, color),
		VertexFormat(corner + glm::vec3(length, 0, 0), color),
		VertexFormat(corner + glm::vec3(length, length, 0), color),
		VertexFormat(corner + glm::vec3(0, length, 0), color)
	};

	Mesh* square = new Mesh(name);
	std::vector<unsigned int> indices = { 0, 1, 2, 3 };

	if (!fill) {
		square->SetDrawMode(GL_LINE_LOOP);
	}
	else {
		// Draw 2 triangles. Add the remaining 2 indices
		indices.push_back(0);
		indices.push_back(2);
	}

	square->InitFromData(vertices, indices);
	return square;
}

Mesh* object2D::CreateRectangle(
	const std::string& name,
	glm::vec3 leftBottomCorner,
	float width,
	float height,
	glm::vec3 color,
	bool fill)
{
	glm::vec3 corner = leftBottomCorner;

	std::vector<VertexFormat> vertices =
	{
		VertexFormat(corner, color),
		VertexFormat(corner + glm::vec3(width, 0, 0), color),
		VertexFormat(corner + glm::vec3(width, height, 0), color),
		VertexFormat(corner + glm::vec3(0, height, 0), color)
	};

	Mesh* rectangle = new Mesh(name);
	std::vector<unsigned int> indices = { 0, 1, 2, 3 };

	if (!fill) {
		rectangle->SetDrawMode(GL_LINE_LOOP);
	}
	else {
		// Draw 2 triangles. Add the remaining 2 indices
		indices.push_back(0);
		indices.push_back(2);
	}

	rectangle->InitFromData(vertices, indices);
	return rectangle;
}

Mesh* object2D::CreateGunShape(
	const std::string& name,
	glm::vec3 bottomCenter,
	float rhombusWidth,
	float rhombusHeight,
	glm::vec3 color,
	bool fill)
{
	glm::vec3 center = bottomCenter;

	// Calculate the vertices for the rhombus
	std::vector<VertexFormat> verticesRhombus =
	{
		VertexFormat(center, color), // H 0
		VertexFormat(center + glm::vec3(0, rhombusHeight / 2, 1), color), // C 1
		VertexFormat(center + glm::vec3(-rhombusWidth / 2, 0, 1), color), // D 2
		VertexFormat(center + glm::vec3(0, -rhombusHeight / 2, 1), color), // A 3
		VertexFormat(center + glm::vec3(rhombusWidth / 2, -rhombusHeight / 6, 1), color), // E 4
		VertexFormat(center + glm::vec3(rhombusWidth / 2, rhombusHeight / 6, 1), color), // B 5
		VertexFormat(center + glm::vec3(rhombusWidth, -rhombusHeight / 6, 1), color), // F 6
		VertexFormat(center + glm::vec3(rhombusWidth, rhombusHeight / 6, 1), color), // G 7
	};

	Mesh* gunShape = new Mesh(name);
	std::vector<unsigned int> indices = {
										   0,1,2,
										   0,2,3,
										   0,3,4,
										   0,4,5,
										   0,5,1,
										   5,6,4,
										   5,7,6,
	};

	// Define the indices for the shape

	if (!fill) {
		gunShape->SetDrawMode(GL_LINE_LOOP);
	}
	else {
		gunShape->SetDrawMode(GL_TRIANGLE_STRIP);
	}

	gunShape->InitFromData(verticesRhombus, indices);

	return gunShape;
}

Mesh* object2D::CreateStarShape(
	const std::string& name,
	glm::vec3 center,
	float innerRadius,
	float outerRadius,
	glm::vec3 color,
	bool fill)
{
	// Calculate the vertices for the star
	std::vector<VertexFormat> verticesStar;
	const int numPoints = 5;
	constexpr float rotationAngle = glm::radians(36.0f);
	float currentAngle = -glm::radians(90.0f); // Start with the top point centered
	for (int i = 0; i < numPoints * 2; i++) {
		float radius = (i % 2 == 0) ? innerRadius : outerRadius;
		glm::vec3 vertexPosition(center.x + radius * std::cos(currentAngle),
			center.y + radius * std::sin(currentAngle),
			center.z + 4.0f);
		verticesStar.push_back(VertexFormat(vertexPosition, color));
		currentAngle += rotationAngle;
	}

	Mesh* starShape = new Mesh(name);
	std::vector<unsigned int> indices;
	for (int i = 0; i < numPoints * 2; i++) {
		indices.push_back(i);
	}

	// Define the indices for the shape
	if (!fill) {
		starShape->SetDrawMode(GL_LINE_LOOP);
	}
	else {
		starShape->SetDrawMode(GL_TRIANGLE_FAN);
	}

	starShape->InitFromData(verticesStar, indices);

	return starShape;
}

Mesh* object2D::CreateOverlappingHexagons(
	const std::string& name,
	glm::vec3 center,
	float outerHexRadius,
	float innerHexRadius,
	glm::vec3 outerColor,
	glm::vec3 innerColor)
{

	std::vector<VertexFormat> verticesOuterHexagon =
	{

		VertexFormat(center + glm::vec3(-outerHexRadius / 2, outerHexRadius, 0.1f), outerColor),
		VertexFormat(center + glm::vec3(outerHexRadius / 2,   outerHexRadius, 0.1f), outerColor),
		VertexFormat(center + glm::vec3(outerHexRadius,   0.0f, 0.0f), outerColor),
		VertexFormat(center + glm::vec3(outerHexRadius / 2,   -outerHexRadius, 0.1f), outerColor),
		VertexFormat(center + glm::vec3(-outerHexRadius / 2,  -outerHexRadius, 0.1f), outerColor),
		VertexFormat(center + glm::vec3(-outerHexRadius,   0.0f, 0.1f), outerColor),
	};
	std::vector<VertexFormat> verticesInnerHexagon =
	{
		VertexFormat(center, innerColor),
		VertexFormat(center + glm::vec3(-innerHexRadius / 2, innerHexRadius, 0.1f), innerColor),
		VertexFormat(center + glm::vec3(innerHexRadius / 2,   innerHexRadius, 0.1f), innerColor),
		VertexFormat(center + glm::vec3(innerHexRadius,   0.0f, 0.1f), innerColor),
		VertexFormat(center + glm::vec3(innerHexRadius / 2,   -innerHexRadius, 0.1f), innerColor),
		VertexFormat(center + glm::vec3(-innerHexRadius / 2,  -innerHexRadius, 0.1f), innerColor),
		VertexFormat(center + glm::vec3(-innerHexRadius,   0.0f, 0.1f), innerColor),
	};

	Mesh* hexagonsShape = new Mesh(name);
	std::vector<unsigned int> indices = { 6,7,8,
										 6,8,9,
										 6,9,10,
										 6,10,11,
										 6,11,12,
										 6,12,7,6,6,6,
										 0,1,2,3,4,5,0 };

	// Define the indices for the shape
	hexagonsShape->SetDrawMode(GL_TRIANGLE_FAN);

	// Combine the vertices and indices for both hexagons
	verticesOuterHexagon.insert(verticesOuterHexagon.end(), verticesInnerHexagon.begin(), verticesInnerHexagon.end());

	hexagonsShape->InitFromData(verticesOuterHexagon, indices);

	return hexagonsShape;
}
























