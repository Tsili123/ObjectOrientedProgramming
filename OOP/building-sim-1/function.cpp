
#include <iostream>
#include <cstdio>
#include "classes.hpp"

using namespace std;


// ============================================||  S T U D E N T   F U N C T I O N S  ||============================================ 

student::student(const short fl, const short shcl, const unsigned int pr ,string name2,const short index) 
: floor(fl), school_class_num(shcl), priority(pr) , index_loc(index) {
      printf("constructor for student\n");
      name = new string(name2);//dynamic allocate space for string
      cout << *name << "\n" << endl;
  } //initializer list

student::student::~student(){
    delete name;
}

unsigned int student::get_priority() const { return priority; }

short student::get_school_class_num() const { return school_class_num; }

short student::get_floor() const { return floor; }

string student::get_name() const { return *name; }

short student::get_index_loc() const { return index_loc; }

// ============================================||  W A I T I N G   R O O M    F U N C T I O N S  ||============================================ 

waiting_room::waiting_room(int size_var) : curr(0),size(size_var) {
   //students= new queue<student*> q(size);
   //queue<student*> students(size);
   students = new queue<student*> (size);
}

waiting_room::~waiting_room() { 
  delete students;
  std::cout << "End of waiting students!\n"; 
}

void waiting_room::enter(student* stds) {
  curr++;
  students->push(stds);
  printf("Entered waiting room\n");
}
//
student* waiting_room::exit() {
  student* stds=students->front();      // Get and return the front student in queue
  students->pop();
  curr--;
  printf("Exited waiting room\n");
  return stds;
}

queue<student*>* waiting_room::get_queue(void) const { return students; }

student* waiting_room::get_front(void) const { return students->front(); }

unsigned int waiting_room::get_size_curr(void) const { return curr; }


// ============================================||  B U I L D I N G   F U N C T I O N S  ||============================================ 

building::building(const unsigned int cap_class, const unsigned int cap_yard,
 const unsigned int cap_stairs, const unsigned int cap_corr,const unsigned int num_stds)
:  curr(0) {

    std::cout << "A new building is ready for students and teachers !\n\n";
    yard_addr = new school_yard(cap_yard, this);
    std::cout << "A school yard has been created with number 0!\n";
    fl = new floor*[3];
    
    for (short i = 0; i < 3; i++){
        fl[i] = new floor(cap_yard,i+1,cap_corr,cap_class);
        std::cout << "A floor has been created with number " << i+1 << "!\n";
    } 

    //corridors are created at the floor's class
    
     strc = new staircase(cap_stairs ,fl ,yard_addr);
     std::cout << "A staircase has been created!\n";
}    

 building::~building() {
  delete strc;
  for (short i = 0; i < 3; i++)
    delete fl[i];
  delete[] fl;
  delete yard_addr;
  std::cout<<"Service not available any longer!\n";
} 

 void building::enter (student* stds) {
  if (yard_addr->enter(stds) == false)
    std::cout << "Please, come tomorrow. P: " << stds->get_priority() << std::endl;
  else {
    curr++;
    std::cout << "A new student wants to go to floor " << stds->get_floor()
              << " and class " << stds->get_school_class_num() << " with Priority "
              << stds->get_priority() << std::endl; 
  }
}

void building::exit(student* stds) {
  --curr;
  std::cout << "\n\"I can't believe I finished!\" - " 
            << "F: " << stds->get_floor() << "  C: " << stds->get_school_class_num()
            << "  P: " << stds->get_priority() << " " << std::endl;
}

school_yard* building::get_yard_addr(void) const { return yard_addr; }

staircase* building::get_staircase(void) const { return strc; } 


// ============================================||  S C H O O L   Y A R D   F U N C T I O N S  ||============================================ 

school_yard::school_yard(const int Ny, building *const bldg)
: cap(Ny), curr(0), bld(bldg) 
{
  wr  = new waiting_room(cap);
  std::cout << "The school yard has been created!\n";
}

school_yard::~school_yard(){ 
  delete wr;
  std::cout << "End of school service!\n";
}

waiting_room* school_yard::get_wr(void) const { return wr; }

unsigned int school_yard::get_cap() const { return cap; }

unsigned int school_yard::get_curr() const { return curr; }

bool school_yard::enter(student* stds) {
  if (get_curr() == get_cap())            // If the school yard has as many students as its maximum capacity, entry is prohibited
    return false;
  curr++;
  wait(stds);
  return true;
}

void school_yard::wait (student* stds) {
  string var = stds->get_name(); 
  wr->enter(stds); 
  std::cout << "Student named " << var << " entered schoolyard !\n";
  }

/* void school_yard::exit(student *stds){
  --curr;
  std::cout << "Student named" << var << " exited schoolyard !\n";
  wr->exit(stds);
} */

 void school_yard::exit(student *stds){
  --curr;
  string var = stds->get_name();
  std::cout << "Student named " << var << " exited schoolyard !\n";
  bld->exit(stds);
} 


//============================================||  S T A I R C A S E   F U N C T I O N S  ||============================================

staircase::staircase(const unsigned int cap_stairs,  floor **const fl_arr,  school_yard*const  schy_num)
: cap(cap_stairs) , fl(fl_arr) , schy(schy_num), curr(0) {
   wr  = new waiting_room(cap);
   std::cout << "The staircase has been created!\n";
}

staircase::~staircase() { 
  delete wr;
  std::cout << "No more ups and downs!\n"; }

bool staircase::enter(student *stds) {
  if (get_curr() < get_cap()) {
    //students.push(stds);
    wr->enter(stds);
    curr++;
    std::cout << "Student " << stds->get_name() << " in the staircase!" << endl;
    return true;
  }
  std::cout << "You are not allowed to enter!\n" << "Your priority is: "
            << stds->get_priority() << endl;
  return false;
}

 void staircase::exit(student *stds) {
   --curr;
   std::cout << "Student " << stds->get_name() << " exited the staircase!" << endl;
   schy->exit(stds);
 }

 void staircase::stop_down() {

  for (short fl_num = 3; fl_num >= 1; --fl_num) {
    floor *flr = fl[fl_num-1];
    std::cout << "Going down to floor " << fl_num  << std::endl;
    unsigned int gap = get_cap() - get_curr();                      // Review how many students can fit in the staircase each time
    //and get them out of floor
    for (unsigned int i = 0; i < gap  && (flr->get_curr() != flr->get_wr()->get_size_curr()) ; ++i)    //  If the floors have people inside, get them out
    //(actually if classes have people inside,that is what the second condition tell us)
    //when students pass floor structure without staying , current counter increases but waiting room counter is staying same
    //its a way of knowing how many people have passed from floors to corridor and eventually to classes
    {//the second condition is error checking,basically means push as many students as you can from floor to staircase

      enter(flr->exit());         //  Push them in the staircase
     } 
  }
} 

void staircase::stop_up() {

  for (short cur_fl = 1; cur_fl <= 3; ++cur_fl){
    std::cout << "Elevating up to floor " << cur_fl << std::endl;

  //This is being done to prevent people from being stuck in the staircase(waiting room)
  //example:if we found their floor but there wasnt space for them

  //floor doesn't have capacity,so students can't be stuck in the staircase when elevating

  // for (unsigned int i = 0, max = fl[cur_fl-1]->get_wr()->get_stds().size(); i < max; ++i){
  //     student *stds = fl[cur_fl-1]->get_wr()->exit();      //  Get them out
  //     floor *flr = stds->get_floor();//fl[cur_fl-1]->get_floor(stds->get_floor_num());
  //     if (flr->enter(stds) == false)   //  But if they get rejected
  //       fl[cur_fl-1]->get_wr()->enter(stds);   // Put them back in the staircase(waiting room) 
  //   }

     for (unsigned int i = 0, max = wr->get_size_curr(); i < max; ++i){
       student *stds = wr->get_front();
       wr->exit();//exit staircase
       curr--;
       cout << "(from the staircase) when elevating\n" << endl;
       if (!(stds->get_floor() == cur_fl && fl[cur_fl-1]->enter(stds)))   // If a student's choice is to get in the current floor, he tries to enter
       {
          wr->enter(stds);// we should go there when students haven't reached their floor
          //floors have unlimited space so the second condition of if is just error checking
          curr++;
          cout << "Student " << stds->get_name() << " reentered staircase from floor\n" << endl;
          //enter(stds);
       } 
     } 
   }
}

 void staircase::operate() { //problem:some people might be stuck at the floors!!!
  
  //This code block fills the staircase with school yard student's pool
  //If the staircase  fills then it doesn't get more students from yard
  //or until school yard empties.After both cases,we have to perform staircase operation

  while (((schy->get_wr()->get_size_curr())>0)){
     while (get_curr() < get_cap() && schy->get_wr()->get_size_curr()){  //  While current students are less than the staircase's maximum capacity
        student* stds = schy->get_wr()->exit();                                    //   and there are students waiting to get on the staircase
         cout << "Student "<< stds->get_name() <<" just exited school yard" << endl;
        if(!enter(stds))                                         // Try to put them in
            schy->get_wr()->enter(stds);                            // If not, put them back to the school yard
     }

     stop_up();                                                // Go all the way up 
     stop_down();                                              // Go all the way down(from floor to staircase)
     empty_stairs();                                              // Let the students leave(from staircase to yard and then out)

     //before we fill staircase with more students , students that have remained at the floors must finish
     //floorptr(i)->empty_floors();
  }
}
 
void staircase::empty_stairs() {        // students leave the staircase
  for (unsigned int i = 0, max = wr->get_size_curr();  i < max; i++)  
  { 
    student *stds = wr->get_front();
    wr->exit();
    cout << " (from the staircase )\n" << endl;
    exit(stds);
  }
}

unsigned int staircase::get_cap() const { return cap; }

unsigned int staircase::get_curr() const { return curr; }

// ============================================||  F L O O R   F U N C T I O N S  ||============================================ 

floor::floor(unsigned int cap_floor,const short num,unsigned int cap_c,unsigned int cap_f) 
: cap(cap_floor),number(num), curr(0)
{
  wr=new waiting_room(cap);
  shcl=new school_class*[6];
  for (short i = 0; i < 6; i++) shcl[i]=new school_class(i+1,cap_f);
  cr=new corridor(cap_c,number,shcl);
}

floor::~floor(){
  delete wr;
  delete cr;
  for (short i = 0; i < 6; i++) 
    delete  shcl[i];
  delete [] shcl;
  
  std::cout<<"End of floor!\n";
}

waiting_room* floor::get_wr(void) const { return wr; }

corridor* floor::get_corridor() const { return cr; }  

unsigned int floor::get_curr() const { return curr; }

unsigned int floor::get_cap() const { return cap; }

bool floor::enter(student *stds) {
  if (get_curr() < get_cap()) {         //  As long as current students are less than maximum capacity
        cout << "Student "<< stds->get_name() <<" just entered floor\n" << endl;
        if (get_corridor()->enter(stds) == false) {
          
           // If a student cannot have access to his preferred corridor, he enters the floor's waiting room
           wr->enter(stds); 
           cout << "entered floor waiting room " << endl;
           curr++;
           return true; 
       }else{
          curr++;
          cout << "entered corridor waiting room " << get_corridor()->get_curridor_num() << endl;
          return true;
       }
  }

  std::cout << "Sorry, corridor number " << number << " is full." << endl;
  std::cout << "Your priority is: " << stds->get_priority()  << endl;
  
  return false; 
}


student * floor::exit() {   //   returns a student from a corridor
  --curr;  
  
  //    if( get_corridor()->is_empty() == false ) {    // Care about an empty floor 
       return get_corridor()->exit();
}
/*
 void floor::empty_floors(){
    int i = get_curr();
    waiting_room* wr2 = get_wr();
    student* stds_var= wr2->get_front();
    //here we are emptying floors for the next staircase call
    while(i>0){
       if( get_corridor(i)->is_empty() == false ) {    // Care about an empty floor 
       return get_corridor(i)->exit();
     } 
      curr--;
    }
  } 
}*/


// ============================================||  C O R R I D O R   F U N C T I O N S  ||============================================ 

corridor::corridor(const unsigned int cap_cor, const short num,school_class**const  schptr) 
: number(num), cap(cap_cor),shcl(schptr), curr(0)
{
  std::cout << "corridor #" << number << " has been created\n";
  cr=new waiting_room(cap);
}

corridor::~corridor(){
  delete cr;
  std::cout<<"End of corridor!\n";
}

waiting_room* corridor::get_cr(void) const { return cr; }

school_class* corridor::get_school_class(const short shcl_n) const { return shcl[shcl_n -1]; }  //////

unsigned int corridor::get_cap() const { return cap; }

unsigned int corridor::get_curr() const { return curr; }

unsigned int corridor::get_curridor_num() const { return number; }

bool corridor::is_empty() { return (cr->get_size_curr() == 0); } 

bool corridor::is_full() { return (cr->get_size_curr() == cap); } 

bool corridor::enter(student *stds) {
  if (get_curr() < get_cap()) {         //  As long as current students are less than maximum capacity
    if (get_school_class(stds->get_school_class_num())->enter(stds) == false) 
        // If a student cannot have access to his preferred class, he enters the floor's corridor(waiting room)
        cr->enter(stds); 
      curr++;
    return true;
  }

  std::cout << "Sorry, corridor number " << number << " is full." << endl;
  std::cout << "Your priority is: "   << stds->get_priority()  << endl;
  
  return false;
}

 student * corridor::exit() {   //  returns a student from a school class
  
  student * sts=NULL;
  for(int i=1;i<=6;i++){
            if( get_school_class(i)->is_empty() == false ) {    // Care about an empty corridor 
                  --curr;  
                  cr->exit();
                  cout << "Student exited corridor \n" << endl;
                  return get_school_class(i)->exit();
        }
  }
  return sts;
   
}  


// ============================================||  S C H O O L   C L A S S   F U N C T I O N S  ||============================================ 

school_class::school_class(const short num,const unsigned int cap_f) 
: number(num), cap(cap_f)
{ 
    wr=new waiting_room(cap);
    std::cout << "school_class #" << number << " has been created\n";
}

school_class::~school_class() { 
  delete wr;
  std::cout << "End of the class(work)!\n"; }

bool school_class::is_empty() { return (wr->get_size_curr() == 0); } 

unsigned int school_class::get_cap() const { return cap; }

unsigned int school_class::get_school_class_num() const { return number; }

bool school_class::enter(student *stds) {
  if (wr->get_size_curr() == (unsigned int)(get_cap())){
    std::cout << "Please, wait in the corridor for entrance in the school_class. Your priority is: " << stds->get_priority() << endl;
    return false;
  } else {
    wr->enter(stds);
    std::cout << stds->get_name() << " entered school_class #" << number << endl;
    //wr->exit();
    return true;
  }
} 

 student *school_class::exit() { 
  cout << "Student exited class" <<endl;
  student *stds = wr->exit();       //  After the school_class visit, people are satisfied and ready to leave
  return stds;  
} 


