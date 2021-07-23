package udel.src.main.java.com.cthacker.udel;

import org.springframework.data.annotation.Id;
import java.text.SimpleDateFormat;
import java.util.*;

public class Employee {

    @Id private String employeeId;

    private String firstName;
    private String lastName;
    private String middleName;
    private String position;
    private int dobYear;
    private int dobMonth;
    private int dobDay;
    private Calendar dob = Calendar.getInstance();
    //newCalendar.set(2021,7,23);
    private Date theDate;// = newCalendar.getTime();
    private SimpleDateFormat format = new SimpleDateFormat("MM/dd/yyyy");
    private String dobStr;// = format.format(theDate);

    public Employee(String newFirst,String newMiddle,String newLast,String newPosition,int newMonth,int newDay,int newYear){

        this.firstName = newFirst;
        this.lastName = newLast;
        this.middleName = newMiddle;
        this.newPosition = position;
        this.dobYear = newYear;
        this.dobMonth = newMonth;
        this.dobDay = newDay;
        this.dob.set(dobYear,dobMonth,dobDay);
        this.theDate = dob.getTime();
        this.dobStr = this.format.format(theDate);

    }

    public void setFirstName(String newFirst){

        this.firstName = newFirst;

    }

    public void setMiddleName(String newMiddle){

        this.middle = newMiddle;

    }

    public void setLastName(String newLast){

        this.last = newLast;

    }

    public void setPosition(String newPosition){

        this.position = newPosition;

    }

    public void setDOBYear(int newDOBYear){

        this.dobYear = newDOBYear;

    }

    public void setDOBMonth(int newDOBMonth){

        this.dobMonth = newDOBMonth;

    }

    public void setDOBDay(int newDOBDay){

        this.dobDay = newDOBDay;

    }

    public String getFirstName(){

        return this.firstName;

    }

    public String getMiddleName(){

        return this.middleName;

    }

    public String getLastName(){

        return this.lastName;

    }

    public String getPosition(){

        return this.position;

    }

    public String getDOB(){

        return this.dobStr;

    }


    
}
