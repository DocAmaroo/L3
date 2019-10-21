package tp;

public class Livre extends Document{

	private int nbChapitres;

	public int getNbChapitres() {
		return nbChapitres;
	}

	public Livre(String titre, int nbChapitres) {
		super(titre);
		this.nbChapitres = nbChapitres;
	}

	@Override
	public String toString() {
		return "Livre [titre==" + getNom() + "]";
	}

	/*public Livre(){
	}*/
}