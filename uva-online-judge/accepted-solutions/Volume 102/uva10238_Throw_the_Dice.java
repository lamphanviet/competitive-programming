import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;


public class uva10238_Throw_the_Dice {
	
	static int maxN = 55;
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		PrintWriter pw = new PrintWriter(System.out);
		
		int f, n, s;
		BigInteger d[][] = null;
		while (sc.hasNext()) {
			f = sc.nextInt();
			n = sc.nextInt();
			s = sc.nextInt();
			if (n*f < s) pw.print("0");
			else if (n*f == s || n==s) pw.printf("1");
			else {
				d = new BigInteger[n+1][Math.max(f, s) + 1];
			
				for (int i=1; i<=f; i++)
					d[1][i] = BigInteger.ONE;
				for (int i=f+1; i<=s; i++)
				d[1][i] = BigInteger.ZERO;
				for (int i=2; i<=n; i++) {
					for (int j=1; j<=s; j++)
						d[i][j] = BigInteger.ZERO;
					for (int j=1; j<=f; j++)
						for (int k=1; k<=s; k++)
							if (j + k > s) break;
							else d[i][j+k] = d[i][j+k].add(d[i-1][k]);
				}
				pw.print(d[n][s].toString());
			}
			pw.println("/" + BigInteger.valueOf(f).pow(n));
		}
		
		sc.close();
		pw.close();
	}

}
