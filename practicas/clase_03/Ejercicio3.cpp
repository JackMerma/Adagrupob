/**
 */
#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int len;
	cin>>len;
	int a[len][len], b[len][len];	
	string aData[len],bData[len];//nobres de cada grupo en el orden dado
	
	//entrada de datos
	for(int i=0;i<len;i++)//nombres grupo A
		cin>>aData[i];
	for(int i=0;i<len;i++)//posiciones
		for(int j=0;j<len;j++)
			cin>>a[i][j];

	for(int i=0;i<len;i++)//nombres grupo B
		cin>>bData[i];
	for(int i=0;i<len;i++)
		for(int j=0;j<len;j++)
			cin>>b[i][j];

	//agrupamiento
	//arreglos que determinaran emparejamiento de a-iesimo con b-iesimo
	//el arreglo 'pri' hace seguimiento de prioridad en A(reemplaza a una cola de prioridad)
	int empA[len]={0},empB[len]={0}, pri[len]={0}, count=0;

	for(int i=0;count<len;i++,i%=len){
		if(empA[i]==0){
			int opt=a[i][pri[i]]-1;
			//verificacion en B
			if(empB[opt]==0){
				empA[i]=opt+1;
				empB[opt]=i+1;
				count++;
			}else{
				//verificacion de la mejor opcion
				if(b[opt][i]<b[opt][empB[opt]-1]){
					empA[empB[opt]-1]=0;
					empB[opt]=i+1;
					empA[i]=opt+1;
				}else{
					pri[i]++;
					i--;
				}
			}
		}
	}
	//resultado
	cout<<"Emparejamientos:"<<endl;
	for(int i=0;i<len;i++)
		cout<<aData[i]<<"->"<<bData[empA[i]-1]<<endl;

	return 0;
}

