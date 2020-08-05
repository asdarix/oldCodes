/*mustafa sabri ince
 *tekerleme oyunu
*/
import java.util.LinkedList;
import java.util.Scanner;

public class Tekerleme {
	public static void main(String[] args) {
		LinkedList<String> object = new LinkedList<String>();
		object.add("Oyuncu1"); 
        object.add("Oyuncu2"); 
        object.add("Oyuncu3"); 
        object.add("Oyuncu4"); 
        object.add("Oyuncu5"); 
        object.add("Oyuncu6"); 
        object.add("Oyuncu7"); 
        System.out.println("Linked list : " + object);
		
		Scanner scan = new Scanner(System.in);
		int count=0,oyuncu_sayisi=7;
		while(oyuncu_sayisi>1) {
			
			System.out.println("Tekerlemenizi giriniz : ");
			String tekerleme= scan.nextLine();
		
			for(int i=0;i< tekerleme.length();++i) {
				if(((tekerleme.charAt(i))=='a')||((tekerleme.charAt(i))=='e')||((tekerleme.charAt(i))=='ý')
				||((tekerleme.charAt(i))=='i')||((tekerleme.charAt(i))=='u')||((tekerleme.charAt(i))=='ü')
				||((tekerleme.charAt(i))=='o')||((tekerleme.charAt(i))=='ö'))
				{
					++count;
				}
			}
			object.remove(count % oyuncu_sayisi);		
			--oyuncu_sayisi;
		}
		 System.out.println("Linked list : " + object);
	}
}