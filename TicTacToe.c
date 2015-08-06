#include<stdio.h>
#include<time.h>
#include"conio.h"
#include<stdlib.h>

int count=0;
void result(char res);
void test(char a[3][3])
{
	if( (a[0][0]==a[0][1])&&(a[0][0]==a[0][2])&&(a[0][0]!='.') )       
	        result(a[0][0]);
	if( ((a[1][0]==a[1][1])&&(a[1][0]==a[1][2]))&&(a[1][0]!='.') )   
	        result(a[1][0]);
	if( ((a[2][0]==a[2][1])&&(a[2][0]==a[2][2]))&&(a[2][0]!='.') )
	        result(a[2][0]);
	if( ((a[0][0]==a[1][0])&&(a[0][0]==a[2][0]))&&(a[0][0]!='.') )       
	        result(a[0][0]);
	if( ((a[0][1]==a[1][1])&&(a[0][1]==a[2][1]))&&(a[0][1]!='.') )
	        result(a[0][1]);
	if( ((a[0][2]==a[1][2])&&(a[0][2]==a[2][2]))&&(a[0][2]!='.') )
	        result(a[0][2]);
	if( ((a[0][0]==a[1][1])&&(a[0][0]==a[2][2]))&&(a[0][0]!='.') )
	        result(a[0][0]);
	if( ((a[0][2]==a[1][1])&&(a[0][2]==a[2][0]))&&(a[0][2]!='.') )
	        result(a[0][2]);
}
void result(char res)
{
    if(res=='x')
        printf("computer wins\n");
    else
        printf("you win\n");
	getch();
	exit(0);
}
void output(char a[3][3]) //Displays the matrix each time
{
	int i,j;
	system("clear");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			printf("%c\t",a[i][j]);
		printf("\n");
	}
	printf("\n");
	test(a);    //tests if there are 3 consicutive x or y
    if(count==9)//all slots are entered
	{
	    printf("the match is a draw\n");
	    getch();
	    exit(0);
    }
}
int user_choice(char a[3][3])
{
	int i,j,y;
	printf("enter position of y");
	scanf("%d",&y);
    j=(y-1)%3;//converts position(0-9) to array index(00-22)
    i=(y-1)/3;//---
	if(a[i][j]=='.')//checks if position is not used previously
	{
		a[i][j]='y';
		count++;
		output(a);
	}
	else
	{
		printf("enter proper input\n");
		user_choice(a);
	}
	return y;
}
void comp_choice(char a[3][3])
{
	int i,j;
	long t;
	if( (a[0][0]==a[0][1])&&(a[0][0]!='.')&&(a[0][2]=='.') ){i=0;j=2;}
	else if( (a[0][1]==a[0][2])&&(a[0][1]=='x')&&(a[0][0]=='.') ){i=0;j=0;}
	else if( (a[1][0]==a[1][1])&&(a[1][0]=='x')&&(a[1][2]=='.') ){i=1;j=2;}
	else if( (a[1][1]==a[1][2])&&(a[1][1]=='x')&&(a[1][0]=='.') ){i=1;j=0;}
	else if( (a[2][0]==a[2][1])&&(a[2][0]=='x')&&(a[2][2]=='.') ){i=2;j=2;}
	else if( (a[2][1]==a[2][2])&&(a[2][1]=='x')&&(a[2][0]=='.') ){i=2;j=0;}
	else if( (a[0][0]==a[1][0])&&(a[0][0]=='x')&&(a[2][0]=='.') ){i=2;j=0;}
	else if( (a[0][1]==a[1][1])&&(a[0][1]=='x')&&(a[2][1]=='.') ){i=2;j=1;}
	else if( (a[0][2]==a[1][2])&&(a[0][2]=='x')&&(a[2][2]=='.') ){i=2;j=2;}
	else if( (a[1][0]==a[2][0])&&(a[1][0]=='x')&&(a[0][0]=='.') ){i=0;j=0;}
	else if( (a[1][1]==a[2][1])&&(a[1][1]=='x')&&(a[0][1]=='.') ){i=0;j=1;}
	else if( (a[1][2]==a[2][2])&&(a[1][2]=='x')&&(a[0][2]=='.') ){i=0;j=2;}
	else if( (a[0][0]==a[1][1])&&(a[0][0]=='x')&&(a[2][2]=='.') ){i=2;j=2;}
	else if( (a[0][2]==a[1][1])&&(a[0][2]=='x')&&(a[2][0]=='.') ){i=2;j=0;}
	else if( (a[2][0]==a[1][1])&&(a[2][0]=='x')&&(a[0][2]=='.') ){i=0;j=2;}
	else if( (a[2][2]==a[1][1])&&(a[2][2]=='x')&&(a[0][0]=='.') ){i=0;j=0;}

	else if( (a[0][0]==a[0][2])&&(a[0][0]=='x')&&(a[0][1]=='.') ){i=0;j=1;}
	else if( (a[1][0]==a[1][2])&&(a[1][0]=='x')&&(a[1][1]=='.') ){i=1;j=1;}
	else if( (a[2][0]==a[2][2])&&(a[2][0]=='x')&&(a[2][1]=='.') ){i=2;j=1;}
	else if( (a[0][0]==a[2][0])&&(a[0][0]=='x')&&(a[1][0]=='.') ){i=1;j=0;}
	else if( (a[0][1]==a[2][1])&&(a[0][1]=='x')&&(a[1][1]=='.') ){i=1;j=1;}
	else if( (a[0][2]==a[2][2])&&(a[0][2]=='x')&&(a[1][2]=='.') ){i=1;j=2;}
	else if( (a[0][0]==a[2][2])&&(a[0][0]=='x')&&(a[1][1]=='.') ){i=1;j=1;}
	else if( (a[0][2]==a[2][0])&&(a[0][2]=='x')&&(a[1][1]=='.') ){i=1;j=1;}
	

	else if( (a[0][0]==a[0][1])&&(a[0][0]=='y')&&(a[0][2]=='.') ){i=0;j=2;}
	else if( (a[0][1]==a[0][2])&&(a[0][1]=='y')&&(a[0][0]=='.') ){i=0;j=0;}
	else if( (a[1][0]==a[1][1])&&(a[1][0]=='y')&&(a[1][2]=='.') ){i=1;j=2;}
	else if( (a[1][1]==a[1][2])&&(a[1][1]=='y')&&(a[1][0]=='.') ){i=1;j=0;}
	else if( (a[2][0]==a[2][1])&&(a[2][0]=='y')&&(a[2][2]=='.') ){i=2;j=2;}
	else if( (a[2][1]==a[2][2])&&(a[2][1]=='y')&&(a[2][0]=='.') ){i=2;j=0;}
	else if( (a[0][0]==a[1][0])&&(a[0][0]=='y')&&(a[2][0]=='.') ){i=2;j=0;}
	else if( (a[0][1]==a[1][1])&&(a[0][1]=='y')&&(a[2][1]=='.') ){i=2;j=1;}
	else if( (a[0][2]==a[1][2])&&(a[0][2]=='y')&&(a[2][2]=='.') ){i=2;j=2;}
	else if( (a[1][0]==a[2][0])&&(a[1][0]=='y')&&(a[0][0]=='.') ){i=0;j=0;}
	else if( (a[1][1]==a[2][1])&&(a[1][1]=='y')&&(a[0][1]=='.') ){i=0;j=1;}
	else if( (a[1][2]==a[2][2])&&(a[1][2]=='y')&&(a[0][2]=='.') ){i=0;j=2;}
	else if( (a[0][0]==a[1][1])&&(a[0][0]=='y')&&(a[2][2]=='.') ){i=2;j=2;}
	else if( (a[0][2]==a[1][1])&&(a[0][2]=='y')&&(a[2][0]=='.') ){i=2;j=0;}
	else if( (a[2][0]==a[1][1])&&(a[2][0]=='y')&&(a[0][2]=='.') ){i=0;j=2;}
	else if( (a[2][2]==a[1][1])&&(a[2][2]=='y')&&(a[0][0]=='.') ){i=0;j=0;}

	else if( (a[0][0]==a[0][2])&&(a[0][0]=='y')&&(a[0][1]=='.') ){i=0;j=1;}
	else if( (a[1][0]==a[1][2])&&(a[1][0]=='y')&&(a[1][1]=='.') ){i=1;j=1;}
	else if( (a[2][0]==a[2][2])&&(a[2][0]=='y')&&(a[2][1]=='.') ){i=2;j=1;}
	else if( (a[0][0]==a[2][0])&&(a[0][0]=='y')&&(a[1][0]=='.') ){i=1;j=0;}
	else if( (a[0][1]==a[2][1])&&(a[0][1]=='y')&&(a[1][1]=='.') ){i=1;j=1;}
	else if( (a[0][2]==a[2][2])&&(a[0][2]=='y')&&(a[1][2]=='.') ){i=1;j=2;}
	else if( (a[0][0]==a[2][2])&&(a[0][0]=='y')&&(a[1][1]=='.') ){i=1;j=1;}
	else if( (a[0][2]==a[2][0])&&(a[0][2]=='y')&&(a[1][1]=='.') ){i=1;j=1;}
	
	
	else
	{   
	    while(1)
	    {
		    srand(time(NULL));
		    t=(rand()%9+1);
            j=(t-1)%3;
            i=(t-1)/3;
		    if(a[i][j]=='.')
		        break;
        }
	}
	a[i][j]='x';
    count++;
	output(a);
}
void playerFirst(char a[3][3])
{
    int y,r,i;
    y=user_choice(a);
    if(y==5)
    {
        srand(time(NULL));
        r=rand()%4;
        a[(r/2)*2][(r%2)*2]='x';//selects one of 4 corners
        count++;
        output(a);
        
        
    }
    else
    {
        a[1][1]='x';
        count++;
        output(a);
        
        y=user_choice(a);
        printf("break\n");
        getch();
        if((a[0][0]=='y'&&a[2][2]=='y')||(a[0][2]=='y'&&a[2][0]=='y'))
        {
            srand(time(NULL));
            r=rand()%4;printf("random=%d\n",r);
            a[(r*2+1)/3][(r*2+1)%3]='x';
            count++;
            output(a);
        }    
        else
            comp_choice(a);
    }
    printf("break2");
    for(i=count/2;i<4;i++)
    {   
        user_choice(a);
        comp_choice(a);
    }
    user_choice(a);
}

int main()
{
	char a[3][3];
	int i,j,fstPlr=0;
	system("clear");
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			a[i][j]='.';
	output(a);
    printf("enter 0 to play 1st,1 to play 2nd\n");
    scanf("%d",&fstPlr);
    if(fstPlr==1)
    {
	    for(i=0;i<4;i++)
	    {
		    comp_choice(a);
		    user_choice(a);
	    }
	    comp_choice(a);
	    getch();
	}
	else
	    playerFirst(a);
}
