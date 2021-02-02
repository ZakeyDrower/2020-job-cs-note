import java.util.*;

class Main1 {
    public static void main(String[] args) {
        int map[][] = new int[4][4];
        Scanner sc = new Scanner(System.in);
        for(int i = 0; i < 4; ++i) {
            for(int j = 0; j < 4; ++ j) {
                map[i][j] = sc.nextInt();
                if(i==0 && j==0) continue;
                if(i==0) {
                    map[i][j] += map[i][j-1];
                }else if(j==0) {
                    map[i][j] += map[i-1][j];
                }else {
                    map[i][j] += Math.min(map[i][j-1], map[i-1][j]);
                }
            }
        }
        System.out.println(map[3][3]);
    }
}


/*
1 3 5 9
8 1 3 4
5 0 6 1
8 8 4 0

1 1 9999 9999
9999 1 9999 9999
1 1 9999 9999
1 1 1 1

*/