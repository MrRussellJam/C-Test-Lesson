//输出源文件
int inDate(studentMessage stu[])  
{
	studentMessage number[1024];
	int i, k;
	FILE *fp;
	fp = fopen("Student_Info.txt", "r");
	if (fp == NULL)
	{
		printf("无法打开文件！\n");
		exit(0);
	}
	
	i = 0;
	while(!feof(fp))
	{
		fscanf(fp, "%d%s%d%d", &stu[i].id, stu[i].name, &stu[i].sex, &stu[i].college);
		for (k = 0; k < 10; k++)
		{
			fscanf(fp, "%d", &stu[i].grade[k]);
		}
		i++;
	}
	printf("学号\t姓名\t性别\t学院\t课程1\t课程2\t课程3\t课程4\t课程5\t课程6\t课程7\t课程8\t课程9\t课程10\n");
	for (int n = 0; n < i - 1; n++)
	{
		printf("%d\t%s\t%d\t%d\t", stu[n].id, stu[n].name, stu[n].sex, stu[n].college);
		for (k = 0; k < 10; k++)
		{
			printf("%d\t", stu[n].grade[k]);
		}
		printf("\n");
	}
	return i-1;
}
