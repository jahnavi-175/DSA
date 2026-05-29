import java.util.Scanner;
import java.util.Arrays;
public class SortedSquares{
  public static void main(String[] args){
    Scanner sc= new Scanner(System.in);

    System.out.print("N = ");
    int N= sc.nextInt();
    if(N<1 || N>100000){
      sc.close();
      return;
    }
    System.out.print("Sorted Array: ");
    int[] arr= new int[N];
    for(int i=0; i<N; i++){
      arr[i]= sc.nextInt();
      if(arr[i]< -10000 || arr[i]>10000){
        sc.close();
        return;
      }
    }

    for(int i=0; i<N; i++){
      arr[i]= arr[i]*arr[i];
    }
    Arrays.sort(arr);
    for(int i=0; i<N; i++)
      System.out.print(arr[i]+" ");
    sc.close();
  }
}