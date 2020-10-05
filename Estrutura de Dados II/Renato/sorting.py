import random
def selectsort(lista):
	for i in range(len(lista)):
		for j in range(len(lista)):
			if lista[j] >= lista[i]:
				lista[j], lista[i] = lista[i], lista[j]




def quicksort(lista, inicio=0, fim=None):
	print(lista)
	if fim is None:
		fim = len(lista)-1

	if inicio < fim:
		p = partition(lista, inicio, fim)
		quicksort(lista, inicio, p-1)
		quicksort(lista, p+1, fim)

def partition(lista, inicio, fim):
	# paga sempre o ultimo elemento da partição como pivor
	pivot = lista[fim] 
	i = inicio
	for j in range(inicio, fim):
		if lista[j] <= pivot:
			lista[j], lista[i] = lista[i], lista[j]
			i = i + 1
	lista[i], lista[fim] = lista[fim], lista[i]
	return i 

def insertsort(lista, h=1):
	for i in range(len(lista)):
		while i > 0 and lista[i - h] > lista[i]:
			lista[i], lista[i -h] = lista[i - h], lista[i]
			i -= h


def shellsort(lista, h=None):
	print(lista)
	if h is None:
		h =  int(len(lista)/2)
	insertsort(lista,h)

	if h > 1:
		shellsort(lista, int(h/2))
	


#lista = [3, 4, 6, 3 , 5]
lista = random.sample(range(1, 100), 19)
print('--'*50)
print(f'Sem ordenar: {lista}')
shellsort(lista)
print(f'Ordenada: {lista}')
print('--'*50)

