import java.util.Scanner;
public class AttendanceCounter {
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        System.out.print("N = ");
        int N= sc.nextInt();
        if(N<1 || N>100000){
            sc.close();
            return;
        }

        System.out.print("X = ");
        int X= sc.nextInt();
        if(X<1 || X>1000000000){
            sc.close();
            return;
        }

        System.out.print("Batches: ");
        int[] arr= new int[N];
        for(int i=0; i<N; i++){
            arr[i]= sc.nextInt();
            if(arr[i]<1 || arr[i]>1000){
                sc.close();
                return;
            }
        }

        int sum=0;
        for(int i=0; i<N; i++){
            sum+= arr[i];
            if(sum>X){
                System.out.print(i);
                break;
            }
        }
        sc.close();
    }
}
