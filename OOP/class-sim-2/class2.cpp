#include <iostream>
#include <cstdio>
#include "class2.hpp"

using namespace std;

// ============================================||  S T U D E N T   F U N C T I O N S  ||============================================ 

student::student(string gnd, const unsigned int pr,string name2,unsigned int class_n) 
:priority(pr) , class_num(class_n) {
      printf("constructor for student\n");
      name = new string(name2);//dynamic allocate space for string(could have been with reference)
      cout << *name << endl;
      gender = new string(gnd);//dynamic allocate space for string
      cout << *gender << endl;
      cout << class_num << endl;
      visited=0;
  } //initializer list

student::student::~student(){
    delete name;
    delete gender;
}

unsigned int student::get_priority() const { return priority; }

short student::get_class_num() const { return class_num; }

short int student::get_place() const { return visited; }

void student::set_place() {  visited=1; }

string student::get_name() const { return *name; }

string student::get_gender() const { return *gender; }

// ============================================||  P A I R    F U N C T I O N S  ||============================================ 


couple::couple(int classn) : curr(classn) {

  male_name = new string("empty");
  male_num=999;

  female_name = new string("empty");
  female_num=999;

}


void couple::insert_to_couple(student **stds,int index,int number){

    if((stds[index]->get_gender()).compare("female")==0){
            delete female_name;
            female_name = new string(stds[index]->get_name());
            female_num = number;
    }else if((stds[index]->get_gender()).compare("male")==0){
            delete male_name;
            male_name = new string(stds[index]->get_name());
            male_num = number;
    }
}

couple::~couple() { 
  delete male_name;
  delete female_name;
  std::cout << "End of waiting couples!\n"; 
}

void couple::print_couple()const{
  cout << "male " << *male_name << " num " << male_num << " female " << *female_name << " num " << female_num << " class num " << curr << endl;
}

unsigned int couple::get_class_num()const{
  return curr;
}

unsigned int couple::get_male_num(void)const{
  return male_num;
}

unsigned int couple::get_female_num(void)const{
  return female_num;
}

string couple::get_mname(void)const{
  return *male_name;
}

string couple::get_fname(void)const{
  return *female_name;
}


// ============================================||  S E Q U E N C E   R O O M    F U N C T I O N S  ||============================================ 

sequence_room::sequence_room(int size_var) : curr(0),size(size_var) {
   couples = new queue<couple*> (size);
}

sequence_room::~sequence_room() { 
  delete couples;
  std::cout << "End of waiting couples!\n"; 
}

void sequence_room::enter(couple* prs) {
  curr++;
  couples->push(prs);
  printf("Entered waiting room\n");
}
//
couple* sequence_room::exit() {
  couple* prs=couples->front();      // Get and return the front student in queue
  couples->pop();
  curr--;
  printf("Exited waiting room\n");
  return prs;
}

queue<couple*>* sequence_room::get_queue(void) const { return couples; }

couple* sequence_room::get_front(void) const { return couples->front(); }

unsigned int sequence_room::get_size_curr(void) const { return curr; }

void sequence_room::print_sequence(void)const{
    
    couples->print_sq();
}

// ============================================||  C L A S S   R O O M    F U N C T I O N S  ||============================================ 

class_room::class_room(int size_var) : curr(0),size(size_var) {
   sequence_rooms = new queue<sequence_room*> (size);
}

class_room::~class_room() { 
  delete sequence_rooms;
  std::cout << "End of waiting sequence_rooms!\n"; 
}

void class_room::enter(sequence_room* prs) {
  curr++;
  sequence_rooms->push(prs);
  printf("Entered waiting room\n");
}
//
sequence_room* class_room::exit() {
  sequence_room* prs=sequence_rooms->front();      // Get and return the front student in queue
  sequence_rooms->pop();
  curr--;
  printf("Exited waiting room\n");
  return prs;
}

queue<sequence_room*>* class_room::get_queue(void) const { return sequence_rooms; }

sequence_room* class_room::get_front(void) const { return sequence_rooms->front(); }

unsigned int class_room::get_size_curr(void) const { return curr; }

void class_room::print_class(void)const{
   
    sequence_rooms->print_cl();
}


