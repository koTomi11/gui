#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main() {
	// 1. GLFW inicializálása
	if (!glfwInit()) {
		std::cerr << "Hiba: Nem sikerult inicializalni a GLFW-t!" << std::endl;
		return -1;
	}

	// OpenGL 3.3 Core profil beállítása
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// 2. Ablak létrehozása
	GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL + GLAD Teszt", nullptr, nullptr);
	if (!window) {
		std::cerr << "Hiba: Nem sikerult letrehozni a GLFW ablakot!" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	// 3. GLAD inicializálása (OpenGL függvénymutatók betöltése)
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cerr << "Hiba: Nem sikerult inicializalni a GLAD-et!" << std::endl;
		glfwTerminate();
		return -1;
	}

	// Ha minden sikeres, kiírjuk a verziót és a videókártya adatait
	std::cout << "Sikeres inicializalas!" << std::endl;
	std::cout << "OpenGL verzio: " << glGetString(GL_VERSION) << std::endl;
	std::cout << "GPU: " << glGetString(GL_RENDERER) << std::endl;

	// 4. Fõ ciklus (render loop)
	while (!glfwWindowShouldClose(window)) {
		// Háttér törlése kékeszöld színnel
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}