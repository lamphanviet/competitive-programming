import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;


public class uva10551_Basic_Remains {

	public static BigInteger ConvertDec(String s, int b) {
		BigInteger p = BigInteger.ZERO, bb = new BigInteger(""+b);
		for (int i=0, len=s.length(); i<len; i++) {
			p = p.multiply(bb);
			p = p.add(new BigInteger("" + (int)(s.charAt(i)-48)));
		}
		return p;
	}
	
	public static String ConvertBase(BigInteger a, int b) {
		String s = "";
		BigInteger bb = new BigInteger(b+"");
		while (a.compareTo(BigInteger.ZERO)!=0) {
			s += a.mod(bb);
			a = a.divide(bb);
		}
		if (s=="") s = "0";
		return s;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		PrintWriter pw = new PrintWriter(System.out);
		int b;
		BigInteger p, m;
		while (true) {
			b = sc.nextInt();
			if (b==0) break;
			p = ConvertDec(sc.next(), b);
			m = ConvertDec(sc.next(), b);
			p = p.mod(m);
			String result = ConvertBase(p, b);
			for (int i = result.length()-1; i>=0; i--)
				pw.print(result.charAt(i));
			pw.println();
		}
		sc.close();
		pw.close();
	}

}
