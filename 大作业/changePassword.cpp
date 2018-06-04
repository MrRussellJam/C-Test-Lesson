//修改密码  
int changePassword(char s[])  
{
	int i;
	char s1[18];
	printf("输入原密码:\n");

	for (i = 0; i < 18; i++)
	{
		if (i < 0) i = 0;
		s1[i] = getch();
		if (s1[i] == '\r')   break;
		if (s1[i] == '\b')
		{
			i -= 2;
			printf("\b \b");
			continue;
		}
		printf("*");
	}
	s1[i] = '\0';

	if (strcmp(s1, s) == 0)
	{
		printf("\n密码正确！原始密码为:\n");
		printf("%s\n", s1);
		printf("请输入新密码:\n");

		for (i = 0; i < 18; i++)
		{
			if (i < 0) i = 0;
			s1[i] = getch();
			if (s1[i] == '\r') break;
			if (s1[i] == '\b')
			{
				i -= 2;
				printf("\b \b");
				continue;
			}
			printf("*");
		}
		s1[i] = '\0';
		printf("\n\n");
		strcpy(s, s1);
	}
	else 
	{
		printf("密码错误!\n");
		exit(0);
	}
	return 1;
}
