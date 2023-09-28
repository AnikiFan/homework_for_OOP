#pragma once
#include"../include/cmd_console_tools.h"
//大小
////BLOCK
#define HORIZONTAL_BLOCK_NUM 21
#define VERTICAL_BLOCK_NUM 26
#define BLOCK_WIDTH 6
#define BLOCK_HEIGHT 3
////GAMEBOARD
#define GAMEBOARD_SIDE_WIDTH 2
#define GAMEBOARD_WIDTH (HORIZONTAL_BLOCK_NUM*BLOCK_WIDTH+2*GAMEBOARD_SIDE_WIDTH)
#define GAMEBOARD_HEIGHT (VERTICAL_BLOCK_NUM*BLOCK_HEIGHT+2)
#define GAMEBOARD_SHADOW_WIDTH 1
////SCOREBOARD
#define SCOREBOARD_WIDTH 24
#define SCOREBOARD_HEIGHT 9
#define SCOREBOARD_SHADOW_WIDTH 1
#define SCOREBOARD_SIDE_WIDTH 2
#define SCOREBOARD_INFO_INTERVAL 2
#define SCOREBOARD_INFO_LENGTH 4
////CONSOLE
#define CONSOLE_WIDTH (GAMEBOARD_WIDTH+SCOREBOARD_WIDTH+23)
#define CONSOLE_HEIGHT (GAMEBOARD_HEIGHT+GAMEBOARD_Y+8)
#define CONSOLE_BUFFER_WIDTH CONSOLE_WIDTH
#define CONSOLE_BUFFER_HEIGHT CONSOLE_HEIGHT
#define CONSOLE_FONT_SIZE 18
////MENU
#define MENU_LIST_LENGTH 6
////BOARD
#define BOARD_SIDE_WIDTH 2
#define BOARD_TOP_WIDTH 5
#define BOARD_HEIGHT (VERTICAL_BLOCK_NUM+BOARD_TOP_WIDTH+BOARD_SIDE_WIDTH)
#define BOARD_WIDTH (HORIZONTAL_BLOCK_NUM+2*BOARD_SIDE_WIDTH)
////其他
#define NUM_BOUND 10
#define INITIAL_SPEED 1000
#define TIME_EPSILON 5

//坐标
////GAMEBOARD
#define GAMEBOARD_X 3
#define GAMEBOARD_Y 1
////SCOREBOARD
#define SCOREBOARD_X (GAMEBOARD_X+GAMEBOARD_WIDTH+10)
#define SCOREBOARD_Y GAMEBOARD_Y
#define SCOREBOARD_INFO_X (SCOREBOARD_X+SCOREBOARD_SIDE_WIDTH)
#define SCOREBOARD_INFO_Y (SCOREBOARD_Y+2)
////PROMPT
#define PROMPT_X 0
#define PROMPT_Y (CONSOLE_HEIGHT-4)


//颜色
////GAMEBOARD
#define GAMEBOARD_COLOR COLOR_WHITE 
#define GAMEBOARD_SIDE_COLOR COLOR_BLACK
#define GAMEBOARD_SHADOW_COLOR COLOR_BLUE
////SCOREBOARD
#define SCOREBOARD_COLOR COLOR_HBLACK
#define SCOREBOARD_SIDE_COLOR COLOR_WHITE
#define SCOREBOARD_SHADOW_COLOR COLOR_CYAN
#define SCOREBOARD_INFO_COLOR COLOR_BLACK
////BLOCK
#define BLOCK_COLOR_LIST {COLOR_BLUE,COLOR_GREEN,COLOR_CYAN,COLOR_RED,COLOR_YELLOW,COLOR_PINK,COLOR_HBLACK,COLOR_HBLUE,COLOR_HGREEN,COLOR_HRED}
#define BLOCK_FRAME_COLOR COLOR_HWHITE

//文字
#define CONSOLE_FONT_FAMILY "点阵字体"
#define MENU_LIST {"打印边框和得分板","单个数字下落","单个数字下落时可平移和加速下落","单个数字下落时可进行所有操作","两个数字下落,可叠加","完整版"}
#define QUIT_KEY "Q"
#define SCOREBOARD_INFO_LIST {"下一个数字:","当前得分:","当前速度:","已消除行数:"}
#define BLOCK {"╔═╗", "║★║","╚═╝"  }

//数字俄罗斯方块
////指标
//统一以abs_index为原点,右下角rel_index为正
struct Index{
	int x;
	int y;
};
#define ZERO_INDEX_NUM 12
#define ONE_INDEEX_NUM 5
#define TWO_INDEX_NUM 11
#define THREE_INDEX_NUM 11
#define FOUR_INDEX_NUM 9
#define FIVE_INDEX_NUM 11
#define SIX_INDEX_NUM 12
#define SEVEN_INDEX_NUM 7
#define EIGHT_INDEX_NUM 13
#define NINE_INDEX_NUM 12
#define INDEX_NUM_LIST {ZERO_INDEX_NUM,ONE_INDEEX_NUM,TWO_INDEX_NUM,THREE_INDEX_NUM,FOUR_INDEX_NUM,FIVE_INDEX_NUM,SIX_INDEX_NUM,SEVEN_INDEX_NUM,EIGHT_INDEX_NUM,NINE_INDEX_NUM}
#define ZERO_REL_INDEX {{-1,-2},{0,-2},{1,-2},{-1,-1},{1,-1},{-1,0},{1,0},{-1,1},{1,1},{-1,2},{0,2},{1,2}}
#define ONE_REL_INDEX {{0,-2},{0,-1},{0,0},{0,1},{0,2}}
#define TWO_REL_INDEX {{-1,-2},{0,-2},{1,-2},{1,-1},{1,0},{0,0},{-1,0},{-1,1},{-1,2},{0,2},{1,2}}
#define THREE_REL_INDEX {{-1,-2},{0,-2},{1,-2},{1,-1},{1,0},{0,0},{1,0},{1,1},{-1,2},{0,2},{1,2}}
#define FOUR_REL_INDEX {{-1,-2},{-1,-1},{-1,0},{0,0},{1,0},{1,-2},{1,-1},{1,1},{1,2}}
#define FIVE_REL_INDEX {{1,-2},{0,-2},{-1,-2},{-1,-1},{-1,0},{0,0},{1,0},{1,1},{1,2},{-1,2},{0,2}}
#define SIX_REL_INDEX {{-1,-2},{0,-2},{1,-2},{-1,-1},{-1,0},{0,0},{1,0},{-1,1},{-1,2},{0,2},{1,2},{1,1}}
#define SEVEN_REL_INDEX {{-1,-2},{0,-2},{1,-2},{1,-1},{1,0},{1,1},{1,2}}
#define EIGHT_REL_INDEX {{-1,-2},{0,-2},{1,-2},{-1,-1},{1,-1},{-1,0},{1,0},{-1,1},{1,1},{-1,2},{0,2},{1,2},{0,0}}
#define NINE_REL_INDEX {{-1,-2},{0,-2},{1,-2},{-1,-1},{1,-1},{-1,0},{0,0},{1,0},{1,1},{1,2},{0,2},{-1,2}}
#define REL_INDEX_LIST {ZERO_REL_INDEX,ONE_REL_INDEX,TWO_REL_INDEX,THREE_REL_INDEX,FOUR_REL_INDEX,FIVE_REL_INDEX,SIX_REL_INDEX,SEVEN_REL_INDEX,EIGHT_REL_INDEX,NINE_REL_INDEX};
#define INITIATE_INDEX (BOARD_SIDE_WIDTH+HORIZONTAL_BLOCK_NUM/2-1),(BOARD_TOP_WIDTH-2-1)
#define MAX_REL_INDEX_NUM 15
////方块
struct Block {
	Index abs_index;
	int index_num;
	Index* rel_index;
	int color;
	int angle = 0;
};

//操控
void make_board(int matrix[BOARD_HEIGHT][BOARD_WIDTH]);
void fall(struct Block* block, int(*board)[BOARD_WIDTH],int speed);
int game_continue(int(*board)[BOARD_WIDTH]);
void merge(struct Block block,int(*board)[BOARD_WIDTH]);
int pop(int(*board)[BOARD_WIDTH]);
void update_info(int erase_sum, int next_num);

//解答
void game(void);
