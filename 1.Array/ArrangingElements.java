import java.util.Scanner;
public class ArrangingElements{
  public static void main(String[] args) {
    
    Scanner sc= new Scanner(System.in);
    System.out.print("N= ");
    int N= sc.nextInt();
    int[] arr= new int[N];

    System.out.print("Elements= ");
    for(int i=0; i<N; i++)
      arr[i]= sc.nextInt();

    int count=0;
    for(int i=0; i<N; i++){
      if(arr[i]!=0){
        arr[count]=arr[i];
        count++;
      }
    }
    while(count<N){
      arr[count]=0;
      count++;
    }

    System.out.print("Sorted Elements= ");
    for(int i=0; i<N; i++)
      System.out.print(arr[i]+" ");
    sc.close();
  }
}