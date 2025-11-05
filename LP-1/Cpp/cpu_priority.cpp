#include <iostream>
using namespace std;

int main() {
    int p[20], bt[20], pri[20], wt[20], tat[20], i, k, n, temp;
    float wtavg, tatavg;
    cout << "Enter the number of processes --- ";
    cin >> n;
    for (i = 0; i < n; i++) {
        p[i] = i;
        cout << "Enter the Burst Time & Priority of Process " << i << " --- ";
        cin >> bt[i] >> pri[i];
    }
    for (i = 0; i < n; i++)
        for (k = i + 1; k < n; k++)
            if (pri[i] > pri[k]) {
                temp = p[i];
                p[i] = p[k];
                p[k] = temp;
                temp = bt[i];
                bt[i] = bt[k];
                bt[k] = temp;
                temp = pri[i];
                pri[i] = pri[k];
                pri[k] = temp;
            }
    wtavg = wt[0] = 0;
    tatavg = tat[0] = bt[0];
    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = tat[i - 1] + bt[i];
        wtavg = wtavg + wt[i];
        tatavg = tatavg + tat[i];
    }
    cout << "\nPROCESS\t\tPRIORITY\tBURST TIME\tWAITING TIME\tTURNAROUND TIME";
    for (i = 0; i < n; i++)
        cout << "\n" << p[i] << " \t\t " << pri[i] << " \t\t " << bt[i] << " \t\t " << wt[i] << " \t\t " << tat[i];
    cout << "\nAverage Waiting Time is --- " << wtavg / n;
    cout << "\nAverage Turnaround Time is --- " << tatavg / n;
    return 0;
}

// OR

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int p[20], bt[20], at[20], pr[20], wt[20], tat[20], ct[20];
    bool done[20] = {false};

    for(int i = 0; i < n; i++) {
        cout << "Enter Arrival Time, Burst Time, Priority for P" << i+1 << ": ";
        cin >> at[i] >> bt[i] >> pr[i];
        p[i] = i+1;
    }

    int completed = 0, time = 0;
    
    while(completed < n) {
        int idx = -1, bestPri = 9999;

        // find highest priority process that has arrived and not completed
        for(int i = 0; i < n; i++) {
            if(at[i] <= time && !done[i]) {
                if(pr[i] < bestPri) {
                    bestPri = pr[i];
                    idx = i;
                }
            }
        }

        if(idx == -1) {  // no process arrived yet
            time++;
            continue;
        }

        time += bt[idx];       // execute full burst (non-preemptive)
        ct[idx] = time;        // completion time
        done[idx] = true;
        completed++;
    }

    float avgWT = 0, avgTAT = 0;

    cout << "\nProcess\tAT\tBT\tPriority\tWT\tTAT";
    for(int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];         // turnaround time
        wt[i] = tat[i] - bt[i];         // waiting time

        avgWT += wt[i];
        avgTAT += tat[i];

        cout << "\nP" << p[i] << "\t" << at[i] << "\t" << bt[i] << "\t" << pr[i]
             << "\t\t" << wt[i] << "\t" << tat[i];
    }

    cout << "\n\nAverage Waiting Time: " << avgWT/n;
    cout << " \nAverage Turnaround Time: " << avgTAT/n;
}

// Enter number of processes: 4
// Enter Arrival Time, Burst Time, Priority for P1: 0 10 2
// Enter Arrival Time, Burst Time, Priority for P2: 2 5 1
// Enter Arrival Time, Burst Time, Priority for P3: 3 2 0
// Enter Arrival Time, Burst Time, Priority for P4: 5 20 3

// Process	AT	BT	Priority	WT	TAT
// P1	0	10	2		0	10
// P2	2	5	1		10	15
// P3	3	2	0		7	9
// P4	5	20	3		12	32

// Average Waiting Time: 7.25 
// Average Turnaround Time: 16.5
