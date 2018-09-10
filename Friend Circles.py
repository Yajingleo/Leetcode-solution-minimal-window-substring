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
# Codes 1 
def friendsCircle(Matrix):
  n = len(Matrix)
  visited = set([])
  
  def dfs(i):
    if i in visited:
      return 
    visited.add(i)
    for j in range(n):
      if Matrix[i][j]:
        dfs(j)
  
  n_components = 0
  for i in range(n):
    if i not in visited:
      n_components += 1
      dfs(i)
  return n_components

#Codes 2  
def friendsCircle(M):
  def dfs(i, M, group, num):
    if i in group:
      return 
    group[i] = num
    for j in range(len(M)):
      if M[i][j] == 1:
        dfs(j, M, group, num)
        
  res = 0
  group = {}
  for i in range(len(M)):
      if i not in group:
          res += 1
          dfs(i, M, group, res)
  return res
