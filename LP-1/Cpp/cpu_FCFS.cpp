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

// OR

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int pid[n], at[n], bt[n], wt[n], tat[n], ct[n];

    cout << "\nEnter Process ID, Arrival Time & Burst Time:\n";
    for (int i = 0; i < n; i++) {
        cin >> pid[i] >> at[i] >> bt[i];
    }

    // Sort by Arrival Time (FCFS)
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (at[j] < at[i]) {
                swap(at[j], at[i]);
                swap(bt[j], bt[i]);
                swap(pid[j], pid[i]);
            }
        }
    }

    // Calculate Completion, TAT, WT
    ct[0] = at[0] + bt[0];
    for (int i = 1; i < n; i++) {
        if (ct[i-1] < at[i])    // CPU idle time check
            ct[i] = at[i] + bt[i];
        else
            ct[i] = ct[i-1] + bt[i];
    }

    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    // Display table
    cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\n";
    float totalWT = 0, totalTAT = 0;
    for (int i = 0; i < n; i++) {
        cout << pid[i] << "\t" << at[i] << "\t" << bt[i]
             << "\t" << ct[i] << "\t" << tat[i] << "\t" << wt[i] << endl;
        totalWT += wt[i];
        totalTAT += tat[i];
    }

    // Gantt Chart
    cout << "\nGantt Chart:\n ";
    for(int i=0;i<n;i++)
        cout << " | P" << pid[i];
    cout << " |";
    cout << "\n0 ";
    for(int i=0;i<n;i++)
        cout << ct[i] << " ";

    cout << "\n\nAverage Waiting Time = " << totalWT/n;
    cout << "\nAverage Turnaround Time = " << totalTAT/n << endl;

    return 0;
}

// Enter number of processes: 4

// Enter Process ID, Arrival Time & Burst Time:
// 2 0 2
// 4 1 2
// 8 5 3
// 12 6 4

// PID	AT	BT	CT	TAT	WT
// 2	0	2	2	2	0
// 4	1	2	4	3	1
// 8	5	3	8	3	0
// 12	6	4	12	6	2

// Gantt Chart:
//   | P2 | P4 | P8 | P12 |
// 0 2 4 8 12 

// Average Waiting Time = 0.75
// Average Turnaround Time = 3.5
