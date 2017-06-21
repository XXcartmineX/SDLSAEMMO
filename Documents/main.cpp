/*
 * main.cpp
 *
 *  Created on: May 24, 2017
 *      Author: komo97
 */
#include <unistd.h>
#include "Header files/Server.h"

int main(){

	Server::getInstance()->App();
	Server::DestroyServer();
	return 0;
}
