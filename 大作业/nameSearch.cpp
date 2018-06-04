//按照姓名查找学生
void nameSearch(studentMessage stu[], int n)
{
	int i;
	char nameTemp[20];
	printf("\n*******************************************************\n");
	printf("请输入需要查找的学生姓名:");
	scanf("%s", nameTemp);

	if (stu[2].avegrade > 0)printf("学号\t姓名\t性别\t学院\t课程1\t课程2\t课程3\t课程4\t课程5\t课程6\t课程7\t课程8\t课程9\t课程10\t平均数\n");
	else printf("学号\t姓名\t性别\t学院\t课程1\t课程2\t课程3\t课程4\t课程5\t课程6\t课程7\t课程8\t课程9\t课程10\n");

	for (i = 0; i < n; i++)
	{
		if (strcmp(nameTemp, stu[i].name) == 0)
		{
			printf("%d\t%s\t%d\t%d\t", stu[i].id, stu[i].name, stu[i].sex, stu[i].college);
			for (int j = 0; j < 10; j++)
			{
				printf("%d\t", stu[i].grade[j]);
			}
			if (stu[i].avegrade > 0) printf("%.2f", stu[i].avegrade);
			printf("\n");
			return;
		}
	}
	printf("没有这名学生。\n");
}
