#include "Laborator1.h"

#include <vector>
#include <iostream>

#include <Core/Engine.h>

using namespace std;

// Order of function calling can be seen in "Source/Core/World.cpp::LoopUpdate()"
// https://github.com/UPB-Graphics/Framework-EGC/blob/master/Source/Core/World.cpp

int task3 = 0;
int task4 = 0;
int counter = 0;
float posX, posY, posZ = 0.f;

Laborator1::Laborator1()
{
}

Laborator1::~Laborator1()
{
}

void Laborator1::Init()
{
	// Load a mesh from file into GPU memory
	{
		Mesh* mesh = new Mesh("box");
		mesh->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "box.obj");
		meshes[mesh->GetMeshID()] = mesh;

		Mesh* mesh1 = new Mesh("sphere");
		mesh1->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "sphere.obj");
		meshes[mesh1->GetMeshID()] = mesh1;

		Mesh* mesh2 = new Mesh("teapot");
		mesh2->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "teapot.obj");
		meshes[mesh2->GetMeshID()] = mesh2;

	}
}

void Laborator1::FrameStart()
{

}

void Laborator1::Update(float deltaTimeSeconds)
{
	glm::ivec2 resolution = window->props.resolution;

	// sets the clear color for the color buffer
	glClearColor(0, 0, 0, 1);

	//TASK3
	if (task3 == 1) {
		// sets the clear color for the color buffer to yellow
		glClearColor(0, 0, 1, 1);
	}

	// clears the color buffer (using the previously set color) and depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	// sets the screen area where to draw
	glViewport(0, 0, resolution.x, resolution.y);


	// render the object
	//TASK 5
	RenderMesh(meshes["box"], glm::vec3(posX, posY, posZ), glm::vec3(0.5f));
	

	// render the object again but with different properties
	RenderMesh(meshes["box"], glm::vec3(-1, 0.5f, 0));

	//TASK 2
	// render another object: a sphere
	//TASK 4 - change the object
	if (task4 == 0) {
		thirdObject = "sphere";
	}
	else {
		changeObj();
	}
	RenderMesh(meshes[thirdObject], glm::vec3(-3, 0.5f, 0));

}

void Laborator1::FrameEnd()
{
	DrawCoordinatSystem();
}

// Read the documentation of the following functions in: "Source/Core/Window/InputController.h" or
// https://github.com/UPB-Graphics/Framework-EGC/blob/master/Source/Core/Window/InputController.h

void Laborator1::OnInputUpdate(float deltaTime, int mods)
{
	// treat continuous update based on input
	if (!window->MouseHold(GLFW_MOUSE_BUTTON_RIGHT))
	{
		//TASK 5

		if (window->KeyHold(GLFW_KEY_A))
		{
			posX -= deltaTime;
		}
		if (window->KeyHold(GLFW_KEY_Q))
		{
			posX += deltaTime;
		}
		if (window->KeyHold(GLFW_KEY_S))
		{
			posY -= deltaTime;
		}
		if (window->KeyHold(GLFW_KEY_W))
		{
			posY += deltaTime;
		}
		if (window->KeyHold(GLFW_KEY_E))
		{
			posZ -= deltaTime;
		}
		if (window->KeyHold(GLFW_KEY_D))
		{
			posZ += deltaTime;
		}
	}
};

void Laborator1::OnKeyPress(int key, int mods)
{
	// add key press event
	if (key == GLFW_KEY_F) {
		task3 = 1;
	}

	if (key == GLFW_KEY_P) {
		task4 = 1;
		counter = (counter + 1) % 3;
	}
};

void Laborator1::OnKeyRelease(int key, int mods)
{
	// add key release event
};

void Laborator1::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
	// add mouse move event
};

void Laborator1::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
	// add mouse button press event
};

void Laborator1::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
	// add mouse button release event
}

void Laborator1::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
	// treat mouse scroll event
}

void Laborator1::OnWindowResize(int width, int height)
{
	// treat window resize event
}

void Laborator1::changeObj() {
	if (counter == 0) {
		thirdObject = "sphere";
		return;
	}
	if (counter == 1) {
		thirdObject = "box";
		return;
	}
	if (counter == 2) {
		thirdObject = "teapot";
		return;
	}
}