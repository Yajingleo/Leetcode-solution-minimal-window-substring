#Python
"""
Questions:
Given the adjacency matrix M, compute the number of friend circle. M[i][j] = 1 if and only if i and j are friends mutually. 
"""
"""
Algorithm:
Build a undirected graph for the friends, and count the connected components. Use DFS to tranverse the graph componentwisely
and record the visited nodes. 
"""

def friendsCircle(Matrix):
  graph = collections.defaultdict(list)
  n = len(Matrix)
  for i in range(n):
    for j in range(n):
      if Matrix[i][j] == 1:
        graph[i].append(j)
        
  visited = set([])
  
  def dfs(i):
    if i in visited:
      return 
    visited.insert(i)
    for j in graph[i]:
      dfs(j)
  
  n_components = 0
  for i in range(n):
    if i not in visited:
      n_components += 1
      dfs(i)
  return n_components
      
