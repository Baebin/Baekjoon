import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		int n;

		Scanner scanner = new Scanner(System.in);
		n = scanner.nextInt();
		scanner.close();

		for (int i = 1; i <= 9; i++) {
			System.out.println(n + " * " + i + " = " + (n * i));
		}
	}
}