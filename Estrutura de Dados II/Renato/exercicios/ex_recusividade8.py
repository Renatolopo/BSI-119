def fibo(n,ax, fib,cont):
	if cont >= n:
		return 0
	cont += 1
	print(fib)
	fibo(n,fib,fib+ax,cont)


n = int(input("Informe N: "))
fibo(n,1,0,0)