#include <iostream>
using namespace std;

int main() {
    int i, j, n, bu[10], wa[10], tat[10], t, ct[10], max;
    float awt = 0, att = 0, temp = 0;
    cout << "Enter the no of processes -- ";
    cin >> n;
    for (i = 0; i < n; i++) {
        cout << "\nEnter Burst Time for process " << i + 1 << " -- ";
        cin >> bu[i];
        ct[i] = bu[i];
    }
    cout << "\nEnter the size of time slice -- ";
    cin >> t;
    max = bu[0];
    for (i = 1; i < n; i++)
        if (max < bu[i])
            max = bu[i];
    for (j = 0; j < (max / t) + 1; j++)
        for (i = 0; i < n; i++)
            if (bu[i] != 0)
                if (bu[i] <= t) {
                    tat[i] = temp + bu[i];
                    temp = temp + bu[i];
                    bu[i] = 0;
                } else {
                    bu[i] = bu[i] - t;
                    temp = temp + t;
                }
    for (i = 0; i < n; i++) {
        wa[i] = tat[i] - ct[i];
        att += tat[i];
        awt += wa[i];
    }
    cout << "\nThe Average Turnaround time is -- " << att / n;
    cout << "\nThe Average Waiting time is -- " << awt / n;
    cout << "\n\tPROCESS\t BURST TIME \t WAITING TIME\tTURNAROUND TIME\n";
    for (i = 0; i < n; i++)
        cout << "\t" << i + 1 << " \t " << ct[i] << " \t\t " << wa[i] << " \t\t " << tat[i] << "\n";
    return 0;
}

// OR

#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, tq;
    cout << "Enter number of processes: ";
    cin >> n;

    int p[n], at[n], bt[n], rt[n], wt[n], tat[n], ct[n];

    for(int i = 0; i < n; i++) {
        cout << "Enter Arrival Time & Burst Time for P" << i+1 << ": ";
        cin >> at[i] >> bt[i];
        p[i] = i+1;
        rt[i] = bt[i];
        ct[i] = -1;
    }

    cout << "Enter Time Quantum: ";
    cin >> tq;

    queue<int> q;
    int time = 0, completed = 0;

    // Push first arriving process
    int idx = 0;
    while(idx < n && at[idx] <= time) {
        q.push(idx);
        idx++;
    }

    cout << "\nGantt Chart:\n";

    while(completed < n) {
        if(q.empty()) {
            time++;
            cout << "| IDLE ";
            while(idx < n && at[idx] <= time) {
                q.push(idx);
                idx++;
            }
            continue;
        }

        int i = q.front(); 
        q.pop();

        cout << "| P" << p[i] << " ";

        if(rt[i] > tq) {
            time += tq;
            rt[i] -= tq;
        } else {
            time += rt[i];
            rt[i] = 0;
            ct[i] = time;
            completed++;
        }

        while(idx < n && at[idx] <= time) {
            q.push(idx);
            idx++;
        }

        if(rt[i] > 0) q.push(i);
    }
    cout << "|\n";

    float avgWT = 0, avgTAT = 0;

    cout << "\nProcess\tAT\tBT\tWT\tTAT";
    for(int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        avgWT += wt[i];
        avgTAT += tat[i];

        cout << "\nP" << p[i] << "\t" << at[i] << "\t" << bt[i]
             << "\t" << wt[i] << "\t" << tat[i];
    }

    cout << "\n\nAverage Waiting Time = " << avgWT/n;
    cout << "\nAverage Turnaround Time = " << avgTAT/n;

    return 0;
}

// Enter number of processes: 4
// Enter Arrival Time & Burst Time for P1: 0 5
// Enter Arrival Time & Burst Time for P2: 1 4
// Enter Arrival Time & Burst Time for P3: 2 2
// Enter Arrival Time & Burst Time for P4: 4 1
// Enter Time Quantum: 2

// Gantt Chart:
// | P1 | P2 | P3 | P1 | P4 | P2 | P1 |

// Process	AT	BT	WT	TAT
// P1	0	5	7	12
// P2	1	4	6	10
// P3	2	2	2	4
// P4	4	1	4	5

// Average Waiting Time = 4.75
// Average Turnaround Time = 7.75
