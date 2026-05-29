import java.util.Scanner;
import java.util.Arrays;
public class TripletSum{
  public static void main(String[] args){
    Scanner sc= new Scanner(System.in);

    System.out.print("N = ");
    int N= sc.nextInt();
    if(N<1 || N>100){
      sc.close();
      return;
    }
    System.out.print("List: ");
    int[] arr= new int[N];
    for(int i=0; i<N; i++){
      arr[i]= sc.nextInt();
      if(arr[i]< -10000 || arr[i]>10000){
        sc.close();
        return;
      }
    }
    System.out.print("K = ");
    int K= sc.nextInt();
    if(K< -10000 || K>10000){
      sc.close();
      return;
    }

    Arrays.sort(arr);
    for(int i=0; i<N-2; i++){
      int a= i+1, b= N-1;

      while(a<b){
        int sum= arr[i]+arr[a]+arr[b];
        if(sum==K){
          System.out.print("YES");
          sc.close();
          return;
        }
        else if(sum<K) a++;
        else b--;
      }
    }
    System.out.print("NO");
    sc.close();
  }
}