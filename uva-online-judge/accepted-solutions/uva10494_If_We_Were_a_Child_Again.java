import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;


public class uva10494_If_We_Were_a_Child_Again {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		PrintWriter pw = new PrintWriter(System.out);
		
		while (sc.hasNext()) {
			BigInteger n = new BigInteger(sc.next());
			String oper = sc.next();
			BigInteger m = new BigInteger(sc.next());
			if (oper.charAt(0) == '/')
				n = n.divide(m);
			else n = n.mod(m);
			pw.println(n);
		}
		
		sc.close();
		pw.close();
	}

}
