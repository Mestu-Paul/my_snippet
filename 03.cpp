#include<bits/stdc++.h>
using namespace std;
struct process
{
    int process_id;
    int arrival_time;
    int burst_time;
    int waiting_time,turn_around_time;
};

struct Queue{
    int index;
    int burst_time;
    bool operator<(const Queue& o)const{
        return burst_time>o.burst_time;
    }
};
int main()
{
    // freopen("input.txt","r",stdin);
    int number_of_process,cur_process;
    cout<<"\n\n\nEnter total number of processes: ";
    cin>>number_of_process;    
    vector<process>allProcess(number_of_process);
    cout<<"\nEnter Process Arrival Time\n";
    for(int i=0; i<number_of_process; i++)
    {
        cout<<"P["<<i+1<<"]:";
        cin>>allProcess[i].arrival_time;
        allProcess[i].process_id=i;
    }
    cout<<"\nEnter Process Burst Time\n";
    for(int i=0; i<number_of_process; i++)
    {
        cout<<"P["<<i+1<<"]:";
        cin>>allProcess[i].burst_time;
    }

    sort(allProcess.begin(),allProcess.end(),
        [](const process& a, const process& b){
            if(a.arrival_time==b.arrival_time)
                return a.process_id<b.process_id;
            return a.arrival_time<b.arrival_time;
        }
    );
    // for(int i=0; i<number_of_process; i++){
    //     cout<<allProcess[i].arrival_time<<" "<<allProcess[i].burst_time<<endl;
    // }
    priority_queue<Queue> ready_queue;
    vector<bool>vis(number_of_process,false);
    int current_time=-1,completed=0;
    int total_tat=0,total_wt=0;
    vector<pair<int,int>>gantt_chart;
    while(completed!=number_of_process){
        if(!ready_queue.empty()){
            int cur = ready_queue.top().index;
            int bt = ready_queue.top().burst_time;
            ready_queue.pop();
            
            gantt_chart.push_back({allProcess[cur].process_id,current_time});
            
            current_time+=bt;
            completed++;

            allProcess[cur].turn_around_time = current_time - allProcess[cur].arrival_time;
            allProcess[cur].waiting_time = allProcess[cur].turn_around_time - allProcess[cur].burst_time;
            total_tat += allProcess[cur].turn_around_time;
            total_wt += allProcess[cur].waiting_time;
            
        }
        else current_time++;
        for(int i=0; i<number_of_process; i++){
            if(current_time>=allProcess[i].arrival_time and vis[i]==false){
                vis[i]=true;
                // cout<<"push "<<allProcess[i].process_id+1<<endl;
                ready_queue.push({i,allProcess[i].burst_time});
            }
        }
    }
    cout<<"\n\nGantt chart: "<<endl;
    string ganttchart="| ";
    for(auto p:gantt_chart){
        ganttchart += "(P"+to_string(p.first+1)+","+to_string(p.second)+")  |  ";
    }
    ganttchart += "End at "+to_string(current_time)+" |";
    for(int i=0; i<ganttchart.size(); i++)cout<<"-";cout<<endl;
    cout<<ganttchart<<endl;
    for(int i=0; i<ganttchart.size(); i++)cout<<"-";cout<<endl;



    sort(allProcess.begin(),allProcess.end(),
        [](const process& a, const process& b){
            return a.process_id<b.process_id;
        } 
    );
    cout<<"-----------------------------------------"<<endl;
    cout<<"|   P\t|   At\t|   Bt\t|   Wt\t|   Tat\t|"<<endl;
    cout<<"-----------------------------------------"<<endl;
    for(int i=0; i<number_of_process; i++){
        cout<<"|   P"<<allProcess[i].process_id+1<<"\t|   "<<allProcess[i].arrival_time<<"\t|   "<<allProcess[i].burst_time
        <<"\t|   "<<allProcess[i].waiting_time<<"\t|   "<<allProcess[i].turn_around_time<<"\t|"<<endl;
        cout<<"-----------------------------------------"<<endl;
    }
    cout<<fixed<<setprecision(2);
    cout<<"\nAverage waiting time: "<<(total_wt*1.0)/number_of_process<<endl;
    cout<<"\nAverage turn around time: "<<(total_tat*1.0)/number_of_process<<endl<<endl;
    return 0;
}
//guru
/*
5

2
5
1
0
4

6
2
8
3
4
*/

//javatpoint
/*
5

1
3
6
7
9

7
3
2
10
8
*/

//gatevidyaloy
/*
5

3
1
4
0
2

1
4
2
6
3
*/