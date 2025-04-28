#include "Living.h"
// CONSTRUCTORS OF BEINGS//
//G everything

Living::Living(string in_name)
    :Name(in_name)
{
    cout << " A living creature has been created with name " << in_name << endl;
    Level = 1;
    healthPower = 100;
    x=0;
    y=0;
}

Hero::Hero(string in_name,int in_magic, int in_strength, int in_dext, int in_ag)
    :Living(in_name)
{
    cout << " A hero has been created " << endl;
    weapons = new Weapon*[1];
    weapons[0] = NULL;
    potions = new Potion*[1];
    potions[0] = NULL;
    spells = new Spell*[1];
    spells[0] = NULL;
    magicPower = in_magic;
    Strength = in_strength;
    Dexterity = in_dext;
    Agility = in_ag;
    money = 50;
    experience = 0;
    armor_protection = 0.8;
    weap_c = 0;
    pot_c = 0;
    spell_c=0;
}

Hero::Hero(const Hero& obj)
    :Living(obj)
{
    weapons = obj.weapons;
    potions = obj.potions;
    spells = obj.spells;
    magicPower = obj.magicPower;
    Strength = obj.Strength;
    Dexterity = obj.Dexterity;
    Agility = obj.Agility;
    money = obj.money;
    experience = obj.experience;
    armor_protection = obj.armor_protection;
    weap_c = obj.weap_c;
    pot_c = obj.pot_c;
}

Warrior::Warrior(string in_name,int in_magic, int in_strength, int in_dext, int in_ag)
    :Hero(in_name,in_magic,in_strength,in_dext,in_ag)
{
}

Warrior::Warrior(const Warrior &obj)
    :Hero(obj)
{
}

Sorcerer::Sorcerer(string in_name,int in_magic, int in_strength, int in_dext, int in_ag)
    :Hero(in_name,in_magic,in_strength,in_dext,in_ag)
{
}

Sorcerer::Sorcerer(const Sorcerer& obj)
    :Hero(obj)
{
}

Paladin::Paladin(string in_name,int in_magic, int in_strength, int in_dext, int in_ag)
    :Hero(in_name,in_magic,in_strength,in_dext,in_ag)
{
}

Paladin::Paladin(const Paladin& obj)
    :Hero(obj)
{
}

Monster::Monster(string in_name, int in_defense, int in_damage, int pos)
    :Living(in_name),Defense(in_defense),possibility_of_push_back(pos)
{   
    Damage = in_damage;
}

Dragon::Dragon(string in_name, int in_damage, int in_defense, double pos)
    :Monster(in_name,in_damage,in_defense,pos)
{
}

Dragon::Dragon(const Dragon& obj)
    :Monster(obj)
{
}

Exoskeleton::Exoskeleton(string in_name, int in_damage, int in_defense, double pos)
    :Monster(in_name,in_damage,in_defense,pos)
{
}

Exoskeleton::Exoskeleton(const Exoskeleton& obj)
    :Monster(obj)
{
}

Spirit::Spirit(string in_name, int in_damage, int in_defense, double pos)
    :Monster(in_name,in_damage,in_defense,pos)
{
}

Spirit::Spirit(const Spirit& obj)
    :Monster(obj)
{
}


// CONSTRUCTORS OF ITEMS//

Item::Item(string in_name, int in_price, int in_lev)
    :Name(in_name),Price(in_price),Level_Requirement(in_lev)
{
}

Armor::Armor(string in_name, int in_price, int in_lev, int in_dam)
    :Item(in_name,in_price,in_lev),Damage_Reduction(in_dam)
{
}

Armor::Armor(const Armor& obj)
    :Item(obj),Damage_Reduction(obj.Damage_Reduction)
{
}

Weapon::Weapon(string in_name, int in_price, int in_lev, int in_dam)
    :Item(in_name,in_price,in_lev),Damage(in_dam)
{
}

Weapon::Weapon(const Weapon& obj)
    :Item(obj),Damage(obj.Damage),Two_Hands(obj.Two_Hands)
{
}

Potion::Potion(string in_name, int in_price, int in_lev)
    :Item(in_name,in_price,in_lev)
{
    Used = 0;
    hp_regen = 10;
}

Potion::Potion(const Potion& obj)
    :Item(obj),Used(obj.Used),hp_regen(obj.hp_regen)
{
}

// CONSTRUCTORS OF SPELLS//

Spell::Spell(string in_Name, int in_price, int in_lev, int in_damage, int in_health)
    :Name(in_Name),Price(in_price),Level_Requirement(in_lev),Damage(in_damage),magicPower_Req(in_health)
{
}

IceSpell::IceSpell(string in_Name, int in_price, int in_lev, int in_damage, int in_health)
    :Spell(in_Name,in_price,in_lev,in_damage,in_health)
{
}

IceSpell::IceSpell(const IceSpell& obj)
    :Spell(obj)
{

}

FireSpell::FireSpell(string in_Name, int in_price, int in_lev, int in_damage, int in_health)
    :Spell(in_Name,in_price,in_lev,in_damage,in_health)
{
}

FireSpell::FireSpell(const FireSpell& obj)
    :Spell(obj)
{

}

LightningSpell::LightningSpell(string in_Name, int in_price, int in_lev, int in_damage, int in_health)
    :Spell(in_Name,in_price,in_lev,in_damage,in_health)
{
}

LightningSpell::LightningSpell(const LightningSpell& obj)
    :Spell(obj)
{
}

Grid_Square::Grid_Square(){
    heroes = new Hero*[3];
    for(int i=0;i<3;i++){
        heroes[i]=NULL;
    }
    monsters = new Monster*[5];
    for(int i=0;i<5;i++){
        monsters[i]=NULL;
    }
    num_of_heroes = 0;
    IsMarket = false;
    equipment = new Item*[10];
    spells = new Spell*[10];
    item_c=0;
    spell_c=0;
    
}

Grid::Grid(int N){
    num_of_squares = N;
    Square = new Grid_Square*[N];
    for(int i=0; i<N; i++){
        Square[i] = new Grid_Square[N];
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            Square[i][j].set_squares(N);
        }
    }
    Market_Squares(N);
}

// DESTRUCTORS

Living::~Living(){
    cout << "A living being is getting destroyed." << endl;
}

Hero::~Hero(){
    cout << "A hero has been destroyed." << endl;
    delete[] weapons;
    delete[] potions;
    delete[] spells;
}

Warrior::~Warrior(){
    cout << "A warrior has been destroyed." << endl;
}

Sorcerer::~Sorcerer(){
    cout << "A Sorcerer has been destroyed." << endl;
}

Paladin::~Paladin(){
    cout << "A Paladin has been destroyed." << endl;
}

Monster::~Monster(){
    cout << "A Monster has been destroyed." << endl;
}

Dragon::~Dragon(){
    cout << "A Dragon has been destroyed." << endl;
}

Exoskeleton::~Exoskeleton(){
    cout << "An Exoskeleton has been destroyed." << endl;
}

Spirit::~Spirit(){
    cout << "A Spirit has been destroyed." << endl;
}

Item::~Item(){
    cout << "An Item has been destroyed." << endl;
}

Weapon::~Weapon(){
    cout << "A Weapon has been destroyed." << endl;
}

Armor::~Armor(){
    cout << "An Armor has been destroyed." << endl;
}

Potion::~Potion(){
    cout << "A Potion has been destroyed." << endl;
}

Spell::~Spell(){
    cout << "A Spell has been destroyed." << endl;
}

IceSpell::~IceSpell(){
    cout << "An IceSpell has been destroyed." << endl;
}

FireSpell::~FireSpell(){
    cout << "A FireSpell has been destroyed." << endl;
}

LightningSpell::~LightningSpell(){
    cout << "A LightningSpell has been destroyed." << endl;
}

Grid_Square::~Grid_Square(){
    cout << "A Grid Square has been destroyed." << endl;
    delete[] heroes;
    delete[] equipment;
    delete[] monsters;
    delete[] spells;
}

Grid::~Grid(){
    cout << "A Grid has been destroyed." << endl;
    for(int i=0; i<num_of_squares; i++){
        delete[] Square[i];
    }
    delete[] Square;
}