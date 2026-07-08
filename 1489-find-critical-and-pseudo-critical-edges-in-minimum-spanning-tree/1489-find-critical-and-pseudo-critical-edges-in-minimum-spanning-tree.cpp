class DSU {
	vector<int> parent, rank;
	
	public:
	DSU(int n) {
		parent.resize(n);
		rank.resize(n);
		for (int i = 0; i < n; i++) {
			parent[i] = i;
			rank[i] = 1;
		}
	}
	
	int find(int i) {
		return (parent[i] == i) ? i : (parent[i] = find(parent[i]));
	}
	
	void unite(int x, int y) {
		int s1 = find(x), s2 = find(y);
		if (s1 != s2) {
			if (rank[s1] < rank[s2])
				parent[s1] = s2;
			else if (rank[s1] > rank[s2])
				parent[s2] = s1;
			else
				parent[s2] = s1, rank[s1]++;
		}
	}
};
class Solution {
public:
    int kruskalsMST(int V, vector<vector<int>> &edges,int add,int skip) {
		
		DSU dsu(V);
		int cost = 0, count = 0;
		if (add != -1){
            dsu.unite(edges[add][0],edges[add][1]);
            cost += edges[add][2];
            count ++;
        }
		for (int i =0;i<edges.size();i++) {
            if (i== skip) continue;
			int x = edges[i][0], y = edges[i][1], w = edges[i][2];
			if (dsu.find(x) != dsu.find(y)) {
				dsu.unite(x, y);
				cost += w;
				if (++count == V - 1)
					break;
			}
		}

        for (int i =0;i<V;i++){
            if (dsu.find(i) != dsu.find(0)) return INT_MAX;
        }

		return cost;
	}
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<int>critical ;
        vector<int>pseudo;
        for (int i =0;i<edges.size();i++){
            edges[i].push_back(i);
        }
        sort(edges.begin(), edges.end(), [](vector<int> &a, vector<int> &b) {
			return a[2] < b[2];
		});
        int mstWeight = kruskalsMST(n,edges,-1,-1);

        for (int i =0;i<edges.size();i++){
            if (kruskalsMST(n,edges,-1,i) > mstWeight){
                critical.push_back(edges[i][3]);
            }
            else if (kruskalsMST(n,edges,i,-1) == mstWeight) {
                pseudo.push_back(edges[i][3]);
            }
        }
        return {critical,pseudo};
    }
};