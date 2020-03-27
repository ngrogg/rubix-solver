#include <stdlib.h>

typedef struct cube_tile {
    struct cube_tile *up;
    struct cube_tile *right;
    struct cube_tile *left;
    struct cube_tile *down;
    char color;
    int index;
} cube_tile;

typedef struct rubik_cube {
    cube_tile *red_face;
    cube_tile *blue_face;
    cube_tile *white_face;
    cube_tile *green_face;
    cube_tile *yellow_face;
    cube_tile *orange_face;
} rubik_cube;

cube_tile* Tile(char color) {
    cube_tile *temp = NULL;
    temp = (cube_tile *) malloc(sizeof(cube_tile));
    temp->up = NULL;
    temp->right = NULL;
    temp->down = NULL;
    temp->left = NULL;
    temp->color = color;
    temp->index = 0;
    return temp;
}

cube_tile *create_face(char color){
    cube_tile *corner = Tile(color);
    cube_tile *top = corner;
    for (int i = 0; i < 8; ++i) {
        cube_tile *next = Tile(color);
        corner->right = next;
        next->left = corner;
        corner = next;
    }
    corner->right = top;
    top->left = corner;
    return top;
}

void cycle(cube_tile *head, int n) {
    // shift a face by n.
    // positive is rightwards, negative is leftwards
    if (n > 0) {
        for (int i = 0; i < n; ++i) {
            head = head->right;
        }
    } else if (n < 0) {
        for (int i = 0; i < n; ++i) {
            head = head->left;
        }
    }
}

cube_tile *__add_face(cube_tile *face_a, cube_tile *face_b) {
    //  a helper function to be used in construction of a cube object
    //  NOT intended for general use
    cube_tile *top = face_a;
    for (int i = 0; i < 3; ++i) {
        face_a->up = face_b;
        face_b->down = face_a;
        face_a = face_a->right;
        face_b = face_b->right;
    }
    return top;
}

cube_tile *_add_blue_face(cube_tile *corner, rubik_cube *cube) {
    // helper function for create_cube.
    // this function is NOT intended for general use.
    cube_tile *blue_face = create_face('B');
    cube->blue_face = blue_face;
    corner = __add_face(corner, blue_face);
    return corner;
}

cube_tile *_add_white_face(cube_tile *corner, rubik_cube *cube) {
    // helper function for create_cube.
    // this function is NOT intended for general use.
    cube_tile *white_face = create_face('W');
    cube->white_face = white_face;
    cycle(corner, 3);
    corner = __add_face(corner, white_face);
    return corner;
}

cube_tile *_add_green_face(cube_tile *corner, rubik_cube *cube) {
    // helper function for create_cube.
    // this function is NOT intended for general use.
    cube_tile * green_face = create_face('G');
    cube->green_face = green_face;
    cycle(corner, 6);
    corner = __add_face(corner, green_face);
    return corner;
}

cube_tile *_add_yellow_face(cube_tile *corner, rubik_cube *cube) {
    // helper function for create_cube.
    // this function is NOT intended for general use.
    cube_tile * yellow_face = create_face('Y');
    cube->yellow_face = yellow_face;
    cycle(corner, 9);
    corner = __add_face(corner, yellow_face);
    return corner;
}

cube_tile *_add_orange_face(cube_tile *corner, rubik_cube *cube) {
    // helper function for create_cube.
    // this function is NOT intended for general use.
    cube_tile *orange_face = create_face('O');
    cube->orange_face = orange_face;
}

rubik_cube *create_cube() {
    rubik_cube * cube = NULL;
    cube = (rubik_cube *) malloc(sizeof(rubik_cube));

    cube_tile *corner = create_face('R');
    for (int i = 0; i < 5; ++i) {
        switch (i) {
            case 0:
                corner = _add_blue_face(corner, cube);
                break;
            case 1:
                corner = _add_white_face(corner, cube);
                break;
            case 2:
                corner = _add_green_face(corner, cube);
                break;
            case 3:
                corner = _add_yellow_face(corner, cube);
                break;
            case 4:
                corner = _add_orange_face(corner, cube);
                break;
        }
    }
    return cube;
}
