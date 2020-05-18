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



public class puzzles {
    FastScanner input;
    PrintWriter output;
    final int MAX_N = (int)(1e6+6);
    int[] p = new int[MAX_N];


    public static void main(String[] arg) {
        new puzzles().run();
    }

    void run() {
        try {
            boolean debug = false;
            //boolean ONLINE_JUDGE = System.getProperty("ONLINE_JUDGE") != null;
            debug = true;
            if (debug) input = new FastScanner(new File("puzzles.in"));
            else input = new FastScanner();
            output = new PrintWriter(System.out);
            solve();
            output.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }



    int getRoot(int u) {
    	if (p[u] == u) return u;
    	return p[u] = getRoot(p[u]);
    }



    void solve() throws IOException {
    	int n = input.nextInt(), m = input.nextInt(), res = n;
    	for (int i = 1; i <= n; ++i)
    		p[i] = i;
    	for (int i = 0; i < m; ++i) {
    		int a = input.nextInt(), b = input.nextInt();
    		int u = getRoot(a), v = getRoot(b);
    		if (u != v) {
    			p[u] = v;
    			--res;
    		}
    		if (a > b) output.println(res);
    	}
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