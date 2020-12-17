#pragma once
#include <C:\Users\ugniu\source\repos\Hash\func.h>
char GetChar(int cs, char cr)
{
	switch (cs)
	{
	case 1: cr = 'A'; break;
	case 2: cr = 'a'; break;
	case 3: cr = 'B'; break;
	case 4: cr = 'b'; break;
	case 5: cr = 'C'; break;
	case 6: cr = 'c'; break;
	case 7: cr = 'D'; break;
	case 8: cr = 'd'; break;
	case 9: cr = 'E'; break;
	default: cr = 'F';
	}
	return cr;

}
string Hash(string line)
{
	string pack, hash;
	int lngt, shw = 0, shw2 = 0, i, y, z = 0, cs;
	char cr = 'D';
	lngt = line.length();
	shw = line[0];
	y = 1;

	for (int i = 1; i < lngt; i++)
	{
		if (y == 0)
		{
			shw -= line[i];
			y++;
		}
		else
		{
			shw += line[i];
			y--;
		}
	}
	shw = abs(shw);

	for (i = 0; i < lngt; i++)
	{
		if (hash.length() >= 32)
			break;

		else
		{
			cs = (line[i] + shw2) % 10;
			hash += to_string(line[i] + shw2) + GetChar(cs, cr);
		}
		shw2++;
	}
	int shw3 = shw;
	int shw4 = shw;
	if (i == lngt)
	{
		while (hash.length() < 32)
		{
			shw2 = abs(shw2 * 2 - shw3 * 2);
			cs = shw2 % 10;
			hash += to_string(shw2) + GetChar(cs, cr);

			shw2 += 3;
			shw3 -= 3;
		}
	}
	else
	{
		for (int x = i; x < lngt; x++)
		{
			if (shw4 > 1000)
				shw4 %= 100;

			cs = (line[x] + shw4) % 10;
			pack = to_string(line[x] + shw4) + GetChar(cs, cr);

			if (z >= 32)
				z = 0;
			auto it1 = hash.begin() + z;
			auto it2 = hash.begin() + z + 3;
			hash.replace(it1, it2, pack);

			z += 3;

			if (x % 2 == 0)
				shw4 += 3;
			else
				shw4 -= 2;
		}
	}
	while (hash.length() > 32)
		hash.pop_back();

	return hash;
}
