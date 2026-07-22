class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int count1 = 0;
        int n_str = s.size();
        for (int i = 0; i < n_str; i++) {
            if (s[i] == '1') count1++;
        }

        vector<vector<int>> zerotrack;
        for (int i = 0; i < n_str; ) {
            if (s[i] == '0') {
                vector<int> col(2);
                int start = i;
                while (i < n_str && s[i] == '0') i++;
                col[0] = start;
                col[1] = i - 1;
                zerotrack.push_back(col);
            } else {
                i++;
            }
        }

        int n = zerotrack.size();
        vector<int> A;
        if (n > 1) {
            for (int i = 0; i < n - 1; i++) {
                A.push_back((zerotrack[i][1] - zerotrack[i][0] + 1) + 
                            (zerotrack[i+1][1] - zerotrack[i+1][0] + 1));
            }
        }

        int K = 0;
        vector<vector<int>> st;
        if (!A.empty()) {
            K = 32 - __builtin_clz(A.size());
            st.assign(K, vector<int>(A.size(), 0));
            for (int i = 0; i < A.size(); i++) {
                st[0][i] = A[i];
            }
            for (int j = 1; j < K; j++) {
                for (int i = 0; i + (1 << j) <= A.size(); i++) {
                    st[j][i] = max(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
                }
            }
        }

        auto query_st = [&](int L, int R) {
            if (L > R || st.empty()) return 0;
            int j = 31 - __builtin_clz(R - L + 1);
            return max(st[j][L], st[j][R - (1 << j) + 1]);
        };

        auto get_len = [&](int id, int l, int r) {
            return max(0, min(zerotrack[id][1], r) - max(zerotrack[id][0], l) + 1);
        };

        vector<int> ans;
        ans.reserve(queries.size());

        for (int k = 0; k < queries.size(); k++) {
            int i = queries[k][0];
            int j = queries[k][1];

            if (n <= 1) {
                ans.push_back(count1);
                continue;
            }

            int fi = -1, s_idx = 0, e_idx = n - 1;
            while (s_idx <= e_idx) {
                int mid = s_idx + (e_idx - s_idx) / 2;
                if (zerotrack[mid][1] >= i) {
                    fi = mid;
                    e_idx = mid - 1;
                } else {
                    s_idx = mid + 1;
                }
            }

            int fj = -1; 
            s_idx = 0; 
            e_idx = n - 1;
            while (s_idx <= e_idx) {
                int mid = s_idx + (e_idx - s_idx) / 2;
                if (zerotrack[mid][0] <= j) {
                    fj = mid;
                    s_idx = mid + 1;
                } else {
                    e_idx = mid - 1;
                }
            }

            if (fi == -1 || fj == -1 || fi >= fj) {
                ans.push_back(count1);
                continue;
            }

            int maxzero = 0;

            if (fi + 1 == fj) {
                maxzero = get_len(fi, i, j) + get_len(fj, i, j);
            } else {
                int full_next = zerotrack[fi+1][1] - zerotrack[fi+1][0] + 1;
                int full_prev = zerotrack[fj-1][1] - zerotrack[fj-1][0] + 1;
                
                maxzero = max(maxzero, get_len(fi, i, j) + full_next);
                maxzero = max(maxzero, full_prev + get_len(fj, i, j));
                
                if (fi + 1 <= fj - 2) {
                    maxzero = max(maxzero, query_st(fi + 1, fj - 2));
                }
            }

            ans.push_back(count1 + maxzero);
        }
        return ans;
    }
};