/** 
* @author      : Jackson Fernando Merma Portocarrero (jmermap@unsa.edu.pe)
* @filename    : tieRopes
*/

/**
 * Explanation:
 *      Para su solucion, simplemente se debe sumar las longitudes
 *      hasta que sean iguales o mayores que K, siendo esa suma,
 *      la respuesta.
*/

int solution(int K, vector<int> &A) {
    /**
     * Metodo solution: proporcionado por el sitio web
     * Atributos:
     *      K -> minima longitud de una recta
     *      A -> lista de longitudes de rectas
     */ 

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