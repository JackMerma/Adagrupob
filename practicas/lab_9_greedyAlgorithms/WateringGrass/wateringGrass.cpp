/** 
* @author      : Jackson Fernando Merma Portocarrero (jmermap@unsa.edu.pe)
* @filename    : wateringGrass
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define PI 3.1415926535897932384626

/**
 * Explanation:
 *      Para resolverlo, primero se agregan solo a los circulos que puedan
 *      rellenar al menos el ancho del rectangulo; luego, se deben calcular por cada circulo,
 *      el limite derecho e izquierdo que forman cuando intersectan con
 *      el rectangulo, es decir, el circulo forma una franja de interseccion
 *      con el rectangulo, de ello, solo es necesario determinar el limite de
 *      ese sub-rectangulo que ocupara dicho circulo; luego este se inserta
 *      al arreglo y se ordena de menor a mayor por los limites izquierdos
 * 
 *      Luego, para maximizar la respuesta, se maneja un limite estatico o
 *      general, que determina hasta que parte ya se relleno el rectangulo,
 *      si este en algun punto no se puede rellenas (no cambia el limite
 *      estatico), entonces se imprime -1, pero si llega al final, se trendra 
 *      la respuesta maximizada.
 */ 

void solve(int n, long int l, int w){
    /**
     * Metodo solve: Metodo para desarrollar cada caso
     * Atributos:
     *      n -> cantidad de sprinklers
     *      l -> longitud del espacio (largo del rectangulo)
     *      w -> angho del espacio (ancho del rectangulo)
     */ 

    // almacena a limite (izquiedo - derecho) => (first - second)
    vector<pair<double, double>> sprinklersValues;//arreglo principal

    for(int i=0;i<n;i++){
        long int x;
        int r;
        cin>>x>>r;

        if(r>=w/2.0){//si el circulo llega a cubrir al menos el ancho del espacio
            

            //los limites estan dados mediante el uso de la formula del circulo
            // r^2 = (w/2)^2 + (k)^2 => r^2 = (w^2)/4 + (k)^2
            // luego ... r^2 - (w^2)/4 = (k)^2 
            // finalmente ... k = (r^2 - (w^2)/4)^0.5 
            // entonces, k, sera esa distancia (largo) que se forma
            // cuando intersecta el circulo y el rectangulo 

            double k = sqrt(r*r-w*w/4.0);// +/- de rectangulos formados por
                                         // los limites que forman el circulo y
                                         // rectangulo
            x*=1.0;
            sprinklersValues.push_back(make_pair(x-k,x+k));//agregando ambos limites
        }
    }

    //se ordena en secuencia lineal del limite izquierdo (como esta en el caso de muestra - grafico)
    sort(sprinklersValues.begin(), sprinklersValues.end());

    double limit = 0;//limite actual
    int ans = 0, ini = 0;//respuesta e inicio

    while(limit < l){//solo los necesarios
        ans ++;//se aumenta la respuesta

        double limit_aux = limit;

        //primero se maximizan los limites de los rectangulos (limites dentro de otros limites)
        for(int i = ini; i < sprinklersValues.size() && sprinklersValues[i].first <= limit_aux; i++){
            if(limit < sprinklersValues[i].second)//si esta dentro del limite principal
                limit = sprinklersValues[i].second;
        }
        if(limit_aux < l && limit_aux == limit){
            //no se cumplio el objetivo y hay espacios no rellenados
            cout<<-1<<endl;
            return; 
        }
    }

    cout<<ans<<endl;
}


int main(){
    /* 
        Metodo principal
    */
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, w;
    long int l;

    while(cin>>n>>l>>w){//hasta que se pueda insertar n, l, w
        solve(n,l,w);//cada caso
    }

    return 0;
}