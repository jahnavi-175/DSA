import java.util.Scanner;
public class SecondLargest{
  public static void main(String[] args){

    Scanner sc= new Scanner(System.in);

    System.out.print("N = ");
    int N= sc.nextInt();
    if(N<2 || N>100000){
        sc.close();
        return; 
    }

    int[] arr= new int[N];
    System.out.print("Amounts = ");
    for(int i=0; i<N; i++){
      arr[i]= sc.nextInt();
      if(arr[i]< -10000 || arr[i]>10000){
        sc.close();
        return;
      }
    }
    
    int largest= Integer.MIN_VALUE;
    int seclargest= Integer.MIN_VALUE;

    for(int i=0; i<N; i++){
      if(arr[i]>largest){
        seclargest=largest;
        largest=arr[i];
      }
      else if(arr[i]>seclargest && arr[i]!=largest)
        seclargest=arr[i];
    }
    System.out.print(seclargest);

    sc.close();
  }
}
