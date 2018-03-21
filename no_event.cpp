#include "./no_event.h"
#include <iostream>

using namespace std;

/****************************************************
** Function:print_precept
** Description: Does not print anything as the
** no_event event is an empty room
** Parameters: N/A
*****************************************************/
void no_event::print_precept(){
	return;
}

/****************************************************
** Function:print_interact
** Description: prints a message for when the player
** enters an empty room
*****************************************************/
void no_event::print_interact(){
	cout << "There is nothing special about this room..." << endl;
	return;
}