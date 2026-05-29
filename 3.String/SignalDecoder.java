import java.util.Scanner;
public class SignalDecoder{
  public static void main(String[] args){
    Scanner sc= new Scanner(System.in);

    System.out.print("String: ");
    String s1= sc.nextLine();
    if(s1.length()<1 || s1.length()>10000){
      sc.close();
      return;
    }

    s1= s1.toLowerCase();
    char[] ch= s1.toCharArray();

    int count=1;
    for(int i=0; i<ch.length -1; i++){
      if(ch[i]==ch[i+1])
        count++;
      else{
        System.out.print(ch[i]);
        System.out.print(count);
        count=1;
      }
    }
    System.out.print(ch[ch.length-1]);
    System.out.print(count);
    sc.close();
  }
}