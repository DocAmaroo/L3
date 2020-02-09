package tp9;

import java.util.ArrayList;

public class Mail {

	
	private String adresseDestinataire;
	private String texte;
	private String titre;
	private ArrayList<String> pj;
	private final static String adresseregexp = "\\p{Alpha}\\{Alnum}@\\";
	
	public Mail(String addr, String text, String titre, ArrayList<String> pj){
		this.adresseDestinataire = addr;
		this.texte = text;
		this.titre = titre;
		this.pj = pj;
	}
	
	public boolean verifAdress(){
		//vérifie si l'adresse est correcte
		return true; //adresseDestinataire.matches(adresseregexp);
	}
	
	public boolean verifTitre(){
		//verifie si le titre est correcte
		return true;
	}
	public boolean verifPJ(){
		//verifie si les PJ sont correctes
		return true;
	}
	
	public void send(){
		boolean res = false;
		if ( verifAdress() && verifTitre() && verifPJ() ){
			//envoi du mail
		}
	}
}
