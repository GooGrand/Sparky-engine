#include "src\graphics\window.h"
#include <iostream>
int main()
{
	using namespace sparky;
	using namespace graphics;
	Window window("Sparky!", 800, 600);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);
	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	while (!window.closed())
	{
		window.clear();
		if (window.isKeyPressed(GLFW_KEY_A)) 
		{
			std::cout << "Pressed A" << std::endl;
		}		
		if (window.isMouseButtonPressed(GLFW_MOUSE_BUTTON_LEFT)) 
		{
			std::cout << "Pressed A" << std::endl;
		}		
		double x, y;
		window.getMousePosition(x, y);
		std::cout << x << ", " << y << std::endl;
#if 1
		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.0f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glEnd();
#else
		glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
#endif
		window.update(); 
	}
	return 0;
}