class Solution {
private:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> vec;
    vector<string> stk;
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto& it : tickets) {
            vec[it[0]].push(it[1]);
        }
        dfs("JFK");
        reverse(stk.begin(), stk.end());
        return stk;
    }

    void dfs(const string& curr) {
        while(vec.count(curr) && vec[curr].size() > 0) {
            string temp = vec[curr].top();
            vec[curr].pop();
            dfs(move(temp));
        }
        stk.push_back(curr);
    }
};