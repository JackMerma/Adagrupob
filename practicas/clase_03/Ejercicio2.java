import java.util.Scanner;
import java.awt.*;
import javax.swing.*;
/*
 *	Programa para graficar tiempo de ejecucion del algoritmo de bsuqueda binaria
 */
public class Ejercicio2{
	static JFrame frame=new JFrame();
	public static void main(String[]args){
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		crearContenido();
		frame.setSize(500,500);
		frame.setLocation(200,200);
		frame.setVisible(true);
	}
	/*
	 * Metodo para crear el contenido con un arreglo y el proceso del algoritmo
	 */
	public static void crearContenido(){
		Scanner scan=new Scanner(System.in);
		int cant=scan.nextInt();
		int data[]=new int[cant];//tiempos de ejecucion por caso

		//cantidad de datos generados entre rango de 300 datos
		final int MIN=100;
		final int RANGO=300;

		//casos
		for(int i=MIN,u=0;u<cant;i+=RANGO,u++){
			long nums[];
			long start,end,duration;
			int len=i;
			nums=new long[len];

			//datos aleatorios ordenados de 10 en 10. Cantidad=len
			//Ejemplo: len=100, entonces numeros aleatorios de 1 a 10000
			for(int k=0,minRango=1;k<len;k++,minRango+=10)
				nums[k]=(long)(Math.random()*(10))+minRango;

			int busq=(int)(Math.random()*(len*10))+1;//aleatorio a buscar de 1 a len*10
			//captura de tiempo
			start=System.nanoTime();

			//algoritmo
			int min=0,max=len-1,pos;
			while(min<=max){
				pos=min+(max-min)/2;
				if(arr[pos]==num)
					break;

				if(arr[pos]>num){
					max=pos-1;
				}else{
					min=pos+1;
				}
			}

			//captura de tiempo
			end=System.nanoTime();
			duration=(end-start)/1000000;//milisegundos
			data[u]=(int)duration;	
		}
		//creacion del grafico
		frame.add(new G(data));
	}
}

