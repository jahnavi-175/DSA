import java.util.Scanner;
public class LongestCommonPrefix{
  public static void main(String[] args){
    Scanner sc= new Scanner(System.in);

    System.out.print("N = ");
    int N= sc.nextInt();
    if(N<1 || N>100){
      sc.close();
      return;
    }
    sc.nextLine();
    System.out.println("Series Names: ");
    String[] arr= new String[N];
    for(int i=0; i<N; i++){
      arr[i]= sc.nextLine();
      if(arr[i].length()<1 || arr[i].length()>10000){
        sc.close();
        return;
      }
    }

    String first= arr[0];
    String ans= "";
    System.out.print("Longest Common Prefix: ");
    for(int i=0; i<first.length(); i++){
      char ch= first.charAt(i);

      for(int j=1; j<N; j++){
        if(i >= arr[j].length() || arr[j].charAt(i) != ch){
          System.out.println(ans);
          sc.close();
          return;
        }
      }
      ans += ch;
    }
    System.out.println(ans);
    sc.close();
  }
}