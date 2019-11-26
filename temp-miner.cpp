#include <cpr/cpr.h> //cpr is a REST API for C++

void miner(int argc, char** argv) {
	// SETUP
	// retrieve latest block
	auto latest = cpr::Get(cpr::Url{"https://blockchain.info/latestblock"});
	print(latest);


	//set difficulty
	//set max nonce
	//retrieve block
	//compute merkle root from transactions once transactions are full

	//mining 
	// **assume nonce and merkle root already set**
	//loop nonce increments/randomizes
	//compute double sha256
	//check if result is a solution
}



//notifying blockchain

