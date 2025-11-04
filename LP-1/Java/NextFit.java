
// Java program for next fit
// memory management algorithm
import java.util.*;

public class NextFit {

    // Function to allocate memory to blocks as per Next fit
    // algorithm
    static void nextFit(int blockSize[], int m, int processSize[], int n) {
        // Stores block id of the block allocated to a
        // process
        int allocation[] = new int[n], j = 0, t = m - 1;

        // Initially no block is assigned to any process
        Arrays.fill(allocation, -1);
        // pick each process and find suitable blocks
        // according to its size ad assign to it
        // pick each process and find sui table blocks
        // according to its size ad assign to it
        for (int i = 0; i < n; i++) {

            // Do not start from beginning
            while (j < m) {
                if (blockSize[j] >= processSize[i]) {

                    // allocate block j to p[i] process
                    allocation[i] = j;

                    // Reduce available memory in this block.
                    blockSize[j] -= processSize[i];

                    // sets a new end point
                    t = (j - 1) % m;
                    break;
                }
                if (t == j) {
                    // sets a new end point
                    t = (j - 1) % m;
                    // breaks the loop after going through all memory block
                    break;
                }

                // mod m will help in traversing the
                // blocks from starting block after
                // we reach the end.
                j = (j + 1) % m;
            }
        }

        System.out.print("\nProcess No.\tProcess Size\tBlock no.\n");
        for (int i = 0; i < n; i++) {
            System.out.print(i + 1 + "\t\t\t\t" + processSize[i] + "\t\t\t\t");
            if (allocation[i] != -1) {
                System.out.print(allocation[i] + 1);
            } else {
                System.out.print("Not Allocated");
            }
            System.out.println("");
        }
    }

    // Driver program
    public static void main(String[] args) {
        int blockSize[] = { 5, 10, 20 };
        int processSize[] = { 10, 20, 5 };
        int m = blockSize.length;
        int n = processSize.length;
        nextFit(blockSize, m, processSize, n);
    }
}