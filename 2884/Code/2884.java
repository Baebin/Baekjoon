import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		int a, b;

		Scanner scanner = new Scanner(System.in);
		a = scanner.nextInt();
		b = scanner.nextInt();
		scanner.close();

		b -= 45;
		if (b < 0) {
			a--;
			b += 60;
		}

		if (a < 0) {
			a += 24;
		}

		System.out.print(a + " " + b);
	}
}