///////Simple implemntation of the disjoint set union to in the problem.
///////



void mySet(int parent[],int rank[],int sz){
        for(int i = 1;i<=sz;i++){
            parent[i] = i;
            rank[i]   = 1;
        }
    }
    
    int findPar(int u,int parent[]){
        if(parent[u] == u){
            return u;
        }
        return parent[u] = findPar(parent[u],parent);
    }
    
    void merge(int u, int v,int parent[],int rank[]){
        
        int par1 = findPar(u,parent);
        int par2 = findPar(v,parent);
        
        if(par1!=par2){
            
            if(rank[par1]<rank[par2]){
                parent[par1] = par2;
            }
            else if(rank[par1]>rank[par2]){
                parent[par2] = par1;
            }
            else{
                parent[par2] = par1;
            }
        }
        
    }
    
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();
        int parent[n+2];
        int rank[n+2];
        
        mySet(parent,rank,n);
        vector<int>ans;
        
        for(auto &edge:edges){
            
            int u = edge[0];
            int v = edge[1];
            
            int par1 = findPar(u,parent);
            int par2 = findPar(v,parent);
            
            if(par1 !=par2){
                merge(u,v,parent,rank);
            }else{
                ans.push_back(u);
                ans.push_back(v);
                break;
            }
            
        }
        
        return ans;
    }
