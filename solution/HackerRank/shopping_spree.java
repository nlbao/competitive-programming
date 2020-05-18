import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;



public class shopping_spree {
    FastScanner input;
    PrintWriter output;

    final int MAX_N = (int)(1e7+7);
    final int MAX_P = (int)(1e5+5);


    public static void main(String[] arg) {
        new shopping_spree().run();
    }

    void run() {
        try {
            boolean debug = false;
            //boolean ONLINE_JUDGE = System.getProperty("ONLINE_JUDGE") != null;
            debug = true;
            if (debug) input = new FastScanner(new File("shopping_spree.in"));
            else input = new FastScanner();
            output = new PrintWriter(System.out);
            solve();
            output.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }


    void solve() throws IOException {
    	int cp[] = new int[MAX_P];
    	Arrays.fill(cp, 0);
    	int n = input.nextInt();
    	for (int i = 0; i < n; ++i)
    		++cp[input.nextInt()];
    	int m = input.nextInt();

    	long sum = 0;
    	for (int i = 0; i < MAX_P && m > 0; ++i)
    		if (cp[i] > 0) {
    			long t = Math.min(m, cp[i]);
    			sum += t*i;
    			m -= t;
    		}
    	output.println(sum);
    }
}



class FastScanner {
    BufferedReader br;
    StringTokenizer st;
    FastScanner(File f) {
        try {
            br = new BufferedReader(new FileReader(f));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }
    FastScanner() {
        br = new BufferedReader(new InputStreamReader(System.in));
    }
    String next() {
        while (st == null || !st.hasMoreTokens()) {
            try {
                String line = br.readLine();
                if (line == null) return null;
                st = new StringTokenizer(line);
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return st.nextToken();
    }
    int nextInt()       {   return Integer.parseInt(next());    }
    long nextLong()     {   return Long.parseLong(next());      }
    double nextDouble() {   return Double.parseDouble(next());  }
}



class Pair<T1 extends Comparable<T1>, T2 extends Comparable<T2>> implements Comparable<Pair<T1, T2>> {
    public T1 first;
    public T2 second;
    public Pair(T1 first, T2 second) {
        this.first = first;
        this.second = second;
    }
    public int compareTo(Pair<T1, T2> o) {
        if (first.compareTo(o.first) != 0) return first.compareTo(o.first);
        return second.compareTo(o.second);
    }
}