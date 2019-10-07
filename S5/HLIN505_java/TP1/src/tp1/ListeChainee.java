package tp1;

public class ListeChainee {

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
	private static int tailleListe;
	
	public ListeChainee(){}
	
	public ListeChainee(Node racine){
		this.racine = racine;
	}
	
	public void setRacine(Node n){
		this.racine = n;
		tailleListe++;
	}
	
	public void ajouterEnTete(Node n){
		n.setSuccesseur(racine);
		racine = n;
		tailleListe++;
	}
	
	public int getTailleListe(){
		return tailleListe;
	}
	
	public ListeChainee reverse(){
		 ListeChainee reverseListe = new ListeChainee(new Node(racine.getNom()));
		 
		 Node tete = racine.getSuccesseur();
		 
		 while( tete != null ){
			 reverseListe.ajouterEnTete(new Node(tete.getNom()));
			 tete = tete.getSuccesseur();
		 }
		 
		 
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
	
	
