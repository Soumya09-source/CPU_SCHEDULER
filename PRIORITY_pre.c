#include <stdio.h>

int main(){

    int n,i,time=0,completed=0,min;
    int at[20],bt[20],rt[20],pr[20];
    int wt[20],tat[20],resp[20],first[20];
    int prev=-1;

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

        rt[i]=bt[i];
        first[i]=-1;
    }

    printf("\n=========== PREEMPTIVE PRIORITY SCHEDULING ===========\n");
    printf("\nGantt Chart\n");

    while(completed<n){

        min=-1;

        for(i=0;i<n;i++){
            if(at[i]<=time && rt[i]>0){
                if(min==-1 || pr[i]<pr[min])
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
            printf("%d | P%d | ",time,min+1);
            prev=min;
        }

        rt[min]--;
        time++;

        if(rt[min]==0){

            completed++;

            tat[min]=time-at[min];
            wt[min]=tat[min]-bt[min];
            resp[min]=first[min];   // response time = first start time
        }
    }

    printf("%d\n\n",time);

    printf("-------------------------------------------------\n");
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