/****************************************************
** Program Filename: Assignment 4
** Author: David Okubo
** Date: 5/24/2016
** Description: This program is a game, 'Hunt the Wumpus',
** which creates a cave system with 4 events - 2 hazards,
** a wumpus and the wumpus tresaure. The player is only
** given hints that there is an event nearby and must
** kill the wumpus and take is gold to escape.
** Input: 1 command line argument for the size of the cave
** system, choices to move or shoot, which direction, and whether
** to restart with a new cave, same cave, or quit.
** Output: event precepts, event interactions, a simple map
** of the caves, player position, number of arrows, and win or lose
** situations 
*****************************************************/
#include "./cave.h"
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

bool check_arg(char**, int);

int main(int argc, char* argv[]){
	int size, choice, num1, num2;
	bool loop1=true, loop2=true, loop3, loopr=true, restart=false, end;
	srand(time(NULL));
	while(loop1==true){
		cave c, temp;
		while(loop2==true){
			if(check_arg(argv, argc)==true){
				size = atoi(argv[1]);
				c.set_cave_size(size);
				c.create_caves();
				c.set_rooms();
				loop2=false;
				loop3 = true;
			}
			while(loopr==true){
				num1 = rand() % c.get_cave_size();
				num2 = rand() % c.get_cave_size();
				if(c.get_caves()[num1][num2].get_type() == "no_event"){
					c.get_caves()[num1][num2].set_start(true);
					c.set_player_x(num1);
					c.set_player_y(num2);
					loopr = false;
				}
				
			}
		}
		temp = c;
		while(loop3==true){
			if(restart == true){
				cave temp2 = temp;
				while(temp2.check_start()==false && temp2.get_dead()==false){
					temp2.print_caves();
					temp2.check_adj();
					temp2.user_choice();
					temp2.arrow_check();
					cout << endl;
				}
				if(temp2.get_dead()==true){
					cout << "Would  you like to 1-Restart with same cave, 2-Restart with new cave, 3-Quit" << endl;
					cin >> choice;
					if(choice == 1){
						restart = true;
					}
					if(choice == 2){
						loop2 = true;
						loop3 = false;
					}
					if(choice == 3){
						loop1 = false;
						loop3 = false;
					}
				}
			}
			else{
				while(c.check_start()==false && c.get_dead()==false){
					c.print_caves();
					c.check_adj();
					c.user_choice();
					c.arrow_check();
					cout << endl;
				}
				if(c.get_dead()==true){
					end = true;
					while(end == true){
						cout << "Would  you like to 1-Restart with same cave, 2-Restart with new cave, 3-Quit" << endl;
						cin >> choice;
						else if(choice == 1){
							restart = true;
							end = false;
						}
						else if(choice == 2){
							loop2 = true;
							loop3 = false;
							end = false;
						}
						else if(choice == 3){
							loop1 = false;
							loop3 = false;
							end = false;
						}
						else{
							cout << "Incorrect Input" << endl;
						}
					}
				}
				else{
					loop1 = false;
					loop3 = false;
				}
			}
		}
	}
	return 0;
}

/****************************************************
** Function: check_arg
** Description: checks the command line arguemnts
** Parameters: argv and argc
*****************************************************/
bool check_arg(char** input, int x){
	int num = atoi(input[1]);
	if(x < 2){
		cout << "Incorrect # of arguments provided." << endl;
		return false;
	}
	else if(x >= 1){
		if(num <= 4){
			cout << "Incorrect argument provided." << endl;
			return false;
		}
		else{return true;}
	}
}

