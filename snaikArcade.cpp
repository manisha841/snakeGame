#include<stdlib.h>
#include<conio.h>
#include<iostream>
#include<stdio.h>
#include<windows.h>
#define width 70
#define height 70

using namespace std;

//The global map

char ma[width][height];
int headr=1;
int headc=1;
int w=35,h=35;
char ch = 'd';
int initialize=0;



//body
struct node{
     char data;
     int rindex;
     int cindex;
     struct node* next;
}*root=NULL;

void append(char a,int r,int c)
{
	//gene created
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = a;
	temp->rindex = r;
	temp->cindex = c;
	temp->next = NULL;
	//cout<<"Location recievded in node:"<<&(*b);
	if(root==NULL)
	{
		//snake's head is being created;
		root=temp;
		root->data='0';
		
	}
	else
	{
		struct node* ptr;
		ptr=root;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next; //getting to last node
		}
		ptr->next=temp;//conecting the two nodes
		temp->data='o';
		}
}

void doChange(int r,int c)
{
	struct node* ptr;
	int tempr,tempc;
	//a for holding the new location of the head while b is a temporary variable
	//cout<<"In change";
	tempr = root->rindex;
	tempc = root->cindex; //point to address stored at root->idexes
	root->rindex = r;
	root->cindex = c;
	ptr = root->next;
	while(ptr!=NULL)
	{
		r = ptr->rindex;
		c = ptr->cindex;
		
		ptr->rindex = tempr;
		ptr->cindex = tempc;
		
		ptr=ptr->next;
	 } 
	 
	 //to check
	 //approach to void the location of the last node
	 if(root->next!=NULL)
	 ma[r][c]=' ';
	 else
	 ma[tempr][tempc]=' ';
	 //cout<<"Did change";
}

void applyChange()
{
	struct node*ptr;
	ptr=root;
	//cout<<"Applying change";
	while(ptr!=NULL)
	{
		ma[ptr->rindex][ptr->cindex]=ptr->data;
		ptr=ptr->next; //applying the change on the respective nodes
	}
}

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


void move(char ch)
{
	switch(ch)
	{
		case 'w':w--;
		         doChange(w,h);
		         applyChange();
		         break;
		case 's':w++;
		         //implement it on ma
		         doChange(w,h);
		         applyChange();
		         break;
		case 'a':h--;
		         doChange(w,h);
		         applyChange();
				 break;
		case 'd':h++;
		         doChange(w,h);
		         applyChange();
				 break;		          
	}
}


void setGame(){
if(initialize==0)
{
	system("CLS");
	frame();
	//appendbody();
	append('0',w,h);
	
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



int main()
{
	
	while(initialize!=-1)
	{
		setGame();
	    Sleep(1000);
	}
	return 0;

}
