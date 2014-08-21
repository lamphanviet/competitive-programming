
import java.math.BigInteger;
import java.util.Scanner;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Lam Phan Viet
 */
public class uva00495 {

    static int maxN = 5001;
    static BigInteger fibo[] = null;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
	PreCal();
	Scanner sc = new Scanner(System.in);
	while (sc.hasNextInt()) {
	    int n = sc.nextInt();
	    System.out.println("The Fibonacci number for " + n + " is " + fibo[n].toString());
	}
    }

    static void PreCal() {
	fibo = new BigInteger[maxN];
	fibo[0] = new BigInteger("0");
	fibo[1] = new BigInteger("1");
	for (int i=2; i<maxN; i++)
	    fibo[i] = fibo[i-1].add(fibo[i-2]);
    }

}
