#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

struct Stu //结构体
{
	int num;
	char name[20];
	char sex[20];
	int age;
	float score[3];
	struct Stu *next;
} stu[100];

//////////////////////////////////////////

int link()
{
	int t;
	FILE *fp = NULL;
	fp = fopen("student.txt", "ab+");
	fseek(fp, 0, SEEK_END);
	t = ftell(fp);
	fclose(fp);
	return t;
}

void save(struct Stu *head) //保存到文件
{
	struct Stu *p = NULL;
	int eof = EOF;
	p = head;
	FILE *fp;
	if ((fp = fopen("student.txt", "ab+")) == NULL)
	{
		printf("打开文件失败\n");
	}
	else
	{
		printf("保存成功\n");
	}
	while (p != NULL)
	{
		fwrite(p, sizeof(struct Stu), 1, fp);
		p = p->next;
	}
	fwrite(&eof,sizeof(eof),1,fp); //文件需要输出文件结尾符：https://blog.csdn.net/weixin_30821731/article/details/95099549
	fclose(fp);
}

struct Stu *read() //读取
{
	int t;
	struct Stu *head, *p, *p0;
	head = NULL;
	FILE *fp;
	if ((fp = fopen("student.txt", "rb+")) == NULL)
	{
		printf("打开文件失败\n");
		return head;
	}
	t = link();
	if (t == 0)
	{
		return head;
	}
	//更改一下输入过程
	p0 = (struct Stu *)malloc(sizeof(struct Stu));
	fread(p0, sizeof(struct Stu), 1, fp);
	head = p = p0;
	while (p0->next != NULL)
	{
		p0 = (struct Stu *)malloc(sizeof(struct Stu));
		p->next = p0;
		p = p0;
	}
	p->next = NULL;
	p = NULL; //清空p和p->next
	fclose(fp);
	return head;
}

////////////////////////////////////////////////////////

void list() //函数目录
{
	printf("\t\t\t\t\t****************欢迎使用本系统*****************\n");
	printf("\t\t\t\t\t*****************1.录入************************\n");
	printf("\t\t\t\t\t*****************2.添加************************\n");
	printf("\t\t\t\t\t*****************3.修改************************\n");
	printf("\t\t\t\t\t*****************4.删除************************\n");
	printf("\t\t\t\t\t*****************5.显示************************\n");
	printf("\t\t\t\t\t*****************6.读取************************\n");
	printf("\t\t\t\t\t*****************7.退出************************\n");
}

struct Stu *create() //创建
{

	struct Stu *head = NULL, *p = NULL, *p0 = NULL; //结构体指针变量
	p0 = (struct Stu *)malloc(sizeof(struct Stu));	//强制转换+申请内存
	p = head = p0;
	int num;//用来缓存学号
	boolean flag = false;
	printf("请输入学生的学号(0 停止输入):");
	scanf("%d", &num);
	while (num != 0) //负责输入，并判断学号是否为0
	{
		flag =true;
		p0->num = num;
		printf("请输入学生的姓名:");
		scanf("%s", p0->name);
		printf("请输入学生的性别:");
		scanf("%s", p0->sex);
		printf("请输入学生的年龄:");
		scanf("%d", &(p0->age));
		printf("请输入学生的语文成绩:");
		scanf("%f", &(p0->score[0]));
		printf("请输入学生的数学成绩:");
		scanf("%f", &(p0->score[1]));
		printf("请输入学生的C语言成绩:");
		scanf("%f", &(p0->score[2]));
		printf("\n");
		printf("请输入学生的学号(0 停止输入):");
		scanf("%d", &num);
		if (num)//如果学号为0就不分配地址
		{
			p0 = (struct Stu *)malloc(sizeof(struct Stu));
			p->next = p0;
			p = p0;
		}
	}
	p->next = NULL;
	if (flag)//如果没有写入数据就不保存
	{
		save(head);
	}
	return head;
}

struct Stu *add(struct Stu *head) //增加
{

	struct Stu *p = NULL, *p0 = NULL;
	p = head;
	printf("\n请输入要增加的学生信息\n\n");
	if (head == NULL)
	{
		p0 = (struct Stu *)malloc(sizeof(struct Stu));
		printf("请输入学生的学号:");
		scanf("%d", &p0->num);
		printf("请输入学生的姓名:");
		scanf("%s", p0->name);
		printf("请输入学生的性别:");
		scanf("%s", p0->sex);
		printf("请输入学生的年龄:");
		scanf("%d", &p0->age);
		printf("请输入学生的语文成绩:");
		scanf("%f", &p0->score[0]);
		printf("请输入学生的数学成绩:");
		scanf("%f", &p0->score[1]);
		printf("请输入学生的C语言成绩:");
		scanf("%f", &p0->score[2]);
		head = p0;
		p0->next = NULL;
	}
	else
	{
		while (p->next != NULL)
		{
			p = p->next;
		}
		p0 = (struct Stu *)malloc(sizeof(struct Stu));
		printf("请输入学生的学号:");
		scanf("%d", &p0->num);
		printf("请输入学生的姓名:");
		scanf("%s", p0->name);
		printf("请输入学生的性别:");
		scanf("%s", p0->sex);
		printf("请输入学生的年龄:");
		scanf("%d", &p0->age);
		printf("请输入学生的语文成绩:");
		scanf("%f", &p0->score[0]);
		printf("请输入学生的数学成绩:");
		scanf("%f", &p0->score[1]);
		printf("请输入学生的C语言成绩:");
		scanf("%f", &p0->score[2]);
		p->next = p0;
		p = p0;
		p->next = NULL;
	}
	save(head);
	return head;
}

struct Stu *change(struct Stu *head) //修改
{

	int n;
	struct Stu *p = NULL;
	p = head;
	printf("请输入需要修改的学生的学号：");
	scanf("%d", &n);

    if(head == NULL){
		printf("没有导入数据！\n");
		return head;
	}

	while (p->num != n)
	{
		p = p->next;
	}

	printf("请输入要把姓名修改为:");
	scanf("%s", p->name);
	printf("请输入要把性别修改为:");
	scanf("%s", p->sex);
	printf("请输入要把年龄修改为:");
	scanf("%d", &p->age);
	printf("请输入要把语文成绩修改为:");
	scanf("%f", &p->score[0]);
	printf("请输入要把数学成绩修改为:");
	scanf("%f", &p->score[1]);
	printf("请输入要把C语言成绩修改为:");
	scanf("%f", &p->score[2]);

	save(head);
	return head;
}

struct Stu *delet(struct Stu *head) //负责删除
{

	char na[20];
	struct Stu *p = NULL, *p0 = NULL;
	p0 = p = head;
	printf("请输入删除学生姓名：");
	scanf("%s", na);
	if(head == NULL){
		printf("没有学生信息\n");
		return head;
	}
	if (strcmp(p->name, na) == 0)
	{
		head = p->next;
	}
	else
	{
		while (p != NULL)
		{

			if (strcmp(p->name, na) == 0)
			{
				p0->next = p0->next->next;
			}
			p0 = p;
			p = p->next;
		}
	}
	save(head);
	return head;
}

void show(struct Stu *head) //输出
{

	struct Stu *p0 = NULL;
	p0 = head;
	if (head == NULL)
	{
		printf("\t\t信息内存为空\n\n\n");
	}

	while (p0 != NULL)
	{
		printf("学生的学号:");
		printf("%d", p0->num);
		printf("\n学生的姓名:");
		printf("%s", p0->name);
		printf("\n学生的性别:");
		printf("%s", p0->sex);
		printf("\n学生的年龄:");
		printf("%d", p0->age);
		printf("\n学生的语文成绩:");
		printf("%.2f", p0->score[0]);
		printf("\n学生的数学成绩:");
		printf("%.2f", p0->score[1]);
		printf("\n学生的C语言成绩:");
		printf("%.2f", p0->score[2]);
		printf("\n\n\n\n\n");
		p0 = p0->next;
	}
}

int main() ////主函数
{

	int n;
	struct Stu *head = NULL;
	while (1) //通过目录引向各个...
	{
		list();
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			head = create(); //录入
			break;
		case 2:
			head = add(head); //添加
			break;
		case 3:
			head = change(head); //修改
			break;
		case 4:
			head = delet(head); //删除
			break;
		case 5:
			show(head); //显示
			break;
		case 6: //读取
			head = read();
			break;
		case 7: //退出
			return 0;
			break;
		}
	}
	return 0;
}