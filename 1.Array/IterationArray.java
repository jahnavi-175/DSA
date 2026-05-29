import java.util.Scanner;
public class IterationArray{
  public static void main(String[] args){

    Scanner sc= new Scanner(System.in);

    System.out.print("N = ");
    int N= sc.nextInt();
    if(N<1 || N>100000){
        sc.close();
        return;
    }

    int sum=0;
    int[] arr= new int[N];
    System.out.print("Scores = ");
    for(int i=0; i<N; i++){
      arr[i]= sc.nextInt();
      if(arr[i]<0 || arr[i]>100){
        sc.close();
        return;
      }
      sum += arr[i];
    }

    int count=0;
    int avg= sum/N;
    for(int i=0; i<N; i++){
      if(arr[i]>avg)
        count++;
    }
    
    System.out.print(count);
    sc.close();
  }
}
