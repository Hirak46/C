//......FCFS..AVG_tt..AVG_WT...
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,p[100],bt[100],tt[100],wt[100], sum_WT=0, sum_TT=0;
    float  avg_WT, avg_TT;
    printf("enter the number of process: \n");
    scanf("%d",&n);
    printf("Process Number: ");

        for(i=0;i<n; i++)
    {
        scanf("%d",&p[i]);
    }

    printf("enter burst time of the process: \n");


    for (i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
    }

    for (i=0;i<n;i++)
    {
        wt[0]= 0;
        tt[0]=bt[0];
        wt[i+1]=wt[i]+bt[i];
        tt[i+1]=wt[i+1]+bt[i+1];
    }

    printf("process burst_time witing time turnarround time: \n");
    for (i=0; i<n;i++)
    {
        printf("p%d \t %d \t\t %d \t %d \n", p[i], bt[i],wt[i],tt[i]);
    }

       printf("\n-----Gantt Chart------ \n");
     for(i=0;i<n;i++)
    {


        printf("P%d ",p[i]);
    }
        for(i=0;i<n;i++)
    {
        sum_WT=sum_WT+wt[i];
        sum_TT=sum_TT+tt[i];
    }
        avg_WT=(float)sum_WT/n;
        avg_TT=(float)sum_TT/n;
        printf("\nAvg_waitingtime=%f\nAvg_TurnaroundTime=%f",avg_WT,avg_TT);
    return 0;
}
