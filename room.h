#ifndef ROOM_H
#define ROOM_H
#include "./event.h"
#include "./no_event.h"
#include "./wumpus.h"
#include "./bats.h"
#include "./pits.h"
#include "./gold.h"

#include <string>

using std::string;

class room{
	private:
		event* room_type;
		string type;
		bool is_player;
		bool start;
	public:
		room();
		room(const room&);
		void operator=(const room&);
		void set_room_type(int);
		void set_type(int);
		void set_player(bool);
		void set_start(bool);
		event* get_room_type();
		string get_type();
		bool get_player();
		bool check_win();
		bool get_start();
};
#endif /*ROOM_H*/