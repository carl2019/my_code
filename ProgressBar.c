#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main()
{
	int i = 0;
	char bar[102];
	memset(bar, 0, sizeof(bar));
	const char* lable = "|/-\\";
	while(i <= 100)
	{
	    printf("\033[32m[%-100s]\033[0m [%d%%][%c]\r", bar, i, lable[i%4]);
		fflush(stdout);
		bar[i++] = '#';
		usleep(100000);
	}
	printf("\n");
	return 0;
}
