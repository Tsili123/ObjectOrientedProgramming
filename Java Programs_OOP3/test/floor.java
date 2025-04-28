public class Floor extends Space implements Closeable
{


		private int class_cap; //class's capacity
		private int fl_num; //this member is floor's number
		private int fl_count; //how many people are in a floor
		private Corridor corridor_of_floor; //floor's corridor
		private Space[] baseptr; //pointer to the mother
		private Space[] Baseptrs = tangible.Arrays.initializeWithDefaultSuperInstances(6); //pointer array to the mothers
		private Classroom[] Cl = tangible.Arrays.initializeWithDefaultClassroomInstances(6); //every floor has 6 classes
		public Floor(int fl_c, int cl_cap, int fl_n)
		{ //Constructor function
			super(fl_c);
			this.class_cap = cl_cap;
			this.fl_num = fl_n;

			if (this.fl_num != 0)
			{
				System.out.print("A Floor has been created with number:");
				System.out.print(this.fl_num);
				System.out.print("\n");
			}

			if (this.class_cap != 0)
			{ //don't create classrooms and corridor if capacity is zero (only in ground floor)
				corridor_of_floor = new Corridor(fl_c);
				baseptr = corridor_of_floor;

				for (int i = 0;i < 6;i++)
				{
					Cl[i] = new Classroom(class_cap,i + 1);
				}

				for (int i = 0;i < 6;i++)
				{
					Baseptrs[i] = Cl[i];
				}
			}

			fl_count = 0;
		}

		public final int get_fl_num()
		{ //getting floor's number
			return this.fl_num;
		}


		public final void enter(Person pl, int a)
		{ //floor enter places a Person in floor's corridor then proceeds to the entering stage of the class

			baseptr.enter(pl); //corridor
			fl_count++;

			for (int i = 0;i < 6;i++)
			{ //for every class
				if (Baseptrs[i].get_class_count() < this.class_cap)
				{ //if the Person fits in class
					if (baseptr.get_class(i + 1))
					{ //and if this is the class he wants to go to

						Person temp = baseptr.exit(1,i + 1); //remove him from the corridor

						Baseptrs[i].enter(temp); //and place him in the class
						System.out.print("Entering class with number: ");
						System.out.print(i + 1);
						temp.print_prio();
						break; //only one can enter at a time so if one person went in no need to continue the loop
					}
				}
				else
				{
					//print the desired messages if he couldn't fit
					System.out.print("Please wait for outside in class: ");
					System.out.print(i + 1);
					System.out.print(" ");
					pl.print_prio();
					break;
				}
			}
		}

		public final Person exit()
		{ //floor exit function removes the first Person
		//that was tired and also proceeds to enter those that wait in the corridor 

			Person cl_temp = null;
			Person pl_temp = null;

			for (int i = 0;i < 6;i++)
			{ //for every floor
				if (Baseptrs[i].get_class_count() != 0)
				{ //if there is at least one person inside
					if ((pl_temp = Baseptrs[i].exit()) != null)
					{ //if we managed to find someone

						cl_temp = pl_temp; //place him temporarily in a variable

						fl_count--;

						for (int j = 0;j < baseptr.get_corridor_count();j++)
						{

							//now check for every person in the corridor if he can go in the Class
							if (Baseptrs[i].get_class_count() < class_cap)
							{
							// if class count is less than its capacity 
								if (baseptr.get_class(i + 1))
								{ //if we find someone that wants this Class
									//cout << "mesaaaaaaaaaaaaaa" <<endl;
									Person temp;
									temp = baseptr.exit(1,i + 1); //remove him from the corridor
									Baseptrs[i].enter(temp); //and place him in that class
									System.out.print("Entering class number: ");
									System.out.print(i + 1);
									temp.print_prio();
								}
							}
							else
							{
								//for those that couldn't enter yet again..
								baseptr.print_prio(j,1,i + 1);
							}
						}
						break; //we only return one Person at a time, so if we found somebody break the loop
					}
				}
			}
			return cl_temp; //return the Person
		}

		public final int get_fl_count()
		{ //getting how many people are in a floor
			return this.fl_count;
		}

		public final void make_tireness()
		{ //this function will go at every class that has at least one person inside and give him a tireness value
			for (int i = 0; i < 6; i++)
			{
				if (Baseptrs[i].get_class_count() != 0)
				{
					Baseptrs[i].make_tireness();
				}
			}
		}

		public final Classroom get_class_from_fl(int i)
		{
			return Cl[i];
		}

		public final void close()
		{ //Destructor function
			if (corridor_of_floor != null)
			{
				corridor_of_floor.close();
			}
			for (int i = 0;i < 6;i++)
			{
				if (Cl[i] != null)
				{
					Cl[i].close();
				}
			}
			System.out.print("End of service!");
			System.out.print("\n");
		}

		public void print_prio(int UnnamedParameter)
		{
		} //ground floor has to inherit those functions
		public int get_grl_count()
		{
        }
        
        public int get_grl_count()
        {
        }
        public void enter(Person UnnamedParameter , int UnnamedParameter, int UnnamedParameter, int UnnamedParameter )
        {
        }
        public Person exit(int UnnamedParameter)
        {
        }
        public void wait(Person UnnamedParameter, int UnnamedParameter)
        {
        }
        public void grl_dec_counter()
        {
        }

    }
