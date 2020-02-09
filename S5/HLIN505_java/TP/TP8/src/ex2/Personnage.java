package ex2;

public abstract class Personnage {
	
	public String nom;
	public int pv;
	public int points;
	
	public Personnage(){};
	
	public Personnage(String nom, int pv, int points) {
		super();
		this.nom = nom;
		this.pv = pv;
		this.points = points;
	}
	
	public String getNom() {
		return nom;
	}
	public void setNom(String nom) {
		this.nom = nom;
	}
	public int getPv() {
		return pv;
	}
	public void setPv(int pv) {
		this.pv = pv;
	}
	public int getPoints() {
		return points;
	}
	public void setPoints(int points) {
		this.points = points;
	}

	@Override
	public String toString() {
		return "nom = " + nom + "\npv = " + pv + "\npoints = " + points;
	}
	
	
}

