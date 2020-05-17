package ex2;

public class Main {
	
	public static void main(String[] args) throws Exception {
		
		FabriquePersonnage fp = new FabriquePersonnage();
		Personnage p1 = fp.makePersonnage("ex2.PersonnageInvisible");
		
		
		System.out.println("____ Création de votre personnage ____\n");
		fp.setAttribut(p1);
	}
}
