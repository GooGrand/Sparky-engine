#include "src\graphics\window.h"
#include "src/maths/maths.h"
#include <iostream>

int main()
{
	using namespace sparky;
	using namespace graphics;
	using namespace maths;

	Window window("Sparky!", 800, 600);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	vec3 a(1.0f, 2.0f, 5.0f);
	vec3 b(2, 4, 6);
	vec3 c = a + b;

	while (!window.closed())
	{
		window.clear();
	
		std::cout << c << std::endl;
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