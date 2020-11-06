#include <C:\Users\USER\source\repos\Hash\func.h>
#include <C:\Users\USER\source\repos\Hash\class.h>

vector<string> read()
{
	string pav;
	vector<string> line;
	cout << "Text file name : ";
	cin >> pav;
	pav = pav + ".txt";
	ifstream fin(pav);
	if (fin)
	{
		while (!fin.eof())
		{
			getline(fin, pav);
	
			line.push_back(pav);
		}
		fin.close();
	}
	else
	{
		cout << "error" << endl;
		line = read();
	}
	return line;
}
void print(vector<string> hex)
{
	ofstream fout("Hash.txt");
	for (int i = 0; i < hex.size(); i++)
	{
		fout << hex.at(i) << endl;
	}
}
vector<string> GetString()
{
	vector<string> line;
	line = read();
	return line;

}
vector<string> Hash(vector<string> eilutes)
{
	vector<int> skaiciai;
	vector<string> hex;
	int a;
	for (int i = 0; i < eilutes.size(); i++)
	{
		code l;
		for (int o = 0; o < eilutes.at(i).size(); o++)
		{
			a = int(eilutes.at(i).at(o));
			l.x(a + o);
		}
		l.hashinimas();
		hex.push_back(l.GetHex());
		l.clear();
	}
	return hex;
}
int main()
{
	vector<string> eilute = GetString();
	auto begin = chrono::high_resolution_clock::now();
	vector<string> hex = Hash(eilute);
	auto end = chrono::high_resolution_clock::now();
	cout << "Hash time " << chrono::duration_cast<chrono::nanoseconds>(end - begin).count() << " nanosek" << endl;
	print(hex);

}
