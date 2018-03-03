#include<stdio.h>
#include<stdlib.h>

struct multiqueue
{
 int priority;
  struct mutliqueue *next;
}*start,*temp,*first=NULL;
 
typedef struct multiqueue Multi;

int main()
{   
   int i=0;
  while(i!=3)
   {         start = (Multi*)malloc(sizeof(Multi));

        printf("Enter the priority of queue %d\n",i);

        scanf("%d", &start->priority);

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

  /*   int j=0; 
    temp=start;
     while(temp!=NULL && j<6)
      {
        printf(" the priority of queue %d is %d \n",j,temp->priority);
        temp=temp->next;
        j++;
      }
*/
}
