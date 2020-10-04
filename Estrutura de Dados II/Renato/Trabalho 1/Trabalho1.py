import random
import string
import time

def row():
	print("-="*25)


#escrevendo no arquivo
def set_file(nome, idade, cpf, sexo):
	file = open('trabalho1.txt', 'a')
	file.write(f'{nome} {idade} {cpf} {sexo}\n')
	file.close()

#cadastrar pessoa manualmente
def set_pessoa():
	nome = str(input("Nome: "))
	idade = int(input("Idade: "))
	cpf = random.randint(1234723,99999999)
	sexo = str(input("Sexo f/m:"))
	nome = nome.replace(" ", "")
	
	set_file(nome,str(idade),str(cpf),sexo)

#apagando todos os registros do arquivo
def clean():
	file = open('trabalho1.txt','w')
	file.write('')
	file.close()
	print("Arquivo Limpo!")

#cadastrando de forma aleatoria
def set_pes_aleatorio():
	clean() #Apagando todos os registros para ficar só os que foram gerados
	n = int(input("Informe o número de pessoas que deseja cadastrar: "))	
	letras = string.ascii_lowercase
	s = ['f','m']
	for i in range(0,n):

		nome =  ''.join(random.choice(letras) for _ in range(6))
		idade = random.randint(1,100)
		cpf = random.randint(1234723,99999999)
		sexo =  random.choice(s)

		set_file(nome,str(idade),str(cpf),sexo)

#Retorna uma lista com os dados do arquivo
def get_file():
	file = open('trabalho1.txt', 'r')
	lista = file.readlines()
	file.close()
	return lista

#imprimir dados
def print_dados(f):
	print(f"Nome: {f[0]}\t Idade: {f[1]}\t CPF: {f[2]}\t Sexo: {f[3]}")


#Ps: os dados estão sendo ordenados pela idade
#Ordenação por seleção
def select():
	file = get_file() 
	file2 = [i.split(' ') for i in file]
	temp = time.time() 
	for i in range(len(file2)):
		for j in range(len(file2)):
			if int(file2[i][1]) < int(file2[j][1]): #instrução relevante
				aux = file2[i][:]
				file2[i] = file2[j]
				file2[j] = aux[:]


	row()
	print("\tLista Ordena Por idade: (select)")
	row()
	for f in file2:
		print_dados(f)

	row()
	print(f"Tempo gasto {time.time() - temp:.2f} seg")

#Ordenação por inserção
def insert():
	file = get_file() 
	file2 = [i.split(' ') for i in file]
	temp = time.time()

	for i in range(len(file2)):
		k = file2[i]
		while i > 0 and int(file2[i-1][1]) > int(k[1]): #instrução relevante
			file2[i] = file2[i-1]
			i -= 1
		file2[i] = k

	row()
	print("\tLista Ordena Por idade: (Insert)")
	row()
	for f in file2:
		print_dados(f)
	row()
	print(f"Tempo gasto {time.time() - temp:.2f} seg")


def lista_dados():
	file = get_file()
	file = [i.split(' ') for i in file]
	for f in file:
		print_dados(f)


#main
while True:
	row()
	print("\tSistema de cadastro de Pessoas")
	row()
	res = int(input("1-Prencher dados manualmente\n2-Sorteio aleatorio\n3-Sair\n4-Limpar arquivo\n5-Ordenar por idade (Seleção)\n6-Ordenar por idade (Inserção)\n7-Listar dados\nOpção: "))
	row()
	if res==1:
		set_pessoa()
	elif res == 2:
		set_pes_aleatorio()
	elif res==3:
		break
	elif res==4:
		clean()
	elif res==5:
		select()
	elif res==6:
		insert()
	elif res == 7:
		lista_dados()
	else:
		print("Opção invalida!")

