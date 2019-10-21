package salaire;

import java.util.ArrayList;
import java.util.Iterator;

public class Main {

	public static void main(String[] args) {
		
		System.out.println("## Feuille Salaire");
		FeuilleSalaire FS = new FeuilleSalaire("Michel", "Patate", "jesaispascequeC", 39, PrelevementFiscaux.CSG ,36000);
		Iterator<Object> ite = FS.iterator();
		
		while( ite.hasNext() ){
			System.out.println( ite.next() );
		}
		
		System.out.println("\n## Collection Feuille Salaire");
		
		FeuilleSalaire FS1 = new FeuilleSalaire("Michel", "Patate", "jesaispascequeC", 3, PrelevementFiscaux.COTISATION_SALARIAL, 1);
		FeuilleSalaire FS2 = new FeuilleSalaire("Martine", "Rasta", "PTDRR", 138, PrelevementFiscaux.CRDS, 2);
		FeuilleSalaire FS3 = new FeuilleSalaire("Michelangelo", "Chikita", "LAVIECNAZE", 16, PrelevementFiscaux.COTISATION_SALARIAL, 0);
		
		ArrayList<FeuilleSalaire> list = new ArrayList<FeuilleSalaire>();
		list.add(FS1);
		list.add(FS2);
		list.add(FS3);
		
		CollectionFeuilleSalaire CFS = new CollectionFeuilleSalaire(list);
		System.out.println("## Stream");
		CFS.print();
		System.out.println("## Foreach");
		CFS.printFE();
		
//		System.out.println("\n## Tri 1");
//		CFS.tri1();
//		CFS.print();
		
		System.out.println("\n## Tri 3");
		CFS.tri3();
		
	}
}