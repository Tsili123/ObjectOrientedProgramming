#include <iostream>
#include <cstdio>
#include <chrono>
#include "classes.hpp"
#include <random>
//#include <vector>
#include <iomanip>
#include <stdlib.h>

using namespace std;

string randomName(int length) {

  char consonents[] = {'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','z'};
  char vowels[] = {'a','e','i','o','u','y'};

  string name = "";

  int random = rand() % 2;
  int count = 0;

  for(int i = 0; i < length; i++) {

    if(random < 2 && count < 2) {
      name = name + consonents[rand() % 19];
      count++;
    }
    else {
      name = name + vowels[rand() % 5];
      count = 0;
    }

    random = rand() % 2;

  }

  return name;
}

int main(int argc, char const *argv[])
{
  if (argc != 6) {  // Error check 
    std::cerr << "\nUsage:\n" << argv[0] 
    << " <class_cap> <yard_cap> <stairs_cap> <corridor_cap> " 
    << " <number_of_students> \n" << std::endl;
    exit(EXIT_FAILURE); 
  }

  srand(time(NULL));
  
  unsigned int cap_class = atoi(argv[1]);
  unsigned int cap_yard = atoi(argv[2]);
  unsigned int cap_stairs = atoi(argv[3]);
  unsigned int cap_corr = atoi(argv[4]);
  unsigned int num_stds = atoi(argv[5]); 

  /* Generate students required */
  mt19937 randomGen(chrono::steady_clock::now().time_since_epoch().count());      
  uniform_int_distribution<short> rnd3(1,3),rnd6(1,6),rnd15(8,15);

  // create students(array with student class elements)
  student **stds = new student *[num_stds];
  for (unsigned int i = 0; i < num_stds; ++i) {
    short fl  = rnd3(randomGen); 
    short shcl = rnd6(randomGen); 
    short length = rnd15(randomGen);
    string str = randomName(length);
    //index of location is initialized as 0 meaning the students just entered the building
    stds[i]  = new student(fl, shcl, i+1,str,0);
  }

  // Create a building, all students attempt to enter 
  building *school = new building(cap_class, cap_yard, cap_stairs, cap_corr, num_stds);

  for (unsigned int i = 0; i < num_stds; ++i)
    school->enter(stds[i]);

  school->get_staircase()->operate();  // Get the staircase going 

  // Cleanup section 
  delete school;

  for (unsigned int i = 0; i < num_stds; ++i)
    delete stds[i];
  delete[] stds;
  return EXIT_SUCCESS;
}