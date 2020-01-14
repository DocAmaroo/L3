package interfaces;

import java.io.IOException;

public abstract class Song extends AbstractAudioElement{
	private String chanteur;
	private int duree;
	
	public Song(int duree, String titre, String fileLocation, String chanteur) throws IncorrectFileNameException {
		super(titre, fileLocation);
		this.chanteur = chanteur;
		this.duree = duree;
		if ( !getFile().exists()){
			throw new IncorrectFileNameException("Nom du fichier problème : " + fileLocation);
		}
	}
	
	public String toString(){
		String res = "S | ";
		res += duree + " | " + getTitre() + " | " + getFileLocation() + " | " + chanteur + " | ";
		return res;
	}
	
	public long getSize() throws IOException{
		return getFile().length();
	}
	public int getDuree(){
		return this.duree;
	}

		
}
