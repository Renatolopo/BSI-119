#include <stdio.h>

typedef struct{
	float kmh, ms, mph, vn;

} Velocidade;

void  kmh(float x){
	

	printf(" %.2fKm/h \t %.2fm/s \t %.2fmph \t %.2f velocidade nautica.\n", x ,x/3.6, x*0.6214, x/1.852);

}
void  ms(float x){
	

	printf(" %.2fKm/h \t %.2fm/s \t %.2fmph \t %.2f velocidade nautica.\n", x*3.6 ,x, (x*3.6)*0.6214, x/0.51444);

}

void  mph(float x){
	

	printf(" %.2fKm/h \t %.2fm/s \t %.2fmph \t %.2f velocidade nautica.\n", x/0.6214 ,(x/3.6)/0.6214, x, ((x/3.6)/0.6214)/0.51444);
}
void  vn(float x){
	

	printf(" %.2fKm/h \t %.2fm/s \t %.2fmph \t %.2f velocidade nautica.\n", x*1.852 ,(x/3.6)*1.852, (x*0.6214)*1.852, x);
}

int main()
{
	int v1;
	char tipo[99];
	printf("informe a velocidade: \n");
	scanf(" %i",&v1);
	printf("medida da velocidade(kmh, ms, mph, vn):\n");
	scanf(" %[^\n]s",tipo);
	Velocidade v;
	if(tipo[0] =='k'){
		v.kmh=v1;
		kmh(v1);
	}
	else if(tipo[1]=='s'){
		v.ms = v1;
		ms(v1);

	}
	else if(tipo[1] == 'p'){
		v.mph = v1;
		mph(v1);
	}
	else if(tipo[1] == 'n'){
		v.vn = v1;
		vn(v1);
	}
}
