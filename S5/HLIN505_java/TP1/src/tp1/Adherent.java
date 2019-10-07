package tp1;

import java.util.Calendar;

public class Adherent {
	
	private String nom;
	private boolean acquiter;
	private int numeroAdherent;
	private static int nbAdherent=1;
	private int annee;
	
	public Adherent(String nom, boolean acquiter) {
		this.nom = nom;
		this.acquiter = acquiter;
		
		this.annee = Calendar.getInstance().get(Calendar.YEAR);
		this.numeroAdherent = nbAdherent++;
	}
	
	
	public int getNumeroAdherent() {
		return numeroAdherent;
	}


	public static int getNbAdherent() {
		return nbAdherent;
	}


	public void reAdhesion(){
		if( !acquiter ){
			annee = Calendar.getInstance().get(Calendar.YEAR);
			acquiter = true;
		}
	}

	@Override
	public String toString() {
		return "Adherent [nom=" + nom + ", acquiter=" + acquiter + ", numeroAdherent=" + numeroAdherent + ", annee="
				+ annee + "]";
	}
	
	
}
