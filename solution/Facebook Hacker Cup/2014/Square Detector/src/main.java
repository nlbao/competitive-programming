import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
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
        		in = new FastScanner(new File("square_detector.txt"));
        		out = new PrintWriter(new File("square_detector.out"));
//        		out = new PrintWriter(System.out);
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

    public void solve() throws IOException {
    	int nTest = in.nextInt();
    	for (int test_id = 1; test_id <= nTest; ++test_id) {
    		int n = in.nextInt();
    		String[] a = new String[n+2];
    		for (int i = 0; i < n; ++i)
    			a[i] = in.nextString();  		
    		out.println("Case #" + test_id + ": " + check(a, n));
    	}
    }
    
    String check(String a[], int n) {
    	final int[] dx = {-1, 0, +1, 0};
    	final int[] dy = {0, +1, 0, -1};
		int sx = n, sy = n;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j)
				if (a[i].charAt(j) == '#') {
					sx = i;
					sy = j;
					break;
				}
			if (sx < n) break;
		}
		if (sx == n) return "NO";
		
		int len = 0, h = 0;
		for (int row = sx; row < n; ++row) {
			int l = 0;
			for (int j = sy; j < n; ++j)
				if (a[row].charAt(j) != '#') break;
				else {
					++l;
					StringBuilder sb = new StringBuilder(a[row]);
					sb.setCharAt(j, '.');
					a[row] = sb.toString();
				}
			if (l == 0) break;			
			if (len == 0) len = l;
			else if (l != len) return "NO";
			++h;
		}			
		
		if (len != h) return "NO";		
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (a[i].charAt(j) == '#')
					return "NO";
    	return "YES";
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
    
    String nextString() {
    	return next();
    }
}