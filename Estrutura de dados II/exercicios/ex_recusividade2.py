def getSoma(vet, n, soma):
	if n >= 0:
		soma = getSoma(vet, n-1, soma)
		return soma + vet[n]
	else:
		return 0
		

vet = [10.8, 2.55, 3.31]
soma = 0
print(f" A soma dos numeros {vet} e = {getSoma(vet,len(vet)-1,soma)}")