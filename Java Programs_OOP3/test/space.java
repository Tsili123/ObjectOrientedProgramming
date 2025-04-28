public class Space implements Closeable
{ //base class which every  class inherits from (groundfloor inherits from floor class)
		protected int cap; //capacity is used by every child
		public Space(int size)
		{
			this.cap = size;
		} //Constructor function

		//all functions are inherited by the mother class 
		//because later on instead of using the children directly,
		//i will pass their addresses at pointers to the mother class

		// Note: Except groundfloor,
		// because it has to use other classes as arguments in its methods

		public void enter(Person UnnamedParameter)
		{
		} //    corridor  enter
		public void enter(Person UnnamedParameter, int UnnamedParameter2)
		{
		} //floor ,staircase ,building enter
		public void enter(Person UnnamedParameter, int UnnamedParameter2, int UnnamedParameter3)
		{
		}

		public Person exit()
		{
		} // classroom , floor exit
		public Person exit(int UnnamedParameter, int UnnamedParameter2)
		{
		} //corridor exit
		public Person exit(int UnnamedParameter)
		{
		} //staircase exit
		public void exit(Person UnnamedParameter)
		{
		} // building exit

		public int get_class_count()
		{
		} //classroom
		public int get_class(int UnnamedParameter)
		{
		} //corridor
		public int get_corridor_count()
		{
		} //corridor
		public int get_fl_num()
		{
		} //floor
		public int get_fl_count()
		{
		} //floor

		public void operate()
		{
		} //staircase,building
		public void print_prio(int UnnamedParameter, int UnnamedParameter2, int UnnamedParameter3)
		{
		} //corridor
		public void make_tireness()
		{
		} //classroom

		public final void close()
		{
		} //Destructor function
}
