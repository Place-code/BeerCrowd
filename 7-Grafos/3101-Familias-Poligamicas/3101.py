def dfs(graph, dead):
    visited, stack = set(), []
    nfamilies, index = 0, -1
    inhabitants = []
    for node in graph:
        if node not in visited:
            nfamilies += 1
            index += 1
            inhabitants.append(0)
            stack.append(node)
            while stack:
                v = stack.pop()
                if v not in visited:
                    visited.add(v)
                    if v not in dead:
                        inhabitants[index] += 1
                    stack.extend(reversed(graph[v]))
    zeroes = inhabitants.count(0)
    for i in range(zeroes):
        inhabitants.remove(0)
    nfamilies -= zeroes
    print (f"Quantidade de familias: {nfamilies}\nNumero de habitantes em cada: ", end='')
    inhabitants.sort()
    len_inhabitants = len(inhabitants)
    if len_inhabitants == 1:
        print (inhabitants[0])
    elif len_inhabitants == 2:
        print (inhabitants[0], "e", inhabitants[-1])
    else:
        for index, i in enumerate (inhabitants):
            if index == len_inhabitants-1:
                print("e", i)
            elif index == len_inhabitants-2:
                print (i, "", end='')
            else:
                print (f"{i}, ", end='')

nvertices, nedges = input().split()
nvertices, nedges = int(nvertices), int(nedges)
graph = {}
dead = []
for i in range(1, nvertices + 1):
    graph.update({i : []})
for i in range (nedges):
    vertex, neighbor = input().split()
    vertex, neighbor = int(vertex), int(neighbor)
    graph[vertex].append(neighbor)
    graph[neighbor].append(vertex)
for i in range(int(input())):
    dead.append(int(input()))
dfs(graph, dead)