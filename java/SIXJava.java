
import java.util.Scanner;

class SixClass {
    public static void main(String[ ] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter name: ");
        String name = scanner.nextLine();

        System.out.println("Enter age: ");
        int age = scanner.nextInt();


        System.out.println("===========OUTPUT===========");
        System.out.println("User : "+name+" is "+ age + " years old and");

        if(age>0){
	    if(age >= 18 && age <= 25) {
                System.out.println("young.");
            } else if(age > 25) {
                System.out.println("old.");
            } else {
		System.out.println("too young");
	    }
	} else {
	    System.out.println("Age Error");
	}
    }

}



