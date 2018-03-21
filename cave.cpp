#include "cave.h"
#include <iostream>
#include <cstdlib>

using namespace std;

/****************************************************
** Default constructor
*****************************************************/
cave::cave(){
	cave_size = 0;
	player_x=0;
	player_y=0;
	arrows = 3;
	gold_status=false;
	wumpus_status=false;
	dead = false;
}

/****************************************************
** Copy Constructor
*****************************************************/
cave::cave(const cave &other){
	caves = new room*[other.cave_size];
	for(int i=0;i<other.cave_size;i++){
		caves[i] = new room[other.cave_size];
		for(int j=0;j<other.cave_size;j++){
			this->caves[i][j] = other.caves[i][j];
		}
	}
	this->cave_size = other.cave_size;
	this->player_x = other.player_x;
	this->player_y = other.player_y;
	this->arrows = other.arrows;
	this->gold_status = other.gold_status;
	this->wumpus_status = other.wumpus_status;
	this->dead = other.dead;
}

/****************************************************
** Deconstructor
*****************************************************/
cave::~cave(){
	for(int i=0;i<cave_size;i++){
		delete [] caves[i];
	}
	delete [] caves;
}

/****************************************************
** operator= overload
*****************************************************/
void cave::operator=(const cave &other){
	/*for(int i=0;i<cave_size;i++){
		delete [] caves[i];
	}
	delete [] caves;*/
	caves = new room*[other.cave_size];
	for(int i=0;i<other.cave_size;i++){
		caves[i] = new room[other.cave_size];
		for(int j=0;j<other.cave_size;j++){
			this->caves[i][j] = other.caves[i][j];
		}
	}
	this->cave_size = other.cave_size;
	this->player_x = other.player_x;
	this->player_y = other.player_y;
	this->arrows = other.arrows;
	this->gold_status = other.gold_status;
	this->wumpus_status = other.wumpus_status;
	this->dead = other.dead;
}

/****************************************************
** Function: create_caves
** Description: creates the cave system based on cave_size
** Parameters: N/A
*****************************************************/
void cave::create_caves(){
	caves = new room*[cave_size];
	for(int i=0;i<cave_size;i++){
		caves[i] = new room[cave_size];
	}
	return;
}

/****************************************************
** Function: set_rooms
** Description: sets up each of the rooms in the caves
** Parameters: N/A
*****************************************************/
void cave::set_rooms(){
	bool loop=true;
	int num1, num2, i=0;
	srand(time(NULL));
	while(loop==true){
		num1 = rand() % cave_size;
		num2 = rand() % cave_size;
		if(caves[num1][num2].get_type() == "no_event" && i==0 && caves[num1][num2].get_start()==false){
			caves[num1][num2].set_room_type(3);
			i++;
		}
		else if(caves[num1][num2].get_type() == "no_event" && i==1 && caves[num1][num2].get_start()==false){
			caves[num1][num2].set_room_type(0);
			i++;
		}
		else if(caves[num1][num2].get_type() == "no_event" && i>1 && i<4 && caves[num1][num2].get_start()==false){
			caves[num1][num2].set_room_type(1);
			i++;
		}
		else if(caves[num1][num2].get_type() == "no_event" && i>3 && i<6 && caves[num1][num2].get_start()==false){
			caves[num1][num2].set_room_type(2);
			i++;
		}
		else if(i==6){
			loop=false;
		}
		
	}
	return;
}

/****************************************************
** Function: set_cave_size
** Description: sets the cave_size integer varaible
** Parameters: integer
*****************************************************/
void cave::set_cave_size(int cave_size){
	this->cave_size = cave_size;
}

/****************************************************
** Function: set_player_x
** Description: sets the player_x integer variable
** Parameters: integer
*****************************************************/
void cave::set_player_x(int player_x){
	this->player_x = player_x;
	return;
}

/****************************************************
** Function: set_player_y
** Description: sets the player_y integer variable
** Parameters: integer
*****************************************************/
void cave::set_player_y(int player_y){
	this->player_y = player_y;
	return;
}

/****************************************************
** Function: set_arrows
** Description: sets the arrows integer variable
** Parameters: integer
*****************************************************/
void cave::set_arrows(int arrows){
	this->arrows = arrows;
	return;
}

/****************************************************
** Function: set_gold_status
** Description: sets the gold_status boolean variable
** Parameters: boolean
*****************************************************/
void cave::set_gold_status(bool gold_status){
	this->gold_status = gold_status;
	return;
}

/****************************************************
** Function: set_wumpus_status
** Description: sets the wumpus_status boolean variable
** Parameters: boolean
*****************************************************/
void cave::set_wumpus_status(bool wumpus_status){
	this->wumpus_status = wumpus_status;
	return;
}

/****************************************************
** Function: set_dead
** Description: sets the dead boolean variable
** Parameters: boolean
*****************************************************/
void cave::set_dead(bool dead){
	this->dead = dead;
	return;
}

/****************************************************
** Function: get_caves
** Description: returns room double pointer caves variable`
** Parameters:N/A
*****************************************************/
room** cave::get_caves(){
	return caves;
}

/****************************************************
** Function: get_cave_size
** Description: returns int cave_size variable`
** Parameters:N/A
*****************************************************/
int cave::get_cave_size(){
	return cave_size;
}

/****************************************************
** Function: get_player_x
** Description: returns int player_x variable`
** Parameters:N/A
*****************************************************/
int cave::get_player_x(){
	return player_x;
}

/****************************************************
** Function: get_player_y
** Description: returns int player_y variable`
** Parameters:N/A
*****************************************************/
int cave::get_player_y(){
	return player_y;
}

/****************************************************
** Function: get_arrows
** Description: returns int arrows variable`
** Parameters:N/A
*****************************************************/
int cave::get_arrows(){
	return arrows;
}

/****************************************************
** Function: get_gold_status
** Description: returns boolean gold_status variable
** Parameters:N/A
*****************************************************/
bool cave::get_gold_status(){
	return gold_status;
}

/****************************************************
** Function: get_wumpus_status
** Description: returns boolean gold_status variable
** Parameters:N/A
*****************************************************/
bool cave::get_wumpus_status(){
	return wumpus_status;
}

/****************************************************
** Function: get_dead
** Description: returns boolean dead variable`
** Parameters:N/A
*****************************************************/
bool cave::get_dead(){
	return dead;
}

/****************************************************
** Function: user_choice
** Description: prints choices for the user to move
** or shoot an arrow
** Parameters: N/A
*****************************************************/
void cave::user_choice(){
	int choice;
	cout << "You have " << arrows << " arrows left." << endl;
	cout << "Would you like to: 1-Move or 2-Shoot an arrow." << endl;
	cin >> choice;
	if(choice == 1){
		move_player();
	}
	else if(choice == 2){
		shoot_arrow();
	}
	else{
		cout << "Invalid input." << endl << endl;
	}
	return;
}

/****************************************************
** Function: move_player
** Description: changes the player_x and player_y
** variables to move the player "north" "east" "west"
** or "south"
** Parameters:N/A
*****************************************************/
void cave::move_player(){
	int move;
	cout << "Would you like to move 1-North, 2-East, 3-South, 4-West?" << endl;
	cin >> move;
	if(move == 1 && player_y > 0){
		player_y-=1;
	}
	else if(move == 2 && player_x < cave_size-1){
		player_x+=1;
	}
	else if(move == 3 && player_y < cave_size-1){
		player_y+=1;
	}
	else if(move == 4 && player_x > 0){
		player_x-=1;
	}
	else{
		cout << "You cannot move that way." << endl << endl;
	}
	check_room();
	cout << endl;
}

/****************************************************
** Function: shoot_arrow
** Description: checks the direction(specified by the user)
** for the wumpus - if there is a wumpus it dies, if there isnt
** the arrows hits a wall or falls after 3 caves
** Parameters: N/A
*****************************************************/
void cave::shoot_arrow(){
	int shoot;
	cout << "Which direction would you like to shoot: 1-North, 2-East, 3-South, 4-West?" << endl;
	cin >> shoot;
	if(shoot == 1 && player_y > 0){
		for(int i=1;i<4;i++){
			if(caves[player_x][player_y-i].get_type()=="wumpus"){
				cout << "Your arrow manages to fly into the room with the Wumpus and kills it." << endl;
				caves[player_x][player_y-i].set_room_type(4);
				wumpus_status = true;
				break;
			}
			else if(player_y-i==0){
				cout << "Your arrow hits a wall." << endl;
				move_wumpus();
				break;
			}
			else if(i==3){
				cout << "Your falls to the floor as has flown as far as it could." << endl;
				move_wumpus();
			}
			
			
		}
		arrows--;
	}
	else if(shoot == 2 && player_x < cave_size-1){
		for(int i=1;i<4;i++){
			if(caves[player_x+i][player_y].get_type()=="wumpus"){
				cout << "Your arrow manages to fly into the room with the Wumpus and kills it." << endl;
				caves[player_x+i][player_y].set_room_type(4);
				wumpus_status = true;
				break;
			}
			else if(player_x+i==cave_size-1){
				cout << "Your arrow hits a wall." << endl;
				move_wumpus();
				break;
			}
			else if(i==3){
				cout << "Your falls to the floor as has flown as far as it could." << endl;
				move_wumpus();
			}
			
			
		}
		arrows--;
	}
	else if(shoot == 3 && player_y < cave_size-1){
		for(int i=1;i<4;i++){
			if(caves[player_x][player_y+i].get_type()=="wumpus"){
				cout << "Your arrow manages to fly into the room with the Wumpus and kills it." << endl;
				caves[player_x][player_y+i].set_room_type(4);
				wumpus_status = true;
				break;
			}
			
			else if(player_y+i==cave_size-1){
				cout << "Your arrow hits a wall." << endl;
				move_wumpus();
				break;
			}
			else if(i==3){
				cout << "Your falls to the floor as has flown as far as it could." << endl;
				move_wumpus();
			}
			
		}
		arrows--;
	}
	else if(shoot == 4 && player_x > 0){
		for(int i=1;i<4;i++){
			if(caves[player_x-i][player_y].get_type()=="wumpus"){
				cout << "Your arrow manages to fly into the room with the Wumpus and kills it." << endl;
				caves[player_x-i][player_y].set_room_type(4);
				wumpus_status = true;
				break;
			}
			else if(player_x-i==0){
				cout << "Your arrow hits a wall." << endl;
				move_wumpus();
				break;
			}
			else if(i==3){
				cout << "Your falls to the floor as has flown as far as it could." << endl;
				move_wumpus();
			}
			
			
		}
		arrows--;
	}
	else{
		cout << "You cannot shoot in that direction." << endl << endl;
	}
	return;
}

/****************************************************
** Function: check_adj
** Description: checks adjecent rooms to the player
** for events and prints respective precepts
** Parameters:N/A
*****************************************************/
void cave::check_adj(){
	if(player_y > 0 && player_y < cave_size-1){
		caves[player_x][player_y+1].get_room_type()->print_precept();
	}
	if(player_x < cave_size-1 && player_x >0){
		caves[player_x+1][player_y].get_room_type()->print_precept();
	}
	if(player_y < cave_size-1 && player_y >0){
		caves[player_x][player_y-1].get_room_type()->print_precept();
	}
	if(player_x > 0 && player_x < cave_size-1){
		caves[player_x-1][player_y].get_room_type()->print_precept();
	}
	return;
}

/****************************************************
** Function: check_room
** Description: checks the room the player is in for
** events and prints the respectie interaction strings
** Parameters:N/A
*****************************************************/
void cave::check_room(){
	caves[player_x][player_y].get_room_type()->print_interact();
	if(caves[player_x][player_y].get_type() == "wumpus"){
		cout << "Oh no you died." << endl;
		dead = true;
	}
	if(caves[player_x][player_y].get_type() == "gold"){
		gold_status = true;
		caves[player_x][player_y].set_room_type(4);
	}
	if(caves[player_x][player_y].get_type() == "bats"){
		bat_move();
	}
	if(caves[player_x][player_y].get_type() == "pits"){
		cout << "Oh no you died." << endl;
		dead = true;
	}
	if(caves[player_x][player_y].get_start()==true){
		cout << "The escape rope is in this room." << endl;
	}
	return;
}

/****************************************************
** Function: check_start
** Description: checks if the player is in the room with
** the exit and if they have the gold and killed the wumpus
** if any of the requirements are not met, they are told they
** cannot leave yet
** Parameters:N/A
*****************************************************/
bool cave::check_start(){
	if(caves[player_x][player_y].get_start()==true && wumpus_status == true && gold_status == true){
		cout << "You have killed the wumpus and found its treasure and managed to find the escape rope!" << endl;
		cout << "Congradulations you win!" << endl;
		return true;
	}
	if(caves[player_x][player_y].get_start()==true && wumpus_status == true && gold_status == false){
		cout << "You have killed the wumpus but have no yet found its treasure, you cannot leave yet." << endl;
		return false;
	}
	if(caves[player_x][player_y].get_start()==true && wumpus_status == false && gold_status == true){
		cout << "You have found the wumpus' treasure but you have not yet killed it, you cannot leave yet." << endl;
		return false;
	}
	if(caves[player_x][player_y].get_start()==true && wumpus_status == false && gold_status == false){
		cout << "You have not killed the wumpus or found its treasure, there is still much to do, you cannot leave yet." << endl;
		return false;
	}
}

/****************************************************
** Function: bat_move
** Description: moves the player to a random empty cave
** room when the player enters a room filled with bats
** Parameters: N/A
*****************************************************/
void cave::bat_move(){
	bool loop=true;
	int num1, num2;
	srand(time(NULL));
	while(loop==true){
		num1 = rand() % cave_size;
		num2 = rand() % cave_size;
		if(caves[num1][num2].get_type() == "no_event"){
			player_x=num1;
			player_y=num2;
			loop = false;
		}	
	}
	return;
}

/****************************************************
** Function: arrow_check
** Description: checks the number of arrows the player has
** if 0 and the wumpus is alive, the player loses
** Parameters: N/A
*****************************************************/
void cave::arrow_check(){
	if(arrows == 0 && wumpus_status == false){
		cout << "You've run out of arrows and are going to die." << endl;
		dead = true;
	}
	if(arrows == 0 && wumpus_status == true){
		cout << "You've run out of arrows, luckily the wumpus is dead already." << endl;
	}
	return;
}

/****************************************************
** Function: print_caves
** Description: prints the simple map of the caves as "[]"
** and the current player location with "[J]"
** with debugging, the locations of the events are printing
** Parameters: N/A
*****************************************************/
void cave::print_caves(){
	for(int i=0;i<cave_size;i++){
		for(int j=0;j<cave_size;j++){
			if(j==player_x && i==player_y){
				cout << "[J]";
			}
			#ifdef DEBUG
			else if(caves[j][i].get_type() == "gold"){ //debugging
				cout << "[G]";
			}
			else if(caves[j][i].get_type() == "wumpus"){ //debugging
				cout << "[W]";
			}
			else if(caves[j][i].get_type() == "bats"){ //debugging
				cout << "[B]";
			}
			else if(caves[j][i].get_type() == "pits"){ //debugging
				cout << "[P]";
			} 
			#endif
			else{
				cout << "[ ]";
			}
		}
		cout << endl;
	}
	return;
}

/****************************************************
** Function: move_wumpus
** Description: the wumpus has an 75% chance of moving
** when an arrow is shot and misses it
** Parameters: N/A
*****************************************************/
void cave::move_wumpus(){
	bool loop=true;
	int num1, num2, num3;
	srand(time(NULL));
	num1 = rand() % 4+1;
	if(num1 < 4){
		while(loop==true){
			num2 = rand() % cave_size;
			num3 = rand() % cave_size;
			if(caves[num2][num3].get_type() == "no_event" && caves[num2][num3].get_start()==false){
				delete_wumpus();
				caves[num2][num3].set_room_type(0);
				loop = false;
			}
		}
	}
	return;
}

/****************************************************
** Function: delete_wumpus
** Description: removes the current wumpus event before
** putting a new one in a random location
** Parameters: N/A
*****************************************************/
void cave::delete_wumpus(){
	for(int i=0;i<cave_size;i++){
		for(int j=0;j<cave_size;j++){
			if(caves[j][i].get_type() == "wumpus"){
				caves[j][i].set_room_type(4);
			}
		}
	}
	return;
}