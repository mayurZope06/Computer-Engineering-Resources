def astar(graph, heuristic, start, goal):
    open_list = [start]
    closed_list = []

    g_cost = {}
    f_cost = {}

    for node in graph:
        g_cost[node] = 999999
        f_cost[node] = 999999

    g_cost[start] = 0
    f_cost[start] = heuristic[start]

    while len(open_list) > 0:
        current = open_list[0]
        for node in open_list:
            if f_cost[node] < f_cost[current]:
                current = node

        if current == goal:
            print("Goal reached")
            print("Total cost:", g_cost[current])
            return

        open_list.remove(current)
        closed_list.append(current)

        for neighbor, weight in graph[current]:
            if neighbor in closed_list:
                continue

            new_g = g_cost[current] + weight

            if neighbor not in open_list:
                open_list.append(neighbor)
            elif new_g >= g_cost[neighbor]:
                continue

            g_cost[neighbor] = new_g
            f_cost[neighbor] = g_cost[neighbor] + heuristic[neighbor]

    print("Goal not found")

n = int(input("Enter number of nodes: "))
e = int(input("Enter number of edges: "))

graph = {}
for i in range(n):
    graph[i] = []

print("Enter edges (u v w):")
for i in range(e):
    u, v, w = map(int, input().split())
    graph[u].append((v, w))
    graph[v].append((u, w))

heuristic = {}
print("Enter heuristic values for each node:")
for i in range(n):
    heuristic[i] = int(input("Heuristic of node " + str(i) + ": "))

start = int(input("Enter start node: "))
goal = int(input("Enter goal node: "))

astar(graph, heuristic, start, goal)

# Enter number of nodes: 4
# Enter number of edges: 4
# Enter edges (u v w):
# 0 1 1
# 0 2 3
# 1 3 3
# 2 3 1
# Enter heuristic values:
# 4
# 2
# 1
# 0
# Enter start node: 0
# Enter goal node: 3
# Goal reached
# Total cost: 4

# import heapq

# def astar(graph, start, goal, heuristic):
#     priority_queue = [(0, start)]
#     cost_so_far = {start: 0}

#     while priority_queue:
#         current_cost, current_node = heapq.heappop(priority_queue)

#         if current_node == goal:
#             print("Goal reached with cost:", cost_so_far[current_node])
#             return

#         for neighbor, weight in graph[current_node]:
#             new_cost = cost_so_far[current_node] + weight

#             if neighbor not in cost_so_far or new_cost < cost_so_far[neighbor]:
#                 cost_so_far[neighbor] = new_cost
#                 priority = new_cost + heuristic[neighbor]
#                 heapq.heappush(priority_queue, (priority, neighbor))


# # Example Graph (Simple)
# graph = {
#     'A': [('B', 1), ('C', 3)],
#     'B': [('D', 3)],
#     'C': [('D', 1)],
#     'D': []
# }

# heuristic = {'A': 4, 'B': 2, 'C': 1, 'D': 0}

# print("Running A* Algorithm...")
# astar(graph, 'A', 'D', heuristic)

# 3) A* Algorithm

# Explanation:
# A* is an informed search algorithm used in path finding and game search problems. It uses:

# f(n) = g(n) + h(n)
# where g(n) is actual cost from start, and h(n) is heuristic cost to goal.

# Time Complexity: Worst case O(E) to O(b^d) depending on heuristic and search space
# Space Complexity: Can be high, often O(V) or more due to open and closed lists

# Viva Q&A:
# Q1. What is A?*
# A best-first search algorithm that uses cost and heuristic.

# Q2. What is heuristic?
# An estimated cost to reach the goal.

# Q3. Formula used?
# f(n) = g(n) + h(n)

# Q4. Where is A used?*
# Maps, robotics, games, route finding.