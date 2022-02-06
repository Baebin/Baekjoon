import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int a, b, t;

        Scanner scanner = new Scanner(System.in);
        t = scanner.nextInt();

        for (int i = 1; i <= t; i++) {
            a = scanner.nextInt();
            b = scanner.nextInt();

            System.out.println("Case #" + i + ": " + (a+b));
        }

        scanner.close();
    }
}
