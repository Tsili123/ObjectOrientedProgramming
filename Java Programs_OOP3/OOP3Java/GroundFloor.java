public class GroundFloor extends Floor {
	
        private Corridor grl_corridor; //groundfloor's corridor
        private Space baseptr; //pointer to the mother
        private Person[] pl_ground; //array that stores all the people in a ground floor 
        private Person[] pl_finished; //array that stores all the people who finished their work from their offices
        private int grl_count; //how many people are in a groundfloor
            
        public GroundFloor(int grlc){  //Constructor function
                super(grlc,0,0);
                System.out.println("A Ground Floor has been created");
                grl_corridor = new Corridor(grlc);
                
                pl_ground= new Person [grlc];
    
                for(int j=0;j<grlc;j++){
                    pl_ground[j]=null;
                }
                
                pl_finished= new Person[grlc];
    
                for(int j=0;j<grlc;j++){
                    pl_finished[j]=null;
                }
                
                baseptr = grl_corridor;
                grl_count=0;
            }
            
        public void wait(Person pl ,int a){ 
                //wait function gives a Person his priority and places him inside groundfloor's corridor 
                 pl.set_prio(a+1);
                 System.out.printf("Waiting for the lift ");
                 pl.print_prio();
                 grl_corridor.enter(pl);
                
            }
            
        public void enter(Person pl, int n, int b, int l ){ 
                //enter function to place the people inside the corridor and forbid from entering those who can't fit
                if(l==0){   //if the Person goes from the building to the groundfloor
                    if(n<cap){ //if he can fit put him in a array
                        pl_ground[n]=pl;
                        grl_count++;
                    }
    
                    if(n>=cap){ //if can't fit print the desired message
                        System.out.println("Sorry, you can't fit in the ground floor.");
                    }
    
                    if(n==b-1){ //if the counter is equal to the building counter then we did all the necessary work for every Person
                    // (who went in the building) 
                        for(int i=0;i<grl_count;i++){ //call the wait function for those that fit in the groundfloor
                            wait(pl_ground[i],i);
                        }
                    }
                }
                
                if(l==1){ //if the Person is returning from the staircase to the groundfloor place him in a different array 
                    int i; 
                    for(i=0;i<cap;i++){
                        if(pl_finished[i]==null){
                            pl_finished[i]=pl;
                            break;
                        }
                    }
                }
            }
            
               
            public Person exit(int l){ //exit function removes a Person 
                 
                Person temp=null;

                if (l==0){ //if the Person goes from the groundfloor to the staircase remove him from the groundfloor's corridor
                    return grl_corridor.exit(0,0);
                }
    
                if(l==1){  
                    //if the Person goes from the groundfloor to the building 
                    //(when he has finished, that is) remove him from the pl_finished array
                    
                    int i;
                    for(i=0;i<super.cap;i++){
                        if(pl_finished[i]!=null){
                            temp=pl_finished[i];
                            pl_finished[i]=null;
                            return temp;
                        }
                    }
                }		
                return temp;
            }
            
            public void print_prio(int y){ 
                //function to print Person's priority 
                grl_corridor.print_prio(y,0,0);
                 //(this is used in the staircase's entering stage 
                 //so the Person won't have to leave the corridor only to enter it again)
            }
            
            public int get_grl_count(){ 
                //getting how many people are in a groundfloor
                return this.grl_count;
            }		
              
            public void grl_dec_counter(){ 
                //function to decrement groundfloor's counter
                this.grl_count--;
            }
}
