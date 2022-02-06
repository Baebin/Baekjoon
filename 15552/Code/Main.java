import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader= new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new OutputStreamWriter(System.out));

        int loop = Integer.parseInt(bufferedReader.readLine());

        for (int i = 0; i < loop; i++) {
            String s = bufferedReader.readLine();

            int a = Integer.parseInt((s.split(" ")[0]));
            int b = Integer.parseInt((s.split(" ")[1]));

            bufferedWriter.write((a + b) + "\n");
        }

        bufferedWriter.flush();
    }
}
