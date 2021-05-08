void soma();

int main(){	
	soma();
	return 0;
}

void soma(){
	int x, y, a, b, resultado;
	scanf("%d", &x);
	scanf("%d", &y);
    resultado = x + y;
	printf("%d", resultado);

    scanf("%d", &a);
	scanf("%d", &b);
    resultado = a + b;
	printf("%d", resultado);
	soma();
}

