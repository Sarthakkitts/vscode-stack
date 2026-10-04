import java.util.Scanner;
public class library{
    public static void main(String[] args) {
Scanner scanner= new Scanner(System.in);
System.out.println("Enter the number of books: ");
int numBooks = scanner.nextInt();
System.out.println("enter the auhtor name of the book: ");
int numAuthor = scanner.nextInt();
System.out.print("enter the price of the book: ");
int numPrice = scanner.nextInt();
void displayBookDetails(int numBooks, int numAuthor, int numPrice) {
    System.out.println("the number of books is " + numBooks);
    System.out.println("the author name of the book is " + numAuthor);
    System.out.println("the price of the book is " + numPrice);
    
