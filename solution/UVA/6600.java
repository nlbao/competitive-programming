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


public class Main {
    FastScanner input;
    PrintWriter output;
    final int dx[] = new int[]{-1, -1, -1, 0, +1, +1, +1, 0};
    final int dy[] = new int[]{-1, 0, +1, +1, +1, 0, -1, -1};


    public static void main(String[] arg) {
        new Main().run();
    }

    void run() {
        try {
			if (System.getProperty("DEBUG") != null)
				input = new FastScanner(new File("input.txt"));
			else input = new FastScanner();
            output = new PrintWriter(System.out);
            solve();
            output.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }


    BigInteger determinant(Fraction a[][], int n) {
    	Fraction det = new Fraction(BigInteger.ONE, BigInteger.ONE);
    	Fraction tmp;
    	for (int i = 0; i < n; i++) {
    		int r = i;
    		for (int j = i; j < n; j++)
    			if (a[j][i].abs().compareTo(a[r][i].abs()) > 0)
    				r = j;
    		if (a[r][i].a.equals(BigInteger.ZERO)) {
    			det = new Fraction();
    			break;
    		}
    		for (int j = 0; j < n; ++j) {
    			tmp = a[i][j];
    			a[i][j] = a[r][j];
    			a[r][j] = tmp;
    		}
    		if (i != r)
    			det.a = det.a.negate();
    		det = det.multiply(a[i][i]);
    		for (int j = i + 1; j < n; j++)
    			a[i][j] = a[i][j].divide(a[i][i]);
    		for (int j = 0; j < n; j++)
    			if (j != i && !a[j][i].a.equals(BigInteger.ZERO))
    				for (int k = i + 1; k < n; k++)
    					a[j][k] = a[j][k].subtract(a[i][k].multiply(a[j][i]));
    	}
    	return det.a;
    }


    void solve() throws IOException {
    	int nTest = input.nextInt();
    	while (nTest-- > 0) {
    		int m = input.nextInt(), n = 0;
    		int id[][] = new int[m][m];
    		for (int i = 0; i < m; ++i)
    			for (int j = 0; j < m; ++j)
    				id[i][j] = n++;
    		Fraction a[][] = new Fraction[n][n];
    		for (int i = 0; i < n; ++i)
    			for (int j = 0; j < n; ++j)
    				a[i][j] = Fraction.ZERO;

    		for (int i = 0; i < m; ++i)
    			for (int j = 0; j < m; ++j) {
    				int u = id[i][j];
    				for (int k = 0; k < 8; ++k) {
    					int x = i + dx[k], y = j + dy[k];
    					if (x < 0 || x >= m || y < 0 || y >= m) continue;
    					int v = id[x][y];
    					a[u][u] = a[u][u].add(Fraction.ONE);
    					a[u][v] = new Fraction(new BigInteger("-1"), BigInteger.ONE);
    				}
    			}
    		BigInteger ans = determinant(a, n-1);
    		output.println(ans);
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



class Fraction {
	public BigInteger a, b;

	public static final Fraction ZERO = new Fraction();
	public static final Fraction ONE = new Fraction(BigInteger.ONE, BigInteger.ONE);


	public Fraction() {
		a = BigInteger.ZERO;
		b = BigInteger.ONE;
	}

	public Fraction(BigInteger _a, BigInteger _b) {
		a = _a;
		b = _b;
		reduce();
	}

	public void reduce() {
		if (a.equals(BigInteger.ZERO)) b = BigInteger.ONE;
		if (b.compareTo(BigInteger.ZERO) < 0) {
			a = a.negate();
			b = b.negate();
		}
		BigInteger d = a.abs().gcd(b);
		a = a.divide(d);
		b = b.divide(d);
	}

	static BigInteger lcm(BigInteger a, BigInteger b) {
		return a.divide(a.gcd(b)).multiply(b);
	}

	public Fraction add(Fraction other) {
		BigInteger g = lcm(b, other.b);
		return new Fraction(g.divide(b).multiply(a)
				.add(g.divide(other.b).multiply(other.a)), g);
	}

	public Fraction subtract(Fraction other) {
		BigInteger g = lcm(b, other.b);
		return new Fraction(g.divide(b).multiply(a)
				.subtract(g.divide(other.b).multiply(other.a)), g);
	}

	public Fraction multiply(Fraction other) {
		BigInteger d1 = a.abs().gcd(other.b);
		BigInteger d2 = other.a.abs().gcd(b);
		return new Fraction(a.divide(d1).multiply(other.a.divide(d2)),
				b.divide(d2).multiply(other.b.divide(d1)));
	}

	public Fraction divide(Fraction other) {
		BigInteger d1 = a.abs().gcd(other.a);
		BigInteger d2 = other.b.gcd(b);
		return new Fraction(a.divide(d1).multiply(other.b.divide(d2)),
				b.divide(d2).multiply(other.a.divide(d1)));
	}

	public int compareTo(Fraction other) {
		return a.multiply(other.b).compareTo(b.multiply(other.a));
	}

	public Fraction abs() {
		return new Fraction(a.abs(), b);
	}
}