#ifndef CAVE_H
#define CAVE_H
#include "room.h"

class cave{
	private:
		room** caves;
		int cave_size;
		int player_x;
		int player_y;
		int arrows;
		bool gold_status;
		bool wumpus_status;
		bool dead;
	public:
		cave();
		cave(const cave&);
		~cave();
		void operator=(const cave&);
		void create_caves();
		void set_rooms();
		void set_cave_size(int);
		void set_player_x(int);
		void set_player_y(int);
		void set_arrows(int);
		void set_gold_status(bool);
		void set_wumpus_status(bool);
		void set_dead(bool);
		room** get_caves();
		int get_cave_size();
		int get_player_x();
		int get_player_y();
		int get_arrows();
		bool get_gold_status();
		bool get_wumpus_status();
		bool get_dead();
		void user_choice();
		void move_player();
		void shoot_arrow();
		void check_adj();
		void check_room();
		bool check_start();
		void bat_move();
		void arrow_check();
		void print_caves();
		void move_wumpus();
		void delete_wumpus();
		
};
#endif /*CAVE_H*/