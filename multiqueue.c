#include<stdio.h>
#include<stdlib.h>

struct multiqueue
{
 int priority;
  struct mutliqueue *next;
}*start,*temp,*first=NULL;
struct rqueue
{
  int burst_time;
  char *p;
  struct rqueue *nextt;
}*startt,*ttemp,*firstt=NULL;

struct pqueue
{
  int burst_time,priority;
  char *p;
  struct pqueue *nexttt;
}*starttt,*tttemp,*firsttt=NULL;

typedef struct multiqueue Multi;
round( )
{
  startt = (struct rqueue*)malloc(sizeof(struct rqueue));
       printf("enter the process name and its burst time:");
       char p1[25];
       gets(p1);
       startt->p=&p1;
       scanf("%d",&startt->burst_time);
     if (firstt != NULL)
     {
         ttemp->nextt = startt;
         ttemp = startt;
     }
     else
     {
         firstt = ttemp = startt;
     }

}
priorityy( )
{
  starttt = ( struct pqueue*)malloc(sizeof(struct pqueue));
       printf("enter the process name and its burst time:");
       char p1[25];
       gets(p1);
       starttt->p=&p1;
       scanf("%d",&starttt->burst_time);
     if (firsttt != NULL)
     {
         tttemp->nexttt = starttt;
         tttemp = starttt;
     }
     else
     {
         firsttt = tttemp = starttt;
     }

}

int main()
{
   int i=0;
  while(i!=3)
   {         start = (Multi*)malloc(sizeof(Multi));

         start->priority=i;

        if (first != NULL)

        {

            temp->next = start;

            temp = start;

        }

        else

        {

            first = temp = start;

        }

     i++;
  }
    temp->next=first;

    /* To check the priority
    int j=0;
    temp=first;
     while(temp!=NULL && j<3)
      {
        printf(" the priority of queue %d is %d \n",j,temp->priority);
        temp=temp->next;
        j++;
      }
*/
      printf("enter no. of processes:");
      int nop,prior;
      fflush(stdin);
      scanf("%d",&nop);
      i=0;
      while(i<nop)
      {
        printf("enter the process %d th priority:",i);
         scanf("%d ", &prior);
         switch(prior)
         {
            case 1:
                   {
                     round();
                    break;
                  }
            case 2:
                  {
                  priorityy();
                  break;
                  }
            case 3:
                   {
                    // fcfs();
                   break;
                   }
         }
         i++;
      }
}
