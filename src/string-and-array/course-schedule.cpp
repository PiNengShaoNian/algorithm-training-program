class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegress(numCourses, 0);
        for(auto& prerequisite : prerequisites) {
            graph[prerequisite[1]].push_back(prerequisite[0]);
            ++indegress[prerequisite[0]];
        }
        queue<int> q;
        for(int i = 0; i < numCourses; ++i) {
            if(indegress[i] == 0) {
                q.push(i);
            }
        }

        int ans = 0;
        while(q.size()) {
            int cur = q.front();
            q.pop();
            ++ans;
            for(int neighbor : graph[cur]) {
                if(--indegress[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return ans == numCourses;
    }
};