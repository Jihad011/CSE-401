#include<bits/stdc++.h>
using namespace std;
int main()
{
    string process[5]= {"p1","p2","p3","p4","p5"};
    int burst_time[5]= {2,1,8,4,5};
    int cumulitive[6]= {0};
    int i,j;
    for(i=1; i<6; i++)
    {
        cumulitive[i]=cumulitive[i-1]+burst_time[i-1];
    }
    cout<<"|";
    for(i=0; i<5; i++)
    {
        cout<<"---"<<process[i]<<"---|";
    }
    cout<<endl;
    for(i=0; i<6; i++)
    {
        cout<<cumulitive[i]<<"        ";
    }
    cout<<endl;
    int turnaround_time[5];
    double average_turnaround_time=0.0;
    cout<<"Turnaround time for each process: "<<endl;
    for(i=1; i<6; i++)
    {
        turnaround_time[i-1]=cumulitive[i];
        cout<<process[i-1]<<"="<<cumulitive[i]<<endl;
        average_turnaround_time+=turnaround_time[i-1];
    }
    int waiting_time[5];
    double average_waiting_time=0.0;
    cout<<"Waiting time for each process: "<<endl;
    for(i=1; i<6; i++)
    {
        waiting_time[i-1]=cumulitive[i]-burst_time[i-1];
        cout<<process[i-1]<<"="<<cumulitive[i]-burst_time[i-1]<<endl;
        average_waiting_time+=waiting_time[i-1];
    }
    cout<<"Average turnaround time="<<average_turnaround_time/5<<endl;
    cout<<"Average waiting time="<<average_waiting_time/5<<endl;
}
