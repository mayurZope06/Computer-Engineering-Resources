#include <iostream>
using namespace std;

#define max 25

int main() {
    int frag[max], b[max], f[max], i, j, nb, nf, temp, highest;
    static int bf[max], ff[max];

    cout << "Memory Management Scheme - Worst Fit\n";
    cout << "Enter the number of blocks: ";
    cin >> nb;
    cout << "Enter the number of files: ";
    cin >> nf;

    cout << "\nEnter the size of the blocks:\n";
    for (i = 1; i <= nb; i++) {
        cout << "Block " << i << ": ";
        cin >> b[i];
        bf[i] = 0; // mark block free
    }

    cout << "\nEnter the size of the files:\n";
    for (i = 1; i <= nf; i++) {
        cout << "File " << i << ": ";
        cin >> f[i];
        ff[i] = -1; // initially not allocated
    }

    // Worst Fit Logic
    for (i = 1; i <= nf; i++) {
        highest = -1;
        for (j = 1; j <= nb; j++) {
            if (bf[j] == 0 && b[j] >= f[i]) { 
                temp = b[j] - f[i];
                if (temp > highest) {
                    ff[i] = j;
                    highest = temp;
                }
            }
        }

        if (ff[i] != -1) {
            frag[i] = highest;
            bf[ff[i]] = 1;
        } else {
            frag[i] = -1; // no fragment -> not allocated
        }
    }

    cout << "\nFile_No\tFile_Size\tBlock_No\tBlock_Size\tFragment\n";
    for (i = 1; i <= nf; i++) {
        cout << i << "\t" << f[i] << "\t\t";
        if (ff[i] != -1)
            cout << ff[i] << "\t\t" << b[ff[i]] << "\t\t" << frag[i];
        else
            cout << "Not Allocated\t-\t\t-";
        cout << endl;
    }

    return 0;
}

// OR 

#include <iostream>
using namespace std;

int main() {
    int nb, nf;
    cout << "Enter number of blocks: ";
    cin >> nb;

    int blockSize[50], blockRemain[50];
    cout << "Enter block sizes:\n";
    for (int i = 0; i < nb; i++) {
        cout << "Block " << i + 1 << ": ";
        cin >> blockSize[i];
        blockRemain[i] = blockSize[i];
    }

    cout << "\nEnter number of files: ";
    cin >> nf;

    int fileSize[50];
    cout << "Enter file sizes:\n";
    for (int i = 0; i < nf; i++) {
        cout << "File " << i + 1 << ": ";
        cin >> fileSize[i];
    }

    cout << "\nFile\tSize\tBlock\tRemaining Space After Allocation\n";

    for (int i = 0; i < nf; i++) {
        int bestIndex = -1;

        // Worst Fit: pick block with maximum remaining space that can fit file
        for (int j = 0; j < nb; j++) {
            if (blockRemain[j] >= fileSize[i]) {
                if (bestIndex == -1 || blockRemain[j] > blockRemain[bestIndex])
                    bestIndex = j;
            }
        }

        if (bestIndex != -1) {
            blockRemain[bestIndex] -= fileSize[i];
            cout << i + 1 << "\t" << fileSize[i] << "\t" << bestIndex + 1 
                 << "\t" << blockRemain[bestIndex] << endl;
        } 
        else {
            cout << i + 1 << "\t" << fileSize[i] << "\t" << "Not Allocated\n";
        }
    }

    cout << "\nFinal space left in each block:\n";
    for (int i = 0; i < nb; i++) {
        cout << "Block " << i + 1 << ": " << blockRemain[i] << endl;
    }
}

// Enter number of blocks: 2
// Enter block sizes:
// Block 1: 150
// Block 2: 350

// Enter number of files: 4
// Enter file sizes:
// File 1: 300
// File 2: 25
// File 3: 125
// File 4: 50

// File	Size	Block	Remaining Space After Allocation
// 1	300	2	50
// 2	25	1	125
// 3	125	1	0
// 4	50	2	0

// Final space left in each block:
// Block 1: 0
// Block 2: 0

