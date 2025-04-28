public class Space {
        //base class which every  class inherits from (groundfloor inherits from floor class)
        protected int cap; //capacity is used by every child
    public Space(int size) {cap = size;} //Constructor function
    
        //all functions are inherited by the mother class 
        //because later on instead of using the children directly,
        //i will pass their addresses at pointers to the mother class
    
        // Note: Except groundfloor,
        // because it has to use other classes as arguments in its methods
        
        void enter(Person p){/*ok */} 	//	corridor  enter
        void enter(Person p, int i){/*ok */}  //floor ,staircase ,building enter
        void enter(Person p , int i,int j){/*ok */}

        Person exit(int i){Person p=null; return p;}  //staircase exit
        Person exit(){Person p=null; return p;}	// classroom , floor exit		 
        Person exit(int i, int j){Person p=null; return p;} //corridor exit
        void exit(Person p){/*ok */} // building exit

        int get_class_count(){int c=0; return c;} //classroom
        boolean get_class(int i){boolean c=false; return c;} //corridor
        int get_corridor_count(){int c=0; return c;}//corridor
        int get_fl_num(){int c=0; return c;}//floor
        int get_fl_count(){int c=0; return c;}//floor

        void operate(){/*ok */} //staircase,building

        void print_prio(int i, int j, int k){/*ok */} //corridor
        
        void make_tireness(){/*ok */} //classroom    
}