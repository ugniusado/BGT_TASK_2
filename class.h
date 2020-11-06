#pragma once

class code
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
};