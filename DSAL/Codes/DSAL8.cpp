// Given a sequence of sorted keys with search probabilities, build a binary search tree with the least search cost.
// Consider the access probability for each key.
// (Binary Search Optimization)
#include <iostream>
#include <vector>
#include <climits>
#include <cfloat> // for FLT_MAX
using namespace std;

// Function to compute the sum of probabilities for a subarray from i to j
float sum(const vector<float>& prob, int i, int j) {
    float s = 0;
    for (int k = i; k <= j; k++) {
        s += prob[k];
    }
    return s;
}

// Function to find the minimum search cost and build the optimal BST
float optimalBST(const vector<int>& keys, const vector<float>& prob, int n) {
    // dp[i][j] will store the minimum cost for the subtree from i to j
    vector<vector<float>> dp(n, vector<float>(n, 0));
    
    // w[i][j] will store the sum of probabilities from i to j
    vector<vector<float>> w(n, vector<float>(n, 0));
    
    // Calculate the sum of probabilities for each subarray
    for (int i = 0; i < n; i++) {
        w[i][i] = prob[i];
        for (int j = i + 1; j < n; j++) {
            w[i][j] = w[i][j - 1] + prob[j];
        }
    }
    
    // Fill the dp table using bottom-up dynamic programming
    for (int len = 1; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (len == 1) {
                dp[i][j] = prob[i];
            } else {
                dp[i][j] = FLT_MAX;
                for (int r = i; r <= j; r++) {
                    float cost = (r > i ? dp[i][r - 1] : 0) + (r < j ? dp[r + 1][j] : 0) + w[i][j];
                    dp[i][j] = min(dp[i][j], cost);
                }
            }
        }
    }
    
    return dp[0][n - 1];
}

int main() {
    int n;
    
    // Take input for number of keys
    cout << "Enter the number of keys: ";
    cin >> n;
    
    vector<int> keys(n);
    vector <float> prob(n);
    
    // Take input for the keys
    cout << "Enter the keys (in sorted order): ";
    for (int i = 0; i < n; i++) {
        cin >> keys[i];
    }
    
    // Take input for the probabilities
    cout << "Enter the probabilities for each key: ";
    for (int i = 0; i < n; i++) {
        cin >> prob[i];
    }
    
    // Call the optimalBST function to get the minimum cost
    float minCost = optimalBST(keys, prob, n);
    
    cout << "The minimum search cost is: " << minCost << endl;
    
    return 0;
}

// OR 
// #include <iostream>
// #include <vector>
// #include <climits>
// #include <cfloat> // for FLT_MAX
// using namespace std;

// struct OBSTNode {
//     int key;
//     OBSTNode* left;
//     OBSTNode* right;
// };

// float sum(const vector<float>& p, int i, int j) {
//     float total = 0;
//     for (int k = i; k <= j; k++) {
//         total += p[k];
//     }
//     return total;
// }

// float optimalBST(const vector<int>& keys, const vector<float>& p) {
//     int n = keys.size();
//     vector<vector<float>> cost(n, vector<float>(n, 0));

//     for (int i = 0; i < n; i++) {
//         cost[i][i] = p[i];
//     }

//     for (int length = 2; length <= n; length++) {
//         for (int i = 0; i <= n - length; i++) {
//             int j = i + length - 1;
//             cost[i][j] = FLT_MAX;

//             for (int r = i; r <= j; r++) {
//                 float c = (r > i ? cost[i][r - 1] : 0) +
//                           (r < j ? cost[r + 1][j] : 0) +
//                           sum(p, i, j);

//                 cost[i][j] = min(cost[i][j], c);
//             }
//         }
//     }
//     return cost[0][n - 1];
// }

// int main() {
//     vector<int> keys = {5, 15, 25, 35};
//     vector<float> probabilities = {0.1, 0.2, 0.4, 0.3}; 
//     cout << "Minimum cost of OBST: " << optimalBST(keys, probabilities) << endl;
//     return 0;
// }