#include <stdlib.h>

typedef struct tile {
    // struct to represent a tile face of the Rubik cube
    // if this abstraction works out I will digitally recreate the
    // drawing the explains these pointers
    struct tile *right;
    struct tile *left;
    struct tile *across;
    struct tile *right_inv;
    struct tile *left_inv;
    char color;
} tile;

tile* Tile(char color) {
    // constructor function for tile struct
    tile *temp = NULL;
    temp = (tile *) malloc(sizeof(tile));
    temp->right = NULL;
    temp->left = NULL;
    temp->across = NULL;
    temp->right_inv = NULL;
    temp->left_inv = NULL;
    temp->color = color;

    return temp;
}

void delete_Tile(tile *_tile) {
    // destructor function for the tile struct
    free(_tile);
}

typedef struct face {
    //  struct to represent a face of the Rubik cube
    //  a b c
    //  h ┼ d
    //  g f e
    //  are the tiles that make up the face they are doubly linked around 
    //  the perimeter using the left and right pointers and across the 
    //  center using the across pointers.
    tile *a;
    tile *b;
    tile *c;
    tile *d;
    tile *e;
    tile *f;
    tile *g;
    tile *h;
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

void delete_Face(face *cube_face) {
    // destructor function for the face struct
    delete_Tile(cube_face->a);
    delete_Tile(cube_face->b);
    delete_Tile(cube_face->c);
    delete_Tile(cube_face->d);
    delete_Tile(cube_face->e);
    delete_Tile(cube_face->f);
    delete_Tile(cube_face->g);
    delete_Tile(cube_face->h);

    free(cube_face);
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

void delete_Rubik_Cube(rubik_cube *cube) {
    // destructor function for the  rubik_cube struct
    // TODO
}
