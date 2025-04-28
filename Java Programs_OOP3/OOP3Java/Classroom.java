public class Classroom extends Space{
    private int classnum;	//class_num member is the number of the Classroom
	private	int classcount; //how many people are in an Classroom
	private	Person[] people_of_class; //array that stores all the people in an Classroom
		
    public Classroom(int spc,int cln) { // constructor function
            super(spc);
            classnum = cln;
            System.out.println( "Classroom number " + this.classnum + " has been created."); 
            
            people_of_class = new Person[spc];
            for(int i=0;i<spc;i++){
				people_of_class[i] = null;
			}
			classcount=0;
		}
		
	public void enter(Person pl){ //Classroom enter takes a Person and places him in the first empty cell it finds
			int i;
			for(i=0;i<super.cap;i++){
				if(people_of_class[i]==null){
                    people_of_class[i]=pl;
			        classcount++;
					break;
				}
			}
        }
		
		public Person exit(){ //Classroom exit removes the first Person (who was tired) from the array 
            int i;
            Person temp = null;
			for(i=0;i<super.cap;i++){
				if(people_of_class[i]!=null && people_of_class[i].get_tireness()>0){
					temp=people_of_class[i];
					people_of_class[i]=null;
					classcount--;
					break;
				}
			}	
			return temp;	
        }
					
    public  void make_tireness(){ //this function sets a Person's tireness value to 1
            int i=0;
			for(i=0;i<super.cap;i++){
				if(people_of_class[i]!=null){
						people_of_class[i].set_tireness();
				}
			}
		}	
		
		public int get_class_count(){ //get how many people are in an Classroom
			return classcount;
		}
}
