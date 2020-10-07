class TabelaHash:
	def __init__(self):
		self.size = 11 # numero de elementos na tabela
		self.slots = [None] * self.size # armazena as chaves
		self.data = [None] * self.size # aramzena os dados

	# add elemento na tabela
	def put(self, chave, data):
		# calcula o hash da chave
		hash_value = self.hash_function(chave, len(self.slots))

		# caso a posição do hash esteja desoculpada 
		if self.slots[hash_value] == None:
			self.slots[hash_value] = chave
			self.data[hash_value] = [data] # em formato de lista para adicionar elementos de chaves iguais

		else:
			# se as chaves são as mesma,nesse caso vc poderia subistituir o data
			# na minha implementação eu estou colocando todos em uma lista para 
			# adicionar elementos de chave igual
			if self.slots[hash_value] == chave:
				self.data[hash_value].append(data)

			else:
				# o hash retornado já existe, recalcula ate achar outra posição
				next_slot = self.rehash(hash_value, len(self.slots))
				while self.slots[next_slot] != None and self.slots[next_slot] != chave:
					next_slot = self.rehash(next_slot, len(self.slots))

				if self.slots[next_slot] == None:
					self.slots[next_slot] = chave
					self.data[next_slot] = [data]

				else:
					self.data[next_slot].append(data)

	# função hash, retorna um valor de acordo com a chave
	def  hash_function(self, chave, size):
		return chave % size

	# re calcula o hash quando a posição ja está ocupada
	def rehash(self, old_hash, size):
		return (old_hash+1) % size

	# dado a chave é retornado o dado
	def get(self, chave):
		start_slot = self.hash_function(chave, len(self.slots))

		data = None
		stop = False
		found = False
		position = start_slot
		while self.slots[position] != None and not found and not stop:
			if self.slots[position] == chave:
				found = True
				data = self.data[position]

			else:
				position = self.rehash(position, len(self.slots))
				if position == start_slot: #deu a volta, chave não existe
					stop = True

		return data

	def __getitem__(self, chave):
		return self.get(chave)

	def __setitem__(self, chave, data):
		self.put(chave, data)


"""
instanciando objeto
H = TabelaHash()

add um dado
H[chave] = dado  ex: -> H[45] = 'python'

buscando um dado
H[chave]   ex: -> H[45] (return ['python'])

----------------------

A hash_function e rehash podem ser adapitadas de acordo com o 
metodo de calcualr o hash voce quer implementar aqui é usado 
o resto da divisão da chave é o tamanho da tabela, existem outras 
maneiras de fazer isso inclusive com strings

----------------------

referencia:
https://panda.ime.usp.br/pythonds/static/pythonds_pt/05-OrdenacaoBusca/Hashing.html

"""