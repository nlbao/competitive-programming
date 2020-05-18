import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;



public class Main {
    FastScanner in;
    PrintWriter out;


    public static void main(String[] arg) {
        new Main().run();
    }

    void run() {
        try {
            boolean debug = false;
            boolean ONLINE_JUDGE = System.getProperty("ONLINE_JUDGE") != null;
//          debug = true;
            if (!ONLINE_JUDGE)
                in = new FastScanner(new File("input.in"));
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
//ArrayList< Pair<Long, Pair<Integer, Integer>> > a;
        int n = (int) 1e6;
//      Vector<Integer>[] a = new Vector[n];
//      a[1] = new Vector<Integer>();
//      for (int i = 0; i < n; ++i) {
//          a[1].add(i);
//      }
//      for (int i = 0; i < n; ++i)
//          a[1].set(i, a[1].get(i)*2);
//      for (int i = 0; i < n; ++i)
//          out.println(a[1].get(i));
//      for (Integer e : a[1])
//          out.println(e);

//      Map<String, Integer> a = new HashMap<String, Integer>();
//      for (int i = 0; i < n; ++i) {
//          String key = "" + (char) (i%26 + 'a');
//          if (a.containsKey(key))
//              a.put(key, a.get(key)+2);
//          else
//              a.put(key, i);
//      }
//
//      for (Object key : a.keySet()) {
//          out.println(key.toString() + " " + a.get(key));
//      }

        n = 10;
        Comparator<Integer> comparator = new HeapMaxComparator();
        PriorityQueue<Integer> a = new PriorityQueue<Integer>(1, comparator);
        for (int i = 0; i < n; ++i)
            a.add(i%5);

        out.println(a.element());

        for (Object x : a) {
            out.println("!!! " + x);
        }

        for (int i = 0; i < n; ++i)
            out.println(a.poll());

        for (int i = 0; i < n; ++i)
            out.println(a.poll());

        out.println(a.size());

        out.println("Done!");
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



class HeapMaxComparator implements Comparator<Integer> {
    @Override
    public int compare(Integer x, Integer y) {
        if (x > y) return -1;
        else if (x < y) return 1;
        return 0;
    }
}