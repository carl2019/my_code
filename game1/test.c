#include "game.h"  

void menu()
{
	printf("********************\n");
	printf("****   1.play   ****\n");
	printf("****   0.exit   ****\n");
	printf("********************\n");
}

void game()
{
	//printf("玩游戏\n");
	char board[ROW][COL] = {0};
	char ret = 0;
	InitBoard(board, ROW, COL); //初始化棋盘
	DisplayBoard(board, ROW, COL); //打印棋盘

	while(1)
	{
		ComputerMove(board, ROW, COL); //电脑走
		ret = IsWin(board, ROW, COL);
		if(ret != ' ')
		{
			break;
		}
		DisplayBoard(board, ROW, COL); 
		PlayerMove(board, ROW, COL); //玩家走
		ret = IsWin(board, ROW, COL);
		if(ret != ' ')
		{
			break;
		}
		DisplayBoard(board, ROW, COL);
	}
	if(ret == 'X')
	{
		printf("电脑赢\n");
	}
    else if(ret == '0')
	{
		printf("玩家赢\n");
	}
	else if(ret == 'Q')
	{
		printf("平局\n");
	}
	DisplayBoard(board, ROW, COL);
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:>");
		scanf_s("%d",&input);
		switch(input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("游戏结束\n");
			break;
		default:
			printf("输入有误，请重新输入\n");
			break;
		}
	}while(input);

	return 0;
}