import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int a, b;

        Scanner scanner = new Scanner(System.in);
        a = scanner.nextInt();
        b = scanner.nextInt();

        if (a > 0) {
            if (b > 0) {
                System.out.print("1");
            } else {
                System.out.print("4");
            }
        } else {
            if (b > 0) {
                System.out.print("2");
            } else {
                System.out.print("3");
            }
        }
    }  
}