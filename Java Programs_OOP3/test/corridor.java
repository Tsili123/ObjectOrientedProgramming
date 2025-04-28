public class Corridor extends Space implements Closeable
{

		private Person[] corridor_arr; //array that stores all the people in the corridor
		private int corridor_ct; //how many people are at corridor
		public Corridor(int size)
		{ //Constructor function
			super(size);
			System.out.print("The Corridor has been created!");
			System.out.print("\n");

			corridor_arr = new Person[size];
			int i;

			for (i=0;i < size;i++)
			{
				corridor_arr[i] = null;
			}
			corridor_ct = 0;
		}

		public final void enter(Person pl)
		{ // Corridor array takes a Person and places him at the first empty cell
			int i;
			for (i=0;i < cap;i++)
			{
				if (corridor_arr[i] == null)
				{
					break;
				}
			}

//C++ TO JAVA CONVERTER TODO TASK: The following line was determined to be a copy assignment (rather than a reference assignment) - this should be verified and a 'copyFrom' method should be created:
//ORIGINAL LINE: corridor_arr[i]=pl;
			corridor_arr[i].copyFrom(pl);
			corridor_ct++;
		}


		public final Person exit(int fl_num,int class_num)
		{
		// Corridor exit removes the first Person (who was tired) from the array 
		// Arguments fl_num and class_num are used because the function behaves differently if we are exiting from a floor's corridor
		//works both ways
			if (fl_num == 0)
			{ //exiting from groundfloor
				Person temp;

				int i;
				for (i=0;i < cap;i++)
				{
					if (corridor_arr[i] != null)
					{
						break;
					}
				}

				temp = corridor_arr[i];
				corridor_arr[i] = null;
				corridor_ct--;
				return temp;

			}
			else if (fl_num == 1)
			{ //exiting from floor
				Person temp;
				int j;
				for (j=0;j < cap;j++)
				{
					//making sure if the Person wants to go to the desired classroom
					if (corridor_arr[j] != null && corridor_arr[j].get_classroom() == class_num)
					{
						break;
					}
				}

				temp = corridor_arr[j];
				corridor_arr[j] = null;
				corridor_ct--;
				return temp;
			}
		}

		public final int get_class(int i)
		{ //this function is used to ensure the Person wants to go to the office we are currently on
			int index = 0;

			int j;
			for (j=0;j < cap;j++)
			{
				if (corridor_arr[j] != null && corridor_arr[j].get_classroom() == i)
				{
					index = 1;
					break;
				}
			}
			return index;
		}

		public final void print_prio(int n, int f, int i)
		{
			//function to print Person's priority
			//again f and i arguments are used because it behaves differently if we are on the floor

			if (f == 0)
			{
				if (corridor_arr[n] != null)
				{
					System.out.print("You are not allowed to enter!");
					corridor_arr[n].print_prio();
				}
			}
			else if (f == 1)
			{
				if (corridor_arr[n] != null)
				{
					System.out.print("Please wait outside office: ");
					System.out.print(i);
					corridor_arr[n].print_prio();
				}
			}
		}

		public final int get_corridor_count()
		{ //getting how many people are at an corridor
			return corridor_ct;
		}

		public final void close()
		{ //Destructor function
			System.out.print("End of waiting people!");
			System.out.print("\n");
			for (int j = 0;j < cap;j++)
			{
				if (corridor_arr[j] != null)
				{
					if (corridor_arr[j] != null)
					{
						corridor_arr[j].close();
					}
				}
				//corridor_arr[j]=NULL;
			}
			//delete[] corridor_arr;
		}
}
