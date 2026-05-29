import java.util.Scanner;
public class PasswordStrength{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);

    System.out.print("Password: ");
    String password = sc.nextLine();
    if(password.length()<1 || password.length()>100){
        sc.close();
        return;
    }

    char[] ch= password.toCharArray();
    
    boolean hU=false, hL=false, hD=false;
    for(int i=0; i<ch.length; i++){
        if(Character.isUpperCase(ch[i])){
            hU=true;
            continue;
        }
        if(Character.isLowerCase(ch[i])){
            hL=true;
            continue;
        }
        if(Character.isDigit(ch[i])){
            hD=true;
            continue;
        }
    }
    if(hU && hL && hD)
        System.out.print("STRONG");
    else
        System.out.print("WEAK");

    sc.close();
    
  }
}