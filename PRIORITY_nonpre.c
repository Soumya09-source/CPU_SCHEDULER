#include <stdio.h>

int main(){

    int n,i,time=0,completed=0,min;
    int at[20],bt[20],pr[20];
    int wt[20],tat[20],resp[20],done[20];

    float avg_wt=0,avg_tat=0,avg_rt=0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){

        printf("\nProcess P%d\n",i+1);

        printf("Arrival Time: ");
        scanf("%d",&at[i]);

        printf("Burst Time: ");
        scanf("%d",&bt[i]);

        printf("Priority: ");
        scanf("%d",&pr[i]);

        done[i]=0;
    }

    printf("\n========= NON PREEMPTIVE PRIORITY SCHEDULING =========\n");
    printf("\nGantt Chart\n");

    while(completed<n){

        min=-1;

        for(i=0;i<n;i++){
            if(at[i]<=time && done[i]==0){
                if(min==-1 || pr[i]<pr[min])
                    min=i;
            }
        }

        if(min==-1){
            time++;
            continue;
        }

        printf("| P%d | ",min+1);

        resp[min]=time;      // first start time

        wt[min]=time-at[min];

        time+=bt[min];       // run full burst time

        tat[min]=time-at[min];

        done[min]=1;
        completed++;
    }

    

    printf("\n-------------------------------------------------\n");
    printf("| Process | AT | BT | PR | WT | TAT | RT |\n");
    printf("-------------------------------------------------\n");

    for(i=0;i<n;i++){

        avg_wt+=wt[i];
        avg_tat+=tat[i];
        avg_rt+=resp[i];

        printf("|   P%d    | %2d | %2d | %2d | %2d | %3d | %2d |\n",
        i+1,at[i],bt[i],pr[i],wt[i],tat[i],resp[i]);
    }

    printf("-------------------------------------------------\n");

    printf("\nAverage Waiting Time    : %.2f\n",avg_wt/n);
    printf("Average Turnaround Time : %.2f\n",avg_tat/n);
    printf("Average Response Time   : %.2f\n",avg_rt/n);

    return 0;
}