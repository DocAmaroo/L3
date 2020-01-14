package tableau;

public class Main {

	public static void main(String[] args) {
		
		Integer T[] = {10, 2, 6, 11, 7, 2, -1, 0, 9};
		Tableau<Integer> obj = new Tableau<Integer>(T);
		obj.triBulles();
		obj.affiche();
		
		String T2[] = {"b", "v", "w", "m", "o", "c", "x", "t"};
		Tableau<String> obj2 = new Tableau<String>(T2);
		obj2.triBulles();
		obj2.affiche();
	}
}
