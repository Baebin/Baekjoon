import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        int a, n, x;

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine(), " ");

        n = Integer.parseInt(st.nextToken());
        x = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine(), " ");
        while (st.hasMoreTokens()) {
            a = Integer.parseInt(st.nextToken());
            if (a < x) bw.write(a + "\n");
        }

        br.close();

        bw.flush();
        bw.close();
    }
}
