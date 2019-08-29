#include "tools.h"

//获取指令
char get_cmd(char start,char end)
{
	clear_stdin();

	printf("请输入指令:");
	for(;;)
	{
		char val = getch();
		if(val >= start && val <= end)
		{
			printf("%c\n",val);
			return val;
		}
	}
}


//清理输入缓冲区
void clear_stdin(void)
{
	stdin->_IO_read_ptr = stdin->_IO_read_end;
}





