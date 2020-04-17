# n1 = 4545**4545
# n2 = 2341**2341
n3 = 4545**5
# print("for n = 287**287")
k = str(n3)
while(len(k)!=1):
	print(len(k))
	n=0
	for d in k:
		n += int(d)
	k = str(n)
	
print("ans = ",k)