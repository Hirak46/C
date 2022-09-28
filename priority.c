//.....Priority...

#include<stdio.h>
int main()
{
    int n, p[10],wt[10],tt[10],bt[10],i,j,temp,priority[100];
    float avg_wt,avg_tt,sumwt=0,sumtt=0;
    printf("Enter number of process: ");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        printf("Enter Process number : ");
        scanf("%d",&p[i]);
        printf("Enter burst time of the process: ");
        scanf("%d",&bt[i]);
        printf("Enter priority for this process :");
        scanf("%d",&priority[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(priority[j]>priority[j+1])
            {
               temp=priority[j];
               priority[j]=priority[j+1];
               priority[j+1]=temp;

               temp=bt[j];
               bt[j]=bt[j+1];
               bt[j+1]=temp;

               temp=p[j];
               p[j]=p[j+1];
               p[j+1]=temp;
            }
        }
    }
    for(i=0; i<n; i++)
    {
        wt[0]=0;
        tt[0]=bt[0];
        wt[i+1]=wt[i]+bt[i];
        tt[i+1]=wt[i+1]+bt[i+1];
        sumwt=sumwt+wt[i];
        sumtt=sumtt+tt[i];
    }
    printf("Process\tBurst_time\tPriority\tWaiting_Time\tTurnaround_time\n");
    for(i=0; i<n; i++)
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i],bt[i],priority[i],wt[i],tt[i]);
       avg_wt=sumwt/n;
       avg_tt=sumtt/n;
       printf("Average waiting Time = %f\n Average TurnaroundTime = %f",avg_wt,avg_tt);
    return 0;
}
