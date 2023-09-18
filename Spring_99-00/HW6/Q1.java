import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Badkonak {

    static int n;
    static int k;

    Badkonak(int n, int k) {
        this.n = n;
        this.k = k;
    }

    static long arr_size = (long) (Math.pow(2, k) - 1);

    public boolean check_it_possible(int num, int k_size) {
        long arr_size = (long) (Math.pow(2, k) - 1);
        return arr_size >= num;
    }


    public static ArrayList<Integer> complete_arr(int num, ArrayList<Integer> myarray) {
        int num2 = (int) Math.pow(2, num - 1);
        for (int i = 0; i < num2 - 1; i = i + 1) {
            myarray.add(2 * i, num);
        }
        myarray.add(num);
        return myarray;
    }


    public static ArrayList<Integer> chinesh(int k) {
        ArrayList<Integer> arr = new ArrayList<Integer>();
        if (k == 1) {
            arr.clear();
            arr.add(1);
            return arr;
        } else {
            return complete_arr(k, chinesh(k - 1));
        }

    }

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(
                    new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
    }

    public static void main(String[] args) {

        FastReader s = new FastReader();

        int n = s.nextInt();
        int k = s.nextInt();
        Badkonak badkonakha = new Badkonak(n, k);

        ArrayList<Integer> help_arr;

        if (badkonakha.check_it_possible(n, k)) {
            help_arr = Badkonak.chinesh(k);
            for (int i = 0; i < n; i++)
                System.out.print(help_arr.get(i) + " ");
        } else {
            System.out.println("Impossible");
        }
    }

}
