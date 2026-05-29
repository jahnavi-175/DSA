import java.util.Scanner;
public class DiagonalMatch{
  public static void main(String[] args){
    Scanner sc= new Scanner(System.in);

    System.out.print("N = ");
    int N= sc.nextInt();
    if(N<1 || N>50){
      sc.close();
      return;
    }

    System.out.println("Matrix:");
    int[][] mat= new int[N][N];
    for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
        mat[i][j]= sc.nextInt();
        if(mat[i][j]< -1000 || mat[i][j]>1000){
          sc.close();
          return;
        }
      }
    }

    int mainD=0, secD=0;
    for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
        if(i==j)
          mainD+= mat[i][j];
        if((i+j)==(N-1))
          secD+= mat[i][j];
      }
    }
    if(mainD==secD)
      System.out.print("YES");
    else
      System.out.print("NO");

    sc.close();
  }
}