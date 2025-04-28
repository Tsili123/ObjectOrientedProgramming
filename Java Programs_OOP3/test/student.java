public class Student extends Person
{
		//tireness
		private int std_tired;
		public Student(int cln, int fln, int flg, String s, int L)
		{ //Constructor function
			super(cln, fln, flg, s);
			this.std_tired = L;
			System.out.print("A student has been created");
			System.out.print("\n");
			this.tireness = 0;
		}

		public final int set_tireness()
		{ //this function will be used later when a person has reached his Classroom in order to get a tireness value
			this.tireness += std_tired;
			return this.tireness;
		}

		public final int get_tireness()
		{ //getter that returns whether the person is tired or not
			return this.tireness;
		}

		public final int get_floor()
		{ //getter that returns person's floor
			return this.floor_num;
		}

		public final int get_classroom()
		{ //getter that returns person's Classroom
			return this.classroom_num;
		}

		public final void set_prio(int i)
		{ //this function is used when a person reaches the groundfloor, this is where his priority is set
			this.priority = i;
		}

		public final int get_prio()
		{ //getter that returns Person's priority
			return this.priority;
		}

		public final void print_prio()
		{ //function that prints person's priority
			System.out.print("  Student included.His/her priority is :");
			System.out.print(this.priority);
			System.out.print(" name is : ");
			System.out.print(name);
			System.out.print(" Tireness : ");
			System.out.print(this.tireness);
			System.out.print("\n");
		}

		public final void close()
		{
			super.close();
		} //Destructor function
}
