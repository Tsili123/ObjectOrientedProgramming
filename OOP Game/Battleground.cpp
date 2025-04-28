#include "Battleground.h"
using namespace std;

// Constructors and destructor 
Battleground::Battleground(Hero *hero_arr, Monster *monster_arr)
	:heroes(hero_arr),monsters(monster_arr), _rounds(0),hp_regeneration(15) {
	//dynamic arrays , not fixed size
	iterh = sizeof(hero_arr)/sizeof(*hero_arr);
	iterm = sizeof(monster_arr)/sizeof(*monster_arr);
	std::cout << "Length of heroes' array  = " << iterh << std::endl;
	std::cout << "Length of monsters's array = " << iterm << std::endl;
}

Battleground::~Battleground() {
	cout << "Destructor of battleground" << endl;
}

// Get functions 
int Battleground::get_round() const { return _round; }


// Print functions
void Battleground::print_final()
{
//
}

// Core loop functions 
void Battleground::round_loop() {
	int counterh=0,counterm=0,flag=0;
	while(true){
		cout << "A game of heroes and monsters is going to start" << endl;
		
		//while(true){ //there we should have a test case condition 

			_rounds++;	// A new round begins. Note that _round was initialized to 0.
			cout << "We are into round number " << _rounds << endl;

			//hero turn 
			cout<<"#			                __#"<<endl;
			cout<<"#			               / _\ #"<<endl;
			cout<<"#			               \c /  #"<<endl;
			cout<<"#			               / \___ #"<<endl;
			cout<<"#			               \`----`#==>  #"<<endl;
			cout<<"#			               |  \  ##"<<endl;
			cout<<"#			    ,%.-''''---'`--'\#_"<<endl;
			cout<<"#			   %%/   HERO TURN  |__`"<<endl;
			cout<<"#			  .%'\     |   \   /  //#"<<endl;
			cout<<"#			  ,%' >   .'----\ |  [/#"<<endl;
			cout<<"#			     < <<`       ||#"<<endl;
			cout<<"#			      `\\\       ||#"<<endl;
			cout<<"#			        )\\      )\#"<<endl;

			//for every hero that exists in the box
			//attack every monster that there is at the box
			for(int i=0;i<iterh;i++){
				for (int j=0;j<iterm;j++){

					//display a menu of choice for every hero
					cout << "The hero's name that you have available is " << heroes[i].get_name(); << endl;
					cout << "The actions that the hero can do are shown below." << endl;
					cout << "1.Attack with weapon" << endl; 
					cout << "2.Use spell" << endl; 
					cout << "3.Use potion" << endl;
					cout << "4.Change armor and weapon" << endl;
					cout << "Please,select the desired action by entering a number from 1 to 4 to console" << endl;
					int var;
					cin >> var;

					if(var == 1){
						//if the hero has weapons,use attack damage

						//only alive heroes can attack
						if(heroes[i].get_health()>0){
							Weapon wp = heroes[i].get_weapon();
							heroes[i].use(wp,monsters[j]);
						}
					}else if(var == 2){
						//if the hero is sorcerer,use spell

						//only alive heroes can attack
						if(heroes[i].get_health()>0){
							Spell sp = heroes[i].get_spell();
							heroes[i].use(sp,monsters[j]);
						}
					}else if(var == 3){
						//we must check the invetory of heroes , if there is any potion
						
						//if not skip
					}else if(var == 4){
						//the change weapon function changes the order of weapons and armor in the array
						//because we always choose the first weapon from array in the fight

						//heroes[i].change_weapon(); ------. function.cpp

						//the change armor function removes the current armor and puts the new one to the hero
						//heroes[i].change_armor(); ------. function.cpp

					}
				}
			}

			//monsters turn
			cout<<"#				       __.-/|#"<<endl;
			cout<<"#				       \`o_O'#"<<endl;
			cout<<"#				       =( )=  +---------------+ #"<<endl;
			cout<<"#				         U|   | MONSTERS TURN | #"<<endl;
			cout<<"#				 /\  /\   / |   +---------------+ #"<<endl;
			cout<<"#				) /^\) ^\/ _)\     |#"<<endl;
			cout<<"#				)   /^\/   _) \    |#"<<endl;
			cout<<"#				)   _ /  / _)  \___|_#"<<endl;
			cout<<"#			/\  )/\/ ||  | )_)\___,|))#"<<endl;
			cout<<"#			<  >      |(,,) )__)    |#"<<endl;
			cout<<"#			||      /    \)___)\ #"<<endl;
			cout<<"#			| \____(      )___) )____#"<<endl;
			cout<<"#			\______(_______;;;)__;;;)#"<<endl;

			//for every monster that exists in the box
			//attack every hero that there is at the box
			for(int i=0;i<iterh;i++){
				for (int j=0;j<iterm;j++){
					//only alive monsters can attack
					if(monsters[j].get_health()>0){
						monsters[j].attack(heroes[i]);
					}
			   }
		    }

			//review stats to determine battle outcome
			//if all heroes are dead , monster won
			//if all monsters are dead, heroes won
			counterh=0;
			for(int i=0;i<iterh;i++){
				if(heroes[i].get_health()<=0){
					counterh++;
					if(counterh == iterh){
						cout << "Monsters won the battle" << endl;
					}
				}
			}

			for(int i=0;i<iterm;i++){
				if(monsters[i].get_health()<=0){
					counterm++;
					if(counterm == iterh){
						cout << "Heroes won the battle" << endl;
					}
				}
			}

			//regeneration
			counterh=0;
			for(int i=0;i<iterh;i++){
				if(heroes[i].get_health()<=0){
					counterh++;
					if(counterh == iterh){
						cout << "Monsters won the battle" << endl;
					}
				}
			}

			for(int i=0;i<iterh;i++){
				if(heroes[i].get_health()>0){
					heroes[i].set_health(hp_regeneration);
				}
			}

			for(int i=0;i<iterm;i++){
				if(monsters[i].get_health()>0){
					monsters[i].set_health(hp_regeneration);
				}
			}
			
			//levels,rewards

		//}

	}
	    //reset to half initial value 
    	for(int i=0;i<iterh;i++){
			if(heroes[i].get_health()<=0){
				heroes[i].set_health(50);
			}
		}

}
