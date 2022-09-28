//.....SRTF...

#include<stdio.h>
int main()
{
    int n,p[100],bt[100],wt[100],tt[100],i,j,temp,sum_WT=0,sum_TT=0;
    float avg_WT,avg_TT;
    printf("Enter number of process: ");
    scanf("%d",&n);
    printf("Process number: ");
    for(i=0; i<n; i++)
    {
        scanf("%d",&p[i]);
    }
    printf("Process Burst Time: ");
    for(i=0; i<n; i++)
    {
        scanf("%d",&bt[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(bt[j]>bt[j+1])
            {
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
    }
    printf("Process Burst_Time waiting_time Turnaround_Time\n");
    for(i=0;i<n;i++)
    {
        printf("P%d\t%d\t\t%d\t\t%d\n",p[i],bt[i],wt[i],tt[i]);
    }
    for(i=0;i<n;i++)
    {
        sum_WT=sum_WT+wt[i];
        sum_TT=sum_TT+tt[i];
    }
        avg_WT=(float)sum_WT/n;
        avg_TT=(float)sum_TT/n;
        printf("Avg_waitingtime=%f\n Avg_TurnaroundTime=%f",avg_WT,avg_TT);
    return 0;
}
