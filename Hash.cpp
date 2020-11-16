#include <C:\Users\ugniu\source\repos\Hash\func.h>
#include <C:\Users\ugniu\source\repos\Hash\class.h>
struct user{
	std::string name;
	std::string public_key;
	double balance;
};
struct BlockChain
{
	std::string prevHash;
	int timestamp;
	std::string Version;
	std::string MerkelRoot;
	int Nonce;
	int Diff_Target;
	struct transaction
	{
		std::string transactionID;
		std::string sender;
		std::string receiver;
		double sum;
	};
	transaction Y;
};
vector<string> read()
{
	string pav;
	vector<string> line;
	ifstream fin("Name.txt");
	if (fin)
	{
		while (!fin.eof())
		{
			getline(fin, pav);

			line.push_back(pav);
		}
		fin.close();
	}
	return line;
}
vector<string> readT()
{
	string pav;
	vector<string> line;
	ifstream fin("TransactionHash.txt");
	if (fin)
	{
		while (!fin.eof())
		{
			getline(fin, pav);

			line.push_back(pav);
		}
		fin.close();
	}
	return line;
}
vector<string> readM()
{
	string pav;
	vector<string> line;
	ifstream fin("RNTHash.txt");
	if (fin)
	{
		while (!fin.eof())
		{
			getline(fin, pav);

			line.push_back(pav);
		}
		fin.close();
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
void printTransaction(vector<string> hex)
{
	ofstream fout("TransactionId.txt");
	for (int i = 0; i < hex.size(); i++)
	{
		fout << hex.at(i) << endl;
	}
}
void printMH(vector<string> hex)
{
	ofstream fout("MerkelHash.txt");
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
vector<string> GetStringT()
{
	vector<string> line;
	line = readT();
	return line;

}
vector<string> GetStringM()
{
	vector<string> line;
	line = readM();
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
	user A[1000];
	for (auto i = 0; i < 1000; i++)
	{
		A[i].name = "Name" + to_string(i);
		A[i].balance = rand() % 1000000 + 100;
	}
	ofstream fout("Name.txt");
	for (int i = 0; i < 1000; i++)
	{
		fout << A[i].name << endl;
	}
	vector<string> eilute = GetString();
	vector<string> hex = Hash(eilute);
	print(hex);
	ifstream fin("Hash.txt");
	for (auto i = 0; i < 1000; i++)
	{
		fin >> A[i].public_key;
	}
	
	for(int i = 0; i < 10; i ++)
	{
		cout << A[i].balance << endl;
		cout << A[i].name << endl;
		cout << A[i].public_key << endl;
	}

	
	BlockChain X[1000];
	for (int i = 0; i < 1000; i++)
	{
		X[i].Y.receiver = A[rand() % 1000].name;
		X[i].Y.sender = A[rand() % 1000].name;
		X[i].Y.sum = rand() %1000000;

	}
	ofstream fout1("TransactionHash.txt");
	for (int i = 0; i < 1000; i++)
	{
		fout1 << X[i].Y.receiver << X[i].Y.sum << X[i].Y.sender << endl;
	}

	eilute = GetStringT();
	hex = Hash(eilute);
	printTransaction(hex);
	ifstream fin1("TransactionId.txt");
	for (int i = 0; i < 1000; i++)
	{
		std::string temp;
		fin1 >> temp;
		X[i].Y.transactionID = temp;	
	}
	BlockChain RandomTransactions[100];
	for (int i = 0; i < 100; i++)
	{
		RandomTransactions[i] = X[rand() % 1000];
	}
	for (int i = 1; i < 100; i++)
	{
		RandomTransactions[i].prevHash = RandomTransactions[i - 1].prevHash;		
	}
	for (int i = 0; i < 100; i++)
	{
		RandomTransactions[i].timestamp = std::time(nullptr);
		RandomTransactions[i].Version = "v" + to_string(i+1) + ".0";
	}
	ofstream fout2("RNTHash.txt");
	for (int i = 0; i < 100; i++)
	{
		fout2 << RandomTransactions[i].Y.transactionID<< endl;
	}
	eilute = GetStringM();
	hex = Hash(eilute);
	printMH(hex);
	ifstream fin2("MerkelHash.txt");
		std::string MerkelTemp;
		fin2 >> MerkelTemp;
	for (int i = 0; i < 100; i++)
	{
		RandomTransactions[i].MerkelRoot = MerkelTemp;
	}



	
}
