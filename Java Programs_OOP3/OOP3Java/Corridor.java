public class Corridor extends Space {
    private Person [] corridorarr; //array that stores all the people in the corridor
	private	int corridorct; //how many people are at corridor
    public Corridor(int size){ //Constructor function
            super(size);
			System.out.println("The Corridor has been created!"); 
			
            int i;
            corridorarr = new Person [size];
			for(i=0;i<size;i++){
				corridorarr[i]=null;
			}
			corridorct=0;
		}
    
    
	public void enter(Person pl){  // Corridor array takes a Person and places him at the first empty cell
			int i;
			for(i=0;i<super.cap;i++){
				if(corridorarr[i]==null){
                    //System.out.println("Entered!"); 
					break;
				}
			}
			corridorarr[i]=pl;
			corridorct++;
		}
		
		
    public	Person exit(int flnum,int classnum){  
        // Corridor exit removes the first Person (who was tired) from the array 
		// Arguments fl_num and class_num are used because the function behaves differently if we are exiting from a floor's corridor
        //works both ways
            

			if(flnum==0){ //exiting from groundfloor
				
				int i;
				Person temp=null;
				for(i=0;i<super.cap;i++){
					if(corridorarr[i]!=null){
                        //System.out.println("Exit");
                        temp=corridorarr[i];
                        // temp.print_prio();
						 corridorarr[i]=null;
						 
                         corridorct--;
                        return (Person)temp;
					}
                }
			}else if(flnum==1){  //exiting from floor
				Person temp=null;
				int j;
				for(j=0;j<super.cap;j++){
                    //making sure if the Person wants to go to the desired classroom
					if(corridorarr[j]!=null && corridorarr[j].get_classroom()==classnum){ 
                        temp=corridorarr[j];
				        corridorarr[j]=null;
                        corridorct--;	
						return temp;
					}
				}		
            }
            return null;
		}
		
        public	boolean get_class(int i){ //this function is used to ensure the Person wants to go to the office we are currently on
			boolean index=false;
			
			int j;
			for(j=0;j<super.cap;j++){
				if(corridorarr[j]!=null && corridorarr[j].get_classroom()==i){
					return true;
				}
			}
			return index;
		}
		
		public void print_prio(int n, int f, int i){ 
            //function to print Person's priority
            //again f and i arguments are used because it behaves differently if we are on the floor

			if (f==0){						 
				if (corridorarr[n]!=null){
					System.out.println("You are not allowed to enter!");
					corridorarr[n].print_prio();
				}
			}else if (f==1){
				if (corridorarr[n]!=null){
					System.out.println("Please wait outside office: " + i);
					corridorarr[n].print_prio();
				}
			}
		}
		
		public int get_corridor_count(){ //getting how many people are at an corridor
			return corridorct;
		}
		
}
