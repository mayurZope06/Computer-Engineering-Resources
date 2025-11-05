#include <iostream>
using namespace std;

int main() {
    int rs[50], i, j, k, m, f, cntr[20], a[20], min, pf = 0;

    cout << "\nEnter number of page references -- ";
    cin >> m;
    cout << "\nEnter the reference string -- ";
    for (i = 0; i < m; i++)
        cin >> rs[i];
    cout << "\nEnter the available number of frames -- ";
    cin >> f;

    for (i = 0; i < f; i++) {
        cntr[i] = 0;
        a[i] = -1;
    }

    cout << "\nThe Page Replacement Process is – \n";
    for (i = 0; i < m; i++) {
        for (j = 0; j < f; j++) {
            if (rs[i] == a[j]) {
                cntr[j]++;
                break;
            }
        }
        if (j == f) {
            min = 0;
            for (k = 1; k < f; k++)
                if (cntr[k] < cntr[min])
                    min = k;
            a[min] = rs[i];
            cntr[min] = 1;
            pf++;
        }
        cout << "\n";
        for (j = 0; j < f; j++)
            cout << "\t" << a[j];
        if (j == f)
            cout << "\tPF No. " << pf;
    }
    cout << "\n\n Total number of page faults -- " << pf << endl;
    return 0;
}

// OR

#include <iostream>
using namespace std;

int main() {
    int rs[50], frames[10];
    int n, f, i, j, k, pos, pageFault = 0;

    cout << "Enter number of page references: ";
    cin >> n;

    cout << "Enter the reference string: ";
    for(i = 0; i < n; i++)
        cin >> rs[i];

    cout << "Enter number of frames: ";
    cin >> f;

    for(i = 0; i < f; i++)
        frames[i] = -1;

    cout << "\nPage Replacement Process (OPTIMAL):\n";

    for(i = 0; i < n; i++) {
        bool found = false;

        for(j = 0; j < f; j++) {
            if(frames[j] == rs[i]) {
                found = true;
                break;
            }
        }

        if(!found) {
            int farthest = -1;
            pos = -1;

            for(j = 0; j < f; j++) {
                int nextUse = -1;

                for(k = i + 1; k < n; k++) {
                    if(frames[j] == rs[k]) {
                        nextUse = k;
                        break;
                    }
                }

                if(nextUse == -1) {
                    pos = j;
                    break;
                }

                if(nextUse > farthest) {
                    farthest = nextUse;
                    pos = j;
                }
            }

            frames[pos] = rs[i];
            pageFault++;
        }

        for(j = 0; j < f; j++)
            cout << frames[j] << "\t";

        if(!found)
            cout << "PF";

        cout << endl;
    }

    cout << "\nTotal Page Faults using OPTIMAL = " << pageFault << endl;
    return 0;
}

// Enter number of page references: 20
// Enter the reference string: 7   
// 0
// 1
// 2
// 0
// 3
// 0
// 4
// 2
// 3
// 0
// 3
// 2
// 1
// 2
// 0
// 1
// 7
// 0
// 1
// Enter number of frames: 4
