/*
Number of islands
Given a matrix marked with 0 and 1, the connected components of 1's are islands. Find the number of islands.
*/
vector<pair<int, int>> directions = vector<pair<int, int>> (
                                    {make_pair(1,0), 
                                     make_pair(-1, 0), 
                                     make_pair(0,1), 
                                     make_pair(0,-1)}
                                    );

int numberOfIslands(vector<vector<char>>& M){
   int res = 0;
   for (int i = 0; i < M.size(); ++i) {
      for (int j = 0; j < M[0].size(); ++j) {
          if (M[i][j] == '1') {
             res += 1;
             dfs(M, i, j);
          }
      }
   }
   return res;
}

void dfs(vector<vector<char>>& M, int i, int j) {
  if (M[i][j] != '1') return;
  M[i][j] = '#';
  for (auto d: directions) {
    int x = i+d.first, y = j + d.second;
    if (x >= 0 && x < M.size() && y >= 0 && y < M[0].size() && M[i][j] == '1') {
        dfs(M, x, y);
    }
  }
}
