#include <iostream>
#include "vulkan/vulkan.h"
#include <GLFW/glfw3.h>
#include "glm/glm.hpp"

int main()
{
    GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
	{
		std::cerr << "Failed to initialize glfw\n";
		return -1;
	}

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(1280, 720, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		std::cerr << "Failed to create window\n";
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();

    return 0;
}