void crivo()
{
	for(int i = 2; i < maxn; ++i)
	{
		if(fat[i] != 0) continue;
		
		fat[i] = i;
		for(int j = i+i; j < maxn; j += i)
		{
			if(fat[j] == 0)
				fat[j] = i;
		}
	}
}
