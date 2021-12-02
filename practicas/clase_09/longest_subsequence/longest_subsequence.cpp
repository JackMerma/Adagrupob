class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len=nums.size();//tamaño de numeros
        
        int data[len][len];//matriz principal
        
        int ans=1;//minima respuesta
        
        //recorrido dinamico sobre la matriz principal
        for(int i=0;i<len;i++){
            for(int u=i;u<len;u++){
                if(i==0){//si es la primera fila solo se compara con el actual (primero)
                    if(nums[u]>nums[i])//si es mayor, entonces habra como maximo 2 numeros 
                        data[i][u]=2;
                    else//si no lo es, solo habra 1 numero (primero)
                        data[i][u]=1;
                }else{
                    if(nums[u]>nums[i])//si es mayor entonces se maximiza entre el actual + 1 y el maximo en esa posicion -> filas anteriores (ya maximizados)
                        data[i][u]=max(data[i-1][i]+1,data[i-1][u]);
                    else
                        data[i][u]=data[i-1][u];//si no es mayor, sera el actual (1 fila anterior -> ya maximizado)
                }
                if(i==u)//cada vez que se evalue un nuevo numero, se pregunta por el mayor
                    ans=max(ans,data[i][u]);
            }
        }
        return ans;
    }
};