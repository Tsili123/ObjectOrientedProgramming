public class Building extends Space implements Closeable
{

		private int flr_cap; //capacities
		private int grl_cap;
		private int class_cap;
		private int strc_cap;
		private int students_num;
		private int L;

		private GroundFloor grl; //Building's groundfloor
		private Floor flbaseptr; //Pointer to groundfloor's mother
		private Staircase strc; //Building's Staircase
		private Space baseptr; //pointer to the mother
		private Floor[] fl = tangible.Arrays.initializeWithDefaultFloorInstances(3); //A building has 3 Floors
		private Space[] Baseptrs = tangible.Arrays.initializeWithDefaultSuperInstances(3); //pointer array to the mothers
		private Person[] pl_in_build; //array that stores all the Persons in a building
		private int operate_cycles;
		private int pl_count; //how many people are in a building
	//finised_counter is how many people finished their work in their classes.At the exiting stage, we will run a loop for finised_counter people.
		private int finised_counter;
		private int flag;
	//Constructor function
		public Building(int bldc, int flrc, int grlc, int clrc, int str_cp, int std_num, int fL)
		{
			super(bldc);
			this.flr_cap = flrc;
			this.grl_cap = grlc;
			this.class_cap = clrc;
			this.strc_cap = str_cp;
			this.students_num = std_num;
			this.operate_cycles = fL;
			System.out.print("A new building is ready for serving students and teachers!");
			System.out.print("\n");

			grl = new GroundFloor(grlc);
			strc = new Staircase(strc_cap);
			for (int i = 0; i < 3;i++)
			{
				fl[i] = new Floor(flrc,clrc,i + 1);
			}
			for (int i = 0; i < 3;i++)
			{
				Baseptrs[i] = fl[i];
			}

			pl_in_build = new Person[bldc];
			for (int j = 0;j < bldc;j++)
			{
				pl_in_build[j] = null;
			}

			pl_count = 0;
			finised_counter = 0;
			baseptr = strc; //staircase
			flbaseptr = grl;
		}

		public final void exit(Person pl)
		{ //exit function prints the desired messages
				System.out.print("I cannot believe I finished!");
				System.out.print("\n");
				pl.print_prio();
		}

		public final void operate()
		{ //operate is used to call Staircase's operate and remove those that finished
			finised_counter = strc.operate(flbaseptr,Baseptrs,grl_cap,flr_cap,operate_cycles); //Staircase operate will return(through empty_all function) how many finished

			for (int i = 0; i < finised_counter;i++)
			{ //removing those that finished
				Person temp = flbaseptr.exit(1);
				exit(temp);
			}
		}

		public final void enter(Person pl, int c, int flag)
		{ //enter function to place the Persons inside the building and forbid from entering those who can't fit
				//cout << "whyyyyyyyy" << endl;
				if (c < cap)
				{ //if he can fit put him in a array
//C++ TO JAVA CONVERTER TODO TASK: The following line was determined to be a copy assignment (rather than a reference assignment) - this should be verified and a 'copyFrom' method should be created:
//ORIGINAL LINE: pl_in_build[c]=pl;
					pl_in_build[c].copyFrom(pl);
					pl_count++;
				}

				if (c > cap)
				{ //if he can't fit print the desired message
					System.out.print("Please, come tomorrow.");
					System.out.print("\n");
				}

				if (c == students_num - 1 + 18 && flag == 1)
				{ //if the counter is equal to the people's number then we did all the necessary work for every Person
					//cout << "whyyyyyyyy" << endl;
					for (int i = 0;i < pl_count;i++)
					{ //now for those that managed to fit, place them in the groundfloor
						//if(i>17)
							flbaseptr.enter(pl_in_build[i],i,pl_count,0);
						 //else
						// 	fl[pl_in_build[i]->get_floor()-1]->get_class_from_fl(pl_in_build[i]->get_classroom()-1)->enter(pl_in_build[i]);
					}
				}
		}

		public final void close()
		{ //Destructor function
			 for (int i = 0;i < 3;i++)
			 {
				 if (fl[i] != null)
				 {
					 fl[i].close();
				 }
			 }
			 if (strc != null)
			 {
				 strc.close();
			 }
			 if (grl != null)
			 {
				 grl.close();
			 }
			 System.out.print("Service not available any longer. Go elsewhere!");
			 System.out.print("\n");
			//   for(int j=0;j<cap;j++){
			// 	  if(pl_in_build[j]!=NULL)
			//   			delete pl_in_build[j];
			//   	//pl_in_build[j]=NULL;
			//   }
			//  delete [] pl_in_build;
		}
}

