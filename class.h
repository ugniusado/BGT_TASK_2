#pragma once

/*class code
{
public:
	code()
	{
		var.reserve(1);
		var.push_back(1);
	};

	~code() {};

	void clear()
	{
		var.clear();
	}

	void check()
	{
		int t;
		for (int i = 0; i < var.size(); i++)
		{
			t = var.at(i) / 1000000;
			if (var.at(i) > 1000000) {
				if (i + 1 == var.size())didinimas(t);
				else var.at(i + 1) = var.at(i + 1) + t;
				var.at(i) = var.at(i) % 1000000;
			}
		}
	}

	void x(int a)
	{
		int t;
		for (int i = 0; i < var.size(); i++)
		{
			var.at(i) = var.at(i) * a;

		}
		check();
	}

	void hashinimas()
	{
		int  t, i = 2;
		while (var.size() < 9)
		{
			x(i);
			i++;
		};
		for (int y = 0; y < 5; y++)
		{
			x(i);
			i++;
		};
		for (int i = 0; i < var.size(); i++)
		{
			t = var.at(i) % 1000;
			var.at(i) = var.at(i) / 1000;
			if (i != 0) var.at(i - 1) = var.at(i - 1) + (t * 1000);
		};
		var.erase(var.begin());
	}

	string GetHex()
	{

		std::string hex = "";
		int  r;
		char ati[] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
		while (var.at(0) > 0)
		{
			r = var.at(0) % 16;
			hex = ati[r] + hex;
			for (int i = 0; i < var.size(); i++)
			{
				if (i != 0) var.at(i - 1) = var.at(i - 1) + ((var.at(i) % 16) * 1000000);
				var.at(i) = var.at(i) / 16;
			}
		}
		return hex;
	};

private:
	std::vector<int> var;

	inline void didinimas(int a)
	{
		var.push_back(a);
	};
};*/
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
	char cr ='D' ;
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

			hash.replace(hash.begin() + z, hash.begin() + z + pack.length(), pack);
			z += pack.length();

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

