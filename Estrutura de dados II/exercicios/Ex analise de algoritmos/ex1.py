#a) Faça um algoritmo recursivo que calcule a soma de todos os valores de um array de inteiros.
#b) Faça um algoritmo não recursivo que calcule a soma de todos os valores de um array de inteiros.
def soma_recusiva(array, posi):
	if posi == 0:
		return array[posi]
	else:
		return array[posi] + soma_recusiva(array, posi -1)


def soma_nao_recusiva(array):
	soma = 0
	for valor in array:
		soma += valor
	return soma



array = [5, 6, 7, 8, 3, 4, 2, 5, 7, 23, 12, 9]
print(f'Soma não recursiva: {soma_nao_recusiva(array)}')
print(f'Soma recursiva: {soma_recusiva(array, len(array)-1)}')