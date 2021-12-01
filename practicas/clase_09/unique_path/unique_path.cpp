/** 
* @author      : Jackson Fernando Merma Portocarrero (jmermap@unsa.edu.pe)
* @filename    : unique_path
*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        if(obstacleGrid[0][0]==1)
            return 0;
        
        //dimensiones
        int height=obstacleGrid.size();
        int width=obstacleGrid[0].size();

        int data[height][width];//matriz acumulatorio de casos
        data[0][0]=1;//se inicializa con 1 la posicion [0][0]

        //recorriendo la primera fila y primera columna --> max(width, height)
        for(int i=1; i<max(height, width); i++){
            if(i<height){//si esta dentro de rango vertical
                if(obstacleGrid[i][0]!=1)//si no es el obstaculo
                    data[i][0]=data[i-1][0];//arriba
                else
                    data[i][0]=0;
            }
            if(i<width){//si esta dentro del rango horizontal
                if(obstacleGrid[0][i]!=1)//si no es el obstaculo
                    data[0][i]=data[0][i-1];//izquierda
                else
                    data[0][i]=0;
            }
        }
        
        //recorridos almacenados en matriz creada
        for(int y=1; y<height; y++){
            for(int x=1; x<width; x++){
                if(obstacleGrid[y][x]!=1){//si no está en el obstáculo
                    data[y][x]=data[y-1][x] + data[y][x-1];//suma de los dos posibles caminos
                }else{
                    data[y][x]=0;
                }
            }
        }
        
        return data[height-1][width-1];//total de caminos
    }