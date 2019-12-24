a1 = 1
a2 = 1
i = 2
while True:
    a3 = a1 + a2
    a1 = a2
    a2 = a3
    i = i + 1
    if a3 < 10**999:
        pass
    else:
        print(i)
        break
