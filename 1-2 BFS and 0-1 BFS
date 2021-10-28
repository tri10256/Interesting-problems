 /*For 0-1 BFS   have a visited array, a distance array, and a deque and adjacency list. push source in deque and update the distance array and the visited array. Now while the deque is not empty do 
this
pop the front node and if the popped node is destination node return the distance at the node.
else 
 1. Push the nodes which are adjacent to this node and  have (0) weight, in deque from front and mark them visited and update the distance as d[v]=d[u]. 
 2. push the nodes which are adjacent to this node and  have (1) weight, in deque from back and mark them visited and update the distance as d[v]=d[u]+1.
 It will give the min weight path or shortest path, and applicable in problems like,( Minimum Reversing edges),(Reversing  few) etc.//
************************************************************************************************************************************************************************

//For (1-2) BFS , use the Split logic, and split the edges which have 2 weight, by inserting a dummy node in between the nodes.
//Apply BFS then to get all benefits of BFS.
 Code (1-2) BFS
 */

const int N=200005;
vector<int> g[N];
int vis[N];

void clean(int n)
{
    for(int i=0;i<=n;++i){
        g[i].clear();
        vis[i]=0;
    }
}

void make_graph(int n, vector<vector<int>>&edges)
{
    for(auto &it:edges)
    {
        int x=it[0];
        int y=it[1];
        int w=it[2];
        if(w==1)
        {
            g[x].push_back(y);
            g[y].push_back(x);
        }
        else
        {
            g[x].push_back(x+n);    //splitting by adding dummy nodes
            g[x+n].push_back(y);
            g[y].push_back(y+n);
            g[y+n].push_back(x);
        }
    }
}

int shortest_path(int n,vector<vector<int>>&edges,int src,int dest)
{
    clean(n+n);
    make_graph(n,edges);
    queue<pair<int,int>>q;
    q.push({src,0});
    vis[src]=1;
    while(!q.empty())
    {
        int x=q.front().first;
        int w=q.front().second;
        q.pop();
        if(x==dest)
        return w;
        else
        {
            for(auto &it :g[x])
            {
                if(!vis[it])
                {
                    vis[it]=1;
                    q.push({it,w+1});
                }
            }
        }
    }
    return -1;
}





int Solution::solve(int A, vector<vector<int> > &B, int C, int D) {
    
    return shortest_path(A,B,C,D);
}



