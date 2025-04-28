#ifndef _BATTLEGROUND_H_
#define _BATTLEGROUND_H_
//#include "Living.h"
#include <iostream>

using namespace std;

//Every grid has an array of heroes and and array of monsters (array of classes)
//Based on that fact , all of these living creatures will join the battleground for a fight
//Every battle happens when the group of heroes arrive at each grid   
//Note1:There must be a check if the grid is valid so as to know if we are able to have a fight 
//Note2:Heroes are equipped before the fight and they can improve their equipment aftr the fight 


//A everything

class Battleground {
private:
	Hero* heroes;
	Monster* monsters;
	Grid_Square *gridsquare;
	int iterh;
	int iterm;
	int _rounds;	// How many rounds have you played?
	int hp_regeneration;

public:
	// Constructors and destructor 
	Battleground(Hero *hero_arr,Monster *monster_arr,Grid_Square *gridsquare);
	~Battleground();

	// Get functions 
	int get_round() const;
	void print_stats();
	void round_loop(); 
};

#endif