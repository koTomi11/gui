#include "Window.h"
#include <iostream>



void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) 
{
	Window* w = static_cast<Window*>(glfwGetWindowUserPointer(window));
	switch (action)
	{
	case GLFW_PRESS:   w->m_currentKeyDown[key] = true; break;
	case GLFW_RELEASE:  w->m_currentKeyDown[key] = false; break;
	}

}


void cursor_position_callback(GLFWwindow* window, double xpos, double ypos) 
{
	Window* w = static_cast<Window*>(glfwGetWindowUserPointer(window));
	w->m_mouseX = (int)xpos;
	w->m_mouseY = (int)ypos;

}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{

	Window* w = static_cast<Window*>(glfwGetWindowUserPointer(window));

	switch (action)
	{
	case GLFW_PRESS:   w->m_mouseButton[button] = true; break;
	case GLFW_RELEASE:  w->m_mouseButton[button] = false; break;
	}
}

void character_callback(GLFWwindow* window, unsigned int codepoint) 
{

	Window* w = static_cast<Window*>(glfwGetWindowUserPointer(window));
	w->m_typedText.push_back((char)codepoint);
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	Window* w = static_cast<Window*>(glfwGetWindowUserPointer(window));
}

void drop_callback(GLFWwindow* window, int count, const char** paths)
{

	Window* w = static_cast<Window*>(glfwGetWindowUserPointer(window));
	std::cout << "Behuzott elemek szama: " << count << std::endl;

	for (int i = 0; i < count; i++)
	{
		// A paths[i] tartalmazza a teljes eleresi utat (pl. "C:\\Users\\Nev\\kep.png")
		std::cout << "  [" << i << "]: " << paths[i] << std::endl;
	}
}

Window::Window(int width, int height)
{

	m_width = width; m_height = height;
	memset(m_mouseButton, 0, 3);
	memset(m_currentKeyDown, 0, 255);

	if (!glfwInit()) {
		std::cerr << "Nem sikerült inicializálni a GLFW-t!" << std::endl;
		
	}

	glfwWindowHint(GLFW_MAXIMIZED, GLFW_FALSE);
	glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	m_window = glfwCreateWindow(m_width, m_height, "OpenGL + GLAD Teszt", NULL, NULL);
	if (!m_window) {
		std::cerr << "Nem sikerült létrehozni a GLFW ablakot!" << std::endl;
		glfwTerminate();
		
	}
	glfwSetWindowUserPointer(m_window, this);
	glfwSetWindowPos(m_window, 200, 100);

	glfwSetKeyCallback(m_window, key_callback);
	glfwSetCursorPosCallback(m_window, cursor_position_callback);
	glfwSetMouseButtonCallback(m_window, mouse_button_callback);
	glfwSetCharCallback(m_window, character_callback);
	glfwSetScrollCallback(m_window, scroll_callback);
	glfwSetDropCallback(m_window, drop_callback);

	glfwMakeContextCurrent(m_window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cerr << "Nem sikerült inicializálni a GLAD-et!" << std::endl;
		glfwTerminate();
		
	}

	std::cout << "OpenGL Verzio: " << glGetString(GL_VERSION) << std::endl;
	std::cout << "Videokartya: " << glGetString(GL_RENDERER) << std::endl;

	glViewport(0, 0, getWidth(), getHeight());

}

bool Window::isMouseLeftClick()
{
	return m_mouseButton[0];
}

bool Window::isMouseRightClick()
{
	return m_mouseButton[1];
}

int Window::getMouseX()
{
	return m_mouseX;
}

int Window::getMouseY()
{
	return m_mouseY;
}

void Window::poolEvent()
{
	glfwPollEvents();
}

void Window::swapBuffers()
{
	glfwSwapBuffers(m_window);
}

bool Window::isClose()
{
	return glfwWindowShouldClose(m_window);
}

void Window::drawBuffer(unsigned char* pixels)
{
	glRasterPos2f(-1, -1);
	glDrawPixels(m_width, m_height, GL_RGB, GL_UNSIGNED_BYTE, pixels);
}

int Window::getWidth()
{
	int width, height;
	glfwGetWindowSize(m_window, &width, &height);
	return width;
}

int Window::getHeight()
{
	int width, height;
	glfwGetWindowSize(m_window, &width, &height);
	return height;
}