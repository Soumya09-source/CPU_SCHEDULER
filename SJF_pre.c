#include <stdio.h>

int main(){

    int n,i,time=0,completed=0,min;
    int at[20],bt[20],rt[20];
    int wt[20],tat[20],resp[20],first[20];
    int prev=-1;

    float avg_wt=0,avg_tat=0,avg_rt=0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){

        printf("Arrival Time P%d: ",i+1);
        scanf("%d",&at[i]);

        printf("Burst Time P%d: ",i+1);
        scanf("%d",&bt[i]);

        rt[i]=bt[i];
        first[i]=-1;
    }

    printf("\n================ SJF PREEMPTIVE =================\n");
    printf("\nGantt Chart\n");

    while(completed<n){

        min=-1;

        for(i=0;i<n;i++){
            if(at[i]<=time && rt[i]>0){
                if(min==-1 || rt[i]<rt[min])
                    min=i;
            }
        }

        if(min==-1){
            time++;
            continue;
        }

        if(first[min]==-1)
            first[min]=time;

        if(prev!=min){
            printf(" P%d | ",min+1);
            prev=min;
        }

        rt[min]--;
        time++;

        if(rt[min]==0){

            completed++;

            tat[min]=time-at[min];
            wt[min]=tat[min]-bt[min];
            resp[min]=first[min];
        }
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