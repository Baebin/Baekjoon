import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		int n, hap = 0;

		Scanner scanner = new Scanner(System.in);
		n = scanner.nextInt();
		scanner.close();

		for (int i = 1; i <= n; i++) {
			hap += i;
		}

		System.out.print(hap);
	}
}