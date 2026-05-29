import java.util.Scanner;
public class TraversingArray{
  public static void main(String[] args){

    Scanner sc = new Scanner(System.in);

    System.out.print("N= ");
    int N= sc.nextInt();
    if(N<1 || N>100000){
        sc.close();
        return;
    }

    int[] arr= new int[N];
    System.out.print("Marks= ");
    for(int i=0; i<N; i++){
      arr[i]= sc.nextInt();
      if(arr[i]<0 || arr[i]>100){
        sc.close();
        return;
      }
    }

    int flag= 0;
    for(int i=0; i<N; i++){
      for(int j=i+1; j<N; j++){
        if(arr[i]==arr[j]){
            System.out.print("YES");
            flag=1;
            break;
        }
      }
      if(flag==1)break;
    }
    if(flag==0)System.out.print("NO");

    sc.close();
  }
}