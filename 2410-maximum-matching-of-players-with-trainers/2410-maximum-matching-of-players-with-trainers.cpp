class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(trainers.begin(), trainers.end());
        sort(players.begin(), players.end());
        int i = players.size() - 1, j = trainers.size() - 1;
        int ans = 0;
        while(i >= 0 && j >= 0){
            if(players[i] <= trainers[j])
                ans += 1, j -= 1;
            i -= 1;
        }
        return ans;
    }
};