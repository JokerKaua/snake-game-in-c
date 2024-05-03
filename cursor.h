/**
 * All codes -> https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797
*/


#define POSC(x, y)      printf("\x1B[%d;%df", y, x)
#define CLEAR           printf("\x1B[2J\x1B[H")
#define ERASE_LINE      printf("\x1B[2K")

#define INVISIBLE_CURSOR "\x1B[?25l"
#define VISIBLE_CURSOR   "\x1B[?25h"
#define SAVE_POS         "\x1B[s"
#define REST_POS         "\x1B[u"

#define RESET_COLOR     "\x1B[0m"

#define RED             "\x1B[31m"
#define GREEN           "\x1B[32m"
#define YELLOW          "\x1B[33m"
#define BLUE            "\x1B[34m"
#define MAGENT          "\x1B[35m"
#define CIAN            "\x1B[36m"
#define WHITE           "\x1B[37m"
#define GRAY            "\x1B[38;5;243m"
#define DARK_GRAY       "\x1B[38;5;238m"
#define BLACK           "\x1B[30m"

#define RED_INT         31
#define GREEN_INT       32
#define YELLOW_INT      33
#define BLUE_INT        34
#define CIAN_INT        36
#define WHITE_INT       37
#define BLACK_INT       30

/**
 * Change terminal color with the colors integers values
*/
#define COLOR(forg, bac) printf("\x1B[0;%d;%dm", forg, bac+10)

/**
 * Make an horizontal line 
 * @param size Width of the line 
*/
#define LINE_H(size) for(int i = size; i > 0; i--){printf("-");}
/**
 * Make an verical line 
 * @param size Height of the line
*/
#define LINE_V(size) for(int i = size; i > 0; i--){printf("|\x1b[1B\x1b[1D");}


