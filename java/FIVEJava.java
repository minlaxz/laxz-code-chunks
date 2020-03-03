import java.util.Scanner;

class FiveClass {
    public static void main(String[ ] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter name: ");
        String name = scanner.nextLine();

        System.out.println("Enter age: ");
        int age = scanner.nextInt();


        System.out.println("===========OUTPUT===========");
        System.out.println("User : "+name+" is "+ age + " years old and");

	if(age>0) {
            if(age <= 18) {
                System.out.println("Young.");
            } else if(age >= 20) {
                System.out.println("Over 20.");
            } else {
		System.out.println("You are 19.");
            }
        } else {
            System.out.println("Error");
        }
    }
}



