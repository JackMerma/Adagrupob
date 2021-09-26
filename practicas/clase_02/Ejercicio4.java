/*
 *	Tiempo de ejecusion en ordenamiento por insercion
 */
import java.util.Scanner;
public class Ejercicio4{
	public static void main(String[]args){
		Scanner scan=new Scanner(System.in);
		long nums[];
		long start,end,duration;

		//cantidad de datos
		int len=scan.nextInt();
		nums=new long[len];

		//generador de numeros aleatorios <1-10.000.000>
		for(int i=0;i<len;i++)
			nums[i]=(long)(Math.random()*(10000000))+1;

		//algoritmo y captura de tiempo
		start=System.nanoTime();
		//algoritmo
		for(int i=1;i<len;i++){
			long key=nums[i];
			int j=i-1;
			while(j>=0&&nums[j]>key){
				nums[j+1]=nums[j];
				j-=1;
			}
			nums[j+1]=key;
		}

		end=System.nanoTime();
		duration=(end-start)/1000000;
		System.out.println("duracion: "+duration+" ms");

		//for(int i=0;i<len;i++)
		//	System.out.print(nums[i]+" ");
	}
}
