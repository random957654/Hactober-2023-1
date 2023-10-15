// DSU by size
class dsu{
public:
vector<int> parent, size;
    dsu(int n){
        parent.resize(n);
        size.resize(n, 1);
        for(int i = 0; i < n; i++) parent[i] = i;
    }

    int findUParent(int node){
        if(parent[node] == node) return node;
        return parent[node] = findUParent(parent[node]);
    }

    void unionBySize(int u, int v){
        int pu = findUParent(u);
        int pv = findUParent(v);
        if(pu == pv) return;
        if(size[pu] >= size[pv]){
            size[pu] += size[pv];
            parent[pv] = pu;
        }
        else if(size[pu] < size[pv]){
            size[pv] += size[pu];
            parent[pu] = pv;
        }
    }
};


// DSU by rank;
class dsu{
    vector<int> rank, parent;
public:
    dsu(int n){
        rank.resize(n, 0);
        parent.resize(n);
        for(int i = 0; i < n; i++) parent[i] = i;
    }

    int findUParent(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUParent(parent[node]);
    }

    void unionByRank(int u, int v){
        int parentU = findUParent(u);
        int parentV = findUParent(v);
        if(parentU == parentV) return;
        if(rank[parentU] < rank[parentV]){
            parent[parentU] = parentV;
        }
        else if(rank[parentU] > rank[parentV]){
            parent[parentV] = parentU;
        }
        else{
            parent[parentU] = parentV;
            rank[parentV]++;
        }
    }
};
