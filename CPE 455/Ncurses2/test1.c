/*
 * ncurses tutorial
 * tutorial.c
 *
 * REFERENCES
 * https://tldp.org/HOWTO/pdf/NCURSES-Programming-HOWTO.pdf
 *
 * Hyperlinked man page - very useful
 * https://man.netbsd.org/curses.3
 *
 */

#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define ROWS 30
#define COLS 60
#define PADDLE_WIDTH 5
#define PADDLE_HEIGHT 1
#define BALL_SIZE 1
#define BRICK_WIDTH 5
#define BRICK_HEIGHT 2

typedef struct {
  int x, y;
  int dx, dy;
} ball_t;

typedef struct {
  int x, y;
} paddle_t;

typedef struct {
  int x, y;
  bool exists;
} brick_t;

int score1 = 0, score2 = 0;
int time_left = 60;

void display_scores() {
  move(0, 0);
  printw("Player 1: %d", score1);
  move(0, COLS-10);
  printw("Player 2: %d", score2);
}

void display_timer() {
  move(0, COLS-20);
  printw("Time Left: %d", time_left);
}

void draw_game_board() {
  clear();
  border(0, 0, 0, 0, 0, 0, 0, 0);
  display_scores();
  display_timer();
  refresh();
}

void initialize_game_objects(ball_t *ball, paddle_t *paddle1, paddle_t *paddle2, brick_t *bricks) 
{
  ball->x = COLS/2;
  ball->y = ROWS/2;
  ball->dx = 1;
  ball->dy = -1;

  paddle1->x = COLS/2 - PADDLE_WIDTH/2;
  paddle1->y = ROWS - 2;

  paddle2->x = COLS/2 - PADDLE_WIDTH/2;
  paddle2->y = 1;
  int i;

  for (i = 0; i < ROWS*COLS/BRICK_WIDTH/BRICK_HEIGHT; i++) {
    bricks[i].x = (i%COLS)*BRICK_WIDTH + 1;
    bricks[i].y = (i/COLS)*BRICK_HEIGHT + 3;
    bricks[i].exists = true;
  }
}

void draw_game_objects(ball_t ball, paddle_t paddle1, paddle_t paddle2, brick_t bricks[]) 
{
  int i, j;
  /*draw game objects on screen*/
  move(ball.y, ball.x);
  addch('o');

  move(paddle1.y, paddle1.x);
  for (i = 0; i < PADDLE_WIDTH; i++) 
  {
    addch('=');
  }

  move(paddle2.y, paddle2.x);
  for (i = 0; i < PADDLE_WIDTH; i++) 
  {
    addch('=');
  }

  for (i = 0; i < ROWS*COLS/BRICK_WIDTH/BRICK_HEIGHT; i++) 
  {
    if (bricks[i].exists) {
      move(bricks[i].y, bricks[i].x);
      for (j = 0; j < BRICK_WIDTH; j++) 
      {
        addch('=');
      }
      move(bricks[i].y+1, bricks[i].x);
      for (j = 0; j < BRICK_WIDTH; j++) {
        addch('=');
      }
    }
  }
}

void handle_collision(ball_t *ball, paddle_t *paddle1, paddle_t *paddle2, brick_t bricks[]) 
{
  int i, j;
  /*check if ball collides with paddle*/
  if ((ball->y == paddle1->y) && (ball->x >= paddle1->x) && (ball->x < paddle1->x + PADDLE_WIDTH)) 
  {
    ball->dy = -ball->dy;
  }
  else if ((ball->y == paddle2->y) && (ball->x >= paddle2->x) && (ball->x < paddle2->x + PADDLE_WIDTH)) 
  {
    ball->dy = -ball->dy;
  }
  /*check if ball collides with brick*/
  for (i = 0; i < ROWS; i++) 
  {
    for (j = 0; j < COLS/BRICK_WIDTH; j++) 
    {
      if (bricks[i*COLS/BRICK_WIDTH+j].exists && (ball->y == i*BRICK_HEIGHT+1) && (ball->x >= j*BRICK_WIDTH) && (ball->x < (j+1)*BRICK_WIDTH)) {
        ball->dy = -ball->dy;
        bricks[i*COLS/BRICK_WIDTH+j].exists = false;
        score1++;
        break;
      }
    }
  }
}

void move_paddle(paddle_t *paddle, int direction) {
  if (direction == KEY_LEFT && paddle->x > 0) {
    paddle->x--;
  }
  else if (direction == KEY_RIGHT && paddle->x < COLS - PADDLE_WIDTH) {
    paddle->x++;
  }
}

void game_loop(ball_t *ball, paddle_t *paddle1, paddle_t *paddle2, brick_t bricks[]) {
  int ch;
  timeout(50); /*set input timeout to 50 milliseconds*/
  while (time_left > 0) {
    /*handle user input*/
    ch = getch();
    switch(ch) {
      case KEY_LEFT:
        move_paddle(paddle1, -1);
        break;
      case KEY_RIGHT:
        move_paddle(paddle1, 1);
        break;
      case 'a':
        move_paddle(paddle2, -1);
        break;
      case 'd':
        move_paddle(paddle2, 1);
        break;
      case 'q':
        endwin();
        exit(0);
    }
    
    /*update game state*/
    handle_collision(ball, paddle1, paddle2, bricks);
    ball->x += ball->dx;
    ball->y += ball->dy;
    
    /*check if game is over*/
    if (score1 + score2 == ROWS * COLS / BRICK_WIDTH / BRICK_HEIGHT) {
      /*all bricks have been destroyed, end the game*/
      break;
    }
    
    /*draw game objects*/
    draw_game_board();
    draw_game_objects(*ball, *paddle1, *paddle2, bricks);
    
    /*decrement timer and sleep for 100 milliseconds*/
    time_left--;
    usleep(100000);
  }
  
  /*game over, display final score and wait for user input*/
  clear();
  if (score1 > score2) {
    mvprintw(ROWS/2, COLS/2-10, "Player 1 wins! Final score: %d-%d", score1, score2);
  } else if (score2 > score1) {
    mvprintw(ROWS/2, COLS/2-10, "Player 2 wins! Final score: %d-%d", score2, score1);
  } else {
    mvprintw(ROWS/2, COLS/2-5, "Tie game! Final score: %d-%d", score1, score2);
  }
  mvprintw(ROWS/2+2, COLS/2-15, "Press any key to exit...");
  refresh();
  getch();
}

int main() {
  ball_t ball;
  paddle_t paddle1, paddle2;
  brick_t bricks[ROWS*COLS/BRICK_WIDTH/BRICK_HEIGHT];

  /*initialize ncurses*/
  initscr();
  cbreak();
  noecho();
  curs_set(0);

  /*initialize game objects*/
  initialize_game_objects(&ball, &paddle1, &paddle2, bricks);

  /*start game loop*/
  game_loop(&ball, &paddle1, &paddle2, bricks);

  /*clean up and exit*/
  endwin();
  return 0;
}

