// APSC 142 Engineering Programming Project Starter Code
// Copyright Sean Kauffman 2026

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <stdio.h>

// make sure not to modify anything in this extern block
extern "C"{
#include "defines.h"
#include "map.h"
#include "character.h"
#include "game.h"
char *map = NULL;
int width, height;
}

/**
 * This file is where you should put your tests for your code.
 * Your code must have tests that execute at least 85% of the code in
 * required functions for you to get full marks for the project.
 * Make sure to check out the course videos on automated testing for
 * more information about how to write tests.
 */

/* Tests for map.c */
TEST_SUITE_BEGIN("Map tests");

// Tests for load_map
TEST_CASE("A test for load_map") {
    CHECK(0 == 0);
}

TEST_SUITE_END();

/* tests for character.c */
TEST_SUITE_BEGIN("Character tests");

// tests for move_character

// tests for locate_character

// tests for charge_minotaur

// tests for sees_player

TEST_SUITE_END();

/* tests for game.c */
TEST_SUITE_BEGIN("Game tests");

// tests for check_win
TEST_CASE("checkwin test"){
    width=4;
    height=5;
    CHECK(check_win(0,3)==YOU_WIN);
    CHECK(check_win(-1,2)==YOU_WIN);
    CHECK(check_win(2,-1)==YOU_WIN);
    CHECK(check_win(5,3)==YOU_WIN);
    CHECK(check_win(3,0)==YOU_WIN);
    CHECK(check_win(3,4)==YOU_WIN);
    CHECK(check_win(2,2)==KEEP_GOING);
    CHECK(check_win(6,3)==YOU_WIN);
    CHECK(check_win(3,5)==YOU_WIN);
    CHECK(check_win(0,0)==YOU_WIN);
    CHECK(check_win(6,5)==YOU_WIN);
    
    
}
// test for check_loss
TEST_CASE("collision test"){
    CHECK(check_loss(2,5,2,5)==YOU_LOSE);
    CHECK(check_loss(2,5,2,4)==KEEP_GOING);
}
TEST_SUITE_END();
