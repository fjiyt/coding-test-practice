import java.util.Scanner;
import java.util.Stack;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int cnt = 0;

        int N = sc.nextInt();
        for(int i=0; i<N; i++)
        {
            String str = sc.next();
            boolean [] isExist = new boolean[26];
            boolean flag = true;
            for(int j=0; j<str.length(); j++)
            {
                int idx = str.charAt(j)-'a';
                if(isExist[idx]){
                    if(str.charAt(j-1) == str.charAt(j)) continue;
                    else {
                        flag = false;
                        break;
                    }
                }
                else {
                    isExist[idx] = true;
                }
            }

            if(flag) cnt++;
        }

        System.out.println(cnt);
    }
}
