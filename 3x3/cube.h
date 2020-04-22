#include <stdlib.h>

typedef struct tile {
    // struct to represent a tile face of the Rubik cube
    // if this abstraction work out I will recreate the
    // drawing the explains these pointers
    struct tile *right;
    struct tile *left;
    struct tile *across;
    struct tile *edge;
    struct tile *right_edge;
    struct tile *left_edge;
    char color;
} tile;

tile* Tile(char color) {
    // constructor function for tile struct
    tile *temp = NULL;
    temp = (tile *) malloc(sizeof(tile));
    temp->right = NULL;
    temp->left = NULL;
    temp->across = NULL;
    temp->edge = NULL;
    temp->right_edge = NULL;
    temp->left_edge = NULL;
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
    rubik_cube *cube = NULL;
    cube = (rubik_cube *) malloc(sizeof(rubik_cube));
    face *red_face = Face('R');
    face *blue_face = Face('B');
    face *white_face = Face('W');
    face *green_face = Face('G');
    face *yellow_face = Face('Y');
    face *orange_face = Face('O');

    red_face->a->left_edge = blue_face->g;  // attach the blue face to the red face
    red_face->b->edge = blue_face->f;
    red_face->c->right_edge = blue_face->e;

    blue_face->g->right_edge = red_face->a;  // attach the red face to the blue face
    blue_face->f->edge = red_face->b;
    blue_face->e->left_edge = red_face->c;

    red_face->c->left_edge = white_face->g;  // attach the white face to the red face
    red_face->d->edge = white_face->f;
    red_face->e->right_edge = white_face->e;

    white_face->g->right_edge = red_face->c;  // attach the red face to the white face
    white_face->f->edge = red_face->d;
    white_face->e->left_edge = red_face->e;

    red_face->e->left_edge = green_face->g;  // attach the green face to the red face
    red_face->f->edge = green_face->f;
    red_face->g->right_edge = green_face->e;

    green_face->g->right_edge = red_face->e;  // attach the red face to the green face
    green_face->f->edge = red_face->f;
    green_face->e->left_edge = red_face->g;

    red_face->g->left_edge = yellow_face->g;  // attach the yellow face to the red face
    red_face->h->edge = yellow_face->f;
    red_face->a->right_edge = yellow_face->e;

    yellow_face->g->right_edge = red_face->g;  // attach the red face to the yellow face
    yellow_face->f->edge = red_face->h;
    yellow_face->e->left_edge = red_face->a;

    orange_face->a->right_edge = green_face->a; // attach the green face to the orange face
    orange_face->b->edge = green_face->b;
    orange_face->c->left_edge = green_face->c;

    orange_face->c->right_edge = yellow_face->a;  // attach the yellow face to the orange face
    orange_face->d->edge = yellow_face->b;
    orange_face->e->left_edge = yellow_face->c;

    orange_face->e->right_edge = blue_face->a;  // attach the blue face to the orange face
    orange_face->f->edge = blue_face->b;
    orange_face->g->left_edge = blue_face->c;

    orange_face->g->right_edge = white_face->a;  // attach the white face to the orange face
    orange_face->h->edge = white_face->b;
    orange_face->a->left_edge = white_face->c;

    return cube;
}

void delete_Rubik_Cube(rubik_cube *cube) {
    // destructor function for the  rubik_cube struct
    // TODO
}
