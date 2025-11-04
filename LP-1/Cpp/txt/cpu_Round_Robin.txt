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
