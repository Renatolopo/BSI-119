def getPoten(x,n):
	if  n < 1:
		return 1
	else:
		return x * getPoten(x,n-1)#chamada recussiva

n =0
while n >= 0:
	x = int(input("Informe X: "))
	n = int(input("Informe N: "))
	print(f"{x} elevado a {n} = {getPoten(x,n)}")
	print("---"*10)