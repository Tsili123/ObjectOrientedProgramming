#include <iostream>
#include <stdlib.h>    
#include <time.h> 

using namespace std;

 class Person{	//Person class will represent the people who take part 
	protected:
		int classroom_num; //the Classroom that the person wants to go to
		int floor_num; //the floor that the person wants to go to
		int priority; //his priority
		int tireness; //variable that determines whether the person was tired or not
		int flag_tier;
		const char *name;
		//tireness
	public:
		Person(int cln, int fln,int flg,const char *s):classroom_num(cln),floor_num(fln),flag_tier(flg),name(s){ //Constructor function
			this->tireness=0;
		}
		
		virtual int set_tireness(){}
		virtual int get_tireness(){}
		virtual int get_floor(){}	
		virtual int get_classroom(){}
		virtual void set_prio(int){}
		virtual int get_prio(){}
		virtual void print_prio(){}
		
		~Person(){} //Destructor function	
}; 

class Student: public Person{
		private:
		//tireness
		int std_tired;
	public:
		Student(int cln, int fln,int flg,const char *s,int L):Person(cln,fln,flg,s),std_tired(L){ //Constructor function
			cout << "A student has been created" << endl;
			this->tireness=0;
		}
		
		int set_tireness(){ //this function will be used later when a person has reached his Classroom in order to get a tireness value
			this->tireness += std_tired;
			return this->tireness;
		}
		
		int get_tireness(){ //getter that returns whether the person is tired or not
			return this->tireness;
		}
		
		int get_floor(){ //getter that returns person's floor
			return this->floor_num;
		}
		
		int get_classroom(){ //getter that returns person's Classroom
			return this->classroom_num;
		}
		
		void set_prio(int i){ //this function is used when a person reaches the groundfloor, this is where his priority is set
			this->priority=i;
		}
		
		int get_prio(){ //getter that returns Person's priority
			return this->priority;
		}
		
		void print_prio(){  //function that prints person's priority
			cout << "  Student included.His/her priority is :" << this->priority << " name is : " << name << " Tireness : " << this->tireness << endl;
		}
		
		~Student(){} //Destructor function	
};


class Teacher: public Person{
		private:
		//tireness
		int teacher_tired;
	public:
		Teacher(int cln, int fln,int flg,const char *s,int Lt):Person(cln,fln,flg,s),teacher_tired(Lt){ //Constructor function
			cout << "A teacher has been created" << endl;
			this->tireness=0;
		}
		
		int set_tireness(){ //this function will be used later when a person has reached his Classroom in order to get a tireness value
			this->tireness += teacher_tired ;
			return this->tireness;
		}
		
		int get_tireness(){ //getter that returns whether the person is tired or not
			return this->tireness;
		}
		
		int get_floor(){ //getter that returns person's floor
			return this->floor_num;
		}
		
		int get_classroom(){ //getter that returns person's Classroom
			return this->classroom_num;
		}
		
		void set_prio(int i){ //this function is used when a person reaches the groundfloor, this is where his priority is set
			this->priority=i;
		}
		
		int get_prio(){ //getter that returns Person's priority
			return this->priority;
		}
		
		void print_prio(){  //function that prints person's priority
			cout << "  Teacher included .His/her" << " priority is :" << this->priority << ", name is : " << name << " Tireness : " << this->tireness << endl;
		}
		
		~Teacher(){} //Destructor function	
};


class Space{ //base class which every  class inherits from (groundfloor inherits from floor class)
	protected:
		int cap; //capacity is used by every child
	public:
		Space(int size):cap(size){} //Constructor function

        //all functions are inherited by the mother class 
        //because later on instead of using the children directly,
        //i will pass their addresses at pointers to the mother class

        // Note: Except groundfloor,
        // because it has to use other classes as arguments in its methods
		
		virtual void enter(Person*){} 	//	corridor  enter
		virtual void enter(Person*, int){}  //floor ,staircase ,building enter
		virtual void enter(Person* , int ,int ){}

		virtual Person* exit(){}	// classroom , floor exit		
		virtual Person* exit(int, int){} //corridor exit
		virtual Person* exit(int){}  //staircase exit
		virtual void exit(Person*){} // building exit
		
		virtual int get_class_count(){} //classroom
		virtual int get_class(int){} //corridor
		virtual int get_corridor_count(){}//corridor
		virtual int get_fl_num(){}//floor
		virtual int get_fl_count(){}//floor

		virtual void operate(){} //staircase,building
        virtual void print_prio(int, int, int){} //corridor
        virtual void make_tireness(){} //classroom
		
		~Space(){} //Destructor function
};

class Classroom: public Space{ //Classroom class that the Person has to go to
		
	private:
		int class_num;	//class_num member is the number of the Classroom
		int class_count; //how many people are in an Classroom
		Person** people_of_class; //array that stores all the people in an Classroom
		
	public:
		Classroom(int spc,int cln):Space(spc),class_num(cln){ // constructor function
            cout << "Classroom number "<< this->class_num << " has been created." <<endl; 
			
			people_of_class = new Person*[spc];
			
            for(int i=0;i<spc;i++){
				people_of_class[i]=NULL;
			}
			class_count=0;
		}
		
		void enter(Person* pl){ //Classroom enter takes a Person and places him in the first empty cell it finds
			int i=0;
			for(i;i<cap;i++){
				if(people_of_class[i]==NULL){
					break;
				}
			}
			people_of_class[i]=pl;
			class_count++;
		}
		
		Person* exit(){ //Classroom exit removes the first Person (who was tired) from the array 
			Person* temp=NULL;
			int i=0;
			for(i;i<cap;i++){
				if(people_of_class[i]!=NULL && people_of_class[i]->get_tireness()>0){
					temp=people_of_class[i];
					people_of_class[i]=NULL;
					class_count--;
					break;
				}
			}	
			return temp;	
		}
						
		void make_tireness(){ //this function sets a Person's tireness value to 1
			for(int i=0;i<cap;i++){
				if(people_of_class[i]!=NULL){
						people_of_class[i]->set_tireness();
				}
			}
		}	
		
		int get_class_count(){ //get how many people are in an Classroom
			return class_count;
		}
		
		~Classroom(){
			cout << "End of the work!" <<endl; //Destructor function
			// for(int i=0;i<cap;i++){
			// 	if(people_of_class[i]!=NULL)
			// 		delete people_of_class[i];
			// }
			//delete[] people_of_class;
		}
};

class Corridor: public Space{ 
	
	private:
		Person** corridor_arr; //array that stores all the people in the corridor
		int corridor_ct; //how many people are at corridor
	public:
		Corridor(int size):Space(size){ //Constructor function
			cout<<"The Corridor has been created!" <<endl; 
			
			corridor_arr = new Person* [size];
			int i=0;

			for(i;i<size;i++){
				corridor_arr[i]=NULL;
			}
			corridor_ct=0;
		}
	
		void enter(Person* pl){  // Corridor array takes a Person and places him at the first empty cell
			int i=0;
			for(i;i<cap;i++){
				if(corridor_arr[i]==NULL){
					break;
				}
			}
			
			corridor_arr[i]=pl;
			corridor_ct++;
		}
		
		
		Person* exit(int fl_num,int class_num){  
        // Corridor exit removes the first Person (who was tired) from the array 
		// Arguments fl_num and class_num are used because the function behaves differently if we are exiting from a floor's corridor
		//works both ways
			if(fl_num==0){ //exiting from groundfloor
				Person* temp;
			
				int i=0;
				for(i;i<cap;i++){
					if(corridor_arr[i]!=NULL){
						break;
					}
				}

				temp=corridor_arr[i];
				corridor_arr[i]=NULL;
				corridor_ct--;
				return temp;

			}else if(fl_num==1){  //exiting from floor
				Person* temp;
				int j=0;
				for(j;j<cap;j++){
                    //making sure if the Person wants to go to the desired classroom
					if(corridor_arr[j]!=NULL && corridor_arr[j]->get_classroom()==class_num){ 
						break;
					}
				}

				temp=corridor_arr[j];
				corridor_arr[j]=NULL;
				corridor_ct--;
				return temp;
			}
		}
		
		int get_class(int i){ //this function is used to ensure the Person wants to go to the office we are currently on
			int index=0;
			
			int j=0;
			for(j;j<cap;j++){
				if(corridor_arr[j]!=NULL && corridor_arr[j]->get_classroom()==i){
					index=1;
					break;
				}
			}
			return index;
		}
		
		void print_prio(int n, int f, int i){ 
            //function to print Person's priority
            //again f and i arguments are used because it behaves differently if we are on the floor

			if (f==0){						 
				if (corridor_arr[n]!=NULL){
					cout<<"You are not allowed to enter!";
					corridor_arr[n]->print_prio();
				}
			}else if (f==1){
				if (corridor_arr[n]!=NULL){
					cout<<"Please wait outside office: " << i ;
					corridor_arr[n]->print_prio();
				}
			}
		}
		
		int get_corridor_count(){ //getting how many people are at an corridor
			return corridor_ct;
		}
		
		~Corridor(){ //Destructor function
			cout << "End of waiting people!" << endl;
			for(int j=0;j<cap;j++){
				if(corridor_arr[j]!=NULL)
					delete corridor_arr[j];
                //corridor_arr[j]=NULL;
			}
			//delete[] corridor_arr;
		}
};	

class Floor: public Space{
		
	private:
		
		int class_cap; //class's capacity
		int fl_num; //this member is floor's number
		int fl_count; //how many people are in a floor
		Corridor* corridor_of_floor; //floor's corridor 
		Space* baseptr; //pointer to the mother
        Space* Baseptrs[6]; //pointer array to the mothers
		Classroom* Cl[6]; //every floor has 6 classes
	public:
		Floor(int fl_c, int cl_cap, int fl_n):Space(fl_c),class_cap(cl_cap),fl_num(fl_n){ //Constructor function
		
			if(this->fl_num!=0){
				cout << "A Floor has been created with number:" << this->fl_num << endl; 
			}
				
			if(this->class_cap!=0){ //don't create classrooms and corridor if capacity is zero (only in ground floor)
				corridor_of_floor= new Corridor(fl_c);
				baseptr=corridor_of_floor;	
				
				for(int i=0;i<6;i++){
					Cl[i]= new Classroom(class_cap,i+1);
				}

				for(int i=0;i<6;i++){
					Baseptrs[i] = Cl[i];
				}
			}
			
			fl_count=0;
		}
		
		int get_fl_num(){   //getting floor's number
			return this->fl_num;
		}
		
	
		void enter(Person* pl, int a){ //floor enter places a Person in floor's corridor then proceeds to the entering stage of the class
			
			baseptr->enter(pl);//corridor
			fl_count++;
		
			for(int i=0;i<6;i++){ //for every class
				if(Baseptrs[i]->get_class_count() < this->class_cap){ //if the Person fits in class
					if(baseptr->get_class(i+1)){ //and if this is the class he wants to go to
						
						Person* temp = baseptr->exit(1,i+1); //remove him from the corridor
				
		            	Baseptrs[i]->enter(temp); //and place him in the class
						cout<<"Entering class with number: "<< i+1 ; 
						temp->print_prio();
						break; //only one can enter at a time so if one person went in no need to continue the loop
					}
				}
				else{ 
                    //print the desired messages if he couldn't fit
					cout<<"Please wait for outside in class: "<< i+1 << " ";
					pl->print_prio(); 
					break;
				}
			}	
		}
		
		Person* exit(){ //floor exit function removes the first Person 
        //that was tired and also proceeds to enter those that wait in the corridor 
			
			Person* cl_temp = NULL;
			Person* pl_temp = NULL;

			for(int i=0;i<6;i++){ //for every floor
				if(Baseptrs[i]->get_class_count()!=0){ //if there is at least one person inside
					if( (pl_temp=Baseptrs[i]->exit()) != NULL ){ //if we managed to find someone
					
						cl_temp=pl_temp; //place him temporarily in a variable

						fl_count--;

						for(int j=0;j<baseptr->get_corridor_count();j++){ 

                            //now check for every person in the corridor if he can go in the Class
							if(Baseptrs[i]->get_class_count() < class_cap){ 
                            // if class count is less than its capacity 
								if( baseptr->get_class(i+1) ){ //if we find someone that wants this Class
									//cout << "mesaaaaaaaaaaaaaa" <<endl;
									Person* temp; 
									temp=baseptr->exit(1,i+1); //remove him from the corridor
									Baseptrs[i]->enter(temp); //and place him in that class
									cout<<"Entering class number: "<< i+1 ;
									temp->print_prio();
								}
							}
							else{ 
                                //for those that couldn't enter yet again..
								baseptr->print_prio(j,1,i+1); 								
							}
						}
					    break; //we only return one Person at a time, so if we found somebody break the loop
					}
				}	
			}
			return cl_temp; //return the Person 
		}
			
		int get_fl_count(){ //getting how many people are in a floor
			return this->fl_count;
		}
	
		void make_tireness(){ //this function will go at every class that has at least one person inside and give him a tireness value
			for (int i=0; i<6; i++){
				if(Baseptrs[i]->get_class_count()!=0){
					Baseptrs[i]->make_tireness();			
				}
			}
		}
		
		Classroom* get_class_from_fl(int i){
			return  Cl[i];
		}

		~Floor(){ //Destructor function
			delete corridor_of_floor;
			for(int i=0;i<6;i++){
				delete Cl[i]; 
			}
			cout<<"End of service!" <<endl;
		}

        virtual void print_prio(int){} //ground floor has to inherit those functions
		virtual int get_grl_count(){}
		virtual void enter(Person*, int, int, int ){}
		virtual Person* exit(int){}
		virtual void wait(Person*, int){}
		virtual void grl_dec_counter(){}
		
};

class GroundFloor: public Floor{ 
	
	private:
		
		Corridor* grl_corridor; //groundfloor's corridor
		Space* baseptr; //pointer to the mother
		Person** pl_ground; //array that stores all the people in a ground floor 
		Person** pl_finished; //array that stores all the people who finished their work from their offices
		int grl_count; //how many people are in a groundfloor
		
	public:
		GroundFloor(int grlc):Floor(grlc,0,0){  //Constructor function
			
			cout << "A Ground Floor has been created " << endl;
			grl_corridor = new Corridor(grlc);
			
			pl_ground= new Person* [grlc];

			for(int j=0;j<grlc;j++){
				pl_ground[j]=NULL;
			}
			
			pl_finished= new Person*[grlc];

			for(int j=0;j<grlc;j++){
				pl_finished[j]=NULL;
			}
			
			baseptr = grl_corridor;
			grl_count=0;
		}
		
		void wait(Person* pl ,int a){ 
            //wait function gives a Person his priority and places him inside groundfloor's corridor 
			 pl->set_prio(a+1);
			 grl_corridor->enter(pl);
			 
			 cout<< "Waiting for the lift." << endl;
		}
		
		void enter(Person* pl, int n, int b, int l ){ 
            //enter function to place the people inside the corridor and forbid from entering those who can't fit
			if(l==0){   //if the Person goes from the building to the groundfloor
				if(n<cap){ //if he can fit put him in a array
					pl_ground[n]=pl;
					grl_count++;
				}

				if(n>=cap){ //if can't fit print the desired message
					cout<<"Sorry, you can't fit in the ground floor."<<endl;
				}

				if(n==b-1){ //if the counter is equal to the building counter then we did all the necessary work for every Person
                // (who went in the building) 
					for(int i=0;i<grl_count;i++){ //call the wait function for those that fit in the groundfloor
						wait(pl_ground[i],i);
					}
				}
			}
			
			if(l==1){ //if the Person is returning from the staircase to the groundfloor place him in a different array 
				int i=0; 
				for(i;i<cap;i++){
					if(pl_finished[i]==NULL){
						break;
					}
				}
				pl_finished[i]=pl;
			}
		}
		
			
		Person* exit(int l){ //exit function removes a Person 
			 
			if (l==0){ //if the Person goes from the groundfloor to the staircase remove him from the groundfloor's corridor
		    	grl_corridor->exit(0,0);
			}

			if(l==1){  
                //if the Person goes from the groundfloor to the building 
                //(when he has finished, that is) remove him from the pl_finished array
				Person* temp;
				
				int i=0;
				for(i;i<cap;i++){
					if(pl_finished[i]!=NULL){
						break;
					}
				}

				temp=pl_finished[i];
				pl_finished[i]=NULL;
				return temp;
			}		
		}
		
		void print_prio(int y){ 
            //function to print Person's priority 
			grl_corridor->print_prio(y,0,0);
             //(this is used in the staircase's entering stage 
             //so the Person won't have to leave the corridor only to enter it again)
		}
		
		int get_grl_count(){ 
            //getting how many people are in a groundfloor
			return this->grl_count;
		}		
			
		void grl_dec_counter(){ 
            //function to decrement groundfloor's counter
			this->grl_count--;
		}
		

		~GroundFloor(){ //Destructor function
			// delete grl_corridor;
			// cout << "End of service!" << endl; 

			// for(int j=0;j<cap;j++){
			// 	if(pl_ground[j]!=NULL)
			// 		delete pl_ground[j];
			// }
			 delete[] pl_ground;
			
			// for(int k=0;k<cap;k++){
			// 	if(pl_finished[k]!=NULL)
			// 		delete pl_finished[k];
			// }
			delete[] pl_finished;
		}
	
};

class Staircase: public Space{ 
	
	private:
		int strc_count;  //how many people are in an Staircase
		int finised_counter;  //how many people finished
		Person** pl; //array that stores all the people in an Staircase
		int lpos,fpos;  //the use of these variables will be explained in the function they are used

	public:
		Staircase(int flc):Space(flc){ //Constructor function

			cout <<"A lift has been created!"<< endl;
			lpos=0;
			fpos=0;
			strc_count=0;
			finised_counter=0;
			
			pl = new Person* [flc];
			for(int j=0;j<flc;j++){
				pl[j]=NULL;	
			}
		}
		
		Person* exit(int n){ //exit function removes the Person from the cap cell 
			Person* temp;
			temp=pl[n];
			pl[n]=NULL;
			
			return temp;
		}
		
		int empty_all(Floor* flptr){ 
        //empty all function takes the Persons who finished and places them in the groundfloor	
			finised_counter=0;
			for(int i=0;i<cap;i++){
				if(pl[i]==NULL){ //if we stumbled upon a non-existent Person run the loop again
					continue;
				}
				if(pl[i]->get_tireness()>0){
					Person* temp = exit(i);
					strc_count--;
					flptr->enter(temp,i,0,1);
					finised_counter++;
				}
			}
			return finised_counter; //empty all has to return how many finished		
		}
		
		void StopDown(Space* flptr[],int opc){  //stop down function that goes through every floor and takes those that finished

			//Attend / Teach
			for(int f=0;f<3;f++){ //give tireness values to those that are in the classes
				for(int p=0;p<opc;p++)
					flptr[f]->make_tireness();
			}
			
			for(int f=2;f>=0;f--){ 
                //since we are stopping down, the loop begins from the last floor
				for(int i=0;i<cap;i++){ 
                    //for cap number of people 
					if (flptr[f]->get_fl_num() == f+1 ){ //just making sure we are on the right floor
						if(strc_count<cap){ //if there is room for more
							int j=0; 
							for(j;j<cap;j++){ //find an empty position
								if(pl[j]==NULL){
									break;
								}
							}
					
							Person* temp= flptr[f]->exit(); //find a tired Person
				
							if(temp!=NULL){ //if he exists place him in the empty position
								enter(temp,j);
								strc_count++;
								continue;
							}
						}	
					}
				}
			}
		}
		
		void StopUp(Space* flptr[],int flr_cap){  //stop up function that goes through every floor and places the people who want to enter it 
			
			for(int f=0;f<3;f++){ //for every floor
	
				for(int i=0; i<cap; i++){ //for cap num of people 
					
                    if (strc_count == 0){ //if there is no one on the Staircase this process is skipped 
						break;
					}

					if (pl[i]==NULL){  //if we stumbled upon a non-existent Person run the loop again
						continue;
					}

					if ( pl[i]->get_floor() == f+1 ){ //if this is the floor the Person wants to go to
				
						if( flptr[f]->get_fl_count() < flr_cap){ //if he can fit in the floor
							Person* temp = exit(i);   //remove him from the Staircase
							strc_count--;	
							cout<<"Entering floor number: " << f+1 ;
							temp->print_prio();
							flptr[f]->enter(temp, i); //and place him on the floor
							continue; 
						}
						else{ 
                            //if he can't fit print the desired messages
							cout<<"Sorry, floor number " << f+1 << " is full. ";
							pl[i]->print_prio();
						}
					}
				}
			}
		}
		
		void enter(Person* prs,int i){ 
            //enter function places a Person in the i cell
				cout<<"Person on the lift. \n" ;
				pl[i]=prs;
				pl[i]->print_prio();
		}
		
		int operate(Floor* flptr,Space* baseptr[],int index,int fl_cap,int opc){
			
				int i=0;
				lpos=fpos; //lpos is the counter that goes through everyone in the groudfloor, fpos's use is explained below  
				
			//Entering stage
			for(lpos;lpos<index;lpos++){
					
                    if(flptr->get_grl_count()==0){ 
                        //if we took everyone from the groundfloor we may skip the entering stage
						break;
					}

					if(strc_count<cap){ //if the Person can fit in the Staircase	
						int j=0;
						for(j;j<cap;j++){
							if(pl[j]==NULL){ //find an empty position
								break;
							}
						}
						
						Person* temp = flptr->exit(0); //remove him from the groundfloor
						
						if(temp!=NULL){ //if he exists
							flptr->grl_dec_counter(); //decrement the counter of those who are on the groundfloor
							enter(temp,j); //and place him in the Staircase
						
							strc_count++;
							i++;
							continue; //continue statement is used in order to execute the following if-block in the next loop 
						}

					}

					if(strc_count==cap){ //if the counter is equal to the capacity this means we can't take any more people
						if(i==cap){ //if this is the first Person who couldn't fit 
							fpos=lpos; //then place his position in fpos so the loop will begin from this one in the next operation
						}
						 
						flptr->print_prio(lpos); //and print the desired messages
						i++;
					}
			}
			
			//entering stage is over, we may call the remaining functions
			StopUp(baseptr,fl_cap); 
			
			StopDown(baseptr,opc); //put them in staircase
			
			empty_all(flptr); //empty staircase
		}
		
		~Staircase(){ //Destructor function
			cout << "No more ups and downs!" << endl;
			// for(int j=0;j<cap;j++){	
			// 	if(pl[j]!=NULL)
			// 		delete pl[j];
            //     //pl[j]=NULL;
			// }
			 delete[] pl;
		}
};

class Building: public Space{   
	
	private:
		int flr_cap,grl_cap,class_cap,strc_cap,students_num,L; //capacities

		GroundFloor* grl; //Building's groundfloor
		Floor* flbaseptr;   //Pointer to groundfloor's mother
		Staircase* strc; //Building's Staircase
		Space* baseptr;   //pointer to the mother
		Floor* fl[3];  //A building has 3 Floors
		Space* Baseptrs[3]; //pointer array to the mothers
		Person** pl_in_build; //array that stores all the Persons in a building
		int operate_cycles;
		int pl_count; //how many people are in a building
	//finised_counter is how many people finished their work in their classes.At the exiting stage, we will run a loop for finised_counter people.
		int finised_counter;
		int flag;
	public:
	//Constructor function
		Building(int bldc, int flrc, int grlc, int clrc, int str_cp, int std_num, int fL ):Space(bldc),flr_cap(flrc),grl_cap(grlc),class_cap(clrc),strc_cap(str_cp),students_num(std_num),operate_cycles(fL){ 
			cout << "A new building is ready for serving students and teachers!" << endl;
			
			grl= new GroundFloor(grlc);
			strc= new Staircase(strc_cap);
			for(int i=0; i<3;i++){
				fl[i]= new Floor(flrc,clrc,i+1);
			}
			for(int i=0; i<3;i++){
				Baseptrs[i]= fl[i];
			}

			pl_in_build=new Person*[bldc];
			for(int j=0;j<bldc;j++){
				pl_in_build[j]=NULL;
			}
			
			pl_count=0;
			finised_counter=0;
			baseptr=strc;//staircase
			flbaseptr=grl;		
		}
	
		void exit(Person* pl){ //exit function prints the desired messages 
				cout<<"I cannot believe I finished!" << endl;
				pl->print_prio();
		}
		
		void operate(){ //operate is used to call Staircase's operate and remove those that finished
			finised_counter=strc->operate(flbaseptr,Baseptrs,grl_cap,flr_cap,operate_cycles); //Staircase operate will return(through empty_all function) how many finished 
			
			for(int i=0; i<finised_counter;i++){ //removing those that finished
				Person* temp=flbaseptr->exit(1);
				exit(temp);
			}
		}
		
		void enter(Person* pl, int c,int flag){ //enter function to place the Persons inside the building and forbid from entering those who can't fit
				//cout << "whyyyyyyyy" << endl;
				if(c<cap){ //if he can fit put him in a array
					pl_in_build[c]=pl;
					pl_count++;
				}

				if(c>cap){ //if he can't fit print the desired message
					cout << "Please, come tomorrow." << endl;
				}
			
				if(c==students_num-1 +18 && flag == 1){ //if the counter is equal to the people's number then we did all the necessary work for every Person
					//cout << "whyyyyyyyy" << endl;
					for(int i=0;i<pl_count;i++){ //now for those that managed to fit, place them in the groundfloor 
						//if(i>17)
							flbaseptr->enter(pl_in_build[i],i,pl_count,0);
						 //else
						// 	fl[pl_in_build[i]->get_floor()-1]->get_class_from_fl(pl_in_build[i]->get_classroom()-1)->enter(pl_in_build[i]);
					}
				}
		}
			
		~Building(){ //Destructor function
			 for(int i=0;i<3;i++){
			 	delete fl[i];	
			 }
			 delete strc;
			 delete grl;
			 cout << "Service not available any longer. Go elsewhere!" << endl;
			//   for(int j=0;j<cap;j++){
			// 	  if(pl_in_build[j]!=NULL)
			//   			delete pl_in_build[j];
			//   	//pl_in_build[j]=NULL;
			//   }
			//  delete [] pl_in_build;
		}
};


// Initialize array of pointer names
    const char *names[24] = { "James", "John", "Robert", "Michael" ,"William","David","Richard","Joseph","Thomas","Charles","Daniel","Aris"
	,"Mary" , "Elizabeth", "Helene" , "Catherine" , "Sophie" , "Georgia" , "Tatiana" , "Penelope", 
    "Corina" , "Sandra" , "Ismene" , "Christine"};


int main(int argc, char* argv[]){
	// ./myprogram 3 5 2 5 11
	srand(time(NULL));
	
	int building_capacity=999,floor_capacity=999,groundfloor_capacity=999,staircase_capacity=999,L=3; //the command line arguments 
	int Cclass,Lj,Ls,Lt,N;

	if(argc < 2){  				
        cout<<"Error of argc!"<<endl;
    }
    else{
        Cclass = atoi(argv[1]);		
        Lj = atoi(argv[2]);		
        Ls = atoi(argv[3]);		
        Lt = atoi(argv[4]);	
		N = atoi(argv[5]);	//students num				
    }

	int class_capacity=Cclass;
	int students_num=11; ////

	Person **pl = new Person *[18+students_num];

	for(int i=0; i<18;i++){ //give every visitor a floor and office preference
		int cl_number=i%6+1;
		int fl_number= i/6 + 1;
		short length = rand()%24;
		pl[i]=new Teacher(cl_number,fl_number,2,names[length],Lt);
	}

	for(int i=18; i<students_num+18;i++){ //give every visitor a floor and office preference
		int fl_number=rand()%3+1; 
		int cl_number=rand()%6+1;
		short length = rand()%24;
		int flag_tier;
		if(cl_number%2 == 0){
			flag_tier = 0;//junior
			pl[i]=new Student(cl_number,fl_number,flag_tier,names[length],Lj);
		}else{
			flag_tier = 1;//senior
			pl[i]=new Student(cl_number,fl_number,flag_tier,names[length],Ls);
		}
	}
	
	Building School(building_capacity,floor_capacity,groundfloor_capacity,class_capacity,staircase_capacity,students_num,N); //constructing the building
	Space* Sch=&School; //pointer to the mother
 	//
	for(int a=0; a<18; a++){ //placing the visitors in the building
	  	Sch->enter(pl[a],a,1);
	  }

	for(int a=18; a<students_num+18; a++){ //placing the visitors in the building

		Sch->enter(pl[a],a,1);
	}   
		
	 for(int fun=0;fun<5;fun++){ //calling operate function for the students that were left outside the class(Not for incrementing tireness values)
		
	 	Sch->operate();
	 }	  
	
	for(int i=0;i<students_num;i++){ //deleting visitor objects
		delete pl[i];
	}
	delete[] pl;
}
