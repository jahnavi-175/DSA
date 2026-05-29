import java.util.*;
public class SortingArray{
  public static void main(String[] args){
    Scanner sc= new Scanner(System.in);

    System.out.print("N = ");
    int N= sc.nextInt();
    if(N<1 || N>100){
      sc.close();
      return;
    }
    System.out.print("Clubs: ");
    int[] arr= new int[N];
    for(int i=0; i<N; i++){
      arr[i]= sc.nextInt();
      if(arr[i]<0 || arr[i]>2){
        sc.close();
        return;
      }
    }
    int first= 0, mid=0, last= N-1;
    while(mid<=last){
      if(arr[mid]==0){
        int temp= arr[first];
        arr[first]=arr[mid];
        arr[mid]=temp;
        first++; mid++;
      }
      else if(arr[mid]==1) mid++;
      else{
        int temp=arr[mid];
        arr[mid]=arr[last];
        arr[last]=temp;
        last--;
      }
    }
    for(int i=0; i<N; i++)
      System.out.print(arr[i]+" ");

    sc.close();
  }
}