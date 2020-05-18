import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {
	FastScanner in;
	PrintWriter out;

	public static void main(String[] arg) {
		new Main().run();
	}

	void run() {
		try {
			boolean ONLINE_JUDGE = System.getProperty("ONLINE_JUDGE") != null;
			if (ONLINE_JUDGE)
				in = new FastScanner(new File("REKMP.in"));
			else
				in = new FastScanner();
			out = new PrintWriter(System.out);
			solve();
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	
	final int BASE = 16;
	int MAX_N = 100005;
	int n;
	int[] a, res, p;
	Set<Integer>[] diff;
	
	
	int get_root(int u) {
		if (p[u] == u) return u;
		return p[u] = get_root(p[u]);
	}
	
	void add_edge(int u, int v) {
		diff[u].add(v);
		diff[v].add(u);
	}
	
	boolean check() {
		diff = new HashSet[MAX_N];
		for (int i = 1; i <= n; ++i)
			diff[i] = new HashSet<Integer>();
		
		if (a[1] != 0) return false;
		p[1] = 1;
		for (int i = 2, len = 0; i <= n; ++i) {
			if (a[i] < 0 || a[i] >= i) return false;
			if (a[i] == 0) p[i] = i;
			else p[i] = get_root(a[i]);
			int u = p[i];
			while (len > 0 && len+1 > a[i]) {
				add_edge(u, get_root(len+1));
				len = a[len];
			}
			if (len+1 < a[i]) return false;
			if (len == 0) {
				if (a[i] > 0) {
					if (a[i] > 1) return false;
					++len;
					p[u] = 1;
				}
				else add_edge(u, 1);
			}
			else {
				if (++len != a[i]) return false;
			}
		}
		
		res = new int[MAX_N];
		Arrays.fill(res, -1);
		for (int i = 1; i <= n; ++i) {
			int u = get_root(i);
			if (u != i) {
				res[i] = res[u];
				continue;
			}
			if (diff[u].contains(u)) return false;
			if (diff[u].size() > BASE) return false;
			
			boolean[] ok = new boolean[BASE+4];
			Arrays.fill(ok, true);
			for (Object v : diff[u]) {
				int color = res[(int) v];
				if (color >= 0) ok[color] = false;
			}
			
			for (int color = 0; color < BASE; ++color)				
				if (ok[color]) {
					res[i] = color;
					break;
				}
			if (res[i] < 0) return false;
		}
		return true;
	}
	
	
	char convert(int x) {
		if (x < 10) return (char) (x + '0');
		return (char) (x - 10 + 'A');
	}

	void solve() throws IOException {
		n = in.nextInt();
		MAX_N = n+4;
		a = new int[MAX_N];
		p = new int[MAX_N];
		for (int i = 1; i <= n; ++i) {
			a[i] = in.nextInt();
			p[i] = i;
		}			
		if (!check())
			out.println(-1);
		else {
			for(int i = 1; i <= n; ++i)
				out.print(convert(res[i]));
			out.println();
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