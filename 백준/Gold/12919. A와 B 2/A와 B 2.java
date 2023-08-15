import java.util.*;

public class Main {
    public static String S;
    public static String T;
    public static boolean flag = false;
    public static int goalA, goalB;

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);

        S = sc.next();
        T = sc.next();

        solve(S, T);
        if(flag == true) System.out.println("1");
        else System.out.println("0");
    }

    public static void solve(String s, String t)
    {
        if(s.length()==t.length())
        {
            if(s.equals(t)) flag = true;
            return;
        }

        if(t.charAt(t.length()-1)=='A') {
            solve(s, t.substring(0, t.length()-1));
        }
        if(t.charAt(0)=='B') {
            solve(s, new StringBuffer(t.substring(1, t.length())).reverse().toString());
        }
    }
}
