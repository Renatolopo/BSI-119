import csv


#Função para validar entrada de números interiros
def validar_int(msg=""):
	while True:
		try:
			op = int(input(f"{msg}: "))
			break
		except:
			print("Entrada invalida!")

	return op


def abriArquivos(msg):
	arquivo = []
	try:
		with open(msg, encoding="utf-8") as obj:
			for l in obj:
				arquivo.append(l.strip())

		return arquivo

	except:
		print("Erro!")
		return arquivo


def abriArquivos_csv(diretorio):
	cidades = []

	try:
		with open(diretorio+".csv", encoding="utf-8") as obj:
			lines = csv.reader(obj)
			for line in lines:
				if line[0] == "Cidade":
					continue
				dic = {}
				dic["Cidade"] = line[0]
				dic["Estado"] = line[1]
				dic["Habitantes"] = int(line[2])
				cidades.append(dic)
			#print('oi')
	except:
		print("Erro ao ler!")

	return cidades


def salvarArquivo_csv(diretorio, cidade, t):
	try:
		with open(diretorio+".csv", t, encoding="utf-8", newline="") as obj:
			cidades = csv.writer(obj)
			cidades.writerow(cidade)
	except:
		print("Erro ao ler ou criar arquivo txt!")

		return