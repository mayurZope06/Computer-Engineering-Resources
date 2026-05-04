n = int(input("Enter number of vertices: "))

graph = []
for i in range(n):
    row = []
    for j in range(n):
        row.append(0)
    graph.append(row)

e = int(input("Enter number of edges: "))

print("Enter edges (u v w):")
for i in range(e):
    u, v, w = map(int, input().split())
    graph[u][v] = w
    graph[v][u] = w

visited = []
for i in range(n):
    visited.append(False)

key = []
parent = []
for i in range(n):
    key.append(999999)
    parent.append(-1)

start = int(input("Enter starting node: "))
key[start] = 0

for count in range(n):
    min_value = 999999
    u = -1

    for i in range(n):
        if visited[i] == False and key[i] < min_value:
            min_value = key[i]
            u = i

    visited[u] = True

    for v in range(n):
        if graph[u][v] != 0 and visited[v] == False and graph[u][v] < key[v]:
            key[v] = graph[u][v]
            parent[v] = u

total_cost = 0
print("Edges in MST:")
for i in range(n):
    if parent[i] != -1:
        print(parent[i], "-", i, ":", graph[i][parent[i]])
        total_cost = total_cost + graph[i][parent[i]]

print("Total MST cost:", total_cost)

# Enter number of vertices: 4
# Enter number of edges: 5
# Enter edges:
# 0 1 2
# 0 3 6
# 1 2 3
# 1 3 8
# 2 3 7
# Enter starting node: 0
# Total MST cost: 11

# import heapq

# def prim(graph, start):
#     visited = set()
#     pq = [(0, start)]
#     total_cost = 0

#     while pq:
#         weight, node = heapq.heappop(pq)

#         if node not in visited:
#             visited.add(node)
#             total_cost += weight

#             for neighbor, w in graph[node]:
#                 if neighbor not in visited:
#                     heapq.heappush(pq, (w, neighbor))

#     print("Minimum Spanning Tree Cost:", total_cost)


# # Input
# n = int(input("Enter number of vertices: "))
# e = int(input("Enter number of edges: "))

# graph = {i: [] for i in range(n)}

# print("Enter edges (u v w):")
# for _ in range(e):
#     u, v, w = map(int, input().split())
#     graph[u].append((v, w))
#     graph[v].append((u, w))  # undirected

# start = int(input("Enter starting node: "))

# prim(graph, start)


# 5) Minimum Spanning Tree (MST)

# Explanation:
# MST is a tree that connects all vertices of a weighted graph with minimum total edge weight and no cycles. It is not a separate algorithm; it is solved using Prim’s or Kruskal’s algorithm.

# Time Complexity:
# Depends on algorithm used: Prim’s or Kruskal’s

# Space Complexity:
# Depends on representation, usually O(V + E)

# Viva Q&A:
# Q1. What is MST?
# A spanning tree with minimum total cost.

# Q2. How many edges in MST?
# V - 1

# Q3. Does MST have cycles?
# No.

# Q4. Which algorithms find MST?
# Prim’s and Kruskal’s.