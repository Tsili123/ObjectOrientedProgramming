public class Staircase extends Space implements Closeable
{

		private int strc_count; //how many people are in an Staircase
		private int finised_counter; //how many people finished
		private Person[] pl; //array that stores all the people in an Staircase
		private int lpos; //the use of these variables will be explained in the function they are used
		private int fpos;

		public Staircase(int flc)
		{ //Constructor function
			super(flc);

			System.out.print("A lift has been created!");
			System.out.print("\n");
			lpos = 0;
			fpos = 0;
			strc_count = 0;
			finised_counter = 0;

			pl = new Person[flc];
			for (int j = 0;j < flc;j++)
			{
				pl[j] = null;
			}
		}

		public final Person exit(int n)
		{ //exit function removes the Person from the cap cell
			Person temp;
			temp = pl[n];
			pl[n] = null;

			return temp;
		}

		public final int empty_all(Floor flptr)
		{
		//empty all function takes the Persons who finished and places them in the groundfloor	
			finised_counter = 0;
			for (int i = 0;i < cap;i++)
			{
				if (pl[i] == null)
				{ //if we stumbled upon a non-existent Person run the loop again
					continue;
				}
				if (pl[i].get_tireness() > 0)
				{
					Person temp = exit(i);
					strc_count--;
					flptr.enter(temp,i,0,1);
					finised_counter++;
				}
			}
			return finised_counter; //empty all has to return how many finished
		}

		public final void StopDown(Space[] flptr, int opc)
		{ //stop down function that goes through every floor and takes those that finished

			//Attend / Teach
			for (int f = 0;f < 3;f++)
			{ //give tireness values to those that are in the classes
				for (int p = 0;p < opc;p++)
				{
					flptr[f].make_tireness();
				}
			}

			for (int f = 2;f >= 0;f--)
			{
				//since we are stopping down, the loop begins from the last floor
				for (int i = 0;i < cap;i++)
				{
					//for cap number of people 
					if (flptr[f].get_fl_num() == f + 1)
					{ //just making sure we are on the right floor
						if (strc_count < cap)
						{ //if there is room for more
							int j;
							for (j=0;j < cap;j++)
							{ //find an empty position
								if (pl[j] == null)
								{
									break;
								}
							}

							Person temp = flptr[f].exit(); //find a tired Person

							if (temp != null)
							{ //if he exists place him in the empty position
								enter(temp, j);
								strc_count++;
								continue;
							}
						}
					}
				}
			}
		}

		public final void StopUp(Space[] flptr, int flr_cap)
		{ //stop up function that goes through every floor and places the people who want to enter it

			for (int f = 0;f < 3;f++)
			{ //for every floor

				for (int i = 0; i < cap; i++)
				{ //for cap num of people

					if (strc_count == 0)
					{ //if there is no one on the Staircase this process is skipped
						break;
					}

					if (pl[i] == null)
					{ //if we stumbled upon a non-existent Person run the loop again
						continue;
					}

					if (pl[i].get_floor() == f + 1)
					{ //if this is the floor the Person wants to go to

						if (flptr[f].get_fl_count() < flr_cap)
						{ //if he can fit in the floor
							Person temp = exit(i); //remove him from the Staircase
							strc_count--;
							System.out.print("Entering floor number: ");
							System.out.print(f + 1);
							temp.print_prio();
							flptr[f].enter(temp, i); //and place him on the floor
							continue;
						}
						else
						{
							//if he can't fit print the desired messages
							System.out.print("Sorry, floor number ");
							System.out.print(f + 1);
							System.out.print(" is full. ");
							pl[i].print_prio();
						}
					}
				}
			}
		}

		public final void enter(Person prs, int i)
		{
			//enter function places a Person in the i cell
				System.out.print("Person on the lift. \n");
//C++ TO JAVA CONVERTER TODO TASK: The following line was determined to be a copy assignment (rather than a reference assignment) - this should be verified and a 'copyFrom' method should be created:
//ORIGINAL LINE: pl[i]=prs;
				pl[i].copyFrom(prs);
				pl[i].print_prio();
		}

		public final int operate(Floor flptr, Space[] baseptr, int index, int fl_cap, int opc)
		{

				int i = 0;
				 //lpos is the counter that goes through everyone in the groudfloor, fpos's use is explained below

			//Entering stage
			for (lpos= fpos;lpos < index;lpos++)
			{

					if (flptr.get_grl_count() == 0)
					{
						//if we took everyone from the groundfloor we may skip the entering stage
						break;
					}

					if (strc_count < cap)
					{ //if the Person can fit in the Staircase
						int j;
						for (j=0;j < cap;j++)
						{
							if (pl[j] == null)
							{ //find an empty position
								break;
							}
						}

						Person temp = flptr.exit(0); //remove him from the groundfloor

						if (temp != null)
						{ //if he exists
							flptr.grl_dec_counter(); //decrement the counter of those who are on the groundfloor
							enter(temp, j); //and place him in the Staircase

							strc_count++;
							i++;
							continue; //continue statement is used in order to execute the following if-block in the next loop
						}

					}

					if (strc_count == cap)
					{ //if the counter is equal to the capacity this means we can't take any more people
						if (i == cap)
						{ //if this is the first Person who couldn't fit
							fpos = lpos; //then place his position in fpos so the loop will begin from this one in the next operation
						}

						flptr.print_prio(lpos); //and print the desired messages
						i++;
					}
			}

			//entering stage is over, we may call the remaining functions
			StopUp(baseptr,fl_cap);

			StopDown(baseptr,opc); //put them in staircase

			empty_all(flptr); //empty staircase
		}

		public final void close()
		{ //Destructor function
			System.out.print("No more ups and downs!");
			System.out.print("\n");
			// for(int j=0;j<cap;j++){	
			// 	if(pl[j]!=NULL)
			// 		delete pl[j];
			//     //pl[j]=NULL;
			// }
			 Arrays.deleteArray(pl);
		}
}

                        
                    