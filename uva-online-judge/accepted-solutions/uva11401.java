
import java.util.Scanner;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Lam Phan Viet
 */
public class uva11401 {
    
    static int maxN = 1000001;
    static long[] ans = new long[maxN];

    static void PreCal() {
	ans[3] = 0;
	for (int n=4; n<maxN; n++) {
	    ans[n] = ans[n-1];
	    long k = (n+1)/2;
	    ans[n] += (k-1)*((long)n-k-1);
	}
    }

    public static void main(String[] args) {
	PreCal();
        Scanner sc = new Scanner(System.in);
	int n;
	while (true) {
	    n = sc.nextInt();
	    if (n<3) break;
	    System.out.println(ans[n]);
	}
    }

}
