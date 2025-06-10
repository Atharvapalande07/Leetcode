class Solution {
public:
  int trapRainWater(vector<vector<int>>& hm) {
    int row = hm.size(), col = hm[0].size(), dir[5] = {0,1,0,-1,0}, answer = 0;

    std::vector<std::vector<bool>> visited(row, std::vector<bool>(col, false)); 
    std::priority_queue<std::pair<int, std::pair<int, int>>, std::vector<std::pair<int, std::pair<int, int>>>, std::greater<>> q;
    std::queue<std::pair<int, int>> cq;
    
    for (int i = 0, k = row - 1; i < col; ++i) {
      q.push({hm[0][i], {0, i}});
      q.push({hm[k][i], {k, i}});
      visited[0][i] = true;
      visited[k][i] = true;
    }
    for (int i = 1, k = col - 1; i < row - 1; ++i) {
      q.push({hm[i][0], {i, 0}});
      q.push({hm[i][k], {i, k}});
      visited[i][0] = true;
      visited[i][k] = true;
    }

    while(!q.empty()) {
      auto [val, coord] = q.top();
      auto [r, c] = coord;
      q.pop();
      cq.push({r, c});
      while (!cq.empty()) {
        auto [cr, cc] = cq.front();
        cq.pop();
        for(int i = 0, k = 1; i < 4; ++i, ++k) {
          int nr = cr + dir[i];
          int nc = cc + dir[k];
          if (nr < 0 || nc < 0 || nr >= row || nc >= col || visited[nr][nc]) continue;
          
          if (hm[nr][nc] <= val) {
            answer += val - hm[nr][nc];
            cq.push({nr, nc});
          } else {
            q.push({hm[nr][nc], {nr, nc}});
          }
          visited[nr][nc] = true;
        }
      }
    } 
    return answer;   
  }
};