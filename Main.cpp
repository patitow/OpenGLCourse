#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

// Vertex Shader source code
const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
//Fragment Shader source code
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);\n"
"}\n\0";

int main() {
	// Initialize glfw
	glfwInit();

	// Communicates to glfw which versions and profile of OpenGl are being used.
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//		Core -> Modern Functions, Compatibility -> Modern and Older functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Creates the GLFW Window Object
	GLFWwindow* window = glfwCreateWindow(1280, 720, "OpenGL FreeCodeCamp Course", NULL, NULL);
	//		If there was any error on the window creation, terminate and return.
	if (window == NULL) { 
		std::cout << "Failed to create a GLFW window correctly" << std::endl;
		glfwTerminate();
		return -1;
	}
	//		Mounts the current context on the screen using the window created
	glfwMakeContextCurrent(window); 

	// Let's start coloring and composing the screen using glad and openGL
	gladLoadGL();
	glViewport(0, 0, 1280, 720);

	// Initial Vertices
	GLfloat vertices[] = {
		-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
		0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
		0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f,
	};

	// Shader
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	GLuint shaderProgram = glCreateProgram();

	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, vertexShader);
	glLinkProgram(shaderProgram);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);


	// Vertex Buffer Objects (VBO) and Vertex Array Objects (pointers to the vbos)
	GLuint VertexArrayObject, VertexBufferObject;

	glGenVertexArrays(1, &VertexArrayObject);
	glGenBuffers(1, &VertexBufferObject);

	glBindBuffer(GL_ARRAY_BUFFER, VertexArrayObject);

	glBindBuffer(GL_ARRAY_BUFFER, VertexBufferObject);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0 );


	// Frame Buffers
	//		On this application, we will use 2 frame buffers, the front and the back one
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	// swaps between the previous and the next buffer
	glfwSwapBuffers(window); 


	//		Start of the Application loop, game loop, etc
	while (!glfwWindowShouldClose(window)){
		glfwPollEvents();
	}
	glfwTerminate();
	return 0; 
}

// stopped at 14:51