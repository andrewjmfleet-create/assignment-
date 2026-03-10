// APSC 142 Engineering Programming Project Starter Code
// Copyright Sean Kauffman 2026

#include "defines.h"
#include "character.h"
#include <stdio.h>

extern char * map;
extern int height;
extern int width;

char sees_player(int player_y, int player_x, int minotaur_y, int minotaur_x) {
    // check to see if the Minotaur has caught the player
    // check if neither the x nor y coordinate is the same as the player
    // if there's a wall in between, they can't see
    // if one of them is the same, check if the path in between is clear
    int start=0;
    int end=0;
    if (player_y == minotaur_y) {
        if (player_x < minotaur_x) {
            start = player_x + 1;
            end = minotaur_x;
        } else {
            start = minotaur_x + 1;
            end = player_x;
        }

        for (int i = start; i < end; i++) {
            if (map[player_y * width + i] == WALL) {
                return SEES_NOTHING;
            }
        }
        if (minotaur_x > player_x) {
            return 'a';
        } else {
            return 'd';
        }
    }
    if (player_x == minotaur_x) {
        if (player_y < minotaur_y) {
            start = player_y + 1;
            end = minotaur_y;
        } else {
            start = minotaur_y + 1;
            end = player_y;
        }
        for (int i = start; i < end; i++) {
            if (map[i * width + player_x] == WALL) {
                return SEES_NOTHING;
            }
        }
        if (minotaur_y > player_y) {
            return 'w';
        } else {
            return 's';
        }
    }
    return SEES_NOTHING;
}
int move_character(int * y, int * x, char direction, char character) {
   
}
int charge_minotaur(int *y, int *x, int player_y, int player_x, char charge_direction) {
   
}
