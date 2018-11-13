"""
Searching is a fundamental problem in algorithms, especially for graphs, trees, and other problems. 
We can always formulate a searching problem into a graph traversal question. Searching has two types, 
depth first search and breath first search. Depth first search means first visiting the children of the
node and later visiting his cousins, while breath first search means first visiting the cousins and then 
their children. 
"""

"""
Here we work on directed graphs. 
"""

class graphnode:
  def __init__(self, val, children = []):
    self.val = val
    self.children = children
   
"""
Recursion DFS traversal
"""

def dfsRecursive(node, visited, res):
  """
  :type node: graphnode
  :type visited: set
  :type res: list
  :rtype: void
  """
  if node in visited:
    return
  res.append(node.val) 
  visited.add(node)
  for child in node.children:
    dfs(child, visited, res)
    
    
    
"""
Iteration DFS using Stack 
"""
def dfsInterative(node):
  """
  :type node: graphnode
  :rtype: list[int]
  """
  stack = [node]
  stacked = set([node])
  while len(stack):
    top = stack.pop()
    res.append(top.val)
    for child in node.children:
      if child not in stacked:
        stack.append(child)
        stacked.add(child)
  return res
    
"""
The above implementations are like preorder tree walks, first push parent into results and then children
into results. Actually, one can also reverse the order, like postorder traversal, first push the children
into results and then push the parent into the results. However, it is not essentially different from 
preorder for searching problems.
"""

"""
Note: This iterative algorithm is not optimal in the case of tree traversal. In tree traversal, once does not
need to use a hashset to track the visited nodes, based on extra properties of tree: no cycle. 
"""
  
