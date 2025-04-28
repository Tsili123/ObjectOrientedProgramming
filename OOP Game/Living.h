#ifndef LIVING_H
#define LIVING_H

#include <iostream>
#include <string.h>

using namespace std;

class Weapon;
class Armor;
class Spell;
class Monster;
class Hero;
class Item;

//LIVING BEINGS//

class Living{
    protected:
        const string Name;
        int Level;
        int healthPower;
    public:
        void set_health(int change);
        int get_health() const;
        Living(string in_name);
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
        int sizee;
        int sizes;
        Item* equipment;
        Spell* spells;
    public:
        void use(Weapon& w, Monster& m);
        void use(Spell &s, Monster& m);
        void equip(Armor& a);
        double get_armor_prot() const;
        int get_Dexterity() const;
        void set_magic_power(int change);
        Hero(string in_name,int in_magic, int in_strength, int in_dext, int in_ag);
        Spell get_spell(void)const;
        Item get_equipment(void)const;
        void add_equipement(Weapon &wp);
        void add_spell(Spell &sp);
        void show_equipment(void);
        void change_equipment(int i);
};

class Warrior: public Hero{
    public:
        Warrior(string in_name,int in_magic, int in_strength, int in_dext, int in_ag);
        Warrior(const Warrior& obj);
};

class Sorcerer: public Hero{
    public:
        Sorcerer(string in_name,int in_magic, int in_strength, int in_dext, int in_ag);
        Sorcerer(const Sorcerer& obj);
};

class Paladin: public Hero{
    Paladin(string in_name,int in_magic, int in_strength, int in_dext, int in_ag);
    Paladin(const Paladin& obj);
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
};

class Dragon: public Monster{
    public:
        Dragon(string in_name, int in_damage, int in_defense, double pos);
        Dragon(const Dragon& obj);
};

class Exoskeleton: public Monster{
    public:
        Exoskeleton(string in_name, int in_damage, int in_defense, double pos);
        Exoskeleton(const Exoskeleton& obj);
};

class Spirit: public Monster{
    public:
        Spirit(string in_name, int in_damage, int in_defense, double pos);
        Spirit(const Spirit& obj);
};

//ITEMS

class Item{
    private:
        const string Name;
        const int Price;
        const int Level_Requirement;
    public:
        int get_requirement() const;
        Item(string in_name, int in_price, int in_lev);
};

class Weapon: public Item{
    private:
        const int Damage;
        bool Two_Hands;
    public:
        int get_damage() const;
        Weapon(string in_name, int in_price, int in_lev, int dam);
        Weapon(const Weapon& obj);
};

class Armor: public Item{
    private:
        const int Damage_Reduction;
    public:
        int get_damage_red() const;
        Armor(string in_name, int in_price, int in_lev, int in_dam);
        Armor(const Armor &obj);
};

class Potion: public Item{
    private:
        bool Used;
    public:
        Potion(string in_name, int in_price, int in_lev);
        Potion(const Potion& obj);
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
        Spell(string in_Name, int in_price, int in_lev, int in_damage, int in_magic);
};

class IceSpell: public Spell{
    public:
        IceSpell(string in_Name, int in_price, int in_lev, int in_damage, int in_health);
        IceSpell(const IceSpell& obj);
};

class FireSpell: public Spell{
    public:
        FireSpell(string in_Name, int in_price, int in_lev, int in_damage, int in_health);
        FireSpell(const FireSpell& obj);
};

class LightningSpell: public Spell{
    public:
        LightningSpell(string in_Name, int in_price, int in_lev, int in_damage, int in_health);
        LightningSpell(const LightningSpell& obj);
};

#endif