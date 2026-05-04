def bfs(start, adj, visited):
    queue = []
    front = 0

    queue.append(start)
    visited[start] = True

    while front < len(queue):
        node = queue[front]
        front += 1
        print(node, end=" ")

        for neighbor in adj[node]:
            if visited[neighbor] == False:
                visited[neighbor] = True
                queue.append(neighbor)

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

print("BFS Traversal:")
bfs(start, adj, visited)

# Enter number of vertices: 5
# Enter number of edges: 4
# Enter edges:
# 0 1
# 0 2
# 1 3
# 1 4
# Enter starting node: 0
# BFS Traversal:
# 0 1 2 3 4

# from collections import deque

# def bfs(start, adj_list, visited):
#     queue = deque([start])
#     visited[start] = True

#     while queue:
#         node = queue.popleft()
#         print(node, end=" ")

#         for neighbor in adj_list[node]:
#             if not visited[neighbor]:
#                 visited[neighbor] = True
#                 queue.append(neighbor)


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

# print("BFS Traversal:")
# bfs(start, adj_list, visited)


# 2) BFS (Breadth First Search)

# Explanation:
# BFS visits nodes level by level starting from a source node. It uses a queue and is useful when we want shortest paths in an unweighted graph.

# Time Complexity: O(V + E)
# Space Complexity: O(V) for queue and visited array

# Viva Q&A:
# Q1. What is BFS?
# BFS visits all nodes level by level.

# Q2. Which data structure is used?
# Queue.

# Q3. DFS and BFS difference?
# DFS goes deep first; BFS goes level by level.

# Q4. Where is BFS used?
# Shortest path in unweighted graphs, level traversal, searching.