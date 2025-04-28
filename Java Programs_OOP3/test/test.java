public class test {

public void main(int argc, String[] args)
{
    // Initialize array of pointer names
    String names[] = { "James", "John", "Robert", "Michael" ,"William","David","Richard","Joseph","Thomas","Charles","Daniel","Aris"
	,"Mary" , "Elizabeth", "Helene" , "Catherine" , "Sophie" , "Georgia" , "Tatiana" , "Penelope", 
    "Corina" , "Sandra" , "Ismene" , "Christine"};

	// ./myprogram 3 5 2 5 11
	tangible.RandomNumbers.seed(time(null));

	int building_capacity = 999; //the command line arguments
	int floor_capacity = 999;
	int groundfloor_capacity = 999;
	int staircase_capacity = 999;
	int L = 3;
	int Cclass;
	int Lj;
	int Ls;
	int Lt;
	int N;

	if (argc < 2)
	{
		System.out.print("Error of argc!");
		System.out.print("\n");
	}
	else
	{
		Cclass = Integer.parseInt(args[1]);
		Lj = Integer.parseInt(args[2]);
		Ls = Integer.parseInt(args[3]);
		Lt = Integer.parseInt(args[4]);
		N = Integer.parseInt(args[5]); //students num
	}

	int class_capacity = Cclass;
	int students_num = 11; ////

	Person[] pl = new Person[18 + students_num];

	for (int i = 0; i < 18;i++)
	{ //give every visitor a floor and office preference
		int cl_number = i % 6 + 1;
		int fl_number = i / 6 + 1;
		short length = tangible.RandomNumbers.nextNumber() % 24;
		pl[i] = new Teacher(cl_number,fl_number,2,names[length],Lt);
	}

	for (int i = 18; i < students_num + 18;i++)
	{ //give every visitor a floor and office preference
		int fl_number = tangible.RandomNumbers.nextNumber() % 3 + 1;
		int cl_number = tangible.RandomNumbers.nextNumber() % 6 + 1;
		short length = tangible.RandomNumbers.nextNumber() % 24;
		int flag_tier;
		if (cl_number % 2 == 0)
		{
			flag_tier = 0; //junior
			pl[i] = new Student(cl_number,fl_number,flag_tier,names[length],Lj);
		}
		else
		{
			flag_tier = 1; //senior
			pl[i] = new Student(cl_number,fl_number,flag_tier,names[length],Ls);
		}
	}

	Building School = new Building(building_capacity,floor_capacity,groundfloor_capacity,class_capacity,staircase_capacity,students_num,N); //constructing the building
	Space Sch = School; //pointer to the mother
	 //
	for (int a = 0; a < 18; a++)
	{ //placing the visitors in the building
		  Sch.enter(pl[a],a,1);
	}

	for (int a = 18; a < students_num + 18; a++)
	{ //placing the visitors in the building

		Sch.enter(pl[a],a,1);
	}

	 for (int fun = 0;fun < 5;fun++)
	 { //calling operate function for the students that were left outside the class(Not for incrementing tireness values)

		 Sch.operate();
	 }

	for (int i = 0;i < students_num;i++)
	{ //deleting visitor objects
		pl[i] = null;
	}
	pl = null;
}
}
