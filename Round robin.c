//....Round Robin...

#include <stdio.h>
#include <stdlib.h>

int main()
{
 int n,p[100],bt[100],tq,wt[100],tt[100],i,j,temp,sum=0,tbt[100],count=0,totaltt=0,totalwt=0;//temp=time quantum
 float avg_wt,avg_tt;
 printf("Enter the number of process: ");
 scanf("%d",&n);
 printf("Enter the time quantum: ");
 scanf("%d",&tq);
 for(i=0;i<n;i++)
 {
    printf("\nEnter Process Number: ");
    scanf("%d",&p[i]);
    printf("Enter the burst time: ");
    scanf("%d",&bt[i]);
    tbt[i]=bt[i];

 }
 while(1)
 {
     for(count=0,i=0;i<n;i++)
     {
         temp=tq;
         if(tbt[i]==0)
         {
         count++;
         continue;
         }
         if(tbt[i]>tq)
         {
             tbt[i]=tbt[i]-tq;
         }
         else if(tbt[i]<=tq)
         {
             temp=tbt[i];
             tbt[i]=0;
         }
         sum=sum+temp;
         tt[i]=sum;

     }

     if(count==n)
        break;
 }
 for(i=0;i<n;i++)
 {
     wt[i]=tt[i]-bt[i];
 }

 printf("process Bursttime Waittingtime Turndaroundtime \n");
 for(i=0;i<n;i++)
 {
     printf("p%d\t%d\t\t%d\t\t%d\n",p[i],bt[i],wt[i],tt[i]);
 }
 for(i=0;i<n;i++)
 {
     totaltt=totaltt+tt[i];
     totalwt=totalwt+bt[i];
 }
 avg_tt=totaltt/n;
 avg_wt=totalwt/n;
 printf("\nAvg Turndarundtime :%f" ,avg_tt);
 printf("\nAvg Waittingtime :%f" ,avg_wt);
 return 0;
}
