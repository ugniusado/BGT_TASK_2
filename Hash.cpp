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
	std::string Transactions[100];
	struct transaction
	{
		std::string transactionID;
		std::string sender;
		std::string receiver;
		double sum;
	};
	transaction Y;
};
struct BS
{
	std::string Hash;
	std::string Transactions[100];
};
string MerkleT(BlockChain RandomTransactions[])
{
	ofstream fout("IDS.txt");
	for (int i = 0; i < 100; i++)
	{
		fout << RandomTransactions[i].Y.transactionID << endl;
	}
	ifstream fin("IDS.txt");
	std::string Merkel;
	std::string MerkelTemp;
	for (int i = 0; i < 10; i++)//100
	{
		fin >> MerkelTemp;
		Merkel += MerkelTemp;
	}
	MerkelTemp = Merkel;
	Merkel = Hash(MerkelTemp);
	return Merkel;
}
void RT(BlockChain RandomTransactions[], BlockChain X[])
{
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
		RandomTransactions[i].Version = "v" + to_string(i + 1) + ".0";
		RandomTransactions[i].Nonce = rand() % 1000000;
		RandomTransactions[i].Diff_Target = 0;
	}
}
void usr(user A[])
{
	for (auto i = 0; i < 1000; i++)
	{
		A[i].name = "Name" + to_string(i);
		A[i].balance = rand() % 1000000 + 100;
		A[i].public_key = Hash(A[i].name);
	}
}
void BC(BlockChain X[], user A[])
{
	for (int i = 0; i < 1000; i++)
	{
		X[i].Y.receiver =Hash(A[rand() % 1000].name);
		X[i].Y.sender = Hash( A[rand() % 1000].name);
		X[i].Y.sum = rand() % 1000000;
		X[i].Y.transactionID = Hash(X[i].Y.receiver + X[i].Y.sender + to_string(X[i].Y.sum));
	}
}
int main()
{
	int  size = 1000, j = 0;
	int characters = 0, blocks= 0;
	user A[1000];
	usr(A);
	BlockChain X[1000];
	BC(X, A);
	BlockChain RandomTransactions[100];
	RT(RandomTransactions, X);
	string Merkel = MerkleT(RandomTransactions);
	for (int i = 0; i < 100; i++)
	RandomTransactions[i].MerkelRoot = Merkel;
	BS bls[100];
	ofstream fout("o.txt");
	while (size > 100)
		
	{
		for (int i = 0; i < 100; i++)
		{
			int send = 0, get = 0;
			for (int j = 0; j < size; j++)
				if (X[j].Y.transactionID == X[blocks].Transactions[i])
					break;
			for (int k = 0; k < 1000; k++)
			{
				if (A[k].public_key == (X[j].Y.sender))
					send = k;
				else if (A[k].public_key == X[j].Y.receiver)
					get = k;
				if (send != 0 && get != 0)
					break;
			}
			A[send].balance -= X[j].Y.sum;
			A[get].balance += X[j].Y.sum;
			for (int m = j; m < (size - 1); m++)
			{
				X[m].Y.transactionID = X[m + 1].Y.transactionID;
				X[m].Y.sender = X[m + 1].Y.sender;
				X[m].Y.receiver = X[m + 1].Y.receiver;
				X[m].Y.sum = X[m + 1].Y.sum;
			}
			size--;
		}
		for (int i = 0; i < 100; i++)
			bls[i].Transactions[characters] = X[i].Transactions[blocks];

		fout << bls[characters].Hash << endl;
		characters++;
	}
	return 0;
}
	





	

