/** 
* @author      : Jackson Fernando Merma Portocarrero (jmermap@unsa.edu.pe)
* @filename    : rectangle_cutting
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define PI 3.1415926535897932384626
#define INF INT_MAX

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    
    //entrada de dimensiones del rectangulo
    int a=0,b=0;
    cin>>a>>b;

    int data[a][b];//matriz principal

    //recorrido dinamico sobre la matriz principal
    for(int height=0; height<a; height++){
        for(int width=0; width<b; width++){
            if(height==width){//si tiene dimensiones k*k
                data[height][width]=0;
            }else{
                int min_count=INF;//valor grande

                //minimizando para : corte(x)+corte(u-x) -> cortes horizontales
                for(int x=0;x<=(width-1)/2 && width!=0;x++){
                    min_count=min(min_count, data[height][x] + data[height][width-x-1] + 1);
                }

                //minimizando para : corte(y)+corte(i-y) -> cortes verticales
                for(int y=0;y<=(height-1)/2 && height!=0;y++){
                    min_count=min(min_count, data[y][width] + data[height-y-1][width] + 1);
                }

                data[height][width]=min_count;//se toma la menor opcion de las sumas
            }
        }
    }

    //el ultimo dato seran los cortes de minima cantidad
    cout<<data[a-1][b-1]<<endl;

	return 0;
}
