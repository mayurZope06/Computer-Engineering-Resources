#include <iostream>
using namespace std;

#define max 25

int main() {
    int frag[max], b[max], f[max], i, j, nb, nf, temp, lowest = 10000;
    static int bf[max], ff[max];
    cout << "\nEnter the number of blocks:";
    cin >> nb;
    cout << "Enter the number of files:";
    cin >> nf;
    cout << "\nEnter the size of the blocks:-" << endl;
    for (i = 1; i <= nb; i++) {
        cout << "Block " << i << ":";
        cin >> b[i];
    }
    cout << "Enter the size of the files :-" << endl;
    for (i = 1; i <= nf; i++) {
        cout << "File " << i << ":";
        cin >> f[i];
    }
    for (i = 1; i <= nf; i++) {
        for (j = 1; j <= nb; j++) {
            if (bf[j] != 1) {
                temp = b[j] - f[i];
                if (temp >= 0)
                    if (lowest > temp) {
                        ff[i] = j;
                        lowest = temp;
                    }
            }
        }
        frag[i] = lowest;
        bf[ff[i]] = 1;
        lowest = 10000;
    }
    cout << "\nFile No\tFile Size \tBlock No\tBlock Size\tFragment";
    for (i = 1; i <= nf && ff[i] != 0; i++)
        cout << "\n" << i << "\t\t" << f[i] << "\t\t" << ff[i] << "\t\t" << b[ff[i]] << "\t\t" << frag[i];
    return 0;
}

// OR

#include <iostream>
using namespace std;

int main() {
    int nb, nf;
    cout << "Enter number of blocks: ";
    cin >> nb;
    int block[nb], remaining[nb];

    cout << "Enter block sizes:\n";
    for(int i = 0; i < nb; i++) {
        cout << "Block " << i+1 << ": ";
        cin >> block[i];
        remaining[i] = block[i];
    }

    cout << "\nEnter number of files: ";
    cin >> nf;
    int file[nf];

    cout << "Enter file sizes:\n";
    for(int i = 0; i < nf; i++) {
        cout << "File " << i+1 << ": ";
        cin >> file[i];
    }

    int alloc[nf];
    for(int i = 0; i < nf; i++) alloc[i] = -1;

    for(int i = 0; i < nf; i++) {
        int best = -1;
        for(int j = 0; j < nb; j++) {
            if(remaining[j] >= file[i]) {
                if(best == -1 || remaining[j] < remaining[best])
                    best = j;
            }
        }
        if(best != -1) {
            alloc[i] = best;
            remaining[best] -= file[i];
        }
    }

    cout << "\nFile\tSize\tBlock\tRemaining Block Space\n";
    for(int i = 0; i < nf; i++) {
        cout << i+1 << "\t" << file[i] << "\t";
        if(alloc[i] != -1)
            cout << alloc[i]+1 << "\t" << remaining[alloc[i]];
        else
            cout << "Not Allocated\t-";
        cout << endl;
    }

    return 0;
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

// File	Size	Block	Remaining Block Space
// 1	        300	     2  	25
// 2       	25	        2	25
// 3	        125	1	25
// 4	        50	Not Allocated	-

// OR 

#include <iostream>
using namespace std;

int main() {
    int nb, nf;
    cout << "Enter number of blocks: ";
    cin >> nb;

    int blockSize[20], blockRemain[20];
    cout << "Enter block sizes:\n";
    for (int i = 0; i < nb; i++) {
        cout << "Block " << i+1 << ": ";
        cin >> blockSize[i];
        blockRemain[i] = blockSize[i]; // Initially full
    }

    cout << "\nEnter number of files: ";
    cin >> nf;

    int fileSize[20];
    cout << "Enter file sizes:\n";
    for (int i = 0; i < nf; i++) {
        cout << "File " << i+1 << ": ";
        cin >> fileSize[i];
    }

    int allocation[20];
    for (int i = 0; i < nf; i++) allocation[i] = -1;

    // Best Fit Allocation allowing multiple files per block
    for (int i = 0; i < nf; i++) {
        int bestIndex = -1;

        for (int j = 0; j < nb; j++) {
            if (blockRemain[j] >= fileSize[i]) {
                if (bestIndex == -1 || blockRemain[j] < blockRemain[bestIndex])
                    bestIndex = j;
            }
        }

        if (bestIndex != -1) {
            allocation[i] = bestIndex;
            blockRemain[bestIndex] -= fileSize[i];
        }
    }

    cout << "\nFile\tSize\tBlock\tRemaining Space After Allocation\n";
    for (int i = 0; i < nf; i++) {
        if (allocation[i] != -1)
            cout << i+1 << "\t" << fileSize[i] << "\t" 
                 << allocation[i]+1 << "\t" 
                 << blockRemain[allocation[i]] << endl;
        else
            cout << i+1 << "\t" << fileSize[i] << "\tNot Allocated\n";
    }

    cout << "\nFinal space left in each block:\n";
    for (int i = 0; i < nb; i++)
        cout << "Block " << i+1 << ": " << blockRemain[i] << endl;

    return 0;
}
