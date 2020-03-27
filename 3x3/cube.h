#include <stdlib.h>

typedef struct cube_tile {
    // struct to represent a tile face of the Rubik cube
    struct cube_tile *up_vertical;
    struct cube_tile *up_horizontal;
    struct cube_tile *across;
    struct cube_tile *right;
    struct cube_tile *left;
    struct cube_tile *down;
    char color;
} cube_tile;

cube_tile* Tile(char color) {
    // constructor function for cube_tile struct
    cube_tile *temp = NULL;
    temp = (cube_tile *) malloc(sizeof(cube_tile));
    temp->up_vertical = NULL;
    temp->up_horizontal = NULL;
    temp->right = NULL;
    temp->down = NULL;
    temp->left = NULL;
    temp->color = color;

    return temp;
}

typedef struct face {
    //  struct to represent a face of the Rubik cube
    //  a b c
    //  h ┼ d
    //  g f e
    //  are the tiles that make up the face they are doubly linked around 
    //  the perimeter using the left and right pointers and across the 
    //  center using the across pointers.
    cube_tile *a;
    cube_tile *b;
    cube_tile *c;
    cube_tile *d;
    cube_tile *e;
    cube_tile *f;
    cube_tile *g;
    cube_tile *h;
    char color;
} face;

face *Face(char color) {
    // constructor function for face struct
    face *temp = NULL;
    temp = (face *) malloc(sizeof(face));

    temp->color = color;

    temp->a = Tile(color);
    temp->b = Tile(color);
    temp->c = Tile(color);
    temp->d = Tile(color);
    temp->e = Tile(color);
    temp->f = Tile(color);
    temp->g = Tile(color);
    temp->h = Tile(color);

    temp->a->right = temp->b;
    temp->a->left = temp->h;
    temp->b->right = temp->c;
    temp->b->left = temp->a;
    temp->c->right = temp->d;
    temp->c->left = temp->b;
    temp->d->right = temp->e;
    temp->d->left = temp->c;
    temp->e->right = temp->f;
    temp->e->left = temp->d;
    temp->f->right = temp->g;
    temp->f->left = temp->e;
    temp->g->right = temp->h;
    temp->g->left = temp->f;
    temp->h->right = temp->a;
    temp->h->left = temp->g;

    temp->b->across = temp->f;
    temp->f->across = temp->b;
    temp->h->across = temp->d;
    temp->d->across = temp->h;

    return temp;
}

typedef struct rubik_cube {
    // struct to represent the Rubik cube
    face *red_face;
    face *blue_face;
    face *white_face;
    face *green_face;
    face *yellow_face;
    face *orange_face;
} rubik_cube;

rubik_cube *Rubik_Cube() {
    // constructor function for rubik_cube struct
    rubik_cube *cube = Rubik_Cube();
    // TODO
    return cube;
}
