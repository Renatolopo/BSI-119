class NodoArvore:
	def __init__(self, chave=None, esquerda=None, direita=None):
		self.chave = chave
		self.esquerda = esquerda
		self.direita = direita

	def __repr__(self):
		return '%s <- %s -> %s' %(self.esquerda and self.esquerda.chave,
			self.chave, self.direita and self.direita.chave)

def em_ordem(raiz):
	if not raiz:
		return

	em_ordem(raiz.esquerda)
	print(raiz.chave)
	em_ordem(raiz.direita)

def insere(raiz, nodo):
	#insere nodo na raiz atual
	if raiz is None:
		raiz = nodo

	# insere na sub arvore a direita
	elif raiz.chave < nodo.chave:
		if raiz.direita is None:
			raiz.direita = nodo
		else:
			insere(raiz.direita, nodo)

	# insere na sub arvore a esquerda
	else:
		if raiz.esquerda is None:
			raiz.esquerda = nodo
		else:
			insere(raiz.esquerda, nodo)

def busca(raiz, chave):
	# chave não existe
	if raiz is None:
		return None
	# chave encontrada
	if raiz.chave == chave:
		return raiz
	# chave na sub arvore a direita
	if raiz.chave < chave:
		return busca(raiz.direita, chave)
	# arvore na sub arvore a direita
	return busca(raiz.esquerda, chave)


vetor  = [34,2,12,7,98,60,5,27,21,87]
raiz = NodoArvore(vetor[0])
for i in range(1,len(vetor)):
	nodo = NodoArvore(vetor[i])
	insere(raiz, nodo)

em_ordem(raiz)
