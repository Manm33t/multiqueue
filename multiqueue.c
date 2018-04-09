#include<stdio.h>
#include<stdlib.h>
int total=0;
struct schedule
{
int burst_time,priority;
};
struct P
{  int no;
  int time,flag;
  int queue1[50],queue2[50][2],queue3[50];
  int count,count1,count2;
}p;
int rr(int len1)
{ int a=10;
  printf("\n cpu is in 1st queue");
  while(a>0 && len1 > 0)
   {

     if(p.queue1[p.count]<=4 && p.queue1[p.count]>0)
           {
             printf(" \n process starts at%d",p.time);
                  if(a<4)
                  {
                    p.time+=a;
                    p.queue1[p.count]-=a;
                    a=0;
                   printf("\t ends at %d",p.time);
                  }
              else{
                   p.time+=p.queue1[p.count];
                   p.queue1[p.count]=0;
                   len1-=1;
                   p.flag=1;
                  a=a-p.time;
                  }
          }
     else if(p.queue1[p.count]>0)
           {
             printf(" \n process starts at%d",p.time);
             p.queue1[p.count]-=4;
              p.time+=4;
              a=a-4;
                printf("\t ends at %d",p.time);
            }
        if(p.queue1[p.count]==0 && p.flag==1)
            {
              printf("\t ends at %d",p.time);
                    p.no--;
                    p.flag=0;
                    p.count++;
              }
    }
    return len1;
}
int priority(int len2)
{  int b=10;
  printf("\n cpu is in 2nd queue");
        while(b>0 && len2 > 0)
        {
           if(p.queue2[p.count1][0]<=10 &&p.queue2[p.count1][0]>0)
          {
            printf(" \n process starts at%d",p.time);
            if(b<10)
            {
              p.time+=b;
              p.queue2[p.count1][0]-=b;
              b=0;
             printf("\t ends at %d",p.time);
            }
             else
             {
                p.time=p.time+p.queue2[p.count1][0];
                  b=b-p.time;
                p.queue2[p.count1][0]=0;
                len2-=1;
                p.flag=1;
            }
          }
          else if(p.queue2[p.count1][0]>0)
                {  printf(" \n process starts at%d",p.time);
                  p.queue2[p.count1][0]=p.queue2[p.count1][0]-10;
                   p.time+=10;
                   b=b-10;
                     printf("\t ends at %d",p.time);
                 }
             if(p.queue2[p.count1][0]==0 && p.flag==1)
                 {
                      printf("\t ends at %d",p.time);
                         p.no--;
                         p.flag=0;
                         p.count1++;
                   }
        }
        return len2;
}
int fcfs(int len3)
{ int c=10;
  printf("\ncpu is in 3rd queue");
  while(c>0 && len3 > 0)
  {
     if(p.queue3[p.count2]<=10 &&p.queue3[p.count2]>0)
    {
      printf(" \n process starts at%d",p.time);
       p.time=p.time+p.queue3[p.count2];
       c=c-p.time;
       p.queue3[p.count2]=0;

         p.flag=1;
         len3-=1;
    }
    else if(p.queue3[p.count2]> c)
          {
            printf(" \n process starts at%d",p.time);

              p.queue3[p.count2]-=c;
            if(p.queue3[p.count2]==0 && p.flag==1)
             p.time+=c;
             c=0;
              printf("\t ends at %d",p.time);
           }
           if(p.queue3[p.count2] == 0){
                printf("\t  ends at %d",p.time);
                   p.no--;
                   p.flag=0;
                   p.count2++;
             }
  }
  return len3;
}

int main()
{
   printf("enter the no. of processes:\n");
   int no=0,i=0,num=0;
   int len1=0;
   int len2=0;
   int len3=0;
   scanf("%d",&p.no);
   num=p.no;
   struct schedule s[p.no];
   for(i=0;i<p.no;i++)
   {
   printf("enter the details of %d process\n",i);
   printf("enter burst time :\n");
   scanf("%d",&s[i].burst_time);
   printf("enter the priority\n");
   scanf("%d",&s[i].priority);
   }
    int j=0,k=0,l=0;
  for(i=0;i<p.no;i++ )
  {
    if(s[i].priority==1)
    {
      len1++;
      p.queue1[j++]=s[i].burst_time;
      total+=s[i].burst_time;
    }
    else if(s[i].priority==2)
    {
      len2++;
      p.queue2[k][0]=s[i].burst_time;
      int temp=0;
      printf("\n enter the priority for priority scheduling of 2nd queue:");
      scanf("%d",&temp);
      p.queue2[k][1]=temp;
      printf("\t%d*",p.queue2[k][1]);
      total+=s[i].burst_time;
        k++;
    }
    else if(s[i].priority==3)
    {
      len3++;
      p.queue3[l++]=s[i].burst_time;
      total+=s[i].burst_time;
    }

  }

  /*for (i=0;i<l;i++)
  {
    printf("\n%d",queue3[i]);
  }*/

  int temp1=0,temp2=0;

  for(int z=1;z<k;z++)
       {
            for(i=0; i<k-1; i++)
            {
                  if(p.queue2[i][1]>p.queue2[i+1][1])
                  {
                      temp1=p.queue2[i][1];
                      p.queue2[i][1]=p.queue2[i+1][1];
                      p.queue2[i+1][1]=temp1;

                          temp2=p.queue2[i][0];
                          p.queue2[i][0]=p.queue2[i+1][0];
                          p.queue2[i+1][0]=temp2;
                  }
            }
       }

/*  for (i=0;i<k;i++)
  {
    printf("\n %d %d",queue2[i][0],queue2[i][1]);

  }
*/
  p.count=0;
  p.flag=0;
  p.count1=0;
  p.count2=0;
  p.time=0;
  p.queue1[no];
  p.queue2[no][2];
  p.queue3[no];

  printf("\n*******************in processing mode*****************");
/*int len1=sizeof(p.queue1);
int len2=sizeof(p.queue2);
int len3=sizeof(p.queue3);
*/
while (p.no!=0)
{   if(len1!=0)
      {
            len1=rr(len1);
      }
    if(len2!=0)
            {
              //printf("\n cpu is in 2nd queue");
                  len2=priority(len2);

            }
     if(len3!=0)
                  {
                //    printf("\n cpu is in 3rd queue");
                        len3=fcfs(len3);

                  }
}

}
