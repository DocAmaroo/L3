package pile;

public class Main{

	public static void main(String[] args) {
		
		// Pile de String
//		CPile<String> pile = new CPile<String>();
//		String a = "patata";
//		String b = "hola";
//		String c = "JE VEUX DES FAJITAS PUTAIN DE MERDE";
		
		// Pile d'entiers
		CPile<Integer> pile = new CPile<Integer>();
		int a = 69, b = 420, c = 51;
		
		System.out.println(pile.estVide());
		pile.empile(a);
		pile.empile(b);
		pile.empile(c);
		System.out.println(pile.sommet());
		System.out.println(pile.nbElements());
		System.out.println(pile.depile());
		System.out.println(pile.sommet());

	}
}
