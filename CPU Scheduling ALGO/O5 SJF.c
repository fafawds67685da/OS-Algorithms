#include<stdio.h>
struct process
{

    int pid;
    int at;
    int bt;
    int ct; //start + burst
    int tat; // completion - arrival
    int wt; //tat - bt
    int st; //
    int rt; // start - arrival
    int done ;
}a[5];

int main()
{
    int ab[5];
    int p = 0;
    for(int i =0;i<5;i++)
    {
        printf("\t Enter process id, arrival time, burst time for process no %d \n",(i+1));
        scanf("%d%d%d",&a[i].pid,&a[i].at,&a[i].bt);
    }
    int min_at = 99999, index;
    for(int i =0;i<5;i++)
    {
        if(a[i].at<min_at)
        {
            min_at = a[i].at;
            index = i;
        }
        if(a[i].at == a[index].at)
        {
            if(a[i].pid<a[index].pid)
            {
                min_at = a[i].at;
                index = i;
            }
        }
    }
    ab[p++]=index;
    a[index].done = 1;
    int z=a[index].at;
    a[index].st = z;
    a[index].ct = a[index].st + a[index].bt;
    a[index].rt = a[index].st - a[index].at;
    a[index].tat = a[index].ct - a[index].at;
    a[index].wt = a[index].tat - a[index].bt;
    z = a[index].ct;

    for(int i =0;i<5;i++)
    {
        int min_bt = 99999;
        index = -1;
            for(int j =0;j<5;j++)
            {
                if(!a[j].done)
                {
                    if(!a[j].done && a[j].at <= z && a[j].bt < min_bt)
                    {
                        min_bt = a[j].bt;
                        index = j;
                    }
                    if(a[j].bt == a[index].bt)
                    {
                        if(a[j].pid<a[index].pid)
                        {
                            min_bt = a[j].bt;
                            index = j;
                        }
                    }
                }
            }
            if(index==-1)
            {
                break;
            }
            else
            {
                ab[p++]=index;
                a[index].st = z;
                a[index].ct = a[index].st + a[index].bt;
                a[index].rt = a[index].st - a[index].at;
                a[index].tat = a[index].ct - a[index].at;
                a[index].wt = a[index].tat - a[index].bt;
                z = a[index].ct;
                a[index].done = 1;
            }
        }

    printf("\t Process in sorted sequence \n");
    for(int i =0;i<5;i++)
    {
        if(i==4)
        {
            printf("P%d",(ab[i]+1));
            break;
        }
        printf("P%d->",(ab[i]+1));
    }
    for(int i =0;i<5;i++)
    {
        printf("\t Process id, arrival time, burst time for process no %d \n Process id: %d\n Arrival time: %d\n Burst time: %d\n Completion time: %d\n Start time: %d\n Response time: %d\n TAT time: %d\n Waiting time: %d\n",(i+1),a[i].pid,a[i].at,a[i].bt,a[i].ct,a[i].st,a[i].rt,a[i].tat,a[i].wt);
    }
    printf("\n\n");
    float avg1 = 0.0, avg2 = 0.0, avg3 = 0.0, thru = 0.0, cpu = 0.0;

    for(int i =0;i<5;i++)
    {
        avg1+=a[i].rt;
        avg2+=a[i].wt;
        avg3+=a[i].tat;
    }
    avg1/=5.0;
    avg2/=5.0;
    avg3/=5.0;
    thru = 5.0/a[4].ct;
    cpu = (float)(a[4].ct ) / a[4].ct;
    cpu*=100;
    printf("\t Avg Response time is: %f \n\t Avg Waiting time is: %f \n\t Avg TAT is: %f \n\t Throughput is : %f\n\t CPU utilization is: %f \n",avg1,avg2,avg3,thru,cpu);
    return 0;
}
