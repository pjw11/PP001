#pragma once

class Player {
public:
    Player(float size_, float x_, float y_, float col)
    {

    }
    ~Player()
    {

    }
    void MoveRight(float distance)
    {

    }
    void Render()
    {
        //Æ¨±â´Â °Í
        glLineWidth(10.0);
        glBegin(GL_LINES);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f(0.5f, -0.5f);
        glEnd();
        glFinish();

    }
};