import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;


public class uva763_Fibinary_Numbers {

	static int maxN = 105;
	static BigInteger fibo[] = new BigInteger[maxN];
	
	static void fibo_precal() {
		fibo[0] = BigInteger.ONE;
		fibo[1] = BigInteger.valueOf(2);
		for (int i = 2; i < maxN; i++)
			fibo[i] = fibo[i-2].add(fibo[i-1]);
	}
	
	static BigInteger ConvertToBig(StringBuffer a) {
		BigInteger res = BigInteger.ZERO;
		for (int i = a.length() - 1, j = 0; i >= 0; i--, j++)
			if (a.charAt(i)=='1')
				res = res.add(fibo[j]);
		return res;
	}
	
	public static void main(String[] args) {
		
		fibo_precal();
		
		Scanner sc = new Scanner(System.in);
		PrintWriter pw = new PrintWriter(System.out);
		boolean Line = false;
		
		while (sc.hasNext()) {
			StringBuffer a = new StringBuffer(sc.next());
			StringBuffer b = new StringBuffer(sc.next());
			
			BigInteger sum = ConvertToBig(a).add(ConvertToBig(b));
			String res = "";
			
			for (int i = maxN - 1; i >= 0; i--)
				if (sum.compareTo(fibo[i]) >= 0) {
					res += '1';
					sum = sum.subtract(fibo[i]);
				}
				else res += '0';
			
			if (Line) pw.println(); Line = true;
			int i = 0;
			while (i + 1 < res.length() && res.charAt(i)=='0') i++;
			while (i < res.length())
				pw.print(res.charAt(i++));
			pw.println();
			
			if (sc.hasNext()) sc.nextLine();
		}
		
		sc.close();
		pw.close();

	}

}
