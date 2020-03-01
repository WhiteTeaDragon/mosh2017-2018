def find(a, x):
    left = 0
    right = len(a)
    while right - left > 1:
        mid = (right + left) // 2
        if a[mid] > x:
            right = mid
        else:
            left = mid
    return a[left] == x

file_r = open("a2.txt", "r")
file_w = open("a2myans.txt", "w")

a = set()
for i in range(0, 1000):
    for j in range(0, 1000):
        x = str(i)
        y = str(j)
        z = ""
        if len(x) != len(y):
            continue
        for k in range(len(x)):
            z = z + str(int(x[k]) * int(y[k]))
        a.add(z)
a = list(a)
a.sort()
n = int(file_r.readline())
for i in range(n):
    x = str(int(file_r.readline()))
    if find(a, x):
        print("YES", file = file_w)
    else:
        print("NO", file = file_w)
file_r.close()
file_w.close()