// Approach 2: binary Search + Greedy
// check mid strongest worker and mid easiest task, start from hardest tasks
class Solution {
public:
    bool checko1(vector<int>& tasks, vector<int>& workers, int pills, int strength, int mid) {
        sort(tasks.begin(),tasks.end());
        sort(workers.begin(),workers.end());
        int n = tasks.size();
        int i = 0, j = 0, _pills = pills;
        int ansl = 0;
        while(i < n && j < n) {
            if(tasks[i] <= workers[j]) {
                ansl++;i++;j++;
            }
            else if(_pills > 0 && tasks[i] <= workers[j]+strength) {
                ansl++; i++; j++; _pills--;
            }
            else {
                j++;
            }
        }
        i = n-1, j = n-1, _pills = pills;
        int ansr = 0;
        while(i >= 0 && j >= 0) {
            if(tasks[i] <= workers[j]) {
                ansr++;i--;j--;
            }
            else if(_pills > 0 && tasks[i] <= workers[j]+strength) {
                ansr++; i--; j--; _pills--;
            }
            else {
                i--;
            }
        }
        cout<<mid<<":"<<ansl<<" "<<ansr<<endl;
        return ansl >= mid;
    }
    // mid strongest worker do mid easiest task 
    bool check(vector<int>& tasks, vector<int>& workers, int pills, int strength, int mid) {
        sort(tasks.begin(),tasks.end());
        sort(workers.begin(),workers.end(),greater<>());
        int n = tasks.size(), ans = 0;
        // if(mid < 0 || mid > n) return false;
        multiset<int> workerst = multiset<int>(workers.begin(),workers.begin()+mid);
        for(int i = mid-1; i >= 0; i--) {
            int task = tasks[i];
            auto lb = workerst.lower_bound(task);
            if(lb != workerst.end()) {
                ans++; workerst.erase(lb);
                continue;
            }
            if(pills > 0) {
                lb = workerst.lower_bound(task-strength);
                if(lb != workerst.end()) {
                    ans++; pills--; workerst.erase(lb);
                    continue;
                }
            }
            break;
        }
        // cout<<mid<<":"<<ans<<endl;
        return ans >= mid;
    }
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int low = 0, high = min(tasks.size(),workers.size()), ans = low;
        while(low <= high) {
            int mid = (low+high)/2;
            if(check(tasks,workers,pills,strength,mid)) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
// task: 5 5 8 9 9 worker: 1 2 4 6 6 

// Approach 1: Greedy
// start from largest task, doing it first is always beneficial as even after boost if u cant do then no one else can anyways help so u can skip the task
class Solution1 {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int m = tasks.size(), n = workers.size();
        for(int i = 0; i < n; i++) {
            workers[i] += pills;
        }
        int ans = 0;
        sort(tasks.begin(),tasks.end(),greater<>());
        sort(workers.begin(),workers.end(),greater<>());
        int i = 0, j = 0;
        while(i < m && j < n) {
            if(tasks[i] <= workers[j]) {
                i++; j++; ans++;
            }
            else if(pills > 0 && workers[j] + strength >= tasks[i]) {
                i++; j++; pills--; ans++;
            }
            else {
                i++;
            }
        }
        return ans;
    }
};