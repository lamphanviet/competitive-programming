import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

public class uva10183_How_Many_Fibs {
	static int maxN = 480;
	static BigInteger f[] = new BigInteger[maxN];

	public static void PreCal() {
		f[1] = new BigInteger("1");
		f[2] = new BigInteger("2");
		for (int i=3; i<maxN; i++)
			f[i] = f[i-1].add(f[i-2]);
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		PreCal();
		Scanner sc = new Scanner(System.in);
		PrintWriter pw = new PrintWriter(System.out);
		BigInteger a, b;
		BigInteger zero = new BigInteger("0");
		while (true) {
			a = new BigInteger(sc.next());
			b = new BigInteger(sc.next());
			if (a.compareTo(zero)==0 && b.compareTo(zero)==0) break;
			int u = 1, v;
			for (; u<maxN; u++)
				if (f[u].compareTo(a)>=0) break;
			v = u;
			for (; v<maxN; v++)
				if (f[v].compareTo(b)>0) break;
			pw.println(v-u);
		}
		sc.close();
		pw.close();
	}

}
