import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;
import java.math.BigInteger;

public class Main {
	FastScanner in;
	PrintWriter out;
	final int MAX_N = 50004;

	public static void main(String[] arg) {
		new Main().run();
	}

	void run() {
		try {
			boolean debug = false;
			boolean ONLINE_JUDGE = System.getProperty("ONLINE_JUDGE") != null;
			//          debug = true;
			if (!ONLINE_JUDGE)
				in = new FastScanner(new File("C11XOA.in"));
			else
				in = new FastScanner();
			out = new PrintWriter(System.out);
			solve();
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	void solve() throws IOException {
		BigInteger[][][] f = new BigInteger[2][2][2];
		int nTest = in.nextInt();
		for (int test_id = 1; test_id <= nTest; ++test_id) {
			int n = in.nextInt(), t = 0;
			f[t][0][1] = f[t][1][0] = new BigInteger("0");
			f[t][0][0] = f[t][1][1] = new BigInteger("1");
			for (int i = 3; i <= n; ++i) {
				int tt = t;
				t = 1-t;
				for (int j = 0; j < 2; ++j) {
					f[t][j][0] = f[tt][j][1];
					f[t][j][1] = f[tt][j][0].add(f[tt][j][1]);
				}
			}			
			BigInteger res = f[t][0][0].add(f[t][0][1]);
			res = res.add(f[t][1][0]);
			res = res.add(f[t][1][1]);
			res = res.add(f[t][1][1]);
			out.println(res);
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
				if (line == null)
					return null;
				st = new StringTokenizer(line);
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
}

class Pair<T1 extends Comparable<T1>, T2 extends Comparable<T2>> implements
		Comparable<Pair<T1, T2>> {
	public T1 first;
	public T2 second;

	public Pair(T1 first, T2 second) {
		this.first = first;
		this.second = second;
	}

	public int compareTo(Pair<T1, T2> o) {
		if (first.compareTo(o.first) != 0)
			return first.compareTo(o.first);
		return second.compareTo(o.second);
	}
}