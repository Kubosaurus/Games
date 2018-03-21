#include "./bats.h"
#include <iostream>

using namespace std;

/****************************************************
** Function:print_precept
** Description: prints the precept message when player
** is near a room with bats
** Parameters: N/A
*****************************************************/
void bats::print_precept(){
	cout << "You hear the wings flapping." << endl;
	return;
}

/****************************************************
** Function:print_interact
** Description: prints a message for when the player
** enters a room with bats
*****************************************************/
void bats::print_interact(){
	cout << "You enter a room filled with super bats!" << endl;
	cout << "They grab you and carry you to another room..." << endl;
	return;
}
