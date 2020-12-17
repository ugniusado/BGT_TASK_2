# BGT_TASK_2

Centralizuota bloku grandinė

## Įdiegimo ir naudojimosi instrukcija
• Parsisiuskite vieną iš releas'ų [Releas'ai](https://github.com/ugniusado/Obj-Task2/releases) 

• *įsidiegti C++ kompiliatorių*

• *terminale, įvesti programos vieta diske*

• *Kompiliuoti jūsų programą*

• *Visos kitos instrukcijos bus rodomos konsolėje*

## Programos versijos 

**[v0.12](https://github.com/ugniusado/BGT_TASK_2/tree/v0.12)**

Šioje programos versijoje, nepilnai išbaigta hashavimo funkcija skaito ir veda duomenis tik į failą.

**[v0.13](https://github.com/ugniusado/BGT_TASK_2/tree/v0.13)**

Šioje programoje sutvarkytas Hash'inimo būdas, kad efektyviau veiktų programa. Bei sutvarkyta Merklee Tree funkcija.

**[v0.14](https://github.com/ugniusado/BGT_TASK_2/tree/v0.14)**

Šioje programoje pilnai sutvarkyta v1.0 versija, funkcionuoja su transakcijomis.

**[v0.21](https://github.com/ugniusado/BGT_TASK_2/tree/v0.21)**

Pridėtas balanso ir hasho tikrinimas

**[v0.22](https://github.com/ugniusado/BGT_TASK_2/tree/v0.22)**

Sutvarkyti string iteratoriu error'ai ir spausdinama iskasto bloko hash

**[v0.32](https://github.com/ugniusado/BGT_TASK_2/tree/v0.32)**

Sutvarkyta merklehash() funkcijos error'ai ir hashai spausdinami tiek į failą, tiek į ekraną.

## Naudotos struktūros(blokai)

### struct user{
	std::string name;
	std::string public_key;
	double balance;
};
### struct BlockChain {
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
### struct BS {
	std::string Hash;
	std::string Transactions[100];
};
### struct BS create_merkle{
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
## Kaip veikia programa?

•Sugeneruojama 1000 vartotojų(user'ių) 

•Sugeneruojama 1000 transakcijų(transactions)

•Suskaičiuojamas random 100 parinktų blokų transakcijų Merkle Tree, paprastuoju būdu.

•Išmininamas naujas hashas, kuris atititinka reikalavimus

•Naujame bloke įvykdomos transakcijos

•Naujame bloke eliminuojamos įvykdytos transakcijos

•Vėliau proceso metu prie blockchain sistemos includ'inamas naujai iškastas block'as


