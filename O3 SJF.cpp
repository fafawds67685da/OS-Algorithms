#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class sjf
{
    public:
        int pid;
        int at;
        int bt;
        int ct;
        int tat;
        int wt;
        int st;
        int rt;
};

int main()
{
    sjf ob[5];
    for(int i =0;i<5;i++)
    {
        cout<< "Enter process id, arrival time, burst time for process no"<<i+1<<endl;
        cin>>ob[i].pid>>ob[i].at>>ob[i].bt;
    }
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4-i;j++)
        {
            if(ob[j].at>ob[j+1].at)
            {
                sjf temp = ob[j];
                ob[j] = ob[j+1];
                ob[j+1] = temp;
            }
            else
            {
                if(ob[j].at == ob[j+1].at)
                {
                    if(ob[j].pid>ob[j+1].pid)
                    {
                        sjf temp = ob[j];
                        ob[j] = ob[j+1];
                        ob[j+1] = temp;
                    }
                }
            }
        }
    }
    int time = 0, completed = 0;
    bool done[5] = {false};
    cout << "\nOrder of execution: ";
    while(completed < 5)
    {
        int ind = -1;
        int min_bt = INT_MAX;

        for(int i = 0; i < 5; i++)
        {
            if(!done[i] && ob[i].at <= time)
            {
                if(ob[i].bt < min_bt)
                {
                    min_bt = ob[i].bt;
                    ind = i;
                }
                else if(ob[i].bt == min_bt)
                {
                    if(ob[i].pid < ob[ind].pid)
                        ind = i;
                }
            }
        }
    
        if(ind == -1)
        {
            time++; 
        }
        else
        {
            ob[ind].st = time;
            ob[ind].ct = ob[ind].st + ob[ind].bt;
            ob[ind].tat = ob[ind].ct - ob[ind].at;
            ob[ind].wt = ob[ind].tat - ob[ind].bt;
            ob[ind].rt = ob[ind].st - ob[ind].at;

            time = ob[ind].ct;
            done[ind] = true;
            completed++;
            cout << "P" << ob[ind].pid;
            if(completed < 5) cout << " -> ";
        }
    }
    cout << "\n";
    cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\tRT\n";
    float sum_rt = 0, sum_wt = 0, sum_tat = 0, sum_bt = 0;
    int first_arrival = ob[0].at;
    int last_completion = 0;
    for(int i = 0; i < 5; i++)
    {
        cout << ob[i].pid << "\t" << ob[i].at << "\t" << ob[i].bt << "\t"
            << ob[i].ct << "\t" << ob[i].tat << "\t" << ob[i].wt << "\t" << ob[i].rt << endl;
        sum_rt += ob[i].rt;
        sum_wt += ob[i].wt;
        sum_tat += ob[i].tat;
        sum_bt += ob[i].bt;
        last_completion = max(last_completion, ob[i].ct);
    }
    float avg1 = sum_rt / 5;
    float avg2 = sum_wt / 5;
    float avg3 = sum_tat / 5;
    float thru = (float)5 / (last_completion - first_arrival);
    float cpu = (sum_bt / (last_completion - first_arrival)) * 100;
    cout << "\nAvg Response time is: " << avg1
         << "\n\t Avg Waiting time is: " << avg2
         << "\n\t Avg TAT is: " << avg3
         << "\n\t Throughput is : " << thru
         << "\n\t CPU utilization is: " << cpu << "%" << endl;
    return 0;
}
