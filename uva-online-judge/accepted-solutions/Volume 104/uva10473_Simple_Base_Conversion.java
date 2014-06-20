import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;


public class uva10473_Simple_Base_Conversion {
	
	static String s = "";
	static int len = 0;
	static BigInteger hex = new BigInteger(16+"");
	
	static int Value(char ch) {
		if ('0' <= ch && ch <= '9') return (int)(ch-48);
		else return (int)(ch-55);
	}
	
	static char getChar(int n) {
		if (0 <= n && n <= 9) return (char)(n+48);
		else return (char)(n+55);
	}
	
	static void ToDec(PrintWriter pw) {
		BigInteger result = BigInteger.ZERO;
		for (int i=2; i<len; i++) {
			result = result.multiply(hex);
			result = result.add(new BigInteger(Value(s.charAt(i))+""));
		}
		pw.println(result);
	}
	
	static void ToHex(PrintWriter pw) {
		String result = "";
		BigInteger a = new BigInteger(s);
		while (a.compareTo(BigInteger.ZERO)!=0) {
			result += getChar(a.mod(hex).intValue());
			a = a.divide(hex);
		}
		pw.print("0x");
		if (result=="") result = "0";
		for (int i=result.length()-1; i>=0; i--)
			pw.print(result.charAt(i));
		pw.println();
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		PrintWriter pw = new PrintWriter(System.out);
		while (sc.hasNext()) {
			s = sc.next(); len = s.length();
			if (s.charAt(0)=='-') break;
			if (len<=2) ToHex(pw);
			else if (s.charAt(1)=='x') ToDec(pw);
			else ToHex(pw);
		}
		sc.close();
		pw.close();
	}

}
