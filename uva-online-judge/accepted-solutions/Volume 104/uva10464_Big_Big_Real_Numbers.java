import java.io.PrintWriter;
import java.math.BigDecimal;
import java.util.Scanner;


public class uva10464_Big_Big_Real_Numbers {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		PrintWriter pw = new PrintWriter(System.out);
		
		int Case = sc.nextInt();
		while (Case-- != 0) {
			BigDecimal a = new BigDecimal(sc.next());
			BigDecimal b = new BigDecimal(sc.next());
			a = a.add(b);
			String res = a.toPlainString();
			int f = res.length() - 1;
			for (int i = 0; i < res.length(); i++)
				if (res.charAt(i) == '.') {
					while (f > i + 1 && res.charAt(f) == '0') f--;
					break;
				}
			for (int i = 0; i <= f; i++)
				pw.print(res.charAt(i));
			pw.println();
		}
		
		sc.close();
		pw.close();
	}

}
