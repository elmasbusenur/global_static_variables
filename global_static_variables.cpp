#include<stdio.h>
void useLocal(void);
void useStaticLocal(void);
void useGlobal(void);

int x=1; //global degisken
int main(void)
{
	int x=5; //mainde ki local degisken
	printf("\nLocal x in outer scope of main is %d\n", x); //5
	//main alani disindaki yerel x
	{
		int x=7;//local variable in new scope
		printf("\nLocal x in inner scope of main is %d",x); //7
	}
	printf("\nLocal x in outer scope of main is %d\n", x); //5
	useLocal();//useLocal has automatic local x (otomatik yerel x degerine sahiptir)
	useStaticLocal();//useStaticLocal has static local x(statik yerel x degerine sahiptir)
	useGlobal();//useGlobal uses global x(useGlobal global x i kullanrý)
	useLocal();/*useLocal reinitializes automatic local x
	(useLocal yerel x i kendiliginden yeniden baslatir)*/
	useStaticLocal();//static local x retains its prior value(önceki degerini korur)
	useGlobal();//global x also retains its value(global x degerini korur)
	printf("\nLocal x in main is %d\n", x);//maindeki yerel x //5
	return 0;
}
void useLocal(void)
{
	int x=25;/*initialized each time useLocal is called
	(useLocal her cagrildiginde ilk deger atar)*/
	printf("\nLocal x in useLocal is %d after entering useLocal\n", x); //25
	//useLocal girdikten sonra degeri %d dir
	x++;
	printf("Local x in useLocal is %d before exiting useLocal\n",x); //26
	//çikmadan önce x degeri %d
	
}
void useStaticLocal(void)
{
	static int x=50;//sadece ilk cagrildiginde 50 olur
	printf("\nLocal static x is %d on entering useStaticLocal\n", x); //50
	//useStaticLocal girildiginde %d dir.
	x++;
	printf("Local static x is %d on exiting useStaticLocal\n", x);//51
}
/*function useGlobal modifies global variables x during each call*/
void useGlobal(void)
{
	printf("\nGlobal x is %d on entering useGlobal\n", x); //1
	x=x*10;
	printf("Global x is %d on exiting useGlobal\n",x); //10
}
