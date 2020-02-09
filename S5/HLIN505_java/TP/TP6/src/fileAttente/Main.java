package fileAttente;

public class Main {

	public static void main(String[] args) {
		Personne p1 = new Personne("ALBERT", 50);
		Personne p2 = new Personne("GINETTE", 90);
		Personne p3 = new Personne("GISELE", 80);
		Personne p4 = new Personne("Maxime", 21);
		Personne p5 = new Personne("Melody", 21);
		Personne p6 = new Personne("Anthony WYIQBGOE (nom de famille de merde)", 21);
		Personne p7 = new Personne("Charles (toujours absent en cours)", 21);
		Personne p8 = new Personne("Mathias", 1);
		Personne p9 = new Personne("Gaetan", 3);
		Personne p10 = new Personne("Toutancanon", 10);
		
		FileAttentePrioritaire<Personne> FAP = new FileAttentePrioritaire<>();
		FAP.entre(p1);
		FAP.entre(p2);
		FAP.entre(p3);
		FAP.entre(p4);
		FAP.entre(p5);
		FAP.entre(p6);
		FAP.entre(p7);
		FAP.entre(p8);
		FAP.entre(p9);
		FAP.entre(p10);
		System.out.println(FAP);
	}
}
