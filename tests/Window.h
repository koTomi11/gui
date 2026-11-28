#pragma once

#include <glad/glad.h>   

#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>

#include <IWindow.h>
#include <vector>
#include <string>

class Window : public IWindow
{

public:

	GLFWwindow* m_window;
	int m_width, m_height;
	
	std::string m_typedText;
	int m_mouseX, m_mouseY;
	bool m_lastKeyDown[255];
	bool m_currentKeyDown[255];
	bool m_mouseButton[3];
	bool m_lastMouseButton[3];


	Window(int width, int height);

	void poolEvent();
	void swapBuffers();
	bool isClose();
	void drawBuffer(unsigned char* pixels);

	int getWidth() override;
	int getHeight() override;

	bool isMouseLeftClick() override;
	bool isMouseRightClick() override;

	int getMouseX() override;
	int getMouseY() override;
};