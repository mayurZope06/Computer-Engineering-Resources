def find(parent, i):
    if parent[i] == i:
        return i
    return find(parent, parent[i])

def union(parent, x, y):
    xroot = find(parent, x)
    yroot = find(parent, y)
    parent[xroot] = yroot

n = int(input("Enter number of vertices: "))
e = int(input("Enter number of edges: "))

edges = []
print("Enter edges (u v w):")
for i in range(e):
    u, v, w = map(int, input().split())
    edges.append([w, u, v])

edges.sort()

parent = []
for i in range(n):
    parent.append(i)

mst_cost = 0
print("Edges in MST:")

for edge in edges:
    w = edge[0]
    u = edge[1]
    v = edge[2]

    if find(parent, u) != find(parent, v):
        union(parent, u, v)
        mst_cost = mst_cost + w
        print(u, "-", v, ":", w)

print("Total MST cost:", mst_cost)

# Enter number of vertices: 4
# Enter number of edges: 5
# Enter edges:
# 0 1 2
# 0 3 6
# 1 2 3
# 1 3 8
# 2 3 7
# Total MST cost: 11

# def find(parent, node):
#     if parent[node] != node:
#         parent[node] = find(parent, parent[node])
#     return parent[node]

# def union(parent, u, v):
#     parent[find(parent, u)] = find(parent, v)


# # Input
# n = int(input("Enter number of vertices: "))
# e = int(input("Enter number of edges: "))

# edges = []
# print("Enter edges (u v w):")
# for _ in range(e):
#     u, v, w = map(int, input().split())
#     edges.append((w, u, v))

# edges.sort()
# parent = list(range(n))
# mst_cost = 0

# for weight, u, v in edges:
#     if find(parent, u) != find(parent, v):
#         union(parent, u, v)
#         mst_cost += weight

# print("Minimum Spanning Tree Cost:", mst_cost)

# 7) Kruskal’s Minimal Spanning Tree Algorithm

# Explanation:
# Kruskal’s algorithm sorts all edges by weight and adds them one by one if they do not create a cycle. It uses union-find.

# Time Complexity: O(E log E)
# Space Complexity: O(V + E)

# Viva Q&A:
# Q1. What is Kruskal’s algorithm?
# A greedy MST algorithm that sorts edges and selects valid minimum edges.

# Q2. How are cycles avoided?
# Using union-find / disjoint set.

# Q3. Is Kruskal’s edge-based or vertex-based?
# Edge-based.

# Q4. When is it useful?
# Sparse graphs.