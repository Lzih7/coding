class Solution
{
public:
    vector<bool> onPath;
    bool hasCircle = false;
    vector<bool> vis;
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> graph(numCourses);
        for (auto edge : prerequisites)
        {
            int from = edge[1], to = edge[0];
            graph[from].push_back(to);
        }
        onPath = vector<bool>(numCourses, false);
        vis = vector<bool>(numCourses, false);
        for (int i = 0; i < numCourses; i++)
        {
            traverse(graph, i);
        }
        return !hasCircle;
    }
    void traverse(vector<vector<int>> &graph, int i)
    {
        if (hasCircle)
            return;
        if (onPath[i] == true)
        {
            hasCircle = true;
            return; 
        }
        if (vis[i])
            return;
        onPath[i] = true;
        vis[i] = true;
        for (int tmp : graph[i])
        {
            traverse(graph, tmp);
        }
        onPath[i] = false;
    }
};