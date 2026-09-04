#ifndef ENTITIES_H
#define ENTITIES_H

#include <SDL2/SDL.h>

class Object : public SDL_Rect {
protected:
    int speed;

public:
    Object(int x, int y, int speed) {
        this->x = x;
        this->y = y;
        this->speed = speed;
    }

    void moveUp()    { y -= speed; }
    void moveLeft()  { x -= speed; }
    void moveDown()  { y += speed; }
    void moveRight() { x += speed; }

    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }

    void getPos(int& x, int& y) {
        x = this->x;
        y = this->y;
    }
};

#endif //ENTITIES_H