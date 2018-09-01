#!/bin/python

import sys

n=int(input())
dist=0
for i in range(n):
	k,s=input().split()
	k=int(k)
	if s[0]=='N':
		dist=dist-k
	elif s[0]=='S':
		dist=dist+k
	elif (dist==0 or dist==20000) and (s[0]=='E' or s[0]=='W'):
		print("NO")
		break
	if dist<0 or dist>20000:
		print("NO")
		break
	if i==n-1 and dist !=0:
		print("NO")
	elif i==n-1 and dist==0:
		print("YES")

