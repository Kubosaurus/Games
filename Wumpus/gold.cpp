#include "./gold.h"
#include <iostream>

using namespace std;

/****************************************************
** Default constructor for Wumpus class
*****************************************************/
gold::gold(){
	pickup = false;
}

/****************************************************
** Function:set_pickup
** Description:picks up the gold when the player enters
** the room with gold - sets the pickup variable to the
** passed boolean
** Parameters: a boolean
** Pre-Conditions: gold is not picked up
** Post-Conditions: gold is picked up
*****************************************************/
void gold::set_pickup(bool pickup){
	this->pickup = pickup;
	return;
}

/****************************************************
** Function: get_pickup
** Description: returns the boolean value stored in
** pickup variable
** Parameters:N/A
*****************************************************/
bool gold::get_pickup(){
	return pickup;
}

/****************************************************
** Function:print_precept
** Description: prints the precept message when player
** is near a room with the wumpus' tresaure
** Parameters: N/A
*****************************************************/
void gold::print_precept(){
	if(pickup == false){
		cout << "You see a glimmer nearby." << endl;
	}
	else{return;}
	return;
}

/****************************************************
** Function:print_interact
** Description: prints a message for when the player
** enters a room with the wumpus' treasure
*****************************************************/
void gold::print_interact(){
	if(pickup == false){
		cout << "You enter a room filled with splendid piles of gold!" << endl;
		cout << "You quickly grab as much gold that can fill your pockets and bags!" << endl;
	}
	else{return;}
	return;
}
