#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>

#include "MMath.hpp"
#include "Player.hpp"
#include "block.hpp"

#pragma comment(lib, "OpenGL32")

Player* p = new Player(0.1f, 0.9f, 0.9f, MuSeoun::vec3(1.0f, 0.0f, 0.0f));

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);

    if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS)
        p->MoveRight(0.001f);
    if (key == GLFW_KEY_RIGHT && action == GLFW_RELEASE)
        p->MoveRight(0.0f);
    if (key == GLFW_KEY_LEFT && action == GLFW_PRESS)
        p->MoveRight(-0.001f);
    if (key == GLFW_KEY_LEFT && action == GLFW_RELEASE)
        p->MoveRight(0.0f);
}
int main(void)
{
    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(640, 480, "202027023_pjw", NULL, NULL); //������ â ũ��, �̸�
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    while (!glfwWindowShouldClose(window))
    {
        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float)height;

        glClearColor(.0f, 0.0f, 0.0f, 0.1f); //�������� ��
        glClear(GL_COLOR_BUFFER_BIT);

        p->Render(); //����

        glPointSize(10.0); 
        glBegin(GL_POINTS); //��
        glVertex2f(-0.5f, -0.5f);

        glEnd();

        glBegin(GL_QUADS); //��
        glVertex2f(-0.1f, -0.5f);
        glVertex2f(0.1f, -0.5f);
        glVertex2f(0.1f, -0.4f);
        glVertex2f(-0.1f, -0.4f);
        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    delete(p);
    exit(EXIT_SUCCESS);
}
