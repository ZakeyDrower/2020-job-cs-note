import java.util.*;

class Main2 {

    private static boolean checkInput(String str, int n) {
        if(n < 1 || n > 8 || str.length() != 8)
            return false;
        for(int i = 0; i < 8; ++ i)
            if(str.charAt(i) < '0' || str.charAt(i) > '9')
                return false;
        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.next();
        int n = sc.nextInt();
        if(!checkInput(str, n)){
            System.out.println("error");
            return;
        }
        // process
        str = str.substring(0, n-1) + str.substring(n, str.length());

        char[] arr = str.toCharArray();
        Arrays.sort(arr);
        for(int i = 0; i < arr.length; i++) {
            System.out.print(arr[i]);
        }
        System.out.println();
    }
}