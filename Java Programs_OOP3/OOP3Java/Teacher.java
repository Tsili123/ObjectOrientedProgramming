public class Teacher extends Person{
    private int tchtired;
public Teacher(int cln, int fln,int flg,String s,int lt) { //Constructor function
        super(cln,fln,flg,s);
        this.tchtired = lt;
        System.out.println("A teacher has been created");
        this.tireness=0;
    }
    
    int set_tireness(){ //this function will be used later when a person has reached his Classroom in order to get a tireness value
        this.tireness += tchtired;
        return this.tireness;
    }
    public int get_tireness(){ //getter that returns whether the person is tired or not
        return this.tireness;
    }
    public int get_floor(){ //getter that returns person's floor
        return this.floor_num;
    }
    public int get_classroom(){ //getter that returns person's Classroom
        return this.classroom_num;
    }
    public void set_prio(int i){ //this function is used when a person reaches the groundfloor, this is where his priority is set
        this.priority=i;
    }
    public int get_prio(){ //getter that returns Person's priority
        return this.priority;
    }
    public void print_prio(){  //function that prints person's priority
        System.out.println("  Teacher included.His/her priority is :" + this.priority + " name is : " + name + " Tireness : " + this.tireness);
    }
	    
}
