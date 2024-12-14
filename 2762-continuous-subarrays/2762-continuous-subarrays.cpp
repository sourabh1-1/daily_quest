class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        int m = 31 - __builtin_clz(n);
        vector<vector<int>> dpmn(n, vector<int>(m + 1, INT_MAX));
        vector<vector<int>> dpmx(n, vector<int>(m + 1, INT_MIN));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < m + 1; j++) {
                if (j == 0) {
                    dpmn[i][j] = nums[i];
                    dpmx[i][j] = nums[i];
                }
                else {
                    int i2 = i + (1 << (j - 1));
                    dpmn[i][j] = min(dpmn[i][j - 1], i2 < n ? dpmn[i2][j - 1] : INT_MAX);
                    dpmx[i][j] = max(dpmx[i][j - 1], i2 < n ? dpmx[i2][j - 1] : INT_MIN);
                }
            }
        }
        auto getmin = [&](int l, int r) {
            int len = r - l + 1;
            int x = 31 - __builtin_clz(len);
            return min(dpmn[l][x], dpmn[r - (1 << x) + 1][x]);
        };
        auto getmax = [&](int l, int r) {
            int len = r - l + 1;
            int x = 31 - __builtin_clz(len);
            return max(dpmx[l][x], dpmx[r - (1 << x) + 1][x]);
        };
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int lo = i, hi = n - 1;
            while (hi - lo > 1) {
                int mid = (hi + lo) / 2;
                int mn = getmin(i, mid);
                int mx = getmax(i, mid);
                if (mx - mn <= 2)
                    lo = mid;
                else
                    hi = mid - 1;
            }
            int r = lo;
            int mn = getmin(i, hi); 
            int mx = getmax(i, hi); 
            if (mx - mn <= 2)
                r = hi;
            ans += r - i + 1;
        }
        return ans;
    }
};