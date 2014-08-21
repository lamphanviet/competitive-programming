import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;


public class uva787_Maximum_Subsequence_Product {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		PrintWriter pw = new PrintWriter(System.out);
		
		BigInteger a[] = new BigInteger[101];
		BigInteger end = BigInteger.valueOf(-999999);
		while (sc.hasNext()) {
			int n = 0;
			while (true) {
				a[n] = BigInteger.valueOf(sc.nextInt());
				if (a[n].compareTo(end) == 0) break;
				n++;
			}
			BigInteger result = a[0], tmp;
			for (int i = 0; i < n; i++) {
				tmp = a[i];
				result = result.max(tmp);
				for (int j = i + 1; j < n; j++) {
					tmp = tmp.multiply(a[j]);
					result = result.max(tmp);
				}
			}
			pw.println(result);
		}
		
		sc.close();
		pw.close();
	}

}
