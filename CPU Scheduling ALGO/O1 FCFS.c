#include<stdio.h>
struct process
{

    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int st;
    int rt;
}a[5];

int main()
{
    for(int i =0;i<5;i++)
    {
        printf("\t Enter process id, arrival time, burst time for process no %d \n",(i+1));
        scanf("%d%d%d",&a[i].pid,&a[i].at,&a[i].bt);
    }


    for(int i =0;i<4;i++)
    {
        for(int j =0;j<4-i;j++)
        {
            if(a[j].at>a[j+1].at)
            {
                struct process t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
            else
            {
                if(a[j].at == a[j+1].at)
            {
                if(a[j].pid>a[j+1].pid)
                {
                    struct process t = a[j];
                    a[j] = a[j+1];
                    a[j+1] = t;
                }
            }
            }
        }
    }
    int x,z,y;
    printf("\t Enter the starting time of the process by the CPU \n");
    scanf("%d",&x);
    z=x;
    y=z;
    for(int i =0;i<5;i++)
    {
        a[i].st=z;
        a[i].ct = y+a[i].bt;
        z=a[i].ct;
        y=a[i].ct;
        a[i].rt = a[i].st-a[i].at;
        a[i].tat = a[i].ct-a[i].at;
        a[i].wt = a[i].tat - a[i].bt;

    }
    printf("\t Process in sorted sequence \n");

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
    cpu = (float)(a[4].ct - x) / a[4].ct;
    cpu*=100;
    printf("\t Avg Response time is: %f \n\t Avg Waiting time is: %f \n\t Avg TAT is: %f \n\t Throughput is : %f\n\t CPU utilization is: %f \n",avg1,avg2,avg3,thru,cpu);
    return 0;
}
