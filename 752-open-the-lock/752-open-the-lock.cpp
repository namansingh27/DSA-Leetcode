class Solution {
public:
    bool isValid(string &s, unordered_map<string,int>&mp){
        if(mp.find(s) == mp.end()) return true;
        return false;
    }
    int openLock(vector<string>& deadends, string target) {
        vector<int>adj[10];
        for(int i=1; i<=8; i++){
            adj[i].push_back(i-1);
            adj[i].push_back(i+1);
        }
        adj[0].push_back(1);
        adj[0].push_back(9);
        adj[9].push_back(0);
        adj[9].push_back(8);
        unordered_map<string,int>mp;
        for(int i=0; i<deadends.size(); i++){
            mp[deadends[i]] = 1;
        }
        if(mp.find("0000") != mp.end()) return -1;
        queue<string>q;
        mp["0000"] = 1;
        q.push("0000");
        int count = 0;
        while(!q.empty()){
            int size = q.size();
            for(int z=0; z<size; z++){
                string top = q.front();
                q.pop();
                if(top == target) return count;
                for(int i=0; i<top.size(); i++){
                    for(auto p: adj[top[i]-'0']){
                        string temp = top;
                        char k = p + '0';
                        temp[i] = k;
                        if(isValid(temp,mp)){
                            q.push(temp);
                            mp[temp] = 1;
                        }
                    }
                }   
            }
            count++;
        }
        return -1;
    }
};