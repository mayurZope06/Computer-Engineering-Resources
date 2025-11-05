#include<iostream>
using namespace std;

int main() {
    int p[20], bt[20], wt[20], tat[20], i, k, n, temp;
    float wtavg, tatavg;
    cout << "\nEnter the number of processes -- ";
    cin >> n;
    for(i = 0; i < n; i++) {
        p[i] = i;
        cout << "Enter Burst Time for Process " << i << " -- ";
        cin >> bt[i];
    }
    for(i = 0; i < n; i++)
        for(k = i + 1; k < n; k++)
            if(bt[i] > bt[k]) {
                temp = bt[i];
                bt[i] = bt[k];
                bt[k] = temp;
                temp = p[i];
                p[i] = p[k];
                p[k] = temp;
            }
    wt[0] = wtavg = 0;
    tat[0] = tatavg = bt[0];
    for(i = 1; i < n; i++) {
        wt[i] = wt[i-1] + bt[i-1];
        tat[i] = tat[i-1] + bt[i];
        wtavg = wtavg + wt[i];
        tatavg = tatavg + tat[i];
    }
    cout << "\n\t PROCESS \tBURST TIME \t WAITING TIME\t TURNAROUND TIME\n";
    for(i = 0; i < n; i++)
        cout << "\n\t P" << p[i] << "\t\t " << bt[i] << "\t\t " << wt[i] << "\t\t " << tat[i];
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

    int pid[n], at[n], bt[n], rt[n]; 
    int wt[n], tat[n], cmplt = 0, t = 0, mn = 1e9, shortest = 0, finish_time;
    bool check = false;

    cout << "\nEnter Process ID, Arrival Time & Burst Time:\n";
    for (int i = 0; i < n; i++) {
        cin >> pid[i] >> at[i] >> bt[i];
        rt[i] = bt[i];
    }

    cout << "\nOrder of execution:\n";

    while (cmplt != n) {
        mn = 1e9;
        check = false;

        for (int i = 0; i < n; i++) {
            if ((at[i] <= t) && (rt[i] < mn) && rt[i] > 0) {
                mn = rt[i];
                shortest = i;
                check = true;
            }
        }

        if (!check) {
            t++;
            continue;
        }

        // Execute the selected process
        rt[shortest]--;
        cout << "P" << pid[shortest] << " ";

        if (rt[shortest] == 0) {
            cmplt++;
            finish_time = t + 1;

            wt[shortest] = finish_time - bt[shortest] - at[shortest];
            if (wt[shortest] < 0) 
                wt[shortest] = 0;

            tat[shortest] = finish_time - at[shortest];
        }
        t++;
    }

    cout << "\n\nPID\tAT\tBT\tWT\tTAT\n";
    float avgWT = 0, avgTAT = 0;

    for (int i = 0; i < n; i++) {
        cout << pid[i] << "\t" << at[i] << "\t" << bt[i] << "\t" << wt[i] << "\t" << tat[i] << endl;
        avgWT += wt[i];
        avgTAT += tat[i];
    }

    cout << "\nAverage Waiting Time = " << avgWT / n;
    cout << "\nAverage Turnaround Time = " << avgTAT / n << endl;

    return 0;
}

// Enter number of processes: 4

// Enter Process ID, Arrival Time & Burst Time:
// 1 0 5
// 2 1 3
// 3 2 4
// 4 4 1

// Order of execution:
// P1 P2 P2 P2 P4 P1 P1 P1 P1 P3 P3 P3 P3 

// PID	AT	BT	WT	TAT
// 1	0	5	4	9
// 2	1	3	0	3
// 3	2	4	7	11
// 4	4	1	0	1

// Average Waiting Time = 2.75
// Average Turnaround Time = 6
