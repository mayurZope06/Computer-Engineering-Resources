def dfs(node, adj, visited):
    visited[node] = True
    print(node, end=" ")

    for neighbor in adj[node]:
        if visited[neighbor] == False:
            dfs(neighbor, adj, visited)

n = int(input("Enter number of vertices: "))
e = int(input("Enter number of edges: "))

adj = []
for i in range(n):
    adj.append([])

print("Enter edges:")
for i in range(e):
    u, v = map(int, input().split())
    adj[u].append(v)
    adj[v].append(u)

visited = []
for i in range(n):
    visited.append(False)

start = int(input("Enter starting node: "))

print("DFS Traversal:")
dfs(start, adj, visited)

# Enter number of vertices: 5
# Enter number of edges: 4
# Enter edges:
# 0 1
# 0 2
# 1 3
# 1 4
# Enter starting node: 0
# DFS Traversal:
# 0 1 3 4 2

# def dfs(node, adj_list, visited):
#     visited[node] = True
#     print(node, end=" ")

#     for neighbor in adj_list[node]:
#         if not visited[neighbor]:
#             dfs(neighbor, adj_list, visited)


# # Main Program
# n = int(input("Enter number of vertices: "))
# e = int(input("Enter number of edges: "))

# adj_list = {i: [] for i in range(n)}

# print("Enter edges (u v):")
# for _ in range(e):
#     u, v = map(int, input().split())
#     adj_list[u].append(v)
#     adj_list[v].append(u)

# visited = {i: False for i in range(n)}

# start = int(input("Enter starting node: "))

# print("DFS Traversal:")
# dfs(start, adj_list, visited)

# 1) DFS (Depth First Search)

# Explanation:
# DFS is a graph traversal technique that explores a node deeply first and then backtracks. It is usually implemented using recursion or stack. In an undirected graph, a visited array is used to avoid revisiting nodes.

# Time Complexity: O(V + E)
# Space Complexity: O(V) for visited array + recursion stack

# Viva Q&A:
# Q1. What is DFS?
# DFS is a traversal algorithm that goes as deep as possible before backtracking.

# Q2. Which data structure is used?
# Stack, usually through recursion.

# Q3. Why do we need visited?
# To avoid repeated visits and infinite loops in cyclic graphs.

# Q4. Where is DFS used?
# Cycle detection, path finding, topological sorting, connected components.