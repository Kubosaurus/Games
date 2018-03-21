#ifndef WUMPUS_H
#define WUMPUS_H
#include "./event.h"

class wumpus : public event{
	private:
		bool is_dead;
		
	public:
		wumpus();
		void set_is_dead(bool);
		bool get_is_dead();
		void print_precept();
		void print_interact();;
		
};
#endif /*WUMPUS_H*/