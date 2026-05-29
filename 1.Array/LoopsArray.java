import java.util.Scanner;
public class LoopsArray{
  public static void main(String[] args){

    Scanner sc= new Scanner(System.in);
    
    System.out.print("N = ");
    int N= sc.nextInt();
    if(N<1 || N>100000){
        sc.close();
        return;
    }

    System.out.print("Codes = ");
    int[] arr= new int[N];
    for(int i=0; i<N; i++){
      arr[i]= sc.nextInt();
      if(arr[i]<1 || arr[i]>1000){
          sc.close();
          return;
      }
    }

    int flag=0;
    for(int i=0; i<N-1; i++){
      if(arr[i]==arr[i+1]){
        System.out.print("INVALID "+arr[i]);
        flag=1;
        break;
      }
    }
    if(flag==0)
      System.out.print("VALID");

    sc.close();
  }
}
