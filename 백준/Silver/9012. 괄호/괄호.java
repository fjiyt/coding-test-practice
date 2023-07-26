import java.util.Scanner;
import java.util.Stack;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();

        for(int i=0; i<T; i++)
        {
            String s = sc.next();
            Stack<Character> stack = new Stack<Character>();
            boolean flag = true;

            for(int j=0; j<s.length(); j++)
            {
                Character tmp = s.charAt(j);
                if(tmp=='(') stack.push(tmp);
                else {
                    if (stack.empty()) {
                        flag = false;
                        break;
                    } else stack.pop();
                }
            }

            if(flag && stack.empty()) System.out.println("YES");
            else System.out.println("NO");
        }
    }
}
