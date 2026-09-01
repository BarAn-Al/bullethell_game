#include <SDL2/SDL.h>

class Object {
protected:
    int posX, posY;
    bool track;

public:
    Object() : posX(0), posY(0), track(false) {}
    Object(int x, int y) : posX(x), posY(y) {}
};


class Character : public Object {
protected:
    int health;

public:
    Character(int x, int y, int h) : Object(x, y), health(h) { track = true; }
};


class Enemy : public Object {
    int health;
    
public:
    Enemy(int x, int y, int h) : Object(x, y), health(h) {}
};