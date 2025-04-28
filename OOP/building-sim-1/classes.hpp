/* ___________________________________________________________________________________________________________________________________________ */
/* ===========================================================||  C L A S S E S  ||=========================================================== */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#pragma once

#include "queue.hpp"
#include <string>

/* Declarations */
class student;
class waiting_room;
class building;
class school_yard;
class staircase;
class floor;
class corridor;
class school_class;

/* ===========================================================||  S T U D E N T  ||=========================================================== */

class student
{
  const short floor;
  const short school_class_num;
  const unsigned int priority; 
  string *name; 
  const short index_loc;
public:
  student(const short fl, const short shcl, const unsigned int pr, string name,const short index_loc);
  ~student();
  unsigned int get_priority() const;
  short get_school_class_num() const;
  short get_floor() const;
  short get_index_loc()const;
  string get_name()const;
};

// ===========================================================||  W A I T I N G    R O O M  ||=========================================================== 

class waiting_room
{
  unsigned int curr;  // Waiting room does not have maximum capacity
  unsigned int size;
  //template <student*>
  queue<student*>* students; 
  //queue* students;
  //std::queue<student*> students; 
public:
  waiting_room(int );
  ~waiting_room();
  void enter(student*);
  student* exit(); 
  unsigned int get_curr() const;
  queue<student*>* get_queue(void) const;
  student* get_front(void) const ;
  unsigned int get_size_curr(void) const;
};

// ===========================================================||  B U I L D I N G  ||=========================================================== 

class building
{  
  unsigned int curr;       
  school_yard * yard_addr; 
  floor ** fl; //floors pointer
  staircase * strc;
public:
  building(const unsigned int cap_class, const unsigned int cap_yard,
 const unsigned int cap_stairs, const unsigned int cap_corr,const unsigned int num_stds);  
  ~building();                                
  void enter(student *);
  void exit(student *);
  staircase * get_staircase() const;
  school_yard * get_yard_addr() const;
};

// ===========================================================|| S C H O O L   Y A R D   ||=========================================================== 

class school_yard
{
  const unsigned int cap; // cap  == capacity 
  unsigned int curr;      // curr == current # of students inside 
  building* const bld;  
  waiting_room* wr;
public:
  school_yard(const int , building *const);
  ~school_yard();
  bool enter(student*);
  void exit(student*);
  void wait(student*);
  unsigned int get_cap() const;
  unsigned int get_curr() const;
  waiting_room* get_wr() const;
};

// ===========================================================||  S T A I R C A S E  ||=========================================================== 

class staircase
{
  const unsigned int cap;
  floor **const fl;
  school_yard *const schy;
  unsigned int curr;
  waiting_room* wr;
  bool enter(student *);     
  void exit(student *);   
  void empty_stairs(); 
  void stop_up();
  void stop_down();
public:                          
  staircase(const unsigned int  , floor **const , school_yard *const);    
  ~staircase();
  void operate();
  unsigned int get_cap() const;
  unsigned int get_curr() const;
};

 // ===========================================================||  C O R R I D O R ||=========================================================== 

class corridor
{
  const short number; // [1,3]
  const unsigned int cap; 
  school_class** shcl;
  unsigned int curr;
  //floor* fl;
  waiting_room* cr;
  
public:
  corridor(const unsigned int Nf, const short num,school_class**const  schptr);
  ~corridor();
  bool enter(student *);    
  student *exit();
  unsigned int get_cap() const;
  unsigned int get_curr() const;
  waiting_room* get_cr(void) const;
  school_class *get_school_class(const short school_class_n) const;
  unsigned int get_curridor_num() const ;
  bool is_empty();
  corridor* get_corridor(const short corr_n) const;
  bool is_full() ;
}; 
// ===========================================================||  F L O O R  ||=========================================================== 

class floor
{
  unsigned int cap;
  const short number; // [1,4]
  unsigned int curr;  // floor does not have maximum capacity 
  waiting_room* wr;
  corridor *cr;
  school_class** shcl;
public:
  floor(unsigned int cap_floor,const short num,unsigned int cap_c,unsigned int cap_f);
  ~floor();
  bool enter(student *);   
  student* exit(); 
  unsigned int get_curr() const;
  waiting_room* get_wr(void) const;
  unsigned int get_cap() const; 
  corridor* get_corridor() const; 
  void empty_floor() ;
  //corridor *corridor::get_corridor(const short corr_n) const;
  //std::queue<student*> get_stds() const;
};




// ===========================================================||  S C H O O L   C L A S S  ||===========================================================

class school_class
{
  const short number; //[1,6]
  const unsigned int cap;
  waiting_room* wr;
public:
  school_class( const short num,const unsigned int );
  ~school_class();
  bool enter(student *);
  student *exit();
  unsigned int get_cap() const;
  bool is_empty();
  unsigned int get_school_class_num() const;
};

// =============================================================||  END OF FILE  ||============================================================== 
