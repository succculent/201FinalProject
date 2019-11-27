#include <iostream>
#include <string>
#include <vector>

#include <typeinfo>

#include <cpr/cpr.h> //cpr is a REST API for C++
#include <nlohmann/json.hpp>
#include <uint256.h>

using json = nlohmann::json;
using namespace std;
int main(int argc, char** argv) {
	// SETUP
	//set difficulty
	double difficulty = stod(cpr::Get(cpr::Url{"https://blockchain.info/q/getdifficulty"},
							   cpr::VerifySsl(false)).text);
	//std::cout << "difficulty: " << difficulty;
	//set max nonce
	unsigned long long int nonce = 0;
	// retrieve latest block
	auto latest = cpr::Get(cpr::Url{"https://blockchain.info/latestblock"},
		                   //cpr::Header{{"Access-Control-Allow-Origin", "*"}},
		                   //cpr::Parameters{{"cors", "true"}},
		                   //cpr::Authentication{"bitcoinrpc", "232fb3276bbb7437d265298ea48bdc46"},
		                   cpr::VerifySsl(false)	
		                   );
	//std::cout << "BEEP BOOP\n";
	//std::cout << "status code is " << latest.status_code << " and text is \n" << latest.text << "\n";
	//compute merkle root from transactions once transactions are full
	auto latest_text = latest.text;
	//cout << typeid(latest_text).name();
	json latest_json = json::parse(latest_text);
	//cout << "boop boop, json should be parsed now \n\n";
	//cout << "and hopefully, transactions should be " << latest_json["txIndexes"];
	//json transactions_json = latest_json["txIndexes"];
	vector<uint256_t> transactions = transactions_json.get(vector<uint256_t>);
	//***

	//***




	//mining 
	// **assume nonce and merkle root already set**
	//loop nonce increments/randomizes
	int counter;
	for (counter = 0; counter < 50; ++counter) {
		srand(nonce);
		nonce = 4294967296 * ((double)rand() / RAND_MAX);
	}
	//compute double sha256
	//check if result is a solution
}

//notifying blockchain

