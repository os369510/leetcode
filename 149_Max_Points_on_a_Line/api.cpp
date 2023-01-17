class Solution {
private:
    std::map<double,int> m;
    std::map<double,int>::iterator it;
public:
    int maxPoints(vector<vector<int>>& points) {
        short num_nodes = points.size();
        int max = 1; double max_slope;
        for (int p = 0; p < num_nodes - 1; p++) {
            m.clear();
            for (int p2 = p + 1; p2 < num_nodes; p2++) {
                double slope;
                int x, y;
                if (points[p][1] == points[p2][1])
                    slope = DBL_MAX;
                else {
                    x = points[p][0] - points[p2][0];
                    y = points[p][1] - points[p2][1];
                    slope = x / (double)y;
                }
                if (slope == max_slope) continue;
                it = m.find(slope);
                if (it == m.end())
                    m[slope] = 2;
                else
                    m[slope]++;
            }
            for (std::map<double,int>::iterator _it=m.begin(); _it!=m.end(); ++_it) {
                if (max < _it->second) {
                    max = _it->second;
                    max_slope = _it->first;
                }
            }
        }
        return max;
    }
};
