#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>


void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void drawGrid()
{
    // Рисование сетки
    glColor3f(0.0f, 0.0f, 0.0f); // Черный цвет линий сетки
    glLineWidth(1.0f); // Толщина линий

    // Горизонтальные линии
    for (float y = -0.9f; y <= 0.9f; y += 0.1f)
    {
        glBegin(GL_LINES);
        glVertex2f(-1.0f, y);
        glVertex2f(1.0f, y);
        glEnd();
    }

    // Вертикальные линии
    for (float x = -0.9f; x <= 0.9f; x += 0.1f)
    {
        glBegin(GL_LINES);
        glVertex2f(x, -1.0f);
        glVertex2f(x, 1.0f);
        glEnd();
    }

    // Преобразование координат Y для прямоугольника
    GLfloat vertices[] = {
            0.5f, 0.5f,
            -0.5f, -0.5f,
            0.5f, 0.5f,
            -0.5f, -0.5f
    };

    for (int i = 0; i < 4; i++) {
        vertices[i * 2 + 1] *= -1.0f; // Инверсия значения координаты Y
    }

    // Рисование прямоугольника
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0.1, 0.1, 0.1);
    glVertex2fv(vertices);
    glEnd();
}


int main()
{
    if (!glfwInit())
    {
        std::cout << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Game", nullptr, nullptr);
    if (window == nullptr)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    glEnable(GL_DEPTH_TEST);

    while (!glfwWindowShouldClose(window))
    {
        processInput(window);

        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



        glfwSwapBuffers(window);
        glfwPollEvents();
        drawGrid();
        glEnd();
    }

    glfwTerminate();
    return 0;
}
