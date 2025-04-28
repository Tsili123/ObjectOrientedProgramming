#ifndef _LIVING_H_
#define _LIVING_H_
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <cstdlib>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Grid_Square;
class Grid;
class Item;
class Weapon;
class Armor;
class Spell;
class Monster;
class Grid;
class Potion;
class Living;
class Hero;
class Battleground;


//LIVING BEINGS//

class Living{
    protected:
        const string Name;
        int Level;
        int healthPower;
        int x,y;
    public:
        void set_health(int change);
        void set_health2(int i);
        void set_x_y(int x_in, int y_in);
        int get_health() const;
        int get_x() const;
        int get_y() const;
        Living(string in_name);
        ~Living();
        string get_name();
};

class Hero: public Living{
    private:
        int magicPower;
        int Strength;
        int Dexterity;
        int Agility;
        int money;
        int experience;
        double armor_protection;
        Weapon** weapons;
        Potion** potions;
        Spell** spells;
        int weap_c;
        int pot_c;
        int spell_c;
    public:
        void use(Weapon& w, Monster& m);
        void use(Spell &s, Monster& m);
        void use(Potion &pt);
        void equip(Armor& a);
        Item* buy(Grid_Square &i,int in);
        Spell* buy2(Grid_Square &i,int in);
        // void buy(Weapon& i);
        // void buy(Potion& i);
        // void buy(Spell& i);
        void sell(Weapon &i,int c); //c represents the index of the Item on the array it is stored
        void sell(Potion &i, int c);
        void sell(Spell &i, int c);
        double get_armor_prot() const;
        int get_Dexterity() const;
        void set_magic_power(int change);
        Hero(string in_name,int in_magic, int in_strength, int in_dext, int in_ag);
        Hero(const Hero& obj);
        ~Hero();
        Spell* get_spell();
        Weapon* get_weapon();
        Potion* get_potion();
        Item* get_weapons(int i);
        Spell* get_spells(int i);
        Item* get_potions(int i);
        void add_weapons(Weapon &wp);
        void add_spells(Spell &sp);
        void add_potions(Potion &pt);
        void print_equipment();
        void change_equipment(int i,int j);
        void get_rewards(int i);
};

class Warrior: public Hero{
    public:
        Warrior(string in_name,int in_magic, int in_strength, int in_dext, int in_ag);
        Warrior(const Warrior& obj);
        ~Warrior();
};

class Sorcerer: public Hero{
    public:
        Sorcerer(string in_name,int in_magic, int in_strength, int in_dext, int in_ag);
        Sorcerer(const Sorcerer& obj);
        ~Sorcerer();
};

class Paladin: public Hero{
    public:
        Paladin(string in_name,int in_magic, int in_strength, int in_dext, int in_ag);
        Paladin(const Paladin& obj);
        ~Paladin();
};

class Monster: public Living{
    private:
        int Damage;
        int Defense;
        const int possibility_of_push_back; //Presented in %, ex. 75 = 75%
    public:
        int get_push_back() const;
        int get_damage() const;
        void attack(Hero& h);
        Monster(string in_name, int in_damage, int in_defense, int pos);
        ~Monster();
};

class Dragon: public Monster{
    public:
        Dragon(string in_name, int in_damage, int in_defense, double pos);
        Dragon(const Dragon& obj);
        ~Dragon();
};

class Exoskeleton: public Monster{
    public:
        Exoskeleton(string in_name, int in_damage, int in_defense, double pos);
        Exoskeleton(const Exoskeleton& obj);
        ~Exoskeleton();
};

class Spirit: public Monster{
    public:
        Spirit(string in_name, int in_damage, int in_defense, double pos);
        Spirit(const Spirit& obj);
        ~Spirit();
};

//ITEMS

class Item{
    private:
        const string Name;
        const int Price;
        const int Level_Requirement;
    public:
        int get_requirement() const;
        int get_Price() const;
        Item(string in_name, int in_price, int in_lev);
        ~Item();
        string get_name()const;
};

class Weapon: public Item{
    private:
        const int Damage;
        bool Two_Hands;
        string name;
    public:
        int get_damage() const;
        Weapon(string in_name, int in_price, int in_lev, int dam);
        Weapon(const Weapon& obj);
        ~Weapon();
};

class Armor: public Item{
    private:
        const int Damage_Reduction;
    public:
        int get_damage_red() const;
        Armor(string in_name, int in_price, int in_lev, int in_dam);
        Armor(const Armor &obj);
        ~Armor();
};

class Potion: public Item{
    private:
        string name;
        bool Used;
        int hp_regen;
    public:
        Potion(string in_name, int in_price, int in_lev);
        Potion(const Potion& obj);
        ~Potion();
        int get_hp_regen();
        bool get_use();
        void set_use();
};

// SPELLS //

class Spell{
    private:
        const string Name;
        const int Price;
        const int Level_Requirement;
        const int Damage;
        const int magicPower_Req;

    public:
        int get_requirement() const;
        int get_magic_requirement() const;
        int get_Damage() const;
        int get_price() const;
        Spell(string in_Name, int in_price, int in_lev, int in_damage, int in_magic);
        ~Spell();
        string get_name()const;
};

class IceSpell: public Spell{
    public:
        IceSpell(string in_Name, int in_price, int in_lev, int in_damage, int in_health);
        IceSpell(const IceSpell& obj);
        ~IceSpell();
};

class FireSpell: public Spell{
    public:
        FireSpell(string in_Name, int in_price, int in_lev, int in_damage, int in_health);
        FireSpell(const FireSpell& obj);
        ~FireSpell();
};

class LightningSpell: public Spell{
    public:
        LightningSpell(string in_Name, int in_price, int in_lev, int in_damage, int in_health);
        LightningSpell(const LightningSpell& obj);
        ~LightningSpell();
};

class Grid_Square{
    private:
        int num_of_squares;
        Hero** heroes;
        Monster** monsters;
        int num_of_heroes;
        int num_of_monsters;
        bool IsMarket;
        Item **equipment;
        Spell **spells;
        int item_c;
        int spell_c;
        Battleground *bg;
    public:
        int IsAccessible(); //Returns 1 for TRUE and -1 for FALSE
        int IsAccessible2();
        int get_isMarket();
        void enter(Hero& h);
        void Market();
        Grid_Square();
        ~Grid_Square();
        //print market
        void print_market();
        //add equipment
        void add_equipment_to_market(Item &it);
        //add spell
        void add_spell_to_market(Spell &sp);
        Item* get_equipment(int i);
        Spell* get_spell(int i);
        void set_squares(int i);
        void print_grid();
        void leave(Hero& h);
        void play_battle();
        void enter(Monster& m);
};

class Grid{
    private:
        int num_of_squares;
        Grid_Square** Square;
    public:
        void move_r(Hero& g);
        void move_l(Hero& g);
        void move_up(Hero& g);
        void move_down(Hero& g);
        void print_grd();
        void Market_Squares(int N);
        void choose_grid_for_battle(int i,int j);
        void place_monsters(Monster &m,int i,int j);
        void customize_market_of_grid_with_items(Item &it,int i,int j);
        Grid(int N);
        ~Grid();
};

//Every grid has an array of heroes and and array of monsters (array of classes)
//Based on that fact , all of these living creatures will join the battleground for a fight
//Every battle happens when the group of heroes arrive at each grid   
//Note1:There must be a check if the grid is valid so as to know if we are able to have a fight 
//Note2:Heroes are equipped before the fight and they can improve their equipment aftr the fight 

class Battleground {
private:
	Hero** heroes;
	Monster** monsters;
	Grid_Square *gridsquare;
	int iterh;
	int iterm;
	int _rounds;	// How many rounds have you played?
	int hp_regeneration;

public:
	// Constructors and destructor 
	Battleground(Hero **hero_arr,Monster **monster_arr,Grid_Square *gridsquare,int num_hero,int num_monster);
	~Battleground();
    
	// Get functions 
	int get_round() const;
	void print_stats();
	void round_loop(); 
};

#endif