/**
 * Created with IntelliJ IDEA.
 * User: manish_sharma
 * Date: 25/4/19
 * Time: 12:09 PM
 * To change this template use File | Settings | File Templates.
 */

import java.util.*;
public class Main
{
    public static ArrayList al = new ArrayList<Integer>();

    public static boolean subsetSum(int[] set, int sum) {
        boolean[][] arr = new boolean[set.length + 1][sum + 1];
        int[][] b = new int[set.length + 1][sum + 1];
        for (int i = 0; i < set.length + 1; i++) {
            for (int j = 0; j < sum + 1; j++) {
                if (i == 0 && j > 0) {
                    arr[i][j] = false;
                } else if (j == 0) {
                    arr[i][j] = true;
                }
            }
        }
        for (int i = 1; i < set.length + 1; i++) {
            for (int j = 1; j < sum + 1; j++) {
                boolean a1 = arr[i - 1][j];
                boolean a2 = ((j - set[i - 1]) >= 0 ? arr[i - 1][j - set[i - 1]] : false);
                if (a2) {
                    b[i][j] = 2;
                } else if (a1) {
                    b[i][j] = 1;
                } else {
                    b[i][j] = 0;
                }
                arr[i][j] = a1 || a2;
            }
        }
        printSubSet(set, b, set.length, sum);
        return arr[set.length][sum];
    }

    private static void printSubSet(int[] set, int[][] b, int n, int m) {
        if (b[n][m] == 1) {
            printSubSet(set, b, n - 1, m);
        } else if (b[n][m] == 2) {
            printSubSet(set, b, n - 1, m - set[n - 1]);
//            System.out.println(set[n - 1]);
            al.add(set[n - 1]);
        }

    }

    public static int FindMaxSum(int arr[], int n)
    {
        int incl = arr[0];
        int excl = 0;
        int excl_new;
        int i;

        for (i = 1; i < n; i++)
        {
            excl_new = (incl > excl) ? incl : excl;
            incl = excl + arr[i];
            excl = excl_new;
        }

        return ((incl > excl) ? incl : excl);
    }

    public static boolean IsAllNeg(int a[])
    {
        for(int i = 0; i < a.length; i++)
        {
            if(a[i] >= 0)
                return false;
        }
        return true;
    }

    public static int findMax(int a[])
    {
        int mx = a[0];
        for(int i = 0; i < a.length; i++)
        {
            if(a[i] > mx)
                mx = a[i];
        }
        return  mx;
    }
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        while(t-- > 0)
        {
            int n = in.nextInt();
            int a[] = new int[n];
            for(int i = 0; i < n; i++)
                a[i] = in.nextInt();

            if(IsAllNeg(a))
            {
                System.out.println(findMax(a));
            }
            else
            {
                int sum = FindMaxSum(a, n);
//                System.out.println(sum);

                for(int i = 0; i < a.length; i++)
                {
                    if(a[i] < 0)
                        a[i] = 0;
                }
                boolean flag = subsetSum(a, sum);
                for(int i = al.size() - 1; i >= 0; i--)
                {
                    if(al.get(i) != (Object)0)
                    System.out.print(al.get(i));
                }
                System.out.println();
                al.clear();
            }

        }
    }
}
