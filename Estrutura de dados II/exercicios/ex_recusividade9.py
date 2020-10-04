def getPrim(num, n):
	r = 0 
	if n > 1:
		if num%n == 0:
			return 0
		else:
			r = getPrim(num, n-1)
	else:
		return 1

	return r

n = int(input("Informe o número: "))
if getPrim(n,n-1) == 1:
	print(f"{n} é um número primo")
else:
	print(f"{n} não e um número primo")