import java.util.Scanner;

public class student {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the number of students: ");
        int numStudents = scanner.nextInt();
        System.out.println("Enter the roll numbers of the student:");
        int numrollNumbers = scanner.nextInt();
        System.out.println("enter the departmet of the student:");
        String departement= scanner.next();
        System.out.println("enter the year of the college of the student");
        String year=scanner.next();
        System.out.println("enter the name of teh college");
        String college = scanner.next();
        System.out.println("the name of the student is " + numStudents);
        System.out.println("the roll number of the student is " + numrollNumbers);
        System.out.println("the departmet of the student is " + departement);
        System.out.println("the year of the college of the student is " + year);
        System.out.println("the name of the college is " + college);

    }
}
