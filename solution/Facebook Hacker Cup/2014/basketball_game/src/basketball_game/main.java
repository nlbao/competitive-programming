package basketball_game;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;



public class main {
    FastScanner in;
    PrintWriter out;
    
    public static void main(String[] arg) {
        new main().run();
    }
    
    public void run() {
        try {
        	boolean debug = false;
        	debug = true;
        	if (debug) {
        		in = new FastScanner(new File("basketball_game.in"));
//        		out = new PrintWriter(new File("basketball_game.out"));
        		out = new PrintWriter(System.out);
        	} else {
        		in = new FastScanner();
        		out = new PrintWriter(System.out);
        	}
            solve();
            out.close();
        } catch (IOException e) {
        	e.printStackTrace();
        }
    }
    
    public boolean cmp(int i, int j) {
    	return i > j;
    }

    public void solve() throws IOException {
    	int nTest = in.nextInt();
    	for (int test_id = 1; test_id <= nTest; ++test_id) {
    		out.print("Case #" + test_id + ": ");
    		int n = in.nextInt(), m = in.nextInt(), p = in.nextInt();
    		String[] name = new String[n+2];
    		int[] shot_percentage = new int[n+2];
    		int[] height = new int[n+2];
    		int[] id = new int[n+2];
    		
    		
    		for (int i = 0; i < n; ++i) {
    			name[i] = in.nextStr();
    			shot_percentage[i] = in.nextInt();
    			height[i] = in.nextInt();
    			id[i] = i;
//    			out.println(name[i] + " " + shot_percentage[i] + " " + height[i]);
    		}
    		Arrays.sort(id, cmp);
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
    
    long nextLong() {
		return Long.parseLong(next());
	}
    
    double nextDouble() {
    	return Double.parseDouble(next());
    }
    
    String nextStr() {
    	return next();
    }
}