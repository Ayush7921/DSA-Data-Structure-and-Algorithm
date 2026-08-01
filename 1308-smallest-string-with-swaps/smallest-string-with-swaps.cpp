#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int parent[100005];
    int rank[100005];

    int find(int i) {
        if (i == parent[i]) {
            return i;
        }
        return parent[i] = find(parent[i]);
    }

    void unite(int i, int j) {
        int x = find(i);
        int y = find(j);
        
        if (x != y) {
            if (rank[x] > rank[y]) {
                parent[y] = x;
            } else if (rank[x] < rank[y]) {
                parent[x] = y;
            } else {
                parent[y] = x;
                rank[x]++;
            }
        }
    }

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        // 1. Fast I/O: Tells C++ not to sync with C-style I/O, resulting in massive speedups
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = s.size();
        
        // Use raw arrays instead of vectors for DSU to avoid allocation overhead
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }

        for (const auto& e : pairs) {
            unite(e[0], e[1]);
        }

        // 2. Flat 1D Vector (Ultimate CPU Cache Locality)
        // Instead of an unordered_map, we map [root][char] to a 1D index: (root * 26 + char)
        // This allocates exactly one block of memory and makes lookups instantaneous.
        vector<int> count(n * 26, 0);
        
        for (int i = 0; i < n; i++) {
            count[find(i) * 26 + (s[i] - 'a')]++;
        }

        // 3. The "Pointer" Trick
        // Remembers the smallest available character for each DSU group so we don't restart from 0
        vector<int> pointer(n, 0);

        for (int i = 0; i < n; i++) {
            int root = find(i);
            int base = root * 26;
            
            // Skip empty character counts instantly
            while (count[base + pointer[root]] == 0) {
                pointer[root]++;
            }
            
            s[i] = pointer[root] + 'a';
            count[base + pointer[root]]--;
        }

        return s;
    }
};