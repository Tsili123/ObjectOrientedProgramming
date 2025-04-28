public class Classroom extends Space implements Closeable
{ //Classroom class that the Person has to go to

		private int class_num; //class_num member is the number of the Classroom
		private int class_count; //how many people are in an Classroom
		private Person[] people_of_class; //array that stores all the people in an Classroom

		public Classroom(int spc,int cln)
		{ // constructor function
			super(spc);
			this.class_num = cln;
			System.out.print("Classroom number ");
			System.out.print(this.class_num);
			System.out.print(" has been created.");
			System.out.print("\n");

			people_of_class = new Person[spc];

			for (int i = 0;i < spc;i++)
			{
				people_of_class[i] = null;
			}
			class_count = 0;
		}

		public final void enter(Person pl)
		{ //Classroom enter takes a Person and places him in the first empty cell it finds
			int i;
			for (i=0;i < cap;i++)
			{
				if (people_of_class[i] == null)
				{
					break;
				}
			}
//C++ TO JAVA CONVERTER TODO TASK: The following line was determined to be a copy assignment (rather than a reference assignment) - this should be verified and a 'copyFrom' method should be created:
//ORIGINAL LINE: people_of_class[i]=pl;
			people_of_class[i].copyFrom(pl);
			class_count++;
		}

		public final Person exit()
		{ //Classroom exit removes the first Person (who was tired) from the array
			Person temp = null;
			int i;
			for (i=0;i < cap;i++)
			{
				if (people_of_class[i] != null && people_of_class[i].get_tireness() > 0)
				{
					temp = people_of_class[i];
					people_of_class[i] = null;
					class_count--;
					break;
				}
			}
			return temp;
		}

		public final void make_tireness()
		{ //this function sets a Person's tireness value to 1
			for (int i = 0;i < cap;i++)
			{
				if (people_of_class[i] != null)
				{
						people_of_class[i].set_tireness();
				}
			}
		}

		public final int get_class_count()
		{ //get how many people are in an Classroom
			return class_count;
		}

		public final void close()
		{
			System.out.print("End of the work!");
			System.out.print("\n");
			// for(int i=0;i<cap;i++){
			// 	if(people_of_class[i]!=NULL)
			// 		delete people_of_class[i];
			// }
			//delete[] people_of_class;
		}
}

