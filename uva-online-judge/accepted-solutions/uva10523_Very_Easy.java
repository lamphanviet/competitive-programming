import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;


public class uva10523_Very_Easy {
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		PrintWriter pw = new PrintWriter(System.out);
		while (sc.hasNextInt()) {
			int n = sc.nextInt();
			BigInteger a = new BigInteger(sc.next());
			BigInteger result = new BigInteger("0"), b = a;
			for (int i=1; i<=n; i++) {
				result = result.add((new BigInteger(i + "").multiply(b)));
				b = b.multiply(a);
			}
			pw.println(result);
		}
		sc.close();
		pw.close();
	}

}
