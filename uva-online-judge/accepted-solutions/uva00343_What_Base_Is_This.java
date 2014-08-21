import java.io.PrintWriter;
import java.util.Scanner;


public class uva00343_What_Base_Is_This {

	static int LowestBase(String a) {
		int Max = 0;
		for (int i=0, len=a.length(); i<len; i++)
			Max = Math.max(Max, (int)(Value(a.charAt(i))));
		return Max + 1;
	}
	
	static long Value(char ch) {
		if ('0' <= ch && ch <= '9') return (long)(ch-48);
		else return (long)(ch-55);
	}
	
	static long Dec(String s, int b) {
		long result = 0;
		for (int i=0, len=s.length(); i<len; i++)
			result = result*(long)(b) + Value(s.charAt(i));
		return result;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		PrintWriter pw = new PrintWriter(System.out);
		
		while (sc.hasNext()) {
			String a = sc.next(), b = sc.next();
//			if (a.charAt(0)=='x') break;
			boolean f = false;
			int lowa = Math.max(LowestBase(a), 2), lowb = Math.max(LowestBase(b), 2);
			for (int i=lowa; i<=36; i++) {
				if (f) break;
				for (int j=lowb; j<=36; j++)
					if (Dec(a, i) == Dec(b, j)) {
						pw.print(a + " (base " + i + ") = ");
						pw.println(b + " (base " + j + ")");
						f = true;
						break;
					}
					
			}
			if (!f) pw.println(a + " is not equal to " + b + " in any base 2..36");
		}
		
		sc.close();
		pw.close();
	}

}
