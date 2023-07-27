import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        Set<String> hashSet = new HashSet<> ();

        for(int i=0; i<N; i++)
        {
            String tmp = sc.next();
            hashSet.add(tmp);
        }

        String[] arr = new String[hashSet.size()];

        int index = 0;
        for(String i : hashSet)
        {
            arr[index++] = i;
        }

        Arrays.sort(arr, new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                if(o1.length() < o2.length())
                {
                    return -1;
                }
                else if(o1.length()==o2.length())
                {
                    return o1.compareTo(o2);
                }
                else return 1;
            }
        });

        for(String i: arr)
        {
            System.out.println(i);
        }
    }
}
