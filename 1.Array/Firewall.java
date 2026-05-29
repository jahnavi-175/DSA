import java.util.Scanner;
public class Firewall {
    public static void main(String[] args){

        Scanner sc= new Scanner(System.in);

        System.out.print("N = ");
        int N= sc.nextInt();
        if(N<1 || N>20){
            sc.close();
            return;
        }

        for(int i=1; i<=N; i++){

            for(int j=1; j<=i; j++)
                System.out.print(j);

            int count= 2*(N-i);
            for(int j=1; j<=count; j++)
                System.out.print("@");

            for(int j=i; j>=1; j--)
                System.out.print(j);

            System.out.println();
        }
        sc.close();
    }
}
