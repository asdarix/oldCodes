/*bulmacada kelimelerin yerlerini bulan program
 * main fonksiyon wordsearchı cagırır lefttoright ile soldan sağa 
 * topdown ile yukarından aşşağıya tüm indexlerde aynı uygulamayı yapar
 * bulunan kelimenin lokasyonunu ekrana yazdırır kelimeyi bulamadıysa -1 -1 -1 yazdırır
 * mustafa sabri ince
 * */
#include <stdio.h>
#include <string.h>
#define M   25 /* number of rows */
#define N	15 /* number of columns */
int wordsearch(char word[], int location[]);/*fonksiyonun prototipi*/
int lefttoright(char word[], int n, int startrow, int startcol);/*fonksiyonun prototipi*/
int topdown(char word[], int n, int startrow, int startcol);/*fonksiyonun prototipi*/
/* bulmaca */
char puzzle [25][15]= { { 'h','c','b','n','z','a','y','d','f','f','y','d','v','k','c' },
		{ 'j','i','m','c','y','v','w','f','i','a','h','r','y','y','u' },
		{ 'n','g','p','z','w','z','g','r','k','e','l','x','m','x','o' },
		{ 's','w','p','h','f','z','c','e','s','i','e','d','x','u','x' },
		{ 'b','l','h','z','o','l','l','s','m','k','s','w','n','w','m' },
		{ 'h','l','o','b','p','p','a','h','a','k','i','j','f','t','c' },
		{ 'e','b','f','p','s','n','i','v','d','v','w','l','z','t','r' },
		{ 'p','k','t','a','g','b','n','z','o','i','b','m','l','n','i' },
		{ 'y','k','f','v','i','n','b','g','j','r','z','y','d','s','u' },
		{ 'l','f','x','n','v','a','v','k','t','k','n','h','r','s','z' }, 
		{ 'c','a','d','i','l','l','a','c','m','a','z','d','a','s','l' },
		{ 'h','o','n','d','a','v','o','l','v','o','b','j','m','g','e' },
		{ 'f','o','r','d','a','u','d','i','r','a','l','e','e','m','x' },
		{ 'o','d','l','c','l','a','n','d','r','o','v','e','r','i','u' },
		{ 'b','t','e','h','o','l','d','e','n','v','o','p','c','t','s' },
		{ 'm','o','u','r','o','l','l','s','r','o','y','c','e','s','a' },
		{ 'w','y','h','y','u','n','d','a','i','l','k','a','d','u','a' },
		{ 'p','o','r','s','c','h','e','l','e','k','i','a','e','b','b' },
		{ 'e','t','m','l','u','i','e','f','o','s','t','y','s','i','p' },
		{ 'u','a','i','e','l','l','d','a','e','w','o','o','b','s','r' },
		{ 'g','o','n','r','n','f','e','r','r','a','r','i','e','h','o' },
		{ 'e','u','i','l','a','m','b','o','r','g','h','i','n','i','t' },
		{ 'o','s','u','z','u','k','i','m','a','e','o','r','z','o','o' },
		{ 't','n','b','e','n','t','l','e','y','n','i','s','s','a','n' },
		{ 'j','a','g','u','a','r','m','o','s','u','b','a','r','u','u' } }; 




/* 
 * ana program her kelimede topdown ve lefttoright fonksiyonlarını çağırır, sonra printlocation fonksiyonu
 * lokasyonunu gösterir
 */
int main()
{
	/* bulmacada aranacak kelimeler */
	char words[33][15]= { "lamborghini", "alfaromeo", "lada", "mazda", 
			"toyota", "nissan", "mini", "jaguar", "mitsubishi", 
			"mercedesbenz", "porsche", "volkswagen", "lexus", "hyundai", 
			"honda", "holden", "ford", "saab", "volvo",	"proton", "peugeot", 
			"chrysler",	"bentley", "bmw", "audi", "rollsroyce",	"kia", 
			"landrover", "jeep", "daewoo", "suzuki", "subaru", "cadillac" };


	for(int i = 0; i < 33; i++){
		int location[3] = {0};
		wordsearch(words[i],location);/*fonksiyonu çağırır*/
		printf("%-15s %-5d %-5d %-5d\n", 
				words[i], location[0], location[1], location[2]);/*lokasyonunu yazdırır*/
	}

	return 0;
}
/*lefttoright ve topdown fonksiyonları yardımıyla kelimeyi aratır */
int wordsearch(char word[], int location[]){
	int n = strlen(word);
	for (int i = 0; i < M; i++){
		for (int j = 0; j < N; j++){
			if (!lefttoright(word, n, i, j)){
				location[0] = i;
				location[1] = j;
				location[2] = 0;
				return 1;

			} 

			else if(!topdown(word, n, i, j)){
				location[0] = i;
				location[1] = j;
				location[2] = 1;
				return 1;
			}

		}	

	}
	location[0] = -1;/*eğer kelime yoksa -1 döndürür*/
	location[1] = -1;
	location[2] = -1;
	return 0;
}
/*
 * bulmacanın içinde ki kelimeyi (n uzunlugundaki)soldan sağa  arar
 */
int lefttoright(char word[], int n, int startrow, int startcol){
	for (int i = 0 ; i < n; i++){
		/* 
		 * if we reach the end of the puzzle 
		 * and the word still hasn't been matched
		 */ 

		if (startcol >= N){
			return 1;
		}
		else if (puzzle[startrow][startcol] != word[i]){
			return 1;
		}

		/*found matching character, check next character
		 * in the word with the next column in the puzzle
		 */
		else{
			startcol++;
		}
	}
	/* whole word has been matched */
	return 0;	

}

/*
 * searches word (whose length is n) in the puzzle from top to bottom
 */
int topdown(char word[], int n, int startrow, int startcol)
{
	for (int i = 0 ; i < n; i++){
		/* 
		 * if we reach the end of the puzzle 
		 * and the word still hasn't been matched
		 */ 
		if (startrow >= M){
			return 1;
		}

		/* if we find a mismatching character */
		else if (puzzle[startrow][startcol] != word[i]){
			return 1;
		}

		/*found matching character, check next character
		 * in the word with the next column in the puzzle
		 */ 
		else{
			startrow++;
		}
	}
	/* whole word has been matched */
	return 0;	

}
