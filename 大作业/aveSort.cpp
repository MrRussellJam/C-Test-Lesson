//平均成绩排序
void aveSort(studentMessage s[], int n)
{
	studentMessage temp;
	int i, j;
	int count;

	studentMessage stu[100];
	for (i = 0; i < length; i++)   stu[i] = s[i];

	for (i = 0; i < n; i++)
	{
		count = 0;
		for (j = 0; j < 10; j++)
		{
			count += s[i].grade[j];
		}
		s[i].avegrade = count / 10.0;
	}

	for (i = 0; i < length; i++)   stu[i] = s[i];

	for (i = 1; i < n; i++)
	{
		for (j = 0; j < n - i; j++)
		{
			if (stu[j].avegrade < stu[j + 1].avegrade)
			{
				temp = stu[j];
				stu[j] = stu[j + 1];
				stu[j + 1] = temp;
			}
		}
	}


	if (stu[2].avegrade > 0)printf("学号\t姓名\t性别\t学院\t课程1\t课程2\t课程3\t课程4\t课程5\t课程6\t课程7\t课程8\t课程9\t课程10\t平均数\n");
	else printf("学号\t姓名\t性别\t学院\t课程1\t课程2\t课程3\t课程4\t课程5\t课程6\t课程7\t课程8\t课程9\t课程10\n");

	for (i = 0; i < length; i++)
	{
		printf("%d\t%s\t%d\t%d\t", stu[i].id, stu[i].name, stu[i].sex, stu[i].college);
		for (j = 0; j < 10; j++)
		{
			printf("%d\t", stu[i].grade[j]);
		}
		printf("%.2f", stu[i].avegrade);
		printf("\n");
	}


}
