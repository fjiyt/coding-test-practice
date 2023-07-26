import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        for(int j = 0; j<n; j++)
        {
            String str = sc.next();
            int cnt = 0;
            int sum = 0;
            for(int i=0; i<str.length(); i++)
            {
                if(str.charAt(i)=='O') {
                    cnt++;
                    sum += cnt;
                }
                else {
                    cnt = 0;
                }
            }

            System.out.println(sum);
        }

        sc.close();
    }
}
