import java.util.Scanner;
public class BinaryBits{
  public static void main(String[] args){
    Scanner sc= new Scanner(System.in);

    System.out.print("N = ");
    int N= sc.nextInt();
    if(N<1 || N>100000){
      sc.close();
      return;
    }

    System.out.print("ROLL: ");
    int[] arr= new int[N];
    for(int i=0; i<N; i++){
      arr[i]= sc.nextInt();
      if(arr[i]<0 || arr[i]>1000000000){
        sc.close();
        return;
      }
    }

    for(int i=0; i<N; i++){
      int num= arr[i];
      int count=0;
      while(num>0){
        int bit= num%2;
        if(bit==1)count++;
        num= num/2;
      }
      if(count%2 == 1)System.out.println("ANSWER");
      else System.out.println("SAFE");
    }
    
    sc.close();
  }
}