#leia o arquivo README

from funções import *
from random import randint

#---------------------------------------------------------------------------------
FILE = ["Cidade","Estado", "Habitantes"]


#Função para imprimir as cidades
def getcidade(cidades=[], salvar=False):
	#salvarArquivo_csv("Dados/cidades", FILE, "w")	
	for cit in cidades:
		print("-"*40)
		print(f"""\tCidade: {cit['Cidade']}
	Estado: {cit['Estado']}
	Habitantes: {cit['Habitantes']}  <==""")

	# Para salvar os dados ordenados basta remover o comentario do código na linha 11 e os códigos abaixo.
	"""	if salvar:
			salvar = [cit['Cidade'],cit['Estado'],cit['Habitantes']]
			salvarArquivo_csv("Dados/cidades_Ordenadas", salvar, "a")"""

	return


#Função para gera de forma aleatória as cidades é salvar no arquivo .csv.
def cidades_aleatorias(dados=10000):
	estados = abriArquivos("estados/estados.txt")
	cit = abriArquivos("estados/cidades.txt")
	lista = []
	c = 0

	while True:
		cidade = []
		num = randint(0, len(cit)-1)
		cidade.append(cit[num])
		cidade.append(estados[randint(0, len(estados)-1)])
		cidade.append(randint(1, 10000))
		lista.append(cidade)

		if c == dados:
			break

		#if len(cit)==0:
		#	break
		c += 1

	for c in lista:
		salvarArquivo_csv("Dados/cidades", c, "a")

	return


#Função para Cadastrar de forma manual as cidades.
def setCidades():
	print("="*40)
	print("Cadastro de Cidades!".center(40))
	print("="*40)

	while True:
		cidade = []
		cidade.append(input("Cidade: ").strip().title())
		cidade.append(input("Estado: ").strip().title())
		cidade.append(validar_int("QTDE Habitantes: "))
		salvarArquivo_csv("Dados/cidades", cidade, "a")
		print(cidade)
		op = input("\nNova cidade: [S/N]").upper().strip()
		if op in"nN":
			break
	return


#Função para ordenar as cidades pelo método Insertion.
def Ordenar_insertion(cidades=[]):
	h =  "Habitantes"
	for i in range(1, len(cidades)):
		c = i-1
		while c >=0 and cidades[i][h] < cidades[c][h]:
				aux = cidades[c]
				cidades[c] = cidades[i]
				cidades[i] = aux
				i = c
				c =i-1

	return cidades


#Função para ordenar as cidades pelo método Salection.
def Ordenar_salection(cid=[]):
	n = len(cid)
	h =  "Habitantes"
	for i in range(n-1):
		ind = i
		for c in range(i+1, n):
			if cid[ind][h] > cid[c][h]:
				ind = c
		if cid[i][h] > cid[ind][h]: 
			aux = cid[i]
			cid[i] = cid[ind]
			cid[ind] = aux 
	
	return cid


#------------------------------------------------------------------
def menu():
	print(f'\033[31m teste')
	print('='*40)
	print("Cadastro de Cidades!\033[0;0m".center(40))
	print("="*40)

	print("""\t1 - Cadastra Aleatório.
	2 - Cadastra de forma manual.
	3 - lista.
	4 - Ordenar por Insertion.
	5 - Ordenar por Selection.
	6 - SAIR!""")
	print("-"*40)

	return validar_int("Opção")


#função principal do programa.
def main():
	salvarArquivo_csv("Dados/cidades", FILE, "w")

	while True:
		op = menu()

		cidades = abriArquivos_csv("Dados/cidades")

		if op == 1:
			num = validar_int("Quantos dados deseja gerar")
			salvarArquivo_csv("Dados/cidades", FILE, "w")
			cidades_aleatorias(num)
		elif op == 2:
			setCidades()
		elif op == 3:
			getcidade(cidades) #Lista os dados
		elif op == 4:
			insertion = Ordenar_insertion(cidades[:])
			getcidade(insertion, True) 	#imprime os dados ordenados.
		elif op == 5:
			selection = Ordenar_salection(cidades[:])
			getcidade(selection, True )	#imprime os dados ordenados.
		else:
			break
	return


#--------------------------------------------------------
main()