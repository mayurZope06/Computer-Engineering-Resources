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
