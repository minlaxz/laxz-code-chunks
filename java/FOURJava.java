import java.util.Scanner;

class FourClass {
    public static void main(String[ ] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter name: ");
        String name = scanner.nextLine();

        System.out.println("Enter age: ");
        int age = scanner.nextInt();


        System.out.println("===========OUTPUT===========");
        System.out.println("User : "+name+" is "+ age + " years old and");

        if(age < 18) {
        System.out.println("Young.");
        }
        else {
        System.out.println("Over 18.");
        }
    }
}
