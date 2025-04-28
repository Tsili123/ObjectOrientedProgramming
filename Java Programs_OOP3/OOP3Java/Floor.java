public class Floor extends Space{
    private int classcap; //class's capacity
    private int flnum; //this member is floor's number
    private int flcount; //how many people are in a floor
    private Corridor corridoroffloor; //floor's corridor 
    private Space baseptr; //pointer to the mother
    private Space[] Baseptrs = new Space[6]; //pointer array to the mothers
    private Classroom[] Cl = new  Classroom[6]; //every floor has 6 classes

        public Floor(int flc, int clcap, int fln){ //Constructor function
                super(flc);
                classcap = clcap;
                flnum = fln;
                if(this.flnum!=0){
                    System.out.println("A Floor has been created with number:" + this.flnum); 
                }
                    
                if(this.classcap!=0){ //don't create classrooms and corridor if capacity is zero (only in ground floor)
                    corridoroffloor= new Corridor(flc);
                    baseptr=corridoroffloor;	
                    
                    for(int i=0;i<6;i++){
                        Cl[i]= new Classroom(classcap,i+1);
                    }
    
                    for(int i=0;i<6;i++){
                        Baseptrs[i] = Cl[i];
                    }
                }
                
                flcount=0;
            }
            
            public int get_fl_num(){   //getting floor's number
                return this.flnum;
            }
            
            
            public void enter(Person pl, int a){ //floor enter places a Person in floor's corridor then proceeds to the entering stage of the class
                
                baseptr.enter(pl);//corridor
                flcount++;
            
                for(int i=0;i<6;i++){ //for every class
                    int vr = i +1;
                    if(Baseptrs[i].get_class_count() < this.classcap){ //if the Person fits in class
                        if(baseptr.get_class(i+1)){ //and if this is the class he wants to go to
                            
                            Person temp = baseptr.exit(1,i+1); //remove him from the corridor
                    
                            Baseptrs[i].enter(temp); //and place him in the class
                            System.out.println("Entering class with number: "+ vr) ; 
                            temp.print_prio();
                            break; //only one can enter at a time so if one person went in no need to continue the loop
                        }
                    }
                    else{ 
                        //print the desired messages if he couldn't fit
                        System.out.println("Please wait for outside in class: "+ vr + " ");
                        pl.print_prio(); 
                        break;
                    }
                }	
            }
           
            public Person exit(){ //floor exit function removes the first Person 
            //that was tired and also proceeds to enter those that wait in the corridor 
                
                Person cl_temp = null;
                Person pl_temp = null;
    
                for(int i=0;i<6;i++){ //for every floor
                    if(Baseptrs[i].get_class_count()!=0){ //if there is at least one person inside
                        if( (pl_temp=Baseptrs[i].exit()) != null ){ //if we managed to find someone
                        
                            cl_temp=pl_temp; //place him temporarily in a variable
    
                            flcount--;
    
                            for(int j=0;j<baseptr.get_corridor_count();j++){ 
    
                                //now check for every person in the corridor if he can go in the Class
                                if(Baseptrs[i].get_class_count() < classcap){ 
                                // if class count is less than its capacity 
                                    if( baseptr.get_class(i+1) ){ //if we find someone that wants this Class
                                        //cout << "mesaaaaaaaaaaaaaa" <<endl;
                                        Person temp; 
                                        temp=baseptr.exit(1,i+1); //remove him from the corridor
                                        Baseptrs[i].enter(temp); //and place him in that class
                                        System.out.println("Entering class number: " + i+1) ;
                                        temp.print_prio();
                                    }
                                }
                                else{ 
                                    //for those that couldn't enter yet again..
                                    baseptr.print_prio(j,1,i+1); 								
                                }
                            }
                            break; //we only return one Person at a time, so if we found somebody break the loop
                        }
                    }	
                }
                return cl_temp; //return the Person 
            }
         
            public    int get_fl_count(){ //getting how many people are in a floor
                return this.flcount;
            }
           
            public void make_tireness(){ //this function will go at every class that has at least one person inside and give him a tireness value
                for (int i=0; i<6; i++){
                    if(Baseptrs[i].get_class_count()!=0){
                        Baseptrs[i].make_tireness();			
                    }
                }
            }
            
            Classroom get_class_from_fl(int i){
                return  Cl[i];
            }
    
        
        void print_prio(int i){/*ok */} //ground floor has to inherit those functions
        int get_grl_count(){int c=0; return c;}
        void enter(Person p, int i, int j, int k ){/* ok */}
        Person exit(int i){Person p=null; return p;}
        void wait(Person p , int i){/*ok */}
        void grl_dec_counter(){/*ok */}
}
