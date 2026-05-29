import java.util.Scanner;
public class StrArray {
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);

        System.out.print("Enter one line: ");
        String sen = sc.nextLine();

        int v=0, c=0, w=0;
        String str= sen.toLowerCase();

        char[] ch1= {'a', 'e', 'i', 'o', 'u'};
        char[] ch2= str.toCharArray();
        if(ch2.length==0 || ch2.length>200){
            sc.close();
            return;
        }

        for(int i=0; i<ch2.length; i++){
            if(Character.isLetter(ch2[i])){

                boolean isVowel= false;
                for(int j=0; j<ch1.length; j++){
                    if(ch2[i]==ch1[j]){
                        v++;
                        isVowel= true;
                        break;
                    }
                }
                if(!isVowel)
                    c++;
            }
        }

        String[] words= sen.trim().split("\\s+");
        w= words.length;

        System.out.println("Vowels: " + v);
        System.out.println("Consonants: " + c);
        System.out.println("Words: " + w);
        sc.close();
    }
}
