import java.util.Scanner;
import java.awt.*;
import javax.swing.*;
/*
 *	Programa para graficar tiempo de ejecucion del algoritmo insertion sort(solo puntos)
 */
public class Ejercicio5{
	static JFrame frame=new JFrame();
	public static void main(String[]args){
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		crearContenido();
		frame.setSize(500,500);
		frame.setLocation(200,200);
		frame.setVisible(true);
	}
	/*
	 * Metodo para crear el contenido con arreglos y con el uso del algoritmo
	 */
	public static void crearContenido(){
		Scanner scan=new Scanner(System.in);
		int cant=scan.nextInt();
		int data[]=new int[cant];

		//rangos
		final int MIN=1000;
		final int RANGO=1000;

		for(int i=MIN,u=0;u<cant;i+=RANGO,u++){
			long nums[];
			long start,end,duration;
			int len=i;
			nums=new long[len];

			for(int k=0;k<len;k++)
				nums[k]=(long)(Math.random()*(100000))+1;

			//algoritmo y captura de tiempo
			start=System.nanoTime();
			//algoritmo
			for(int k=1;k<len;k++){
				long key=nums[k];
				int j=k-1;
				while(j>=0&&nums[j]>key){
					nums[j+1]=nums[j];
					j-=1;
				}
				nums[j+1]=key;
			}

			end=System.nanoTime();
			duration=(end-start)/1000000;//milisegundos
			System.out.println("case #"+u+": "+duration);
			data[u]=(int)duration;	
		}
		//creacion del grafico
		frame.add(new G(data));
	}
}
