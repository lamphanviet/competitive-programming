import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;


public class uva10669_Three_powers {
	
	static BigInteger pow3[] = new BigInteger[100];
	static BigInteger big2 = BigInteger.valueOf(2);
	static BigInteger big3 = BigInteger.valueOf(3);
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		pow3[0] = BigInteger.ONE;
		for (int i = 1; i < 100; i++)
			pow3[i] = pow3[i - 1].multiply(big3);
		
		Scanner sc = new Scanner(System.in);
		PrintWriter pw = new PrintWriter(System.out);
		
		while (sc.hasNext()) {
			BigInteger n = new BigInteger(sc.next());
			if (n.compareTo(BigInteger.ZERO) == 0) break;
			n = n.subtract(BigInteger.ONE);
			
			boolean comma = false;
			int i = 0;
			pw.print("{");
			while (n.compareTo(BigInteger.ZERO) != 0) {
				if (n.mod(big2).compareTo(BigInteger.ZERO) != 0) {
					if (comma) pw.print(','); comma = true;
					pw.print(" " + pow3[i]);
				}
				n = n.divide(big2);
				i++;
			}
			pw.println(" }");
		}
		
		sc.close();
		pw.close();
	}

}
