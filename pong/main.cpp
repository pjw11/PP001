#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>

#include <Player.hpp>

#pragma comment(lib,"opengl32")



static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    //Ű �Է�
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);

    if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS)
        p->MoveRight(0.01f);
    if (key == GLFW_KEY_RIGHT && action == GLFW_RELEASE)
        p->MoveRight(0.0f);
    if (key == GLFW_KEY_LEFT && action == GLFW_PRESS)
        p->MoveRight(-0.01f);
    if (key == GLFW_KEY_LEFT && action == GLFW_RELEASE)
        p->MoveRight(0.0f);
}
int main(void)
{
    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(640, 480, "202027023_pjw", NULL, NULL); //������â ũ��, �̸�
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);

    while (!glfwWindowShouldClose(window))
    {
        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float)height;

        glClearColor(1.0f, 0.7f, 0.7f, 1); //������â ��� ��
        glClear(GL_COLOR_BUFFER_BIT);

        //ƨ��� ��
        glLineWidth(10.0);   
        glBegin(GL_LINES); 
        glVertex2f(-0.5f, -0.5f); 
        glVertex2f(0.5f, -0.5f); 
        glEnd(); 
        glFinish();



        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}