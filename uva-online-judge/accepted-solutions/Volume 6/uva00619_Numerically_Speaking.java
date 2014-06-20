import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;


public class uva00619_Numerically_Speaking {
	
	static BigInteger N = BigInteger.valueOf(26);

	static void ConvertToInt(String s, PrintWriter pw) {
		BigInteger num = BigInteger.ZERO;
		
		for (int i=0; i<s.length(); i++) {
			int k = (int)(s.charAt(i) - 96);
			num = num.multiply(N).add(BigInteger.valueOf(k));
		}
		
		PrintResult(s, num.toString(), pw);
	}
	
	static void ConvertToString(String s, PrintWriter pw) {
		BigInteger num = new BigInteger(s);
		StringBuffer str = new StringBuffer("");
		
		while (num.compareTo(BigInteger.ZERO)!=0) {
			str.append((char)(num.mod(N).intValue() + 96));
			num = num.divide(N);
		}
		
		PrintResult(str.reverse().toString(), s.toString(), pw);
	}
	
	static void PrintResult(String a, String b, PrintWriter pw) {
		pw.print(a);
		
		for (int i=a.length()+1; i<23; i++)
			pw.print(" ");
		int n = b.length();
		if (n%3!=0) pw.print(b.charAt(0));
		if (n%3==2) pw.print(b.charAt(1));
		n = n%3;
		
		for (int i=0; n<b.length(); i++, n++) {
			if (n!=0 && i%3==0) pw.print(",");
			pw.print(b.charAt(n));
		}
		
		pw.println();
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		PrintWriter pw = new PrintWriter(System.out);
		
		while (sc.hasNext()) {
			String s = sc.next();
			if (s.equals("*")) break;
			
			char ch = s.charAt(0);
			if ('0' <= ch && ch <= '9') ConvertToString(s, pw);
			else ConvertToInt(s, pw);
		}
		
		sc.close();
		pw.close();
	}

}