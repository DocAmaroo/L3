package tpTest.visites.toTest;

public class Etape {
	private int dureeVisite;
	private NatureEtape type;
	private String nom;
	private String rue;
	
	public Etape(String nom, String rue, int dureeVisite, NatureEtape type) {
		this.nom=nom;
		this.dureeVisite = dureeVisite;
		this.type = type;
	}
	
	public NatureEtape getType() {
		return type;
	}

	public void setType(NatureEtape type) {
		this.type = type;
	}

	public String getNom() {
		return nom;
	}

	public void setNom(String nom) {
		this.nom = nom;
	}

	public int getDureeVisite() {
		return dureeVisite;
	}

	public void setDureeVisite(int dureeVisite) {
		this.dureeVisite = dureeVisite;
	}
	
	public String getRue() {
		return rue;
	}
/** 
 * vérifie que l'étape est correcte, c'est à dire que la durée de visite n'est nulle que s'il s'agit d'un lieu d'intérêt sans visite.
 * @return vrai ssi duree de visite nulle <=> lieu d'intérêt sans visite 
 */
	public boolean estCorrecte(){
		boolean res = true;
		if (dureeVisite!=0 && type==NatureEtape.lieuInteretSansVisite){
			res = false;
		}		
		return res;
	}
}
