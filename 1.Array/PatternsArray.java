import java.util.Scanner;
public class PatternsArray{
  public static void main(String[] args){

    Scanner sc= new Scanner(System.in);

    char[] alphabet= {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    System.out.print("N = ");
    int N= sc.nextInt();
    if(N<1 || N>26){
        sc.close();
        return;
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(j==i || j==N-1-i)
                System.out.print(alphabet[i]+" ");
            else
                System.out.print("* ");
        }
        System.out.println();
    }
    sc.close();
  }
}
