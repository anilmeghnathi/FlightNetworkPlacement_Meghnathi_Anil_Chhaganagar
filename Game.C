#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct child
{
char child_name[50];
struct child *addr;
};

typedef struct child child;
child *first_child=NULL;

void insert(char[]);
void show_remaining();
void new_turn(int);

void main()
{
  char na[50],c;

  int a,tot,no;

  clrscr();

  one_more_time:

  printf("\n HOW MANY CHILDREN ARE THERE?  (ATLEAST 2)-->");
  scanf("%d",&tot);
  while(tot<=1)
  {
     printf("\n\n SORRY.THIS IS INVALID.TRY AGAIN-->");
     scanf("%d",&tot);
  }

  first_child=NULL;

  for(a=1;a<=tot;a++)
  {
	 printf("\n ENTER NAME:");
	 flushall();
	 gets(na);
	 insert(na);
  }

  show_remaining();

  printf("\n ENTER NUMBER (1-%d) :",tot-1);
  scanf("%d",&no);

  while(no>tot-1 || no<=0)
  {
	    printf("\n SORRY.THIS IS INVALID.TRY AGAIN NUMBER (1-%d):",tot-1);
	    scanf("%d",&no);
  }



  while(first_child->addr!=first_child)
  {
	    printf("\n PRESS ANY KEY FOR CONTINUE:");
	    getch();
	    new_turn(no);
	    show_remaining();
	    printf("\n");
  }

  if(first_child->addr==first_child)
  {
	     printf("\n %s WON THE GAME.\n",first_child->child_name);

	     printf("\n \nDO YOU WANT TO PLAY ONE MORE TIME ?(Y/N)-->");

	     flushall();

	     scanf("%c",&c);

	     if(c=='Y' || c=='y')
	     {
	       goto one_more_time;
	     }
  }

}


void insert(char name[]) //Function for adding new child to the game....!!!!
{
  child *new_child,*fake_child;

  new_child=(child*)malloc(sizeof(child));
  if(new_child==NULL)
 {
     printf("\n No FREE SPACE AVAILABLE.");
     exit(0);
 }
  strcpy(new_child->child_name,name);
  new_child->addr=new_child;

  if(first_child==NULL)
  {
     first_child=new_child;
  }

  else
  {
     fake_child=first_child->addr;

     while(fake_child->addr!=first_child)
     {
	fake_child=fake_child->addr;
     }
     new_child->addr=fake_child->addr;

     fake_child->addr=new_child;

  }
}
void show_remaining()  // Function for displaying remaining child in the Game...!!!
{

   child *fake_child;

   printf("---------------------------------------------------------------------\n");

   printf("   %s",first_child->child_name);

   fake_child=first_child->addr;

   while(fake_child!=first_child)
   {
	printf("   %s",fake_child->child_name);

	fake_child=fake_child->addr;

   }
   printf("           <---------------- READY FOR NEXT ROUND.");

   printf("\n---------------------------------------------------------------------\n\n");
}


void new_turn(int d)  //Function for new turn of elimenation in the Game....!!!
{
  int i;

  child *pchild,*fake_child;

  if(d==1)
  {

    printf("\n\n\n\n %s , YOU ARE OUT FROM THE GAME.\n\n",first_child->child_name);

    fake_child=first_child->addr;

    while(fake_child!=first_child)
    {
      pchild=fake_child;

      fake_child=fake_child->addr;
    }

    pchild->addr=fake_child->addr;

    first_child=pchild->addr;
  }

  else
  {
    fake_child=first_child;

    for(i=1;i<d;i++)
    {

      pchild=fake_child;

      fake_child=fake_child->addr;
    }

    pchild->addr=fake_child->addr;

    printf("\n\n\n\n %s , YOU ARE OUT FROM THE GAME.\n\n",fake_child->child_name);

    first_child=pchild->addr;
  }
}

