import java.util.Scanner;


public class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int mod = (int) (1e9+7);
        int []dx = {-2, -2, -1, 1, 2, 2, 1, -1};
        int []dy = {-1, 1, -2, -2, 1, -1, 2, 2};
        int n = sc.nextInt(), k = sc.nextInt() + 1, x1 = sc.nextInt() - 1, y1 = sc.nextInt() - 1, x2 = sc.nextInt() - 1 , y2 = sc.nextInt() - 1;
        int [][][] a = new int[n][n][k];
        a[x1][y1][0] = 1;
        for(int q = 1;q < k;q++){
            for(int i = 0;i < n;i++){
                for(int j = 0;j < n;j++){
                    for(int d = 0;d < 8;d++){
                        int x = i + dx[d] , y = j + dy[d];
                        if(!(x < 0 || x >= n || y < 0 || y >= n))
                            a[x][y][q] = (a[x][y][q]+ a[i][j][q-1])% mod;
                    }
                }
            }
        }
        System.out.println(a[x2][y2][k-1]);
    }
}
