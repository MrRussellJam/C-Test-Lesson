
//学生成绩信息修改
void changeMessage(studentMessage s[],int n)
{
	studentMessage stu[100];
	int temp;
	FILE *fp;
	int i, j;

	for (i = 0; i < length; i++)  stu[i] = s[i];

	fp = fopen("Student_Info.txt", "w");
	printf("\n*******************************************************\n");
	printf("请输入需要修改成绩信息的学生学号:");
	scanf("%d", &temp);
	if (stu[2].avegrade > 0)printf("学号\t姓名\t性别\t学院\t课程1\t课程2\t课程3\t课程4\t课程5\t课程6\t课程7\t课程8\t课程9\t课程10\t平均数\n");
	else printf("学号\t姓名\t性别\t学院\t课程1\t课程2\t课程3\t课程4\t课程5\t课程6\t课程7\t课程8\t课程9\t课程10\n");
	for (i = 0; i < n; i++)
	{
		if (temp == stu[i].id)
		{
			printf("%d\t%s\t%d\t%d\t", stu[i].id, stu[i].name, stu[i].sex, stu[i].college);
			for (j = 0; j < 10; j++)
			{
				printf("%d\t", stu[i].grade[j]);
			}
			if (stu[i].avegrade > 0) printf("%.2f", stu[i].avegrade);
			break;
		}
	}
	if (i > n)
	{
		printf("\n学号错误！\n");
		return;
	}

	printf("\n不更改请输 0 \n");
	while (1)
	{
		printf("请输入需要改的课程:");
		scanf("%d", &temp);
		if (temp < 0 || temp>10)
		{
			printf("输入错误\n");
			continue;
		}
		if (temp == 0) break;

		printf("课程 %d 的成绩为 %d\n", temp, stu[i].grade[temp-1]);
		printf("请输入改的成绩:");
		scanf("%d", &stu[i].grade[temp-1]);
	}
	int count=0;
	for (j = 0; j < 10; j++)
	{
		count += stu[i].grade[j];
	}

	stu[i].avegrade = count / 10.0;

	int a = i;
	for (i = 0; i < length; i++)
	{
		if (stu[a].id == s[i].id) s[i] = stu[a];
	}

	for (i = 0; i < n; i++)
	{
		fprintf(fp, "%d\t%s\t%d\t%d\t", stu[i].id, stu[i].name, stu[i].sex, stu[i].college);
		for (j = 0; j < 10; j++)
		{
			fprintf(fp,"%d\t", stu[i].grade[j]);
		}
		fprintf(fp, "\n");
	}

}

