#include <bits/stdc++.h>
using namespace std;

#define  x 5
#define Inf 9999

void Dis_tance(int a[][x]);

void Floyd_Warshall(int V[][x])
{
	int a[x][x], u, v, w;

	for (u = 0; u < x; u++)
	for (v = 0; v < x; v++)
		a[u][v] = V[u][v]; 
			
	for (w = 0; w < x; w++) 
	{
		for (u = 0; u < x; u++) 
		{
			for (v = 0; v < x; v++) 
			{
				if (a[u][v] > (a[u][w] + a[w][v])
				        && (a[w][v] != Inf
						&& a[u][w] != Inf))
					a[u][v] = a[u][w] + a[w][v];
			}
		}
	}
	Dis_tance(a);
}

void Dis_tance(int a[][x])
{
	cout << "Shortest-Distance between every pair of vertices \n";
	for (int u = 0; u < x; u++) 
	{
		for (int v = 0; v < x; v++) 
		{
			if (a[u][v] == Inf)
				cout << "Inf"
					<< "	 ";
			else
				cout << a[u][v] << "	 ";
		}
		cout << endl;
	}
}
int main()
{

	int V[x][x] = { { 0, 2, Inf, 1, 8 },
						{ Inf, 2, 0, Inf, 9 },
						{4, Inf, 1,  4, 5 },
						{2, Inf, 1, 0 , Inf } ,
						{5, Inf, Inf, 3, 0 }};
	Floyd_Warshall(V);
	return 0;
}


