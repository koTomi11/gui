#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "Render.h"

#include "Window.h"
#include <GuiContext.h>
#include <GuiItem.h>

int main() {
	
	Window w(600,800);
	
	Render r;
	r.initalize(w.getWidth(), w.getHeight());
	int font = r.loadFont("fonts/Montserrat-Italic-VariableFont_wght.ttf");
	
	GuiContext::RENDER = &r;
	GuiContext::WINDOW = &w;

	GuiItem item(40,40,50,50);
	
	while (!w.isClose()) {
		
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		w.poolEvent();
		
		
		item.draw();
		item.update();
		
		r.endFrame();

		w.swapBuffers();
	}

	
	return 0;
}