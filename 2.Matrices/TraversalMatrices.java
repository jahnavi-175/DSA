import java.util.Scanner;
public class TraversalMatrices {
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);

        System.out.print("N = ");
        int N= sc.nextInt();
        if(N<0 || N>50){
            sc.close();
            return;
        }

        int[][] M= new int[N][N];
        System.out.println("Seats: ");
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                M[i][j]= sc.nextInt();
            }
        }

        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(M[i][j]==1)
                    System.out.print("O");

                else {
                    if((j>0 && M[i][j-1]==1) || (j<N-1 && M[i][j+1]==1) || (i>0 && M[i-1][j]==1) || (i<N-1 && M[i+1][j]==1))
                        System.out.print("X");
                    else
                        System.out.print("S");
                }
            }
            System.out.println();
        }

        sc.close();
    }
}
