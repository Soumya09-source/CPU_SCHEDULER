#include <stdio.h>

int main() {

    int n,i,time=0,completed=0,idx;
    int at[20],bt[20],done[20]={0};
    int st[20],wt[20],tat[20],rt[20];
    float avg_wt=0,avg_tat=0,avg_rt=0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("Arrival Time P%d: ",i+1);
        scanf("%d",&at[i]);

        printf("Burst Time P%d: ",i+1);
        scanf("%d",&bt[i]);
    }

    printf("\n================ SJF NON PREEMPTIVE ================\n\n");
    printf("Gantt Chart\n");
    printf("-------------------------------------------------\n|");

    while(completed<n){

        idx=-1;

        for(i=0;i<n;i++){
            if(at[i]<=time && !done[i]){
                if(idx==-1 || bt[i]<bt[idx])
                    idx=i;
            }
        }

        if(idx==-1){
            time++;
            continue;
        }

        st[idx]=time;
        rt[idx]=st[idx]-at[idx];

        printf(" P%d |",idx+1);

        time+=bt[idx];

        tat[idx]=time-at[idx];
        wt[idx]=tat[idx]-bt[idx];

        done[idx]=1;
        completed++;
    }

    printf("\n-------------------------------------------------\n\n");

    printf("-----------------------------------------------------------------\n");
    printf("| Process | AT | BT | WT | TAT | RT |\n");
    printf("-----------------------------------------------------------------\n");

    for(i=0;i<n;i++){

        avg_wt+=wt[i];
        avg_tat+=tat[i];
        avg_rt+=rt[i];

        printf("|   P%d    | %2d | %2d | %2d |  %2d | %2d |\n",
        i+1,at[i],bt[i],wt[i],tat[i],rt[i]);
    }

    printf("-----------------------------------------------------------------\n");

    printf("\nAverage Waiting Time    : %.2f\n",avg_wt/n);
    printf("Average Turnaround Time : %.2f\n",avg_tat/n);
    printf("Average Response Time   : %.2f\n",avg_rt/n);
}