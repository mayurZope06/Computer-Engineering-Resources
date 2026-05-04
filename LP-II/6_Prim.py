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
print("Prim's MST:")
for i in range(n):
    if parent[i] != -1:
        print(parent[i], "-", i, ":", graph[i][parent[i]])
        total_cost = total_cost + graph[i][parent[i]]

print("Total cost:", total_cost)

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

# def prim_mst(graph, start):
#     visited = set()
#     priority_queue = [(0, start)]
#     total_cost = 0

#     while priority_queue:
#         weight, node = heapq.heappop(priority_queue)

#         if node not in visited:
#             visited.add(node)
#             total_cost += weight

#             for neighbor, w in graph[node]:
#                 if neighbor not in visited:
#                     heapq.heappush(priority_queue, (w, neighbor))

#     print("Minimum Spanning Tree Cost:", total_cost)


# # Input
# n = int(input("Enter number of vertices: "))
# e = int(input("Enter number of edges: "))

# graph = {i: [] for i in range(n)}

# print("Enter edges (u v w):")
# for _ in range(e):
#     u, v, w = map(int, input().split())
#     graph[u].append((v, w))
#     graph[v].append((u, w))

# start = int(input("Enter starting node: "))

# print("Running Prim's Algorithm...")
# prim_mst(graph, start)


# 6) Prim’s Minimal Spanning Tree Algorithm

# Explanation:
# Prim’s algorithm starts from one vertex and keeps adding the minimum weight edge that connects the visited set to an unvisited vertex.

# Time Complexity:
# With min-heap: O(E log V)

# Space Complexity: O(V + E)

# Viva Q&A:
# Q1. What is Prim’s algorithm?
# A greedy algorithm to find MST.

# Q2. How does it grow the tree?
# By adding minimum weight edges one by one.

# Q3. What data structure is used?
# Priority queue / min-heap.

# Q4. Is Prim’s greedy?
# Yes.