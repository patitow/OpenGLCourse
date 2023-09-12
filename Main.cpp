#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

int main() {
	// Initialize glfw
	glfwInit();
	// Communicates to glfw which versions and profile of OpenGl are being used.
	// Core -> Modern Functions, Compatibility -> Modern and Older functions
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); 

	// Creates the GLFW Window Object
	GLFWwindow* window = glfwCreateWindow(1280, 720, "OpenGL FreeCodeCamp Course", NULL, NULL);
	// If there was any error on the window creation, terminate and return.
	if (window == NULL) { 
		std::cout << "Failed to create a GLFW window correctly" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window); // mounts the current context on the screen using the window created

	// let's start coloring and composing the screen using glad and openGL
	gladLoadGL();
	glViewport(0, 0, 1280, 720);

	// on this application, we will use 2 frame buffers, the front and the back one
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(window); // swaps between the previous and the next buffer

	// application loop, game loop, etc
	while (!glfwWindowShouldClose(window)){
		glfwPollEvents();
	}
	glfwTerminate();
	return 0; 
}

// stopped at 14:51