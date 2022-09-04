#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <string>

using namespace std;

int main() {
  if (!glfwInit()) {
    cout << "GLFW initialisation failed!" << endl;
    glfwTerminate();
    return EXIT_FAILURE;
  }
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

  const GLint width(600), height(600);
  string title("Main Window");

  GLFWwindow *mainWindow =
      glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

  if (!mainWindow) {
    cout << "Window creation failed!" << endl;
    glfwTerminate();
    return EXIT_FAILURE;
  }

  GLint bufferWidth, bufferHeight;
  glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);
  glfwMakeContextCurrent(mainWindow);

  // Enable experimental features
  glewExperimental = GL_TRUE;
  if (glewInit() != GLEW_OK) {
    cout << "Glew initialisation failed!" << endl;
    glfwDestroyWindow(mainWindow);
    glfwTerminate();
    return EXIT_FAILURE;
  }

  // Setup viewport size
  glViewport(0, 0, bufferWidth, bufferHeight);

  // Loop until window closed
  while (!glfwWindowShouldClose(mainWindow)) {
    // Get and handle user input events
    glfwPollEvents();
    // Clear window (RGBA)
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(mainWindow);
  }

  return 0;
}
