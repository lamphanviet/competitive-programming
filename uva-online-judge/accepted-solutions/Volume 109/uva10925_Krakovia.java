import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;


public class uva10925_Krakovia {

	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		PrintWriter pw = new PrintWriter(System.out);
		int n, f, Case = 0;
		while (true) {
			n = sc.nextInt(); f = sc.nextInt();
			if (n==0 && f==0) break;
			BigInteger sum = new BigInteger("0");
			for (int i=1; i<=n; i++)
				sum = sum.add(new BigInteger(sc.next()));
			BigInteger avg = sum.divide(new BigInteger(f + ""));
			pw.println("Bill #" + (++Case) + " costs " + sum + ": each friend should pay " + avg);
			pw.println();
		}
		sc.close();
		pw.close();
	}

}
