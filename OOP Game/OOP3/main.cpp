
#include "Living.h"

int main(void)
{
	//Grid
	Grid G(6);
	//Heroes
	Warrior W("Ned",80,120,60,80);
	Sorcerer S("Gandalf",150,70,60,80);
	Paladin P("Rob",60,120,120,90);

	//Weapons
	Weapon Hammer("Hammer",5,0,10);
	Weapon Gun("Gun",5,0,10);
	Weapon Axe("Axe",2,0,10);

	//Potions
	Potion Pot("Hp boost",25,0);
	//Spells
	FireSpell fp("Flamethrow",0,0,20,20);

	//Monsters
	Exoskeleton Ork("Ork",100,50,20);
	Dragon Charzard("Charzard",100,40,20);
	
	//equip heroes with weapons and spells
	W.add_weapons(Hammer);
	W.add_weapons(Gun);
    W.add_spells(fp);

	//Move them somewhere on the grid
	G.move_r(W);
    G.move_r(W);
    G.move_r(W);
	//G.move_down(S);
	//G.move_l(W);
	//G.move_down(S);
    //G.move_down(S);
   	//G.move_down(S);
   	//G.move_down(S);
    //G.move_up(S);
	//Track heroes on the grid
    G.print_grd();
	//Place the monsters on the grid
	G.place_monsters(Ork,3,0);
	G.place_monsters(Charzard,3,0);
	//Place the equipment on the market
	G.customize_market_of_grid_with_items(Axe,3,0);
	//u cant use the same potion twice, so you must add multiple potions to the market if you want to use more
	// for example if you buy the same potion twice, the second time it will be used and it will have no effect
	G.customize_market_of_grid_with_items(Pot,3,0);
	//Prepare for battle!!
	G.choose_grid_for_battle(3,0);
	return 0;
}