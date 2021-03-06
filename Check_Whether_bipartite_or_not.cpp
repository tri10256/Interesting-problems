// Given a undirected graph having A nodes. A matrix B of size M x 2 is given which represents the edges such that there is an edge between B[i][0] and B[i][1].

// Find whether the given graph is bipartite or not.

// A graph is bipartite if we can split it's set of nodes into two independent subsets A and B such that every edge in the graph has one node in A and another node in B

// Note:

// There are no self-loops in the graph.

// No multiple edges between two pair of vertices.

// The graph may or may not be connected.

// Nodes are Numbered from 0 to A-1.

// Your solution will run on multiple testcases. If you are using global variables make sure to clear them.



// Problem Constraints
// 1 <= A <= 100000

// 1 <= M <= min(A(A-1)/2,200000)

// 0 <= B[i][0],B[i][1] < A



// Input Format
// The first argument given is an integer A.

// The second argument given is the matrix B.



// Output Format
// Return 1 if the given graph is bipartide else return 0.



// Example Input
// Input 1:

// A = 2
// B = [ [0, 1] ]
// Input 2:

// A = 3
// B = [ [0, 1], [0, 2], [1, 2] ]


// Example Output
// Output 1:

// 1
// Output 2:

// 0


// Example Explanation*
// Explanation 1:

// Put 0 and 1 into 2 different subsets.
// Explanation 2:

 
// It is impossible to break the graph down to make two different subsets for bipartite matching





Solution code:


bool isbipi(vector<int>adj[],int s,vector<int>&col){
   
   queue<int>q;
   q.push(s);
   col[s]=0;

   while(!q.empty()){
      int u=q.front();
      q.pop();
      
      for(auto v:adj[u]){
          if(col[v]==-1){
              col[v]=1-col[u];
              q.push(v);
          }
          if(col[v]==col[u])
          return false;
      }
   }
return true;
}


int Solution::solve(int A, vector<vector<int> > &B) {

    vector<int>adj[A+1];

    for(int i=0;i<B.size();i++){
        adj[B[i][0]].push_back(B[i][1]);
        adj[B[i][1]].push_back(B[i][0]);
    }

    vector<int>col(A+1,-1);

    int ans=1;
    for(int i=0;i<A;i++){
     if(col[i]==-1)
       ans=ans && isbipi(adj,i,col);
     }
    return ans;
}
