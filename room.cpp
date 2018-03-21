#include "./room.h"

/****************************************************
** Non-Default constructor
*****************************************************/
room::room(){
	room_type = new no_event;
	type = "no_event";
	is_player = false;
	start = false;
}

/****************************************************
** Copy Constructor
*****************************************************/
room::room(const room &other){
	this->room_type = other.room_type;
	this->type = other.type;
	this->is_player = other.is_player;
	this->start = other.start;
}

/****************************************************
** operator= overload
*****************************************************/
void room::operator=(const room &other){
	this->room_type = other.room_type;
	this->type = other.type;
	this->is_player = other.is_player;
	this->start = other.start;
}

/****************************************************
** Function: set_room_type
** Description: sets the type of event that is going
** to be in the room (bat, wumpus, gold, or pit)
** Parameters: integer
*****************************************************/
void room::set_room_type(int x){
	if(x == 0){
		room_type = new wumpus();
		set_type(x);
	}
	if(x == 1){
		room_type = new bats();
		set_type(x);
	}
	if(x == 2){
		room_type = new pits();
		set_type(x);
	}
	if(x == 3){
		room_type = new gold();
		set_type(x);
	}
	if(x == 4){
		room_type = new no_event();
		set_type(x);
	}
	return;
}

/****************************************************
** Function: set_type
** Description: sets a string for identification purposes
** of events in a room
** Parameters: integer
*****************************************************/
void room::set_type(int x){
	if(x == 0){
		type = "wumpus";
	}
	if(x == 1){
		type = "bats";
	}
	if(x == 2){
		type = "pits";
	}
	if(x == 3){
		type = "gold";
	}
	if(x == 4){
		type = "no_event";
	}
	return;
}

/****************************************************
** Function: set_player
** Description: sets whether the player is currently
** in the room or not - changes is_player variable
** Parameters: boolean
*****************************************************/
void room::set_player(bool player){
	this->is_player = player;
	return;
}

/****************************************************
** Function: set_start
** Description: sets the start room or where the escape rope
** is for the current cave system
** Parameters: boolean
*****************************************************/
void room::set_start(bool start){
	this->start = start;
	return;
}

/****************************************************
** Function: get_room_type
** Description: returns event pointer room_type variable`
** Parameters:N/A
*****************************************************/
event* room::get_room_type(){
	return room_type;
}

/****************************************************
** Function: get_type
** Description: returns string type variable`
** Parameters:N/A
*****************************************************/
string room::get_type(){
	return type;
}

/****************************************************
** Function: get_player
** Description: returns boolean plsyer variable`
** Parameters:N/A
*****************************************************/
bool room::get_player(){
	return is_player;
}

/****************************************************
** Function: get_start
** Description: returns boolean start variable`
** Parameters:N/A
*****************************************************/
bool room::get_start(){
	return start;
}