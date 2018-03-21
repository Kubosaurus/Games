#include "./pits.h"
#include <iostream>

using namespace std;

/****************************************************
** Function:print_precept
** Description: prints the precept message when player
** is near a room with a pit
** Parameters: N/A
*****************************************************/
void pits::print_precept(){
	cout << "You feel a breeze." << endl;
	return;
}

/****************************************************
** Function:print_interact
** Description: prints a message for when the player
** enters a room with a pit
*****************************************************/
void pits::print_interact(){
	cout << "You enter a dark room and fall into a pit!" << endl;
	cout << "There doesn't seem to be a bottom..." << endl;
	return;
}
