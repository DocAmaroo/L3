package assertionsAndExceptions;

public class ListeChainee{

	public class Node{
			
		private String nom;
		private Node successeur;
		
		
		public Node(String nom){
			this.nom = nom;
		}
		
		public Node(String nom, Node successeur){
			this.nom = nom;
			this.successeur = successeur;
		}
		
		public String getNom(){
			return this.nom;
		}
		
		public Node getSuccesseur(){
			return this.successeur;
		}
		
		public void setSuccesseur(Node n){
			this.successeur = n;
		}
	}
		
	private Node racine;
	private int tailleListe = 0;
	
	public ListeChainee(){}
	
	public ListeChainee(Node racine){
		this.racine = racine;
		tailleListe = 0;
	}
	
	public void ajouterEnTete(Node n){
		int oldTailleListe = tailleListe;
		n.setSuccesseur(racine);
		racine = n;
		tailleListe++;
		System.out.println("ajouterEnTete = " + tailleListe);
		assert (tailleListe == oldTailleListe + 1);
		
	}
	
	public int getTailleListe(){
		return tailleListe;
	}
	
	public ListeChainee reverse(){
		int oldTaille = tailleListe;

		ListeChainee reverseListe = new ListeChainee();
		
		Node tete = racine;
				
		while( tete != null ){
			reverseListe.ajouterEnTete(new Node(tete.getNom()));
			tete = tete.getSuccesseur();
		}

		assert (oldTaille == reverseListe.getTailleListe());
		
		return reverseListe;
	}
	
	public String toString(){
		String res = "";
		Node tete = racine;
		
		while( tete.getSuccesseur() != null ){
			res += tete.getNom() + " --> ";
			tete = tete.getSuccesseur();
		}
		return res + tete.getNom();
	}
}


	

