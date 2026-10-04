
public class supermarket {
    public static void main(String[] args) {
      Scanner scanner = new Scanner(System.in);
      System.out.println("Enter the number of products:");
      int numProducts = scanner.nextInt();
      String[] productNames = new String[numproducts];
      double[] productprices = new double[numproducts];
      System.out.println(" the total of the two products is " + (productprices[0] + productprices[1]));
      System.out.println("enter the discounted price of the product");
      double discountedPrice = scanner.nextDouble();
      System.out.println("the discount percentage of the product is " + ((productprices[0] - discountedPrice) / productprices[0]) * 100);
      System.out.println("the product of the prices is " + (productprices[0] * productprices[1]));
      System.out.println("the quotient of the prices is " + (productprices[0] / productprices[1]));
      System.out.println("the remainder of the prices is " + (productprices[0] % productprices[1]));

    }
}
