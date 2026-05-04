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

start = int(input("Enter starting node: "))

dist = []
visited = []
for i in range(n):
    dist.append(999999)
    visited.append(False)

dist[start] = 0

for count in range(n):
    min_value = 999999
    u = -1

    for i in range(n):
        if visited[i] == False and dist[i] < min_value:
            min_value = dist[i]
            u = i

    visited[u] = True

    for v in range(n):
        if graph[u][v] != 0 and visited[v] == False:
            if dist[u] + graph[u][v] < dist[v]:
                dist[v] = dist[u] + graph[u][v]

print("Shortest distances:")
for i in range(n):
    print(start, "to", i, "=", dist[i])

# Enter number of vertices: 4
# Enter number of edges: 5
# Enter edges:
# 0 1 4
# 0 2 1
# 2 1 2
# 1 3 1
# 2 3 5
# Enter starting node: 0

# 0 to 0 = 0
# 0 to 1 = 3
# 0 to 2 = 1
# 0 to 3 = 4

# import heapq

# def dijkstra(graph, start):
#     distances = {node: float('inf') for node in graph}
#     distances[start] = 0

#     priority_queue = [(0, start)]

#     while priority_queue:
#         current_dist, current_node = heapq.heappop(priority_queue)

#         for neighbor, weight in graph[current_node]:
#             new_dist = current_dist + weight

#             if new_dist < distances[neighbor]:
#                 distances[neighbor] = new_dist
#                 heapq.heappush(priority_queue, (new_dist, neighbor))

#     print("Shortest distances from source:")
#     for node in distances:
#         print(f"{start} -> {node} = {distances[node]}")


# # Graph Input
# graph = {
#     0: [(1, 4), (2, 1)],
#     1: [(3, 1)],
#     2: [(1, 2), (3, 5)],
#     3: []
# }

# start = int(input("Enter starting node: "))
# dijkstra(graph, start)

# 8) Dijkstra’s Algorithm

# Explanation:
# Dijkstra’s algorithm finds the shortest path from a source to all vertices in a graph with non-negative weights. It repeatedly chooses the vertex with the smallest tentative distance.

# Time Complexity:
# With min-heap: O(E log V)

# Space Complexity: O(V)

# Viva Q&A:
# Q1. What does Dijkstra find?
# Shortest path from one source to all vertices.

# Q2. Can it handle negative weights?
# No.

# Q3. What data structure is used?
# Priority queue / min-heap.

# Q4. Is it greedy?
# Yes.