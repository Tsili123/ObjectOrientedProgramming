
 public class Person implements Closeable
 { //Person class will represent the people who take part
		protected int classroom_num; //the Classroom that the person wants to go to
		protected int floor_num; //the floor that the person wants to go to
		protected int priority; //his priority
		protected int tireness; //variable that determines whether the person was tired or not
		protected int flag_tier;
		protected final String name;
		//tireness
		public Person(int cln, int fln, int flg, String s)
		{ //Constructor function
			this.classroom_num = cln;
			this.floor_num = fln;
			this.flag_tier = flg;
			this.name = s;
			this.tireness = 0;
		}

		public int set_tireness()
		{
		}
		public int get_tireness()
		{
		}
		public int get_floor()
		{
		}
		public int get_classroom()
		{
		}
		public void set_prio(int UnnamedParameter)
		{
		}
		public int get_prio()
		{
		}
		public void print_prio()
		{
        }
        public final void close()
		{
		} //Destructor function
 }