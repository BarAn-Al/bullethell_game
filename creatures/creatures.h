#ifndef CREATURES_H
#define CREATURES_H

#include <SDL2/SDL.h>
#include "entities/entities.h"
#include <random>

short int sign(short int x) {
    if (!x) return 0;
    return x > 0 ? 1 : -1;
}

class Enemy : public Object {
protected:
    int health;

public:
    void moveTo(int x, int y) {
        int xMove = sign(x - this->x);
        int yMove = sign(y - this->y);
        double norm = sqrt(xMove * xMove + yMove * yMove);

        if (norm <= speed) {
            this->x = x;
            this->y = y;
        } else {
            rand() % xMove // дописать функцию
        }
        
    }
};

#endif //CREATURES_H