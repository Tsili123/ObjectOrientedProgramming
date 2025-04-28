/* ___________________________________________________________________________________________________________________________________________ */
/* ===========================================================||  C L A S S E S  ||=========================================================== */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#pragma once

#include "queue.hpp"
#include <string>

/* Declarations */
class student;
class couple;
class sequence_room;
class class_room;

/* ===========================================================||  S T U D E N T  ||=========================================================== */

class student
{
  const unsigned int priority; 
  string *name; 
  string *gender; 
  unsigned int class_num;//might change later 
  short int visited;
public:
  student(string gnd, const unsigned int pr,string name2,unsigned int class_n);
  ~student();
  unsigned int get_priority() const;
  short get_class_num() const;
  string get_name()const;
  string get_gender()const;
  short int get_place() const; 
  void set_place();
};


class couple{
    unsigned int male_num;
    unsigned int female_num;
    string *male_name;
    string *female_name;
    int curr;
    int size;
    public:
    //couple(student **stds,int size_1,int size_2,int capc,int classn,int mnum ,int fnum);
    couple(int classn);
    void insert_to_couple(student **stds,int index,int number);
    ~couple();
    void print_couple()const;
    unsigned int get_class_num()const;
    string get_fname(void)const;
    string get_mname(void)const;
    unsigned int get_female_num(void)const;
    unsigned int get_male_num(void)const;
};
// ===========================================================||  S E Q U E N C E   R O O M  ||=========================================================== 

class sequence_room
{
  unsigned int curr;  // Waiting room does not have maximum capacity
  unsigned int size;
  queue<couple*>* couples; 
public:
  sequence_room(int );
  ~sequence_room();
  void enter(couple*);
  couple* exit(); 
  unsigned int get_curr() const;
  queue<couple*>* get_queue(void) const;
  couple* get_front(void) const ;
  unsigned int get_size_curr(void) const;
  void print_sequence(void)const;
};

// ===========================================================||  C L A S S   R O O M  ||=========================================================== 

class class_room
{
  unsigned int curr;  // Waiting room does not have maximum capacity
  unsigned int size;
  queue<sequence_room*>* sequence_rooms; 
public:
  class_room(int );
  ~class_room();
  void enter(sequence_room*);
  sequence_room* exit(); 
  unsigned int get_curr() const;
  queue<sequence_room*>* get_queue(void) const;
  sequence_room* get_front(void) const ;
  unsigned int get_size_curr(void) const;
  void print_class(void)const;
};
