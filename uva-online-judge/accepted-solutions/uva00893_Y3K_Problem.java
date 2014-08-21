import java.io.PrintWriter;
import java.util.Calendar;
import java.util.Date;
import java.util.Scanner;


public class uva00893_Y3K_Problem {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		PrintWriter pw = new PrintWriter(System.out);
		
		int n, day, month, year;
		
		while (true) {
			n = sc.nextInt();
			day = sc.nextInt();
			month = sc.nextInt();
			year = sc.nextInt();
			if (n==0 && day==0 && month==0 && year==0) break;
			
			Calendar date = Calendar.getInstance();
			date.set(year, month - 1, day);
			date.add(Calendar.DAY_OF_MONTH, n);
			
			day = date.get(Calendar.DAY_OF_MONTH);
			month = date.get(Calendar.MONTH) + 1;
			year = date.get(Calendar.YEAR);
			
			pw.println(day + " " + month + " " + year);
		}
		
		sc.close();
		pw.close();
	}

}
