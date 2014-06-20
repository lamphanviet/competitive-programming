import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;


public class uva713_Adding_Reversed_Numbers {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		PrintWriter pw = new PrintWriter(System.out);
		
		int Case = sc.nextInt();
		while (Case-- > 0) {
			StringBuffer sa = new StringBuffer(sc.next()), sb = new StringBuffer(sc.next());
			BigInteger na = new BigInteger(sa.reverse().toString());
			BigInteger nb = new BigInteger(sb.reverse().toString());
			
			na = na.add(nb);
			sa = (new StringBuffer(na.toString())).reverse();
			na = new BigInteger(sa.toString());
			
			pw.println(na);
		}
		
		sc.close();
		pw.close();
	}

}
