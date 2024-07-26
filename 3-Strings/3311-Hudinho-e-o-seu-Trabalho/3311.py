names = []
for _ in range(int(input())):
    names.append(input())
analog = []
init = []
for _ in names:
    _ = [i for i in _]
    init.append(_[0])
while len(names) != 0:
    for _ in names:
        for i in _:
            if i == min(init):
                init.remove(i)
                analog.append(_)
                names.remove(_)
            break
        if _ in analog:
            break
for _ in analog:
    print (_)