class Solution {
public:
    string target = "123450";
    vector<vector<int>> dir{{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};
    int slidingPuzzle(vector<vector<int>>& board) 
    {
        int m = board.size(),n = board[0].size();
        string first = "";
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                first += to_string(board[i][j]);
            }
        }
        queue<pair<string,int>> q;
        unordered_set<string> visited;
        q.push({first,0});
        visited.insert(first);
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                auto cur = q.front();
                q.pop();
                
                string s = cur.first;
                int count = cur.second;
                
                if(s == target)
                {
                    return count;
                }
                int indx = s.find('0');
                for(auto &x: dir[indx])
                {
                    string temp = s;
                    
                    swap(temp[x],temp[indx]);
                    
                    if(!visited.count(temp))
                    {
                        visited.insert(temp);
                        
                        q.push({temp,count+1});
                    }
                }
            }
        }
        return -1;
        
    }
};
