#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#pragma comment(lib,"opengl32")

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}
int main(void)
{
    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
    //윈도우 매니저한테 윈도우 만들어달라고 함
    //윈도우라는 객체에 저장
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);
    //메세지 핸들러
    //glfw붙은게 dc사용. 
    while (!glfwWindowShouldClose(window))
    {
        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float)height;


        glClearColor(0.7f, 0.7f, 0.7f, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_POLYGON);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3f(-0.5, -0.5, 0.0);
        glVertex3f(0.5, -0.5, 0.0);
        glVertex3f(0.5, 0.5, 0.0);
        glVertex3f(-0.5, 0.5, 0.0);


        glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(1.0f, -1.0f);
        glEnd();
        //glFlush();
        //html canvas랑 같음 opengl사용
        glfwSwapBuffers(window);//버퍼 스왑됨
        glfwPollEvents(); //키콜백, 에러콜백 중 받은걸로 실행.
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}