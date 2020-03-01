file_r = open("c2.txt", "r")
file_r2 = open("c_ans.txt", "r")
n = int(file_r.readline())
for i in range(n):
    a = list(map(int, file_r2.readline().split()))
    k = file_r.readline()
    k = int(file_r.readline())
    cards = [[]] * k
    for j in range(k):
        curr = file_r.readline().split()
        cards[j] = [int(curr[0]), float(curr[1])]
    m = int(file_r.readline())
    ans = 0
    prod = list(map(int, file_r.readline().split()))
    for j in range(m):
        if cards[a[j] - 1][0] > 0:
            ans += min(prod[j], cards[a[j] - 1][0]) * cards[a[j] - 1][1] / 100
        cards[a[j] - 1][0] -= prod[j]
    print(ans)
    
#308.3
#1456.188
#27383.600000000006
#4663.0
#297.8999999999999
#7504.500000000001
#12223.744999999999