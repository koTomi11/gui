#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "Render.h"

#include "Window.h"
#include <GuiContext.h>
#include <GuiItem.h>
#include <GuiPanel.h>

int main() {
	
	Window w(800,600);
	
	Render r;
	r.initalize(w.getWidth(), w.getHeight());
	int font = r.loadFont("fonts/Montserrat-Italic-VariableFont_wght.ttf");
	
	GuiContext::RENDER = &r;
	GuiContext::WINDOW = &w;

	GuiItem item(40,40,50,50);

	GuiPanel panel(0, 0, w.getWidth(), w.getHeight());
	
	while (!w.isClose()) {
		
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		w.poolEvent();
		
		
		panel.draw();
		panel.update();
		
		r.endFrame();

		w.swapBuffers();
	}

	
	return 0;
}