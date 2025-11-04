#include <iostream>
using namespace std;
#define max 25

int main() {
    int frag[max], b[max], f[max], i, j, nb, nf, temp;
    static int bf[max], ff[max];
    cout << "Memory Management Scheme - First Fit" << endl;
    cout << "Enter the number of blocks:";
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
                if (temp >= 0) {
                    ff[i] = j;
                    break;
                }
            }
        }
        frag[i] = temp;
        bf[ff[i]] = 1;
    }
    cout << "\nFile_no:\tFile_size :\tBlock_no:\tBlock_size:\tFragment";
    for (i = 1; i <= nf; i++)
        cout << "\n" << i << "\t\t" << f[i] << "\t\t" << ff[i] << "\t\t" << b[ff[i]] << "\t\t" << frag[i];
    return 0;
}
