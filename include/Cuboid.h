#ifndef CUBOID_H
#define CUBOID_H

#include "Rectangle.h"
#include "Drawable.h"

class Cuboid: public Drawable
{
    public:
        Cuboid(int x,int y,int z, Operators3D * opGlobal);
        virtual ~Cuboid();

    protected:

    private:
};

#endif // CUBOID_H
