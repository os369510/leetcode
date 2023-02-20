class Solution {
private:
    bool *reachable;
    queue<int> q;
public:
    bool canReach(vector<int>& arr, int start) {
        int v, len = arr.size();
        reachable = (bool*) calloc(arr.size(), sizeof(bool));
        q.push(start);
        while (!q.empty()) {
            v = q.front();
            q.pop();
            if (arr[v] == 0) return true;
            if (reachable[v]) continue;
            reachable[v] = true;
            if (v + arr[v] < len) q.push(v + arr[v]);
            if (v - arr[v] >= 0) q.push(v - arr[v]);
        }
        return false;
    }
};
