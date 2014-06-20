import java.io.PrintWriter;
import java.math.BigDecimal;
import java.util.Scanner;


public class uva748_Exponentiation {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		PrintWriter pw = new PrintWriter(System.out);
		
		while (sc.hasNext()) {
			BigDecimal n = new BigDecimal(sc.next());
			n = n.pow(sc.nextInt());
			String res = n.toPlainString();
			int s = 0, t = res.length() - 1;
			while (res.charAt(s) == '0') s++;
			for (int i = s; i < res.length(); i++)
				if (res.charAt(i) == '.') {
					while (res.charAt(t) == '0') t--;
					break;
				}
			for (int i = s; i <= t; i++)
				pw.print(res.charAt(i));
			pw.println();
		}
		
		sc.close();
		pw.close();
	}

}
