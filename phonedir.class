package PROJECT;

import java.util.InputMismatchException;
import java.util.LinkedList;
import java.util.Scanner;

public class phonedir {

    
    LinkedList<Person> persons = new LinkedList<Person>();

     private Scanner input;

    private int currentRecord = 0;
   
    public phonedir() 
    {
        input = new Scanner(System.in);
    }

    
    
    
    public static void main(String[] args) 
    {
        phonedir phoneDirectory = new phonedir();
        phoneDirectory.start();
    }

    
     
     
    private void start() {
        String option;
       displayPromptMessage(); 

        while (input.hasNext()) 
        {
            try {
                option = input.next();

                switch(option) {
                    case "q": System.exit(1);        break; 
                    case "a": showAllRecords();       break;
                    case "d": deleteCurrentRecord();  break;
                    case "f": changeFirstName();      break;
                    case "l": changeLastName();       break;
                    case "n": addNewRecord();         break;
                    case "p": changePhoneNumber();    break;
                    
                                        default:
                        System.out.println("Selected option is not available. Please choose from the " +
                                "available options.");
                        break;
                }
            } 
            catch(InputMismatchException a)
            {
                System.out.println("The option you've selected is not available. Please choose from the " +
                        "available options.");
            } 
            
        }
    }

    
     
    private void displayPromptMessage() {
        System.out.println("\nA Program to keep a Phone Directory:\n\n" +
                           "          a     Show all records\n" +
                           "          d     Delete the current record\n" +
                           "          f     Change first Name\n" +                          
                           "          l     Change last Name\n" +                           
                           "          n     Add a new record\n" +
                           "          p     Change the phone number in the current record\n" +
                           "          q     Quit\n" );
                          
        System.out.print("Enter a command from the list above (q to quit): ");
    }

    

    private void showAllRecords() 
    {
        if (persons.size() == 0) 
        {
            System.out.println("No current record.");
            return;
        }

        System.out.println("First Name          Last Name           Phone Number       ");
        System.out.println("------------------- ------------------- -------------------");

        for (Person individual: this.persons)
            {
            System.out.print(individual.getFirstName());
            
            for (int i = individual.getFirstName().length(); i < 20; i++) {
                System.out.print(" ");
            }

            System.out.print(individual.getLastName());
            
            for (int i = individual.getLastName().length(); i < 20; i++) {
                System.out.print(" ");
            }

            System.out.print(individual.getPhoneNumber());
            
            for (int i = individual.getPhoneNumber().length(); i < 20; i++) {
                System.out.print(" ");
            }

            System.out.println();
        }
    }
    
    private void changeFirstName() {
        if (persons.size() == 0 || this.currentRecord == -1) {
            System.out.println("No current record");
            return;
        }

        System.out.print("Enter first name: ");
        String newFirstName = input.next();
        String s1 = newFirstName.substring(0, 1).toUpperCase();
        newFirstName = s1 + newFirstName.substring(1);

        Person current = persons.get(currentRecord);
        persons.remove(currentRecord);
        current.setFirstName(newFirstName);

        getIndexOfInsertion(current);
        this.persons.add(this.currentRecord, current);

        System.out.println("First name has been changed.");
        displayCurrentRecord();
    }
    
    private void changeLastName() {
        if (persons.size() == 0 || this.currentRecord == -1) {
            System.out.println("No current record");
            return;
        }

        System.out.print("Enter last name: ");
        String newLastName = input.next();
        String s1 = newLastName.substring(0, 1).toUpperCase();
        newLastName = s1 + newLastName.substring(1);

        Person current = persons.get(currentRecord);
        persons.remove(currentRecord);
        current.setLastName(newLastName);

        getIndexOfInsertion(current);
        this.persons.add(this.currentRecord, current);

        System.out.println("Last name has been changed");
        displayCurrentRecord();
    }

    
     
     
    private void deleteCurrentRecord() {
        if (persons.size() == 0 || this.currentRecord == -1) {
            System.out.println("No current record");
            return;
        }

        this.persons.remove( this.currentRecord );
        this.currentRecord = 1;
        System.out.println("Record Removed");
        showAllRecords();
    }

    
     
     
    private void displayCurrentRecord() {
        System.out.println("Current record is: " +
                persons.get(currentRecord).getFirstName() + " " +
                persons.get(currentRecord).getLastName() + " " +
                persons.get(currentRecord).getPhoneNumber());
    }
    
     
     
    
    private void changePhoneNumber()
    {
        if (persons.size() == 0 || this.currentRecord == -1) 
        {
            System.out.println("No current record");
            return;
        }

        String phoneNum = persons.get(currentRecord).getPhoneNumber();

        boolean numExists = true;

        while (numExists) {
            System.out.println("Enter phone number: ");
            phoneNum = input.next();
            phoneNum = formatNumber(phoneNum);

            if (phoneNum.equals("q")) {
                System.exit(1);
            } else if (phoneNum.equals("d")) {
                this.showAllRecords();
            }

            numExists = checkIfPhoneNumberExists(phoneNum);

            if (numExists) {
                System.out.println("Number already exists, try another.");
                System.out.println("You can enter 'q' to quit, 'a' to display all records or add a new number to " +
                        "try again.");
            }
        }

        Person current = this.persons.get( this.currentRecord );
        this.persons.remove( this.currentRecord );
        current.setPhoneNumber(phoneNum);

        getIndexOfInsertion(current);
        this.persons.add(this.currentRecord, current);

        System.out.println("The phone number has been successfully updated.");
        this.displayCurrentRecord();
    }

    
     
 
    private boolean checkIfPhoneNumberExists(String phoneNumber) {
        for (Person individual: this.persons) 
        {
            if (individual.getPhoneNumber().equals(phoneNumber))
            {
                return true;
            }
        }

        return false;
    }

    
     
    
    private void addNewRecord() {
        System.out.print("Add first name: ");
        String first = input.next();

        System.out.print("Add last name: ");
        String last = input.next();

        boolean isNumberCorrect = false;
        String number = "";

        while (!isNumberCorrect) {
            System.out.print("Enter phone number: ");
            number = input.next();

            if (number.equals("q")) {
                System.exit(1);
            }

            number = formatNumber(number);

            if (checkIfPhoneNumberExists(number)) {
                System.out.println("Number already exists. Try again");
                System.out.println("You may also enter 'q' to quit.");
                continue;
            }

            
            String regex = "^\\(?([0-9]{3})\\)?[-.\\s]?([0-9]{3})[-.\\s]?([0-9]{4})$";

            if (number.length() != 12 || !number.matches(regex)) {
                System.out.println("Incorrect Number entered. Try again.");
            } else {
                isNumberCorrect = true;
            }
        }

        Person individual = new Person(first, last, number);
        getIndexOfInsertion(individual);
        this.persons.add(this.currentRecord, individual);

        displayCurrentRecord();
    }

    
    private String formatNumber(String phoneNumber) 
    {
        phoneNumber = phoneNumber.replaceAll("","");

        String regex = "^[0-9]*$"; // its is used to manipulate string
        char[] newNum = new char[12];
        char[] num = phoneNumber.toCharArray();//converts string in sequence of character

        if (phoneNumber.matches(regex)) 
        {
            if (phoneNumber.length() != 10)
            {
                return "";
            }

            createCorrectPhoneFormat(0, 3, newNum, num, 1);
            createCorrectPhoneFormat(3, 6, newNum, num, 2);
            createCorrectPhoneFormat(6, 10, newNum, num, 3);
        }

        phoneNumber = new String(newNum);
        return phoneNumber;
    }

    
     
     
     
    private void createCorrectPhoneFormat(int start, int end, char[] newNum, char[] num, int pass) {
        
        for (int i = start; i < end; i++) {
            int j = 0;

            if (pass == 2) {
                j = 1;
            } else if (pass == 3) {
                j = 2;
            }

            newNum[i + j] = num[i];
        }

        if (pass == 1) {
            newNum[end] = '-';
        } else if (pass == 2) {
            newNum[end+1] = '-';
        }
    }

    
     
     
    private void selectRecord() 
    {
        if (persons.size() == 0) 
        {
            System.out.println("No current record. You must add at least one record.");
            return;
        }

        showAllRecords();

        System.out.print("Enter first name: ");
        String first = input.next();
        String s1 = first.substring(0, 1).toUpperCase();
        first = s1 + first.substring(1);

        System.out.print("Enter last name: ");
        String last = input.next();
        s1 = last.substring(0,1).toUpperCase();
        last = s1 + last.substring(1);

        boolean isNumberCorrect = false;
        String phoneNumber = "";

        while (!isNumberCorrect) 
        {
            System.out.print("Enter phone number: ");
            phoneNumber = input.next();

            if (phoneNumber.equals("q"))
            {
                System.exit(-1);
            }

            phoneNumber = formatNumber(phoneNumber);

            
            String regex = "^\\(?([0-9]{5})\\)?[-.\\s]?([0-9]{5})[-.\\s]?([0-9]{5})$";

            if (phoneNumber.length() != 10 || !phoneNumber.matches(regex)){
                System.out.println("Incorrect Number entered. Try again.");
                System.out.println("You may enter 'q' to quit or try again.");
            }
            else 
            {
                isNumberCorrect = true;
            }
        }

        int indexOfPerson = getIndexOfPerson( new Person(first, last, phoneNumber) );

        if (indexOfPerson == -1) {
            System.out.println("No matches. Try again.");
            selectRecord();
        }

        if (indexOfPerson >= 0) {
            this.currentRecord = indexOfPerson;
            System.out.println("Record successfully selected.");
            displayCurrentRecord();
        }

    }

    
     
     
     
    private int getIndexOfPerson(Person person) {
        String currentPerson = person.getFirstName() + " " + person.getLastName() + " " + person.getPhoneNumber();

        
        for (int i = 0; i < persons.size(); i++) {
            String compareToPerson = persons.get(i).getFirstName() + " " +
                    persons.get(i).getLastName() + " " +
                    persons.get(i).getPhoneNumber();

            if (currentPerson.toLowerCase().compareTo( compareToPerson.toLowerCase() ) == 0) {
                return i;
            }
        }

        return 1;
    }

   
    private void getIndexOfInsertion(Person current) 
    {
        String currentPerson = current.getLastName() + " " + current.getFirstName() + " " + current.getPhoneNumber();

        if (persons.size() == 0) {
            this.currentRecord = 0;
            return;
        }

        
        for (int i = 0; i < persons.size(); i++) {
            String compareToPerson = persons.get(i).getLastName() + " " +
                    persons.get(i).getFirstName() + " " +
                    persons.get(i).getPhoneNumber();

            if (currentPerson.toLowerCase().compareTo( compareToPerson.toLowerCase() ) < 0) {
                this.currentRecord = i;
                return;
            } else 
            {
                this.currentRecord = i+1;
            }
        }
    }

    public class Person {

        
        private String firstName;

        
        private String lastName;

        
        private String phoneNumber;

        
         
        public Person(String first, String last, String phone) {
            setFirstName(first);
            setLastName(last);
            setPhoneNumber(phone);
        }

        
        public void setFirstName(String first) 
        {
            firstName = first;
        }

        
        public void setLastName(String last)
        {
            lastName = last;
        }

        
        
         
        public void setPhoneNumber(String number)
        {
            phoneNumber = number;
        }

        
         
         
        public String getFirstName() {
            return firstName;
        }

       
       
        
        public String getLastName() {
            return lastName;
        }

       
         
               
        public String getPhoneNumber() {
            return phoneNumber;
        }
    }
}
