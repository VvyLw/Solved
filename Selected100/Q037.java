import static java.lang.Math.*;

import java.io.Closeable;
import java.io.Flushable;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Collection;
import java.util.Formatter;
import java.util.Random;
import java.util.function.IntUnaryOperator;
import java.util.function.LongUnaryOperator;
import java.util.stream.IntStream;

final class Q037 {
	public static void main(final String[] args) {
		IntStream.range(0, VvyLw.MULTI ? VvyLw.io.ni() : 1).forEach(i -> VvyLw.solve());
		VvyLw.io.close();
	}
}

final class VvyLw extends Utility {
	static final IO io = new IO(System.in, System.out, System.err, false);
	static final Random rd = new Random();
	static final boolean MULTI = false;
	static final int INF = 1 << 30;
	static final long LINF = (1L << 61) - 1;
	static final double EPS = 1e-18;
	static final int MOD = 998244353;
	static final int M0D = (int) 1e9 + 7;
	static final int[] dx = {0, -1, 1, 0, 0, -1, -1, 1, 1};
	static final int[] dy = {0, 0, 0, -1, 1, -1, 1, -1, 1};
	static final void solve() {
		final int n = io.ni(), m = io.ni();
		final var c = io.ni(m);
		final var dp = new long[n + 1];
		Arrays.fill(dp, LINF);
		dp[0] = 0;
		for(int i = 0; i < m; ++i) {
			for(int j = 0; j <= n; ++j) {
				if(j + c[i] <= n) {
					dp[j + c[i]] = min(dp[j + c[i]], dp[j] + 1);
				}
			}
		}
		io.out(dp[n]);
	}
}
class Utility {
	protected static final String yes(final boolean ok){ return ok ? "Yes" : "No"; }
	protected static final String no(final boolean ok){ return yes(!ok); }
	protected static final long sqr(final long x){ return x * x; }
	protected static final int mod(long n, final int m) {
		n %= m;
		return (int) (n < 0 ? n + m : n);
	}
	protected static final long mod(long n, final long m) {
		n %= m;
		return n < 0 ? n + m : n;
	}
	protected static final long intCeil(final long a, final long b){ return a == 0 ? 0 : (a - 1) / b + 1; }
	protected static final double intRound(final double a, final long b, final int c) {
		final long d = intPow(10, c);
		return rint((a * d) / b) / d;
	}
	protected static final long intPow(long a, int b) {
		long res = 1;
		while(b > 0) {
			if(b % 2 == 1) {
				res *= a;
			}
			a *= a;
			b >>= 1;
		}
		return res;
	}
	protected static final long intPow(long a, long b, final long m) {
		long res = 1;
		while(b > 0) {
			if(b % 2 == 1) {
				res *= a;
				res = mod(res, m);
			}
			a *= a;
			a = mod(a, m);
			b >>= 1;
		}
		return res;
	}
	protected static final int min(final int... a){ return Arrays.stream(a).min().getAsInt(); }
	protected static final long min(final long... a){ return Arrays.stream(a).min().getAsLong(); }
	protected static final double min(final double... a){ return Arrays.stream(a).min().getAsDouble(); }
	protected static final int max(final int... a){ return Arrays.stream(a).max().getAsInt(); }
	protected static final long max(final long... a){ return Arrays.stream(a).max().getAsLong(); }
	protected static final double max(final double... a){ return Arrays.stream(a).max().getAsDouble(); }
	protected static final long sum(final int... a){ return Arrays.stream(a).asLongStream().sum(); }
	protected static final long sum(final long... a){ return Arrays.stream(a).sum(); }
	protected static final double sum(final double... a){ return Arrays.stream(a).sum(); }
	protected static final boolean scope(final int l, final int x, final int r){ return l <= x && x <= r; }
	protected static final boolean scope(final long l, final long x, final long r){ return l <= x && x <= r; }
	protected static final boolean scope(final double l, final double x, final double r){ return l <= x && x <= r; }
	public static final IntStream iota(final int n){ return IntStream.range(0, n); }
	public static final IntStream iota(final int n, final int init){ return IntStream.range(0 + init, n + init); }
}

final class IO implements Closeable, AutoCloseable {
	private final MyScanner in;
	private final MyPrinter out, err;
	private final boolean autoFlush;
	IO(final InputStream in, final OutputStream out, final OutputStream err, final boolean autoFlush) {
		this.in = new MyScanner(in);
		this.out = new MyPrinter(out, this.autoFlush = autoFlush);
		this.err = new MyPrinter(err, true);
	}
	final int ni(){ return in.ni(); }
	final long nl(){ return in.nl(); }
	final double nd(){ return in.nd(); }
	final char nc(){ return in.nc(); }
	final String ns(){ return in.ns(); }
	final char[] nt(){ return in.nt(); }
	final BigInteger nb(){ return in.nb(); }
	final int[] ni(final int n) {
		final int[] a = new int[n];
		Arrays.setAll(a, i -> ni());
		return a;
	}
	final int[] ni(final int n, final IntUnaryOperator f){ return Arrays.stream(ni(n)).map(f).toArray(); }
	final long[] nl(final int n) {
		final long[] a = new long[n];
		Arrays.setAll(a, i -> nl());
		return a;
	}
	final long[] nl(final int n, final LongUnaryOperator f){ return Arrays.stream(nl(n)).map(f).toArray(); }
	final double[] nd(final int n) {
		final double[] a = new double[n];
		Arrays.setAll(a, i -> nd());
		return a;
	}
	final char[] nc(final int n) {
		final char[] a = new char[n];
		IntStream.range(0, n).forEach(i -> a[i] = nc());
		return a;
	}
	final String[] ns(final int n) {
		final String[] a = new String[n];
		Arrays.setAll(a, i -> ns());
		return a;
	}
	final char[][] nt(final int n) {
		final char[][] a = new char[n][];
		Arrays.setAll(a, i -> nt());
		return a;
	}
	final BigInteger[] nb(final int n) {
		final BigInteger[] a = new BigInteger[n];
		Arrays.setAll(a, i -> nb());
		return a;
	}
	final int[][] ni(final int h, final int w) {
		final int[][] a = new int[h][w];
		Arrays.setAll(a, i -> ni(w));
		return a;
	}
	final long[][] nl(final int h, final int w) {
		final long[][] a = new long[h][w];
		Arrays.setAll(a, i -> nl(w));
		return a;
	}
	final double[][] nd(final int h, final int w) {
		final double[][] a = new double[h][w];
		Arrays.setAll(a, i -> nd(w));
		return a;
	}
	final char[][] nc(final int h, final int w) {
		final char[][] a = new char[h][w];
		Arrays.setAll(a, i -> nc(w));
		return a;
	}
	final String[][] ns(final int h, final int w) {
		final String[][] a = new String[h][w];
		Arrays.setAll(a, i -> ns(w));
		return a;
	}
	final BigInteger[][] nb(final int h, final int w) {
		final BigInteger[][] a = new BigInteger[h][w];
		Arrays.setAll(a, i -> nb(w));
		return a;
	}
	final String line(){ return in.line(); }
	final void print(final Object arg){ out.print(arg); }
	final void printf(final String fmt, final Object... args){ out.printf(fmt, args); }
	final void out(){ out.out(); }
	final void out(final Object head, final Object... tail){ out.out(head, tail); }
	final <E> void out(final Collection<E> a){ out.out(a); }
	final void out(final int[] head, final int[]...tail){ out.out(head, tail); }
	final void out(final long[] head, final long[]...tail){ out.out(head, tail); }
	final void out(final double[] head, final double[]...tail){ out.out(head, tail); }
	final void out(final boolean[] head, final boolean[]...tail){ out.out(head, tail); }
	final void out(final char[] head, final char[]...tail){ out.out(head, tail); }
	final void out(final Object[] head, final Object[]...tail){ out.out(head, tail); }
	final void out(final int[][] args){ IntStream.range(0, args.length).forEach(i -> out(args[i])); }
	final void out(final long[][] args){ IntStream.range(0, args.length).forEach(i -> out(args[i])); }
	final void out(final double[][] args){ IntStream.range(0, args.length).forEach(i -> out(args[i])); }
	final void out(final boolean[][] args){ IntStream.range(0, args.length).forEach(i -> out(args[i])); }
	final void out(final char[][] args){ IntStream.range(0, args.length).forEach(i -> out(args[i])); }
	final void out(final Object[][] args){ IntStream.range(0, args.length).forEach(i -> out(args[i])); }
	final void outl(final Object head, final Object... tail) {
		out(head);
		Arrays.stream(tail).forEach(this::out);
	}
	final void fin(final Object head, final Object... tail) {
		out(head, tail);
		if(!autoFlush) {
			out.flush();
		}
		System.exit(0);
	}
	final <E> void fin(final Collection<E> args) {
		out(args);
		if(!autoFlush) {
			out.flush();
		}
		System.exit(0);
	}
	final void fin(final int[] args) {
		out(args);
		if(!autoFlush) {
			out.flush();
		}
		System.exit(0);
	}
	final void fin(final long[] args) {
		out(args);
		if(!autoFlush) {
			out.flush();
		}
		System.exit(0);
	}
	final void fin(final double[] args) {
		out(args);
		if(!autoFlush) {
			out.flush();
		}
		System.exit(0);
	}
	final void fin(final boolean[] args) {
		out(args);
		if(!autoFlush) {
			out.flush();
		}
		System.exit(0);
	}
	final void fin(final char[] args) {
		out(args);
		if(!autoFlush) {
			out.flush();
		}
		System.exit(0);
	}
	final void fin(final Object[] args) {
		out(args);
		if(!autoFlush) {
			out.flush();
		}
		System.exit(0);
	}
	final void fin(final int[][] args) {
		out(args);
		if(!autoFlush) {
			out.flush();
		}
		System.exit(0);
	}
	final void fin(final long[][] args) {
		out(args);
		if(!autoFlush) {
			out.flush();
		}
		System.exit(0);
	}
	final void fin(final double[][] args) {
		out(args);
		if(!autoFlush) {
			out.flush();
		}
		System.exit(0);
	}
	final void fin(final boolean[][] args) {
		out(args);
		if(!autoFlush) {
			out.flush();
		}
		System.exit(0);
	}
	final void fin(final char[][] args) {
		out(args);
		if(!autoFlush) {
			out.flush();
		}
		System.exit(0);
	}
	final void fin(final Object[][] args) {
		out(args);
		if(!autoFlush) {
			out.flush();
		}
		System.exit(0);
	}
	final void ende(final Object head, final Object... tail) {
		outl(head, tail);
		if(!autoFlush) {
			out.flush();
		}
		System.exit(0);
	}
	final void dump(final Object head, final Object... tail){ err.out(head, tail); }
	final void dump(final int[] head, final int[]...tail){ err.out(head, tail); }
	final void dump(final long[] head, final long[]...tail){ err.out(head, tail); }
	final void dump(final double[] head, final double[]...tail){ err.out(head, tail); }
	final void dump(final boolean[] head, final boolean[]...tail){ err.out(head, tail); }
	final void dump(final char[] head, final char[]...tail){ err.out(head, tail); }
	final void dump(final Object[] head, final Object[]...tail){ err.out(head, tail); }
	final void dump(final int[][] args){ IntStream.range(0, args.length).forEach(i -> dump(args[i])); }
	final void dump(final long[][] args){ IntStream.range(0, args.length).forEach(i -> dump(args[i])); }
	final void dump(final double[][] args){ IntStream.range(0, args.length).forEach(i -> dump(args[i])); }
	final void dump(final boolean[][] args){ IntStream.range(0, args.length).forEach(i -> dump(args[i])); }
	final void dump(final char[][] args){ IntStream.range(0, args.length).forEach(i -> dump(args[i])); }
	final void dump(final Object[][] args){ IntStream.range(0, args.length).forEach(i -> dump(args[i])); }
	@Override
	public final void close() {
		out.flush();
		in.close();
		out.close();
		err.close();
	}
	private final class MyScanner implements Closeable, AutoCloseable {
		private int pos, lim;
		private final byte[] buf;
		private final InputStream is;
		private boolean check;
		MyScanner(final InputStream is) {
			this.is = is;
			pos = lim = 0;
			buf = new byte[1 << 17];
			check = false;
		}
		private final boolean isPunct(final byte bt){ return !Utility.scope(33, bt, 126); }
		private final boolean isNum(final byte bt){ return Utility.scope('0', bt, '9'); }
		private final byte read() {
			if(pos == lim && lim != -1) {
				try {
					lim = is.read(buf);
					pos = 0;
				} catch(final IOException e) {
					e.printStackTrace();
				}
			}
			return buf[pos++];
		}
		private final byte next() {
			byte bt;
			if(check) {
				check = false;
				bt = buf[pos - 1];
				if(!isPunct(bt)) {
					return bt;
				}
			}
			while(isPunct(bt = read())){}
			return bt;
		}
		final int ni(){ return toIntExact(nl()); }
		final long nl() {
			byte c = next();
			final boolean neg = c == '-';
			if(neg) {
				c = next();
			}
			assert isNum(c);
			long res = c - '0';
			while(isNum(c = read())) {
				res = 10 * res + c - '0';
			}
			check = !isNum(c);
			return neg ? -res : res;
		}
		final double nd() {
			byte c = next();
			final boolean neg = c == '-';
			if(neg) {
				c = next();
			}
			assert isNum(c);
			double res = c - '0';
			while(isNum(c = read())) {
				res = 10 * res + c - '0';
			}
			if(c != '.') {
				check = true;
				return res;
			}
			int i;
			for(i = 0; isNum(c = read()); ++i) {
				res = res * 10 + c - '0';
			}
			res /= pow(10, i);
			check = true;
			return neg ? -res : res;
		}
		final char nc(){ return (char) next(); }
		final String ns() {
			final StringBuilder sb = new StringBuilder();
			byte c = next();
			while(!isPunct(c)) {
				sb.append((char) c);
				c = read();
			}
			return sb.toString();
		}
		final char[] nt(){ return ns().toCharArray(); }
		final BigInteger nb(){ return new BigInteger(ns()); }
		final String line() {
			final StringBuilder sb = new StringBuilder();
			byte c;
			while((c = read()) != '\n') {
				sb.append((char) c);
			}
			return sb.toString();
		}
		@Override
		public final void close() {
			try {
				is.close();
			} catch(final IOException e) {
				e.printStackTrace();
			}
		}
	}
	private final class MyPrinter implements Closeable, Flushable, AutoCloseable {
		private OutputStream os;
		private final boolean autoFlush;
		private final byte[] buf;
		private int pos;
		private final boolean debug;
		MyPrinter(final OutputStream os, final boolean autoFlush){
			this.os = os;
			this.autoFlush = autoFlush;
			buf = new byte[1 << 17];
			pos = 0;
			debug = os == System.err;
		}
		private final void write(final byte bt) {
			buf[pos++] = bt;
			if(pos == buf.length) {
				flush();
			}
		}
		private final void newLine() {
			write((byte) '\n');
			if(autoFlush) {
				flush();
			}
		}
		final void print(final Object arg) {
			if(arg instanceof String) {
				final String s = (String) arg;
				for(final char c: s.toCharArray()) {
					write((byte) c);
				}
			} else {
				print(String.valueOf(arg));
			}
			if(autoFlush) {
				flush();
			}
		}
		final void printf(final String fmt, final Object... args) {
			print(new Formatter().format(fmt, args));
			if(autoFlush) {
				flush();
			}
		}
		final void out(){ newLine(); }
		final void out(final Object head, final Object... tail) {
			print(head);
			for(final var el: tail) {
				print(" " + el);
			}
			newLine();
		}
		final <E> void out(final Collection<E> args) {
			if(debug) {
				print(args.toString());
			} else {
				int i = 0;
				for(final var el: args) {
					print(el);
					if(++i != args.size()) {
						print(" ");
					}
				}
			}
			newLine();
		}
		private final void out(final int[] args) {
			if(debug) {
				print(Arrays.toString(args));
			} else if(args.length > 0) {
				print(args[0]);
				for(int i = 0; ++i < args.length;) {
					print(" " + args[i]);
				}
			}
			newLine();
		}
		final void out(final int[] head, final int[]... tail) {
			out(head);
			for(final int[] a: tail) {
				out(a);
			}
		}
		private final void out(final long[] args) {
			if(debug) {
				print(Arrays.toString(args));
			} else if(args.length > 0) {
				print(args[0]);
				for(int i = 0; ++i < args.length;) {
					print(" " + args[i]);
				}
			}
			newLine();
		}
		final void out(final long[] head, final long[]... tail) {
			out(head);
			for(final long[] a: tail) {
				out(a);
			}
		}
		private final void out(final double[] args) {
			if(debug) {
				print(Arrays.toString(args));
			} else if(args.length > 0) {
				print(args[0]);
				for(int i = 0; ++i < args.length;) {
					print(" " + args[i]);
				}
			}
			newLine();
		}
		final void out(final double[] head, final double[]... tail) {
			out(head);
			for(final double[] a: tail) {
				out(a);
			}
		}
		private final void out(final boolean[] args) {
			if(debug) {
				print(Arrays.toString(args));
			} else if(args.length > 0) {
				print(args[0]);
				for(int i = 0; ++i < args.length;) {
					print(" " + args[i]);
				}
			}
			newLine();
		}
		final void out(final boolean[] head, final boolean[]... tail) {
			out(head);
			for(final boolean[] a: tail) {
				out(a);
			}
		}
		private final void out(final char[] args) {
			if(args.length > 0) {
				print(args[0]);
				for(int i = 0; ++i < args.length;) {
					print(" " + args[i]);
				}
			}
			newLine();
		}
		final void out(final char[] head, final char[]... tail) {
			out(head);
			for(final char[] a: tail) {
				out(a);
			}
		}
		private final void out(final Object[] args) {
			if(debug) {
				print(Arrays.toString(args));
			} else if(args.length > 0) {
				print(args[0]);
				for(int i = 0; ++i < args.length;) {
					print(" " + args[i]);
				}
			}
			newLine();
		}
		final void out(final Object[] head, final Object[]... tail) {
			out(head);
			for(final Object[] a: tail) {
				out(a);
			}
		}
		@Override
		public final void flush() {
			try {
				os.write(buf, 0, pos);
				pos = 0;
			} catch(final IOException e) {
				e.printStackTrace();
			}
		}
		@Override
		public final void close() {
			if(os == null) {
				return;
			}
			try {
				os.close();
				os = null;
			} catch(final IOException e) {
				e.printStackTrace();
			}
		}
	}
}
