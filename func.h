#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <math.h>
#include <chrono>
#include <ctime>
#include <streambuf>
#include <stdlib.h>
#include <cstdlib>
#include <bitcoin/bitcoin.hpp>
using namespace std;


vector<string> read();
void print(vector<string> hex);
vector<string> GetString();
string Hash(string line);
char GetChar(int r1, char r11);
//string Miner(BlockChain RandomTransactions[], BS bls[], int blocks, int characters, int& n);
//void  MerkleT(BlockChain RandomTransactions[], int blocks);
