#include<stdio.h>
#include<conio.h>


struct stack
{
int no;
struct stack *addr;
};

typedef struct stack  stack;
stack *top=NULL;
void push(int);
int pop();

void main()
{
  int i,menu,number;
  int array[20],j=0,temp,expected=0;
  clrscr();

   while(menu!=3)
   {
    printf("\n1.PUSH");
    printf("\n2.POP");
    printf("\n3.EXIT");
    printf("\nENTER YOUR CHOICE:");
    scanf("%d",&menu);

    switch(menu)
    {
      case 1:printf("\nENTER NO:");
	     scanf("%d",&number);

	     if(number>9)
	     {
	       printf("\n\nYOU MUST  ENTER NUMBER BETWEEN 0 AND 9 !!");
	     }

	     else if(number>expected+1||number<=expected)
	     {
	       if(number==0)
	       {
		  push(number);
	       }
	       else
	       {
		  printf("\nYOU CAN PUSH ONLY NUMBER %d",expected+1);
	       }
	     }
	     else
	     {
	       expected=number;
	       push(number);
	     }
	     break;
       case 2:
	      temp=pop();

	      if(temp!=-1)
	      {
		array[j++]=temp;
		printf("\nPOP:%d",temp);
	      }

	      printf("\nPATTERN:");

	      for(i=0;i<j;i++)
	      {
		printf("%d ",array[i]);
	      }
	      printf("\n");
	      break;

     case 3:  exit(0);
	      break;

     default: printf("\nINVALID CHOICE..!!");

    }
   }
   getch();
}



void push(int data)  //Function for Pushing Number on Stack.
{
  stack *added,*fake;

  added=(stack*)malloc(sizeof(stack));

  added->no=data;
  added->addr=NULL;
  
  if(added==NULL)
 {
     exit(0);
 }

    if(top==NULL)
    {
       top=added;
    }

    else
    {
	fake=top;

	while(fake->addr!=NULL)
	{
	  fake=fake->addr;
	}
	fake->addr=added;
    }
}

int pop()      //Function for Poping Number from Stack...!!
{
  int data;

  stack *p,*fake;

  if(top==NULL)
  {
    printf("\n\nSTACK IS EMPTY.");
    return -1;
  }

  else
  {
    fake=top;

    while(fake->addr!=NULL)
    {
      p=fake;
      fake=fake->addr;
    }

    if(fake==top)
    {
      data=fake->no;
      top=NULL;
    }
    else
    {
      data=fake->no;
      p->addr=NULL;
    }
    return data;
  }
}

