import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		int t;

		Scanner scanner = new Scanner(System.in);
		t = scanner.nextInt();

		for (int i = 1; i <= t; i++) {
			int a, b;

			a = scanner.nextInt();
			b = scanner.nextInt();

			System.out.println(a + b);
		}

		scanner.close();
	}
}