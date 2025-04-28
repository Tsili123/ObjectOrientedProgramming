import java.util.Random;
/*
javac Building.java Staircase.java Corridor.java oop3.java Floor.java GroundFloor.java Classroom.java Space.java Student.java Teacher.java
*/
public class oop3{	
    public static void main(String []argv){

	// Initialize array of pointer names
    String names[] = { "James", "John", "Robert", "Michael" ,"William","David","Richard","Joseph","Thomas","Charles","Daniel","Aris"
	,"Mary" , "Elizabeth", "Helene" , "Catherine" , "Sophie" , "Georgia" , "Tatiana" , "Penelope", 
	"Corina" , "Sandra" , "Ismene" , "Christine"};

	int building_capacity=100,floor_capacity=100,groundfloor_capacity=100,staircase_capacity=100,L=3; //the command line arguments 
	int Cclass,Lj,Ls,Lt,N;

    Cclass = Integer.parseInt(argv[0]);		
    Lj = Integer.parseInt(argv[1]);		
    Ls = Integer.parseInt(argv[2]);		
    Lt = Integer.parseInt(argv[3]);	
	N = Integer.parseInt(argv[4]);	//students num				

	int class_capacity=Cclass;
	int students_num=11; ////

	Person [] pl = new Person [18+students_num];

	Random rand = new Random();	
	
	for(int i=0; i<18;i++){ //give every visitor a floor and office preference
		int cl_number=i%6+1;
		int fl_number= i/6 + 1;
		int length = rand.nextInt(24);
		pl[i]=new Teacher(cl_number,fl_number,2,names[length],Lt);
	}

	for(int i=18; i<students_num+18;i++){ //give every visitor a floor and office preference
		int fl_number=rand.nextInt(3)+1; 
		int cl_number=rand.nextInt(6)+1;
		int length = rand.nextInt(24);
		int flag_tier;
		if(cl_number%2 == 0){
			flag_tier = 0;//junior
			pl[i]=new Student(cl_number,fl_number,flag_tier,names[length],Lj);
		}else{
			flag_tier = 1;//senior
			pl[i]=new Student(cl_number,fl_number,flag_tier,names[length],Ls);
		}
	}
	
	Building School = new Building(building_capacity,floor_capacity,groundfloor_capacity,class_capacity,staircase_capacity,students_num,N); //constructing the building
	Space Sch=School; //pointer to the mother
 	//
	for(int a=0; a<18; a++){ //placing the visitors in the building
	  	Sch.enter(pl[a],a,1);
	  }

	for(int a=18; a<students_num+18; a++){ //placing the visitors in the building

		Sch.enter(pl[a],a,1);
	}   
		
	 for(int fun=0;fun<5;fun++){ //calling operate function for the students that were left outside the class(Not for incrementing tireness values)
		
	 	Sch.operate();
	 }	  

   }
}
