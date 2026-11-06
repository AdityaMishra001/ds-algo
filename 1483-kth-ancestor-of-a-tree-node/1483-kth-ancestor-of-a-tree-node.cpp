class TreeAncestor {
    vector<vector<int>> ancestor;
    int LOG, n;
public:
    TreeAncestor(int n, vector<int>& parent) {
        this->n=n;
        LOG = log2(n); // max 2^j size;
        ancestor.assign(n, vector<int>(16, -1));
        for (int node = 0; node < n; node++) {
            ancestor[node][0] = parent[node];
        }
        // j->>2^j jumps:
        //  2^j-1 --> 2^j-1 jumps
        //=>>2^j-1)*2=>2^j-1+1=2^j
        for (int j = 1; j <= LOG; j++) {
            for (int node = 0; node < n; node++) {
                if (ancestor[node][j - 1] != -1) {
                    ancestor[node][j] = ancestor[ancestor[node][j - 1]][j - 1];
                } 
            }
        }

    }

    int getKthAncestor(int node, int k) {
        if(k==1)
	    return ancestor[node][0];
        int ans=node;
        for (int j = 0; j <= LOG; j++) {
            if (k & (1 << j)) {
                ans = ancestor[ans][j];
                if (ans == -1)
                    break;
            }
        }

        return ans;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */