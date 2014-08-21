import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

public class uva10334_Ray_Through_Glasses {

	static int maxN = 1001;
	static BigInteger f[] = new BigInteger[maxN];
	
	public static void PreCal() {
		f[0] = new BigInteger("1");
		f[1] = new BigInteger("2");
		for (int i=2; i<maxN; i++)
			f[i] = f[i-1].add(f[i-2]);
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		PreCal();
		Scanner sc = new Scanner(System.in);
		PrintWriter pw = new PrintWriter(System.out);
		while (sc.hasNext()) {
			int n = sc.nextInt();
			pw.println(f[n]);
		}
		sc.close();
		pw.close();
	}

}
