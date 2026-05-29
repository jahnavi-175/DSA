import java.util.Scanner;
import java.util.Arrays;
public class GreedyApproach{
  public static void main(String[] args){
    Scanner sc= new Scanner (System.in);

    System.out.print("N = ");
    int N= sc.nextInt();
    if(N<2 || N>100){
      sc.close();
      return;
    }
    System.out.print("Temperatures: ");
    int[] arr= new int[N];
    for(int i=0; i<N; i++){
      arr[i]= sc.nextInt();
      if(arr[i]< -100000 || arr[i]>100000){
        sc.close();
        return;
      }
    }

    Arrays.sort(arr);
    int left=0, right=N-1, s=Integer.MAX_VALUE, first=0, second=0;

    while(left<right){
      int sum= arr[left]+arr[right];
      if(Math.abs(sum)<Math.abs(s)){
        s=sum;
        first= arr[left];
        second= arr[right];
      }
      if(sum<0) left++;
      else if(sum>0) right--;
      else break;
    }
    System.out.print(first+" "+second);
    sc.close();
  }
}