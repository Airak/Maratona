#include <bits/stdc++.h>
#define maxn 5000020

using namespace std;

ll fat[maxn];

void crivo()
{
	for(int i = 2; i < maxn; ++i)
	{
		if(fat[i] != 0) continue;
		
		fat[i] = 1;
		primos.push_back(i);
		for(int j = i+i; j < maxn; j += i)
		{
			int aux = j;
			while(aux%i == 0)
			{
				fat[j]++;
				aux /= i;
			}
		}
	}
	
	for(int i = 2; i < maxn; ++i)
	{
		fat[i] += fat[i-1];
	}
}

int main()
{
	crivo();
	int t, a, b;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &a, &b);
		printf("%lld\n", fat[a]-fat[b]);
	}
}
