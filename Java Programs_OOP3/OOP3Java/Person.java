public class Person {//Person class will represent the people who take part 
    protected int classroom_num; //the Classroom that the person wants to go to
    protected int floor_num; //the floor that the person wants to go to
    protected int priority; //his priority
    protected int tireness; //variable that determines whether the person was tired or not
    protected int flag_tier;
    protected String name;
public Person(int cln, int fln,int flg,String s){ //Constructor function
        this.classroom_num = cln;
        this.floor_num = fln;
        this.flag_tier = flg;
        this.name = s;
        this.tireness=0;
    }
    
    int set_tireness(){int c=0; return c;}
    int get_tireness(){int c=0; return c;}
    int get_floor(){int c=0; return c;}	
    int get_classroom(){int c=0; return c;}
    void set_prio(int i){/* set */}
    int get_prio(){int c=0; return c;}
    void print_prio(){/* print */}

}
