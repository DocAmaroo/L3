package tp1;

import java.util.ArrayList;

public enum Lieu {
	PISCINES("Piscine municipal"), 
	STADE("Stade de foot"), 
	SALLE_DE_SPORT("Salle de sport");
	
	private String nom;
	private ArrayList<Créneau> creneauxDisponible = new ArrayList<Créneau>();
			
	private Lieu(String nom){
		this.nom = nom;
	}
	
	public void ajoutCreneau(Créneau c){
		creneauxDisponible.add(c);
	}
	
	public boolean estDisponiblePendant(Créneau c){
		boolean result=true;
		for (Créneau cr : creneauxDisponible){
			if ( c.estInclusDans(cr)) return true;
			else return false;
		}
		return result;
	}
	
}
