// Contains the game globals
#pragma once

//The direction the sprite is moving in
const int static WEST = 1;
const int static EAST = 3;
const int static NORTH = 2; // direction north
const int static SOUTH = 4;


const float SCREEN_WIDTH = 1500;   // the size of the screen in pixels used in the game
const float SCREEN_HEIGHT = 800;

//game modes
const int INSTRUCTIONS = 1;
const int CHOOSE_CHARACTER = 2;
const int GAME_PLAY = 3;
const int CLOSING_SCREEN = 4;

//character size
const int CHARACTER_WIDTH = 48;
const int CHARACTER_HEIGHT = 64;

//guard size
const int GUARD_WIDTH = 64;
const int GUARD_HEIGHT = 64;

const int MAX_GUARDS = 4; //maximum number of guards
const int MAX_WALLS = 4;//maximum number of wall sides

//poison size
const int POISON = 64; //poision is a square so both width and hight are 64

//cat size
const int CAT_WIDTH = 64;
const int CAT_HEIGHT = 64;

//side
const int RIGHT = 1;
const int LEFT = 2;
const int UP = 3;
const int DOWN = 4;