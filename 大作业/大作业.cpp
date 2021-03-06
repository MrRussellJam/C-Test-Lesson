#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

int length;   //数据长度

//学生成绩结构体
struct studentMessage
{
	int id;
	char name[20] = { 0 };
	int college;
	int sex;
	int grade[10];
	float avegrade;
};


#include "changeMessage.cpp"
#include "inDate.cpp"
#include "nameSort.cpp"
#include "aveSort.cpp"
#include "changePassword.cpp"
#include "nameSearch.cpp"
#include "searchStudent.cpp"

int main()
{
	char password[18]; //密码
	int select;        //选择菜单
	int i;
	printf("请输入初始密码：\n");

	for (i = 0; i < 18; i++)
	{
		if (i < 0) i = 0;
		password[i] = getch();
		if (password[i] == '\r')  break;
		if (password[i] == '\b')
		{
			i -= 2;
			printf("\b \b");
			continue;
		}
		printf("*");
	}
	password[i] = '\0';
	printf("\n\n");

	studentMessage date[1024];

	while (1)
	{
		printf("*******************学生成绩系统菜单*******************\n");
		printf("1. 原始文件读取\n");
		printf("2. 按姓名排序，输出 \n");                                                     //todo证明已排序
		printf("3. 按平均成绩排序，输出 \n");
		printf("4. 输出给定学院学生 \n");
		printf("5. 修改给定学生成绩信息（修改后的信息，需输出到文件）\n");
		printf("6. 按姓名查询学生，输出 \n");
		printf("7. 修改系统密码* \n");
		printf("0. 返回上一级菜单 \n");
		printf("******************************************************\n");

		printf("输入想要执行的菜单代码:");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			length = inDate(date);
			break;
		case 2:
			nameSort(date, length);
			break;
		case 3:
			aveSort(date, length);
			break;
		case 4:
			searchStudet(date, length);
			break;
		case 5:
			changeMessage(date, length);
			break;
		case 6:
			nameSearch(date, length);
			break;
		case 7:
			changePassword(password);
			break;
		case 0:
			exit(0);
		default:
			printf("请输入正确指令!\n");
			break;

		}
	}
	return 0;
}