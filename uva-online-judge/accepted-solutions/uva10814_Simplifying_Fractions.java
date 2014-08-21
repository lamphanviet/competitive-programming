import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;


public class uva10814_Simplifying_Fractions {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		PrintWriter pw = new PrintWriter(System.out);
		int Case = sc.nextInt();
		BigInteger p, q, gcd;
		while (Case-- != 0) {
			p = new BigInteger(sc.next());
			sc.next();
			q = new BigInteger(sc.next());
			gcd = p.gcd(q);
			pw.print(p.divide(gcd) + " / " + q.divide(gcd));
			pw.println();
		}
		sc.close();
		pw.close();
	}

}
