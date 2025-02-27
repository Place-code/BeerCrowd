def dfs(graph):
    visited, connected, stack = [], [], []
    index = -1
    for node in graph:
        if node not in visited:
            connected.append([])
            index += 1
            stack.append(node)
            while stack:
                v = stack.pop()
                if v not in visited:
                    connected[index].append(v)
                    visited.append(v)
                    stack.extend(reversed(graph[v]))
    return connected

alphabet = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
for i in range(int(input())):
    graph = {}
    nvertices, nedges = input().split()
    nvertices, nedges = int(nvertices), int(nedges)
    graph.update({alphabet[i] : [] for i in range(nvertices)})
    for q in range(nedges):
        edge, neighbor = input().split()
        graph[edge].append(neighbor)
        graph[neighbor].append(edge)
    print (f"Case #{i+1}:")
    counter = 0
    for connected in dfs(graph):
        connected.sort()
        print (',' .join(connected), end='')
        print (',')
        counter += 1
    print (counter, "connected components\n")