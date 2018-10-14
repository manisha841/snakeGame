#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<cstdlib>
#include<ctime>
#include<time.h>
#include<windows.h>
#define width 70
#define height 70

using namespace std;

//The global map

char ma[width][height];
int headr=1;
int headc=1;
int w=width,h=height;
char ch = 'w';
int initialize=0;


//Structure of the Snake
struct sbody
{
	char data;
	char* loc;
	int cc;
	struct sbody *next;
}*root=NULL,*temp,*ptr;


//The functions according to precedence

void frame(){

for(int i=0;i<width;i++)
{
	for(int j=0;j<height;j++)
	{
		if(i==0)//for the top row
		ma[i][j]='-';
		else if(i==height-1)//for the bottom row
		ma[i][j]='-';
		else if(j==0)//for the left margin
		ma[i][j]='|';
		else if(j==width-1)//for the right margin
		ma[i][j]='|';
		else
		ma[i][j]=' ';
	}
}
}


//displaying the finished frame
void display()
{
	for(int i=0;i<width;i++)
	{
		for(int j=0;j<height;j++)
		{
			cout<<ma[i][j];
		}
	cout<<endl;
	}
}

void appendbody(){
	temp=(struct sbody*)malloc(sizeof(struct sbody));
	if(root==NULL)
	{
		root=temp;
		root->data='0';
		free(temp);
	}
	else
	{
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
	ptr->next=temp;
	}
}

//adress of ma[][] head that is actually moved
void movebody(char* a){
	char*b;
	b=root->loc;
	ptr=root;
	root->loc=a;
	while(ptr->next!=NULL)
	{
		//transferring the previous address to every next node
	  ptr=ptr->next;
	  b=a;
	  a=ptr->loc;
	  ptr->loc=b;
	}
}

//changing and parsing value each time the display is going on
void setcanvas(){
frame();
	
}

void MaximizeOutputWindow(void)
{
    HWND consoleWindow = GetConsoleWindow(); // This gets the value Windows uses to identify your output window 
    ShowWindow(consoleWindow, SW_MAXIMIZE); // this mimics clicking on its' maximize button
}
 

//To deicde the position of the snake's apettite
char* newFruit(){
int w=1+(rand()%(width-2));
int h=1+(rand()%(height-2));
return &ma[w][h];
}


void moveDown(){
	int i=0;
	do{
	system("CLS");
	headr++;
	ma[headr][headc]='O';
	display();
	i++;
	}while(i<height-3);
}

void move(char ch)
{
	switch(ch)
	{
		case 'w':w--;
		         movebody(&ma[w][h]);
		         break;
		case 's':w++;
		         //implement it on ma
		         ma[w][h]='V';
		         break;
		case 'a':h--;
		         ma[w][h]='<';
				 break;
		case 'd':h++;
		         ma[w][h]='>';
				 break;		          
	}
}


void setGame(){
if(initialize==0)
{
	system("CLS");
	appendbody();
	frame();
	display();
	initialize++;
	}else{
		system("CLS");
	if(_kbhit())
	{
		ch=(_getch());
		switch(ch)
		{
			case 'w':move('w');
			         break;
			case 's':move('s');
			         break;
			case 'a':move('a');
			         break;
			case 'd':move('d');
			         break;
			case 'x':initialize=-1;		 		          
			         break;
		}
	}else
	{
		move(ch);
	}
		display();
	}	
}


//<<<<<<
void logic()
{
	
}

int main()
{
	MaximizeOutputWindow();
	while(initialize!=-1)
	{
		setGame();
		Sleep(100);
	}
	return 0;

}
