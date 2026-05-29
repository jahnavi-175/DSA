import java.util.Scanner;
import java.util.Arrays;
public class Lexicograph{
  public static void main(String[] args){
    Scanner sc= new Scanner(System.in);

    System.out.print("N = ");
    int N= sc.nextInt();
    if(N<1 || N>100){
      sc.close();
      return;
    }
    sc.nextLine();
    System.out.println("Restaurant Names: ");
    String[] arr= new String[N];
    for(int i=0; i<N; i++){
      arr[i]= sc.nextLine();
      if(arr[i].length()<1 || arr[i].length()>100 || !arr[i].matches("[a-z]+")){
        sc.close();
        return;
      }
    }
    System.out.print("Search prefix = ");
    String prefix= sc.nextLine();
    Arrays.sort(arr);
    int flag=0;
    for(int i=0; i<N; i++){
      if(arr[i].startsWith(prefix)){
        System.out.println(arr[i]);
        flag=1;
      }
    }
    if(flag==0) System.out.println("-1");
    sc.close();
  }
}