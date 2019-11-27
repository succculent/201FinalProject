#include <cpr/cpr.h> //cpr is a REST API for C++
#include <iostream>
#include <string>
using namespace std;
int main(int argc, char** argv) {
	// SETUP
	// retrieve latest block
	auto latest = cpr::Get(cpr::Url{"https://blockchain.info/latestblock"},
		                   cpr::Header{{"Access-Control-Allow-Origin", "*"}},
		                   cpr::Parameters{{"cors", "true"}},
		                   cpr::Authentication{"bitcoinrpc", "232fb3276bbb7437d265298ea48bdc46"},
		                   cpr::VerifySsl(false)	
		                   );
	std::cout << "BEEP BOOP\n";
	std::cout << "status code is " << latest.status_code << " and text is \n" << latest.text << "\n";
	//set difficulty
	double difficulty = stod(cpr::Get(cpr::Url{"https://blockchain.info/q/getdifficulty"},
							   cpr::VerifySsl(false)).text);
	std::cout << "difficulty: " << difficulty;
	//set max nonce
	unsigned long long int nonce = 0;
	//compute merkle root from transactions once transactions are full

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

