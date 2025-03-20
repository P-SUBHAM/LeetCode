class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mpp;
        int maxi = 0, com = 0;

        // Count task frequencies
        for (char task : tasks) {
            mpp[task]++;
            maxi = max(mpp[task], maxi);
        }

        // Count how many tasks have max frequency
        for (auto it : mpp) {
            if (it.second == maxi) com++;
        }

        // Compute required intervals
        int ans1 = (maxi - 1) * (n + 1) + com;
        return max((int)tasks.size(), ans1);
    }
};