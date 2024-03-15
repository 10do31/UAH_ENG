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
#define B_WIDTH 4
#define B_HEIGHT 3


int main(int argc, char* argv[ ])
{
  WINDOW* W = 0;                     /* Curses Window handle */
  int rowLimit, colLimit;            /* Num of rows and columns in terminal window */  
  int playerRow, playerCol;          /* Player row-column position */
  int deltaRow, deltaCol;            /* Change in row-column position based on key input */
  int c;                             /* Column value */
  int c2;

  /* Initialize ncurses -- you will want to use the following settings */
  W = initscr();     /* Determine terminal type and initialize curses data structures */
  start_color();     /* Enable use of color with ncurses */
  cbreak();          /* Disable line buffering and make char inputs immediately accessible to program */
  noecho();          /* Disable echo printing of chars type by user */
  nodelay(W, true);  /* Make getch( ) a non-blocking call */
  keypad(W, true);   /* Enable keypad and arrow keys */
  curs_set(0);       /* Set cursor to be invisible - 0 */
  getmaxyx(W, rowLimit, colLimit);  /* Query terminal dimensions */

  /* Define color palette foreground-background color pairs */
  /* PairID#, Foreground Color, Background Color */
  /* Foreground color == Background color ==> solid color block */
  init_pair(1, COLOR_BLACK, COLOR_BLACK);      /* Black text on Black background */
  init_pair(2, COLOR_RED, COLOR_RED);        /* Red text on Black background */
  init_pair(3, COLOR_BLUE, COLOR_BLUE);       /* White text on Blue background */
  init_pair(4, COLOR_YELLOW, COLOR_BLACK);    /* MODIFICATION: Yellow text on Yellow background */
  init_pair(5, COLOR_GREEN, COLOR_BLACK);    /* MODIFICATION: Yellow text on Yellow background */
 
  /* Draw some obstacle */
  attron(COLOR_PAIR(2));                  /* Turn on color attribute #2 */
  wmove(W, rowLimit/2, colLimit/2);      /* Position cursor in middle of terminal window */
  waddch(W, ACS_DIAMOND);                         /* Draw # symbol */
  /* SHOW SHORTCUT HERE */
  mvwaddch(W, rowLimit/3, colLimit/3, '?');
  attroff(COLOR_PAIR(2));                 /* Turn off color attribute #2 */

  /* Draw a border along top of screen */
  /* POSSIBLE MODIFICATION - ADD CODE HERE TO DRAW TOP BORDER */
  attron(COLOR_PAIR(4));
  for(c = 0; c < colLimit; c++)
  {
     wmove(W, 0, c);
     waddch(W, '*');
  }
  mvwhline(W, 2, 0, '-', colLimit);
  attroff(COLOR_PAIR(4));

  attron(COLOR_PAIR(5));
  /*for(c = 0; c < rowLimit; c++)
  {
     wmove(W, 0, c);
     waddch(W, '|');
  }*/
  mvwhline(W, 2, 0, '|', colLimit);
  wborder(W, '|', '|', '-', '-', '$', '$', '$', '$');
  attroff(COLOR_PAIR(5));
  /* SHOW SHORTCUT HERE */

  /* Initialize player movement variables */
  playerRow = rowLimit/4;
  playerCol = colLimit/4;
  deltaRow = 0;
  deltaCol = 0;
 
  /* Player movement loop */
  do
  {
    int kb = wgetch(W);                   /* Grab keypress */

    /* Support player movement via arrow keys */
    /* POSSIBLE MODIFICATION - add support for WASD or IJKL keys */
    if (kb == KEY_LEFT)
    {
        /* Move Left */  
        deltaRow = 0;
        deltaCol = -1;
    }
    else if (kb == KEY_RIGHT)
    {
        /* Move Right */
        deltaRow = 0;
        deltaCol = 1;
    }
    else if (kb == KEY_UP)
    {
        /* Move Up */  
        deltaRow = -1;
        deltaCol = 0;
    }
    else if (kb == KEY_DOWN)
    {
        /* Move Down */ 
        deltaRow = 1;
        deltaCol = 0;
    }
    else if (kb == 'q')
    {
        /* q to exit player movement loop */ 
        break;
    };

    /* Erase player from current position                                    */
    /*                                                                       */ 
    /* Algorithm:                                                            */
    /* - Turn on color attribute #1  (solid block of background color)       */
    /* - Position cursor                                                     */
    /* - Draw player symbol                                                  */
    /* - Turn off color attribute #1                                         */
    /* POSSIBLE MODIFICATION - ADD CODE HERE TO ERASE TAIL */
    attron(COLOR_PAIR(1));                   /* Turn on color attribute #3 */
    /*wmove(W, playerRow, playerCol);          Position cursor */
    /* waddch(W, 'P');                          Draw player symbol */
    /*attroff(COLOR_PAIR(1));                  Turn off color attribute #3 */ 

    for(c2 = 0; c2 < rowLimit + colLimit; c++)
    {
        wmove(W, playerRow, playerCol);         /* Position cursor */
        waddch(W, 'P'); 
    }
    attroff(COLOR_PAIR(1));                  /*Turn off color attribute #3*/
    /* SHOW SHORTCUT HERE */            
    
    /* Compute new player position without checking to see if new position is valid */
    /* POSSIBLE MODIFICATION - ADD BOUNDS CHECKING CODE HERE */
    playerRow = playerRow + deltaRow;
    playerCol = playerCol + deltaCol;

    if(playerRow < 1)
    {
       playerRow = 1;
    }
    else if(playerRow > rowLimit -1)
    {
       playerRow = rowLimit - 1;
    }

    /* Redraw player in new position */
    attron(COLOR_PAIR(3));                  /* Turn on color attribute #3 */
    wmove(W, playerRow, playerCol);         /* Position cursor */
    waddch(W, 'P');                         /* Draw player symbol */
    attroff(COLOR_PAIR(3));                 /* Turn off color attribute #3 */
    
    /* Zero offsets prior to next key press */
    /* POSSIBLE MODIFICATION - ZERO OUT VELOCITY VECTOR */
    deltaRow = 0;
    deltaCol = 0;

    wrefresh(W);                            /* Refresh ncurses window */

  } while (true);                           /* Repeat until user selects q to quit */

  endwin();                                 /* Terminate ncurses window -- very important */

  return 0;
}


