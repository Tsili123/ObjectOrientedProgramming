#include "Living.h"

void Hero::use(Weapon& w, Monster& m){
    
    if(this->Level < w.get_requirement())
        cout << "You need to get to Level " << w.get_requirement() << " to use this Item." << endl;
    else{
        bool TrueFalse = (rand() % 100) < m.get_push_back();
        if(TrueFalse)
            cout << "The attack was avoided by the Monster!" << endl;
        else{
            m.set_health(w.get_damage() + this->Strength);
        }
    }
}

void Hero::use(Spell& s, Monster& m){ //G
    if(this->Level < s.get_requirement())
        cout << "You should get to Level " << s.get_requirement() << " to use this Item." << endl;
    else{
        this->set_magic_power(magicPower-=s.get_magic_requirement());
        bool TrueFalse = (rand() % 100) < m.get_push_back() - Dexterity;
        if(TrueFalse)
            cout << "The attack was avoided by the Monster!" << endl;
        else
            m.set_health(s.get_Damage());

    }

}

void Hero::use(Potion &pt){ //G
    if(this->Level < pt.get_requirement())
        cout << "You should get to Level " << pt.get_requirement() << " to use this Item." << endl;
    else{
        pt.set_use();
        cout << "I used potion,I have "<< this->get_health()<<" health \n";
            this->set_health2(pt.get_hp_regen());
        cout << "Now,I have "<< this->get_health()<<"health \n";
    }
}

Item* Hero::get_weapons(int i){//G,A
    if(i<weap_c && i >=0){
        return weapons[i];
    }else{return NULL;}
}

Spell* Hero::get_spells(int i){//G,A
    if(i<spell_c && i >=0){
        return spells[i];
    }else{return NULL;}
}

Item* Hero::get_potions(int i){//G,A
    if(i<pot_c && i >=0){
        return potions[i];
    }else{return NULL;}
}

void Hero::get_rewards(int i){//A
    //get experience and gold for killing a monster
    //if experience is above certain state, level up
    if(this->Level==1){
        this->experience+=10*this->Level+5*i;
        this->money+=20*this->Level;
        if(this->experience>10){
            this->Level++;
            this->experience=0;
        }
    }else if(this->Level==2){
        this->experience+=10*this->Level+5*i;
        this->money+=20*this->Level;
        if(this->experience>30){
            this->experience=0;
            this->Level++;
        }
    }else{
        this->experience+=10*this->Level+10*i;
        this->money+=20*this->Level;
        if(this->experience>this->Level*10){
            this->experience=0;
            this->Level++;
        }
    }

}

int Potion::get_hp_regen(){//G
    return hp_regen;
}

bool Potion::get_use(){//G
    return Used;
}

void Potion::set_use(){//G
    Used = true;
}

Spell* Hero::get_spell(){
    return spells[0];
}

Weapon* Hero::get_weapon(){//A
    return weapons[0];
}

Potion* Hero::get_potion(){//A
    return potions[0];
}

void Hero::add_weapons(Weapon &wp){//A
    //resize original
    Weapon** newbuf = new Weapon*[weap_c+1];
    weap_c++;
    std::copy_n(weapons, std::min(weap_c-1, weap_c), newbuf);
    newbuf[weap_c-1] = &wp;
    delete[] weapons;
    weapons = newbuf;
}

void Hero::add_spells(Spell &sp){//A
    //resize original
    Spell** newbuf = new Spell*[weap_c+1];
    spell_c++;
    std::copy_n(spells, std::min(spell_c-1, spell_c), newbuf);
    newbuf[spell_c-1] = &sp;
    delete[] spells;
    spells = newbuf;
}

void Hero::add_potions(Potion &pt){//A
    //resize original
    Potion** newbuf = new Potion*[pot_c+1];
    pot_c++;
    std::copy_n(potions, std::min(pot_c-1, pot_c), newbuf);
    newbuf[pot_c-1] = &pt;
    delete[] potions;
    potions = newbuf;
}

void Hero::print_equipment(){//A
    
    cout << "The weapons that the hero has available are:"<<weap_c << endl;
    for(int i=0;i<weap_c;i++){
        if(weapons[i]!=NULL){
             cout << "weapon " << i << " "<< weapons[i]->get_name() << endl;
        }else{
            cout << "empty place" << i <<endl;
        }
         //same with stats
    }

    cout << "The spells that the hero has available are:" <<spell_c << endl;
    for(int i=0;i<spell_c;i++){
        if(spells[i]!=NULL){
             cout << "spell " << i << " "<< spells[i]->get_name() <<endl;
        }else{
            cout << "empty place" << i <<endl;
        }
    }

    cout << "The potions that the hero has available are:" << pot_c << endl;
    for(int i=0;i<pot_c;i++){
        if(potions[i]!=NULL) {
            cout << "potion " << i << " " << potions[i]->get_name() << endl;
        }else{
            cout << "empty place" << i <<endl;
        }
    }
}

void Hero::change_equipment(int i,int j){//A
    if(j==0){//code for weapons
        if(i>0 && i< weap_c && weapons[i]!=NULL){
            //choose the i th weapon from inventory
            std::swap(weapons[0],weapons[i]);
        }else{
            cout << "error" << endl;
        }
    }else if(j==1){//code for spells
        if(i>0 && i< spell_c&& spells[i]!=NULL){
            std::swap(spells[0],spells[i]);
        }else{
        cout << "error" << endl;
    }
    }else if(j==2){//code for potions
        if(i>0 && i< pot_c&& potions[i]!=NULL){
            std::swap(potions[0],potions[i]);
        }else{
        cout << "error" << endl;
    }
    }else{
        cout << "error" << endl;
    }
    
}

//check marketplace

Item* Hero::buy(Grid_Square& i,int in){//G,A

    if(i.get_equipment(in)!=NULL){
        Item* it = i.get_equipment(in);
        if(it->get_Price() > money){
            cout << "You don't have the money to buy this Item. It costs " << it->get_Price() << " $." << endl;
        }else{
            //return item
            money = money - it->get_Price();
            cout << "item bought\n";
            return it;
        }
    }else{
        cout << "There is no equiment at the market " << endl;
    }
}

Spell* Hero::buy2(Grid_Square& i,int in){//G,A

    if(i.get_spell(in)!=NULL){
        Spell* sp = i.get_spell(in);
        return sp;
    }else{
        cout << "There is no spell at the market " << endl;
    }
}

void Hero::sell(Weapon& i, int c){//G
    weapons[c] = NULL;
    weap_c--;
    money+=(i.get_Price()/2);
}

void Hero::sell(Potion& i, int c){//G
    potions[c] = NULL;
    pot_c--;
    money+=(i.get_Price()/2);
}

void Hero::sell(Spell& i, int c){//G
    spells[c] = NULL;
    spell_c--;
    //money+=(i.get_Price()/2);
}


void Hero::equip(Armor& a){//G
    armor_protection = a.get_damage_red() / 100;
}

int Hero::get_Dexterity() const{//G
    return Dexterity;
}

double Hero::get_armor_prot() const{//G
    return armor_protection;
}

void Hero::set_magic_power(int change){//G
    magicPower = change;
}

string Living::get_name(){//G
    return Name;
}

void Living::set_x_y(int x_in, int y_in){//G
    x = x_in;
    y = y_in;
}

void Monster::attack(Hero& h){//A
    bool TrueF = (rand() % 100) < h.get_Dexterity();
    if(TrueF){
        cout << "The hero avoided the attack!" << endl;
    }
    else{
        h.set_health(Damage*h.get_armor_prot());
    }
}

int Monster::get_damage() const{//G
    return Damage;
}

int Monster::get_push_back() const{//G
    return possibility_of_push_back;
}

int Living::get_x() const{//G
    return x;
}

int Living::get_y() const{//G
    return y;
}

int Living::get_health() const{//G
    return healthPower;
}

void Living::set_health(int change){//G
    healthPower = healthPower - change;
}

void Living::set_health2(int h){//G
    if((healthPower + h) < 100)
        healthPower += h;
    else 
        healthPower = 100;   
}

int Item::get_requirement() const{//G
    return Level_Requirement;
}

int Item::get_Price() const{//G
    return Price;
}

string Item::get_name() const{//G
    return Name;
}

int Weapon::get_damage() const{//G
    return Damage;
}

int Armor::get_damage_red() const{//G
    return Damage_Reduction;
}

int Spell::get_requirement() const{//G
    return Level_Requirement;
}

int Spell::get_magic_requirement() const{//G
    return magicPower_Req;
}

int Spell::get_Damage() const{//G
    return Damage;
}

int Spell::get_price() const{//G
    return Price;
}

string Spell::get_name() const{//G
    return Name;
}

int Grid_Square::IsAccessible(){//G
    if(num_of_heroes >=3)
        return -1;
    else    
        return 1;
}

int Grid_Square::IsAccessible2(){//A
    if(num_of_monsters >=5)
        return -1;
    else    
        return 1;
}

void Grid_Square::Market(){//G
    IsMarket = 1;
}

void Grid_Square::enter(Hero& h){//G
    if (this->IsAccessible()){
        heroes[num_of_heroes] = &h;
        num_of_heroes++;
        cout << "Hero entered" << endl;
    }
    else
        cout << "Square not Accessible." << endl;
}

void Grid_Square::enter(Monster& m){//A
    if (this->IsAccessible2()){
        monsters[num_of_monsters] = &m;
        num_of_monsters++;
        cout << "Monster entered" << endl;
    }
    else
        cout << "Square not Accessible." << endl;
}

void Grid_Square::leave(Hero& h){//A
    if(h.get_x()==0 && h.get_y()==0){
        cout << "We are at the start" << endl;
    }else{
        heroes[num_of_heroes] = NULL;
        num_of_heroes--;
    }
}

void Grid::Market_Squares(int N){//G
    //There will be 2 Market Squares
    int num[4];
    for(int i=0; i<4; i++){
        num[i] = rand() % N+1;
    }
    Square[num[0]][num[1]].Market();
    Square[3][0].Market();
}

void Grid::move_r(Hero& h){//G,A
    if(h.get_x() > num_of_squares-2){
        cout << "You can't move right. You will get off the limits." << endl;
        return;
    }
    Square[h.get_x()][h.get_y()].leave(h);
    Square[h.get_x()+1][h.get_y()].enter(h);
    h.set_x_y(h.get_x()+1,h.get_y());
}

void Grid::move_l(Hero& h){//G,A
    if(h.get_x() < 1){
        cout << "You can't move left. You will get off the limits." << endl;
        return;
    }
    Square[h.get_x()][h.get_y()].leave(h);
    Square[h.get_x()-1][h.get_y()].enter(h);
    h.set_x_y(h.get_x()-1,h.get_y());
}

void Grid::move_up(Hero& h){//G,A
    if(h.get_y() < 1){
        cout << "You can't move up. You will get off the limits." << endl;
        return;
    }
    Square[h.get_x()][h.get_y()].leave(h);
    Square[h.get_x()][h.get_y()-1].enter(h);
    h.set_x_y(h.get_x(),h.get_y()-1);
}

void Grid::move_down(Hero& h){//G,A
    if(h.get_y() > num_of_squares-2){
        cout << "You can't move down You will get off the limits." << endl;
        return;
    }
    Square[h.get_x()][h.get_y()].leave(h);
    Square[h.get_x()][h.get_y()+1].enter(h);    
    h.set_x_y(h.get_x(),h.get_y()+1);
}

int Grid_Square::get_isMarket(){//A
    return IsMarket;
}

void Grid_Square::add_equipment_to_market(Item &it){//A
    if(IsMarket){
        cout << "The square is for market\n";
         //resize original
        Item** newbuf = new Item*[item_c+1];
        item_c++;
        std::copy_n(equipment, std::min(item_c-1, item_c), newbuf);
        newbuf[item_c-1] = &it;
        delete[] equipment;
        equipment = newbuf;
    }else{
        cout << "The square is not for market\n";
    }
}

void Grid_Square::add_spell_to_market(Spell &sp){//A
    if(IsMarket){
        cout << "The square is for market\n";
        //resize original
        Spell** newbuf = new Spell*[spell_c+1];
        spell_c++;
        std::copy_n(spells, std::min(spell_c-1, spell_c), newbuf);
        newbuf[spell_c-1] = &sp;
        delete[] spells;
        spells = newbuf;
    }else{
        cout << "The square is not for market\n";
    }
}

void Grid_Square::print_market(){//A
    if(spells!=NULL){
        cout << "The spells that exist at the market are " << endl;
        for(int i=0;i<spell_c;i++){
            cout << spells[i]->get_name() << endl;
        }
    }else{
        cout << "There are not spells at the market " << endl;
    }

    cout << "\n\n" ;

    if(equipment!=NULL){
        cout << "The items that exist at the market are " << endl;
        for(int i=0;i<item_c;i++){
            cout << equipment[i]->get_name() << endl;
        }
    }else{
        cout << "There are not items at the market " << endl;
    }
}

Item* Grid_Square::get_equipment(int i){//G,A
    if(i<item_c && i >=0){
        return equipment[i];
    }else{return NULL;}
}

Spell* Grid_Square::get_spell(int i){//G,A
    if(i<spell_c && i >=0){
        return spells[i];
    }else{return NULL;}
}

void Grid_Square::set_squares(int i){//A
    num_of_squares = i;
}

void Grid_Square::print_grid(){//A
    if(num_of_heroes!=0){
         for(int i=0;i<num_of_heroes;i++){
                if(heroes[i]!= NULL){
                    cout << "v ";
                    return;
                }
         }
         cout << num_of_heroes;
    }else{
        cout << "x ";
    }
}

void Grid_Square::play_battle(){//A
    if(num_of_heroes>0 && num_of_monsters>0){
        cout << "Num of heroes "<< num_of_heroes << endl;
        bg = new Battleground(heroes,monsters,this,num_of_heroes,num_of_monsters);
        bg->round_loop();
    }else{
        cout << "There are no heroes or monsters for battle---------------\n";
    }
}

void Grid::print_grd(){//A
    cout << " I am going to print grid " << endl;
     for (int i = 0; i < num_of_squares; i++) {
        for (int j = 0; j < num_of_squares; j++) {
            Square[i][j].print_grid();
                if(j==num_of_squares-1){
                    cout << endl;
                }
        }
     }
}

void Grid::choose_grid_for_battle(int i,int j){//A
    cout << "Time for battle\n";
    if(i>-1 && i < num_of_squares && j>-1 && j<num_of_squares){
        Square[i][j].play_battle();
    }else{
        cout << "Battle out of bounds\n";
    }
}

void Grid::customize_market_of_grid_with_items(Item &it,int i,int j){//A
    cout << "Time for marketing\n";
    if(i>-1 && i < num_of_squares && j>-1 && j<num_of_squares){
        Square[i][j].add_equipment_to_market(it);
    }else{
        cout << "Market out of bounds\n";
    }
}

void Grid::place_monsters(Monster &m,int i,int j){//A
    cout << "Time to place monsters\n";
    if(i>-1 && i < num_of_squares && j>-1 && j<num_of_squares){
        Square[i][j].enter(m);
    }else{
        cout << "Battle out of bounds\n";
    }
}