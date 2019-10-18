package tp1;

public class Main {

	public static void main(String[] args) {
		
//		HeureSimple h1 = new HeureSimple(15,10);
//		HeureSimple h2 = new HeureSimple(16,10);
//		HeureSimple h3 = new HeureSimple(15,30);
//		HeureSimple h4 = new HeureSimple(18,00);
		
//		Créneau c1 = new Créneau(JourSemaine.MERCREDI,h1,h2);
//		Créneau c2 = new Créneau(JourSemaine.MERCREDI,h3,h4);
		
		// affichage heure
		
//		System.out.println(h1);
//		System.out.println(h2);
		
		// affichage créneau
//		System.out.println(c1);
		
//		 System.out.println(c2.estInclusDans(c1));
//		 System.out.println(c1.chevauche(c2));
//		 System.out.println(c2.chevauche(c1));
		
//		Adherent a1 = new Adherent("Michel", false);
//		Adherent a2 = new Adherent("Maxime", true);
//		Adherent a3 = new Adherent("Alexandrie", true);
//		Adherent a4 = new Adherent("Alexandra", true);
		
		// Créneau 2
//		Créneau2 c1 = new Créneau2(JourSemaine.MERCREDI,15,10,16,10);
//		Créneau2 c2 = new Créneau2(JourSemaine.MERCREDI,15,30,18,00);
		
		// affichage créneau
		// System.out.println(c1);
		
		ListeChainee l = new ListeChainee();
		ListeChainee.Node racine = l.new Node("racine");
		ListeChainee.Node n1 = l.new Node("Node 1",racine);
		ListeChainee.Node n2 = l.new Node("Node 2",n1);
		l.setRacine(racine);
		l.ajouterEnTete(n1);
		l.ajouterEnTete(n2);
		System.out.println(l);
		System.out.println(l.reverse());
	}
	
}
