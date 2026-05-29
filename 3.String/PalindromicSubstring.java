import java.util.Scanner;
public class PalindromicSubstring{
  public static void main(String[] args){
    Scanner sc= new Scanner(System.in);

    System.out.print("S = ");
    String S= sc.nextLine();
    if(S.length()<1 || S.length()>10000 || !S.matches("[a-z]+")){
      sc.close();
      return;
    }

    int start=0, maxlen=1;
    for(int i=0; i<S.length(); i++){
      int left= i, right=i;
      while(left>=0 && right<S.length() 
            && S.charAt(left)==S.charAt(right)){
        int len= right-left+1;
        if(len>maxlen){
          maxlen=len;
          start=left;
        } left--; right++;
      }

      left=i; right=i+1;
      while(left>=0 && right<S.length()
           && S.charAt(left)==S.charAt(right)){
        int len= right-left+1;
        if(len>maxlen){
          maxlen=len;
          start=left;
        } left--; right++;
      }
    }
    System.out.println(S.substring(start, start+maxlen));
    sc.close();
  }
}