/** 
* @author      : Jackson Fernando Merma Portocarrero (jmermap@unsa.edu.pe)
* @filename    : maxNoneoverlappingSegments
*/
int solution(vector<int> &A, vector<int> &B) {
    if(A.size()==0)//si no hay datos
        return 0;

    //La verificación de la NO superposición esta dada por:
    // B[i] < A[j], donde i < j
    // En otras palabras: 
    //      el límite derecho de la primera recta sea menor que el
    //      limite izquierdo de la segunda recta
    
    long int b=B[0];//Primer límite izquierdo

    int ans=1;//Si siempre hay superposiciones, el mínimo es 1
    
    //recorrido lineal desde la pos 1
    for(int i=1;i<A.size();i++){
        if(b<A[i]){//si NO se superponen
            ans++;//se aumenta la respuesta
            b=B[i];//se cambia el límite derecho más optimo
        }
    }
    return ans;
}