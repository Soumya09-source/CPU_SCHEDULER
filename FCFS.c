#include <stdio.h>

int main() {

    int n,i,j;
    int at[20],bt[20],wt[20],tat[20],rt[20];
    int p[20],temp;
    int time=0;

    float avg_wt=0, avg_tat=0, avg_rt=0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        p[i]=i+1;

        printf("Arrival Time P%d: ",i+1);
        scanf("%d",&at[i]);

        printf("Burst Time P%d: ",i+1);
        scanf("%d",&bt[i]);
    }

    // Sort by arrival time
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(at[i] > at[j]){

                temp=at[i]; at[i]=at[j]; at[j]=temp;
                temp=bt[i]; bt[i]=bt[j]; bt[j]=temp;
                temp=p[i]; p[i]=p[j]; p[j]=temp;

            }
        }
    }

    printf("\nGantt Chart:\n");
    printf("-------------------------------------------------\n|");

    for(i=0;i<n;i++){

        if(time < at[i])
            time = at[i];

        printf("  P%d  |",p[i]);

        wt[i] = time - at[i];
        rt[i] = wt[i];
        tat[i] = wt[i] + bt[i];

        time += bt[i];

        avg_wt += wt[i];
        avg_tat += tat[i];
        avg_rt += rt[i];
    }

    printf("\n-------------------------------------------------\n");

    printf("\n-------------------------------------------------\n");
    printf("| Process | AT | BT | WT | TAT | RT |\n");
    printf("-------------------------------------------------\n");

    for(i=0;i<n;i++){
        printf("|   P%d    | %d  | %d  | %d  |  %d  | %d  |\n",
        p[i],at[i],bt[i],wt[i],tat[i],rt[i]);
    }

    printf("-------------------------------------------------\n");

    avg_wt /= n;
    avg_tat /= n;
    avg_rt /= n;

    printf("\nAverage Waiting Time    : %.2f\n",avg_wt);
    printf("Average Turnaround Time : %.2f\n",avg_tat);
    printf("Average Response Time   : %.2f\n",avg_rt);

    return 0;
}