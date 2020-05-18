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



public class i_like_trains {
    FastScanner input;
    PrintWriter output;


    public static void main(String[] arg) {
        new i_like_trains().run();
    }

    void run() {
        try {
            boolean debug = false;
            //boolean ONLINE_JUDGE = System.getProperty("ONLINE_JUDGE") != null;
            debug = true;
            if (debug) input = new FastScanner(new File("i_like_trains.in"));
            else input = new FastScanner();
            output = new PrintWriter(System.out);
            solve();
            output.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }


    void solve() throws IOException {
    	int h1 = input.nextInt(), m1 = input.nextInt();
    	int h2 = input.nextInt(), m2 = input.nextInt();
    	int h = h1+h2, m = m1+m2;
    	h += m/60;
    	m %= 60;
    	// h %= 24;
    	if (h == 24) output.print("00 ");
    	else {
    		if (h < 10) output.print(0);
    		output.print(h + " ");
    	}
    	if (m < 10) output.print(0);
    	output.println(m);
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