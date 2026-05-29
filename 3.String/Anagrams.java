import java.util.Scanner;
import java.util.Arrays;
public class Anagrams{
  public static void main(String[] args){
    Scanner sc= new Scanner(System.in);

    System.out.print("S1: ");
    String S1= sc.nextLine();
    System.out.print("S2: ");
    String S2= sc.nextLine();

    if((S1.length()<1 || S1.length()>100000)||(S2.length()<1 || S2.length()>100000)){
      sc.close();
      return;
    }
    else{
      S1= S1.toLowerCase();
      S2= S2.toLowerCase();
    }

    char[] ch1= S1.toCharArray();
    char[] ch2= S2.toCharArray();

    if(ch1.length!=ch2.length){
        System.out.print("NO");
        sc.close();
        return;
    }

    Arrays.sort(ch1);
    Arrays.sort(ch2);

    if(Arrays.equals(ch1,ch2))
      System.out.print("YES");
    else
      System.out.print("NO");

    sc.close();
  }
}