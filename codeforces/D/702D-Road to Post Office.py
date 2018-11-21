#!/bin/python
import sys

d,k,a,b,t =input().split()
d,k,a,b,t =int(d),int(k),int(a),int(b),int(t)
if d<=k:
	if a>b:
		print(b*d)
	else:
		print(a*d)
elif a*k+t>=b*k:
	if a<b:
		print((d-k)*b+k*a)
	else:
		print(d*b)
else:
	q=d//k
	m=d%k
	ans=q*(a*k+t)-t
	if m*b<=t+m*a:
		ans=ans+m*b
	else:
		ans=ans+t+m*a
	print(ans)