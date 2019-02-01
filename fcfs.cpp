/***** FCFS Scheduling ******/
#include<bits/stdc++.h>
using namespace std;
template<class T>
void display(vector<T> array) {
    for(int i = 0; i<array.size();i++) {
        cout<<array[i]<<"\t"<<endl;
    }
} 

vector<int> completionTime(vector<string> processID, vector<int> arrivalTime, vector<int> burstTime) {
    int len = processID.size()+1;
    vector<int> completionTimeResult(len);
    completionTimeResult[0] = 0;
    for(int i = 1; i < completionTimeResult.size(); i++) {
        completionTimeResult[i] = completionTimeResult[i-1] + burstTime[i-1]; 
    }
    //display(completionTimeResult);
    return completionTimeResult;
}

vector<int> turnAroundTime(vector<string> processID, vector<int> arrivalTime, vector<int> completionTimeResult) {
    vector<int> tatResult(processID.size(), 0);
    for(int i = 0; i < tatResult.size(); i++) {
        tatResult[i] = completionTimeResult[i+1] - arrivalTime[i];
    }
    return tatResult;
}

vector<int> waitingTime(vector<string> processID, vector<int> burstTime, vector<int> tatTime) {
    vector<int> waitingTimeResult(processID.size(), 0);
    for(int i = 0; i < waitingTimeResult.size(); i++) {
        waitingTimeResult[i] = tatTime[i] - burstTime[i];
    }
    return waitingTimeResult;
}

int main() {
    vector<string> processID{"P1", "P2", "P3", "P4", "P5"};
    vector<int> arrivalTime{0,1,2,3,4};
    vector<int> burstTime{2, 3, 5, 4, 6};

    vector<int> compl_time = completionTime(processID, arrivalTime, burstTime);
    vector<int> tat_time = turnAroundTime(processID, arrivalTime, compl_time);
    vector<int> wait_time = waitingTime(processID, burstTime, tat_time);
    cout<<"Process ID"<<"\t"<<"Arrival Time"<<"\t"<<"Burst Time"<<"\t"<<"Completion Time"<<"\t\t"<<"Turn Around Time"<<"\t"<<"Waiting Time"<<endl;  
    for(int i = 0; i < processID.size(); i++) {
        cout<<"  "<<processID[i]<<"\t\t"<<arrivalTime[i]<<"\t\t"<<burstTime[i]<<"\t\t"<<compl_time[i+1]<<"\t\t\t"<<tat_time[i]<<"\t\t\t"<<wait_time[i]<<endl;
    }
    return 0;
}