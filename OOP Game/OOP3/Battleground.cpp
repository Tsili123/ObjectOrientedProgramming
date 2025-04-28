#include "Living.h"
#include <sstream>
//#include "Functions.cpp"
//#include "Constructors.cpp"
using namespace std;

//g++ -std=c++11 -o f.o Functions.cpp
//g++ -std=c++11 -o b.o Battleground.cpp

//A everything

// Constructors and destructor 
Battleground::Battleground(Hero **hero_arr, Monster **monster_arr,Grid_Square *gc,int num_hero,int num_monster)
	:heroes(hero_arr),monsters(monster_arr),gridsquare(gc), _rounds(0),hp_regeneration(15) {
	//dynamic arrays , not fixed size
	iterh = num_hero;
	iterm = num_monster;
	std::cout << "Length of heroes' array  = " << iterh << std::endl;
	std::cout << "Length of monsters's array = " << iterm << std::endl;
}

Battleground::~Battleground() {
	cout << "Destructor of battleground" << endl;
}

// Get functions 
int Battleground::get_round() const { return _rounds; }


// Print functions
void Battleground::print_stats()
{
	cout << "The health points for every hero are:" << endl;
	for(int i=0;i<iterh;i++){	
		if(heroes[i]!=NULL){
			cout << heroes[i]->get_name()<< " health : " << heroes[i]->get_health()  <<endl;
		}
		else{
			//cout << " empty place in hero array\n";
		}
	}

	cout << "The health points for every monster are:" << endl;
	for(int i=0;i<iterm;i++){	
		if(monsters[i]!=NULL){
			cout << monsters[i]->get_name()<< " health : " << monsters[i]->get_health()  << endl;
		}else{
			//cout << " empty place in monster array\n";
		}
	}
}

// Core loop functions 
void Battleground::round_loop() {
	int counterh=0,counterm=0,flag=0;
	std::string tString = ""; // Used to read and subsequently parse the string.
	string str, error;
	bool outer=true;
	int var;
					
	while(outer){
		cout << "A game of heroes and monsters is going to start" << endl;
		// Ignore to the end of line
				
		if(iterh>0 && iterm >0){ //there we should have a test case condition 

			_rounds++;	// A new round begins-> Note that _round was initialized to 0->
			cout << "We are into round number " << _rounds << endl;

			//hero turn 
			cout<<"#			                __#"<<endl;
			cout<<"#			               / _\\ #"<<endl;
			cout<<"#			               \\c /  #"<<endl;
			cout<<"#			               / \\___ #"<<endl;
			cout<<"#			               \\`----`#==>  #"<<endl;
			cout<<"#			               |  \\  ##"<<endl;
			cout<<"#			    ,%.-''''---'`--'\\#_"<<endl;
			cout<<"#			   %%/   HERO TURN  |__`"<<endl;
			cout<<"#			  .%'\\     |   \\   /  //#"<<endl;
			cout<<"#			  ,%' >   ->'----\\ |  [/#"<<endl;
			cout<<"#			     < <<`       ||#"<<endl;
			cout<<"#			      `\\\\       ||#"<<endl;
			cout<<"#			        )\\      )\\#"<<endl;

			//for every hero that exists in the box
			//attack every monster that there is at the box
			for(int i=0;i<iterh;i++){
				for (int j=0;j<iterm;j++){

					cout << "The weapon that the hero has available right now is " << heroes[i]->get_weapon()->get_name() << endl; 

					//display a menu of choice for every hero
					cout << "The hero's name that you have available is " << heroes[i]->get_name() << endl;
					cout << "The actions that the hero can do are shown below :" << endl;
					cout << "1.Attack with weapon" << endl; 
					cout << "2.Use spell" << endl; 
					cout << "3.Use potion" << endl;
					cout << "4.Change armor and weapon" << endl;
					cout << "5.Market,deals" << endl;
					cout << "Please,select the desired action by entering a number from 1 to 5 to console:" << endl;
					
					cin >> var;
					cin.ignore();

					if(var == 1){
						//if the hero has weapons,use attack damage
						if(heroes[i]->get_weapon()!=NULL){
							//only alive heroes can attack
							if(heroes[i]->get_health()>0){
								if(monsters[j]!=NULL && monsters[j]->get_health()>0){
									Weapon *wp = heroes[i]->get_weapon();
									heroes[i]->use(*wp,*monsters[j]);
								}else
									cout << "Monster is dead" << endl;
							}
						}else{
							cout << "The hero has no weapons to use" << endl;
						}
					}else if(var == 2){
						//if the hero has spells,use spell
						if(heroes[i]->get_spell()!=NULL){
							//only alive heroes can attack
							if(heroes[i]->get_health()>0){
								if(monsters[j]!=NULL && monsters[j]->get_health()>0){
									Spell *sp = heroes[i]->get_spell();
									heroes[i]->use(*sp,*monsters[j]);
								}else
									cout << "Monster is dead" << endl;
							}
						}else{
							cout << "The hero has no spells to use" << endl;
						}
					}else if(var == 3){
						//we must check the invetory of heroes , if there is any potion
						if(heroes[i]->get_potion()!=NULL && heroes[i]->get_potion()->get_use() == false ){
							//only alive heroes can use potions
							if(heroes[i]->get_health()>0){
								Potion *pt = heroes[i]->get_potion();
								heroes[i]->use(*pt);
							}
						}
						//if not skip
						else{
							cout << "The hero has no potions to use,or the potion is used" << endl;
						}
					}else if(var == 4){
						//the change weapon function changes the order of weapons and armor in the array
						//because we always choose the first weapon from array in the fight
						
						//print inventory
						heroes[i]->print_equipment(); 

						//print market

						cout << "Enter which category you want to use" << endl;
						cout << "0 for weapon , 1 for spell,2 for potion" << endl;
						int cat,num;
						cin >> cat;
						cin.ignore();

						cout << "Enter which item from category you want to use" << endl;
						cout << "0, 1 , 2 , 3 etc depending on the size of each array(segme fault if out of bounds)" << endl;
						cin >> num;
						cin.ignore();

						if(num < 4 && num >0)
							heroes[i]->change_equipment(num,cat); 
						else
							cout << "Out of bounds of inventory \n";

						//print inventory
						heroes[i]->print_equipment(); 

						//the change armor function removes the current armor and puts the new one to the hero
						//heroes[i]->change_armor(); -------> function->cpp

					}else if(var == 5){
						if(gridsquare->get_isMarket()){
							gridsquare->print_market();
							cout << "Enter the number of item that you want to buy starting from 0,press -1 if you dont want to.Then you are going to sell " << endl;
							int temp;
							cin >> temp;
							cin.ignore();

							if(temp!=-1){
								Item* tp = heroes[i]->buy(*gridsquare,temp);
								cout << "You bought a potion or a weapon ?" << endl;
								cout << "press 1 for weapon , 2 for potion" << endl;
								int temp2;
								cin >> temp2;
								cin.ignore();
								if(temp2==1){
									Weapon *tp2 = (Weapon *)tp;
									heroes[i]->add_weapons(*tp2);
								}else if(temp2 == 2){
									Potion *tp2 = (Potion *)tp;
									heroes[i]->add_potions(*tp2);
								}else{
									cout << "error" << endl;
									continue;
								}
							}else{
								//sell
								int temp3,temp4;
								cout << "You want to sell a potion , a spell or a weapon ?" << endl;
								cout << "press 1 for weapon , 2 for potion, 3 for spell" << endl;
								cin >> temp3;
								cin.ignore();

								cout << "Enter the number of item that you want to sell starting from 0\n";
								cin >> temp4;
								cin.ignore();

								if(temp3==1){	
									Item* tp = heroes[i]->get_weapons(temp4);
									Weapon *tp2 = (Weapon *)tp;
									if(tp2!=NULL)
										heroes[i]->sell(*tp2,temp4);
									else
										cout << "weapon does not exist\n";
								}else if(temp3 == 2){
									Item* tp = heroes[i]->get_potions(temp4);
									Potion *tp2 = (Potion *)tp;
									if(tp2!=NULL)
										heroes[i]->sell(*tp2,temp4);
									else
										cout << "weapon does not exist\n";
								}else if(temp3 == 3){
									Spell* tp = heroes[i]->get_spells(temp4);
									Spell *tp2 = (Spell *)tp;
									if(tp2!=NULL)
										heroes[i]->sell(*tp2,temp4);
									else
										cout << "Spell does not exist\n";
								}else{
									cout << "error" << endl;
									continue;
								}
							}
					}else{
							cout << "The square does not include a market\n";
					}
				}
				cout << "\n\n\n\n";
			}

			print_stats();

			//monsters turn
			cout<<"#				       __.-/|#"<<endl;
			cout<<"#				      \\`o_O'#"<<endl;
			cout<<"#				       =( )=  +---------------+ #"<<endl;
			cout<<"#				         U|   | MONSTERS TURN | #"<<endl;
			cout<<"#				 /\\  /\\   / |   +---------------+ #"<<endl;
			cout<<"#				) /^\\) ^\\/ _)\\     |#"<<endl;
			cout<<"#				)   /^\\/   _) \\    |#"<<endl;
			cout<<"#				)   _ /  / _)  \\___|_#"<<endl;
			cout<<"#			/\\  )/\\/ ||  | )_)\\___,|))#"<<endl;
			cout<<"#			<  >      |(,,) )__)    |#"<<endl;
			cout<<"#			||      /    \\)___)\\ #"<<endl;
			cout<<"#			| \\____(      )___) )____#"<<endl;
			cout<<"#			\\______(_______;;;)__;;;)#"<<endl;

			//for every monster that exists in the box
			//attack every hero that there is at the box
			for(int i=0;i<iterh;i++){
				for (int j=0;j<iterm;j++){
					//only alive monsters can attack
					if(monsters[j]->get_health()>0){
						//if hero is alive
						if(heroes[i]->get_health()>0)
							monsters[j]->attack(*heroes[i]);
						else	
							cout << "Hero is dead" << endl;
					}
			   }
		    }

			//review stats to determine battle outcome
			//if all heroes are dead , monster won
			//if all monsters are dead, heroes won
			counterh=0;
			for(int i=0;i<iterh;i++){
				if(heroes[i]->get_health()<=0){
					counterh++;
					if(counterh == iterh){
						cout << "Monsters won the battle" << endl;
						outer = false;
						break;
					}
				}
			}
			
			counterm=0;
			for(int i=0;i<iterm;i++){
				if(monsters[i]->get_health()<=0){
					counterm++;
					if(counterm == iterm){
						cout << "Heroes won the battle" << endl;
						for(int i=0;i<iterh;i++){
							heroes[i]->get_rewards(counterm);
						}
						outer = false;
						break;
					}
				}
			}

			print_stats();

			if(outer==false)
				break;

			//regeneration

			for(int i=0;i<iterh;i++){
				if(heroes[i]->get_health()>0){
					int var5;
					heroes[i]->set_health2(hp_regeneration);
				}
			}

			for(int i=0;i<iterm;i++){
				if(monsters[i]->get_health()>0){
					monsters[i]->set_health2(hp_regeneration);
				}
			}
			
		}}else{
			cout << "Battle cant happen ,there are no heroes or monsters\n";
		}

			print_stats();
	}
	
	//reset to half initial value 
    for(int i=0;i<iterh;i++){
		if(heroes[i]->get_health()<=0){
			heroes[i]->set_health(50);
		}
	}

	print_stats();

}
