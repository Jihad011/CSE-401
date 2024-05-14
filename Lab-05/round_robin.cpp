#include<bits/stdc++.h>
using namespace std;
int main(){
    string process[5]={"p1","p2","p3","p4","p5"};
    int burst_time[5]={2,1,8,4,5};
    int new_burst_time[5]={2,1,8,4,5};
    int time_quantum,i,j;
    cout<<"Enter the time quantum: ";
    cin>>time_quantum;
    queue<string>round_robin_queue;
    queue<string>line;
    queue<int>round_robin_time;
    for(i=0;i<5;i++){
        round_robin_queue.push(process[i]);
    }
    for(i=1;i;i++){
        string popped=round_robin_queue.front();
        round_robin_queue.pop();
        line.push(popped);
        if(burst_time[popped[1]-'0'-1]>=time_quantum){
            round_robin_time.push(time_quantum);
            burst_time[popped[1]-'0'-1]=burst_time[popped[1]-'0'-1]-time_quantum;
        }
        else{
            round_robin_time.push(burst_time[popped[1]-'0'-1]);
            burst_time[popped[1]-'0'-1]=0;
        }
        if(burst_time[popped[1]-'0'-1]>0){
            round_robin_queue.push(popped);
        }
        if(round_robin_queue.size()==0){
            break;
        }
    }
    cout<<"                                           gantt chart"<<endl;
    string new_process[line.size()];
    int new_time[round_robin_time.size()];
    int index=0,sum=0;
    cout<<"|";
    while(line.size()!=0){
        new_process[index]=line.front();
        cout<<"---"<<line.front()<<"---|";
        line.pop();
        index++;
    }
    cout<<endl;
    cout<<"0";
    index=0;
    while(round_robin_time.size()!=0){
        sum+=round_robin_time.front();
        new_time[index]=sum;
        cout<<"        "<<sum;
        round_robin_time.pop();
        index++;
    }
    cout<<endl;
    int completion_time[5]={0};
    for(i=index-1;i>=0;i--){
        int new_index=new_process[i][1]-'0'-1;
        if(completion_time[new_index]==0){
            completion_time[new_index]=new_time[i];
        }
    }
    double average_turnaround_time=0.0;
    double average_waiting_time=0.0;
    cout<<"Turnaround time for each process: "<<endl;
    for(i=0;i<5;i++){
        cout<<process[i]<<"="<<completion_time[i]<<endl;
        average_turnaround_time+=completion_time[i];
    }
    cout<<"Waiting time for each process: "<<endl;
    for(i=0;i<5;i++){
        cout<<process[i]<<"="<<completion_time[i]-new_burst_time[i]<<endl;
        average_waiting_time+=completion_time[i]-new_burst_time[i];
    }
    cout<<"Average turnarond time: "<<average_turnaround_time/5<<endl;
    cout<<"Average waiting time: "<<average_waiting_time/5<<endl;
}