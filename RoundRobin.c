#include <stdio.h>

int main(){

    int n,i,time=0,completed=0,tq;
    int at[20],bt[20],rt[20];
    int wt[20],tat[20],resp[20],first[20];

    float avg_wt=0,avg_tat=0,avg_rt=0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){

        printf("\nProcess P%d\n",i+1);

        printf("Arrival Time: ");
        scanf("%d",&at[i]);

        printf("Burst Time: ");
        scanf("%d",&bt[i]);

        rt[i]=bt[i];
        first[i]=-1;
    }

    printf("\nEnter Time Slice: ");
    scanf("%d",&tq);

    printf("\n=========== ROUND ROBIN SCHEDULING ===========\n");
    printf("\nGantt Chart\n");

    while(completed<n){

        int executed=0;

        for(i=0;i<n;i++){

            if(at[i]<=time && rt[i]>0){

                if(first[i]==-1)
                    first[i]=time;

                printf("| P%d | ",i+1);

                if(rt[i] > tq){

                    time+=tq;
                    rt[i]-=tq;

                }
                else{

                    time+=rt[i];
                    rt[i]=0;

                    tat[i]=time-at[i];
                    wt[i]=tat[i]-bt[i];
                    resp[i]=first[i];

                    completed++;
                }

                executed=1;
            }
        }

        if(!executed)
            time++;
    }

    

    printf("\n-------------------------------------------------\n");
    printf("| Process | AT | BT | WT | TAT | RT |\n");
    printf("-------------------------------------------------\n");

    for(i=0;i<n;i++){

        avg_wt+=wt[i];
        avg_tat+=tat[i];
        avg_rt+=resp[i];

        printf("|   P%d    | %2d | %2d | %2d | %3d | %2d |\n",
        i+1,at[i],bt[i],wt[i],tat[i],resp[i]);
    }

    printf("-------------------------------------------------\n");

    printf("\nAverage Waiting Time    : %.2f\n",avg_wt/n);
    printf("Average Turnaround Time : %.2f\n",avg_tat/n);
    printf("Average Response Time   : %.2f\n",avg_rt/n);

    return 0;
}