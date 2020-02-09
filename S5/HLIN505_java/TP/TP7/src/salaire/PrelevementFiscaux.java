package salaire;

public enum PrelevementFiscaux {
	CRDS ("CRDS"), CSG("CSG"), COTISATION_SALARIAL ("Cotisation Salarial");
	
	
	String nom;
	
	private PrelevementFiscaux( String nom ){
		this.nom = nom;
	}
	
	private String getNom(){
		return this.nom;
	}
}
