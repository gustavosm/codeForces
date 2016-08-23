import java.util.Scanner;
import java.math.BigInteger;


public class Main
{
	BigInteger dez = BigInteger.valueOf(10);
	public static int len(BigInteger d)
	{
		int ans = 0;
		while (d.compareTo(BigInteger.ZERO) != 0)
		{
			++ans;
			d = d.divide(dez);
		}
		return ans;
	}
	public static void main(String[] args)
	{
		BigInteger x;
		int n;
		BigInteger t;
		
		Scanner s = new Scanner(System.in);
		
		n = s.nextInt();
		t = s.nextBigInteger();

		for (int i = 1; ; ++i)
		{
			x = t.multply(BigInteger.valueOf(i));
			
			l = len(x);
			if (l >= n) break;
		}
		
		if (l > n) System.out.println("-1");
		else System.out.println(x);
	}
}
