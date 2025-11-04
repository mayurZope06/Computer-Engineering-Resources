#include<iostream>
using namespace std;

int main() {
    int bt[20], wt[20], tat[20], i, n;
    float wtavg, tatavg;
    cout << "\nEnter the number of processes -- ";
    cin >> n;
    for(i = 0; i < n; i++) {
        cout << "\nEnter Burst Time for Process " << i << " -- ";
        cin >> bt[i];
    }
    wt[0] = wtavg = 0;
    tat[0] = tatavg = bt[0];
    for(i = 1; i < n; i++) {
        wt[i] = wt[i-1] + bt[i-1];
        tat[i] = tat[i-1] + bt[i];
        wtavg = wtavg + wt[i];
        tatavg = tatavg + tat[i];
    }
    cout << "\t PROCESS \tBURST TIME \t WAITING TIME\t TURNAROUND TIME\n";
    for(i = 0; i < n; i++)
        cout << "\n\t P" << i << "\t\t " << bt[i] << "\t\t " << wt[i] << "\t\t " << tat[i];
    cout << "\nAverage Waiting Time -- " << wtavg / n;
    cout << "\nAverage Turnaround Time -- " << tatavg / n;
    return 0;
}