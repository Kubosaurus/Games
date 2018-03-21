#include "./wumpus.h"
#include <iostream>

using namespace std;

/****************************************************
** Default constructor for Wumpus class
*****************************************************/
wumpus::wumpus(){
	is_dead = false;
}

/****************************************************
** Function:set_is_dead
** Description: sets the wumpus' status as dead
** when the player kills it - the is_dead variable
** is set to the passed boolean
** Parameters: a boolean
** Pre-Conditions: wumpus is alive
** Post-Conditions: wumpus is dead
*****************************************************/
void wumpus::set_is_dead(bool is_dead){
	this->is_dead = is_dead;
	return;
}

/****************************************************
** Function:get_is_dead
** Description:returns the boolean value held in
** the is_dead varaiable
** Parameters: N/A
*****************************************************/
bool wumpus::get_is_dead(){
	return is_dead;
}

/****************************************************
** Function:print_precept
** Description: prints the precept message when player
** is near a room with the wumpus
** Parameters: N/A
*****************************************************/
void wumpus::print_precept(){
	if(is_dead == false){
		cout << "You smell a terrible stench." << endl;
	}
	else{return;}
	return;
}

/****************************************************
** Function:print_interact
** Description: prints a message for when the player
** enters a room with the wumpus
*****************************************************/
void wumpus::print_interact(){
	if(is_dead == false){
		cout << "You enter the room with the Wumpus." << endl;
		cout << "It awakens and attacks!" << endl;
	}
	else{return;}
	return;
}
