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


void solve(int n, long int l, int w){

    // X - r
    vector<pair<double, double>> sprinklersValues;

    for(int i=0;i<n;i++){
        long int x;
        int r;
        cin>>x>>r;

        if(r>=w/2.0){
            double k = sqrt(r*r-w*w/4.0);
            x*=1.0;
            sprinklersValues.push_back(make_pair(x-k,x+k));
        }
    }

    sort(sprinklersValues.begin(), sprinklersValues.end());

    double limit = 0;
    int ans = 0, ini = 0;

    while(limit < l){//solo los necesarios
        ans ++;

        //primero se maximizan los limites de los rectangulos (limites dentro de otros limites)
        double limit_aux = limit;

        for(int i = ini; i < sprinklersValues.size() && sprinklersValues[i].first <= limit_aux; i++){
            if(limit < sprinklersValues[i].second)
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

    while(cin>>n>>l>>w){
        solve(n,l,w);
    }

    return 0;
}