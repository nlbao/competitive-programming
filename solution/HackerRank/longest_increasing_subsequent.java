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



public class longest_increasing_subsequent {
    FastScanner input;
    PrintWriter output;
    final int MAX_N = (int)(1e6+6);
    final int MAX_A = (int)(1e5+5);


    public static void main(String[] arg) {
        new longest_increasing_subsequent().run();
    }

    void run() {
        try {
            boolean debug = false;
            //boolean ONLINE_JUDGE = System.getProperty("ONLINE_JUDGE") != null;
            debug = true;
            if (debug) input = new FastScanner(new File("longest_increasing_subsequent.in"));
            else input = new FastScanner();
            output = new PrintWriter(System.out);
            solve();
            output.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }


    void solve() throws IOException {
    	int n = input.nextInt(), res = 0;
    	int f[] = new int[MAX_N];
    	Arrays.fill(f, -1);
    	for (int i = 0; i < n; ++i) {
    		int a = input.nextInt();
    		if (a > f[res]) f[++res] = a;
    		else if (a < f[1]) f[1] = a;
    		else {
    			int l = 1, r = res-1, t = -1;
    			while (l <= r) {
    				int mid = (l+r)>>1;
    				if (f[mid] < a) t = l = mid+1;
    				else r = mid-1;
    			}
    			if (t > 0) f[t] = a;
    		}
    	}
    	output.println(res);
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