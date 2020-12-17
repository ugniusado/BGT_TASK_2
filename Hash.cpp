
#include <C:\Users\ugniu\source\repos\Hash\func.h>
#include <C:\Users\ugniu\source\repos\Hash\class.h>



struct user {
	std::string name;
	std::string public_key;
	double balance;
};
struct BlockChain
{
	std::string prevHash;
	int timestamp;
	std::string Version;
	std::string MerkelRoot[50];
	int Nonce;
	string Diff_Target;
	std::string Transactions[100];
};
struct transaction
{
	std::string transactionID[1000];
	std::string sender[1000];
	std::string receiver[1000];
	double sum[1000];
};
struct BS
{
	std::string Hash;
	std::string Transactions[100];
};
/*void  MerkleT(BlockChain RandomTransactions[], int blocks)
{
	int temp = 50;
	for (int i = 0; i < 100; i += 2)
		RandomTransactions[blocks].MerkelRoot[i / 2] = Hash(RandomTransactions[blocks].Transactions[i] + RandomTransactions[blocks].Transactions[i + 1]);
	while (temp != 1)
	{
		for (int i = 0; i < temp; i++)
		{
			RandomTransactions[blocks].MerkelRoot[i] = Hash(RandomTransactions[blocks].MerkelRoot[i] + RandomTransactions[blocks].MerkelRoot[i + 1]);
			for (int g = i++; g < temp - 1; g++)
			{
				RandomTransactions[blocks].MerkelRoot[g] = RandomTransactions[blocks].MerkelRoot[g + 1];

			}
			temp--;

		}
	}
}
*/
bc::hash_digest create_merkle(bc::hash_list& merkle)
{
	if (merkle.empty())
		return bc::null_hash;
	else if (merkle.size() == 1)
		return merkle[0];
	while (merkle.size() > 1)
	{
		if (merkle.size() % 2 != 0)
			merkle.push_back(merkle.back());
		assert(merkle.size() % 2 == 0);
		bc::hash_list new_merkle;
		for (auto it = merkle.begin(); it != merkle.end(); it += 2)
		{
			bc::data_chunk concat_data(bc::hash_size * 2);
			auto concat = bc::serializer<
				decltype(concat_data.begin())>(concat_data.begin());
			concat.write_hash(*it);
			concat.write_hash(*(it + 1));
			bc::hash_digest new_root = bc::bitcoin_hash(concat_data);
			new_merkle.push_back(new_root);
		}
		merkle = new_merkle;
		cout << "Current merkle hash list:" << endl;
		for (const auto& hash: merkle)
		cout << " " << bc::encode_base16(hash) << endl;
		cout << endl;
	}
	return merkle[0];
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

transaction TRS(user A[])
{
	transaction trss;
	for (int i = 0; i < 1000; i++)
	{
		trss.receiver[i] = A[rand() % 999].public_key;
		trss.sender[i] = A[rand() % 999].public_key;
		trss.sum[i] = rand() % 100;
		trss.transactionID[i] = Hash(trss.sender[i] + trss.receiver[i] + to_string(trss.sum[i]));
	}
	return trss;
}
string Miner(BlockChain RandomTransactions[], BS bls[], int blocks, int characters, int& n)
{
	int x;
	string newhash;
	if (blocks == 0)
		RandomTransactions[0].prevHash = Hash("");
	else
		RandomTransactions[blocks].prevHash = bls[characters - 1].Hash;

	RandomTransactions[blocks].timestamp = std::time(nullptr);
	RandomTransactions[blocks].Version = "v" + to_string(blocks + 1) + ".0";
	RandomTransactions[blocks].Diff_Target = "0";
	x = RandomTransactions[blocks].Diff_Target.size();
	srand((unsigned)time(0));
	for (int i = 0; i < n; i++)
	{
		RandomTransactions[blocks].Nonce = rand() % 1000000;
		newhash = Hash(RandomTransactions[blocks].Diff_Target + RandomTransactions[blocks].MerkelRoot[0] + RandomTransactions[blocks].prevHash + to_string(RandomTransactions[blocks].timestamp) + RandomTransactions[blocks].Version + to_string(RandomTransactions[blocks].Nonce));
		if (newhash.substr(1, x) == RandomTransactions[blocks].Diff_Target)
			return newhash;
	}

	return "0";
}

int main()
{
	int  size = 1000, j = 0, l, h;
	int characters = 0, blocks = 0;
	user A[1000];
	usr(A);
	BS bls[100];
	ofstream fout("o.txt");
	string line, newhash, temp;
	transaction trss;
	trss = TRS(A);
	BlockChain RandomTransactions[5];
	while (size > 100)
	{
		for (int b = 0; b < 5; b++)
		{
			l = 0;
			srand((unsigned)time(0));
			for (int i = 0; i < 100; i++)
			{
				h = rand() % (size - 1);
				for (j = 0; j < 1000; j++)
					if (trss.sender[h] == A[i].public_key)
						break;
				if (trss.sum[h] >= A[j].balance && trss.transactionID[h] == Hash(trss.sender[h] + trss.receiver[h] + to_string(trss.sum[h])))
				{
					RandomTransactions[l].Transactions[blocks] = trss.transactionID[h];
				}
				else {
					for (j = h; j < (size - 2); j++)
					{
						trss.transactionID[j] = trss.transactionID[j + 1];
						trss.receiver[j] = trss.receiver[j + 1];
						trss.sender[j] = trss.sender[j + 1];
						trss.sum[j] = trss.sum[j + 1];
					}
					i--;
					size--;

				}
			}
			//MerkleT(RandomTransactions, blocks);
		}
		int r = 10000;
		temp = "0";
		while (temp == "0")
		{
			for (int i = 0; i < 5; i++)
			{
				temp = Miner(RandomTransactions, bls, blocks, characters, r);
			}r *= 2; cout << temp << "   ";
		}
		bls[characters].Hash = temp;
		for (int i = 0; i < 100; i++)
		{
			transactions[i] = hashas(block[blcount].trans[i]);
		}
		bc::hash_list tx_hashes;
		for (int i = 0; i < 100; i++)
		{
			char chars[65];
			strcpy(chars, transactions[i].c_str());
			tx_hashes.push_back(bc::hash_literal(chars));
		}
		const bc::hash_digest merkle_root = create_merkle(tx_hashes);
		string MerkleT = bc::encode_base16(merkle_root);
		bls[characters].Has = Miner(block, blcount, blchain, chcount, MerkleT);
		for (int i = 0; i < 100; i++)
		{
			int send = 0, get = 0;
			for (int j = 0; j < size; j++)
				if (trss.transactionID[j] == RandomTransactions[blocks].Transactions[i])
					break;
			for (int k = 0; k < 1000; k++)
			{
				if (A[k].public_key == (trss.sender[j]))
					send = k;
				else if (A[k].public_key == trss.receiver[j])
					get = k;
				if (send != 0 && get != 0)
					break;
			}
			A[send].balance -= trss.sum[j];
			A[get].balance += trss.sum[j];
			for (int m = j; m < (size - 1); m++)
			{
				trss.transactionID[m] = trss.transactionID[m + 1];
				trss.sender[m] = trss.sender[m + 1];
				trss.receiver[m] = trss.receiver[m + 1];
				trss.sum[m] = trss.sum[m + 1];
			}
			size--;
		}
		for (int i = 0; i < 100; i++)
			bls[i].Transactions[characters] = RandomTransactions[blocks].Transactions[i];

		fout << bls[characters].Hash << "      ";
		characters++;
	}
	return 0;
}