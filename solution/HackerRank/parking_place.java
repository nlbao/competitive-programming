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



public class parking_place {
    FastScanner input;
    PrintWriter output;

    public static void main(String[] arg) {
        new parking_place().run();
    }

    void run() {
        try {
            boolean debug = false;
            //boolean ONLINE_JUDGE = System.getProperty("ONLINE_JUDGE") != null;
            debug = true;
            if (debug) input = new FastScanner(new File("parking_place.in"));
            else input = new FastScanner();
            output = new PrintWriter(System.out);
            solve();
            output.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }


    void solve() throws IOException {
    	long n = input.nextLong();
    	int m = input.nextInt(), k = input.nextInt();
    	HashSet q = new HashSet();
    	for (int i = 0; i < m; ++i) {
    		long a = input.nextLong();
    		q.add(a);
    	}
    	for (int i = 0; i < k; ++i) {
    		long a = input.nextLong();
    		if (q.contains(a)) output.println(1);
    		else output.println(0);
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