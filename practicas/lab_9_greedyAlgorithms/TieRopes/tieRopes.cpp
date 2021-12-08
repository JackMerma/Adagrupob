/** 
* @author      : Jackson Fernando Merma Portocarrero (jmermap@unsa.edu.pe)
* @filename    : tieRopes
*/
int solution(int K, vector<int> &A) {
    long int ans=0;//respuesta almacenada
    long long aux=0;//sera el conteo auxiliar de los adyacentes
    
    //recorrido lineal
    for(int i=0;i<A.size();i++){
        if(A[i]+aux>=K){//si es mayor o igual que K
            ans++;
            aux=0;//el conteo se vacía
        }else{
            aux+=A[i];//el conteo se almacena 
        }
    }
    
    return ans;
}