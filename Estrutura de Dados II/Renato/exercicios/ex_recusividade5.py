def getBin(n, b):
	if n <= 1:
		b.append(1)
		return 0

	else:
		n2 = n/2
		if n%2 != 0:
			n2-1	
		getBin(n2,b)
		if n%2 == 0:
			b.append(0)
		else:
			b.append(1)

#so funciona ate certos numeros


n = int(input("Informe o número: "))
bina = []
getBin(n,bina)
print(f"O número {n}  = {bina}")