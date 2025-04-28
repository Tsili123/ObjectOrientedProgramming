#include <iostream>
#include <cstdio>
#include <chrono>
#include "class2.hpp"
#include <random>
#include <iomanip>
#include <stdlib.h>


using namespace std;


int main(int argc, char const *argv[])
{


     // Initialize array of pointer names
    const char *male_names[12] = { "James", "John", "Robert", "Michael" ,"William","David","Richard","Joseph","Thomas","Charles","Daniel","Aris"};

    const char *female_names[12] = { "Mary" , "Elizabeth", "Helene" , "Catherine" , "Sophie" , "Georgia" , "Tatiana" , "Penelope", 
    "Corina" , "Sandra" , "Ismene" , "Christine"};

  if (argc != 4) {  // Error check 
    std::cerr << "\nUsage:\n" << argv[0] 
    << " <number_of_students> <class_cap> <class_num>\n" << std::endl;
    exit(EXIT_FAILURE); 
  }
  
  unsigned int num_stds = atoi(argv[1]);
  unsigned int cap_class = atoi(argv[2]);
  unsigned int num_class = atoi(argv[3]);      
  unsigned int limit = ceil(num_stds/num_class);
  unsigned int gender_var = 1, name_var ,class_var=0,class_num=1,flag=0,total=0; // 1 for boys , 0 for girls
  string *str,*str2;
  
  //ignore
  std::cout << "Every class can fit " << limit << " students\n" << endl;
  
  // Generate index for students 
  mt19937 randomGen(chrono::steady_clock::now().time_since_epoch().count());      
  uniform_int_distribution<short> rnd12(0,11);

  // create students(array with student class elements)
  student **stds = new student *[num_stds];
  
  for (unsigned int i = 0; i < num_stds; ++i) {
    name_var  = rnd12(randomGen); 
    if(gender_var==1){
        str = new string(male_names[name_var]);
        str2 = new string("male");
        gender_var = 0;
    }else if(gender_var==0){
        str = new string(female_names[name_var]);
        str2 = new string("female");
        gender_var = 1;
    } 
    
    if(class_var == cap_class){
      class_var=0;
      class_num++;
    }

    if(class_num == num_class+1 ){
        flag=1;
        break;
    }
    else
      class_var++; //find how many classes needed
    total++;//create students
    stds[i] = new student(*str2,i+1,*str,class_num);

    delete str;
    delete str2;
  }

  // create students(array with student class elements)
  unsigned int num_couples = ceil(num_stds/2);
  couple **cpls = new couple *[num_couples];
  unsigned int mnum=1,fnum=2,flagm=3,flagf=1,swap,k=0;//,flagg=0;
  //int flag1=0,flag2=0;
  
  if(flag==1){
    class_num -= 1;
  }

  cout << class_num << endl;
  cout << total << endl;
  unsigned int j,i,l=0,c=0;
  
  if (cap_class%2==0){//for even number capacity of class
       for (i = 0; i < total; i++){

        if(i%2==0 && i>0 ){// if we reach even number of students , change couple
            swap = flagm;
            flagm = flagf;
            flagf = swap;            
          }

          if(i%2==0){
            cpls[k] = new couple(c);
            k++;
          }
          
          l++;
          if(l==cap_class){//change class
            l=0;
            c++;
          }

          if(i==cap_class  || (i % cap_class==0 && i>0)){ //reset female,male number
            swap = mnum;
            mnum = fnum;
            fnum = swap;

            swap = flagm;
            flagm = flagf;
            flagf = swap; 
          }
          
           if(i%2==0){//i is even , so it is a boy
              cpls[k-1]->insert_to_couple(stds,i,mnum);
              mnum += flagm; 
          }else{//then it's odd , so it is a girl
              cpls[k-1]->insert_to_couple(stds,i,fnum);
              fnum += flagf;
          }
          
       }
  }else{
      // capacity is odd number
       int fh=0;
       
      for (i = 0; i < total; i++){
          //basically in this condition,because we have odd capacity ,we need to change couple starting from a different number each time
          //for example with a capacity 5,we start from num student (0),2,4 | (5),7,9 | (10),12,14
          //parenthesised means the student number in the array.As we see each time the starting number switches from even to odd
          //it wirks for some iterations but not always
           if((i%2==0  && fh==0  && i>0 && c==0) ||(i%2==1  && fh==1  && c>0)){
              swap = flagm;
              flagm = flagf;
              flagf = swap;
          } 

         if(i%2==1 && fh==1){
           //cout << "fh " << fh << endl;
           cpls[k] = new couple(c);
           k++;
           //fh=0;
         }

         if(i%2==0 && fh==0){
           //cout << "fh " << fh << endl;
           cpls[k] = new couple(c);
           k++;
         }


          if((i==(c+1)*cap_class-1) && fh==1){
            //cout << "inside2 " << i << endl;
            fh=0;
          }else if((i==(c+1)*cap_class-1) && fh==0){
            //cout << "inside1 " << i << endl;
            fh=1;
          }
          
          
           if((stds[i]->get_gender()).compare("male")==0){
              cpls[k-1]->insert_to_couple(stds,i,mnum);
              mnum += flagm;
          }else{
              cpls[k-1]->insert_to_couple(stds,i,fnum);
              fnum += flagf;
          }

            if(i==(c+1)*cap_class-1){//reset
              //cout << "mesaaaaa" << endl;
              mnum = k*2+1;
              fnum = k*2+2;

               //if(c%2==0 && c>0){
               if((stds[i-1]->get_gender()).compare("female")==0){
                  swap = flagm;
                  flagm = flagf;
                  flagf = swap;  
              } 
          }
           

          l++;
          if(l==cap_class){
            l=0;
            c++;
          }
           
         //cpls[k-1]->insert_to_couple(stds,i,555); 
      }
  }
//either ends as an odd
//or ends as full cap as an odd
//or ends as an even 



//just print the couples that have been created by students
cout << "k" << k <<endl;
 
    for (unsigned int i = 0; i<k;i++){
      cpls[i]->print_couple();
  }


  //create a queue that will contain the couples for each class
  //I used array wiht pointers instead of linked list
  //the queue also has been implemented with array and pointers as its element

   //make sequence
  sequence_room **sqs = new sequence_room *[class_num];
  //unsigned int l=0;
  l=0;

  for (i = 0; i<class_num;i++){
    sqs[i] = new sequence_room(cap_class);
    for(j=l;j<k;j++){
      l=j;
      if(cpls[j]->get_class_num()!=i)
        break;
      sqs[i]->enter(cpls[j]);
    }
  }

  // for (i = 0; i<class_num;i++){
  //  sqs[i]->print_sequence();
  //} 

  cout << "\n\n\n\n\n" << endl;
  class_room **classes = new class_room *[class_num];
  
  //connect sequence aka create classes
  //one class has one sequence , so one pointer contained inside
  for (i = 0; i<class_num;i++){
    classes[i] = new class_room(1);
    classes[i]->enter(sqs[i]);
  }

  for (i = 0; i<class_num;i++){
    cout << "\nclass number " << i << endl;
    classes[i]->print_class();
  } 
    

  //call destructors
   for (i = 0; i<class_num;i++){
    delete sqs[i];
    delete classes[i];
  } 
  delete [] sqs;
  delete [] classes;

  l=0;

//problem when delting couples

/*   for (i = 0; i<class_num;i++){
    for(j=l;j<k-1;j++){
      l=j;
      if(cpls[j]->get_class_num()!=i)
        break;
      delete cpls[j];
    }
  }
  delete [] cpls; */

  return EXIT_SUCCESS;
  //./class_sim 71 9 6
  //./class_sim 37 15 5
}