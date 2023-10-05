import java.util.*;
import java.io.*;

public class Main {
    static int L, C;
    static char [] arr;
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        L = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());

        arr = new char[C];
        st = new StringTokenizer(br.readLine());
        for(int i=0; i<C; i++)
        {
            arr[i] = st.nextToken().charAt(0);
        }

        Arrays.sort(arr);

        solve(0,0,0, "");
    }

    public static void solve(int idx, int v, int c, String str)
    {
        if(str.length() == L)
        {
            if(v>=1 && c>=2)
            {
                System.out.println(str);
            }
            return;
        }
        if(idx == C) return;

        if(arr[idx] == 'a' || arr[idx] == 'e' || arr[idx] == 'i' || arr[idx] == 'o' || arr[idx] == 'u')
        {
            solve(idx+1, v+1, c, str+arr[idx]);
        }
        else {
            solve(idx+1, v, c+1, str+arr[idx]);
        }
        solve(idx+1, v, c, str);
    }
}
