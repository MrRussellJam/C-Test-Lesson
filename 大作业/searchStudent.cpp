//输出学院学生
void searchStudet(studentMessage stu[], int n)
{
	FILE *fp;
	char ch;
	int num;
	int i;
	fp = fopen("C_Info.txt", "r");
	ch = fgetc(fp);
	while (!feof(fp))
	{
		putchar(ch);
		ch = fgetc(fp);
	}
	printf("\n******************************************************\n");
	printf("请输入需要搜索的学院学生:");
	scanf("%d", &num);

	if (stu[2].avegrade > 0)printf("学号\t姓名\t性别\t学院\t课程1\t课程2\t课程3\t课程4\t课程5\t课程6\t课程7\t课程8\t课程9\t课程10\t平均数\n");
	else printf("学号\t姓名\t性别\t学院\t课程1\t课程2\t课程3\t课程4\t课程5\t课程6\t课程7\t课程8\t课程9\t课程10\n");

	for (i = 0; i < n; i++)
	{
		if (stu[i].college == num)
		{
			printf("%d\t%s\t%d\t%d\t", stu[i].id, stu[i].name, stu[i].sex, stu[i].college);
			for (int k = 0; k < 10; k++)
			{
				printf("%d\t", stu[i].grade[k]);
			}
			if (stu[i].avegrade > 0) printf("%.2f", stu[i].avegrade);
			printf("\n");
		}
	}
}
