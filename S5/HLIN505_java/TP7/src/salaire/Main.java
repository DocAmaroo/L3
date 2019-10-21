package salaire;

import java.util.Iterator;

public class Main {

	public static void main(String[] args) {
		
		FeuilleSalaire FS = new FeuilleSalaire("Michel", "Patate", "jesaispascequeC", 39, 36000, 2);
		Iterator<Object> ite = FS.iterator();
		
		while( ite.hasNext() ){
			System.out.println( ite.next() );
		}
	}
}
