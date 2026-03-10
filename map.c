// APSC 142 Engineering Programming Project Starter Code
// Copyright Sean Kauffman 2026

#include <stdio.h>
#include <stdlib.h>

#include "defines.h"
#include "colours.h"
#include "map.h"

#define BUFFER_SIZE 10


extern char *map;
extern int width, height;

/**
 * You should use this function to print out individual characters
 * in the colours used in the demo.
 * @param c
 */
static void printc(char c) {
    switch (c) {
        case WALL:
            change_text_colour(BLUE);
            break;
        case MINOTAUR:
            change_text_colour(MAGENTA);
            break;
        case PLAYER:
            change_text_colour(YELLOW);
            break;
        default:
            change_text_colour(WHITE);
    }
    printf("%c", c);
}

void print_map(void) {
    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            if (j==width-1){
                printc(map[i*width+j]);
            }else{
                printc(map[i*width+j]);
                printf(" ");
        
            }
        }
        printf("\n");
    }

}

void print_revealed_map(int player_y, int player_x) {
    // Only the map within PLAYER_VISION_DISTANCE of the player (including diagonals) should be printed
}

int locate_character(char character, int* character_y, int* character_x) {
    // Attempt to find the character in the map and return a status code indicating
    // if they were present
    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            if (map[i*width+j]==character) {
                return FOUND_CHARACTER;
            }
        }
    }
    return CHARACTER_NOT_FOUND;
}


char *load_map(char *filename, int *map_height, int *map_width) {
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        return NULL;
    }
    width = *map_width;
    height = *map_height;
    map=malloc(width*height*sizeof(char));
    for (int i=0; i<width; i++) {
        for (int j=0; j<height; j++) {
           fscanf(f,"%c",&map[i*width+j]);
        }
    }
    fclose(f);
    return map;
}
