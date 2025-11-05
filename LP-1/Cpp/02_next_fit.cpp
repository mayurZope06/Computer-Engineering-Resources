

#include <iostream>
using namespace std;

void NextFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[100] = {-1};
    int j = 0, t = m - 1;

    for (int i = 0; i < n; i++) {
        while (j < m) {
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                t = (j - 1) % m;
                break;
            }
            if (t == j) {
                t = (j - 1) % m;
                break;
            }
            j = (j + 1) % m;
        }
    }

    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < n; i++) {
        cout << " " << i + 1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}

int main() {
    int blockSize[] = {5, 10, 20};
    int processSize[] = {10, 20, 5};
    int m = sizeof(blockSize) / sizeof(blockSize[0]);
    int n = sizeof(processSize) / sizeof(processSize[0]);

    NextFit(blockSize, m, processSize, n);

    return 0;
}

// OR

#include <iostream>
using namespace std;

void NextFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[100];
    for(int i = 0; i < n; i++)
        allocation[i] = -1;   // initialize all to -1

    int j = 0; // start from first block

    for (int i = 0; i < n; i++) {
        int start = j; // to avoid infinite loop

        while (true) {
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }

            j = (j + 1) % m; // circular movement

            if (j == start)   // if full circle, stop
                break;
        }
    }

    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < n; i++) {
        cout << " " << i + 1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}

int main() {
    int m, n;

    cout << "Enter number of memory blocks: ";
    cin >> m;
    int blockSize[m];
    cout << "Enter size of each block:\n";
    for(int i = 0; i < m; i++) {
        cout << "Block " << i+1 << ": ";
        cin >> blockSize[i];
    }

    cout << "\nEnter number of processes: ";
    cin >> n;
    int processSize[n];
    cout << "Enter size of each process:\n";
    for(int i = 0; i < n; i++) {
        cout << "Process " << i+1 << ": ";
        cin >> processSize[i];
    }

    NextFit(blockSize, m, processSize, n);

    return 0;
}

// Enter number of memory blocks: 3
// Block 1: 5
// Block 2: 10
// Block 3: 20

// Enter number of processes: 3
// Process 1: 10
// Process 2: 20
// Process 3: 5
