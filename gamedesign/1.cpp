#include<stdio.h>
#include<windows.h>
#include<conio.h>  //接收键盘输入输出 
#include<time.h>

#define HEIGHT 24//界面高度为24 
#define WIDTH 78//界面宽度为78 

//********************************************************************* 
void Page();                           //打印开始页面 
void gotoxy(int x,int y);              //光标跳转 ，也就是将光标移动到控制台的（x，y）坐标处 
void BorderPrint();                    //边框打印 
void gotoprin(int x,int y);           //跳转打印边框 
int color(int c);                      //改变颜色 
void InitSnake();                      //初始化蛇 ，打印蛇身 
//void MoveSnake();                      //移动 
void HideCursor();					   //光标的隐藏 
char Get();								//获取玩家指令中蛇的方向 
void gotoprint(int x,int y);			//打印蛇的方块颜色 
void ChangeBody(int a,int b);			//改变方向后，改变蛇的后半身 
int ClickControl();    					//获取键盘信号 
void MovingBody();				       //实现蛇的坐标位置的改变 
void CreatFood();					    //创造食物 
void Eating();							//吃掉食物之后边长 
int Judge(); 							//判断是否撞墙或者咬到自己 
void Finish();
//******************************************************************* 
struct Snake//定义蛇身的结构体，结点 
{ 
	int x;
	int y;
	struct Snake *next; 
}snake;
 Snake *head,*tail;
 struct Food
 {
 	int x;
 	int y;
 }food;
 
char name[20];//玩家名字 
int score=0;//玩家成绩 
int speed;
char click=1;

//********************************************************************* 
void gotoxy(int x,int y)
{	
	HANDLE handle;//定义句柄变量handle，windows 
    COORD coord;//定义结构体coord，坐标系，windows 
	 coord.X=x;//横坐标 
	 coord.Y=y;//纵坐标
	 handle=GetStdHandle(STD_OUTPUT_HANDLE);
	 SetConsoleCursorPosition(handle,coord);//移动光标 
}

//********************************************************************* 
void gotoprin(int x,int y)//打印游戏边框 
{
	gotoxy(x,y); 
	color(5);//7是白色 
	printf("■");
}
void gotoprint(int x, int y)//打印蛇 
{
	gotoxy(x, y);
	color(14);
	printf("■");
} 

//********************************************************************* 
void HideCursor()//隐藏光标 
{
	CONSOLE_CURSOR_INFO cursor;
	cursor.bVisible=FALSE;
	cursor.dwSize=sizeof(cursor);
	HANDLE handle =GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(handle,&cursor);
}

//********************************************************************* 
int color(int c)//改变颜色 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c); //设置控制台具体颜色 
	return 0;	//GetStdHandle(STD_OUTPUT_HANDLE)获取输出流的句柄 ，windows 
}

//********************************************************************* 
void Page()//打印开始界面 
{
	
	gotoxy(15,10);
	color(12);
	printf("/*******************************贪吃蛇小游戏********************************/");
	gotoxy(15,20);
	color(12);
	printf("/***************************************************************************/");
	color(11);
	gotoxy(15,13);
	printf("请设置您的玩家名称：");
	scanf("%s",&name);
	gotoxy(15,17);
	printf("正在进入游戏......");
	 
	Sleep(600);//休眠600毫秒 ，在头文件windows里面 
	system("cls");//清屏 ，属windows 
} 

//********************************************************************* 

void BorderPrint()//游戏界面边框及相关信息的打印 
{
	int i,j;
	for(i=0;i<=WIDTH;i+=2)//打印上下边框 
	{
		gotoprin(i,0);
		gotoprin(i,HEIGHT);
	}
	for(i=0;i<=HEIGHT;i++)//打印左右边框 
	{
		gotoprin(0,i);
		gotoprin(WIDTH,i);
	}
	for(i = 2;i<WIDTH;i+=2)	//打印中间网格
	{
		for(j = 1;j<HEIGHT;j++)
		{
			gotoxy(i,j);
			color(3);
			printf("■");
		}
	}
	gotoxy(82,6);
	printf("hello %s,welcome to play",name);
	gotoxy(82,8);
	printf("your score is %d ",score);
	color(12);
	gotoxy(82,12);
	printf("规则小提示：");
	gotoxy(82,14);
	printf("不能碰到墙"); 
	gotoxy(82,15);
	printf(" ↑向上	↓向下");
	gotoxy(82,16);
	printf("←向左     →向右");
}

//********************************************************************* 
void InitSnake()//打印蛇身 
{
	int i;
	tail=(Snake*)malloc(sizeof(snake));//malloc开辟snake的内存空间，并将申请到的空间地址转换成了Snake类型的空间地址，最后赋值给指向Snake型空间的tail指针 
	tail->x=34;        //蛇的初始位置（34，16） 
	tail->y=11;
//	gotoxy(tail->x,tail->y);
	tail->next=NULL;
	for(i=1;i<=3;i++)   //设置蛇身长度
	{
		head=(Snake*)malloc(sizeof(snake));//初始化蛇头 
		head->next=tail;     //蛇头的next指向蛇尾 ，也就是下一位置 
		head->x=34+i*2;          //设置蛇头位置 
		head->y=11;
		tail=head;           //将蛇头变为蛇尾，在继续下一个循环 
	}
	while(tail!=NULL)    //打印出蛇身 ，当蛇尾下一位置不是NULL时，继续打印 
	{
		gotoxy(tail->x,tail->y);
    	color(14);
    	printf("■");
    	tail=tail->next;   //输出蛇头，继续下一位，直到输出蛇尾 
    	
		}
	}
	


//********************************************************************* 
void ChangeBody(int a,int b)//（这里是改变蛇的身体，没有的话就只剩下头动了） 
{
	Snake *p = head->next;    //声明一个新的结构体变量 
	int mid1, mid2,_mid1,_mid2;  
	mid1 = p->x;
	mid2 = p->y;
	while (1)                  //使得原来的蛇身的最后两节坐标交换 
	{
		if (p->next->next == NULL) break;
		_mid1 = p->next->x;
		_mid2 = p->next->y;
		p->next->x = mid1;
		p->next->y = mid2;
		mid1 = _mid1;
		mid2 = _mid2; 
		p = p->next;
	}
	p = head->next;              //在使第二节蛇身变成原来的蛇头位置 
		p->x = a;
		p->y = b;
}

//********************************************************************* 
int ClickControl()    //获取键盘信号 
{
//	char c;
	while (1)
	{
		HideCursor();
		if (Judge()==0) return 0;
		if (_kbhit())//检查是否有键盘输入，如果有则返回值为非0   conio头文件 
		{
			click =_getch();         //conio头文件 
//			click =_getch();
		}
		MovingBody();//根据键盘操作对蛇身进行移动 
		Eating();//同时吃掉食物 
	}
	return 1;
}
//********************************************************************* 
void MovingBody()       //实现蛇的坐标位置的改变 
{
	int count = 0;
	int a = head->x, b = head->y;
	Snake *p = head;
	
	//通过先清空后打印实现动画效果
	while (1)
	{
		if (p == NULL) break;//打印蛇移动后变成背景色 
		gotoxy(p->x, p->y);
		color(3);
		printf("■");
		count++;
		p = p->next;
	}
		switch (click)
	{
		case 72:		//向上移动 
			head->y -= 1;
			ChangeBody(a,b);
			break;
		case 80:		//向下移动 
			head->y += 1;
			ChangeBody(a,b);
			break;
		case 75:		//向左移动 
			head->x -= 2;
			ChangeBody(a,b);
			break;
		case 77:		//向右移动 
			head->x += 2;
			ChangeBody(a,b);
			break;
	}
	p = head;
	while (1)     //依次输出改变过后的蛇的各个坐标 ，在没有改变方向之前，输出原来的坐标位置 
	{
		if (p->next== NULL) break;
		gotoprint(p->x, p->y);
		p = p->next;
	}
	
	p = head;
//	gotoxy(0, 28);
	if (count <= 10) speed = 150;
	else if (count > 10 && count <= 20) speed = 100;
	else if (count > 20 && count <= 40) speed = 50;
	else speed = 10;
	Sleep(speed);

}

//********************************************************************* 
void CreatFood()			  //创造食物 
{
	srand((int)time(NULL));
	E:
		food.x=rand()%(76-2+1)+2;
		food.y=rand()%(23-1+1)+1;
		if(food.x%2!=0)
		{
			food.x=food.x+1;//如果生成的食物不是偶数，则加一使其变成偶数，确保蛇能完全吃上食物 
		 } 
		 Snake *judge=head;
		 while(1)//遍历确保生成的食物不在蛇身上 
		 {
		 	if(judge->next==NULL);
			 break;
			if(food.x==judge->x&&food.y==judge->y)
			{
				goto E;
			}
			judge=judge->next;
		 }
		 gotoxy(food.x,food.y);
		 color(14);
		 printf("★");
} 

//********************************************************************* 
void Eating()	//吃食物并伸长(同时伸长)
{	Snake *p;
	if(head->x==food.x&&head->y==food.y)
	{
		CreatFood();
		Snake *_new = (Snake*)malloc(sizeof(snake));
		p = head->next;
        while(p->next)
        {
            p=p->next;
        }
        p->next=_new;
        _new->next=NULL;
		score += 10;
		gotoxy(82,8);
		printf("your score is %d ",score);
	}

}
//*********************************************************************
int Judge()		//判断是否撞墙或者咬到自己 
{
	if (head->x == 0|| head->x == 78 || head->y == 0 || head->y == 24)
	{
		Finish();
		return 0;
	}
	Snake *p = head->next;
	while (1)
	{
		if (p->next == NULL) break;
		if (head->x == p->x&&head->y == p->y)
		{
			Finish();
			return 0;
		}
		p = p->next;
	}
	return 1;
}
//********************************************************************* 
void Finish()
{
	system("cls");
	gotoxy(15,10);
	printf("************************************************");
	gotoxy(18,13);
	printf("Game over！");
	gotoxy(18,15);
	printf("你的成绩是：%d分",score);
	gotoxy(18,16);
	printf("继续加油哦(⊙o⊙)");
	gotoxy(15,20);
	printf("************************************************");
	
	system("pause");//去掉结尾的显示 
	
}
//********************************************************************* 
int main()
{	
	//	system("color F1");//将界面颜色置为白色，蓝字 
    Page();//进入开始界面 
    BorderPrint();//打印游戏开始界面边框 
    InitSnake();//打印蛇
	CreatFood(); 
	MovingBody();
	if (ClickControl() == 0) return 0;
	return 0;
	
}
