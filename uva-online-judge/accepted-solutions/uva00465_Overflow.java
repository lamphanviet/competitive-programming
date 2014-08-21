import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;


public class uva465_Overflow {
	
	static BigInteger Max = BigInteger.valueOf(Integer.MAX_VALUE);
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		PrintWriter pw = new PrintWriter(System.out);
		
		while (sc.hasNext()) {
			StringBuffer a = new StringBuffer(sc.next());
			char optr = sc.next().charAt(0);
			StringBuffer b = new StringBuffer(sc.next());
			BigInteger ba = new BigInteger(a.toString());
			BigInteger bb = new BigInteger(b.toString());
			BigInteger result;
			
			if (optr=='+') result = ba.add(bb);
			else result = ba.multiply(bb);
			
			pw.println(a + " " + optr + " " + b);
			
			if (ba.compareTo(Max)>0) pw.println("first number too big");
			if (bb.compareTo(Max)>0) pw.println("second number too big");
			if (result.compareTo(Max)>0) pw.println("result too big");
		}
		
		sc.close();
		pw.close();
	}

}
