#ifndef GOLD_H
#define GOLD_H
#include "./event.h"

class gold : public event{
	private:
		bool pickup;
	public:
		gold();
		void set_pickup(bool);
		bool get_pickup();
		void print_precept();
		void print_interact();
};
#endif /*GOLD_H*/
