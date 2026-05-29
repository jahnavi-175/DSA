import java.util.Scanner;
public class XORScanner{
  public static void main(String[] args){
    Scanner sc= new Scanner(System.in);

    System.out.print("N = ");
    int N= sc.nextInt();
    if(N<1 || N>100000){
      sc.close();
      return;
    }

    System.out.print("IDs: ");
    int[] arr= new int[N];
    for(int i=0; i<N; i++){
      arr[i]= sc.nextInt();
      if(arr[i]<0 || arr[i]>1000000000){
        sc.close();
        return;
      }
    }

    int result=0;
    for(int i=0; i<N; i++){
      result= result ^ arr[i];
    }
    if(result==0)System.out.print("BALANCED");
    else System.out.print("UNBALANCED");
    sc.close();
  }
}