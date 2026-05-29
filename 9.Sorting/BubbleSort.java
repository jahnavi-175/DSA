import java.util.Scanner;
public class BubbleSort{
  public static void main(String[] args){
    Scanner sc= new Scanner(System.in);

    System.out.print("N = ");
    int N= sc.nextInt();

    String[] names= new String[N];
    int[] scores= new int[N];
    for(int i=0; i<N; i++){
      names[i]= sc.next();
      scores[i]= sc.nextInt();
    }

    for(int i=0; i<N-1; i++){
      for(int j=0; j<N-i-1; j++){
        if(scores[j]>scores[j+1]){

          int temp1= scores[j];
          scores[j]= scores[j+1];
          scores[j+1]= temp1;

          String temp2= names[j];
          names[j]= names[j+1];
          names[j+1]= temp2;
        }
      }
    }
    System.out.println("Sorted:");
    for(int i=0; i<N; i++)
      System.out.println(names[i]+" "+scores[i]);

    sc.close();
  }
}