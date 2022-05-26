x = 5
INF = 9999
def Floyd_Warshall(F_Graph):
	a = list(map(lambda u: list(map(lambda v: v, u)), F_Graph))

	for u in range(x):
			for v in range(x):
				a[u][v] = min(a[u][v], a[v][u])
	F_sol(a)

def F_sol(a):
	for u in range(x):
		for v in range(x):
			if(a[u][v] == INF):
				print("INF", end=" ")
			else:
				print(a[u][v], end=' ')
		print(" ")


F_Graph = [[0, 2, INF, 8, 1],
		[INF, 2, 0, INF, 9],
		[4, INF, 1, 4, 5],
		[2, INF, 1, 0, INF],
		[5, INF, INF, 3, 0]
		]

Floyd_Warshall(F_Graph)
