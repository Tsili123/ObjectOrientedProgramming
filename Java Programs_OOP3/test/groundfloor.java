public class GroundFloor extends Floor implements Closeable
{


		private Corridor grl_corridor; //groundfloor's corridor
		private Space[] baseptr; //pointer to the mother
		private Person[] pl_ground; //array that stores all the people in a ground floor
		private Person[] pl_finished; //array that stores all the people who finished their work from their offices
		private int grl_count; //how many people are in a groundfloor

		public GroundFloor(int grlc)
		{ //Constructor function
			super(grlc,0,0);

			System.out.print("A Ground Floor has been created ");
			System.out.print("\n");
			grl_corridor = new Corridor(grlc);

			pl_ground = new Person[grlc];

			for (int j = 0;j < grlc;j++)
			{
				pl_ground[j] = null;
			}

			pl_finished = new Person[grlc];

			for (int j = 0;j < grlc;j++)
			{
				pl_finished[j] = null;
			}

			baseptr = grl_corridor;
			grl_count = 0;
		}

		public final void wait(Person pl, int a)
		{
			//wait function gives a Person his priority and places him inside groundfloor's corridor 
			 pl.set_prio(a + 1);
			 grl_corridor.enter(pl);

			 System.out.print("Waiting for the lift.");
			 System.out.print("\n");
		}

		public final void enter(Person pl, int n, int b, int l)
		{
			//enter function to place the people inside the corridor and forbid from entering those who can't fit
			if (l == 0)
			{ //if the Person goes from the building to the groundfloor
				if (n < cap)
				{ //if he can fit put him in a array
//C++ TO JAVA CONVERTER TODO TASK: The following line was determined to be a copy assignment (rather than a reference assignment) - this should be verified and a 'copyFrom' method should be created:
//ORIGINAL LINE: pl_ground[n]=pl;
					pl_ground[n].copyFrom(pl);
					grl_count++;
				}

				if (n >= cap)
				{ //if can't fit print the desired message
					System.out.print("Sorry, you can't fit in the ground floor.");
					System.out.print("\n");
				}

				if (n == b - 1)
				{ //if the counter is equal to the building counter then we did all the necessary work for every Person
				// (who went in the building) 
					for (int i = 0;i < grl_count;i++)
					{ //call the wait function for those that fit in the groundfloor
						wait(pl_ground[i], i);
					}
				}
			}

			if (l == 1)
			{ //if the Person is returning from the staircase to the groundfloor place him in a different array
				int i;
				for (i=0;i < cap;i++)
				{
					if (pl_finished[i] == null)
					{
						break;
					}
				}
//C++ TO JAVA CONVERTER TODO TASK: The following line was determined to be a copy assignment (rather than a reference assignment) - this should be verified and a 'copyFrom' method should be created:
//ORIGINAL LINE: pl_finished[i]=pl;
				pl_finished[i].copyFrom(pl);
			}
		}


		public final Person exit(int l)
		{ //exit function removes a Person

			if (l == 0)
			{ //if the Person goes from the groundfloor to the staircase remove him from the groundfloor's corridor
				grl_corridor.exit(0,0);
			}

			if (l == 1)
			{
				//if the Person goes from the groundfloor to the building 
				//(when he has finished, that is) remove him from the pl_finished array
				Person temp;

				int i;
				for (i=0;i < cap;i++)
				{
					if (pl_finished[i] != null)
					{
						break;
					}
				}

				temp = pl_finished[i];
				pl_finished[i] = null;
				return temp;
			}
		}

		public final void print_prio(int y)
		{
			//function to print Person's priority 
			grl_corridor.print_prio(y,0,0);
			 //(this is used in the staircase's entering stage 
			 //so the Person won't have to leave the corridor only to enter it again)
		}

		public final int get_grl_count()
		{
			//getting how many people are in a groundfloor
			return this.grl_count;
		}

		public final void grl_dec_counter()
		{
			//function to decrement groundfloor's counter
			this.grl_count--;
		}


		public final void close()
		{ //Destructor function
			// delete grl_corridor;
			// cout << "End of service!" << endl; 

			// for(int j=0;j<cap;j++){
			// 	if(pl_ground[j]!=NULL)
			// 		delete pl_ground[j];
			// }
			 Arrays.deleteArray(pl_ground);

			// for(int k=0;k<cap;k++){
			// 	if(pl_finished[k]!=NULL)
			// 		delete pl_finished[k];
			// }
			Arrays.deleteArray(pl_finished);
		}

}

