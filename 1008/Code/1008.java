import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        double a,b;

        Scanner scanner = new Scanner(System.in);
        a = scanner.nextInt();
        b = scanner.nextInt();

        System.out.print(a/b);

        scanner.close();
    }
}