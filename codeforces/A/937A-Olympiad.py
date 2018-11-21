n=int(input())
a=[int(x) for x in input().split()]
b=set(a)
if 0 in b:
	b.remove(0)
print(len(b))