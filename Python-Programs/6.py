a = []
j = 1
while (j <= 3):
    index = int(raw_input("index:"))
    b = [raw_input("input:") for i in range(0, int(index))]
    b = [int(i) for i in b]
    a.append(b)
    j = j + 1

max_num = []
for i in range(0, len(a)):
    for j in range(0, len(a[i])):
        max_num.append(max(a[i]))
        break

sum_max = map(lambda x : x*x, max_num)
final = sum(sum_max)/10
print final
