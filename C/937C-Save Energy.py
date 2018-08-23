k,d,t=input().split()
k,d,t=int(k),int(d),int(t)
on=k
off=d-(k-1)%d-1
cycle=on+off/2
time=(on+off)*(t//cycle)
t-=cycle*(t//cycle)
if t<k:
	print(t+time)
else:
	print(time+k+(t-k)*2)