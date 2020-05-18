import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.Random;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.NoSuchElementException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Tmbao
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        GridMST solver = new GridMST();
        solver.solve(1, in, out);
        out.close();
    }

    static class GridMST {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int N = in.readInt();
            Pair<Integer, Integer>[] points = new Pair[N];
            for (int i = 0; i < N; i++)
                points[i] = Pair.makePair(in.readInt(), in.readInt());

            BidirectionalGraph graph = new BidirectionalGraph(N);
            addXEdges(graph, points);
            addYEdges(graph, points);
            for (int i = 0; i < N; i++)
                points[i] = Pair.makePair(999 - points[i].first, 999 - points[i].second);
            addXEdges(graph, points);
            addYEdges(graph, points);

            IntSet tree = MinimalSpanningTree.minimalTree(graph);
            final long[] result = {0};
            if (tree != null)
                tree.forEach(value -> result[0] += graph.edge(value).getWeight());
            out.printLine(result[0]);
        }

        private void addYEdges(BidirectionalGraph graph, Pair<Integer, Integer>[] points) {
            Integer[] id = new Integer[points.length];
            for (int i = 0; i < points.length; i++)
                id[i] = i;
            Arrays.sort(id, (o1, o2) -> Pair.makePair(points[o1].second, -points[o1].first).compareTo(Pair.makePair(points[o2].second, -points[o2].first)));

            int[] BITMin = new int[2000];
            int[] BITMax = new int[2000];
            Arrays.fill(BITMax, -1);
            Arrays.fill(BITMin, -1);

            for (int _ = 0; _ < id.length; _++) {
                int i = id[_], j;

                j = -1;
                for (int k = -points[i].first - points[i].second + 1998; k > 0; k -= k & -k)
                    if (BITMin[k] != -1 && (j == -1 || -points[BITMin[k]].second + points[BITMin[k]].first < -points[j].second + points[j].first))
                        j = BITMin[k];
                if (j != -1)
                    graph.addWeightedEdge(i, j, manhattanDistance(points[i], points[j]));

                j = -1;
                for (int k = points[i].first - points[i].second + 1000; k > 0; k -= k & -k)
                    if (BITMax[k] != -1 && (j == -1 || points[BITMax[k]].first + points[BITMax[k]].second > points[j].first + points[j].second))
                        j = BITMax[k];
                if (j != -1)
                    graph.addWeightedEdge(i, j, manhattanDistance(points[i], points[j]));

                for (int k = -points[i].first - points[i].second + 1999; k < 2000; k += k & -k)
                    if (BITMin[k] == -1 || -points[BITMin[k]].second + points[BITMin[k]].first > -points[i].second + points[i].first)
                        BITMin[k] = i;
                for (int k = points[i].first - points[i].second + 1000; k < 2000; k += k & -k)
                    if (BITMax[k] == -1 || points[BITMax[k]].first + points[BITMax[k]].second < points[i].first + points[i].second)
                        BITMax[k] = i;

            }
        }

        private void addXEdges(BidirectionalGraph graph, Pair<Integer, Integer>[] points) {
            Integer[] id = new Integer[points.length];
            for (int i = 0; i < points.length; i++)
                id[i] = i;
            Arrays.sort(id, (o1, o2) -> points[o1].compareTo(points[o2]));

            int[] BITMin = new int[2000];
            int[] BITMax = new int[2000];
            Arrays.fill(BITMax, -1);
            Arrays.fill(BITMin, -1);

            for (int _ = 0; _ < id.length; _++) {
                int i = id[_], j;

                j = -1;
                for (int k = -points[i].first - points[i].second + 1999; k > 0; k -= k & -k)
                    if (BITMin[k] != -1 && (j == -1 || -points[BITMin[k]].first + points[BITMin[k]].second < -points[j].first + points[j].second))
                        j = BITMin[k];
                if (j != -1)
                    graph.addWeightedEdge(i, j, manhattanDistance(points[i], points[j]));

                j = -1;
                for (int k = points[i].second - points[i].first + 999; k > 0; k -= k & -k)
                    if (BITMax[k] != -1 && (j == -1 || points[BITMax[k]].first + points[BITMax[k]].second > points[j].first + points[j].second))
                        j = BITMax[k];
                if (j != -1)
                    graph.addWeightedEdge(i, j, manhattanDistance(points[i], points[j]));

                for (int k = -points[i].first - points[i].second + 1999; k < 2000; k += k & -k)
                    if (BITMin[k] == -1 || -points[BITMin[k]].first + points[BITMin[k]].second > -points[i].first + points[i].second)
                        BITMin[k] = i;
                for (int k = points[i].second - points[i].first + 1000; k < 2000; k += k & -k)
                    if (BITMax[k] == -1 || points[BITMax[k]].first + points[BITMax[k]].second < points[i].first + points[i].second)
                        BITMax[k] = i;

            }
        }

        private int manhattanDistance(Pair<Integer, Integer> p1, Pair<Integer, Integer> p2) {
            int dx = Math.abs(p1.first - p2.first);
            int dy = Math.abs(p1.second - p2.second);
            return dx + dy;
        }

    }

    static interface Edge {
        public long getWeight();

    }

    static class IntSortedArray extends IntSortedList {
        private final int[] array;

        public IntSortedArray(int[] array) {
            this(array, IntComparator.DEFAULT);
        }

        public IntSortedArray(IntCollection collection) {
            this(collection, IntComparator.DEFAULT);
        }

        public IntSortedArray(int[] array, IntComparator comparator) {
            super(comparator);
            this.array = array;
            ensureSorted();
        }

        public IntSortedArray(IntCollection collection, IntComparator comparator) {
            super(comparator);
            array = new int[collection.size()];
            int i = 0;
            for (IntIterator iterator = collection.iterator(); iterator.isValid(); iterator.advance())
                array[i++] = iterator.value();
            ensureSorted();
        }


        public int get(int index) {
            return array[index];
        }


        public int size() {
            return array.length;
        }

    }

    static interface IndependentSetSystem {
        public boolean join(int first, int second);

        public int getSetCount();

        public static interface Listener {
            public void joined(int joinedRoot, int root);

        }

    }

    static interface IntTask {
        public void process(int value);

    }

    static class Pair<U, V> implements Comparable<Pair<U, V>> {
        public final U first;
        public final V second;

        public static <U, V> Pair<U, V> makePair(U first, V second) {
            return new Pair<U, V>(first, second);
        }

        private Pair(U first, V second) {
            this.first = first;
            this.second = second;
        }


        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Pair pair = (Pair) o;

            return !(first != null ? !first.equals(pair.first) : pair.first != null) && !(second != null ? !second.equals(pair.second) : pair.second != null);

        }


        public int hashCode() {
            int result = first != null ? first.hashCode() : 0;
            result = 31 * result + (second != null ? second.hashCode() : 0);
            return result;
        }


        public String toString() {
            return "(" + first + "," + second + ")";
        }

        @SuppressWarnings({"unchecked"})
        public int compareTo(Pair<U, V> o) {
            int value = ((Comparable<U>) first).compareTo(o.first);
            if (value != 0)
                return value;
            return ((Comparable<V>) second).compareTo(o.second);
        }

    }

    static interface IntComparator {
        public static final IntComparator DEFAULT = new IntComparator() {
            public int compare(int first, int second) {
                if (first < second)
                    return -1;
                if (first > second)
                    return 1;
                return 0;
            }
        };

        public int compare(int first, int second);

    }

    static class BidirectionalGraph extends Graph {
        public int[] transposedEdge;

        public BidirectionalGraph(int vertexCount) {
            this(vertexCount, vertexCount);
        }

        public BidirectionalGraph(int vertexCount, int edgeCapacity) {
            super(vertexCount, 2 * edgeCapacity);
            transposedEdge = new int[2 * edgeCapacity];
        }


        public int addEdge(int fromID, int toID, long weight, long capacity, int reverseEdge) {
            int lastEdgeCount = edgeCount;
            super.addEdge(fromID, toID, weight, capacity, reverseEdge);
            super.addEdge(toID, fromID, weight, capacity, reverseEdge == -1 ? -1 : reverseEdge + 1);
            this.transposedEdge[lastEdgeCount] = lastEdgeCount + 1;
            this.transposedEdge[lastEdgeCount + 1] = lastEdgeCount;
            return lastEdgeCount;
        }


        protected int entriesPerEdge() {
            return 2;
        }


        protected void ensureEdgeCapacity(int size) {
            if (size > edgeCapacity()) {
                super.ensureEdgeCapacity(size);
                transposedEdge = resize(transposedEdge, edgeCapacity());
            }
        }

    }

    static abstract class IntSet extends IntCollection {
    }

    static class MinimalSpanningTree {
        public static IntSet minimalTree(final BidirectionalGraph graph) {
            IntSet result = new IntHashSet(graph.vertexCount - 1);
            int[] edgeOrder = new int[graph.edgeCount >> 1];
            for (int i = 0; i < edgeOrder.length; i++)
                edgeOrder[i] = i << 1;
            ArrayUtils.sort(edgeOrder, new IntComparator() {
                public int compare(int first, int second) {
                    return IntegerUtils.longCompare(graph.weight(first), graph.weight(second));
                }
            });
            IndependentSetSystem setSystem = new RecursiveIndependentSetSystem(graph.vertexCount);
            for (int i : edgeOrder) {
                if (setSystem.join(graph.source(i), graph.destination(i)))
                    result.add(i);
            }
            if (setSystem.getSetCount() == 1)
                return result;
            else
                return null;
        }

    }

    static abstract class IntCollection {
        public abstract IntIterator iterator();

        public abstract int size();

        public abstract void add(int value);

        public void forEach(IntTask task) {
            for (IntIterator iterator = iterator(); iterator.isValid(); iterator.advance())
                task.process(iterator.value());
        }

    }

    static interface IntIterator {
        public int value();

        public void advance();

        public boolean isValid();

    }

    static class Graph {
        protected int vertexCount;
        protected int edgeCount;
        private int[] firstOutbound;
        private int[] firstInbound;
        private Edge[] edges;
        private int[] nextInbound;
        private int[] nextOutbound;
        private int[] from;
        private int[] to;
        private long[] weight;
        public long[] capacity;
        private int[] reverseEdge;
        private int[] flags;

        public Graph(int vertexCount) {
            this(vertexCount, vertexCount);
        }

        public Graph(int vertexCount, int edgeCapacity) {
            this.vertexCount = vertexCount;
            firstOutbound = new int[vertexCount];
            Arrays.fill(firstOutbound, -1);

            from = new int[edgeCapacity];
            to = new int[edgeCapacity];
            nextOutbound = new int[edgeCapacity];
            flags = new int[edgeCapacity];
        }

        public int addEdge(int fromID, int toID, long weight, long capacity, int reverseEdge) {
            ensureEdgeCapacity(edgeCount + 1);
            if (firstOutbound[fromID] != -1)
                nextOutbound[edgeCount] = firstOutbound[fromID];
            else
                nextOutbound[edgeCount] = -1;
            firstOutbound[fromID] = edgeCount;
            if (firstInbound != null) {
                if (firstInbound[toID] != -1)
                    nextInbound[edgeCount] = firstInbound[toID];
                else
                    nextInbound[edgeCount] = -1;
                firstInbound[toID] = edgeCount;
            }
            this.from[edgeCount] = fromID;
            this.to[edgeCount] = toID;
            if (capacity != 0) {
                if (this.capacity == null)
                    this.capacity = new long[from.length];
                this.capacity[edgeCount] = capacity;
            }
            if (weight != 0) {
                if (this.weight == null)
                    this.weight = new long[from.length];
                this.weight[edgeCount] = weight;
            }
            if (reverseEdge != -1) {
                if (this.reverseEdge == null) {
                    this.reverseEdge = new int[from.length];
                    Arrays.fill(this.reverseEdge, 0, edgeCount, -1);
                }
                this.reverseEdge[edgeCount] = reverseEdge;
            }
            if (edges != null)
                edges[edgeCount] = createEdge(edgeCount);
            return edgeCount++;
        }

        protected final GraphEdge createEdge(int id) {
            return new GraphEdge(id);
        }

        public final int addFlowWeightedEdge(int from, int to, long weight, long capacity) {
            if (capacity == 0) {
                return addEdge(from, to, weight, 0, -1);
            } else {
                int lastEdgeCount = edgeCount;
                addEdge(to, from, -weight, 0, lastEdgeCount + entriesPerEdge());
                return addEdge(from, to, weight, capacity, lastEdgeCount);
            }
        }

        protected int entriesPerEdge() {
            return 1;
        }

        public final int addWeightedEdge(int from, int to, long weight) {
            return addFlowWeightedEdge(from, to, weight, 0);
        }

        protected final int edgeCapacity() {
            return from.length;
        }

        public final Edge edge(int id) {
            initEdges();
            return edges[id];
        }

        public final int source(int id) {
            return from[id];
        }

        public final int destination(int id) {
            return to[id];
        }

        public final long weight(int id) {
            if (weight == null)
                return 0;
            return weight[id];
        }

        protected final void initEdges() {
            if (edges == null) {
                edges = new Edge[from.length];
                for (int i = 0; i < edgeCount; i++)
                    edges[i] = createEdge(i);
            }
        }

        protected void ensureEdgeCapacity(int size) {
            if (from.length < size) {
                int newSize = Math.max(size, 2 * from.length);
                if (edges != null)
                    edges = resize(edges, newSize);
                from = resize(from, newSize);
                to = resize(to, newSize);
                nextOutbound = resize(nextOutbound, newSize);
                if (nextInbound != null)
                    nextInbound = resize(nextInbound, newSize);
                if (weight != null)
                    weight = resize(weight, newSize);
                if (capacity != null)
                    capacity = resize(capacity, newSize);
                if (reverseEdge != null)
                    reverseEdge = resize(reverseEdge, newSize);
                flags = resize(flags, newSize);
            }
        }

        protected final int[] resize(int[] array, int size) {
            int[] newArray = new int[size];
            System.arraycopy(array, 0, newArray, 0, array.length);
            return newArray;
        }

        private long[] resize(long[] array, int size) {
            long[] newArray = new long[size];
            System.arraycopy(array, 0, newArray, 0, array.length);
            return newArray;
        }

        private Edge[] resize(Edge[] array, int size) {
            Edge[] newArray = new Edge[size];
            System.arraycopy(array, 0, newArray, 0, array.length);
            return newArray;
        }

        protected class GraphEdge implements Edge {
            protected int id;

            protected GraphEdge(int id) {
                this.id = id;
            }

            public long getWeight() {
                return weight(id);
            }

        }

    }

    static class IntArray extends IntList {
        private final int[] array;

        public IntArray(int[] array) {
            this.array = array;
        }

        public IntArray(IntCollection collection) {
            array = new int[collection.size()];
            int i = 0;
            for (IntIterator iterator = collection.iterator(); iterator.isValid(); iterator.advance())
                array[i++] = iterator.value();
        }


        public int get(int index) {
            return array[index];
        }


        public void set(int index, int value) {
            array[index] = value;
        }


        public int size() {
            return array.length;
        }


        public void add(int value) {
            throw new UnsupportedOperationException();
        }

    }

    static abstract class IntList extends IntCollection implements Comparable<IntList> {
        private static final int INSERTION_THRESHOLD = 16;

        public abstract int get(int index);

        public abstract void set(int index, int value);


        public IntIterator iterator() {
            return new IntIterator() {
                private int size = size();
                private int index = 0;

                public int value() throws NoSuchElementException {
                    if (!isValid())
                        throw new NoSuchElementException();
                    return get(index);
                }

                public void advance() throws NoSuchElementException {
                    if (!isValid())
                        throw new NoSuchElementException();
                    index++;
                }

                public boolean isValid() {
                    return index < size;
                }
            };
        }

        public IntList subList(final int from, final int to) {
            return new SubList(from, to);
        }

        private void swap(int first, int second) {
            if (first == second)
                return;
            int temp = get(first);
            set(first, get(second));
            set(second, temp);
        }

        public IntSortedList inPlaceSort(IntComparator comparator) {
            quickSort(0, size() - 1, (Integer.bitCount(Integer.highestOneBit(size()) - 1) * 5) >> 1, comparator);
            return new IntSortedArray(this, comparator);
        }

        private void quickSort(int from, int to, int remaining, IntComparator comparator) {
            if (to - from < INSERTION_THRESHOLD) {
                insertionSort(from, to, comparator);
                return;
            }
            if (remaining == 0) {
                heapSort(from, to, comparator);
                return;
            }
            remaining--;
            int pivotIndex = (from + to) >> 1;
            int pivot = get(pivotIndex);
            swap(pivotIndex, to);
            int storeIndex = from;
            int equalIndex = to;
            for (int i = from; i < equalIndex; i++) {
                int value = comparator.compare(get(i), pivot);
                if (value < 0)
                    swap(storeIndex++, i);
                else if (value == 0)
                    swap(--equalIndex, i--);
            }
            quickSort(from, storeIndex - 1, remaining, comparator);
            for (int i = equalIndex; i <= to; i++)
                swap(storeIndex++, i);
            quickSort(storeIndex, to, remaining, comparator);
        }

        private void heapSort(int from, int to, IntComparator comparator) {
            for (int i = (to + from - 1) >> 1; i >= from; i--)
                siftDown(i, to, comparator, from);
            for (int i = to; i > from; i--) {
                swap(from, i);
                siftDown(from, i - 1, comparator, from);
            }
        }

        private void siftDown(int start, int end, IntComparator comparator, int delta) {
            int value = get(start);
            while (true) {
                int child = ((start - delta) << 1) + 1 + delta;
                if (child > end)
                    return;
                int childValue = get(child);
                if (child + 1 <= end) {
                    int otherValue = get(child + 1);
                    if (comparator.compare(otherValue, childValue) > 0) {
                        child++;
                        childValue = otherValue;
                    }
                }
                if (comparator.compare(value, childValue) >= 0)
                    return;
                swap(start, child);
                start = child;
            }
        }

        private void insertionSort(int from, int to, IntComparator comparator) {
            for (int i = from + 1; i <= to; i++) {
                int value = get(i);
                for (int j = i - 1; j >= from; j--) {
                    if (comparator.compare(get(j), value) <= 0)
                        break;
                    swap(j, j + 1);
                }
            }
        }

        public int hashCode() {
            int hashCode = 1;
            for (IntIterator i = iterator(); i.isValid(); i.advance())
                hashCode = 31 * hashCode + i.value();
            return hashCode;
        }


        public boolean equals(Object obj) {
            if (!(obj instanceof IntList))
                return false;
            IntList list = (IntList) obj;
            if (list.size() != size())
                return false;
            IntIterator i = iterator();
            IntIterator j = list.iterator();
            while (i.isValid()) {
                if (i.value() != j.value())
                    return false;
                i.advance();
                j.advance();
            }
            return true;
        }

        public int compareTo(IntList o) {
            IntIterator i = iterator();
            IntIterator j = o.iterator();
            while (true) {
                if (i.isValid()) {
                    if (j.isValid()) {
                        if (i.value() != j.value()) {
                            if (i.value() < j.value())
                                return -1;
                            else
                                return 1;
                        }
                    } else
                        return 1;
                } else {
                    if (j.isValid())
                        return -1;
                    else
                        return 0;
                }
                i.advance();
                j.advance();
            }
        }

        private class SubList extends IntList {
            private final int to;
            private final int from;
            private int size;

            public SubList(int from, int to) {
                this.to = to;
                this.from = from;
                size = to - from;
            }


            public int get(int index) {
                if (index < 0 || index >= size)
                    throw new IndexOutOfBoundsException();
                return IntList.this.get(index + from);
            }


            public void set(int index, int value) {
                if (index < 0 || index >= size)
                    throw new IndexOutOfBoundsException();
                IntList.this.set(index + from, value);
            }


            public int size() {
                return size;
            }


            public void add(int value) {
                throw new UnsupportedOperationException();
            }

        }

    }

    static abstract class IntSortedList extends IntList {
        protected final IntComparator comparator;

        protected IntSortedList(IntComparator comparator) {
            this.comparator = comparator;
        }


        public void set(int index, int value) {
            throw new UnsupportedOperationException();
        }


        public void add(int value) {
            throw new UnsupportedOperationException();
        }


        public IntSortedList inPlaceSort(IntComparator comparator) {
            if (comparator == this.comparator)
                return this;
            throw new UnsupportedOperationException();
        }

        protected void ensureSorted() {
            int size = size();
            if (size == 0)
                return;
            int last = get(0);
            for (int i = 1; i < size; i++) {
                int current = get(i);
                if (comparator.compare(last, current) > 0)
                    throw new IllegalArgumentException();
                last = current;
            }
        }


        public IntSortedList subList(final int from, final int to) {
            return new IntSortedList(comparator) {
                private int size = to - from;


                public int get(int index) {
                    if (index < 0 || index >= size)
                        throw new IndexOutOfBoundsException();
                    return IntSortedList.this.get(index + from);
                }


                public int size() {
                    return size;
                }
            };
        }

    }

    static class IntegerUtils {
        public static int gcd(int a, int b) {
            a = Math.abs(a);
            b = Math.abs(b);
            while (b != 0) {
                int temp = a % b;
                a = b;
                b = temp;
            }
            return a;
        }

        public static int longCompare(long a, long b) {
            if (a < b)
                return -1;
            if (a > b)
                return 1;
            return 0;
        }

    }

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void close() {
            writer.close();
        }

        public void printLine(long i) {
            writer.println(i);
        }

    }

    static class IntHashSet extends IntSet {
        private static final Random RND = new Random();
        private static final int[] SHIFTS = new int[4];
        private static final byte PRESENT_MASK = 1;
        private int size;
        private int realSize;
        private int[] values;
        private byte[] present;
        private int step;
        private int ratio;

        static {
            for (int i = 0; i < 4; i++)
                SHIFTS[i] = RND.nextInt(31) + 1;
        }

        public IntHashSet() {
            this(3);
        }

        public IntHashSet(int capacity) {
            capacity = Math.max(capacity, 1);
            values = new int[capacity];
            present = new byte[capacity];
            ratio = 2;
            initStep(capacity);
        }

        private void initStep(int capacity) {
            step = RND.nextInt(capacity - 2) + 1;
            while (IntegerUtils.gcd(step, capacity) != 1)
                step++;
        }


        public IntIterator iterator() {
            return new IntIterator() {
                private int position = size == 0 ? values.length : -1;

                public int value() throws NoSuchElementException {
                    if (position == -1)
                        advance();
                    if (position >= values.length)
                        throw new NoSuchElementException();
                    return values[position];
                }

                public void advance() throws NoSuchElementException {
                    if (position >= values.length)
                        throw new NoSuchElementException();
                    position++;
                    while (position < values.length && (present[position] & PRESENT_MASK) == 0)
                        position++;
                }

                public boolean isValid() {
                    return position < values.length;
                }
            };
        }


        public int size() {
            return size;
        }


        public void add(int value) {
            ensureCapacity((realSize + 1) * ratio + 2);
            int current = getHash(value);
            while (present[current] != 0) {
                if ((present[current] & PRESENT_MASK) != 0 && values[current] == value) {
                    return;
                }
                current += step;
                if (current >= values.length)
                    current -= values.length;
            }
            while ((present[current] & PRESENT_MASK) != 0) {
                current += step;
                if (current >= values.length)
                    current -= values.length;
            }
            if (present[current] == 0) {
                realSize++;
            }
            present[current] = PRESENT_MASK;
            values[current] = value;
            size++;
        }

        private int getHash(int value) {
            int result = value;
            for (int i : SHIFTS)
                result ^= value >> i;
            result %= values.length;
            if (result < 0)
                result += values.length;
            return result;
        }

        private void ensureCapacity(int capacity) {
            if (values.length < capacity) {
                capacity = Math.max(capacity * 2, values.length);
                rebuild(capacity);
            }
        }

        private void rebuild(int capacity) {
            initStep(capacity);
            int[] oldValues = values;
            byte[] oldPresent = present;
            values = new int[capacity];
            present = new byte[capacity];
            size = 0;
            realSize = 0;
            for (int i = 0; i < oldValues.length; i++) {
                if ((oldPresent[i] & PRESENT_MASK) == PRESENT_MASK)
                    add(oldValues[i]);
            }
        }

    }

    static class ArrayUtils {
        public static int[] sort(int[] array, IntComparator comparator) {
            return sort(array, 0, array.length, comparator);
        }

        public static int[] sort(int[] array, int from, int to, IntComparator comparator) {
            if (from == 0 && to == array.length)
                new IntArray(array).inPlaceSort(comparator);
            else
                new IntArray(array).subList(from, to).inPlaceSort(comparator);
            return array;
        }

    }

    static class RecursiveIndependentSetSystem implements IndependentSetSystem {
        private final int[] color;
        private final int[] rank;
        private int setCount;
        private Listener listener;

        public RecursiveIndependentSetSystem(int size) {
            color = new int[size];
            rank = new int[size];
            for (int i = 0; i < size; i++)
                color[i] = i;
            setCount = size;
        }

        public RecursiveIndependentSetSystem(RecursiveIndependentSetSystem other) {
            color = other.color.clone();
            rank = other.rank.clone();
            setCount = other.setCount;
        }

        public boolean join(int first, int second) {
            first = get(first);
            second = get(second);
            if (first == second)
                return false;
            if (rank[first] < rank[second]) {
                int temp = first;
                first = second;
                second = temp;
            } else if (rank[first] == rank[second])
                rank[first]++;
            setCount--;
            color[second] = first;
            if (listener != null)
                listener.joined(second, first);
            return true;
        }

        public int get(int index) {
            if (color[index] == index)
                return index;
            return color[index] = get(color[index]);
        }

        public int getSetCount() {
            return setCount;
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private SpaceCharFilter filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (numChars == -1)
                throw new InputMismatchException();
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        public int readInt() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public boolean isSpaceChar(int c) {
            if (filter != null)
                return filter.isSpaceChar(c);
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

        }

    }
}

