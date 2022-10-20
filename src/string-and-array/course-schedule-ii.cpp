class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<vector<int>> graph(numCourses);
        vector<int> indegress(numCourses, 0);
        queue<int> q;

        for(auto &prerequisite : prerequisites) {
            graph[prerequisite[1]].push_back(prerequisite[0]);
            ++indegress[prerequisite[0]];
        }

        for(int i = 0; i < numCourses; ++i) {
            if(indegress[i] == 0) {
                q.push(i);
            }
        }

        while(q.size()) {
            int cur = q.front();
            q.pop();
            ans.push_back(cur);

            for(int neighbor : graph[cur]) {
                if(--indegress[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return ans.size() == numCourses ? ans : vector<int>();
    }
};