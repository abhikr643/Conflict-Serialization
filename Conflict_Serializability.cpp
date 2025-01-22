// Conflicting operations: Two operations are said to be conflicting if all conditions satisfy:
// 1.) They belong to different transactions
// 2.) They operate on the same data item
// 3.) At Least one of them is a write operation

//***************** IMPLEMENTATION OF CONFLICT SERIALIZATION*******************/
// Check given Tranctions Are in Conflict Serialization Or Not.


#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;


// Function to build the adjacency list
vector<vector<int>>buildAdjacencyList(const vector<vector<char>> &operations) {
    int n = operations.size();
    vector<vector<int>> adjList(n); // Adjacency List

    // Check for conflicts
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // Extract details of operations
            int t1=operations[i][0] -'0'; // Transaction ID 1
            char op1 = toupper(operations[i][1]);     // Operation type 1
            char item1=operations[i][2];   // Data item 1

            int t2=operations[j][0] -'0'; // Transaction ID 2
            char op2 = toupper(operations[j][1]);     // Operation type 2
            char item2=operations[j][2];   // Data item 2

            // If operations involve the same data item and at least one is a write
            if (item1 == item2 && t1 != t2) {
                if (op1 == 'W' || op2 == 'W') {
                    adjList[t1 - 1].push_back(t2 - 1); // Add edge t1 -> t2
                }
            }
        }
    }

    return adjList;
}

// Utility function to print the adjacency list
void printAdjacencyList(const vector<vector<int>> &adjList) {
    for (int i = 0; i < adjList.size(); i++) {
        cout<< i + 1 << " : ";
        for (int neighbor : adjList[i]) {
            cout<< neighbor + 1 << " ";
        }
        cout << endl;
    }
}

// Detect Cycle in directed Graph
bool TopoSort(vector<vector<int>> &adjList){
    int n=adjList.size();
    vector<int>indegree(n , 0); // 0 Based Indexing

    for(int i=0;i<n;i++){
        for(auto &x : adjList[i]){
            indegree[x]++;
        }
    }

    queue<int>q;
    for(int i=0;i<n;i++){
        if(indegree[i]==0) q.push(i);
    }

    vector<int>topoRes;

    while(!q.empty()){
        auto node=q.front();
        q.pop();
        topoRes.push_back(node);

        for(auto &x: adjList[node]){
            indegree[x]--;
            if(indegree[x]==0) q.push(x);
        }
    }

    if(topoRes.size()!=n){
        // cycle found not in Conflict Serialization 
        return false;
    }

    return true;
}

int main() {
    // Input: Number of operations
    int numOperations;
    cout << "Enter the number of transaction operations : ";
    cin >> numOperations;

    vector<vector<char>> operations(numOperations, vector<char>(3));

    cout << "Enter the operations in the format (TransactionID, OperationType, DataItem):\n";
    for (int i = 0; i < numOperations; i++) {
        cin >> operations[i][0] >> operations[i][1] >> operations[i][2];
    }

    // Build adjacency list
    cout<<endl<<"Adjacency List : "<<endl;
    vector<vector<int>> adjList = buildAdjacencyList(operations);

    // Print the adjacency list
    printAdjacencyList(adjList);
    cout<<endl;

    //Check 
    bool flag=TopoSort(adjList);
    if(flag){
        cout<<"Given set of Transactions are in : Conflict Serialization";
        cout<<endl;
        cout<<"Implies Good to Go with this Serialization";
    }
    else{
        cout<<"Given set of Transactions are in : NOT Conflict Serialization";
        cout<<endl; 
        cout<<"Implies Improve(Reorder) Transactions";
    }

    return 0;
}
